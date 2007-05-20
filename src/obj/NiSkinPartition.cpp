/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

//--BEGIN FILE HEAD CUSTOM CODE--//
#include "../../include/obj/NiSkinPartition.h"
#include "../../include/gen/SkinPartition.h"
#include "../../include/obj/NiSkinInstance.h"
#include "../../include/obj/NiSkinData.h"
#include "../../include/obj/NiTriBasedGeom.h"
#include "../../include/obj/NiTriBasedGeomData.h"
#include "../../include/obj/NiTriStripsData.h"
#include "../../include/gen/SkinWeight.h"
#include "../../NvTriStrip/NvTriStrip.h"

using namespace NvTriStrip;
using namespace Niflib;

#include <vector>
#include <utility>
#include <algorithm>

typedef std::vector<float> WeightList;
typedef std::vector<unsigned short> BoneList;
typedef std::vector<unsigned short> Strip;
typedef std::vector<Strip> Strips;
typedef std::vector<Triangle> Triangles;

typedef std::pair<int,float> BoneWeight;
typedef std::vector<BoneWeight> BoneWeightList;
typedef SkinPartition Partition;
typedef vector<SkinPartition> PartitionList;

//--END CUSTOM CODE--//

#include "../../include/FixLink.h"
#include "../../include/NIF_IO.h"
#include "../../include/obj/NiSkinPartition.h"
#include "../../include/gen/SkinPartition.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiSkinPartition::TYPE("NiSkinPartition", &NiObject::TYPE );

