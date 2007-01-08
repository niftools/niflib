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

class NIFLIB_API NiSourceTexture : public NI_SOURCE_TEXTURE_PARENT {
public:
	NiSourceTexture();
	~NiSourceTexture();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:	
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	bool IsTextureExternal ();

	void SetExternalTexture( string file_name, const Ref<NiObject> & unk_link );

	void SetInternalTexture( byte unk_byte, string original_file_name, const Ref<NiPixelData> & pixel_data );

	string GetExternalFileName() const;
	Ref<NiObject> GetExternalUnknownLink() const;

	byte GetInternalUnknownByte() const;
	string GetInternalOriginalFileName() const;
	Ref<NiPixelData> GetInternalPixelData() const;

	PixelLayout GetPixelLayout() const;
	void SetPixelLayout( PixelLayout n );

	MipMapFormat GetMipMapFormat() const;
	void SetMipMapFormat( MipMapFormat n );

	AlphaFormat GetAlphaFormat() const;
	void SetAlphaFormat( AlphaFormat n );

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
