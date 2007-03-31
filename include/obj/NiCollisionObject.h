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

class NiCollisionObject : public NI_COLLISION_OBJECT_PARENT {
public:
	NIFLIB_API NiCollisionObject();
	NIFLIB_API ~NiCollisionObject();
	//Run-Time Type Information
	NIFLIB_API static const Type & TypeConst();
private:
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Links to the node parent.
	 */
	NIFLIB_API Ref<NiAVObject> GetParent() const;
	NIFLIB_API void SetParent( NiAVObject * value );

	/*!
	 * Links to the collision object data
	 */
	NIFLIB_API Ref<NiObject > GetBody() const;
	NIFLIB_API void SetBody( Ref<NiObject > value );

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
