/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiAutoNormalParticlesData.h"

//Definition of TYPE constant
const Type NiAutoNormalParticlesData::TYPE("NiAutoNormalParticlesData", &NI_AUTO_NORMAL_PARTICLES_DATA_PARENT::TYPE );

NiAutoNormalParticlesData::NiAutoNormalParticlesData() NI_AUTO_NORMAL_PARTICLES_DATA_CONSTRUCT {}

NiAutoNormalParticlesData::~NiAutoNormalParticlesData() {}

void NiAutoNormalParticlesData::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  NI_AUTO_NORMAL_PARTICLES_DATA_READ
}

void NiAutoNormalParticlesData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  NI_AUTO_NORMAL_PARTICLES_DATA_WRITE
}

string NiAutoNormalParticlesData::asString( bool verbose ) const {
  NI_AUTO_NORMAL_PARTICLES_DATA_STRING
}

void NiAutoNormalParticlesData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  NI_AUTO_NORMAL_PARTICLES_DATA_FIXLINKS
}

const Type & NiAutoNormalParticlesData::GetType() const {
  return TYPE;
};

