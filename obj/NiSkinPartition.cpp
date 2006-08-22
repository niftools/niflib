/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiSkinPartition.h"
#include "../gen/SkinPartition.h"
#include "NiSkinInstance.h"
#include "NiSkinData.h"
#include "NiTriBasedGeom.h"
#include "NiTriBasedGeomData.h"
#include "NiTriStripsData.h"
#include "../gen/SkinWeight.h"
#include "../NvTriStrip/NvTriStrip.h"
using namespace Niflib;

typedef vector<SkinWeight> SkinWeightList;
typedef vector<SkinWeightList> BoneWeightList;
typedef vector<float> WeightList;
typedef vector<ushort> BoneList;
typedef vector<ushort> Strip;
typedef vector<Strip> Strips;
typedef vector<Triangle> Triangles;

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
   SkinPartition& part = skinPartitionBlocks[partition];
   part.strips.resize(n);
   part.stripLengths.resize(n);
   part.hasStrips = (n!=0);
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

NiSkinPartition::NiSkinPartition(Ref<NiTriBasedGeom> shape) {
   NiSkinInstanceRef skinInst = shape->GetSkinInstance();
   if ( skinInst == NULL ) {
      throw runtime_error( "You must bind a skin before setting generating skin partitions.  No NiSkinInstance found." );
   }
   NiSkinDataRef skinData = skinInst->GetSkinData();
   if ( skinData == NULL ) {
      throw runtime_error( "You must bind a skin before setting generating skin partitions.  No NiSkinData found." );
   }
   NiTriBasedGeomDataRef geomData = shape->GetData();
   if ( geomData == NULL ) {
      throw runtime_error( "Attempted to generate a skin partition on a mesh with no geometry data." );
   }

   int nWeightsPerVertex = 0;
   vector<WeightList> vertexWeights;
   BoneList boneMap;
   vector<ushort> vertexMap;
   Strips strips;
   vector<BoneList> boneIndexList;
   Triangles triangles;

   int totalBones = skinInst->GetBoneCount();
   boneMap.resize(totalBones);

   int nv = geomData->GetVertexCount();
   vertexMap.resize(nv);
   vertexWeights.resize(nv);
   boneIndexList.resize(nv);

   for (int i=0; i<totalBones; ++i) {
      boneMap[i] = i;

      vector<SkinWeight> skinWeights = skinData->GetBoneWeights(i);
      for (vector<SkinWeight>::const_iterator skinWeight = skinWeights.begin(); skinWeight != skinWeights.end(); ++skinWeight) {
         WeightList& vertexWeight = vertexWeights[skinWeight->index];
         BoneList& boneIndex = boneIndexList[skinWeight->index];

         vertexWeight.push_back(skinWeight->weight);
         boneIndex.push_back(i);

         // Adjust upper limit on number of weights per vertex if necessary.
         int nWeights = vertexWeight.size();
         if (nWeights > nWeightsPerVertex)
            nWeightsPerVertex = nWeights;
      }
   }
   if (nWeightsPerVertex == 0) {
      throw runtime_error( "Attempted to generate a skin partition on a mesh with no weights specified." );
   }
   for (int i=0; i<nv; ++i) {
      vertexMap[i] = i;

      WeightList& vertexWeight = vertexWeights[i];
      BoneList& boneIndex = boneIndexList[i];
      vertexWeight.reserve(nWeightsPerVertex);
      boneIndex.reserve(nWeightsPerVertex);
      for (int j = nWeightsPerVertex - vertexWeight.size(); j>0; --j) {
         vertexWeight.push_back(0.0f);
         boneIndex.push_back(0);
      }
   }

   SetNumPartitions(1);
   SetWeightsPerVertex(0, nWeightsPerVertex);
   SetBoneMap(0, boneMap);
   SetNumVertices(0, ushort(vertexMap.size()) );
   SetVertexMap(0, vertexMap);
   EnableVertexWeights(0, true);
   EnableVertexBoneIndices(0, true);
   for (int i=0; i<nv; ++i) {
      SetVertexWeights(0, i, vertexWeights[i]);
      SetVertexBoneIndices(0, i, boneIndexList[i]);
   }

   // Special case for pre-stripped data
   if (NiTriStripsDataRef stripData = DynamicCast<NiTriStripsData>(geomData)) {
      ushort nstrips = stripData->GetStripCount();
      SetStripCount(0, nstrips);
      for (int i=0; i<int(nstrips); ++i) {
         SetStrip(0, i, stripData->GetStrip(i));
      }
   } else {

      SetTriangles(0, geomData->GetTriangles());

      unsigned short *data = new unsigned short[triangles.size() * 3 * 2];
      for (size_t i=0; i< triangles.size(); i++) {
         data[i * 3 + 0] = triangles[i][0];
         data[i * 3 + 1] = triangles[i][1];
         data[i * 3 + 2] = triangles[i][2];
      }
      PrimitiveGroup * groups = 0;
      unsigned short numGroups = 0;

      // GF 3+
      SetCacheSize(CACHESIZE_GEFORCE3);
      // don't generate hundreds of strips
      SetStitchStrips(true);
      GenerateStrips(data, triangles.size()*3, &groups, &numGroups);

      delete [] data;

      if (groups) {
         SetStripCount(0, numGroups);
         for (int g=0; g<numGroups; g++) {
            if (groups[g].type == PT_STRIP) {
               vector<Niflib::ushort> strip(groups[g].numIndices);
               for (size_t s=0; s<groups[g].numIndices; s++)
                  strip[s] = groups[g].indices[s];
               SetStrip(0, g, strip);
            }
         }
         delete [] groups;
      }
   }
  
}