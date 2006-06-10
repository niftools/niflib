/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiMorphData.h"
#include "../gen/Morph.h"

//Definition of TYPE constant
const Type NiMorphData::TYPE("NiMorphData", &NI_MORPH_DATA_PARENT::TYPE );

NiMorphData::NiMorphData() NI_MORPH_DATA_CONSTRUCT {}

NiMorphData::~NiMorphData() {}

void NiMorphData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_MORPH_DATA_READ
}

void NiMorphData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_MORPH_DATA_WRITE
}

string NiMorphData::asString( bool verbose ) const {
	NI_MORPH_DATA_STRING
}

void NiMorphData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_MORPH_DATA_FIXLINKS
}

list<NiObjectRef> NiMorphData::GetRefs() const {
	NI_MORPH_DATA_GETREFS
}

const Type & NiMorphData::GetType() const {
	return TYPE;
};

int NiMorphData::GetVertexCount() const {
	
	return numVertices;
}

void NiMorphData::SetVertexCount( int n ) {
	numVertices = n;
	for ( uint i = 0; i < morphs.size(); ++i ) {
		morphs[i].vectors.resize( n );
	}
}

int NiMorphData::GetMorphCount() const {
	return int(morphs.size());
}

void NiMorphData::SetMorphCount( int n ) {
	uint old_size = uint(morphs.size());
	morphs.resize( n );

	//Make sure any new vertex groups are the right size
	for (uint i = old_size; i < morphs.size(); ++i ) {
		morphs[i].vectors.resize( numVertices );
	}
}

KeyType NiMorphData::GetMorphKeyType( int n ) const {
	return morphs[n].morphInterpolation;
}

void NiMorphData::SetMorphKeyType( int n, KeyType t ) {
	morphs[n].morphInterpolation = t;
}

vector< Key<float> > NiMorphData::GetMorphKeys( int n ) const {
	return morphs[n].morphKeys;
}

void NiMorphData::SetMorphKeys( int n, vector< Key<float> > const & keys ) {
	morphs[n].morphKeys = keys;
}

vector<Vector3> NiMorphData::GetMorphVerts( int n) const {
	return morphs[n].vectors;
}

void NiMorphData::SetMorphVerts( int n, const vector<Vector3> & in ) {
	// Make sure the size of the incoming vector equal vertCount
	if ( in.size() != numVertices )
		throw runtime_error("Input array size must equal Vertex Count.  Call SetVertexCount() to resize.");

	//It's the right size, so go ahead and set it
	morphs[n].vectors = in;
}
