# -*- coding: utf-8 -*-
#
# Sphinx documentation build configuration file, created by
# sphinx-quickstart on Fri Jul 25 11:19:04 2008.
#
# This file is execfile()d with the current directory set to its containing
# dir.
#
# The contents of this file are pickled, so don't put values in the
# namespace that aren't pickleable (module imports are okay, they're
# removed automatically).
#
# All configuration values have a default value; values that are commented
# out serve to show the default value.

import sys, os, time
sys.path.insert(0, os.path.abspath('tools'))

from ifm import IFMLexer
from transcript import TranscriptLexer

# General configuration
# ---------------------

# Setup function.
def setup(app):
    app.add_lexer('ifm', IFMLexer())
    app.add_lexer('transcript', TranscriptLexer())

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom ones.
#extensions = ['']

# Add any paths that contain templates here, relative to this directory.
templates_path = ['templates']

# The suffix of source filenames.
source_suffix = '.rst'

# The master toctree document.
#master_doc = 'index'

# General substitutions.
project = 'IFM'
author = "Glenn Hutchings"
copyright = '1998-%s, %s' % (time.strftime('%Y'), author)

# The default replacements for |version| and |release|, also used in
# various other places throughout the built documents.
#
# The short X.Y version.
version = "5.5"
# The full version, including alpha/beta/rc tags.
release = version

# There are two options for replacing |today|: either, you set today to
# some non-false value, then it is used:
#today = ''
# Else, today_fmt is used as the format for a strftime call.
today_fmt = '%B %d, %Y'

# List of documents that shouldn't be included in the build.
exclude_patterns = ["refs.rst", "conf/*", "venv/*"]

# The reST default role (used for this markup: `text`) to use for all
# documents.
#default_role = None

# The name of the Pygments (syntax highlighting) style to use.
pygments_style = 'sphinx'


# Options for HTML output
# -----------------------

# The style sheet to use for HTML and HTML Help pages. A file of that name
# must exist either in Sphinx' static/ path, or in one of the custom paths
# given in html_static_path.
#html_style = 'ifm.css'

# The name for this set of Sphinx documents.  If None, it defaults to
# "<project> v<release> documentation".
#html_title = None

# A shorter title for the navigation bar.  Default is the same as
# html_title.
#html_short_title = None

# The name of an image file (within the static path) to place at the top of
# the sidebar.
html_logo = "images/logo.png"

# The name of an image file (within the static path) to use as favicon of
# the docs.  This file should be a Windows icon file (.ico) being 16x16 or
# 32x32 pixels large.
html_favicon = "static/logo.ico"

# Add any paths that contain custom static files (such as style sheets)
# here, relative to this directory. They are copied after the builtin
# static files, so a file named "default.css" will overwrite the builtin
# "default.css".
#html_static_path = ['static']

# If not '', a 'Last updated on:' timestamp is inserted at every page bottom,
# using the given strftime format.
html_last_updated_fmt = '%b %d, %Y'

# If true, SmartyPants will be used to convert quotes and dashes to
# typographically correct entities.
#html_use_smartypants = True

# Custom sidebar templates, maps document names to template names.
html_sidebars = {
    'index': 'indexsidebar.html',
}

# Additional templates that should be rendered to pages, maps page names to
# template names.
html_additional_pages = {
    'index': 'indexcontent.html',
}

# If false, no module index is generated.
html_use_modindex = False

# If false, no index is generated.
html_use_index = True

# If true, the index is split into individual pages for each letter.
html_split_index = False

# If true, the reST sources are included in the HTML build as
# _sources/<name>.
html_copy_source = True

# If true, an OpenSearch description file will be output, and all pages
# will contain a <link> tag referring to it.  The value of this option must
# be the base URL from which the finished HTML is served.
#html_use_opensearch = ''

# Output file base name for HTML help builder.
htmlhelp_basename = 'IFM'


# Options for LaTeX output
# ------------------------

# LaTeX parameters.
latex_elements = dict(papersize = "a4",
                      pointsize = "11pt",
		      fncychap = r"\usepackage[Conny]{fncychap}",
                      footer = "")

# Grouping the document tree into LaTeX files. List of tuples (source start
# file, target name, title, author, document class [howto/manual]).
latex_documents = [
  ('contents', 'ifm.tex', 'IFM User Manual', author, 'manual'),
]

# The name of an image file (relative to this directory) to place at the
# top of the title page.
#latex_logo = None

# For "manual" documents, if this is true, then toplevel headings are parts,
# not chapters.
#latex_use_parts = False

# Additional stuff for the LaTeX preamble.
#latex_preamble = ''

# Documents to append as an appendix to all manuals.
#latex_appendices = []
