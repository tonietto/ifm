# Makefile.in generated by automake 1.16.1 from Makefile.am.
# src/Makefile.  Generated from Makefile.in by configure.

# Copyright (C) 1994-2018 Free Software Foundation, Inc.

# This Makefile.in is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.



# Common Makefile stuff.


am__is_gnu_make = { \
  if test -z '$(MAKELEVEL)'; then \
    false; \
  elif test -n '$(MAKE_HOST)'; then \
    true; \
  elif test -n '$(MAKE_VERSION)' && test -n '$(CURDIR)'; then \
    true; \
  else \
    false; \
  fi; \
}
am__make_running_with_option = \
  case $${target_option-} in \
      ?) ;; \
      *) echo "am__make_running_with_option: internal error: invalid" \
              "target option '$${target_option-}' specified" >&2; \
         exit 1;; \
  esac; \
  has_opt=no; \
  sane_makeflags=$$MAKEFLAGS; \
  if $(am__is_gnu_make); then \
    sane_makeflags=$$MFLAGS; \
  else \
    case $$MAKEFLAGS in \
      *\\[\ \	]*) \
        bs=\\; \
        sane_makeflags=`printf '%s\n' "$$MAKEFLAGS" \
          | sed "s/$$bs$$bs[$$bs $$bs	]*//g"`;; \
    esac; \
  fi; \
  skip_next=no; \
  strip_trailopt () \
  { \
    flg=`printf '%s\n' "$$flg" | sed "s/$$1.*$$//"`; \
  }; \
  for flg in $$sane_makeflags; do \
    test $$skip_next = yes && { skip_next=no; continue; }; \
    case $$flg in \
      *=*|--*) continue;; \
        -*I) strip_trailopt 'I'; skip_next=yes;; \
      -*I?*) strip_trailopt 'I';; \
        -*O) strip_trailopt 'O'; skip_next=yes;; \
      -*O?*) strip_trailopt 'O';; \
        -*l) strip_trailopt 'l'; skip_next=yes;; \
      -*l?*) strip_trailopt 'l';; \
      -[dEDm]) skip_next=yes;; \
      -[JT]) skip_next=yes;; \
    esac; \
    case $$flg in \
      *$$target_option*) has_opt=yes; break;; \
    esac; \
  done; \
  test $$has_opt = yes
am__make_dryrun = (target_option=n; $(am__make_running_with_option))
am__make_keepgoing = (target_option=k; $(am__make_running_with_option))
pkgdatadir = $(datadir)/ifm
pkgincludedir = $(includedir)/ifm
pkglibdir = $(libdir)/ifm
pkglibexecdir = $(libexecdir)/ifm
am__cd = CDPATH="$${ZSH_VERSION+.}$(PATH_SEPARATOR)" && cd
install_sh_DATA = $(install_sh) -c -m 644
install_sh_PROGRAM = $(install_sh) -c
install_sh_SCRIPT = $(install_sh) -c
INSTALL_HEADER = $(INSTALL_DATA)
transform = $(program_transform_name)
NORMAL_INSTALL = :
PRE_INSTALL = :
POST_INSTALL = :
NORMAL_UNINSTALL = :
PRE_UNINSTALL = :
POST_UNINSTALL = :
build_triplet = arm-apple-darwin22.5.0
host_triplet = arm-apple-darwin22.5.0
bin_PROGRAMS = ifm$(EXEEXT)
subdir = src
ACLOCAL_M4 = $(top_srcdir)/aclocal.m4
am__aclocal_m4_deps = $(top_srcdir)/etc/ccoption.m4 \
	$(top_srcdir)/configure.ac
am__configure_deps = $(am__aclocal_m4_deps) $(CONFIGURE_DEPENDENCIES) \
	$(ACLOCAL_M4)
DIST_COMMON = $(srcdir)/Makefile.am $(am__DIST_COMMON)
mkinstalldirs = $(install_sh) -d
CONFIG_HEADER = $(top_builddir)/etc/config.h
CONFIG_CLEAN_FILES =
CONFIG_CLEAN_VPATH_FILES =
am__installdirs = "$(DESTDIR)$(bindir)"
PROGRAMS = $(bin_PROGRAMS)
am__objects_1 = ifm-dot.$(OBJEXT) ifm-fig.$(OBJEXT) \
	ifm-format.$(OBJEXT) ifm-main.$(OBJEXT) ifm-map.$(OBJEXT) \
	ifm-path.$(OBJEXT) ifm-ps.$(OBJEXT) ifm-raw.$(OBJEXT) \
	ifm-rec.$(OBJEXT) ifm-task.$(OBJEXT) ifm-text.$(OBJEXT) \
	ifm-tk.$(OBJEXT) ifm-util.$(OBJEXT) ifm-vars.$(OBJEXT) \
	ifm-yaml.$(OBJEXT)
am__objects_2 = ifm-parse.$(OBJEXT) ifm-scan.$(OBJEXT)
am__objects_3 =
am_ifm_OBJECTS = $(am__objects_1) $(am__objects_2) $(am__objects_3)
ifm_OBJECTS = $(am_ifm_OBJECTS)
ifm_DEPENDENCIES =
ifm_LINK = $(CCLD) $(AM_CFLAGS) $(CFLAGS) $(ifm_LDFLAGS) $(LDFLAGS) -o \
	$@