NiSkinPartition::NiSkinPartition() : numSkinPartitionBlocks((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiSkinPartition::~NiSkinPartition() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiSkinPartition::GetType() const {
	return TYPE;
}

namespace Niflib {
	typedef NiObject*(*obj_factory_func)();
	extern map<string, obj_factory_func> global_object_map;

	//Initialization function
	static bool Initialization();

	//A static bool to force the initialization to happen pre-main
	static bool obj_initialized = Initialization();

	static bool Initialization() {
		//Add the function to the global object map
		global_object_map["NiSkinPartition"] = NiSkinPartition::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiSkinPartition::Create() {
	return new NiSkinPartition;
}

void NiSkinPartition::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::Read( in, link_stack, info );
	NifStream( numSkinPartitionBlocks, in, info );
	skinPartitionBlocks.resize(numSkinPartitionBlocks);
	for (unsigned int i1 = 0; i1 < skinPartitionBlocks.size(); i1++) {
		NifStream( skinPartitionBlocks[i1].numVertices, in, info );
		NifStream( skinPartitionBlocks[i1].numTriangles, in, info );
		NifStream( skinPartitionBlocks[i1].numBones, in, info );
		NifStream( skinPartitionBlocks[i1].numStrips, in, info );
		NifStream( skinPartitionBlocks[i1].numWeightsPerVertex, in, info );
		skinPartitionBlocks[i1].bones.resize(skinPartitionBlocks[i1].numBones);
		for (unsigned int i2 = 0; i2 < skinPartitionBlocks[i1].bones.size(); i2++) {
			NifStream( skinPartitionBlocks[i1].bones[i2], in, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( skinPartitionBlocks[i1].hasVertexMap, in, info );
		};
		if ( info.version <= 0x0A000102 ) {
			skinPartitionBlocks[i1].vertexMap.resize(skinPartitionBlocks[i1].numVertices);
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].vertexMap.size(); i3++) {
				NifStream( skinPartitionBlocks[i1].vertexMap[i3], in, info );
			};
		};
		if ( info.version >= 0x0A010000 ) {
			if ( (skinPartitionBlocks[i1].hasVertexMap != 0) ) {
				skinPartitionBlocks[i1].vertexMap.resize(skinPartitionBlocks[i1].numVertices);
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i1].vertexMap.size(); i4++) {
					NifStream( skinPartitionBlocks[i1].vertexMap[i4], in, info );
				};
			};
			NifStream( skinPartitionBlocks[i1].hasVertexWeights, in, info );
		};
		if ( info.version <= 0x0A000102 ) {
			skinPartitionBlocks[i1].vertexWeights.resize(skinPartitionBlocks[i1].numVertices);
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].vertexWeights.size(); i3++) {
				skinPartitionBlocks[i1].vertexWeights[i3].resize(skinPartitionBlocks[i1].numWeightsPerVertex);
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i1].vertexWeights[i3].size(); i4++) {
					NifStream( skinPartitionBlocks[i1].vertexWeights[i3][i4], in, info );
				};
			};
		};
		if ( info.version >= 0x0A010000 ) {
			if ( (skinPartitionBlocks[i1].hasVertexWeights != 0) ) {
				skinPartitionBlocks[i1].vertexWeights.resize(skinPartitionBlocks[i1].numVertices);
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i1].vertexWeights.size(); i4++) {
					skinPartitionBlocks[i1].vertexWeights[i4].resize(skinPartitionBlocks[i1].numWeightsPerVertex);
					for (unsigned int i5 = 0; i5 < skinPartitionBlocks[i1].vertexWeights[i4].size(); i5++) {
						NifStream( skinPartitionBlocks[i1].vertexWeights[i4][i5], in, info );
					};
				};
			};
		};
		skinPartitionBlocks[i1].stripLengths.resize(skinPartitionBlocks[i1].numStrips);
		for (unsigned int i2 = 0; i2 < skinPartitionBlocks[i1].stripLengths.size(); i2++) {
			NifStream( skinPartitionBlocks[i1].stripLengths[i2], in, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( skinPartitionBlocks[i1].hasStrips, in, info );
		};
		if ( info.version <= 0x0A000102 ) {
			skinPartitionBlocks[i1].strips.resize(skinPartitionBlocks[i1].numStrips);
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].strips.size(); i3++) {
				skinPartitionBlocks[i1].strips[i3].resize(skinPartitionBlocks[i1].stripLengths[i3]);
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i1].stripLengths[i3]; i4++) {
					NifStream( skinPartitionBlocks[i1].strips[i3][i4], in, info );
				};
			};
		};
		if ( info.version >= 0x0A010000 ) {
			if ( (skinPartitionBlocks[i1].hasStrips != 0) ) {
				skinPartitionBlocks[i1].strips.resize(skinPartitionBlocks[i1].numStrips);
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i1].strips.size(); i4++) {
					skinPartitionBlocks[i1].strips[i4].resize(skinPartitionBlocks[i1].stripLengths[i4]);
					for (unsigned int i5 = 0; i5 < skinPartitionBlocks[i1].stripLengths[i4]; i5++) {
						NifStream( skinPartitionBlocks[i1].strips[i4][i5], in, info );
					};
				};
			};
		};
		if ( (skinPartitionBlocks[i1].numStrips == 0) ) {
			skinPartitionBlocks[i1].triangles.resize(skinPartitionBlocks[i1].numTriangles);
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].triangles.size(); i3++) {
				NifStream( skinPartitionBlocks[i1].triangles[i3], in, info );
			};
		};
		NifStream( skinPartitionBlocks[i1].hasBoneIndices, in, info );
		if ( (skinPartitionBlocks[i1].hasBoneIndices != 0) ) {
			skinPartitionBlocks[i1].boneIndices.resize(skinPartitionBlocks[i1].numVertices);
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].boneIndices.size(); i3++) {
				skinPartitionBlocks[i1].boneIndices[i3].resize(skinPartitionBlocks[i1].numWeightsPerVertex);
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i1].boneIndices[i3].size(); i4++) {
					NifStream( skinPartitionBlocks[i1].boneIndices[i3][i4], in, info );
				};
			};
		};
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiSkinPartition::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, info );
	numSkinPartitionBlocks = (unsigned int)(skinPartitionBlocks.size());
	NifStream( numSkinPartitionBlocks, out, info );
	for (unsigned int i1 = 0; i1 < skinPartitionBlocks.size(); i1++) {
		for (unsigned int i2 = 0; i2 < skinPartitionBlocks[i1].strips.size(); i2++)
			skinPartitionBlocks[i1].stripLengths[i2] = (unsigned short)(skinPartitionBlocks[i1].strips[i2].size());
		skinPartitionBlocks[i1].numWeightsPerVertex = (unsigned short)((skinPartitionBlocks[i1].vertexWeights.size() > 0) ? skinPartitionBlocks[i1].vertexWeights[0].size() : 0);
		skinPartitionBlocks[i1].numStrips = (unsigned short)(skinPartitionBlocks[i1].stripLengths.size());
		skinPartitionBlocks[i1].numBones = (unsigned short)(skinPartitionBlocks[i1].bones.size());
		skinPartitionBlocks[i1].numTriangles = (unsigned short)(skinPartitionBlocks[i1].triangles.size());
		skinPartitionBlocks[i1].numVertices = (unsigned short)(skinPartitionBlocks[i1].vertexMap.size());
		NifStream( skinPartitionBlocks[i1].numVertices, out, info );
		NifStream( skinPartitionBlocks[i1].numTriangles, out, info );
		NifStream( skinPartitionBlocks[i1].numBones, out, info );
		NifStream( skinPartitionBlocks[i1].numStrips, out, info );
		NifStream( skinPartitionBlocks[i1].numWeightsPerVertex, out, info );
		for (unsigned int i2 = 0; i2 < skinPartitionBlocks[i1].bones.size(); i2++) {
			NifStream( skinPartitionBlocks[i1].bones[i2], out, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( skinPartitionBlocks[i1].hasVertexMap, out, info );
		};
		if ( info.version <= 0x0A000102 ) {
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].vertexMap.size(); i3++) {
				NifStream( skinPartitionBlocks[i1].vertexMap[i3], out, info );
			};
		};
		if ( info.version >= 0x0A010000 ) {
			if ( (skinPartitionBlocks[i1].hasVertexMap != 0) ) {
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i1].vertexMap.size(); i4++) {
					NifStream( skinPartitionBlocks[i1].vertexMap[i4], out, info );
				};
			};
			NifStream( skinPartitionBlocks[i1].hasVertexWeights, out, info );
		};
		if ( info.version <= 0x0A000102 ) {
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].vertexWeights.size(); i3++) {
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i1].vertexWeights[i3].size(); i4++) {
					NifStream( skinPartitionBlocks[i1].vertexWeights[i3][i4], out, info );
				};
			};
		};
		if ( info.version >= 0x0A010000 ) {
			if ( (skinPartitionBlocks[i1].hasVertexWeights != 0) ) {
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i1].vertexWeights.size(); i4++) {
					for (unsigned int i5 = 0; i5 < skinPartitionBlocks[i1].vertexWeights[i4].size(); i5++) {
						NifStream( skinPartitionBlocks[i1].vertexWeights[i4][i5], out, info );
					};
				};
			};
		};
		for (unsigned int i2 = 0; i2 < skinPartitionBlocks[i1].stripLengths.size(); i2++) {
			NifStream( skinPartitionBlocks[i1].stripLengths[i2], out, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( skinPartitionBlocks[i1].hasStrips, out, info );
		};
		if ( info.version <= 0x0A000102 ) {
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].strips.size(); i3++) {
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i1].stripLengths[i3]; i4++) {
					NifStream( skinPartitionBlocks[i1].strips[i3][i4], out, info );
				};
			};
		};
		if ( info.version >= 0x0A010000 ) {
			if ( (skinPartitionBlocks[i1].hasStrips != 0) ) {
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i1].strips.size(); i4++) {
					for (unsigned int i5 = 0; i5 < skinPartitionBlocks[i1].stripLengths[i4]; i5++) {
						NifStream( skinPartitionBlocks[i1].strips[i4][i5], out, info );
					};
				};
			};
		};
		if ( (skinPartitionBlocks[i1].numStrips == 0) ) {
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].triangles.size(); i3++) {
				NifStream( skinPartitionBlocks[i1].triangles[i3], out, info );
			};
		};
		NifStream( skinPartitionBlocks[i1].hasBoneIndices, out, info );
		if ( (skinPartitionBlocks[i1].hasBoneIndices != 0) ) {
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].boneIndices.size(); i3++) {
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i1].boneIndices[i3].size(); i4++) {
					NifStream( skinPartitionBlocks[i1].boneIndices[i3][i4], out, info );
				};
			};
		};
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiSkinPartition::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	numSkinPartitionBlocks = (unsigned int)(skinPartitionBlocks.size());
	out << "  Num Skin Partition Blocks:  " << numSkinPartitionBlocks << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < skinPartitionBlocks.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (unsigned int i2 = 0; i2 < skinPartitionBlocks[i1].strips.size(); i2++)
			skinPartitionBlocks[i1].stripLengths[i2] = (unsigned short)(skinPartitionBlocks[i1].strips[i2].size());
		skinPartitionBlocks[i1].numWeightsPerVertex = (unsigned short)((skinPartitionBlocks[i1].vertexWeights.size() > 0) ? skinPartitionBlocks[i1].vertexWeights[0].size() : 0);
		skinPartitionBlocks[i1].numStrips = (unsigned short)(skinPartitionBlocks[i1].stripLengths.size());
		skinPartitionBlocks[i1].numBones = (unsigned short)(skinPartitionBlocks[i1].bones.size());
		skinPartitionBlocks[i1].numTriangles = (unsigned short)(skinPartitionBlocks[i1].triangles.size());
		skinPartitionBlocks[i1].numVertices = (unsigned short)(skinPartitionBlocks[i1].vertexMap.size());
		out << "    Num Vertices:  " << skinPartitionBlocks[i1].numVertices << endl;
		out << "    Num Triangles:  " << skinPartitionBlocks[i1].numTriangles << endl;
		out << "    Num Bones:  " << skinPartitionBlocks[i1].numBones << endl;
		out << "    Num Strips:  " << skinPartitionBlocks[i1].numStrips << endl;
		out << "    Num Weights Per Vertex:  " << skinPartitionBlocks[i1].numWeightsPerVertex << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < skinPartitionBlocks[i1].bones.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Bones[" << i2 << "]:  " << skinPartitionBlocks[i1].bones[i2] << endl;
			array_output_count++;
		};
		out << "    Has Vertex Map:  " << skinPartitionBlocks[i1].hasVertexMap << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < skinPartitionBlocks[i1].vertexMap.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Vertex Map[" << i2 << "]:  " << skinPartitionBlocks[i1].vertexMap[i2] << endl;
			array_output_count++;
		};
		out << "    Has Vertex Weights:  " << skinPartitionBlocks[i1].hasVertexWeights << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < skinPartitionBlocks[i1].vertexWeights.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].vertexWeights[i2].size(); i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					break;
				};
				out << "        Vertex Weights[" << i3 << "]:  " << skinPartitionBlocks[i1].vertexWeights[i2][i3] << endl;
				array_output_count++;
			};
		};
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < skinPartitionBlocks[i1].stripLengths.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Strip Lengths[" << i2 << "]:  " << skinPartitionBlocks[i1].stripLengths[i2] << endl;
			array_output_count++;
		};
		out << "    Has Strips:  " << skinPartitionBlocks[i1].hasStrips << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < skinPartitionBlocks[i1].strips.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].stripLengths[i2]; i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					break;
				};
				out << "        Strips[" << i3 << "]:  " << skinPartitionBlocks[i1].strips[i2][i3] << endl;
				array_output_count++;
			};
		};
		if ( (skinPartitionBlocks[i1].numStrips == 0) ) {
			array_output_count = 0;
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].triangles.size(); i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
					break;
				};
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					break;
				};
				out << "        Triangles[" << i3 << "]:  " << skinPartitionBlocks[i1].triangles[i3] << endl;
				array_output_count++;
			};
		};
		out << "    Has Bone Indices:  " << skinPartitionBlocks[i1].hasBoneIndices << endl;
		if ( (skinPartitionBlocks[i1].hasBoneIndices != 0) ) {
			array_output_count = 0;
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].boneIndices.size(); i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
					break;
				};
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i1].boneIndices[i3].size(); i4++) {
					if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
						break;
					};
					out << "          Bone Indices[" << i4 << "]:  " << skinPartitionBlocks[i1].boneIndices[i3][i4] << endl;
					array_output_count++;
				};
			};
		};
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiSkinPartition::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiSkinPartition::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

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

