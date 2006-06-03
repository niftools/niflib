/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _ROTATIONKEYARRAY_H_
#define _ROTATIONKEYARRAY_H_

#include "NIF_IO.h"


/*!
 * Rotation key array.
 */
template <class T >
struct RotationKeyArray {
	/*!
	 * Number of keys.
	 */
	uint numKeys;
	/*!
	 * Key type (1, 2, 3, or 4).
	 */
	KeyType keyType;
	/*!
	 * The rotation keys.
	 */
	vector<Key<T > > keys;
};

#endif
