/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

//--BEGIN FILE HEAD CUSTOM CODE--//

//--END CUSTOM CODE--//

#include "../../include/FixLink.h"
#include "../../include/ObjectRegistry.h"
#include "../../include/NIF_IO.h"
#include "../../include/obj/bhkCompressedMeshShapeData.h"
#include "../../include/gen/bhkCMSD_Something.h"
#include "../../include/gen/bhkCMSDData.h"
#include "../../include/gen/bhkCMSDData.h"
#include "../../include/gen/bhkCMSD_Shape.h"
#include "../../include/gen/bhkCMSDContainer.h"
#include "../../include/gen/bhkCMSD_Shape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkCompressedMeshShapeData::TYPE("bhkCompressedMeshShapeData", &NiObject::TYPE );

bhkCompressedMeshShapeData::bhkCompressedMeshShapeData() : bitsPerIndex((unsigned int)0), bitsPerWIndex((unsigned int)0), maskWIndex((unsigned short)0), maskIndex((unsigned short)0), error(0.0f), unknownByte1((byte)0), unknownInt3((unsigned int)0), unknownInt4((unsigned int)0), unknownInt5((unsigned int)0), unknownByte2((byte)0), numMaterials((unsigned int)0), unknownInt6((unsigned int)0), numTransforms((unsigned int)0), numBigVerts((unsigned int)0), numBigTris((unsigned int)0), numChunks((unsigned int)0), unknownInt12((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

bhkCompressedMeshShapeData::~bhkCompressedMeshShapeData() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & bhkCompressedMeshShapeData::GetType() const {
	return TYPE;
}

NiObject * bhkCompressedMeshShapeData::Create() {
	return new bhkCompressedMeshShapeData;
}

void bhkCompressedMeshShapeData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::Read( in, link_stack, info );
	NifStream( bitsPerIndex, in, info );
	NifStream( bitsPerWIndex, in, info );
	NifStream( maskWIndex, in, info );
	NifStream( maskIndex, in, info );
	NifStream( error, in, info );
	NifStream( boundsMin, in, info );
	NifStream( boundsMax, in, info );
	NifStream( unknownByte1, in, info );
	NifStream( unknownInt3, in, info );
	NifStream( unknownInt4, in, info );
	NifStream( unknownInt5, in, info );
	NifStream( unknownByte2, in, info );
	NifStream( numMaterials, in, info );
	chunkMaterials.resize(numMaterials);
	for (unsigned int i1 = 0; i1 < chunkMaterials.size(); i1++) {
		NifStream( chunkMaterials[i1].largeInt, in, info );
		NifStream( chunkMaterials[i1].unknownInteger, in, info );
	};
	NifStream( unknownInt6, in, info );
	NifStream( numTransforms, in, info );
	if ( (numTransforms >= 1) ) {
    chunkTransforms.resize(numTransforms);
		for (unsigned int i2 = 0; i2 < chunkTransforms.size(); i2++) {
      NifStream( chunkTransforms[i2].translation, in, info );
      NifStream( chunkTransforms[i2].rotation.x, in, info );
      NifStream( chunkTransforms[i2].rotation.y, in, info );
      NifStream( chunkTransforms[i2].rotation.z, in, info );
      NifStream( chunkTransforms[i2].rotation.w, in, info );
		};
	};
	NifStream( numBigVerts, in, info );
	if ( (numBigVerts >= 1) ) {
		bigVerts.resize(numBigVerts);
		for (unsigned int i2 = 0; i2 < bigVerts.size(); i2++) {
			NifStream( bigVerts[i2], in, info );
		};
	};
	NifStream( numBigTris, in, info );
	if ( (numBigTris >= 1) ) {
		bigTris.resize(numBigTris);
		for (unsigned int i2 = 0; i2 < bigTris.size(); i2++) {
      NifStream( bigTris[i2].triangle1, in, info );
      NifStream( bigTris[i2].triangle2, in, info );
      NifStream( bigTris[i2].triangle3, in, info );
      NifStream( bigTris[i2].unknownInt1, in, info );
      NifStream( bigTris[i2].unknownShort1, in, info );
		};
	};
	NifStream( numChunks, in, info );
	if ( (numChunks >= 1) ) {
    chunks.resize(numChunks);
    for (unsigned int i2 = 0; i2 < chunks.size(); i2++) {
      NifStream( chunks[i2].translation, in, info );
      NifStream( chunks[i2].materialIndex, in, info );
      NifStream( chunks[i2].unknownShort1, in, info );
      NifStream( chunks[i2].transformIndex, in, info );
      NifStream( chunks[i2].numVertices, in, info );
      if ( (chunks[i2].numVertices >= 1) ) {
        chunks[i2].vertices.resize(chunks[i2].numVertices);
        for (unsigned int i4 = 0; i4 < chunks[i2].vertices.size(); i4++) {
          NifStream( chunks[i2].vertices[i4], in, info );
        };
      };
      NifStream( chunks[i2].numIndices, in, info );
      if ( (chunks[i2].numIndices >= 1) ) {
        chunks[i2].indices.resize(chunks[i2].numIndices);
        for (unsigned int i4 = 0; i4 < chunks[i2].indices.size(); i4++) {
          NifStream( chunks[i2].indices[i4], in, info );
        };
      };
      NifStream( chunks[i2].numStrips, in, info );
      if ( (chunks[i2].numStrips >= 1) ) {
        chunks[i2].strips.resize(chunks[i2].numStrips);
        for (unsigned int i4 = 0; i4 < chunks[i2].strips.size(); i4++) {
          NifStream( chunks[i2].strips[i4], in, info );
        };
      };
      NifStream( chunks[i2].numIndices2, in, info );
      if ( (chunks[i2].numIndices2 >= 1) ) {
        chunks[i2].indices2.resize(chunks[i2].numIndices2);
        for (unsigned int i4 = 0; i4 < chunks[i2].indices2.size(); i4++) {
          NifStream( chunks[i2].indices2[i4], in, info );
        };
      };
		};
	};
	NifStream( unknownInt12, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void bhkCompressedMeshShapeData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, missing_link_stack, info );
	numChunks = (unsigned int)(chunks.size());
	numBigTris = (unsigned int)(bigTris.size());
	numBigVerts = (unsigned int)(bigVerts.size());
	numTransforms = (unsigned int)(chunkTransforms.size());
	numMaterials = (unsigned int)(chunkMaterials.size());
	NifStream( bitsPerIndex, out, info );
	NifStream( bitsPerWIndex, out, info );
	NifStream( maskWIndex, out, info );
	NifStream( maskIndex, out, info );
	NifStream( error, out, info );
	NifStream( boundsMin, out, info );
	NifStream( boundsMax, out, info );
	NifStream( unknownByte1, out, info );
	NifStream( unknownInt3, out, info );
	NifStream( unknownInt4, out, info );
	NifStream( unknownInt5, out, info );
	NifStream( unknownByte2, out, info );
	NifStream( numMaterials, out, info );
	for (unsigned int i1 = 0; i1 < chunkMaterials.size(); i1++) {
		NifStream( chunkMaterials[i1].largeInt, out, info );
		NifStream( chunkMaterials[i1].unknownInteger, out, info );
	};
	NifStream( unknownInt6, out, info );
	NifStream( numTransforms, out, info );
	if ( (numTransforms >= 1) ) {
		for (unsigned int i2 = 0; i2 < chunkTransforms.size(); i2++) {
			NifStream( chunkTransforms[i2].translation, out, info );
			NifStream( chunkTransforms[i2].rotation.x, out, info );
			NifStream( chunkTransforms[i2].rotation.y, out, info );
			NifStream( chunkTransforms[i2].rotation.z, out, info );
			NifStream( chunkTransforms[i2].rotation.w, out, info );
		};
	};
	NifStream( numBigVerts, out, info );
	if ( (numBigVerts >= 1) ) {
		for (unsigned int i2 = 0; i2 < bigVerts.size(); i2++) {
			NifStream( bigVerts[i2], out, info );
		};
	};
	NifStream( numBigTris, out, info );
	if ( (numBigTris >= 1) ) {
		for (unsigned int i2 = 0; i2 < bigTris.size(); i2++) {
      NifStream( bigTris[i2].triangle1, out, info );
      NifStream( bigTris[i2].triangle2, out, info );
      NifStream( bigTris[i2].triangle3, out, info );
      NifStream( bigTris[i2].unknownInt1, out, info );
      NifStream( bigTris[i2].unknownShort1, out, info );
		};
	};
	NifStream( numChunks, out, info );
	if ( (numChunks >= 1) ) {
    for (unsigned int i2 = 0; i2 < chunks.size(); i2++) {
      NifStream( chunks[i2].translation, out, info );
      NifStream( chunks[i2].materialIndex, out, info );
      NifStream( chunks[i2].unknownShort1, out, info );
      NifStream( chunks[i2].transformIndex, out, info );
      chunks[i2].numVertices = chunks[i2].vertices.size();
      NifStream( chunks[i2].numVertices, out, info );
      if ( (chunks[i2].numVertices >= 1) ) {
        for (unsigned int i4 = 0; i4 < chunks[i2].vertices.size(); i4++) {
          NifStream( chunks[i2].vertices[i4], out, info );
        };
      };
      chunks[i2].numIndices = chunks[i2].indices.size();
      NifStream( chunks[i2].numIndices, out, info );
      if ( (chunks[i2].numIndices >= 1) ) {
        for (unsigned int i4 = 0; i4 < chunks[i2].indices.size(); i4++) {
          NifStream( chunks[i2].indices[i4], out, info );
        };
      };
      chunks[i2].numStrips = chunks[i2].strips.size();
      NifStream( chunks[i2].numStrips, out, info );
      if ( (chunks[i2].numStrips >= 1) ) {
        for (unsigned int i4 = 0; i4 < chunks[i2].strips.size(); i4++) {
          NifStream( chunks[i2].strips[i4], out, info );
        };
      };
      chunks[i2].numIndices2 = chunks[i2].indices2.size();
      NifStream( chunks[i2].numIndices2, out, info );
      if ( (chunks[i2].numIndices2 >= 1) ) {
        for (unsigned int i4 = 0; i4 < chunks[i2].indices2.size(); i4++) {
          NifStream( chunks[i2].indices2[i4], out, info );
        };
      };
		};
	};
	NifStream( unknownInt12, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string bhkCompressedMeshShapeData::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	numChunks = (unsigned int)(chunks.size());
	numBigTris = (unsigned int)(bigTris.size());
	numBigVerts = (unsigned int)(bigVerts.size());
	numTransforms = (unsigned int)(chunkTransforms.size());
	numMaterials = (unsigned int)(chunkMaterials.size());
	out << "  Bits Per Index:  " << bitsPerIndex << endl;
	out << "  Bits Per WIndex:  " << bitsPerWIndex << endl;
	out << "  Mask WIndex:  " << maskWIndex << endl;
	out << "  Mask Index:  " << maskIndex << endl;
	out << "  Error:  " << error << endl;
	out << "  boundsMin:  " << boundsMin << endl;
	out << "  boundsMax:  " << boundsMax << endl;
	out << "  Unknown Byte 1:  " << unknownByte1 << endl;
	out << "  Unknown Int 3:  " << unknownInt3 << endl;
	out << "  Unknown Int 4:  " << unknownInt4 << endl;
	out << "  Unknown Int 5:  " << unknownInt5 << endl;
	out << "  Unknown Byte 2:  " << unknownByte2 << endl;
	out << "  numMaterials:  " << numMaterials << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < chunkMaterials.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Large Int:  " << chunkMaterials[i1].largeInt << endl;
		out << "    Unknown Integer:  " << chunkMaterials[i1].unknownInteger << endl;
	};
	out << "  Unknown Int 6:  " << unknownInt6 << endl;
	out << "  Num Transforms:  " << numTransforms << endl;
	if ( (numTransforms >= 1) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < chunkTransforms.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Translation:  " << chunkTransforms[i2].translation << endl;
			out << "      Rotation:  " << chunkTransforms[i2].rotation.x << ", " << chunkTransforms[i2].rotation.y << ", "  << chunkTransforms[i2].rotation.z << ", "  << chunkTransforms[i2].rotation.w << endl;
		};
	};
	out << "  Num Big Verts:  " << numBigVerts << endl;
	if ( (numBigVerts >= 1) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < bigVerts.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Vertices[" << i2 << "]:  " << bigVerts[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Num Big Tris:  " << numBigTris << endl;
	if ( (numBigTris >= 1) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < bigTris.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "    Triangle1:  " << bigTris[i2].triangle1 << endl;
			out << "    Triangle2:  " << bigTris[i2].triangle2 << endl;
			out << "    Triangle3:  " << bigTris[i2].triangle3 << endl;
			out << "    unknown Int 1:  " << bigTris[i2].unknownInt1 << endl;
			out << "    unknown Short 1:  " << bigTris[i2].unknownShort1 << endl;
		};
	};
	out << "  Num Chunks:  " << numChunks << endl;
	if ( (numChunks >= 1) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < chunks.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "    Translation:  " << chunks[i2].translation << endl;
			out << "    MaterialIndex:  " << chunks[i2].materialIndex << endl;
			out << "    Unknown Short 1:  " << chunks[i2].unknownShort1 << endl;
			out << "    TransformIndex:  " << chunks[i2].transformIndex << endl;
			chunks[i2].numVertices = chunks[i2].vertices.size();
			out << "      Num Vertices:  " << chunks[i2].numVertices << endl;
			if ( (chunks[i2].numVertices >= 1) ) {
				array_output_count = 0;
				for (unsigned int i4 = 0; i4 < chunks[i2].vertices.size(); i4++) {
					if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
						out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
						break;
					};
					out << "          Vertex[" << i4 << "]:  " << chunks[i2].vertices[i4] << endl;
					array_output_count++;
				};
			};
			chunks[i2].numIndices = chunks[i2].indices.size();
			out << "      Num Indices:  " << chunks[i2].numIndices << endl;
			if ( (chunks[i2].numIndices >= 1) ) {
				array_output_count = 0;
				for (unsigned int i4 = 0; i4 < chunks[i2].indices.size(); i4++) {
					if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
						out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
						break;
					};
					out << "          Indices[" << i4 << "]:  " << chunks[i2].indices[i4] << endl;
					array_output_count++;
				};
			};
			chunks[i2].numStrips = chunks[i2].strips.size();
			out << "      Num Strips:  " << chunks[i2].numStrips << endl;
			if ( (chunks[i2].numStrips >= 1) ) {
				array_output_count = 0;
				for (unsigned int i4 = 0; i4 < chunks[i2].strips.size(); i4++) {
					if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
						out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
						break;
					};
					out << "          Strips[" << i4 << "]:  " << chunks[i2].strips[i4] << endl;
				};
			};
			chunks[i2].numIndices2 = chunks[i2].indices2.size();
			out << "      Num Indices2:  " << chunks[i2].numIndices2 << endl;
			if ( (chunks[i2].numIndices2 >= 1) ) {
				array_output_count = 0;
		        for (unsigned int i4 = 0; i4 < chunks[i2].indices2.size(); i4++) {
					if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
						out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
						break;
					};
					out << "          Indices2[" << i4 << "]:  " << chunks[i2].indices2[i4] << endl;
				};
			};
		};
	};
	out << "  Unknown Int 12:  " << unknownInt12 << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void bhkCompressedMeshShapeData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> bhkCompressedMeshShapeData::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

