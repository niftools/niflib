dnl configure.ac
dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT([The NIF Library],[1.3],[http://niftools.sourceforge.net/],[niflib])
AC_CONFIG_SRCDIR([niflib.cpp])
AC_CONFIG_HEADER([config.h])
AM_INIT_AUTOMAKE

dnl Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_LIBTOOL
AM_PATH_PYTHON(2.3)
AC_PROG_SWIG(1.3.21)
SWIG_ENABLE_CXX
SWIG_PYTHON

dnl Checks for libraries.

dnl Checks for header files.
AC_HEADER_STDBOOL

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

dnl Checks for library functions.

dnl Checks for system services.

AC_CONFIG_FILES([Makefile])

AC_OUTPUT

dnl eof
