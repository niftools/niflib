/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKCOLLISIONOBJECT_H_
#define _BHKCOLLISIONOBJECT_H_

#include "xml_extract.h"
#include BHK_COLLISION_OBJECT_INCLUDE

/*
 * bhkCollisionObject
 */

class bhkCollisionObject;
typedef Ref<bhkCollisionObject> bhkCollisionObjectRef;

class bhkCollisionObject : public BHK_COLLISION_OBJECT_PARENT {
public:
	bhkCollisionObject();
	~bhkCollisionObject();
	//Run-Time Type Information
	static const Type TYPE;
	virtual const Type & GetType() const { return TYPE; };
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
private:
	BHK_COLLISION_OBJECT_MEMBERS
};
#endif
