/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiKeyframeData.h"
#include "../../include/gen/KeyGroup.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiKeyframeData::TYPE("NiKeyframeData", &NI_KEYFRAME_DATA_PARENT::TypeConst() );

NiKeyframeData::NiKeyframeData() NI_KEYFRAME_DATA_CONSTRUCT {}

NiKeyframeData::~NiKeyframeData() {}

void NiKeyframeData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiKeyframeData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiKeyframeData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiKeyframeData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiKeyframeData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiKeyframeData::GetType() const {
	return TYPE;
};

KeyType NiKeyframeData::GetRotateType() const {
	return rotationType;
}

void NiKeyframeData::SetRotateType( KeyType t ) {
	rotationType = t;
	UpdateRotationKeyCount();
}

vector< Key<Quaternion> > NiKeyframeData::GetQuatRotateKeys() const {
	return quaternionKeys;
}

void NiKeyframeData::UpdateRotationKeyCount() {
	if ( rotationType == XYZ_ROTATION_KEY ) {
		numRotationKeys = 1;
	} else {
		numRotationKeys = (unsigned int)(quaternionKeys.size());
	}
};

void NiKeyframeData::SetQuatRotateKeys( const vector< Key<Quaternion> > & keys ) {
	quaternionKeys = keys;
	UpdateRotationKeyCount();
}

KeyType NiKeyframeData::GetXRotateType() const {
	return xyzRotations[0].interpolation;
}

void NiKeyframeData::SetXRotateType( KeyType t ) {
	xyzRotations[0].interpolation = t;
}

vector< Key<float> > NiKeyframeData::GetXRotateKeys() const {
	return xyzRotations[0].keys;
}

void NiKeyframeData::SetXRotateKeys( const vector< Key<float> > & keys ) {
	xyzRotations[0].keys = keys;
}

KeyType NiKeyframeData::GetYRotateType() const {
	return xyzRotations[1].interpolation;
}

void NiKeyframeData::SetYRotateType( KeyType t ) {
	xyzRotations[1].interpolation = t;
}

vector< Key<float> > NiKeyframeData::GetYRotateKeys() const {
	return xyzRotations[1].keys;
}

void NiKeyframeData::SetYRotateKeys( const vector< Key<float> > & keys ) {
	xyzRotations[1].keys = keys;
}

KeyType NiKeyframeData::GetZRotateType() const {
	return xyzRotations[2].interpolation;
}

void NiKeyframeData::SetZRotateType( KeyType t ) {
	xyzRotations[2].interpolation = t;
}

vector< Key<float> > NiKeyframeData::GetZRotateKeys() const {
	return xyzRotations[2].keys;
}

void NiKeyframeData::SetZRotateKeys( const vector< Key<float> > & keys ) {
	xyzRotations[2].keys = keys;
}

KeyType NiKeyframeData::GetTranslateType() const {
	return translations.interpolation;
}

void NiKeyframeData::SetTranslateType( KeyType t ) {
	translations.interpolation = t;
}

vector< Key<Vector3> > NiKeyframeData::GetTranslateKeys() const {
	return translations.keys;
}

void NiKeyframeData::SetTranslateKeys( vector< Key<Vector3> > const & keys ) {
	translations.keys = keys;
}

KeyType NiKeyframeData::GetScaleType() const {
	return scales.interpolation;
}

void NiKeyframeData::SetScaleType( KeyType t ) {
	scales.interpolation = t;
}

vector< Key<float> > NiKeyframeData::GetScaleKeys() const { 
	return scales.keys;
}

void NiKeyframeData::SetScaleKeys( vector< Key<float> > const & keys ) {
	scales.keys = keys;
}

const Type & NiKeyframeData::TypeConst() {
	return TYPE;
}
