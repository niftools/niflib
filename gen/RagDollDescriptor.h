/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _RAGDOLLDESCRIPTOR_H_
#define _RAGDOLLDESCRIPTOR_H_

#include "NIF_IO.h"


/*!
 * 
 */
struct RagDollDescriptor {
	/*! Default Constructor */
	RagDollDescriptor();
	/*! Default Destructor */
	~RagDollDescriptor();
	/*!
	 * Unknown.
	 */
	Float4 pivotA;
	/*!
	 * Unknown.
	 */
	Float4 planeA;
	/*!
	 * Unknown.
	 */
	Float4 twistA;
	/*!
	 * Unknown.
	 */
	Float4 pivotB;
	/*!
	 * Unknown.
	 */
	Float4 planeB;
	/*!
	 * Unknown.
	 */
	Float4 twistB;
	/*!
	 * Unknown.
	 */
	float coneMinAngle;
	/*!
	 * Unknown.
	 */
	float planeMinAngle;
	/*!
	 * Unknown.
	 */
	float planeMaxAngle;
	/*!
	 * Unknown.
	 */
	float twistMinAngle;
	/*!
	 * Unknown.
	 */
	float twistMaxAngle;
	/*!
	 * Unknown.
	 */
	float maxFriction;
};

#endif
