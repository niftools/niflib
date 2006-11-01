/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _HKTRIANGLE_H_
#define _HKTRIANGLE_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * A triangle with extra data used for physics.
 */
struct NIFLIB_API hkTriangle {
	/*! Default Constructor */
	hkTriangle();
	/*! Default Destructor */
	~hkTriangle();
	/*!
	 * The triangle.
	 */
	Triangle triangle;
	/*!
	 * Another short, doesn't look like a vertex index.
	 */
	ushort unknownShort;
	/*!
	 * This is the triangle's normal.
	 */
	Vector3 normal;
};

}
#endif
