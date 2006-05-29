/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIDEFAULTAVOBJECTPALETTE_H_
#define _NIDEFAULTAVOBJECTPALETTE_H_

#include "xml_extract.h"
#include NI_DEFAULT_A_V_OBJECT_PALETTE_INCLUDE

/*
 * NiDefaultAVObjectPalette
 */

class NiDefaultAVObjectPalette;
typedef Ref<NiDefaultAVObjectPalette> NiDefaultAVObjectPaletteRef;

class NiDefaultAVObjectPalette : public NI_DEFAULT_A_V_OBJECT_PALETTE_PARENT {
public:
	NiDefaultAVObjectPalette();
	~NiDefaultAVObjectPalette();
	//Run-Time Type Information
	static const Type TYPE;
	virtual const Type & GetType() const { return TYPE; };
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
private:
	NI_DEFAULT_A_V_OBJECT_PALETTE_MEMBERS
};
#endif
