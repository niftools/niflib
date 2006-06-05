/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISTRINGSEXTRADATA_H_
#define _NISTRINGSEXTRADATA_H_

#include "NiExtraData.h"

#include "../gen/obj_defines.h"

class NiStringsExtraData;
typedef Ref<NiStringsExtraData> NiStringsExtraDataRef;

/*!
 * NiStringsExtraData - List of strings; for example, a list of all bone
 * names.
 */

class NiStringsExtraData : public NI_STRINGS_EXTRA_DATA_PARENT {
public:
	NiStringsExtraData();
	~NiStringsExtraData();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_STRINGS_EXTRA_DATA_MEMBERS
};

#endif