std::list<NiObject *> bhkCompressedMeshShapeData::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiObject::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//
const unsigned int bhkCompressedMeshShapeData::GetBitsPerIndex() const {
	return bitsPerIndex;
}

void bhkCompressedMeshShapeData::SetBitsPerIndex(unsigned int value) {
	bitsPerIndex = value;
}

const unsigned int bhkCompressedMeshShapeData::GetBitsPerWIndex() const {
	return bitsPerWIndex;
}

void bhkCompressedMeshShapeData::SetBitsPerWIndex(unsigned int value) {
	bitsPerWIndex = value;
}

const unsigned int bhkCompressedMeshShapeData::GetMaskWIndex() const {
	return maskWIndex;
}

void bhkCompressedMeshShapeData::SetMaskWIndex(unsigned int value) {
	maskWIndex = value;
}

const unsigned int bhkCompressedMeshShapeData::GetMaskIndex() const {
	return maskIndex;
}

void bhkCompressedMeshShapeData::SetMaskIndex(unsigned int value) {
	maskIndex = value;
}

const float bhkCompressedMeshShapeData::GetError() const {
	return error;
}

void bhkCompressedMeshShapeData::SetError(float value) {
	error = value;
}

const Vector4 bhkCompressedMeshShapeData::GetBoundsMin() const {
	return boundsMin;
}

