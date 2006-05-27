/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKLISTSHAPE_H_
#define _BHKLISTSHAPE_H_

#include "xml_extract.h"
#include BHK_LIST_SHAPE_INCLUDE

/*
 * bhkListShape
 */

class bhkListShape;
typedef Ref<bhkListShape> bhkListShapeRef;

class bhkListShape : public BHK_LIST_SHAPE_PARENT {
public:
	bhkListShape();
	~bhkListShape();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version );
private:
	BHK_LIST_SHAPE_MEMBERS
};
#endif
