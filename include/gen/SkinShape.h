/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _SKINSHAPE_H_
#define _SKINSHAPE_H_

#include "../NIF_IO.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class NiTriShape;
class NiSkinInstance;

/*!
 * Reference to shape and skin instance.
 */
struct NIFLIB_API SkinShape {
	/*! Default Constructor */
	SkinShape();
	/*! Default Destructor */
	~SkinShape();
	/*!
	 * The shape.
	 */
	Ref<NiTriShape > shape;
	/*!
	 * Skinning instance for the shape?
	 */
	Ref<NiSkinInstance > skinInstance;
};

}
#endif
