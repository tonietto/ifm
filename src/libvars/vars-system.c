/*
 * This file is part of IFM (Interactive Fiction Mapper), copyright (C)
 * Glenn Hutchings 1997-2015.
 *
 * IFM comes with ABSOLUTELY NO WARRANTY.  This is free software, and you
 * are welcome to redistribute it under certain conditions; see the file
 * COPYING for details.
 */

/*!
  @defgroup system System functions

  These functions provide an interface to various system functions.
*/

/*!
  @defgroup system_name Filename functions
  @ingroup system
*/

/*!
  @defgroup system_io I/O functions
  @ingroup system
*/

/*!
  @defgroup system_misc Miscellaneous functions
  @ingroup system
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#include "vars-config.h"
#include "vars-buffer.h"
#include "vars-hash.h"
#include "vars-macros.h"
#include "vars-system.h"

#include <sys/types.h>
#include <sys/stat.h>

#ifdef HAVE_GETDATE
#include "getdate.h"
#endif

#ifndef IGNORE_GLOB
#include "glob.h"
#endif

#define INIT_IO                                                         \
        if (pipes == NULL) {                                            \
            pipes = vh_create();                                        \
            pipedata = vh_create();                                     \
            pipelist = vl_create();                                     \
        }

#define STAT_FILE(file)                                                 \
        if (file != NULL)                                               \
            statok = (stat(file, &statbuf) == 0)

#define BUF_APPEND(b, text)                                             \
        do {                                                            \
            if (vb_length(b) > 0) vb_putc(b, ' ');                      \
            vb_puts(b, text);                                           \
        } while (0)

#ifndef GLOB_ABORTED
#define GLOB_ABORTED GLOB_ABEND
#endif

/* File stat buffer */
static struct stat statbuf;

/* Whether last stat was successful */
static int statok = 0;

/*!
  @brief   Return the directory part of a path.
  @ingroup system_name
  @param   path Pathname.
  @return  Directory part (pointer to internal buffer).
*/
char *
v_dirname(char *path)
{
    char *cp = strrchr(path, V_PATHSEP[0]);
    static vbuffer *b = NULL;

    vb_init(b);

    if (cp == path)
        vb_puts(b, V_PATHSEP);
    else if (cp == NULL)
        vb_putc(b, '.');
    else while (path != cp)
        vb_putc(b, *path++);

    return vb_get(b);
}

/*!
  @brief   Return hash of environment variables.
  @ingroup system_misc

  @return  Hash table.
  Each key is the name of an environment variable, and its value is the
  value of the variable.
*/
vhash *
v_environ(void)
{
    /*@i@*/ extern char **environ;
    char *cp, buf[200];
    vhash *env;
    int i;

    env = vh_create();

    for (i = 0; environ[i] != NULL; i++) {
        strcpy(buf, environ[i]);
        if ((cp = strchr(buf, '=')) != NULL) {
            *cp++ = '\0';
            vh_sstore(env, buf, cp);
        }
    }

    return env;
}

/*!
  @brief   Return the filename part of a path.
  @ingroup system_name
  @param   path Pathname.
  @return  Filename part (pointer to internal buffer).
*/
char *
v_filename(char *path)
{
    char *cp = strrchr(path, V_PATHSEP[0]);
    static vbuffer *b = NULL;

    vb_init(b);

    if (cp == NULL)
        cp = path;
    else
        cp++;

    while (*cp != '\0')
        vb_putc(b, *cp++);

    return vb_get(b);
}

/*!
  @brief   Parse a date string into a time value.
  @ingroup system_misc

  @param   string Date specification.
  Can be anything that looks vaguely like a time or date, e.g. '2pm' ,'next
  thursday'.

  @return  Time value.
  @retval  -1 if string doesn't look like a date.
*/
time_t
v_parse_date(char *string)
{
#ifdef HAVE_GETDATE
    return get_date(string, NULL);
#else
    v_unavailable("v_parse_date()");
    return -1;
#endif
}

