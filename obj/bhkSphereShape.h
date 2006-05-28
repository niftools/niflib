/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKSPHERESHAPE_H_
#define _BHKSPHERESHAPE_H_

#include "xml_extract.h"
#include BHK_SPHERE_SHAPE_INCLUDE

/*
 * bhkSphereShape
 */

class bhkSphereShape;
typedef Ref<bhkSphereShape> bhkSphereShapeRef;

class bhkSphereShape : public BHK_SPHERE_SHAPE_PARENT {
public:
	bhkSphereShape();
	~bhkSphereShape();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version );
private:
	BHK_SPHERE_SHAPE_MEMBERS
};
#endif