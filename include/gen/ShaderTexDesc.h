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
struct NIFLIB_API ShaderTexDesc {
	/*! Default Constructor */
	ShaderTexDesc();
	/*! Copy Constructor */
	ShaderTexDesc( const ShaderTexDesc & src );
	/*! Copy Operator */
	ShaderTexDesc & operator=( const ShaderTexDesc & src );
	/*! Default Destructor */
	~ShaderTexDesc();
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
