/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIVERTWEIGHTSEXTRADATA_H_
#define _NIVERTWEIGHTSEXTRADATA_H_

#include "NiExtraData.h"

#include "gen/obj_defines.h"

/*
 * NiVertWeightsExtraData
 */

class NiVertWeightsExtraData;
typedef Ref<NiVertWeightsExtraData> NiVertWeightsExtraDataRef;

class NiVertWeightsExtraData : public NI_VERT_WEIGHTS_EXTRA_DATA_PARENT {
public:
	NiVertWeightsExtraData();
	~NiVertWeightsExtraData();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_VERT_WEIGHTS_EXTRA_DATA_MEMBERS
};

#endif
