/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISTRINGEXTRADATA_H_
#define _NISTRINGEXTRADATA_H_

#include "NiExtraData.h"

#include "../gen/obj_defines.h"

class NiStringExtraData;
typedef Ref<NiStringExtraData> NiStringExtraDataRef;

/*!
 * NiStringExtraData - Apparently commands for an optimizer instructing
 * it to keep things it would normally discard. Also refers to NiNode
 * blocks (through their name) in animation .kf files.
 */

class NIFLIB_API NiStringExtraData : public NI_STRING_EXTRA_DATA_PARENT {
public:
	NiStringExtraData();
	~NiStringExtraData();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	uint BytesRemaining() const;
	NI_STRING_EXTRA_DATA_MEMBERS
};

#endif
