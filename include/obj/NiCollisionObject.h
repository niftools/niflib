/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NICOLLISIONOBJECT_H_
#define _NICOLLISIONOBJECT_H_

#include "NiObject.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
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
	NIFLIB_API static const Type TYPE;
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Returns the NiNode that this collision object is connected to, if any.
	 * \return The NiNode that this collision object is connected to, or NULL if it is not connected to any nodes.
	 */
	NIFLIB_API Ref<NiAVObject> GetParent() const;

	/*!
	 * Gets the rigid body that this collision object uses, if any.
	 * \return The rigid body that this object references, or a NULL reference if it does not reference any.
	 */
	NIFLIB_API Ref<NiObject> GetBody() const;

	/*!
	 * Sets the new rigid body that this collision object uses.
	 * \param[in] value The new rigid body for this collision object to use, or NULL to clear the current reference.
	 */
	NIFLIB_API void SetBody( NiObject * value );

	/*! NIFLIB_HIDDEN function.  For internal use only */
	NIFLIB_HIDDEN void SetParent( NiAVObject * value );

protected:
	NI_COLLISION_OBJECT_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
