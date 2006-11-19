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
struct NIFLIB_API AVObject {
	/*! Default Constructor */
	AVObject();
	/*! Copy Constructor */
	AVObject( const AVObject & src );
	/*! Copy Operator */
	AVObject & operator=( const AVObject & src );
	/*! Default Destructor */
	~AVObject();
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
