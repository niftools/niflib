/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _SKINWEIGHT_H_
#define _SKINWEIGHT_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * A weighted vertex.
 */
struct SkinWeight {
	/*! Default Constructor */
	NIFLIB_API SkinWeight();
	/*! Default Destructor */
	NIFLIB_API ~SkinWeight();
	/*! Copy Constructor */
	NIFLIB_API SkinWeight( const SkinWeight & src );
	//This operator give SWIG problems
	#ifndef SWIG
	/*! Copy Operator */
	NIFLIB_API SkinWeight & operator=( const SkinWeight & src );
	#endif
	/*!
	 * The vertex index, in the mesh.
	 */
	unsigned short index;
	/*!
	 * The vertex weight - between 0.0 and 1.0
	 */
	float weight;
};

}
#endif
