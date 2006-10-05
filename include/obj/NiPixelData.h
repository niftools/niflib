/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPIXELDATA_H_
#define _NIPIXELDATA_H_

#include "NiObject.h"
// Include structures
#include "../Ref.h"
#include "../gen/MipMap.h"
#include "../gen/ByteArray.h"
namespace Niflib {

// Forward define of referenced blocks
class NiPalette;

#include "../gen/obj_defines.h"

class NiPixelData;
typedef Ref<NiPixelData> NiPixelDataRef;

/*!
 * NiPixelData - A texture.
 */

class NIFLIB_API NiPixelData : public NI_PIXEL_DATA_PARENT {
public:
	NiPixelData();
	~NiPixelData();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:	
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	/*! Retrieves the height of the texture image stored in this block.
	 * \return The height of the texture image stored in this block.
	 * \sa NiPixelData::GetWidth, NiPixelData::GetPixelFormat
	 */
	int GetHeight() const;

	/*! Retrieves the width of the texture image stored in this block.
	 * \return The width of the texture image stored in this block.
	 * \sa NiPixelData::GetHeight, NiPixelData::GetPixelFormat
	 */
	int GetWidth() const;

    /*! Retrieves the pixel format of the texture image stored in this block.
	 * \return The pixel format of the texture image stored in this block.
	 * \sa NiPixelData::GetWidth, NiPixelData::GetHeight
	 */
	PixelFormat GetPixelFormat() const;

    /*! Deletes all image data and sets a new size and format in preparation for new data to be provided.
	 * \param new_width The width of the new texture image.
	 * \param new_height The height of the new texture image.
	 * \param px_fmt The pixel format of the new texture image.
	 * \sa NiPixelData::GetWidth, NiPixelData::GetHeight
	 */
	void Reset( int new_width, int new_height, PixelFormat px_fmt );
	
	/*! Retrieves the the pixels of the texture image stored in this block.  This function does not work on palettized textures.
	 * \return A vector containing the colors of each pixel in the texture image stored in this block, one row after another starting from the bottom of the image.  The width of the image must be used to interpret them correctly.
	 * \sa NiPixelData::SetColors, NiPixelData::GetWidth
	 */
	vector<Color4> GetColors() const;

	/*! Sets the the pixels of the texture image stored in this block and optionally generates mipmaps.  This function does not work for palettized textures.
	 * \param new_pixels A vector containing the colors of each new pixel to be set in the texture image stored in this block, one row after another starting from the botom of the image.
	 * \param generate_mipmaps If true, mipmaps will be generated for the new image and stored in the file.
	 * \sa NiPixelData::GetColors, NiPixelData::GetWidth
	 */
	void SetColors( const vector<Color4> & new_pixels, bool generate_mipmaps );

protected:
	NI_PIXEL_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