unsigned short NiSkinPartition::GetWeightsPerVertex( int partition ) const {
   return skinPartitionBlocks[partition].numWeightsPerVertex;
}

void NiSkinPartition::SetWeightsPerVertex( int partition, unsigned short value ) {
   skinPartitionBlocks[partition].numWeightsPerVertex = value;
}

unsigned short NiSkinPartition::GetNumVertices( int partition ) const {
   return skinPartitionBlocks[partition].numVertices;
}

void NiSkinPartition::SetNumVertices( int partition, unsigned short value ) {
   skinPartitionBlocks[partition].numVertices = value;
}

vector<unsigned short> NiSkinPartition::GetBoneMap( int partition ) const {
   return skinPartitionBlocks[partition].bones;
}

void NiSkinPartition::SetBoneMap( int partition, const vector<unsigned short>& boneMap ) {
   skinPartitionBlocks[partition].bones = boneMap;
   skinPartitionBlocks[partition].numBones = (unsigned short)boneMap.size();
}

vector<unsigned short> NiSkinPartition::GetVertexMap( int partition ) const {
   return skinPartitionBlocks[partition].vertexMap;
}

void NiSkinPartition::SetVertexMap( int partition, const vector<unsigned short>& vertexMap ) {
   SkinPartition& part = skinPartitionBlocks[partition];
   if (vertexMap.empty()) {
      part.vertexMap.clear();
      part.numVertices = 0;
      part.hasVertexMap = false;
   } else {
      part.vertexMap = vertexMap;
      part.numVertices = (unsigned short)(vertexMap.size());
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

vector<unsigned short> NiSkinPartition::GetVertexBoneIndices( int partition, int vertex ) const {
   const vector<byte>& bones = skinPartitionBlocks[partition].boneIndices[vertex];
   vector<unsigned short> value;
   size_t n = bones.size();
   value.resize(bones.size());
   for (size_t i=0; i<n; ++i)
      value[i] = (unsigned short)(bones[i]);
   return value;
}

void NiSkinPartition::SetVertexBoneIndices( int partition, int vertex, const vector<unsigned short>& boneList ) {
   vector<byte>& bones = skinPartitionBlocks[partition].boneIndices[vertex];
   size_t n = boneList.size();
   bones.resize(n);
   for (size_t i=0; i<n; ++i)
      bones[i] = byte(boneList[i]);
}

unsigned short NiSkinPartition::GetStripCount( int partition ) const {
   return (unsigned short)skinPartitionBlocks[partition].strips.size();
}

void NiSkinPartition::SetStripCount( int partition, int n ) {
   SkinPartition& part = skinPartitionBlocks[partition];
   part.strips.resize(n);
   part.stripLengths.resize(n);
   part.hasStrips = (n!=0);
}

vector<unsigned short> NiSkinPartition::GetStrip( int partition, int index ) const {
   return skinPartitionBlocks[partition].strips[index];
}

void NiSkinPartition::SetStrip( int partition, int index, const vector<unsigned short> & in ) {
   SkinPartition& part = skinPartitionBlocks[partition];
   part.strips[index] = in;
   part.stripLengths[index] = (unsigned short)(in.size());

   int len = 0;
   for (vector<unsigned short>::iterator itr = part.stripLengths.begin(); itr != part.stripLengths.end(); ++itr) {
      len += ((*itr) - 2);
   }
   if (len < 0)
      len = 0;
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
   part.numTriangles = (unsigned int)(in.size()) * 3;
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
   NiTriBasedGeomDataRef geomData = DynamicCast<NiTriBasedGeomData>( shape->GetData() );
   if ( geomData == NULL ) {
      throw runtime_error( "Attempted to generate a skin partition on a mesh with no geometry data." );
   }

   int nWeightsPerVertex = 4;
   vector<WeightList> vertexWeights;
   BoneList boneMap;
   vector<unsigned short> vertexMap;
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
   SetNumVertices(0, (unsigned short)(vertexMap.size()) );
   SetVertexMap(0, vertexMap);
   EnableVertexWeights(0, true);
   EnableVertexBoneIndices(0, true);
   for (int i=0; i<nv; ++i) {
      SetVertexWeights(0, i, vertexWeights[i]);
      SetVertexBoneIndices(0, i, boneIndexList[i]);
   }

   // Special case for pre-stripped data
   if (NiTriStripsDataRef stripData = DynamicCast<NiTriStripsData>(geomData)) {
      unsigned short nstrips = stripData->GetStripCount();
      SetStripCount(0, nstrips);
      for (int i=0; i<int(nstrips); ++i) {
         SetStrip(0, i, stripData->GetStrip(i));
      }
   } else {

      Triangles triangles = geomData->GetTriangles();
      SetTriangles(0, triangles);

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
               vector<unsigned short> strip(groups[g].numIndices);
               for ( unsigned int s = 0; s<groups[g].numIndices; s++ )
                  strip[s] = groups[g].indices[s];
               SetStrip(0, g, strip);
            }
         }
         delete [] groups;
      }
   }
  
}