AM_V_P = $(am__v_P_$(V))
am__v_P_ = $(am__v_P_$(AM_DEFAULT_VERBOSITY))
am__v_P_0 = false
am__v_P_1 = :
AM_V_GEN = $(am__v_GEN_$(V))
am__v_GEN_ = $(am__v_GEN_$(AM_DEFAULT_VERBOSITY))
am__v_GEN_0 = @echo "  GEN     " $@;
am__v_GEN_1 = 
AM_V_at = $(am__v_at_$(V))
am__v_at_ = $(am__v_at_$(AM_DEFAULT_VERBOSITY))
am__v_at_0 = @
am__v_at_1 = 
DEFAULT_INCLUDES = -I. -I$(top_builddir)/etc
depcomp = $(SHELL) $(top_srcdir)/etc/depcomp
am__maybe_remake_depfiles = depfiles
am__depfiles_remade = ./$(DEPDIR)/ifm-dot.Po ./$(DEPDIR)/ifm-fig.Po \
	./$(DEPDIR)/ifm-format.Po ./$(DEPDIR)/ifm-main.Po \
	./$(DEPDIR)/ifm-map.Po ./$(DEPDIR)/ifm-parse.Po \
	./$(DEPDIR)/ifm-path.Po ./$(DEPDIR)/ifm-ps.Po \
	./$(DEPDIR)/ifm-raw.Po ./$(DEPDIR)/ifm-rec.Po \
	./$(DEPDIR)/ifm-scan.Po ./$(DEPDIR)/ifm-task.Po \
	./$(DEPDIR)/ifm-text.Po ./$(DEPDIR)/ifm-tk.Po \
	./$(DEPDIR)/ifm-util.Po ./$(DEPDIR)/ifm-vars.Po \
	./$(DEPDIR)/ifm-yaml.Po
am__mv = mv -f
COMPILE = $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) \
	$(CPPFLAGS) $(AM_CFLAGS) $(CFLAGS)
AM_V_CC = $(am__v_CC_$(V))
am__v_CC_ = $(am__v_CC_$(AM_DEFAULT_VERBOSITY))
am__v_CC_0 = @echo "  CC      " $@;
am__v_CC_1 = 
CCLD = $(CC)
LINK = $(CCLD) $(AM_CFLAGS) $(CFLAGS) $(AM_LDFLAGS) $(LDFLAGS) -o $@
AM_V_CCLD = $(am__v_CCLD_$(V))
am__v_CCLD_ = $(am__v_CCLD_$(AM_DEFAULT_VERBOSITY))
am__v_CCLD_0 = @echo "  CCLD    " $@;
am__v_CCLD_1 = 
LEXCOMPILE = $(LEX) $(AM_LFLAGS) $(LFLAGS)
AM_V_LEX = $(am__v_LEX_$(V))
am__v_LEX_ = $(am__v_LEX_$(AM_DEFAULT_VERBOSITY))
am__v_LEX_0 = @echo "  LEX     " $@;
am__v_LEX_1 = 
YLWRAP = $(top_srcdir)/etc/ylwrap
am__yacc_c2h = sed -e s/cc$$/hh/ -e s/cpp$$/hpp/ -e s/cxx$$/hxx/ \
		   -e s/c++$$/h++/ -e s/c$$/h/
YACCCOMPILE = $(YACC) $(AM_YFLAGS) $(YFLAGS)
AM_V_YACC = $(am__v_YACC_$(V))
am__v_YACC_ = $(am__v_YACC_$(AM_DEFAULT_VERBOSITY))
am__v_YACC_0 = @echo "  YACC    " $@;
am__v_YACC_1 = 
SOURCES = $(ifm_SOURCES)
DIST_SOURCES = $(ifm_SOURCES)
RECURSIVE_TARGETS = all-recursive check-recursive cscopelist-recursive \
	ctags-recursive dvi-recursive html-recursive info-recursive \
	install-data-recursive install-dvi-recursive \
	install-exec-recursive install-html-recursive \
	install-info-recursive install-pdf-recursive \
	install-ps-recursive install-recursive installcheck-recursive \
	installdirs-recursive pdf-recursive ps-recursive \
	tags-recursive uninstall-recursive
am__can_run_installinfo = \
  case $$AM_UPDATE_INFO_DIR in \
    n|no|NO) false;; \
    *) (install-info --version) >/dev/null 2>&1;; \
  esac
RECURSIVE_CLEAN_TARGETS = mostlyclean-recursive clean-recursive	\
  distclean-recursive maintainer-clean-recursive
am__recursive_targets = \
  $(RECURSIVE_TARGETS) \
  $(RECURSIVE_CLEAN_TARGETS) \
  $(am__extra_recursive_targets)
AM_RECURSIVE_TARGETS = $(am__recursive_targets:-recursive=) TAGS CTAGS \
	distdir distdir-am
