/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISOURCETEXTURE_H_
#define _NISOURCETEXTURE_H_

#include "xml_extract.h"
#include NI_SOURCE_TEXTURE_INCLUDE

/*
 * NiSourceTexture
 */

class NiSourceTexture;
typedef Ref<NiSourceTexture> NiSourceTextureRef;

class NiSourceTexture : public NI_SOURCE_TEXTURE_PARENT {
public:
	NiSourceTexture();
	~NiSourceTexture();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version );
private:
	NI_SOURCE_TEXTURE_MEMBERS
};
#endif
