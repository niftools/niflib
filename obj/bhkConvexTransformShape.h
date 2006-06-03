/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKCONVEXTRANSFORMSHAPE_H_
#define _BHKCONVEXTRANSFORMSHAPE_H_

#include "bhkTransformShape.h"

#include "gen/obj_defines.h"

/*
 * bhkConvexTransformShape
 */

class bhkConvexTransformShape;
typedef Ref<bhkConvexTransformShape> bhkConvexTransformShapeRef;

class bhkConvexTransformShape : public BHK_CONVEX_TRANSFORM_SHAPE_PARENT {
public:
	bhkConvexTransformShape();
	~bhkConvexTransformShape();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual const Type & GetType() const;
protected:
	BHK_CONVEX_TRANSFORM_SHAPE_MEMBERS
};

#endif
