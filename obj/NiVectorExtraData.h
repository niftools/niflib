/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIVECTOREXTRADATA_H_
#define _NIVECTOREXTRADATA_H_

#include "NiExtraData.h"

#include "../gen/obj_defines.h"

class NiVectorExtraData;
typedef Ref<NiVectorExtraData> NiVectorExtraDataRef;

/*!
 * NiVectorExtraData - Extra vector data.
 */

class NIFLIB_API NiVectorExtraData : public NI_VECTOR_EXTRA_DATA_PARENT {
public:
	NiVectorExtraData();
	~NiVectorExtraData();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:	
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_VECTOR_EXTRA_DATA_MEMBERS
};

#endif