am__tagged_files = $(HEADERS) $(SOURCES) $(TAGS_FILES) $(LISP)
# Read a list of newline-separated strings from the standard input,
# and print each of them once, without duplicates.  Input order is
# *not* preserved.
am__uniquify_input = $(AWK) '\
  BEGIN { nonempty = 0; } \
  { items[$$0] = 1; nonempty = 1; } \
  END { if (nonempty) { for (i in items) print i; }; } \
'
# Make sure the list of sources is unique.  This is necessary because,
# e.g., the same source file might be shared among _SOURCES variables
# for different programs/libraries.
am__define_uniq_tagged_files = \
  list='$(am__tagged_files)'; \
  unique=`for i in $$list; do \
    if test -f "$$i"; then echo $$i; else echo $(srcdir)/$$i; fi; \
  done | $(am__uniquify_input)`
ETAGS = etags
CTAGS = ctags
DIST_SUBDIRS = $(SUBDIRS)
am__DIST_COMMON = $(srcdir)/Makefile.in \
	$(top_srcdir)/etc/Makefile.common $(top_srcdir)/etc/depcomp \
	$(top_srcdir)/etc/ylwrap ifm-parse.c ifm-parse.h ifm-scan.c
DISTFILES = $(DIST_COMMON) $(DIST_SOURCES) $(TEXINFOS) $(EXTRA_DIST)
am__relativize = \
  dir0=`pwd`; \
  sed_first='s,^\([^/]*\)/.*$$,\1,'; \
  sed_rest='s,^[^/]*/*,,'; \
  sed_last='s,^.*/\([^/]*\)$$,\1,'; \
  sed_butlast='s,/*[^/]*$$,,'; \
  while test -n "$$dir1"; do \
    first=`echo "$$dir1" | sed -e "$$sed_first"`; \
    if test "$$first" != "."; then \
      if test "$$first" = ".."; then \
        dir2=`echo "$$dir0" | sed -e "$$sed_last"`/"$$dir2"; \
        dir0=`echo "$$dir0" | sed -e "$$sed_butlast"`; \
      else \
        first2=`echo "$$dir2" | sed -e "$$sed_first"`; \
        if test "$$first2" = "$$first"; then \
          dir2=`echo "$$dir2" | sed -e "$$sed_rest"`; \
        else \
          dir2="../$$dir2"; \
        fi; \
        dir0="$$dir0"/"$$first"; \
      fi; \
    fi; \
    dir1=`echo "$$dir1" | sed -e "$$sed_rest"`; \
  done; \
  reldir="$$dir2"
