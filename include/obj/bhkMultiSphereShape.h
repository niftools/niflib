/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _BHKMULTISPHERESHAPE_H_
#define _BHKMULTISPHERESHAPE_H_

#include "bhkSphereRepShape.h"

// Include structures
#include "../gen/Sphere.h"
namespace Niflib {

//#include "../gen/obj_defines.h"

class bhkMultiSphereShape;
typedef Ref<bhkMultiSphereShape> bhkMultiSphereShapeRef;

/*!
 * bhkMultiSphereShape - Unknown.
 */

class bhkMultiSphereShape : public BHK_MULTI_SPHERE_SHAPE_PARENT {
public:
	NIFLIB_API bhkMultiSphereShape();
	NIFLIB_API ~bhkMultiSphereShape();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	//--BEGIN MISC CUSTOM CODE--//

	/*!
	 * Gets the spheres which make up the multi sphere shape.
	 * \return The spheres which make up the multi sphere shape.
	 */
	NIFLIB_API vector<Sphere> GetSpheres() const;

	/*!
	 * Sets the spheres which make up the multi sphere shape.
	 * \param[in] value The new spheres which will make up the multi sphere shape.
	 */

	NIFLIB_API void SetSpheres( const vector<Sphere> & value );

	//--END CUSTOM CODE--//

protected:
	BHK_MULTI_SPHERE_SHAPE_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
