## Makefile.am ##

## Process this file with automake to create Makefile.in ##

ACLOCAL_AMFLAGS = -I .

## header files

include_HEADERS = \
niflib.h \
nif_math.h \
nif_attrs.h \
NIF_Blocks.h \
NIF_IO.h

AM_CPPFLAGS = -I$(srcdir) -ggdb

## generated libraries and sources

# (uncomment the libniflib stuff to build a C++ library)

#lib_LTLIBRARIES = libniflib.la

#libniflib_la_SOURCES = \
#niflib.cpp \
#nif_math.cpp \
#NIF_Blocks.cpp \
#NIF_IO.cpp \
#docsys_extract.cpp

#libniflib_la_LDFLAGS = -version-info 0:0:0 -shared -no-undefined

BUILT_SOURCES = swig_wrap.cpp
SWIG_SOURCES = pyniflib.i niflib.h
pkgpython_PYTHON = niflib.py
pkgpyexec_LTLIBRARIES = _niflib.la
_niflib_la_SOURCES = \
niflib.cpp \
nif_math.cpp \
NIF_Blocks.cpp \
NIF_IO.cpp \
docsys_extract.cpp \
swig_wrap.cpp \
$(SWIG_SOURCES)
_niflib_la_CPPFLAGS = $(SWIG_PYTHON_CPPFLAGS)
_niflib_la_LDFLAGS = -module -shared #-no-undefined

swig_wrap.cpp: $(SWIG_SOURCES)
	$(SWIG) $(SWIG_PYTHON_OPT) -o $@ $<

CLEANFILES = swig_wrap.cpp
