/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _DLL_EXPORT_H_
#define _DLL_EXPORT_H_

#ifdef USE_NIFLIB_DLL
	#ifdef _MSC_VER
		#ifdef BUILDING_NIFLIB_DLL
			#define NIFLIB_API __declspec(dllexport)
		#else
			#define NIFLIB_API __declspec(dllimport)
		#endif
		#define NIFLIB_HIDDEN
	#else
		#ifdef HAVE_GCCVISIBILITYPATCH
			#define NIFLIB_API __attribute__ ((visibility("default")))
			#define NIFLIB_HIDDEN __attribute__ ((visibility("hidden")))
		#else
			#define NIFLIB_API
			#define NIFLIB_HIDDEN
		#endif
	#endif 
#else
	#define NIFLIB_API
	#define NIFLIB_HIDDEN
#endif

#endif
