/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiAlphaProperty.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiAlphaProperty::TYPE("NiAlphaProperty", &NI_ALPHA_PROPERTY_PARENT::TypeConst() );

NiAlphaProperty::NiAlphaProperty() NI_ALPHA_PROPERTY_CONSTRUCT {}

NiAlphaProperty::~NiAlphaProperty() {}

void NiAlphaProperty::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiAlphaProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiAlphaProperty::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiAlphaProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiAlphaProperty::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiAlphaProperty::GetType() const {
	return TYPE;
};

unsigned short NiAlphaProperty::GetFlags() const {
	return flags;
}

void NiAlphaProperty::SetFlags( unsigned short n ) {
	flags = n;
}

byte NiAlphaProperty::GetTestThreshold() const {
	return threshold;
}

void NiAlphaProperty::SetTestThreshold( byte n ) {
	threshold = n;
}

#define NIFLIB_GET_FLAG(value, shift, mask) \
   (( value >> shift ) & mask)

#define NIFLIB_MASK_FLAG(flag, value, shift, mask) \
   ((flag & ~(mask << shift)) | ((value & mask) << shift))

NiAlphaProperty::BlendFunc NiAlphaProperty::GetSourceBlendFunc() const {
   return (NiAlphaProperty::BlendFunc)NIFLIB_GET_FLAG(flags, 1, 0x0f);
}

void NiAlphaProperty::SetSourceBlendFunc(BlendFunc value) {
   flags = NIFLIB_MASK_FLAG(flags, value, 1, 0x0f);
}

NiAlphaProperty::BlendFunc NiAlphaProperty::GetDestBlendFunc() const {
   return (NiAlphaProperty::BlendFunc)(( flags >> 5 ) & 0x0f);
}

void NiAlphaProperty::SetDestBlendFunc(BlendFunc value) {
   flags = NIFLIB_MASK_FLAG(flags, value, 5, 0x0f);
}

NiAlphaProperty::TestFunc NiAlphaProperty::GetTestFunc() const {
   return (NiAlphaProperty::TestFunc)NIFLIB_GET_FLAG(flags, 10, 0x7);
}

void NiAlphaProperty::SetTestFunc(TestFunc value) {
   flags = NIFLIB_MASK_FLAG(flags, value, 10, 0x7);
}

bool NiAlphaProperty::GetBlendState() const {
   return NIFLIB_GET_FLAG(flags, 0, 0x1) ? true : false;
}

void NiAlphaProperty::SetBlendState(bool value) {
   flags = NIFLIB_MASK_FLAG(flags, value?1:0, 0, 0x1);
}

bool NiAlphaProperty::GetTestState() const {
   return NIFLIB_GET_FLAG(flags, 9, 0x1) ? true : false;
}

void NiAlphaProperty::SetTestState(bool value) {
   flags = NIFLIB_MASK_FLAG(flags, value?1:0, 9, 0x1);
}

bool NiAlphaProperty::GetTriangleSortMode() const {
   return NIFLIB_GET_FLAG(flags, 13, 0x1) ? false : true;
}
void NiAlphaProperty::SetTriangleSortMode(bool value) {
   flags = NIFLIB_MASK_FLAG(flags, value?0:1, 13, 0x1);
}

const Type & NiAlphaProperty::TypeConst() {
	return TYPE;
}
