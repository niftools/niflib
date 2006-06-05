/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _HKPACKEDNITRISTRIPSDATA_H_
#define _HKPACKEDNITRISTRIPSDATA_H_

#include "AbhkShapeCollection.h"
// Include structures
#include "../gen/hkTriangle.h"

#include "../gen/obj_defines.h"

class hkPackedNiTriStripsData;
typedef Ref<hkPackedNiTriStripsData> hkPackedNiTriStripsDataRef;

/*!
 * hkPackedNiTriStripsData - NiTriStripsData for havok data?
 */

class hkPackedNiTriStripsData : public HK_PACKED_NI_TRI_STRIPS_DATA_PARENT {
public:
	hkPackedNiTriStripsData();
	~hkPackedNiTriStripsData();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	HK_PACKED_NI_TRI_STRIPS_DATA_MEMBERS
};

#endif
