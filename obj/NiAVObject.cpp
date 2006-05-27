/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiAVObject.h"
#include "NiProperty.h"
#include "NiCollisionData.h"

//Definition of TYPE constant
const Type NiAVObject::TYPE("NiAVObject", &NI_A_V_OBJECT_PARENT::TYPE );

NiAVObject::NiAVObject() NI_A_V_OBJECT_CONSTRUCT {}

NiAVObject::~NiAVObject() {}

void NiAVObject::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	NI_A_V_OBJECT_READ
}

void NiAVObject::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_A_V_OBJECT_WRITE
}

string NiAVObject::asString( bool verbose ) const {
	NI_A_V_OBJECT_STRING
}

void NiAVObject::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	NI_A_V_OBJECT_FIXLINKS
}