/*!
  @brief   Return list of \c stat(2) information on a file.
  @ingroup system_io

  @param   file Filename to stat.
  If \c NULL, stat information from the most recent \c stat(2) call is
  used.

  @return  List of stat info (pointer to internal buffer).
  @retval  NULL if the file doesn't exist.

  The list contains the following entries:
      -# device number of filesystem
      -# inode number
      -# file mode (type and permissions)
      -# number of (hard) links to the file
      -# numeric user ID of file's owner
      -# numer group ID of file's owner
      -# the device identifier (special files only)
      -# total size of file, in bytes
      -# last access time since the epoch
      -# last modify time since the epoch
      -# inode change time (NOT creation time!) since the epoch
      -# preferred blocksize for file system I/O
      -# actual number of blocks allocated
*/
vlist *
v_stat(char *file)
{
    static vlist *l = NULL;

    /* Get stat info */
    STAT_FILE(file);
    if (!statok)
        return NULL;

    /* Initialise */
    vl_init(l);

    /* Store info */
    vl_istore(l,  0, (int) statbuf.st_dev);
    vl_istore(l,  1, statbuf.st_ino);
    vl_istore(l,  2, statbuf.st_mode);
    vl_istore(l,  3, statbuf.st_nlink);
    vl_istore(l,  4, statbuf.st_uid);
    vl_istore(l,  5, statbuf.st_gid);

#ifdef HAVE_STRUCT_STAT_ST_RDEV
    vl_istore(l,  6, (int) statbuf.st_rdev);
#endif

    vl_istore(l,  7, statbuf.st_size);
    vl_istore(l,  8, statbuf.st_atime);
    vl_istore(l,  9, statbuf.st_mtime);
    vl_istore(l, 10, statbuf.st_ctime);

#ifdef HAVE_STRUCT_STAT_ST_BLKSIZE
    vl_istore(l, 11, statbuf.st_blksize);
#endif

#ifdef HAVE_STRUCT_STAT_ST_BLOCKS
    vl_istore(l, 12, statbuf.st_blocks);
#endif

    return l;
}

/*!
  @brief   Return the suffix part of a path.
  @ingroup system_name
  @param   path Pathname.
  @return  Suffix part (pointer to internal buffer).
*/
char *
v_suffix(char *path)
{
    char *cp = strrchr(path, '.');
    static vbuffer *b = NULL;

    vb_init(b);

    if (cp != NULL)
        while (*cp != '\0')
            vb_putc(b, *cp++);

    return vb_get(b);
}

/*!
  @brief   Create a temporary file.
  @ingroup system_name
  @param   prefix Prefix to use.
  @param   buffer Buffer to put filename in.

  The file is created in /tmp, or the value of TMPDIR if that is set.

  @return  Buffer (modified).
  @retval  NULL if it failed (and buffer is unchanged).
*/
char *
v_tempfile(char *prefix, char *buffer)
{
    static char tmpbuf[200];
    char *dir;
#ifdef HAVE_MKSTEMP
    int fd;
#endif

    if ((dir = getenv("TMPDIR")) == NULL)
        dir = V_TEMPDIR;

    sprintf(tmpbuf, "%s%s%s.XXXXXX", dir, V_PATHSEP, prefix);

#ifdef HAVE_MKSTEMP
    if ((fd = mkstemp(tmpbuf)) >= 0) {
        strcpy(buffer, tmpbuf);
        close(fd);
    }
#else
    strcpy(buffer, mktemp(tmpbuf));
#endif    

    return buffer;
}

/*!
  @brief   Test a file for various attributes, via \c stat(2).
  @ingroup system_io

  @param   file Pathname to test.
  If \c NULL, the results of the most recent \c stat(2) are used.

  @param   test Type of test.
  @return  Yes or no.
*/
int
v_test(char *file, enum v_testtype test)
{
    int retval = 0;

    /* Stat the file */
    STAT_FILE(file);
    if (!statok)
        return 0;

    /* Do the test */
    switch (test) {
    case V_TEST_EXISTS:
        retval = 1;
        break;
    case V_TEST_DIR:
        retval = S_ISDIR(statbuf.st_mode);
        break;
    case V_TEST_CHR:
        retval = S_ISCHR(statbuf.st_mode);
        break;
    case V_TEST_BLK:
        retval = S_ISBLK(statbuf.st_mode);
        break;
    case V_TEST_REG:
        retval = S_ISREG(statbuf.st_mode);
        break;
    case V_TEST_FIFO:
        retval = S_ISFIFO(statbuf.st_mode);
        break;
    default:
        v_exception("v_test(): invalid test type");
        break;
    }

    return retval;
}
