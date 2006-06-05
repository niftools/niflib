/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiMaterialProperty.h"

//Definition of TYPE constant
const Type NiMaterialProperty::TYPE("NiMaterialProperty", &NI_MATERIAL_PROPERTY_PARENT::TYPE );

NiMaterialProperty::NiMaterialProperty() NI_MATERIAL_PROPERTY_CONSTRUCT {}

NiMaterialProperty::~NiMaterialProperty() {}

void NiMaterialProperty::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_MATERIAL_PROPERTY_READ
}

void NiMaterialProperty::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_MATERIAL_PROPERTY_WRITE
}

string NiMaterialProperty::asString( bool verbose ) const {
	NI_MATERIAL_PROPERTY_STRING
}

void NiMaterialProperty::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_MATERIAL_PROPERTY_FIXLINKS
}

list<NiObjectRef> NiMaterialProperty::GetRefs() const {
	NI_MATERIAL_PROPERTY_GETREFS
}

const Type & NiMaterialProperty::GetType() const {
	return TYPE;
};

