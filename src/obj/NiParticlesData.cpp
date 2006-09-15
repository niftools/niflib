/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiParticlesData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiParticlesData::TYPE("NiParticlesData", &NI_PARTICLES_DATA_PARENT::TypeConst() );

NiParticlesData::NiParticlesData() NI_PARTICLES_DATA_CONSTRUCT {}

NiParticlesData::~NiParticlesData() {}

void NiParticlesData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_PARTICLES_DATA_READ
}

void NiParticlesData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_PARTICLES_DATA_WRITE
}

string NiParticlesData::asString( bool verbose ) const {
	NI_PARTICLES_DATA_STRING
}

void NiParticlesData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_PARTICLES_DATA_FIXLINKS
}

list<NiObjectRef> NiParticlesData::GetRefs() const {
	NI_PARTICLES_DATA_GETREFS
}

const Type & NiParticlesData::GetType() const {
	return TYPE;
};

