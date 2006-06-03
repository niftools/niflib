/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISEQUENCESTREAMHELPER_H_
#define _NISEQUENCESTREAMHELPER_H_

#include "NiObjectNET.h"

#include "gen/obj_defines.h"

/*
 * NiSequenceStreamHelper
 */

class NiSequenceStreamHelper;
typedef Ref<NiSequenceStreamHelper> NiSequenceStreamHelperRef;

class NiSequenceStreamHelper : public NI_SEQUENCE_STREAM_HELPER_PARENT {
public:
	NiSequenceStreamHelper();
	~NiSequenceStreamHelper();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual const Type & GetType() const;
protected:
	NI_SEQUENCE_STREAM_HELPER_MEMBERS
};

#endif
