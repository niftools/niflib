/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _STRINGPALETTE_H_
#define _STRINGPALETTE_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * A list of \\0 terminated strings.
 */
struct NIFLIB_API StringPalette {
	/*! Default Constructor */
	StringPalette();
	/*! Copy Constructor */
	StringPalette( const StringPalette & src );
	/*! Copy Operator */
	StringPalette & operator=( const StringPalette & src );
	/*! Default Destructor */
	~StringPalette();
	/*!
	 * A bunch of 0x00 seperated strings.
	 */
	string palette;
	/*!
	 * Length of the palette string is repeated here.
	 */
	unsigned int length;
};

}
#endif
