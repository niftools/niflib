/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiTextureEffect.h"
#include "NiSourceTexture.h"
using namespace NifLib;

//Definition of TYPE constant
const Type NiTextureEffect::TYPE("NiTextureEffect", &NI_TEXTURE_EFFECT_PARENT::TypeConst() );

NiTextureEffect::NiTextureEffect() NI_TEXTURE_EFFECT_CONSTRUCT {}

NiTextureEffect::~NiTextureEffect() {}

void NiTextureEffect::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_TEXTURE_EFFECT_READ
}

void NiTextureEffect::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_TEXTURE_EFFECT_WRITE
}

string NiTextureEffect::asString( bool verbose ) const {
	NI_TEXTURE_EFFECT_STRING
}

void NiTextureEffect::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_TEXTURE_EFFECT_FIXLINKS
}

list<NiObjectRef> NiTextureEffect::GetRefs() const {
	NI_TEXTURE_EFFECT_GETREFS
}

const Type & NiTextureEffect::GetType() const {
	return TYPE;
};

