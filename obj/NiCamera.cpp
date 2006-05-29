/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiCamera.h"

//Definition of TYPE constant
const Type NiCamera::TYPE("NiCamera", &NI_CAMERA_PARENT::TYPE );

NiCamera::NiCamera() NI_CAMERA_CONSTRUCT {}

NiCamera::~NiCamera() {}

void NiCamera::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_CAMERA_READ
}

void NiCamera::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_CAMERA_WRITE
}

string NiCamera::asString( bool verbose ) const {
	NI_CAMERA_STRING
}

void NiCamera::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_CAMERA_FIXLINKS
}

