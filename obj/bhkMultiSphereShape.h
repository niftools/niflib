/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKMULTISPHERESHAPE_H_
#define _BHKMULTISPHERESHAPE_H_

#include "bhkSphereRepShape.h"

#include "gen/obj_defines.h"

class bhkMultiSphereShape;
typedef Ref<bhkMultiSphereShape> bhkMultiSphereShapeRef;

/*!
 * bhkMultiSphereShape - Unknown.
 */

class bhkMultiSphereShape : public BHK_MULTI_SPHERE_SHAPE_PARENT {
public:
	bhkMultiSphereShape();
	~bhkMultiSphereShape();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	BHK_MULTI_SPHERE_SHAPE_MEMBERS
};

#endif
