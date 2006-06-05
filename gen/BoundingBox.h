/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BOUNDINGBOX_H_
#define _BOUNDINGBOX_H_

#include "../NIF_IO.h"


/*!
 * Bounding box.
 */
struct BoundingBox {
	/*! Default Constructor */
	BoundingBox();
	/*! Default Destructor */
	~BoundingBox();
	/*!
	 * Usually 1.
	 */
	uint unknownInt;
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

#endif
