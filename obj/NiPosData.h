/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPOSDATA_H_
#define _NIPOSDATA_H_

#include "AKeyedData.h"
#include "gen/KeyGroup.h"

#include "gen/obj_defines.h"

/*
 * NiPosData
 */

class NiPosData;
typedef Ref<NiPosData> NiPosDataRef;

class NiPosData : public NI_POS_DATA_PARENT {
public:
	NiPosData();
	~NiPosData();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual const Type & GetType() const;
protected:
	NI_POS_DATA_MEMBERS
};

#endif
