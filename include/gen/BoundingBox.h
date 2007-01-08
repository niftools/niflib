/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BOUNDINGBOX_H_
#define _BOUNDINGBOX_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * Bounding box.
 */
struct NIFLIB_API BoundingBox {
	/*! Default Constructor */
	BoundingBox();
	/*! Copy Constructor */
	BoundingBox( const BoundingBox & src );
	/*! Copy Operator */
	BoundingBox & operator=( const BoundingBox & src );
	/*! Default Destructor */
	~BoundingBox();
	/*!
	 * Usually 1.
	 */
	unsigned int unknownInt;
	/*!
	 * Translation vector.
	 */
	Vector3 translation;
	/*!
	 * Rotation matrix.
	 */
	Matrix33 rotation;
	/*!
	 * Radius, per direction.
	 */
	Vector3 radius;
};

}
#endif
