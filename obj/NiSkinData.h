/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISKINDATA_H_
#define _NISKINDATA_H_

#include "NiObject.h"
// Include structures
#include "../gen/SkinData.h"

// Forward define of referenced blocks
#include "../Ref.h"
class NiSkinPartition;

#include "../gen/obj_defines.h"

class NiSkinData;
typedef Ref<NiSkinData> NiSkinDataRef;

/*!
 * NiSkinData - Skinning data.
 */

class DLLEXPORT NiSkinData : public NI_SKIN_DATA_PARENT {
public:
	NiSkinData();
	~NiSkinData();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_SKIN_DATA_MEMBERS
};

#endif
