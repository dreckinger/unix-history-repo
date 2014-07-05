/*-
 * Copyright (c) 2003 Silicon Graphics International Corp.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions, and the following disclaimer,
 *    without modification.
 * 2. Redistributions in binary form must reproduce at minimum a disclaimer
 *    substantially similar to the "NO WARRANTY" disclaimer below
 *    ("Disclaimer") and any redistribution must be conditioned upon
 *    including a substantially similar Disclaimer requirement for further
 *    binary redistribution.
 *
 * NO WARRANTY
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGES.
 *
 * $Id: //depot/users/kenm/FreeBSD-test2/sys/cam/ctl/ctl_frontend.c#4 $
 */
/*
 * CAM Target Layer front end interface code
 *
 * Author: Ken Merry <ken@FreeBSD.org>
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

#include <sys/param.h>
#include <sys/systm.h>
#include <sys/kernel.h>
#include <sys/types.h>
#include <sys/malloc.h>
#include <sys/lock.h>
#include <sys/mutex.h>
#include <sys/condvar.h>
#include <sys/endian.h>
#include <sys/queue.h>
#include <sys/sysctl.h>

#include <cam/scsi/scsi_all.h>
#include <cam/scsi/scsi_da.h>
#include <cam/ctl/ctl_io.h>
#include <cam/ctl/ctl.h>
#include <cam/ctl/ctl_frontend.h>
#include <cam/ctl/ctl_frontend_internal.h>
#include <cam/ctl/ctl_backend.h>
/* XXX KDM move defines from ctl_ioctl.h to somewhere else */
#include <cam/ctl/ctl_ioctl.h>
#include <cam/ctl/ctl_ha.h>
#include <cam/ctl/ctl_private.h>
#include <cam/ctl/ctl_debug.h>

extern struct ctl_softc *control_softc;

int
ctl_frontend_register(struct ctl_frontend *fe)
{
	struct ctl_frontend *fe_tmp;

	KASSERT(control_softc != NULL, ("CTL is not initialized"));

	/*
	 * Sanity check, make sure this isn't a duplicate registration.
	 */
	mtx_lock(&control_softc->ctl_lock);
	STAILQ_FOREACH(fe_tmp, &control_softc->fe_list, links) {
		if (strcmp(fe_tmp->name, fe->name) == 0) {
			mtx_unlock(&control_softc->ctl_lock);
			return (-1);
		}
	}
	mtx_unlock(&control_softc->ctl_lock);
	STAILQ_INIT(&fe->port_list);

	/*
	 * Call the frontend's initialization routine.
	 */
	if (fe->init != NULL)
		fe->init();

	mtx_lock(&control_softc->ctl_lock);
	control_softc->num_frontends++;
	STAILQ_INSERT_TAIL(&control_softc->fe_list, fe, links);
	mtx_unlock(&control_softc->ctl_lock);
	return (0);
}

int
ctl_frontend_deregister(struct ctl_frontend *fe)
{

	if (!STAILQ_EMPTY(&fe->port_list))
		return (-1);

	mtx_lock(&control_softc->ctl_lock);
	STAILQ_REMOVE(&control_softc->fe_list, fe, ctl_frontend, links);
	control_softc->num_frontends--;
	mtx_unlock(&control_softc->ctl_lock);

	/*
	 * Call the frontend's shutdown routine.
	 */
	if (fe->shutdown != NULL)
		fe->shutdown();
	return (0);
}

struct ctl_frontend *
ctl_frontend_find(char *frontend_name)
{
	struct ctl_softc *ctl_softc = control_softc;
	struct ctl_frontend *fe;

	mtx_lock(&ctl_softc->ctl_lock);
	STAILQ_FOREACH(fe, &ctl_softc->fe_list, links) {
		if (strcmp(fe->name, frontend_name) == 0) {
			mtx_unlock(&ctl_softc->ctl_lock);
			return (fe);
		}
	}
	mtx_unlock(&ctl_softc->ctl_lock);
	return (NULL);
}

