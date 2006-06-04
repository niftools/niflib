/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIDEFAULTAVOBJECTPALETTE_H_
#define _NIDEFAULTAVOBJECTPALETTE_H_

#include "NiObject.h"
// Include structures
#include "gen/AVObject.h"

#include "gen/obj_defines.h"

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
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_DEFAULT_A_V_OBJECT_PALETTE_MEMBERS
};

#endif
