/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKSPHERESHAPE_H_
#define _BHKSPHERESHAPE_H_

#include "bhkConvexShape.h"
namespace Niflib {


//#include "../gen/obj_defines.h"

class bhkSphereShape;
typedef Ref<bhkSphereShape> bhkSphereShapeRef;

/*!
 * bhkSphereShape - A sphere.
 */

class bhkSphereShape : public BHK_SPHERE_SHAPE_PARENT {
public:
	NIFLIB_API bhkSphereShape();
	NIFLIB_API ~bhkSphereShape();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Retrieves the radius of the sphere.
	 * \return The radius of the sphere.
	 */
	NIFLIB_API float GetRadius() const;

	/*!
	 * Sets a new value for the radius of the sphere.
	 * \param[in] value The new radius of the sphere.
	 */
	NIFLIB_API void SetRadius( float value );

protected:
	BHK_SPHERE_SHAPE_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