ACLOCAL = ${SHELL} /Users/tonietto/Downloads/ifm-5.5/etc/missing aclocal-1.16
ALLOCA = 
AMTAR = $${TAR-tar}
AM_DEFAULT_VERBOSITY = 1
AUTOCONF = ${SHELL} /Users/tonietto/Downloads/ifm-5.5/etc/missing autoconf
AUTOHEADER = ${SHELL} /Users/tonietto/Downloads/ifm-5.5/etc/missing autoheader
AUTOMAKE = ${SHELL} /Users/tonietto/Downloads/ifm-5.5/etc/missing automake-1.16
AWK = awk
CC = gcc
CCDEPMODE = depmode=gcc3
CFLAGS = -g -O2
CPP = gcc -E
CPPFLAGS = 
CYGPATH_W = echo
DEFS = -DHAVE_CONFIG_H
DEPDIR = .deps
ECHO_C = \c
ECHO_N = 
ECHO_T = 
EGREP = /usr/bin/grep -E
EXEEXT = 
GREP = /usr/bin/grep
INSTALL = /usr/bin/install -c
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_PROGRAM = ${INSTALL}
INSTALL_SCRIPT = ${INSTALL}
INSTALL_STRIP_PROGRAM = $(install_sh) -c -s
LDFLAGS = 
LEX = flex
LEXLIB = -ll
LEX_OUTPUT_ROOT = lex.yy
LIBOBJS = 
LIBS = 
LOCAL_CFLAGS =  -pipe -W -Wall -Werror-implicit-function-declaration -Wno-multistatement-macros -Wno-sign-compare -Wno-switch -Wno-unknown-warning-option -Wno-unused-but-set-variable -Wno-unused-parameter -Wno-unused-value
LTLIBOBJS = 
MAKEINFO = ${SHELL} /Users/tonietto/Downloads/ifm-5.5/etc/missing makeinfo
MKDIR_P = /opt/homebrew/bin/gmkdir -p
OBJEXT = o
PACKAGE = ifm
PACKAGE_BUGREPORT = zondo42@gmail.com
PACKAGE_NAME = ifm
PACKAGE_STRING = ifm 5.5
PACKAGE_TARNAME = ifm
PACKAGE_URL = 
PACKAGE_VERSION = 5.5
PANDOC = no
PATH_SEPARATOR = :
PERL = /usr/bin/perl
PYTHON = /usr/bin/python3
PYTHON_EXEC_PREFIX = ${exec_prefix}
PYTHON_PLATFORM = darwin
PYTHON_PREFIX = ${prefix}
PYTHON_VERSION = 3.9
RANLIB = ranlib
SET_MAKE = 
SHELL = /bin/sh
STRIP = 
VERSION = 5.5
WISH = /usr/bin/wish
YACC = bison -y
YFLAGS = 
abs_builddir = /Users/tonietto/Downloads/ifm-5.5/src
abs_srcdir = /Users/tonietto/Downloads/ifm-5.5/src
abs_top_builddir = /Users/tonietto/Downloads/ifm-5.5
abs_top_srcdir = /Users/tonietto/Downloads/ifm-5.5
ac_ct_CC = gcc
am__include = include
am__leading_dot = .
am__quote = 
am__tar = $${TAR-tar} chof - "$$tardir"
am__untar = $${TAR-tar} xf -
bindir = ${exec_prefix}/bin
build = arm-apple-darwin22.5.0
build_alias = 
build_cpu = arm
build_os = darwin22.5.0
build_vendor = apple
builddir = .
datadir = ${datarootdir}
datarootdir = ${prefix}/share
docdir = $(prefix)/doc
dvidir = ${docdir}
exec_prefix = ${prefix}
host = arm-apple-darwin22.5.0
host_alias = 
host_cpu = arm
host_os = darwin22.5.0
host_vendor = apple
htmldir = ${docdir}
ifm2dev = ifm2dev
ifm2tex = ifm2tex
ifm2web = ifm2web
includedir = ${prefix}/include
infodir = ${datarootdir}/info
install_sh = ${SHELL} /Users/tonietto/Downloads/ifm-5.5/etc/install-sh
libdir = ${exec_prefix}/lib
libexecdir = ${exec_prefix}/libexec
localedir = ${datarootdir}/locale
localstatedir = ${prefix}/var
mandir = ${datarootdir}/man
mkdir_p = $(MKDIR_P)
oldincludedir = /usr/include
pdfdir = ${docdir}
pkgpyexecdir = ${pyexecdir}/ifm
pkgpythondir = ${pythondir}/ifm
prefix = /usr/local
program_transform_name = s,x,x,
psdir = ${docdir}
pyexecdir = ${exec_prefix}/lib/python3.9/site-packages
pythondir = ${prefix}/lib/python3.9/site-packages
runstatedir = ${localstatedir}/run
sbindir = ${exec_prefix}/sbin
scr2ifm = scr2ifm
sharedstatedir = ${prefix}/com
srcdir = .
sysconfdir = ${prefix}/etc
target_alias = 
tkifm = tkifm
top_build_prefix = ../
top_builddir = ..
top_srcdir = ..
SUBDIRS = libfig libvars
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
ifm_LDADD = -lfig -lvars -lm
AM_YFLAGS = -d -v
IFMDEFS = -DIFMLIB=$(pkgdatadir)
#IFMDEFS = -DIFMLIB=ifm
AM_CFLAGS = $(LOCAL_CFLAGS)
AM_CPPFLAGS = -I$(FIG_SRC) -I$(VARS_SRC) $(IFMDEFS) -DVCVERSION="\"$(VCVERSION)\""

# Version control version stamp.
VCFILE = ifm-main.o
VCVERSION := $(shell $(top_srcdir)/etc/vctag .. 2>/dev/null)

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
ifmdocdir = $(docdir)/ifm
OPTIONAL = $(top_srcdir)/etc/missing --run
CLEANFILES = *.output
DISTCLEANFILES = ifm-parse.c ifm-parse.h ifm-scan.c stamp-vc
all: all-recursive

.SUFFIXES:
.SUFFIXES: .c .l .o .obj .y
$(srcdir)/Makefile.in:  $(srcdir)/Makefile.am $(top_srcdir)/etc/Makefile.common $(am__configure_deps)
	@for dep in $?; do \
	  case '$(am__configure_deps)' in \
	    *$$dep*) \
	      ( cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh ) \
	        && { if test -f $@; then exit 0; else break; fi; }; \
	      exit 1;; \
	  esac; \
	done; \
	echo ' cd $(top_srcdir) && $(AUTOMAKE) --foreign src/Makefile'; \
	$(am__cd) $(top_srcdir) && \
	  $(AUTOMAKE) --foreign src/Makefile
Makefile: $(srcdir)/Makefile.in $(top_builddir)/config.status
	@case '$?' in \
	  *config.status*) \
	    cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh;; \
	  *) \
	    echo ' cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@ $(am__maybe_remake_depfiles)'; \
	    cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@ $(am__maybe_remake_depfiles);; \
	esac;
$(top_srcdir)/etc/Makefile.common $(am__empty):

$(top_builddir)/config.status: $(top_srcdir)/configure $(CONFIG_STATUS_DEPENDENCIES)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh

