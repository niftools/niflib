/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _HKPACKEDNITRISTRIPSDATA_H_
#define _HKPACKEDNITRISTRIPSDATA_H_

#include "xml_extract.h"
#include HK_PACKED_NI_TRI_STRIPS_DATA_INCLUDE

/*
 * hkPackedNiTriStripsData
 */

class hkPackedNiTriStripsData;
typedef Ref<hkPackedNiTriStripsData> hkPackedNiTriStripsDataRef;

class hkPackedNiTriStripsData : public HK_PACKED_NI_TRI_STRIPS_DATA_PARENT {
public:
	hkPackedNiTriStripsData();
	~hkPackedNiTriStripsData();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version );
private:
	HK_PACKED_NI_TRI_STRIPS_DATA_MEMBERS
};
#endif
