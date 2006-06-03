/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/NiBlendBoolInterpolator.h"

//Definition of TYPE constant
const Type NiBlendBoolInterpolator::TYPE("NiBlendBoolInterpolator", &NI_BLEND_BOOL_INTERPOLATOR_PARENT::TYPE );

NiBlendBoolInterpolator::NiBlendBoolInterpolator() NI_BLEND_BOOL_INTERPOLATOR_CONSTRUCT {}

NiBlendBoolInterpolator::~NiBlendBoolInterpolator() {}

void NiBlendBoolInterpolator::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  NI_BLEND_BOOL_INTERPOLATOR_READ
}

void NiBlendBoolInterpolator::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  NI_BLEND_BOOL_INTERPOLATOR_WRITE
}

string NiBlendBoolInterpolator::asString( bool verbose ) const {
  NI_BLEND_BOOL_INTERPOLATOR_STRING
}

void NiBlendBoolInterpolator::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  NI_BLEND_BOOL_INTERPOLATOR_FIXLINKS
}

const Type & NiBlendBoolInterpolator::GetType() const {
  return TYPE;
};

