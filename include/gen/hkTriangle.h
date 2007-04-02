/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/nifxml_niflib.py Python script.

#ifndef _HKTRIANGLE_H_
#define _HKTRIANGLE_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * A triangle with extra data used for physics.
 */
struct hkTriangle {
	/*! Default Constructor */
	NIFLIB_API hkTriangle();
	/*! Default Destructor */
	NIFLIB_API ~hkTriangle();
	/*! Copy Constructor */
	NIFLIB_API hkTriangle( const hkTriangle & src );
	//This operator give SWIG problems
	#ifndef SWIG
	/*! Copy Operator */
	NIFLIB_API hkTriangle & operator=( const hkTriangle & src );
	#endif
	/*!
	 * The triangle.
	 */
	Triangle triangle;
	/*!
	 * Another short, doesn't look like a vertex index.
	 */
	unsigned short unknownShort;
	/*!
	 * This is the triangle's normal.
	 */
	Vector3 normal;
};

}
#endif