$(top_srcdir)/configure:  $(am__configure_deps)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh
$(ACLOCAL_M4):  $(am__aclocal_m4_deps)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh
$(am__aclocal_m4_deps):
install-binPROGRAMS: $(bin_PROGRAMS)
	@$(NORMAL_INSTALL)
	@list='$(bin_PROGRAMS)'; test -n "$(bindir)" || list=; \
	if test -n "$$list"; then \
	  echo " $(MKDIR_P) '$(DESTDIR)$(bindir)'"; \
	  $(MKDIR_P) "$(DESTDIR)$(bindir)" || exit 1; \
	fi; \
	for p in $$list; do echo "$$p $$p"; done | \
	sed 's/$(EXEEXT)$$//' | \
	while read p p1; do if test -f $$p \
	  ; then echo "$$p"; echo "$$p"; else :; fi; \
	done | \
	sed -e 'p;s,.*/,,;n;h' \
	    -e 's|.*|.|' \
	    -e 'p;x;s,.*/,,;s/$(EXEEXT)$$//;$(transform);s/$$/$(EXEEXT)/' | \
	sed 'N;N;N;s,\n, ,g' | \
	$(AWK) 'BEGIN { files["."] = ""; dirs["."] = 1 } \
	  { d=$$3; if (dirs[d] != 1) { print "d", d; dirs[d] = 1 } \
	    if ($$2 == $$4) files[d] = files[d] " " $$1; \
	    else { print "f", $$3 "/" $$4, $$1; } } \
	  END { for (d in files) print "f", d, files[d] }' | \
	while read type dir files; do \
	    if test "$$dir" = .; then dir=; else dir=/$$dir; fi; \
	    test -z "$$files" || { \
	      echo " $(INSTALL_PROGRAM_ENV) $(INSTALL_PROGRAM) $$files '$(DESTDIR)$(bindir)$$dir'"; \
	      $(INSTALL_PROGRAM_ENV) $(INSTALL_PROGRAM) $$files "$(DESTDIR)$(bindir)$$dir" || exit $$?; \
	    } \
	; done

uninstall-binPROGRAMS:
	@$(NORMAL_UNINSTALL)
	@list='$(bin_PROGRAMS)'; test -n "$(bindir)" || list=; \
	files=`for p in $$list; do echo "$$p"; done | \
	  sed -e 'h;s,^.*/,,;s/$(EXEEXT)$$//;$(transform)' \
	      -e 's/$$/$(EXEEXT)/' \
	`; \
	test -n "$$list" || exit 0; \
	echo " ( cd '$(DESTDIR)$(bindir)' && rm -f" $$files ")"; \
	cd "$(DESTDIR)$(bindir)" && rm -f $$files

clean-binPROGRAMS:
	-test -z "$(bin_PROGRAMS)" || rm -f $(bin_PROGRAMS)

ifm$(EXEEXT): $(ifm_OBJECTS) $(ifm_DEPENDENCIES) $(EXTRA_ifm_DEPENDENCIES) 
	@rm -f ifm$(EXEEXT)
	$(AM_V_CCLD)$(ifm_LINK) $(ifm_OBJECTS) $(ifm_LDADD) $(LIBS)

mostlyclean-compile:
	-rm -f *.$(OBJEXT)

distclean-compile:
	-rm -f *.tab.c

include ./$(DEPDIR)/ifm-dot.Po # am--include-marker
include ./$(DEPDIR)/ifm-fig.Po # am--include-marker
include ./$(DEPDIR)/ifm-format.Po # am--include-marker
include ./$(DEPDIR)/ifm-main.Po # am--include-marker
include ./$(DEPDIR)/ifm-map.Po # am--include-marker
include ./$(DEPDIR)/ifm-parse.Po # am--include-marker
include ./$(DEPDIR)/ifm-path.Po # am--include-marker
include ./$(DEPDIR)/ifm-ps.Po # am--include-marker
include ./$(DEPDIR)/ifm-raw.Po # am--include-marker
include ./$(DEPDIR)/ifm-rec.Po # am--include-marker
include ./$(DEPDIR)/ifm-scan.Po # am--include-marker
include ./$(DEPDIR)/ifm-task.Po # am--include-marker
include ./$(DEPDIR)/ifm-text.Po # am--include-marker
include ./$(DEPDIR)/ifm-tk.Po # am--include-marker
include ./$(DEPDIR)/ifm-util.Po # am--include-marker
include ./$(DEPDIR)/ifm-vars.Po # am--include-marker
include ./$(DEPDIR)/ifm-yaml.Po # am--include-marker

$(am__depfiles_remade):
	@$(MKDIR_P) $(@D)
	@echo '# dummy' >$@-t && $(am__mv) $@-t $@

am--depfiles: $(am__depfiles_remade)

.c.o:
	$(AM_V_CC)$(COMPILE) -MT $@ -MD -MP -MF $(DEPDIR)/$*.Tpo -c -o $@ $<
	$(AM_V_at)$(am__mv) $(DEPDIR)/$*.Tpo $(DEPDIR)/$*.Po
#	$(AM_V_CC)source='$<' object='$@' libtool=no \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(AM_V_CC_no)$(COMPILE) -c -o $@ $<

.c.obj:
	$(AM_V_CC)$(COMPILE) -MT $@ -MD -MP -MF $(DEPDIR)/$*.Tpo -c -o $@ `$(CYGPATH_W) '$<'`
	$(AM_V_at)$(am__mv) $(DEPDIR)/$*.Tpo $(DEPDIR)/$*.Po
