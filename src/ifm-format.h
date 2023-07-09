/*
 * This file is part of IFM (Interactive Fiction Mapper), copyright (C)
 * Glenn Hutchings 1997-2015.
 *
 * IFM comes with ABSOLUTELY NO WARRANTY.  This is free software, and you
 * are welcome to redistribute it under certain conditions; see the file
 * COPYING for details.
 */

/* Output format definitions */

#ifndef IFM_FORMAT_H
#define IFM_FORMAT_H

/* Format structs */
typedef struct outputfuncs_st {
    void (*output_start)(void);
    void (*output_finish)(void);
} outputfuncs;

typedef struct mapfuncs_st {
    void (*map_start)(void);
    void (*map_section)(vhash *sect);
    void (*map_room)(vhash *room);
    void (*map_link)(vhash *link);
    void (*map_join)(vhash *join);
    void (*map_endsection)(void);
    void (*map_finish)(void);
} mapfuncs;

typedef struct itemfuncs_st {
    void (*item_start)(void);
    void (*item_entry)(vhash *item);
    void (*item_finish)(void);
} itemfuncs;

typedef struct taskfuncs_st {
    void (*task_start)(void);
    void (*task_entry)(vhash *task);
    void (*task_finish)(void);
} taskfuncs;

typedef struct errfuncs_st {
    void (*warning)(char *file, int line, char *msg);
    void (*error)(char *file, int line, char *msg);
} errfuncs;

typedef struct format_st {
    char *name, *desc;
    outputfuncs *ofunc;
    mapfuncs    *mfunc;
    itemfuncs   *ifunc;
    taskfuncs   *tfunc;
    errfuncs    *efunc;
} format;

/* Format list */
extern format formats[];

/* Control variables */
extern char *room_text_font, *room_text_colour, *room_colour;
extern char *room_border_colour, *room_shadow_colour, *item_text_font;
extern char *item_text_colour, *link_colour, *link_text_colour;
extern char *link_text_font, *link_updown_string, *link_inout_string;
extern char *map_title_font, *page_border_colour, *page_background_colour;
extern char *page_title_font, *page_title_colour, *map_title_colour;
extern char *room_exit_colour, *page_size, *map_border_colour;
extern char *map_background_colour;

extern float room_text_fontsize, room_border_width, room_shadow_xoff;
extern float room_shadow_yoff, room_exit_width, item_text_fontsize;
extern float link_arrow_size, link_text_fontsize, link_line_width;
extern float map_title_fontsize, page_title_fontsize, font_scale, page_margin;
extern float room_width, room_height, room_size, page_width, page_height;

extern int room_border_dashed, show_items, link_dashed, show_page_border;
extern int show_page_title, show_tags, link_spline, show_map_title;
extern int show_map_border;

/* Advertised functions */
extern void set_map_vars(void);
extern void set_room_vars(void);
extern void set_link_vars(void);
extern void print_start(int dnum);
extern void print_map(int dnum, vlist *sections);
extern void print_items(int dnum);
extern void print_tasks(int dnum);
extern void print_finish(int dnum);

#endif
