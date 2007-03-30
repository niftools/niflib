/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _DLL_EXPORT_H_
#define _DLL_EXPORT_H_

// detect visibility support for linux compilers
#if (__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#  ifndef GCC_HASCLASSVISIBILITY
#    define GCC_HASCLASSVISIBILITY
#  endif
#endif

// shared library: expose NIFLIB_API objects, hide NIFLIB_HIDDEN objects
#ifdef USE_NIFLIB_DLL
	// building swig wrapper
	#if defined(SWIG)
		#define NIFLIB_API
		#define NIFLIB_HIDDEN
	// building shared library (windows)
	#elif defined(_WIN32) || defined(__WIN32__) || defined(_MSC_VER) || defined(__CYGWIN__)
		#ifdef BUILDING_NIFLIB_DLL
			#define NIFLIB_API __declspec(dllexport)
		#else
			#define NIFLIB_API __declspec(dllimport)
		#endif
		#define NIFLIB_HIDDEN
	// building shared library (linux)
	#elif defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
		#define NIFLIB_API __attribute__ ((visibility("default")))
		#define NIFLIB_HIDDEN __attribute__ ((visibility("hidden")))
	#else
		#error __attribute__ ((visibility("hidden"))) support required, but not detected (see gcc.gnu.org/wiki/Visibility)
	#endif
// static library: nothing to hide
#else
	#define NIFLIB_API
	#define NIFLIB_HIDDEN
#endif

#endif
