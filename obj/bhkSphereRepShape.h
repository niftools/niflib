/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKSPHEREREPSHAPE_H_
#define _BHKSPHEREREPSHAPE_H_

#include "bhkShape.h"
namespace NifLib {


#include "../gen/obj_defines.h"

class bhkSphereRepShape;
typedef Ref<bhkSphereRepShape> bhkSphereRepShapeRef;

/*!
 * bhkSphereRepShape - A havok shape, perhaps with a bounding sphere for
 * quick rejection in addition to more detailed shape data?
 */

class NIFLIB_API bhkSphereRepShape : public BHK_SPHERE_REP_SHAPE_PARENT {
public:
	bhkSphereRepShape();
	~bhkSphereRepShape();
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
	BHK_SPHERE_REP_SHAPE_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
