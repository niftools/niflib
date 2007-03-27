/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISOURCETEXTURE_H_
#define _NISOURCETEXTURE_H_

#include "NiObjectNET.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
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
	NIFLIB_API static const Type & TypeConst() { return TYPE; }
private:	
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const { return TYPE; };
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	NIFLIB_API bool IsTextureExternal ();

	NIFLIB_API void SetExternalTexture( string file_name, const Ref<NiObject> & unk_link );

	NIFLIB_API void SetInternalTexture( byte unk_byte, string original_file_name, const Ref<NiPixelData> & pixel_data );

	NIFLIB_API string GetExternalFileName() const;
	NIFLIB_API Ref<NiObject> GetExternalUnknownLink() const;

	NIFLIB_API byte GetInternalUnknownByte() const;
	NIFLIB_API string GetInternalOriginalFileName() const;
	NIFLIB_API Ref<NiPixelData> GetInternalPixelData() const;

	NIFLIB_API PixelLayout GetPixelLayout() const;
	NIFLIB_API void SetPixelLayout( PixelLayout n );

	NIFLIB_API MipMapFormat GetMipMapFormat() const;
	NIFLIB_API void SetMipMapFormat( MipMapFormat n );

	NIFLIB_API AlphaFormat GetAlphaFormat() const;
	NIFLIB_API void SetAlphaFormat( AlphaFormat n );

	//TODO: Fix name problem with Unknown Byte in XML
	//byte GetUnknownByte2() const;
	//SetUnknownByte2( byte n );

	//byte GetUnknownByte3() const;
	//SetUnknownByte3( byte n );
protected:
	NI_SOURCE_TEXTURE_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
