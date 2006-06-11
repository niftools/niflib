/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _SKINSHAPEGROUP_H_
#define _SKINSHAPEGROUP_H_

#include "../NIF_IO.h"

// Include structures
#include "SkinShape.h"

/*!
 * Unknown.
 */
struct NIFLIB_API SkinShapeGroup {
	/*! Default Constructor */
	SkinShapeGroup();
	/*! Default Destructor */
	~SkinShapeGroup();
	/*!
	 * Counts unknown.
	 */
	uint numLinkPairs;
	/*!
	 * First link is a NiTriShape block. Second link is a NiSkinInstance
	 * block.
	 */
	vector<SkinShape > linkPairs;
};

#endif
