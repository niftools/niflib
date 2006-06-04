/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPIXELDATA_H_
#define _NIPIXELDATA_H_

#include "NiObject.h"
// Include structures
#include "gen/MipMap.h"
#include "gen/ByteArray.h"

// Forward define of referenced blocks
#include "Ref.h"
class NiPalette;

#include "gen/obj_defines.h"

class NiPixelData;
typedef Ref<NiPixelData> NiPixelDataRef;

/*!
 * NiPixelData - A texture.
 */

class NiPixelData : public NI_PIXEL_DATA_PARENT {
public:
	NiPixelData();
	~NiPixelData();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_PIXEL_DATA_MEMBERS
};

#endif
