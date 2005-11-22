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

lib_LTLIBRARIES = libniflib.la

libniflib_la_SOURCES = \
niflib.cpp \
nif_math.cpp \
NIF_Blocks.cpp \
NIF_IO.cpp

libniflib_la_LDFLAGS = -version-info 0:0:0

BUILT_SOURCES = swig_wrap.cpp
SWIG_SOURCES = pyniflib.i
pkgpython_PYTHON = niflib.py
pkgpyexec_LTLIBRARIES = _niflib.la
_niflib_la_SOURCES = swig_wrap.cpp $(SWIG_SOURCES)
_niflib_la_CPPFLAGS = $(SWIG_PYTHON_CPPFLAGS)
_niflib_la_LDFLAGS = -module
_niflib_la_LIBADD = libniflib.la

swig_wrap.cpp: $(SWIG_SOURCES)
	$(SWIG) $(SWIG_PYTHON_OPT) -o $@ $<
