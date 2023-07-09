/*
 * This file is part of IFM (Interactive Fiction Mapper), copyright (C)
 * Glenn Hutchings 1997-2015.
 *
 * IFM comes with ABSOLUTELY NO WARRANTY.  This is free software, and you
 * are welcome to redistribute it under certain conditions; see the file
 * COPYING for details.
 */

/* Text output format header */

#ifndef IFM_DOT_H
#define IFM_DOT_H

#include "ifm-format.h"

extern taskfuncs dot_taskfuncs;

extern void dot_task_start(void);
extern void dot_task_finish(void);

#endif
