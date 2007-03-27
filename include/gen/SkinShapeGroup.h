/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _SKINSHAPEGROUP_H_
#define _SKINSHAPEGROUP_H_

#include "../NIF_IO.h"

// Include structures
#include "SkinShape.h"
namespace Niflib {


/*!
 * Unknown.
 */
struct SkinShapeGroup {
	/*! Default Constructor */
	NIFLIB_API SkinShapeGroup();
	/*! Copy Constructor */
	NIFLIB_API SkinShapeGroup( const SkinShapeGroup & src );
	/*! Copy Operator */
	NIFLIB_API SkinShapeGroup & operator=( const SkinShapeGroup & src );
	/*! Default Destructor */
	NIFLIB_API ~SkinShapeGroup();
	/*!
	 * Counts unknown.
	 */
	mutable unsigned int numLinkPairs;
	/*!
	 * First link is a NiTriShape object.             Second link is a
	 * NiSkinInstance object.
	 */
	vector<SkinShape > linkPairs;
};

}
#endif
