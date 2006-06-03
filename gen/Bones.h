/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BONES_H_
#define _BONES_H_

#include "NIF_IO.h"
class NiNode;

/*!
 * This is a list of bone influences.  It points to blocks higher in the
 * hierarchy so ints are used to represent the indices.
 */
struct Bones {
	/*! Default Constructor */
	Bones();
	/*! Default Destructor */
	~Bones();
	/*!
	 * The number of node bones referenced as influences.
	 */
	uint numBones;
	/*!
	 * Block indicies of the bones.
	 */
	vector<NiNode * > bones;
};

#endif
