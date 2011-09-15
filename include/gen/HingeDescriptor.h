/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#ifndef _HINGEDESCRIPTOR_H_
#define _HINGEDESCRIPTOR_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!  */
struct HingeDescriptor {
	/*! Default Constructor */
	NIFLIB_API HingeDescriptor();
	/*! Default Destructor */
	NIFLIB_API ~HingeDescriptor();
	/*! Copy Constructor */
	NIFLIB_API HingeDescriptor( const HingeDescriptor & src );
	/*! Copy Operator */
	NIFLIB_API HingeDescriptor & operator=( const HingeDescriptor & src );
	/*! Pivot point around which the object will rotate. */
	Vector4 pivotA;
	/*! Vector in the rotation plane which defines the zero angle. */
	Vector4 perp2AxleInA1;
	/*!
	 * Vector in the rotation plane, orthogonal on the previous one, which defines the
	 * positive direction of rotation.
	 */
	Vector4 perp2AxleInA2;
	/*! Pivot A in second entity coordinate system. */
	Vector4 pivotB;
	/*! Axle A (vector orthogonal on Perp2 Axles) in second entity coordinate system. */
	Vector4 axleB;
	/*! Unknown */
	float unknownFloat1;
	/*! Unknown */
	float unknownInt2;
	/*! Unknown */
	float unknownInt3;
	/*! Unknown */
	float unknownInt4;
	/*! Unknown */
	float unknownInt5;
	/*! Unknown */
	float unknownInt6;
	/*! Unknown */
	float unknownInt7;
	/*! Unknown */
	float unknownInt8;
	/*! Unknown */
	float unknownInt9;
	/*! Unknown */
	float unknownInt10;
	/*! Unknown */
	byte unknownByte1;
	/*! Unknown */
	byte unknownByte2;
	/*! Unknown */
	byte unknownByte3;
	//--BEGIN MISC CUSTOM CODE--//
	//--END CUSTOM CODE--//
};

}
#endif
