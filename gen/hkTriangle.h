/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _HKTRIANGLE_H_
#define _HKTRIANGLE_H_

#include "../NIF_IO.h"

namespace NifLib {


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
	 * This appears to be a normalized vector, so probably it is a normal or
	 * a tangent vector or something like that.
	 */
	Vector3 normal;
};

}
#endif
