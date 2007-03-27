/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _AVOBJECT_H_
#define _AVOBJECT_H_

#include "../NIF_IO.h"

namespace Niflib {

// Forward define of referenced blocks
class NiAVObject;

/*!
 * Used in NiDefaultAVObjectPalette.
 */
struct AVObject {
	/*! Default Constructor */
	NIFLIB_API AVObject();
	/*! Copy Constructor */
	NIFLIB_API AVObject( const AVObject & src );
	/*! Copy Operator */
	NIFLIB_API AVObject & operator=( const AVObject & src );
	/*! Default Destructor */
	NIFLIB_API ~AVObject();
	/*!
	 * Object name.
	 */
	string name;
	/*!
	 * Object reference.
	 */
	NiAVObject * avObject;
};

}
#endif
