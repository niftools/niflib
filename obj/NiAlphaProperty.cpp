/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiAlphaProperty.h"
using namespace NifLib;

//Definition of TYPE constant
const Type NiAlphaProperty::TYPE("NiAlphaProperty", &NI_ALPHA_PROPERTY_PARENT::TypeConst() );

NiAlphaProperty::NiAlphaProperty() NI_ALPHA_PROPERTY_CONSTRUCT {}

NiAlphaProperty::~NiAlphaProperty() {}

void NiAlphaProperty::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_ALPHA_PROPERTY_READ
}

void NiAlphaProperty::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_ALPHA_PROPERTY_WRITE
}

string NiAlphaProperty::asString( bool verbose ) const {
	NI_ALPHA_PROPERTY_STRING
}

void NiAlphaProperty::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_ALPHA_PROPERTY_FIXLINKS
}

list<NiObjectRef> NiAlphaProperty::GetRefs() const {
	NI_ALPHA_PROPERTY_GETREFS
}

const Type & NiAlphaProperty::GetType() const {
	return TYPE;
};

ushort NiAlphaProperty::GetFlags() const {
	return flags;
}

void NiAlphaProperty::SetFlags( ushort n ) {
	flags = n;
}

byte NiAlphaProperty::GetAlphaTestThreshold() const {
	return threshold;
}

void NiAlphaProperty::SetAlphaTestThreshold( byte n ) {
	threshold = n;
}

#define NIFLIB_GET_FLAG(value, shift, mask) \
   (( value >> shift ) & mask)

#define NIFLIB_MASK_FLAG(flag, value, shift, mask) \
   ((flag ^ ~(mask << shift)) | ((value & mask) << shift))

NiAlphaProperty::BlendMode NiAlphaProperty::GetSourceBlendMode() const {
   return (NiAlphaProperty::BlendMode)NIFLIB_GET_FLAG(flags, 1, 0x0f);
}

void NiAlphaProperty::SetSourceBlendMode(BlendMode value) {
   flags = NIFLIB_MASK_FLAG(flags, value, 1, 0x0f);
}

NiAlphaProperty::BlendMode NiAlphaProperty::GetDestBlendMode() const {
   return (NiAlphaProperty::BlendMode)(( flags >> 5 ) & 0x0f);
}

void NiAlphaProperty::SetDestBlendMode(BlendMode value) {
   flags = NIFLIB_MASK_FLAG(flags, value, 5, 0x0f);
}

NiAlphaProperty::TestMode NiAlphaProperty::GetTestMode() const {
   return (NiAlphaProperty::TestMode)NIFLIB_GET_FLAG(flags, 10, 0x7);
}

void NiAlphaProperty::SetTestMode(TestMode value) {
   flags = NIFLIB_MASK_FLAG(flags, value, 10, 0x7);
}

bool NiAlphaProperty::GetAlphaBlend() const {
   return NIFLIB_GET_FLAG(flags, 0, 0x1) ? true : false;
}

void NiAlphaProperty::SetAlphaBlend(bool value) {
   flags = NIFLIB_MASK_FLAG(flags, value?1:0, 0, 0x1);
}

bool NiAlphaProperty::GetAlphaTest() const {
   return NIFLIB_GET_FLAG(flags, 9, 0x1) ? true : false;
}

void NiAlphaProperty::SetAlphaTest(bool value) {
   flags = NIFLIB_MASK_FLAG(flags, value?1:0, 9, 0x1);
}

bool NiAlphaProperty::GetAlphaSort() const {
   return NIFLIB_GET_FLAG(flags, 13, 0x1) ? false : true;
}
void NiAlphaProperty::SetAlphaSort(bool value) {
   flags = NIFLIB_MASK_FLAG(flags, value?0:1, 13, 0x1);
}
