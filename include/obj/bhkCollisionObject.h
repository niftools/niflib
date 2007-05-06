/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _BHKCOLLISIONOBJECT_H_
#define _BHKCOLLISIONOBJECT_H_

#include "NiCollisionObject.h"
namespace Niflib {

//#include "../gen/obj_defines.h"

class bhkCollisionObject;
typedef Ref<bhkCollisionObject> bhkCollisionObjectRef;

/*!
 * bhkCollisionObject - Unknown.
 */

class bhkCollisionObject : public BHK_COLLISION_OBJECT_PARENT {
public:
	NIFLIB_API bhkCollisionObject();
	NIFLIB_API ~bhkCollisionObject();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
	virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_API virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_API virtual list<NiObjectRef> GetRefs() const;
	NIFLIB_API virtual const Type & GetType() const;

protected:
	BHK_COLLISION_OBJECT_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