void bhkCompressedMeshShapeData::SetBoundsMin(Vector4 value) {
	boundsMin = value;
}

const Vector4 bhkCompressedMeshShapeData::GetBoundsMax() const {
	return boundsMax;
}

void bhkCompressedMeshShapeData::SetBoundsMax(Vector4 value) {
	boundsMax = value;
}

unsigned int bhkCompressedMeshShapeData::GetNumMaterials() const {
	return numMaterials;
}

void bhkCompressedMeshShapeData::SetNumMaterials(unsigned int value) {
	numMaterials = value;
}

const vector<bhkCMSD_Something> & bhkCompressedMeshShapeData::GetChunkMaterials() const {
	return chunkMaterials;
}

unsigned int bhkCompressedMeshShapeData::SetChunkMaterials(vector<bhkCMSD_Something>& theChunkMaterials)
{
	numMaterials   = theChunkMaterials.size();
	chunkMaterials = theChunkMaterials;
	return numMaterials;
}

unsigned int bhkCompressedMeshShapeData::GetNumTransforms() const {
	return numTransforms;
}

void bhkCompressedMeshShapeData::SetNumTransforms(unsigned int value) {
	numTransforms = value;
}

const vector<bhkCMSDTransform> & bhkCompressedMeshShapeData::GetChunkTransforms() const {
	return chunkTransforms;
}

