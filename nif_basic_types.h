/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIF_BASIC_TYPES_H_
#define _NIF_BASIC_TYPES_H_

#include <string>
namespace Niflib {
using namespace std;

struct HeaderString {
	string header;
};

struct ShortString {
	string str;
};

//TODO:  This is temporary to make it compile.  Should eventually be adjusted to display 1's and 0's insted of as an int.
typedef unsigned short Flags;

/*! Lists the basic texture types availiable from the ITexturingProperty interface*/
enum TexType {
	BASE_MAP = 0, /*!< The basic texture used by most meshes. */ 
	DARK_MAP = 1, /*!< Used to darken the model with false lighting. */ 
	DETAIL_MAP = 2, /*!< Combined with base map for added detail. */ 
	GLOSS_MAP = 3, /*!< Allows the glossyness of an object to differ across its surface. */ 
	GLOW_MAP = 4, /*!< Creates a glowing effect. */ 
	BUMP_MAP = 5, /*!< Used to make the object appear to have more detail than it really does. */ 
	DECAL_0_MAP = 6, /*!< For placing images on the object like stickers. */ 
	DECAL_1_MAP = 7 /*!< For placing images on the object like stickers. */ 
};

/*! Specifies the availiable texture apply modes.  Affects the way colors are composed together. */
enum ApplyMode {
   APPLY_REPLACE = 0, /*!< Replaces existing color */ 
   APPLY_DECAL = 1, /*!< For placing images on the object like stickers. */ 
   APPLY_MODULATE = 2, /*!< Modulates existing color. */ 
   APPLY_HILIGHT = 3, /*!< PS2 Only */
   APPLY_HILIGHT2 = 4 /*!< PS2 Only */
};

/*! Specifies the availiable texture clamp modes.  That is, the behavior of pixels outside the range of the texture.*/
enum TexClampMode {
	CLAMP_S_CLAMP_T = 0, /*!< Clamp in both directions. */ 
	CLAMP_S_WRAP_T = 1, /*!< Clamp in the S direction but wrap in the T direction. */ 
	WRAP_S_CLAMP_T = 2, /*!< Wrap in the S direction but clamp in the T direction. */ 
	WRAP_S_WRAP_T = 3 /*!< Wrap in both directions. */ 
};

/*! Specifies the availiable texture filter modes.  That is, the way pixels within a texture are blended together when textures are displayed on the screen at a size other than their original dimentions.*/
enum TexFilterMode {
	FILTER_NEAREST = 0, /*!< Simply uses the nearest pixel.  Very grainy. */ 
	FILTER_BILERP = 1, /*!< Uses bilinear filtering. */ 
	FILTER_TRILERP = 2, /*!< Uses trilinear filtering. */ 
	FILTER_NEAREST_MIPNEAREST = 3, /*!< Uses the nearest pixel from the mipmap that is closest to the display size. */ 
	FILTER_NEAREST_MIPLERP = 4, /*!< Blends the two mipmaps closest to the display size linearly, and then uses the nearest pixel from the result. */ 
	FILTER_BILERP_MIPNEAREST = 5, /*!< Uses the closest mipmap to the display size and then uses bilinear filtering on the pixels. */ 
};

/*! Specifies the availiable alpha formats.  That is, the type of alpha blending (transparency) that will be used on a particular texture.*/
enum AlphaFormat {
   ALPHA_NONE = 0, /*!< No alpha blending, the texture is fully opaque */ 
   ALPHA_BINARY = 1, /*!< Texture is either fully transparent or fully opaque.  There are no partially transparent areas. */ 
   ALPHA_SMOOTH = 2, /*!< Full range of alpha values can be used from fully transparent to fully opaque including all partially transparent values in between. */ 
   ALPHA_DEFAULT = 3 /*!< Use default setting. */ 
};

/*!
 * This enum contains all the animation key types used by Niflib.
 */
enum KeyType {
	LINEAR_KEY = 1, /*!< Use linear interpolation. */ 
	QUADRATIC_KEY = 2, /*!< Use quadratic interpolation.  Forward and back tangents will be stored.*/ 
	TBC_KEY = 3, /*!< Use Tension Bias Continuity interpolation.  Tension, bias, and continuity will be stored.*/ 
	XYZ_ROTATION_KEY = 4 /*!< For use only with rotation data.  Separate X, Y, and Z keys will be stored instead of using quaternions. */ 
};

/*!
 * Specifies the pixel format used by the NiPixelData object to store a texture.
 */
enum PixelFormat {
	PX_FMT_RGB8 = 0, /*!< 24-bit color: uses 8 bit to store each red, blue, and green component. */
	PX_FMT_RGBA8 = 1, /*!< 32-bit color with alpha: uses 8 bits to store each red, blue, green, and alpha component. */
	PX_FMT_PAL8 = 2 /*!< 8-bit palette index: uses 8 bits to store an index into the palette stored in a NiPallete block. */
};

/*!
 * Specifies the mip map format of a texture.
 */
enum MipMapFormat {
	MIP_FMT_NO = 0, /*!< Texture does not use mip maps. */
	MIP_FMT_YES = 1,/*!< Texture uses mip maps. */
	MIP_FMT_DEFAULT = 2, /*!< Use default setting. */
};

/*!
 * Specifies the pixel layout of a texture.  That is, the format of the image data.
 */
enum PixelLayout {
	PIX_LAY_PALETTISED = 0, /*!< Texture is in 8-bit paletized format. */
	PIX_LAY_HIGH_COLOR_16 = 1, /*!< Texture is in 16-bit high color format. */
	PIX_LAY_TRUE_COLOR_32 = 2, /*!< Texture is in 32-bit true color format. */
	PIX_LAY_COMPRESSED = 3, /*!< Texture is compressed. */
	PIX_LAY_BUMPMAP = 4, /*!< Texture is a grayscale bump map. */
	PIX_LAY_DEFAULT = 5 /*!< Use default setting. */
};

/*!
 * Specifies what type of light is active on the shape.
 */
enum VertMode {
	VERT_MODE_SRC_IGNORE = 0, /*!< Source Ignore. */
	VERT_MODE_SRC_EMISSIVE = 1, /*!< Source Emissive. */
	VERT_MODE_SRC_AMB_DIF = 2, /*!< Source Ambient/Diffuse. (Default) */
};

/*!
 * Specifies the light mode.
 */
enum LightMode {
	LIGHT_MODE_EMISSIVE = 0, /*!< Emissive. */
	LIGHT_MODE_EMI_AMB_DIF = 1, /*!< Emissive + Ambient + Diffuse. (Default) */
};

}
#endif
