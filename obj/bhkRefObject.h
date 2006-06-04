/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKREFOBJECT_H_
#define _BHKREFOBJECT_H_

#include "NiObject.h"

#include "gen/obj_defines.h"

class bhkRefObject;
typedef Ref<bhkRefObject> bhkRefObjectRef;

/*!
 * bhkRefObject - The base type of all Havok objects?
 */

class bhkRefObject : public BHK_REF_OBJECT_PARENT {
public:
	bhkRefObject();
	~bhkRefObject();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	BHK_REF_OBJECT_MEMBERS
};

#endif
