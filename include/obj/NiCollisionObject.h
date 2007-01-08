/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NICOLLISIONOBJECT_H_
#define _NICOLLISIONOBJECT_H_

#include "NiObject.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class NiAVObject;
class NiObject;

//#include "../gen/obj_defines.h"

class NiCollisionObject;
typedef Ref<NiCollisionObject> NiCollisionObjectRef;

/*!
 * NiCollisionObject - Unknown.
 */

class NIFLIB_API NiCollisionObject : public NI_COLLISION_OBJECT_PARENT {
public:
	NiCollisionObject();
	~NiCollisionObject();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	/*!
	 * Links to the node parent.
	 */
   Ref<NiAVObject> GetParent() const;
	void SetParent( NiAVObject * value );

	/*!
	 * Links to the collision object data
	 */
	Ref<NiObject > GetBody() const;
	void SetBody( Ref<NiObject > value );

protected:
	NI_COLLISION_OBJECT_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
