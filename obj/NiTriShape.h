/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NITRISHAPE_H_
#define _NITRISHAPE_H_

#include "xml_extract.h"
#include NI_TRI_SHAPE_INCLUDE

/*
 * NiTriShape
 */

class NiTriShape;
typedef Ref<NiTriShape> NiTriShapeRef;

class NiTriShape : public NI_TRI_SHAPE_PARENT {
public:
	NiTriShape();
	~NiTriShape();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version );
private:
	NI_TRI_SHAPE_MEMBERS
};
#endif
