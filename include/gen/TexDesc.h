/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _TEXDESC_H_
#define _TEXDESC_H_

#include "../NIF_IO.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class NiSourceTexture;

/*!
 * Texture description.
 */
struct NIFLIB_API TexDesc {
	/*! Default Constructor */
	TexDesc();
	/*! Default Destructor */
	~TexDesc();
	/*!
	 * NiSourceTexture object index.
	 */
	Ref<NiSourceTexture > source;
	/*!
	 * 0=clamp S clamp T, 1=clamp S wrap T, 2=wrap S clamp T, 3=wrap S wrap T
	 */
	TexClampMode clampMode;
	/*!
	 * 0=nearest, 1=bilinear, 2=trilinear, 3=..., 4=..., 5=...
	 */
	TexFilterMode filterMode;
	/*!
	 * The texture coordinate set in NiTriBasedGeomData that this texture
	 * slot will use.
	 */
	uint uvSet;
	/*!
	 * 0?
	 */
	ushort ps2L;
	/*!
	 * 0xFFB5?
	 */
	ushort ps2K;
	/*!
	 * Unknown, 0 or 0x0101?
	 */
	ushort unknown1;
	/*!
	 * Determines whether or not the texture's coordinates are transformed.
	 */
	bool hasTextureTransform;
	/*!
	 * The amount to translate the texture coordinates in each direction?
	 */
	TexCoord translation;
	/*!
	 * The number of times the texture is tiled in each direction?
	 */
	TexCoord tiling;
	/*!
	 * 2D Rotation of texture image around third W axis after U and V.
	 */
	float wRotation;
	/*!
	 * The texture transform type?  Doesn't seem to do anything.
	 */
	uint transformType_;
	/*!
	 * The offset from the origin?
	 */
	TexCoord centerOffset;
};

}
#endif
