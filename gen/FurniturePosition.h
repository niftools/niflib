/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _FURNITUREPOSITION_H_
#define _FURNITUREPOSITION_H_

#include "../NIF_IO.h"


/*!
 * Describes a furniture position?
 */
struct DLLEXPORT FurniturePosition {
	/*! Default Constructor */
	FurniturePosition();
	/*! Default Destructor */
	~FurniturePosition();
	/*!
	 * Offset of furniture marker.
	 */
	Vector3 offset;
	/*!
	 * Furniture marker orientation.
	 */
	ushort orientation;
	/*!
	 * Refers to a furnituremarkerxx.nif file. Always seems to be the same as
	 * Position Ref 2.
	 */
	byte positionRef1;
	/*!
	 * Refers to a furnituremarkerxx.nif file. Always seems to be the same as
	 * Position Ref 1.
	 */
	byte positionRef2;
};

#endif
