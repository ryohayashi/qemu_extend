/*
 * Balloon
 *
 * Copyright IBM, Corp. 2008
 *
 * Authors:
 *  Anthony Liguori   <aliguori@us.ibm.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2.  See
 * the COPYING file in the top-level directory.
 *
 */

#ifndef QEMU_BALLOON_H
#define QEMU_BALLOON_H

#include "exec/cpu-common.h"
#include "qapi/qapi-types-misc.h"

typedef void (QEMUBalloonEvent)(void *opaque, ram_addr_t target);
typedef void (QEMUNBalloonEvent)(void *opaque, ram_addr_t target, int node);
typedef void (QEMUBalloonStatus)(void *opaque, BalloonInfo *info);
typedef void (QEMUNBalloonStatus)(void *opaque, NBalloonInfo *info);

int qemu_add_balloon_handler(QEMUBalloonEvent *event_func, QEMUNBalloonEvent *nevent_func,
                             QEMUBalloonStatus *stat_func, QEMUNBalloonStatus *nstat_func, 
                             void *opaque);
void qemu_remove_balloon_handler(void *opaque);
bool qemu_balloon_is_inhibited(void);
void qemu_balloon_inhibit(bool state);

#endif
