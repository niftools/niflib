/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKSPCOLLISIONOBJECT_H_
#define _BHKSPCOLLISIONOBJECT_H_

#include "NiCollisionObject.h"

#include "../gen/obj_defines.h"

class bhkSPCollisionObject;
typedef Ref<bhkSPCollisionObject> bhkSPCollisionObjectRef;

/*!
 * bhkSPCollisionObject - Unknown.
 */

class bhkSPCollisionObject : public BHK_S_P_COLLISION_OBJECT_PARENT {
public:
	bhkSPCollisionObject();
	~bhkSPCollisionObject();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	BHK_S_P_COLLISION_OBJECT_MEMBERS
};

#endif
