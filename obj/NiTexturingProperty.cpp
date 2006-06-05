/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiTexturingProperty.h"
#include "../gen/TexDesc.h"
#include "NiSourceTexture.h"
#include "../gen/TexDesc.h"
#include "NiSourceTexture.h"
#include "../gen/TexDesc.h"
#include "NiSourceTexture.h"
#include "../gen/TexDesc.h"
#include "NiSourceTexture.h"
#include "../gen/TexDesc.h"
#include "NiSourceTexture.h"
#include "../gen/TexDesc.h"
#include "NiSourceTexture.h"
#include "../gen/TexDesc.h"
#include "NiSourceTexture.h"
#include "../gen/TexDesc.h"
#include "NiSourceTexture.h"
#include "../gen/ShaderTexDesc.h"
#include "../gen/TexDesc.h"
#include "NiSourceTexture.h"

//Definition of TYPE constant
const Type NiTexturingProperty::TYPE("NiTexturingProperty", &NI_TEXTURING_PROPERTY_PARENT::TYPE );

NiTexturingProperty::NiTexturingProperty() NI_TEXTURING_PROPERTY_CONSTRUCT {}

NiTexturingProperty::~NiTexturingProperty() {}

void NiTexturingProperty::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_TEXTURING_PROPERTY_READ
}

void NiTexturingProperty::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_TEXTURING_PROPERTY_WRITE
}

string NiTexturingProperty::asString( bool verbose ) const {
	NI_TEXTURING_PROPERTY_STRING
}

void NiTexturingProperty::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_TEXTURING_PROPERTY_FIXLINKS
}

list<NiObjectRef> NiTexturingProperty::GetRefs() const {
	NI_TEXTURING_PROPERTY_GETREFS
}

const Type & NiTexturingProperty::GetType() const {
	return TYPE;
};

