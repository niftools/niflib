/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKSPHERESHAPE_H_
#define _BHKSPHERESHAPE_H_

#include "bhkConvexShape.h"

#include "../gen/obj_defines.h"

class bhkSphereShape;
typedef Ref<bhkSphereShape> bhkSphereShapeRef;

/*!
 * bhkSphereShape - A sphere.
 */

class NIFLIB_API bhkSphereShape : public BHK_SPHERE_SHAPE_PARENT {
public:
	bhkSphereShape();
	~bhkSphereShape();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	BHK_SPHERE_SHAPE_MEMBERS
};

#endif
