/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _OBLIVIONSUBSHAPE_H_
#define _OBLIVIONSUBSHAPE_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * Havok Information for packed TriStrip shapes.
 */
struct NIFLIB_API OblivionSubShape {
	/*! Default Constructor */
	OblivionSubShape();
	/*! Default Destructor */
	~OblivionSubShape();
	/*!
	 * Sets mesh color in Oblivion Construction Set.
	 */
	OblivionLayer layer;
	/*!
	 * The first bit sets the LINK property and controls whether this body is
	 * physically linked to others. The next bit turns collision off. Then,
	 * the next bit sets the SCALED property in Oblivion. The next five bits
	 * make up the number of this part in a linked body list.
	 */
	byte colFilter;
	/*!
	 * Unknown.
	 */
	ushort unknownShort;
	/*!
	 * Seems to be the number of vertices that form this sub shape.
	 */
	uint vertexCount___;
	/*!
	 * The material of the subshape.
	 */
	HavokMaterial material;
};

}
#endif
