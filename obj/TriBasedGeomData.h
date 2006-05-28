/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _TRIBASEDGEOMDATA_H_
#define _TRIBASEDGEOMDATA_H_

#include "xml_extract.h"
#include TRI_BASED_GEOM_DATA_INCLUDE

/*
 * TriBasedGeomData
 */

class TriBasedGeomData;
typedef Ref<TriBasedGeomData> TriBasedGeomDataRef;

class TriBasedGeomData : public TRI_BASED_GEOM_DATA_PARENT {
public:
	TriBasedGeomData();
	~TriBasedGeomData();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version );
	
	Vector3 Center() const;
	float Radius() const;
protected:
	TRI_BASED_GEOM_DATA_MEMBERS
};
#endif