////////////////////////////////////////////////

static void mergeBones( BoneList &a, BoneList& b ) {
   for (size_t i=0; i<b.size(); ++i) {
      int c = b[i];
      BoneList::iterator it = find(a.begin(), a.end(), c);
      if ( a.end() == it ) {
         a.push_back( c );
      }
   }
}

static bool containsBones( BoneList& a, BoneList& b ) {
   for (size_t i=0; i<b.size(); ++i) {
      int c = b[i];
      BoneList::iterator it = find(a.begin(), a.end(), c);
      if ( a.end() == it ) {
         return false;
      }
   }
   return true;
}
template <typename I, typename V>
int indexOf(I begin, I end, const V& val) {
   return std::distance(begin, std::find(begin, end, val));
}


NiSkinPartition::NiSkinPartition(Ref<NiTriBasedGeom> shape, int maxBonesPerPartition, int maxBonesPerVertex ) {
   NiSkinInstanceRef skinInst = shape->GetSkinInstance();
   if ( skinInst == NULL ) {
      throw runtime_error( "You must bind a skin before setting generating skin partitions.  No NiSkinInstance found." );
   }
   NiSkinDataRef skinData = skinInst->GetSkinData();
   if ( skinData == NULL ) {
      throw runtime_error( "You must bind a skin before setting generating skin partitions.  No NiSkinData found." );
   }
   NiTriBasedGeomDataRef geomData = DynamicCast<NiTriBasedGeomData>(shape->GetData() );
   if ( geomData == NULL ) {
      throw runtime_error( "Attempted to generate a skin partition on a mesh with no geometry data." );
   }

      // read in the weights from NiSkinData
   vector<Vector3> verts = geomData->GetVertices();
   vector< BoneWeightList > weights;
   if (verts.empty()){
      throw runtime_error( "Attempted to generate a skin partition on a mesh with no vertices." );
   }

   Triangles triangles = geomData->GetTriangles();
   if (triangles.empty()) {
      throw runtime_error( "Attempted to generate a skin partition on a mesh with no triangles." );
   }

   weights.resize( verts.size() );
   int numBones = skinData->GetBoneCount();
   for ( int bone = 0; bone < numBones; bone++ )
   {
      vector<SkinWeight> vertexWeights = skinData->GetBoneWeights(bone);
      for (int r = 0; r < int(vertexWeights.size()); ++r ){
         int vertex = vertexWeights[r].index;
         float weight = vertexWeights[r].weight;
         if ( vertex >= int(weights.size()) )
            throw runtime_error( "bad NiSkinData - vertex count does not match" );
         weights[vertex].insert( weights[vertex].end(), BoneWeight(bone, weight) );
      }
   }

   // count min and max bones per vertex
   int minBones, maxBones;
   minBones = maxBones = weights[0].size();
   for(vector< BoneWeightList >::iterator itr = weights.begin(); itr != weights.end(); ++itr ){
      int n = (*itr).size();
      minBones = min(n, minBones);
      maxBones = max(n, maxBones);
   }

   if ( minBones <= 0 )
      throw runtime_error( "bad NiSkinData - some vertices have no weights at all" );

   // reduce vertex influences if necessary
   if ( maxBones > maxBonesPerVertex )
   {
      int c = 0;
      for ( vector< BoneWeightList >::iterator it = weights.begin(); it != weights.end(); ++it )
      {
         BoneWeightList & lst = *it;
         if ( int(lst.size()) > maxBonesPerVertex )
            c++;

         while ( int(lst.size()) > maxBonesPerVertex ) {
            int j = 0;
            float weight = lst.front().second;
            for ( int i = 0; i < int(lst.size()); i++ )
            {
               if ( lst[i].second < weight )
                  j = i;
            }
            BoneWeightList::iterator jit = lst.begin() + j;
            lst.erase( jit );
         }

         float totalWeight = 0;
         for (BoneWeightList::iterator bw = lst.begin(); bw != lst.end(); ++bw) {
            totalWeight += (*bw).second;
         }
         for (BoneWeightList::iterator bw = lst.begin(); bw != lst.end(); ++bw) {
            (*bw).second /= totalWeight;
         }
      }
      //qWarning() << "reduced" << c << "vertices to" << maxBonesPerVertex << "bone influences (maximum number of bones per vertex was" << maxBones << ")";
   }

   maxBones = maxBonesPerVertex;

   // reduces bone weights so that the triangles fit into the partitions

   typedef multimap<int,int> matchmap;
   typedef pair<matchmap::iterator, matchmap::iterator> matchrange;
   matchmap match;
   bool doMatch = true;

   BoneList tribones;
   int cnt = 0;
   for (Triangles::iterator itr = triangles.begin(); itr != triangles.end(); ++itr) {
      Triangle& tri = (*itr);
      do
      {
         tribones.clear();
         for ( int c = 0; c < 3; c++ ) {
            BoneWeightList& bwl = weights[tri[c]];
            for (BoneWeightList::iterator bw = bwl.begin(); bw != bwl.end(); ++bw) {
               if ( tribones.end() == find(tribones.begin(), tribones.end(), (*bw).first ) )
                  tribones.insert(tribones.end(), (*bw).first );
            }
         }

         if ( int(tribones.size()) > maxBonesPerPartition )
         {
            // sum up the weights for each bone
            // bones with weight == 1 can't be removed

            map<int, float> sum;
            vector<int> nono;

            for ( int t = 0; t < 3; t++ ) {
               BoneWeightList& bwl = weights[tri[t]];
               if ( bwl.size() == 1 )
                  nono.insert(nono.end(), bwl.front().first );

               for (BoneWeightList::iterator bw = bwl.begin(); bw != bwl.end(); ++bw) {
                  sum[ (*bw).first ] += (*bw).second;
               }                 
            }

            // select the bone to remove

            float minWeight = 5.0;
            int minBone = -1;

            for (map<int, float>::iterator sitr = sum.begin(); sitr != sum.end(); ++sitr) {
               int b = (*sitr).first;
               if ( (find(nono.begin(), nono.end(), b) == nono.end()) && sum[b] < minWeight) {
                  minWeight = sum[b];
                  minBone = b;
               }
            }

            if ( minBone < 0 )	// this shouldn't never happen
               throw runtime_error( "internal error 0x01" );

            // do a vertex match detect
            if ( doMatch ) {
               for ( size_t a = 0; a < verts.size(); a++ ) {
                  match.insert(matchmap::value_type(a, a));
                  for ( size_t b = a + 1; b < verts.size(); b++ ) {
                     if ( verts[a] == verts[b] && weights[a] == weights[b] ) {
                        match.insert(matchmap::value_type(a, b));
                        match.insert(matchmap::value_type(b, a));
                     }
                  }
               }
            }

            // now remove that bone from all vertices of this triangle and from all matching vertices too
            for ( int t = 0; t < 3; t++ ) {
               bool rem = false;

               matchrange range = match.equal_range(tri[t]);
               for (matchmap::iterator itr = range.first; itr != range.second; ++itr) {
                  int v = (*itr).second;

                  BoneWeightList & bws = weights[ v ];
                  BoneWeightList::iterator it = bws.begin();
                  while ( it != bws.end() ) {
                     BoneWeight & bw = *it;
                     if ( bw.first == minBone ) {
                        it = bws.erase(it);
                        rem = true;
                     } else {
                        ++it;
                     }
                  }

                  float totalWeight = 0;

                  for (BoneWeightList::iterator bw = bws.begin(); bw != bws.end(); ++bw) {
                     totalWeight += (*bw).second;
                  }

                  if ( totalWeight == 0 )
                     throw runtime_error( "internal error 0x02" );

                  // normalize
                  for (BoneWeightList::iterator bw = bws.begin(); bw != bws.end(); ++bw) {
                     (*bw).second /= totalWeight;
                  }
               }
               if ( rem )
                  cnt++;
            }
         }
      } while ( int(tribones.size()) > maxBonesPerPartition );
   }
   //if ( cnt > 0 )
   //   qWarning() << "removed" << cnt << "bone influences";

   PartitionList& parts = skinPartitionBlocks;
   // split the triangles into partitions
   while ( ! triangles.empty() ) {

      SkinPartition part;
      Triangles::iterator it = triangles.begin();
      while ( it != triangles.end() ) {
         Triangle & tri = *it;

         BoneList tribones;
         for ( int c = 0; c < 3; c++ ) {
            BoneWeightList& bws = weights[tri[c]];
            for (BoneWeightList::iterator bw = bws.begin(); bw != bws.end(); ++bw) {
               if ( tribones.end() == find(tribones.begin(), tribones.end(), (*bw).first ) )
                  tribones.push_back( (*bw).first );
            }
         }

         if ( part.bones.empty() || containsBones( part.bones, tribones ) ) {
            mergeBones( part.bones, tribones );
            part.triangles.push_back( tri );
            it = triangles.erase(it);
         } else {
            ++it;
         }
      }

      parts.push_back( part );
   }

   //qWarning() << parts.size() << "small partitions";

   // merge partitions

   bool merged;
   do
   {
      merged = false;
      // Working backwards through this list minimizes numbers of swaps
      //for ( int p2 = int(parts.size()-1); p2 >= 0  && ! merged; --p2 )
      //{
      //   Partition& part2 = parts[p2];
      //   for ( int p1 = int(p2-1); p1 >= 0 && ! merged; --p1 )
      //   {
      //      Partition& part1 = parts[p1];
      for ( int p1 = 0; p1 < int(parts.size()) && ! merged; p1++ )
      {
         Partition& part1 = parts[p1];
         for ( int p2 = p1+1; p2 < int(parts.size()) && ! merged; p2++ )
         {
            Partition& part2 = parts[p2];
            BoneList mergedBones = part1.bones;
            mergeBones( mergedBones, part2.bones );
            if ( int(mergedBones.size()) <= maxBonesPerPartition )
            {
               PartitionList::iterator p2i = parts.begin() + p2;
               part1.bones = mergedBones;
               part1.triangles.insert(part1.triangles.end(), (*p2i).triangles.begin(), (*p2i).triangles.end());
               parts.erase(p2i);
               merged = true;
            }
         }
      }
   }
   while ( merged );

   //qWarning() << parts.size() << "partitions";

   // start writing NiSkinPartition

   for ( int p = 0; p < int(parts.size()); p++ )
   {
      Partition& part = parts[p];
      BoneList& bones = part.bones;
      sort( bones.begin(), bones.end() );

      Triangles& triangles = part.triangles;

      vector<unsigned short>& vertices = part.vertexMap;
      for( Triangles::iterator tri = triangles.begin(); tri !=  triangles.end(); ++tri) {
         for ( int t = 0; t < 3; t++ ) {
            if ( vertices.end() == find(vertices.begin(), vertices.end(), (*tri)[t] ) )
               vertices.push_back( (*tri)[t] );
         }
      }
      sort( vertices.begin(), vertices.end() );
      part.numVertices = vertices.size();
      part.hasVertexMap = true;

      // map the vertices

      for ( int tri = 0; tri < int(triangles.size()); tri++ ) {
         for ( int t = 0; t < 3; t++ ) {
            triangles[tri][t] = indexOf(vertices.begin(), vertices.end(), triangles[tri][t]);
         }
      }

      SetWeightsPerVertex(p, maxBones);
      EnableVertexWeights(p, true);
      EnableVertexBoneIndices(p, true);

      // strippify the triangles
      NiTriStripsDataRef data = new NiTriStripsData(triangles, true);
      int nstrips = data->GetStripCount();
      SetStripCount( p, nstrips );
      for ( int i=0; i<nstrips; ++i ) {
         SetStrip(p, i, data->GetStrip(i));
      }

      //// Special case for pre-stripped data
      //unsigned short *data = new unsigned short[triangles.size() * 3 * 2];
      //for (size_t i=0; i< triangles.size(); i++) {
      //   data[i * 3 + 0] = triangles[i][0];
      //   data[i * 3 + 1] = triangles[i][1];
      //   data[i * 3 + 2] = triangles[i][2];
      //}
      //PrimitiveGroup * groups = 0;
      //unsigned short numGroups = 0;

      //// GF 3+
      //SetCacheSize(CACHESIZE_GEFORCE3);
      //// don't generate hundreds of strips
      //SetStitchStrips(true);
      //GenerateStrips(data, triangles.size()*3, &groups, &numGroups);
      //delete [] data;
      //if (groups) {
      //   SetStripCount(p, numGroups);
      //   for (int g=0; g<numGroups; g++) {
      //      if (groups[g].type == PT_STRIP) {
      //         vector<Niflib::unsigned short> strip(groups[g].numIndices);
      //         for (size_t s=0; s<groups[g].numIndices; s++)
      //            strip[s] = groups[g].indices[s];
      //         SetStrip(p, g, strip);
      //      }
      //   }
      //   delete [] groups;
      //}

      // fill in vertex weights and bones
      for (size_t v = 0; v < vertices.size(); ++v) {
         BoneWeightList& bwl = weights[vertices[v]];
         for ( int b = 0; b < maxBones; b++ ) {
            part.boneIndices[v][b] = (int(bwl.size()) > b) ? indexOf(bones.begin(), bones.end(), bwl[b].first) : 0 ;
            part.vertexWeights[v][b] = (int(bwl.size()) > b ? bwl[b].second : 0.0f);
         }
      }
   }
}

//--END CUSTOM CODE--//
