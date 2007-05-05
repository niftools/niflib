/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiMorphData.h"
#include "../../include/gen/Morph.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiMorphData::TYPE("NiMorphData", &NI_MORPH_DATA_PARENT::TYPE );

NiMorphData::NiMorphData() NI_MORPH_DATA_CONSTRUCT {}

NiMorphData::~NiMorphData() {}

void NiMorphData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiMorphData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiMorphData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiMorphData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiMorphData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiMorphData::GetType() const {
	return TYPE;
};

int NiMorphData::GetVertexCount() const {
	
	return numVertices;
}

void NiMorphData::SetVertexCount( int n ) {
	numVertices = n;
	for ( unsigned int i = 0; i < morphs.size(); ++i ) {
		morphs[i].vectors.resize( n );
	}
}

int NiMorphData::GetMorphCount() const {
	return int(morphs.size());
}

void NiMorphData::SetMorphCount( int n ) {
	unsigned int old_size = (unsigned int)(morphs.size());
	morphs.resize( n );

	//Make sure any new vertex groups are the right size
	for (unsigned int i = old_size; i < morphs.size(); ++i ) {
		morphs[i].vectors.resize( numVertices );
	}
}

KeyType NiMorphData::GetMorphKeyType( int n ) const {
	return morphs[n].interpolation;
}

void NiMorphData::SetMorphKeyType( int n, KeyType t ) {
	morphs[n].interpolation = t;
}

vector< Key<float> > NiMorphData::GetMorphKeys( int n ) const {
	return morphs[n].keys;
}

void NiMorphData::SetMorphKeys( int n, vector< Key<float> > const & keys ) {
	morphs[n].keys = keys;
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
