/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _SKINWEIGHT_H_
#define _SKINWEIGHT_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * A weighted vertex.
 */
struct NIFLIB_API SkinWeight {
	/*! Default Constructor */
	SkinWeight();
	/*! Copy Constructor */
	SkinWeight( const SkinWeight & src );
	/*! Copy Operator */
	SkinWeight & operator=( const SkinWeight & src );
	/*! Default Destructor */
	~SkinWeight();
	/*!
	 * The vertex index, in the mesh.
	 */
	ushort index;
	/*!
	 * The vertex weight - between 0.0 and 1.0
	 */
	float weight;
};

}
#endif
