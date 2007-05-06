/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _NISOURCETEXTURE_H_
#define _NISOURCETEXTURE_H_

#include "NiObjectNET.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiObject;
class NiPixelData;

//#include "../gen/obj_defines.h"

class NiSourceTexture;
typedef Ref<NiSourceTexture> NiSourceTextureRef;

/*!
 * NiSourceTexture - Describes texture source and properties.
 */

class NiSourceTexture : public NI_SOURCE_TEXTURE_PARENT {
public:
	NIFLIB_API NiSourceTexture();
	NIFLIB_API ~NiSourceTexture();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Used to check whether the texture referenced by this object is an external file.
	 * \return True if the texture is stored in an external file, false if it is stored within this NIF file.
	 */
	NIFLIB_API bool IsTextureExternal() const;

	/*!
	 * Sets a new external file texture.  Removes any existing texture references, whether internal or external.
	 * \param[in] file_name The file name of the external texture.  Often needs to follow game guidlines to be found.
	 */
	NIFLIB_API void SetExternalTexture( string file_name );

	/*!
	 * Sets a new internal file texture.  Removes any existing texture references, whether internal or external.
	 * \param[in] original_file_name The original file name of the texture.  This may be optional.
	 * \param[in] pixel_data The NiPixelData object that contains the texture image data.
	 */
	NIFLIB_API void SetInternalTexture( string original_file_name, NiPixelData * pixel_data );

	/*!
	 * Returns either the file name of the external texture, or the original file name of the internal one.
	 * \return The name of the texture file.
	 */
	NIFLIB_API string GetTextureFileName() const;

	/*!
	 * Returns a reference to the texture image data object used by this texture, if any.
	 * \return The iamge data object referenced by this texture, or NULL if one is not being used.
	 */
	NIFLIB_API Ref<NiPixelData> GetPixelData() const;

	/*!
	 * Gets the current pixel layout of this texture.  This is the image format, usually the color depth.
	 * \return The pixel layout of this texture.
	 */
	NIFLIB_API PixelLayout GetPixelLayout() const;

	/*!
	 * Sets the pixel layout of this texture.  This is the image format, usually the color depth.
	 * \param[in] n The new pixel layout of this texture.
	 */
	NIFLIB_API void SetPixelLayout( PixelLayout n );

	/*!
	 * Gets the current mip map format of this texture.  Specifies whether or not the texture contains mipmaps which are smaller versions of the texture that will be displayed on far away objects that use it.
	 * \return The current mip map format of this texture.
	 */
	NIFLIB_API MipMapFormat GetMipMapFormat() const;

	/*!
	 * Sets the mip map format of this texture.  Specifies whether or not the texture contains mipmaps which are smaller versions of the texture that will be displayed on far away objects that use it.
	 * \param[in] n The new mip map format of this texture.
	 */
	NIFLIB_API void SetMipMapFormat( MipMapFormat n );

	/*!
	 * Gets the current alpha format of this texture.  Specifies whether and how the texture uses alpha transparency.
	 * \return The current alpha format of this texture.
	 */
	NIFLIB_API AlphaFormat GetAlphaFormat() const;

	/*!
	 * Sets the alpha format of this texture.  Specifies whether and how the texture uses alpha transparency.
	 * \param[in] n The new alpha format of this texture.
	 */
	NIFLIB_API void SetAlphaFormat( AlphaFormat n );

protected:
	NI_SOURCE_TEXTURE_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
