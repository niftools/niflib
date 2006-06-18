/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _TEXSOURCE_H_
#define _TEXSOURCE_H_

#include "../NIF_IO.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class NiObject;
class NiPixelData;

/*!
 * A texture source.
 */
struct NIFLIB_API TexSource {
	/*! Default Constructor */
	TexSource();
	/*! Default Destructor */
	~TexSource();
	/*!
	 * Is the texture external?
	 */
	byte useExternal;
	/*!
	 * The external texture file name.  Note: all original morrowind nifs use
	 * name.ext only for addressing the textures, but most mods use something
	 * like textures/[subdir/]name.ext. This is due to a feature in Morrowind
	 * resource manager: it loads name.ext, textures/name.ext and
	 * textures/subdir/name.ext but NOT subdir/name.ext.
	 */
	string fileName;
	/*!
	 * Unknown.
	 */
	Ref<NiObject > unknownLink;
	/*!
	 * Unknown.
	 */
	byte unknownByte;
	/*!
	 * The original source filename of the image embedded by the referred
	 * NiPixelData block.
	 */
	string originalFileName_;
	/*!
	 * Pixel data block index.
	 */
	Ref<NiPixelData > pixelData;
};

}
#endif
