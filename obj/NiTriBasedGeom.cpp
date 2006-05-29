/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiTriBasedGeom.h"
#include "TriBasedGeomData.h"
#include "NiSkinInstance.h"

//Definition of TYPE constant
const Type NiTriBasedGeom::TYPE("NiTriBasedGeom", &NI_TRI_BASED_GEOM_PARENT::TYPE );

NiTriBasedGeom::NiTriBasedGeom() NI_TRI_BASED_GEOM_CONSTRUCT {}

NiTriBasedGeom::~NiTriBasedGeom() {}

void NiTriBasedGeom::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_TRI_BASED_GEOM_READ
}

void NiTriBasedGeom::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_TRI_BASED_GEOM_WRITE
}

string NiTriBasedGeom::asString( bool verbose ) const {
	NI_TRI_BASED_GEOM_STRING
}

void NiTriBasedGeom::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_TRI_BASED_GEOM_FIXLINKS
}

