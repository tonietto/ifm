/*
 * This file is part of IFM (Interactive Fiction Mapper), copyright (C)
 * Glenn Hutchings 1997-2015.
 *
 * IFM comes with ABSOLUTELY NO WARRANTY.  This is free software, and you
 * are welcome to redistribute it under certain conditions; see the file
 * COPYING for details.
 */

/* Recording output format header */

#ifndef IFM_REC_H
#define IFM_REC_H

#include "ifm-format.h"

extern taskfuncs rec_taskfuncs;

extern void rec_task_entry(vhash *task);

#endif
