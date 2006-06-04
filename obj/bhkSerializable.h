/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKSERIALIZABLE_H_
#define _BHKSERIALIZABLE_H_

#include "bhkRefObject.h"

#include "gen/obj_defines.h"

/*
 * bhkSerializable
 */

class bhkSerializable;
typedef Ref<bhkSerializable> bhkSerializableRef;

class bhkSerializable : public BHK_SERIALIZABLE_PARENT {
public:
	bhkSerializable();
	~bhkSerializable();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	BHK_SERIALIZABLE_MEMBERS
};

#endif
