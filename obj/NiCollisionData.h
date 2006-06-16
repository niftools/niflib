/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NICOLLISIONDATA_H_
#define _NICOLLISIONDATA_H_

#include "NiObject.h"

// Forward define of referenced blocks
#include "../Ref.h"
class NiNode;

#include "../gen/obj_defines.h"

class NiCollisionData;
typedef Ref<NiCollisionData> NiCollisionDataRef;

/*!
 * NiCollisionData - Collision box.
 */

class NIFLIB_API NiCollisionData : public NI_COLLISION_DATA_PARENT {
public:
	NiCollisionData();
	~NiCollisionData();
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
	NI_COLLISION_DATA_MEMBERS
};

#endif
