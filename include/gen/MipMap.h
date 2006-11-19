/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _MIPMAP_H_
#define _MIPMAP_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * Description of a MipMap within a NiPixelData object.
 */
struct NIFLIB_API MipMap {
	/*! Default Constructor */
	MipMap();
	/*! Copy Constructor */
	MipMap( const MipMap & src );
	/*! Copy Operator */
	MipMap & operator=( const MipMap & src );
	/*! Default Destructor */
	~MipMap();
	/*!
	 * Width of the mipmap image.
	 */
	uint width;
	/*!
	 * Height of the mipmap image.
	 */
	uint height;
	/*!
	 * Offset into the pixel data array where this mipmap starts.
	 */
	uint offset;
};

}
#endif
