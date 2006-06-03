/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiRotatingParticlesData.h"

//Definition of TYPE constant
const Type NiRotatingParticlesData::TYPE("NiRotatingParticlesData", &NI_ROTATING_PARTICLES_DATA_PARENT::TYPE );

NiRotatingParticlesData::NiRotatingParticlesData() NI_ROTATING_PARTICLES_DATA_CONSTRUCT {}

NiRotatingParticlesData::~NiRotatingParticlesData() {}

void NiRotatingParticlesData::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_ROTATING_PARTICLES_DATA_READ
}

void NiRotatingParticlesData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_ROTATING_PARTICLES_DATA_WRITE
}

string NiRotatingParticlesData::asString( bool verbose ) const {
	NI_ROTATING_PARTICLES_DATA_STRING
}

void NiRotatingParticlesData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_ROTATING_PARTICLES_DATA_FIXLINKS
}

const Type & NiRotatingParticlesData::GetType() const {
	return TYPE;
};

