## Automake template for ifm.

.NOTPARALLEL:

SUBDIRS = libfig libvars

bin_PROGRAMS = ifm

SRCS = ifm-dot.c ifm-fig.c ifm-format.c ifm-main.c ifm-map.c ifm-path.c	\
ifm-ps.c ifm-raw.c ifm-rec.c ifm-task.c ifm-text.c ifm-tk.c ifm-util.c	\
ifm-vars.c ifm-yaml.c

NOLINT_SRCS = ifm-parse.y ifm-scan.l

HDRS = ifm-dot.h ifm-fig.h ifm-format.h ifm-main.h ifm-map.h ifm-parse.h \
ifm-path.h ifm-ps.h ifm-raw.h ifm-rec.h ifm-task.h ifm-text.h ifm-tk.h	 \
ifm-util.h ifm-vars.h ifm-yaml.h

ifm_SOURCES = $(SRCS) $(NOLINT_SRCS) $(HDRS)

EXTRA_DIST = ifm-parse.c ifm-scan.c

FIG_SRC = $(top_srcdir)/src/libfig
FIG_BIN = $(top_builddir)/src/libfig

VARS_SRC = $(top_srcdir)/src/libvars
VARS_BIN = $(top_builddir)/src/libvars

ifm_LDFLAGS = -L$(FIG_BIN) -L$(VARS_BIN)
ifm_LDADD   = -lfig -lvars -lm

AM_YFLAGS = -d -v

if MINGW32
IFMDEFS = -DIFMLIB=ifm
else
IFMDEFS = -DIFMLIB=$(pkgdatadir)
endif

AM_CFLAGS = $(LOCAL_CFLAGS)
AM_CPPFLAGS = -I$(FIG_SRC) -I$(VARS_SRC) $(IFMDEFS) -DVCVERSION="\"$(VCVERSION)\""

$(bin_PROGRAMS): $(VARS_BIN)/libvars.a $(FIG_BIN)/libfig.a

ifm-parse.h: ifm-parse.c

# Version control version stamp.

VCFILE = ifm-main.o
VCVERSION := $(shell $(top_srcdir)/etc/vctag .. 2>/dev/null)

$(VCFILE): stamp-vc

stamp-vc: dummy
	@ test -f $@ || touch $@
	@ echo $(VCVERSION) | cmp -s $@ - || echo $(VCVERSION) > $@

dummy: ;

# Add lint support.

LINT = cppcheck

LINTARGS = --template=gcc -j$(LINTJOBS) --suppressions-list=$(LINTSUPP)
LINTENABLE = style,performance,portability,information
LINTGLOBAL = --platform=unix64 --enable=$(LINTENABLE)

LINTINCLUDE = -I. -I/usr/include -I/usr/include/x86_64-linux-gnu	\
-I/usr/lib/gcc/x86_64-linux-gnu/4.7/include -D__x86_64__ $(CS_INCLUDES)

LINTSUPP = $(top_srcdir)/etc/cppcheck.supp
LINTDEFS = $(CPPFLAGS) $(DEFS) $(AM_CPPFLAGS)
LINTIGNORE = -W% -pthread% -pipe% -g -O%
LINTJOBS = 2

LINTCMD = $(SHELL) $(OPTIONAL) $(LINT) $(LINTARGS) $(filter-out		\
${LINTIGNORE},${LINTDEFS}) $(LINTGLOBAL) $(LINTLOCAL) $(LINTINCLUDE)	\
$(LINTFLAGS) $(LINTEXTRA)

LINTCHECK = LINTEXTRA=--check-config LINTENABLE=information

%.lint: %.c
	@ $(LINTCMD) $<

lint:; $(LINTCMD) $(LINTDEFS) $(SRCS)

# Add emacs flymake support.

check-syntax:
	$(CC) $(AM_CPPFLAGS) -o /dev/null -S $(CHK_SOURCES)

include $(top_srcdir)/etc/Makefile.common

CLEANFILES = *.output

DISTCLEANFILES = ifm-parse.c ifm-parse.h ifm-scan.c stamp-vc