#	$(AM_V_CC)source='$<' object='$@' libtool=no \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(AM_V_CC_no)$(COMPILE) -c -o $@ `$(CYGPATH_W) '$<'`

.l.c:
	$(AM_V_LEX)$(am__skiplex) $(SHELL) $(YLWRAP) $< $(LEX_OUTPUT_ROOT).c $@ -- $(LEXCOMPILE)

.y.c:
	$(AM_V_YACC)$(am__skipyacc) $(SHELL) $(YLWRAP) $< y.tab.c $@ y.tab.h `echo $@ | $(am__yacc_c2h)` y.output $*.output -- $(YACCCOMPILE)

# This directory's subdirectories are mostly independent; you can cd
# into them and run 'make' without going through this Makefile.
# To change the values of 'make' variables: instead of editing Makefiles,
# (1) if the variable is set in 'config.status', edit 'config.status'
#     (which will cause the Makefiles to be regenerated when you run 'make');
# (2) otherwise, pass the desired values on the 'make' command line.
$(am__recursive_targets):
	@fail=; \
	if $(am__make_keepgoing); then \
	  failcom='fail=yes'; \
	else \
	  failcom='exit 1'; \
	fi; \
	dot_seen=no; \
	target=`echo $@ | sed s/-recursive//`; \
	case "$@" in \
	  distclean-* | maintainer-clean-*) list='$(DIST_SUBDIRS)' ;; \
	  *) list='$(SUBDIRS)' ;; \
	esac; \
	for subdir in $$list; do \
	  echo "Making $$target in $$subdir"; \
	  if test "$$subdir" = "."; then \
	    dot_seen=yes; \
	    local_target="$$target-am"; \
	  else \
	    local_target="$$target"; \
	  fi; \
	  ($(am__cd) $$subdir && $(MAKE) $(AM_MAKEFLAGS) $$local_target) \
	  || eval $$failcom; \
	done; \
	if test "$$dot_seen" = "no"; then \
	  $(MAKE) $(AM_MAKEFLAGS) "$$target-am" || exit 1; \
	fi; test -z "$$fail"

ID: $(am__tagged_files)
	$(am__define_uniq_tagged_files); mkid -fID $$unique
tags: tags-recursive
TAGS: tags

tags-am: $(TAGS_DEPENDENCIES) $(am__tagged_files)
	set x; \
	here=`pwd`; \
	if ($(ETAGS) --etags-include --version) >/dev/null 2>&1; then \
	  include_option=--etags-include; \
	  empty_fix=.; \
	else \
	  include_option=--include; \
	  empty_fix=; \
	fi; \
	list='$(SUBDIRS)'; for subdir in $$list; do \
	  if test "$$subdir" = .; then :; else \
	    test ! -f $$subdir/TAGS || \
	      set "$$@" "$$include_option=$$here/$$subdir/TAGS"; \
	  fi; \
	done; \
	$(am__define_uniq_tagged_files); \
	shift; \
	if test -z "$(ETAGS_ARGS)$$*$$unique"; then :; else \
	  test -n "$$unique" || unique=$$empty_fix; \
	  if test $$# -gt 0; then \
	    $(ETAGS) $(ETAGSFLAGS) $(AM_ETAGSFLAGS) $(ETAGS_ARGS) \
	      "$$@" $$unique; \
	  else \
	    $(ETAGS) $(ETAGSFLAGS) $(AM_ETAGSFLAGS) $(ETAGS_ARGS) \
	      $$unique; \
	  fi; \
	fi
ctags: ctags-recursive

CTAGS: ctags
ctags-am: $(TAGS_DEPENDENCIES) $(am__tagged_files)
	$(am__define_uniq_tagged_files); \
	test -z "$(CTAGS_ARGS)$$unique" \
	  || $(CTAGS) $(CTAGSFLAGS) $(AM_CTAGSFLAGS) $(CTAGS_ARGS) \
	     $$unique

GTAGS:
	here=`$(am__cd) $(top_builddir) && pwd` \
	  && $(am__cd) $(top_srcdir) \
	  && gtags -i $(GTAGS_ARGS) "$$here"
cscopelist: cscopelist-recursive

cscopelist-am: $(am__tagged_files)
	list='$(am__tagged_files)'; \
	case "$(srcdir)" in \
	  [\\/]* | ?:[\\/]*) sdir="$(srcdir)" ;; \
	  *) sdir=$(subdir)/$(srcdir) ;; \
	esac; \
	for i in $$list; do \
	  if test -f "$$i"; then \
	    echo "$(subdir)/$$i"; \
	  else \
	    echo "$$sdir/$$i"; \
	  fi; \
	done >> $(top_builddir)/cscope.files

distclean-tags:
	-rm -f TAGS ID GTAGS GRTAGS GSYMS GPATH tags

distdir: $(BUILT_SOURCES)
	$(MAKE) $(AM_MAKEFLAGS) distdir-am

