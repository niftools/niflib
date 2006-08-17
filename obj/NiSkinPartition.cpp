/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiSkinPartition.h"
#include "../gen/SkinPartition.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiSkinPartition::TYPE("NiSkinPartition", &NI_SKIN_PARTITION_PARENT::TypeConst() );

NiSkinPartition::NiSkinPartition() NI_SKIN_PARTITION_CONSTRUCT {}

NiSkinPartition::~NiSkinPartition() {}

void NiSkinPartition::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_SKIN_PARTITION_READ
}

void NiSkinPartition::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_SKIN_PARTITION_WRITE
}

string NiSkinPartition::asString( bool verbose ) const {
	NI_SKIN_PARTITION_STRING
}

void NiSkinPartition::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_SKIN_PARTITION_FIXLINKS
}

list<NiObjectRef> NiSkinPartition::GetRefs() const {
	NI_SKIN_PARTITION_GETREFS
}

const Type & NiSkinPartition::GetType() const {
	return TYPE;
};

int NiSkinPartition::GetNumPartitions() const {
   return (int)skinPartitionBlocks.size();
}

void NiSkinPartition::SetNumPartitions( int value ) {
   SkinPartition part;
   part.numVertices = 0;
   part.numTriangles = 0;
   part.numBones = 0;
   part.numStrips = 0;
   part.numWeightsPerVertex = 0;
   part.hasVertexMap = false;
   part.hasVertexWeights = false;
   part.hasStrips = false;
   part.hasBoneIndices = false;
   skinPartitionBlocks.assign(value, part);
   numSkinPartitionBlocks = value;
}

ushort NiSkinPartition::GetWeightsPerVertex( int partition ) const {
   return skinPartitionBlocks[partition].numWeightsPerVertex;
}

void NiSkinPartition::SetWeightsPerVertex( int partition, ushort value ) {
   skinPartitionBlocks[partition].numWeightsPerVertex = value;
}

ushort NiSkinPartition::GetNumVertices( int partition ) const {
   return skinPartitionBlocks[partition].numVertices;
}

void NiSkinPartition::SetNumVertices( int partition, ushort value ) {
   skinPartitionBlocks[partition].numVertices = value;
}

vector<ushort> NiSkinPartition::GetBoneMap( int partition ) const {
   return skinPartitionBlocks[partition].bones;
}

void NiSkinPartition::SetBoneMap( int partition, const vector<ushort>& boneMap ) {
   skinPartitionBlocks[partition].bones = boneMap;
   skinPartitionBlocks[partition].numBones = (ushort)boneMap.size();
}

vector<ushort> NiSkinPartition::GetVertexMap( int partition ) const {
   return skinPartitionBlocks[partition].vertexMap;
}

void NiSkinPartition::SetVertexMap( int partition, const vector<ushort>& vertexMap ) {
   SkinPartition& part = skinPartitionBlocks[partition];
   if (vertexMap.empty()) {
      part.vertexMap.clear();
      part.numVertices = 0;
      part.hasVertexMap = false;
   } else {
      part.vertexMap = vertexMap;
      part.numVertices = ushort(vertexMap.size());
      part.hasVertexMap = true;
   }
}

bool NiSkinPartition::HasVertexWeights( int partition ) const {
   return skinPartitionBlocks[partition].hasVertexWeights;
}

void NiSkinPartition::EnableVertexWeights( int partition, bool enable) {
   SkinPartition& part = skinPartitionBlocks[partition];
   if (enable) {
      // Allocate appropriately sized vectors. Clearing existing data.
      vector<float> weights(part.numWeightsPerVertex);
      skinPartitionBlocks[partition].vertexWeights.assign(part.numVertices, weights);
   } else {
      skinPartitionBlocks[partition].vertexWeights.clear();
   }
   skinPartitionBlocks[partition].hasVertexWeights = enable;
}

vector<float> NiSkinPartition::GetVertexWeights( int partition, int vertex ) const {
   return skinPartitionBlocks[partition].vertexWeights[vertex];
}

void NiSkinPartition::SetVertexWeights( int partition, int vertex, const vector<float> & n ) {
   skinPartitionBlocks[partition].vertexWeights[vertex] = n;
}

bool NiSkinPartition::HasVertexBoneIndices( int partition ) const {
   return skinPartitionBlocks[partition].hasBoneIndices;
}

void NiSkinPartition::EnableVertexBoneIndices( int partition, bool enable) {
   SkinPartition& part = skinPartitionBlocks[partition];
   if (enable) {
      // Allocate appropriately sized vectors. Clearing existing data.
      vector<byte> bones(part.numWeightsPerVertex);
      skinPartitionBlocks[partition].boneIndices.assign(part.numVertices, bones);
   } else {
      skinPartitionBlocks[partition].boneIndices.clear();
   }
   skinPartitionBlocks[partition].hasBoneIndices = enable;
}

vector<ushort> NiSkinPartition::GetVertexBoneIndices( int partition, int vertex ) const {
   const vector<byte>& bones = skinPartitionBlocks[partition].boneIndices[vertex];
   vector<ushort> value;
   size_t n = bones.size();
   value.resize(bones.size());
   for (size_t i=0; i<n; ++i)
      value[i] = ushort(bones[i]);
   return value;
}

void NiSkinPartition::SetVertexBoneIndices( int partition, int vertex, const vector<ushort>& boneList ) {
   vector<byte>& bones = skinPartitionBlocks[partition].boneIndices[vertex];
   size_t n = boneList.size();
   bones.resize(n);
   for (size_t i=0; i<n; ++i)
      bones[i] = byte(boneList[i]);
}

ushort NiSkinPartition::GetStripCount( int partition ) const {
   return (ushort)skinPartitionBlocks[partition].strips.size();
}

void NiSkinPartition::SetStripCount( int partition, int n ) {
   skinPartitionBlocks[partition].strips.resize(n);
   skinPartitionBlocks[partition].stripLengths.resize(n);
   skinPartitionBlocks[partition].hasStrips = (n!=0);
}

vector<ushort> NiSkinPartition::GetStrip( int partition, int index ) const {
   return skinPartitionBlocks[partition].strips[index];
}

void NiSkinPartition::SetStrip( int partition, int index, const vector<ushort> & in ) {
   SkinPartition& part = skinPartitionBlocks[partition];
   part.strips[index] = in;
   part.stripLengths[index] = ushort(in.size());

   int len = 0;
   for (vector<ushort>::iterator itr = part.stripLengths.begin(); itr != part.stripLengths.end(); ++itr) {
      len += ((*itr) - 2);
   }
   part.numTriangles = len;
   part.triangles.resize(len);
}

vector<Triangle> NiSkinPartition::GetTriangles( int partition ) const {
   return skinPartitionBlocks[partition].triangles;
}

void NiSkinPartition::SetTriangles( int partition, const vector<Triangle> & in ) {
   if ( in.size() > 65535 || in.size() < 0 ) {
      throw runtime_error("Invalid Triangle Count: must be between 0 and 65535.");
   }
   SkinPartition& part = skinPartitionBlocks[partition];
   part.triangles = in;
   part.hasStrips = (in.size() > 0) ? false : (part.strips.size() != 0);
   part.numTriangles = uint(in.size()) * 3;
}

