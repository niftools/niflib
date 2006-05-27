/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NITRIBASEDGEOM_H_
#define _NITRIBASEDGEOM_H_

#include "xml_extract.h"
#include NI_TRI_BASED_GEOM_INCLUDE

/*
 * NiTriBasedGeom
 */

class NiTriBasedGeom;
typedef Ref<NiTriBasedGeom> NiTriBasedGeomRef;

class NiTriBasedGeom : public NI_TRI_BASED_GEOM_PARENT {
public:
	NiTriBasedGeom();
	~NiTriBasedGeom();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version );
private:
	NI_TRI_BASED_GEOM_MEMBERS
};
#endif
