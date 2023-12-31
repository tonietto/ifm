## Automake template for IFM documentation.

builddir	= $(top_builddir)/doc
htmldir		= $(builddir)/html
latexdir	= $(builddir)/latex
sphinxdir	= $(builddir)/sphinx
venvdir 	= $(builddir)/venv

imagedir	= $(srcdir)/images
exampledir	= $(srcdir)/examples
tooldir		= $(srcdir)/tools
staticdir	= $(srcdir)/static
templatedir	= $(srcdir)/templates
filedir		= $(srcdir)/files

repodir		= $(top_srcdir)/../ifmdocs

# Documentation sources.

DOCFILES = changes.rst contents.rst editors.rst example.rst ifm2dev.rst	 \
ifm2tex.rst ifm2web.rst intro.rst language.rst license.rst links.rst	 \
maps.rst refs.rst scr2ifm.rst solving.rst thanks.rst tkifm.rst tools.rst \
usage.rst vars.rst

INCFILES = NEWS THANKS COPYING COPYING.DOC

REPODOCS = conf.py $(DOCFILES) $(imagedir) $(exampledir) $(tooldir)	\
$(filedir) $(staticdir) $(templatedir)

SUBDIRS = conf examples

# Programs.

SPHINX = $(venvdir)/bin/sphinx-build -N -d $(sphinxdir) $(SPHINXOPTS)
PIP    = $(venvdir)/bin/pip

# User guide.

.PHONY: html latex images examples venv

guide: html

force:; @ rm -rf $(htmldir) $(sphinxdir); $(MAKE) guide

html: setup conf.py
	$(SPHINX) -b $@ $(srcdir) $(htmldir)

latex: setup conf.py
	$(SPHINX) -b $@ $(srcdir) $(latexdir)

linkcheck: setup conf.py
	$(SPHINX) -b $@ $(srcdir) $(sphinxdir)

ifmdocs: $(repodir) setup
	cp -auv $(REPODOCS) $(repodir)

setup: venv
	@ mkdir -p $(htmldir) $(latexdir) $(sphinxdir) $(imagedir)
	@ $(MAKE) -s images examples
	@ for file in conf.py images/logo.png; do			\
	    path=$(builddir)/$$file;					\
	    test -f $$path || ln -s $(srcdir)/$$file $$path;		\
	done
	@ mkdir -p $(filedir)
	@ for file in $(INCFILES); do					\
	    cp $(top_srcdir)/$$file $(filedir);				\
	done

venv:;	@ test -d $(venvdir) || $(MAKE) init

init:;	$(PYTHON) -m venv $(venvdir)
	$(PIP) install -U pip
	$(PIP) install -r conf/requirements-dev.txt
	$(PIP) install -r conf/requirements.txt

# Generated images.

EXAMPLES = $(wildcard ${exampledir}/*.ifm)
TMP = $(subst ${exampledir},${imagedir},${EXAMPLES})
PNG = $(subst .ifm,.png,${TMP}) $(imagedir)/ruins-graph.png	\
$(imagedir)/ruins-graph-byroom.png

IFM     = $(top_builddir)/src/ifm -I $(top_srcdir)/lib
IFM2WEB = env IFM="$(IFM)" perl $(top_srcdir)/progs/ifm2web.pl -S helvetica

LARGE = $(IFM2WEB) -z 3 -s 40
SMALL = $(IFM2WEB) -z 3 -s 14
TASKS = $(IFM2WEB) -g -s 70

images: $(PNG)

examples:
	cd $(top_builddir)/src; $(MAKE)
	cd $(builddir)/examples; $(MAKE)

$(imagedir)/%.png: $(exampledir)/%.ifm
	@ echo creating $@
	@ mkdir -p $(imagedir)
	$(LARGE) -o $@ $<

$(imagedir)/%-graph.png: $(exampledir)/%.ifm
	@ echo creating $@
	@ mkdir -p $(imagedir)
	@ $(TASKS) -o $@ $<

$(imagedir)/%-graph-byroom.png: $(exampledir)/%.ifm
	@ echo creating $@
	@ mkdir -p $(imagedir)
	@ $(TASKS) -r -o $@ $<

$(imagedir)/logo.png: $(exampledir)/logo.ifm
	@ echo creating $@
	@ mkdir -p $(imagedir)
	$(SMALL) -o $@ $<

# Installation stuff.

install-doc: install-html

install-html: $(ifmdocdir)
	@ if test -d $(htmldir); then					\
	   set -x;							\
	   rm -rf $(ifmdocdir);						\
	   mkdir -p $(ifmdocdir);					\
	   cp -rf $(htmldir)/* $(ifmdocdir);				\
	fi

$(ifmdocdir):
	- chmod u+w $(prefix)
	$(mkinstalldirs) $(docdir)
	- chmod u+w $(docdir)
	$(mkinstalldirs) $(ifmdocdir)

# Distribution stuff.

EXTRA_DIST = $(DOCFILES) examples templates static

dist-doc:
	if test -d $(htmldir); then					\
	   cp -rf $(htmldir) $(distdir);				\
	fi

check-doc:
	@ for path in $(srcdir)/*.rst; do				\
	    file=`basename $$path`;    					\
	    if ! test -f $(distdir)/$$file; then			\
		echo Error: $$file is missing from the distribution;	\
		exit 1;	 		   				\
	    fi;	      	 		   				\
	done

# Other stuff.

install-data-hook: install-doc

uninstall-hook:
	- chmod -R u+w $(ifmdocdir)
	rm -rf $(ifmdocdir)

dist-hook: dist-doc check-doc

include $(top_srcdir)/etc/Makefile.common
