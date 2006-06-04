/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiParticlesData.h"

//Definition of TYPE constant
const Type NiParticlesData::TYPE("NiParticlesData", &NI_PARTICLES_DATA_PARENT::TYPE );

NiParticlesData::NiParticlesData() NI_PARTICLES_DATA_CONSTRUCT {}

NiParticlesData::~NiParticlesData() {}

void NiParticlesData::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_PARTICLES_DATA_READ
}

void NiParticlesData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_PARTICLES_DATA_WRITE
}

string NiParticlesData::asString( bool verbose ) const {
	NI_PARTICLES_DATA_STRING
}

void NiParticlesData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_PARTICLES_DATA_FIXLINKS
}

list<NiObjectRef> NiParticlesData::GetRefs() const {
	NI_PARTICLES_DATA_GETREFS
}

const Type & NiParticlesData::GetType() const {
	return TYPE;
};

