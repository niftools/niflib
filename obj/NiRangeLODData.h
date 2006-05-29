/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIRANGELODDATA_H_
#define _NIRANGELODDATA_H_

#include "xml_extract.h"
#include NI_RANGE_L_O_D_DATA_INCLUDE

/*
 * NiRangeLODData
 */

class NiRangeLODData;
typedef Ref<NiRangeLODData> NiRangeLODDataRef;

class NiRangeLODData : public NI_RANGE_L_O_D_DATA_PARENT {
public:
	NiRangeLODData();
	~NiRangeLODData();
	//Run-Time Type Information
	static const Type TYPE;
	virtual const Type & GetType() const { return TYPE; };
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
private:
	NI_RANGE_L_O_D_DATA_MEMBERS
};
#endif
