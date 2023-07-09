/*
 * This file is part of IFM (Interactive Fiction Mapper), copyright (C)
 * Glenn Hutchings 1997-2015.
 *
 * IFM comes with ABSOLUTELY NO WARRANTY.  This is free software, and you
 * are welcome to redistribute it under certain conditions; see the file
 * COPYING for details.
 */

/* Text output format */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <vars.h>

#include "ifm-format.h"
#include "ifm-main.h"
#include "ifm-map.h"
#include "ifm-task.h"
#include "ifm-util.h"
#include "ifm-vars.h"
#include "ifm-text.h"

/* Internal functions */
static void text_init(void);

/* Output function list */
outputfuncs text_outputfuncs = {
    text_init,
    NULL
};

/* Map function list */
mapfuncs text_mapfuncs = {
    text_map_start,
    text_map_section,
    text_map_room,
    NULL,
    NULL,
    NULL,
    NULL,
};

/* Item function list */
itemfuncs text_itemfuncs = {
    NULL,
    text_item_entry,
    NULL
};

/* Task function list */
taskfuncs text_taskfuncs = {
    NULL,
    text_task_entry,
    text_task_finish,
};

/* Total score */
static int total = 0;

/* Total distance travelled */
static int travel = 0;

/* Counts of things */
static int taskcount = 0;
static int itemcount = 0;
static int sectcount = 0;

/* Task settings */
static vhash *lastroom = NULL;
static int moved = 0;

/* Map functions */
void
text_map_start(void)
{
    char *title = vh_sgetref(map, "TITLE");
    output("Map sections for %s\n", title);
}

void
text_map_section(vhash *sect)
{
    char *title = vh_sgetref(sect, "TITLE");
    vlist *rooms = vh_pget(sect, "ROOMS");
    int width = vh_iget(sect, "XLEN");
    int height = vh_iget(sect, "YLEN");

    output("\n%d (%s) (size: %dx%d, rooms: %d):\n",
           ++sectcount, title, width, height, vl_length(rooms));
}

void
text_map_room(vhash *room)
{
    output("   %s (%d, %d)\n",
           vh_sgetref(room, "DESC"),
           vh_iget(room, "X"),
           vh_iget(room, "Y"));
}

/* Item functions */
void
text_item_entry(vhash *item)
{
    vlist *notes = vh_pget(item, "NOTE");
    vhash *room, *task, *reach;
    vlist *list;
    char *title;
    V_BUF_DECL;
    viter iter;

    if (itemcount++ == 0) {
        title = vh_sgetref(map, "TITLE");
        output("Item list for %s\n", title);
    }

    output("\n%s:\n", vh_sgetref(item, "DESC"));

    if ((room = vh_pget(item, "ROOM")) == NULL)
        output("   carried at the start of the game\n");
    else
        output("   %s in %s\n",
               (vh_iget(item, "HIDDEN") ? "hidden" : "seen"),
               vh_sgetref(room, "DESC"));

    if (vh_exists(item, "SCORE"))
        output("   scores %d points when picked up\n",
               vh_iget(item, "SCORE"));

    if (vh_exists(item, "LEAVE"))
        output("   may have to be dropped when moving\n");

    if (vh_exists(item, "FINISH"))
        output("   finishes the game when picked up\n");

    if ((list = vh_pget(item, "RTASKS")) != NULL) {
        output("   obtained after:\n");
        v_iterate(list, iter) {
            task = vl_iter_pval(iter);
            if ((room = vh_pget(task, "ROOM")) == NULL)
                V_BUF_SET(vh_sgetref(task, "DESC"));
            else
                V_BUF_SETF("%s (%s)",
                           vh_sgetref(task, "DESC"),
                           vh_sgetref(room, "DESC"));
            output("      %s\n", V_BUF_VAL);
        }
    }

    if ((list = vh_pget(item, "TASKS")) != NULL) {
        output("   needed for:\n");
        v_iterate(list, iter) {
            task = vl_iter_pval(iter);
            if ((room = vh_pget(task, "ROOM")) == NULL)
                V_BUF_SET(vh_sgetref(task, "DESC"));
            else
                V_BUF_SETF("%s (%s)",
                           vh_sgetref(task, "DESC"),
                           vh_sgetref(room, "DESC"));
            output("      %s\n", V_BUF_VAL);
        }
    }

    if ((list = vh_pget(item, "NROOMS")) != NULL) {
        output("   needed to enter:\n");
        v_iterate(list, iter) {
            room = vl_iter_pval(iter);
            output("      %s\n", vh_sgetref(room, "DESC"));
        }
    }

    if ((list = vh_pget(item, "NLINKS")) != NULL) {
        output("   needed to move:\n");
        v_iterate(list, iter) {
            reach = vl_iter_pval(iter);
            room = vh_pget(reach, "FROM");
            output("      %s to", vh_sgetref(room, "DESC"));
            room = vh_pget(reach, "TO");
            output(" %s\n", vh_sgetref(room, "DESC"));
        }
    }

    if (notes != NULL) {
        v_iterate(notes, iter)
            output("   note: %s\n", vl_iter_svalref(iter));
    }
}

/* Task functions */
void
text_task_entry(vhash *task)
{
    vlist *triggers = vh_pget(task, "DO");
    vlist *notes = vh_pget(task, "NOTE");
    vhash *room = vh_pget(task, "ROOM");
    vlist *cmds = vh_pget(task, "CMD");
    int type, score;
    vhash *otask;
    char *title;
    viter iter;

    if (taskcount == 0) {
        title = vh_sgetref(map, "TITLE");
        output("Task list for %s\n", title);
    }

    type = vh_iget(task, "TYPE");

    if (type == T_MOVE) {
        if (taskcount == 0)
            output("\nStart: %s\n", vh_sgetref(startroom, "DESC"));

        if (!moved)
            output("\n");

        output("%s", vh_sgetref(task, "DESC"));
        if (cmds != NULL)
            output(" (%s)", vl_join(cmds, ". "));

        output("\n");
        travel++;
        moved++;
    } else {
        if (room != NULL && (moved || room != lastroom))
            output("\n%s:\n", vh_sgetref(room, "DESC"));
        else if (!taskcount)
            output("\nFirstly:\n");

        output("   %s\n", vh_sgetref(task, "DESC"));

        if (cmds != NULL) {
            if (vl_length(cmds) > 0) {
                v_iterate(cmds, iter)
                    output("      cmd: %s\n", vl_iter_svalref(iter));
            } else {
                output("      no action required\n");
            }
        }

        moved = 0;
    }

    if (triggers != NULL) {
        v_iterate(triggers, iter) {
            otask = vl_iter_pval(iter);

            if (type != T_MOVE)
                output("   ");

            output("   also does: %s\n", vh_sgetref(otask, "DESC"));
        }
    }

    if ((score = vh_iget(task, "SCORE")) > 0) {
        if (type != T_MOVE)
            output("   ");

        output("   score: %d\n", score);
    }

    if (notes != NULL) {
        v_iterate(notes, iter) {
            if (type != T_MOVE)
                output("   ");

            output("   note: %s\n", vl_iter_svalref(iter));
        }
    }

    if (room != NULL)
        lastroom = room;

    total += score;
    taskcount++;
}

void
text_task_finish(void)
{
    if (travel > 0)
        output("\nTotal distance travelled: %d\n", travel);
    if (total > 0)
        output("\nTotal score: %d\n", total);
}

/* Initialise text output */
static void
text_init(void)
{
    total = 0;
    travel = 0;
    moved = 0;

    taskcount = 0;
    itemcount = 0;
    sectcount = 0;

    lastroom = NULL;
}