unsigned int bhkCompressedMeshShapeData::SetChunkTransforms(vector<bhkCMSDTransform>& theChunkTransforms)
{
	numTransforms   = theChunkTransforms.size();
	chunkTransforms = theChunkTransforms;
	return numTransforms;
}

unsigned int bhkCompressedMeshShapeData::GetNumBigVerts() const {
	return numBigVerts;
}

void bhkCompressedMeshShapeData::SetNumBigVerts(unsigned int value) {
	numBigVerts = value;
}

const vector<Vector4> & bhkCompressedMeshShapeData::GetBigVerts() const {
	return bigVerts;
}

unsigned int bhkCompressedMeshShapeData::SetBigVerts(vector<Vector4>& theBigVerts)
{
	numBigVerts = theBigVerts.size();
	bigVerts    = theBigVerts;
	return numBigVerts;
}

unsigned int bhkCompressedMeshShapeData::GetNumBigTris() const {
	return numBigTris;
}

void bhkCompressedMeshShapeData::SetNumBigTris(unsigned int value) {
	numBigTris = value;
}

const vector<bhkCMSDBigTris> & bhkCompressedMeshShapeData::GetBigTris() const {
	return bigTris;
}

unsigned int bhkCompressedMeshShapeData::SetBigTris(vector<bhkCMSDBigTris>& theBigVerts)
{
	numBigTris = theBigVerts.size();
	bigTris    = theBigVerts;
	return numBigTris;
}

unsigned int bhkCompressedMeshShapeData::GetNumChunks() const {
	return numChunks;
}

void bhkCompressedMeshShapeData::SetNumChunks(unsigned int value) {
	numChunks = value;
}

const vector<bhkCMSDChunk> & bhkCompressedMeshShapeData::GetChunks() const {
	return chunks;
}

unsigned int bhkCompressedMeshShapeData::SetChunks(vector<bhkCMSDChunk>& theChunks) {
	numChunks = theChunks.size();
	chunks    = theChunks;
	return numChunks;
}

//--END CUSTOM CODE--//
