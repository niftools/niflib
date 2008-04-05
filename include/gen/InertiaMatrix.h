/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#ifndef _INERTIAMATRIX_H_
#define _INERTIAMATRIX_H_

#include "../NIF_IO.h"

namespace Niflib {


/*! An inertia matrix. */
struct InertiaMatrix {
	/*! Default Constructor */
	NIFLIB_API InertiaMatrix();
	/*! Default Destructor */
	NIFLIB_API ~InertiaMatrix();
	/*! Copy Constructor */
	NIFLIB_API InertiaMatrix( const InertiaMatrix & src );
	/*! Copy Operator */
	NIFLIB_API InertiaMatrix & operator=( const InertiaMatrix & src );
	/*! Unknown. */
	float m11;
	/*! Unknown. */
	float m12;
	/*! Unknown. */
	float m13;
	/*! Zero */
	float m14;
	/*! Unknown. */
	float m21;
	/*! Unknown. */
	float m22;
	/*! Unknown. */
	float m23;
	/*! Zero */
	float m24;
	/*! Unknown. */
	float m31;
	/*! Unknown. */
	float m32;
	/*! Unknown. */
	float m33;
	/*! Zero */
	float m34;
};

}
#endif