int
ctl_port_register(struct ctl_port *port, int master_shelf)
{
	struct ctl_io_pool *pool;
	int port_num;
	int retval;

	retval = 0;

	KASSERT(control_softc != NULL, ("CTL is not initialized"));

	mtx_lock(&control_softc->ctl_lock);
	port_num = ctl_ffz(&control_softc->ctl_port_mask, CTL_MAX_PORTS);
	if ((port_num == -1)
	 || (ctl_set_mask(&control_softc->ctl_port_mask, port_num) == -1)) {
		port->targ_port = -1;
		mtx_unlock(&control_softc->ctl_lock);
		return (1);
	}
	control_softc->num_ports++;
	mtx_unlock(&control_softc->ctl_lock);

	/*
	 * We add 20 to whatever the caller requests, so he doesn't get
	 * burned by queueing things back to the pending sense queue.  In
	 * theory, there should probably only be one outstanding item, at
	 * most, on the pending sense queue for a LUN.  We'll clear the
	 * pending sense queue on the next command, whether or not it is
	 * a REQUEST SENSE.
	 */
	retval = ctl_pool_create(control_softc, CTL_POOL_FETD,
				 port->num_requested_ctl_io + 20, &pool);
	if (retval != 0) {
		port->targ_port = -1;
		mtx_lock(&control_softc->ctl_lock);
		ctl_clear_mask(&control_softc->ctl_port_mask, port_num);
		mtx_unlock(&control_softc->ctl_lock);
		return (retval);
	}
	port->ctl_pool_ref = pool;

	if (port->options.stqh_first == NULL)
		STAILQ_INIT(&port->options);

	mtx_lock(&control_softc->ctl_lock);
	port->targ_port = port_num + (master_shelf != 0 ? 0 : CTL_MAX_PORTS);
	port->max_initiators = CTL_MAX_INIT_PER_PORT;
	STAILQ_INSERT_TAIL(&port->frontend->port_list, port, fe_links);
	STAILQ_INSERT_TAIL(&control_softc->port_list, port, links);
	control_softc->ctl_ports[port_num] = port;
	mtx_unlock(&control_softc->ctl_lock);

	return (retval);
}

int
ctl_port_deregister(struct ctl_port *port)
{
	struct ctl_io_pool *pool;
	int port_num;
	int retval;

	retval = 0;

	pool = (struct ctl_io_pool *)port->ctl_pool_ref;

	if (port->targ_port == -1) {
		retval = 1;
		goto bailout;
	}

	mtx_lock(&control_softc->ctl_lock);
	STAILQ_REMOVE(&control_softc->port_list, port, ctl_port, links);
	STAILQ_REMOVE(&port->frontend->port_list, port, ctl_port, fe_links);
	control_softc->num_ports--;
	port_num = (port->targ_port < CTL_MAX_PORTS) ? port->targ_port :
	    port->targ_port - CTL_MAX_PORTS;
	ctl_clear_mask(&control_softc->ctl_port_mask, port_num);
	control_softc->ctl_ports[port_num] = NULL;
	mtx_unlock(&control_softc->ctl_lock);

	ctl_pool_free(pool);
	ctl_free_opts(&port->options);

bailout:
	return (retval);
}

void
ctl_port_set_wwns(struct ctl_port *port, int wwnn_valid, uint64_t wwnn,
		      int wwpn_valid, uint64_t wwpn)
{
	if (wwnn_valid)
		port->wwnn = wwnn;

	if (wwpn_valid)
		port->wwpn = wwpn;
}

void
ctl_port_online(struct ctl_port *port)
{
	port->port_online(port->onoff_arg);
	/* XXX KDM need a lock here? */
	port->status |= CTL_PORT_STATUS_ONLINE;
}

void
ctl_port_offline(struct ctl_port *port)
{
	port->port_offline(port->onoff_arg);
	/* XXX KDM need a lock here? */
	port->status &= ~CTL_PORT_STATUS_ONLINE;
}

/*
 * vim: ts=8
 */
