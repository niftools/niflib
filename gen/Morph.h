/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _MORPH_H_
#define _MORPH_H_

#include "../NIF_IO.h"


/*!
 * Geometry morphing data component.
 */
struct Morph {
	/*! Default Constructor */
	Morph();
	/*! Default Destructor */
	~Morph();
	/*!
	 * Name of the frame.
	 */
	string frameName;
	/*!
	 * The number of morph keys that follow.
	 */
	uint numMorphKeys;
	/*!
	 * Unlike most blocks, the presense of this value is not conditional on
	 * there being keys.
	 */
	KeyType morphInterpolation;
	/*!
	 * The morph key frames.
	 */
	vector<Key<float > > morphKeys;
	/*!
	 * Unknown.
	 */
	uint unknownInt;
	/*!
	 * Morph vectors.
	 */
	vector<Vector3 > vectors;
};

#endif
