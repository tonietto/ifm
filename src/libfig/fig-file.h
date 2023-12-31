/*
 * This file is part of IFM (Interactive Fiction Mapper), copyright (C)
 * Glenn Hutchings 1997-2015.
 *
 * IFM comes with ABSOLUTELY NO WARRANTY.  This is free software, and you
 * are welcome to redistribute it under certain conditions; see the file
 * COPYING for details.
 */

/* File function header */

#ifndef FIG_FILE_H
#define FIG_FILE_H

#include <vars.h>

extern void fig_set_stream(FILE *fp);
extern void fig_set_handler(void (*func)(char *line));
extern void fig_write_figure(vhash *figure);

#endif