distdir-am: $(DISTFILES)
	@srcdirstrip=`echo "$(srcdir)" | sed 's/[].[^$$\\*]/\\\\&/g'`; \
	topsrcdirstrip=`echo "$(top_srcdir)" | sed 's/[].[^$$\\*]/\\\\&/g'`; \
	list='$(DISTFILES)'; \
	  dist_files=`for file in $$list; do echo $$file; done | \
	  sed -e "s|^$$srcdirstrip/||;t" \
	      -e "s|^$$topsrcdirstrip/|$(top_builddir)/|;t"`; \
	case $$dist_files in \
	  */*) $(MKDIR_P) `echo "$$dist_files" | \
			   sed '/\//!d;s|^|$(distdir)/|;s,/[^/]*$$,,' | \
			   sort -u` ;; \
	esac; \
	for file in $$dist_files; do \
	  if test -f $$file || test -d $$file; then d=.; else d=$(srcdir); fi; \
	  if test -d $$d/$$file; then \
	    dir=`echo "/$$file" | sed -e 's,/[^/]*$$,,'`; \
	    if test -d "$(distdir)/$$file"; then \
	      find "$(distdir)/$$file" -type d ! -perm -700 -exec chmod u+rwx {} \;; \
	    fi; \
	    if test -d $(srcdir)/$$file && test $$d != $(srcdir); then \
	      cp -fpR $(srcdir)/$$file "$(distdir)$$dir" || exit 1; \
	      find "$(distdir)/$$file" -type d ! -perm -700 -exec chmod u+rwx {} \;; \
	    fi; \
	    cp -fpR $$d/$$file "$(distdir)$$dir" || exit 1; \
	  else \
	    test -f "$(distdir)/$$file" \
	    || cp -p $$d/$$file "$(distdir)/$$file" \
	    || exit 1; \
	  fi; \
	done
	@list='$(DIST_SUBDIRS)'; for subdir in $$list; do \
	  if test "$$subdir" = .; then :; else \
	    $(am__make_dryrun) \
	      || test -d "$(distdir)/$$subdir" \
	      || $(MKDIR_P) "$(distdir)/$$subdir" \
	      || exit 1; \
	    dir1=$$subdir; dir2="$(distdir)/$$subdir"; \
	    $(am__relativize); \
	    new_distdir=$$reldir; \
	    dir1=$$subdir; dir2="$(top_distdir)"; \
	    $(am__relativize); \
	    new_top_distdir=$$reldir; \
	    echo " (cd $$subdir && $(MAKE) $(AM_MAKEFLAGS) top_distdir="$$new_top_distdir" distdir="$$new_distdir" \\"; \
	    echo "     am__remove_distdir=: am__skip_length_check=: am__skip_mode_fix=: distdir)"; \
	    ($(am__cd) $$subdir && \
	      $(MAKE) $(AM_MAKEFLAGS) \
	        top_distdir="$$new_top_distdir" \
	        distdir="$$new_distdir" \
		am__remove_distdir=: \
		am__skip_length_check=: \
		am__skip_mode_fix=: \
	        distdir) \
	      || exit 1; \
	  fi; \
	done
check-am: all-am
check: check-recursive
all-am: Makefile $(PROGRAMS)
installdirs: installdirs-recursive
installdirs-am:
	for dir in "$(DESTDIR)$(bindir)"; do \
	  test -z "$$dir" || $(MKDIR_P) "$$dir"; \
	done
install: install-recursive
install-exec: install-exec-recursive
install-data: install-data-recursive
uninstall: uninstall-recursive

install-am: all-am
	@$(MAKE) $(AM_MAKEFLAGS) install-exec-am install-data-am

installcheck: installcheck-recursive
install-strip:
	if test -z '$(STRIP)'; then \
	  $(MAKE) $(AM_MAKEFLAGS) INSTALL_PROGRAM="$(INSTALL_STRIP_PROGRAM)" \
	    install_sh_PROGRAM="$(INSTALL_STRIP_PROGRAM)" INSTALL_STRIP_FLAG=-s \
	      install; \
	else \
	  $(MAKE) $(AM_MAKEFLAGS) INSTALL_PROGRAM="$(INSTALL_STRIP_PROGRAM)" \
	    install_sh_PROGRAM="$(INSTALL_STRIP_PROGRAM)" INSTALL_STRIP_FLAG=-s \
	    "INSTALL_PROGRAM_ENV=STRIPPROG='$(STRIP)'" install; \
	fi
mostlyclean-generic:

clean-generic:
	-test -z "$(CLEANFILES)" || rm -f $(CLEANFILES)

distclean-generic:
	-test -z "$(CONFIG_CLEAN_FILES)" || rm -f $(CONFIG_CLEAN_FILES)
	-test . = "$(srcdir)" || test -z "$(CONFIG_CLEAN_VPATH_FILES)" || rm -f $(CONFIG_CLEAN_VPATH_FILES)
	-test -z "$(DISTCLEANFILES)" || rm -f $(DISTCLEANFILES)

maintainer-clean-generic:
	@echo "This command is intended for maintainers to use"
	@echo "it deletes files that may require special tools to rebuild."
	-rm -f ifm-parse.c
	-rm -f ifm-parse.h
	-rm -f ifm-scan.c
clean: clean-recursive

clean-am: clean-binPROGRAMS clean-generic mostlyclean-am

distclean: distclean-recursive
		-rm -f ./$(DEPDIR)/ifm-dot.Po
	-rm -f ./$(DEPDIR)/ifm-fig.Po
	-rm -f ./$(DEPDIR)/ifm-format.Po
	-rm -f ./$(DEPDIR)/ifm-main.Po
	-rm -f ./$(DEPDIR)/ifm-map.Po
	-rm -f ./$(DEPDIR)/ifm-parse.Po
	-rm -f ./$(DEPDIR)/ifm-path.Po
	-rm -f ./$(DEPDIR)/ifm-ps.Po
	-rm -f ./$(DEPDIR)/ifm-raw.Po
	-rm -f ./$(DEPDIR)/ifm-rec.Po
	-rm -f ./$(DEPDIR)/ifm-scan.Po
	-rm -f ./$(DEPDIR)/ifm-task.Po
	-rm -f ./$(DEPDIR)/ifm-text.Po
	-rm -f ./$(DEPDIR)/ifm-tk.Po
	-rm -f ./$(DEPDIR)/ifm-util.Po
	-rm -f ./$(DEPDIR)/ifm-vars.Po
	-rm -f ./$(DEPDIR)/ifm-yaml.Po
	-rm -f Makefile
distclean-am: clean-am distclean-compile distclean-generic \
	distclean-tags

dvi: dvi-recursive

dvi-am:

html: html-recursive

html-am:

info: info-recursive

info-am:

install-data-am:

install-dvi: install-dvi-recursive

install-dvi-am:

install-exec-am: install-binPROGRAMS

install-html: install-html-recursive

install-html-am:

install-info: install-info-recursive

install-info-am:

install-man:

install-pdf: install-pdf-recursive

install-pdf-am:

install-ps: install-ps-recursive

install-ps-am:

installcheck-am:

maintainer-clean: maintainer-clean-recursive
		-rm -f ./$(DEPDIR)/ifm-dot.Po
	-rm -f ./$(DEPDIR)/ifm-fig.Po
	-rm -f ./$(DEPDIR)/ifm-format.Po
	-rm -f ./$(DEPDIR)/ifm-main.Po
	-rm -f ./$(DEPDIR)/ifm-map.Po
	-rm -f ./$(DEPDIR)/ifm-parse.Po
	-rm -f ./$(DEPDIR)/ifm-path.Po
	-rm -f ./$(DEPDIR)/ifm-ps.Po
	-rm -f ./$(DEPDIR)/ifm-raw.Po
	-rm -f ./$(DEPDIR)/ifm-rec.Po
	-rm -f ./$(DEPDIR)/ifm-scan.Po
	-rm -f ./$(DEPDIR)/ifm-task.Po
	-rm -f ./$(DEPDIR)/ifm-text.Po
	-rm -f ./$(DEPDIR)/ifm-tk.Po
	-rm -f ./$(DEPDIR)/ifm-util.Po
	-rm -f ./$(DEPDIR)/ifm-vars.Po
	-rm -f ./$(DEPDIR)/ifm-yaml.Po
	-rm -f Makefile
maintainer-clean-am: distclean-am maintainer-clean-generic

mostlyclean: mostlyclean-recursive

mostlyclean-am: mostlyclean-compile mostlyclean-generic

pdf: pdf-recursive

pdf-am:

ps: ps-recursive

ps-am:

uninstall-am: uninstall-binPROGRAMS

.MAKE: $(am__recursive_targets) install-am install-strip

.PHONY: $(am__recursive_targets) CTAGS GTAGS TAGS all all-am \
	am--depfiles check check-am clean clean-binPROGRAMS \
	clean-generic cscopelist-am ctags ctags-am distclean \
	distclean-compile distclean-generic distclean-tags distdir dvi \
	dvi-am html html-am info info-am install install-am \
	install-binPROGRAMS install-data install-data-am install-dvi \
	install-dvi-am install-exec install-exec-am install-html \
	install-html-am install-info install-info-am install-man \
	install-pdf install-pdf-am install-ps install-ps-am \
	install-strip installcheck installcheck-am installdirs \
	installdirs-am maintainer-clean maintainer-clean-generic \
	mostlyclean mostlyclean-compile mostlyclean-generic pdf pdf-am \
	ps ps-am tags tags-am uninstall uninstall-am \
	uninstall-binPROGRAMS

.PRECIOUS: Makefile


.NOTPARALLEL:

$(bin_PROGRAMS): $(VARS_BIN)/libvars.a $(FIG_BIN)/libfig.a

ifm-parse.h: ifm-parse.c

$(VCFILE): stamp-vc

stamp-vc: dummy
	@ test -f $@ || touch $@
	@ echo $(VCVERSION) | cmp -s $@ - || echo $(VCVERSION) > $@

dummy: ;

%.lint: %.c
	@ $(LINTCMD) $<

lint:; $(LINTCMD) $(LINTDEFS) $(SRCS)

# Add emacs flymake support.

check-syntax:
	$(CC) $(AM_CPPFLAGS) -o /dev/null -S $(CHK_SOURCES)

# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
