/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _LIMITEDHINGEDESCRIPTOR_H_
#define _LIMITEDHINGEDESCRIPTOR_H_

#include "../NIF_IO.h"


/*!
 * 
 */
struct LimitedHingeDescriptor {
	/*! Default Constructor */
	LimitedHingeDescriptor();
	/*! Default Destructor */
	~LimitedHingeDescriptor();
	/*!
	 * Unknown.
	 */
	Float4 pivotA;
	/*!
	 * Unknown.
	 */
	Float4 axleA_;
	/*!
	 * Unknown.
	 */
	Float4 perp2axleina1;
	/*!
	 * Unknown.
	 */
	Float4 perp2axleina2;
	/*!
	 * Unknown.
	 */
	Float4 pivotB;
	/*!
	 * Unknown.
	 */
	Float4 axleB;
	/*!
	 * Unknown.
	 */
	Float4 unknownVector;
	/*!
	 * Unknown.
	 */
	float minAngle;
	/*!
	 * Unknown.
	 */
	float maxAngle;
	/*!
	 * Unknown.
	 */
	float maxFriction;
};

#endif
