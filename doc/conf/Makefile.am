## Automake template for pinning requirements.

REQ = $(wildcard requirements*.in)
TXT = $(subst .in,.txt,$(REQ))

IDXOPTS = $(addprefix --extra-index-url ,$(INDEXES))
PIPOPTS = --pip-args '$(PIPARGS)'
COMPILE = $(PYTHON) -m piptools compile -v $(IDXOPTS) $(PIPOPTS) $(OPTS)

EXTRA_DIST = $(REQ) $(TXT) constraints.txt

requirements: $(TXT) ## Build requirements files

upgrade-pkg: ## Upgrade a single package (PKG)
	@ echo Upgrading $(PKG)
	@ touch $(REQ)
	@ $(MAKE) $(TXT) OPTS="$(addprefix -P ,$(PKG))"

upgrade-all: ## Upgrade all packages
	@ echo Upgrading all packages
	@ touch $(REQ)
	@ $(MAKE) $(TXT) OPTS=-U

depend: ## Update requirement dependencies
	@ $(PYTHON) requirements.py $(REQ) > requirements.mk

%.txt: %.in constraints.txt
	@ echo Making $@
	@ $(COMPILE) $< -o $@

include $(top_srcdir)/etc/Makefile.common
