/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiKeyframeData.h"
#include "../gen/KeyGroup.h"
#include "../gen/KeyGroup.h"
#include "../gen/KeyGroup.h"

//Definition of TYPE constant
const Type NiKeyframeData::TYPE("NiKeyframeData", &NI_KEYFRAME_DATA_PARENT::TypeConst() );

NiKeyframeData::NiKeyframeData() NI_KEYFRAME_DATA_CONSTRUCT {}

NiKeyframeData::~NiKeyframeData() {}

void NiKeyframeData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_KEYFRAME_DATA_READ
}

void NiKeyframeData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_KEYFRAME_DATA_WRITE
}

string NiKeyframeData::asString( bool verbose ) const {
	NI_KEYFRAME_DATA_STRING
}

void NiKeyframeData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_KEYFRAME_DATA_FIXLINKS
}

list<NiObjectRef> NiKeyframeData::GetRefs() const {
	NI_KEYFRAME_DATA_GETREFS
}

const Type & NiKeyframeData::GetType() const {
	return TYPE;
};

KeyType NiKeyframeData::GetRotateType() const {
	return rotationType;
}

void NiKeyframeData::SetRotateType( KeyType t ) {
	rotationType = t;
}

vector< Key<Quaternion> > NiKeyframeData::GetQuatRotateKeys() const {
	return quaternionKeys;
}

void NiKeyframeData::SetQuatRotateKeys( const vector< Key<Quaternion> > & keys ) {
	quaternionKeys = keys;
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
