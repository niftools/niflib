/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKSPHEREREPSHAPE_H_
#define _BHKSPHEREREPSHAPE_H_

#include "bhkShape.h"
namespace Niflib {


//#include "../gen/obj_defines.h"

class bhkSphereRepShape;
typedef Ref<bhkSphereRepShape> bhkSphereRepShapeRef;

/*!
 * bhkSphereRepShape - A havok shape, perhaps with a bounding sphere for
 * quick rejection in addition to more detailed shape data?
 */

class bhkSphereRepShape : public BHK_SPHERE_REP_SHAPE_PARENT {
public:
	NIFLIB_API bhkSphereRepShape();
	NIFLIB_API ~bhkSphereRepShape();
	//Run-Time Type Information
	NIFLIB_API static const Type & TypeConst();
private:
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * The shape's material.
	 */
	NIFLIB_API HavokMaterial GetMaterial() const;
	NIFLIB_API void SetMaterial( HavokMaterial value );

protected:
	BHK_SPHERE_REP_SHAPE_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
