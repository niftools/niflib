/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIKEYFRAMEDATA_H_
#define _NIKEYFRAMEDATA_H_

#include "AKeyedData.h"
// Include structures
#include "gen/KeyGroup.h"

#include "gen/obj_defines.h"

/*
 * NiKeyframeData
 */

class NiKeyframeData;
typedef Ref<NiKeyframeData> NiKeyframeDataRef;

class NiKeyframeData : public NI_KEYFRAME_DATA_PARENT {
public:
	NiKeyframeData();
	~NiKeyframeData();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual const Type & GetType() const;
protected:
	NI_KEYFRAME_DATA_MEMBERS
};

#endif
