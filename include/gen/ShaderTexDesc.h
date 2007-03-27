/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _SHADERTEXDESC_H_
#define _SHADERTEXDESC_H_

#include "../NIF_IO.h"

// Include structures
#include "TexDesc.h"
namespace Niflib {


/*!
 * An extended texture description for shader textures.
 */
struct ShaderTexDesc {
	/*! Default Constructor */
	NIFLIB_API ShaderTexDesc();
	/*! Copy Constructor */
	NIFLIB_API ShaderTexDesc( const ShaderTexDesc & src );
	/*! Copy Operator */
	NIFLIB_API ShaderTexDesc & operator=( const ShaderTexDesc & src );
	/*! Default Destructor */
	NIFLIB_API ~ShaderTexDesc();
	/*!
	 * Is it used?
	 */
	bool isUsed;
	/*!
	 * The texture data.
	 */
	TexDesc textureData;
	/*!
	 * Unknown.
	 */
	unsigned int unknownInt;
};

}
#endif
