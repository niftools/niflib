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
#include "../../include/obj/NiParticlesData.h"
#include "../../include/obj/NiAdditionalGeometryData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiParticlesData::TYPE("NiParticlesData", &NiObject::TYPE );

NiParticlesData::NiParticlesData() : numVertices((unsigned short)0), keepFlags((byte)0), compressFlags((byte)0), hasVertices(1), numUvSets((byte)0), tspaceFlag((byte)0), hasNormals(false), radius(0.0f), hasVertexColors(false), hasUv(false), consistencyFlags((ConsistencyType)CT_MUTABLE), additionalData(NULL), numParticles((unsigned short)0), particleRadius(0.0f), hasRadii(false), numActive((unsigned short)0), hasSizes(false), hasRotations(false), hasRotationAngles(false), hasRotationAxes(false), hasUnknownStuff1(false), numUnknownStuff1((short)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiParticlesData::~NiParticlesData() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiParticlesData::GetType() const {
	return TYPE;
}

NiObject * NiParticlesData::Create() {
	return new NiParticlesData;
}

void NiParticlesData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	if ( info.version >= 0x0A020000 ) {
		NifStream( name, in, info );
	};
	NifStream( numVertices, in, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( keepFlags, in, info );
		NifStream( compressFlags, in, info );
	};
	NifStream( hasVertices, in, info );
	if ( (!((info.version >= 0x14020007) && (info.userVersion == 11))) ) {
		if ( (hasVertices != 0) ) {
			vertices.resize(numVertices);
			for (unsigned int i3 = 0; i3 < vertices.size(); i3++) {
				NifStream( vertices[i3], in, info );
			};
		};
	};
	if ( info.version >= 0x0A000100 ) {
		NifStream( numUvSets, in, info );
		NifStream( tspaceFlag, in, info );
	};
	NifStream( hasNormals, in, info );
	if ( (!((info.version >= 0x14020007) && (info.userVersion == 11))) ) {
		if ( (hasNormals != 0) ) {
			normals.resize(numVertices);
			for (unsigned int i3 = 0; i3 < normals.size(); i3++) {
				NifStream( normals[i3], in, info );
			};
		};
	};
	if ( ( info.version >= 0x0A010000 ) && ( (!((info.version >= 0x14020007) && (info.userVersion == 11))) ) ) {
		if ( ((hasNormals != 0) && (tspaceFlag & 240)) ) {
			binormals.resize(numVertices);
			for (unsigned int i3 = 0; i3 < binormals.size(); i3++) {
				NifStream( binormals[i3], in, info );
			};
			tangents.resize(numVertices);
			for (unsigned int i3 = 0; i3 < tangents.size(); i3++) {
				NifStream( tangents[i3], in, info );
			};
		};
	};
	NifStream( center, in, info );
	NifStream( radius, in, info );
	NifStream( hasVertexColors, in, info );
	if ( (!((info.version >= 0x14020007) && (info.userVersion == 11))) ) {
		if ( (hasVertexColors != 0) ) {
			vertexColors.resize(numVertices);
			for (unsigned int i3 = 0; i3 < vertexColors.size(); i3++) {
				NifStream( vertexColors[i3], in, info );
			};
		};
	};
	if ( info.version <= 0x04020200 ) {
		NifStream( numUvSets, in, info );
		NifStream( tspaceFlag, in, info );
	};
	if ( info.version <= 0x04000002 ) {
		NifStream( hasUv, in, info );
	};
	if ( (!((info.version >= 0x14020007) && (info.userVersion == 11))) ) {
		uvSets.resize((numUvSets & 63));
		for (unsigned int i2 = 0; i2 < uvSets.size(); i2++) {
			uvSets[i2].resize(numVertices);
			for (unsigned int i3 = 0; i3 < uvSets[i2].size(); i3++) {
				NifStream( uvSets[i2][i3], in, info );
			};
		};
	};
	if ( info.version >= 0x0A000100 ) {
		NifStream( consistencyFlags, in, info );
	};
	if ( info.version >= 0x14000004 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	if ( info.version <= 0x04000002 ) {
		NifStream( numParticles, in, info );
	};
	if ( info.version <= 0x0A000100 ) {
		NifStream( particleRadius, in, info );
	};
	if ( info.version >= 0x0A010000 ) {
		NifStream( hasRadii, in, info );
	};
	if ( ( info.version >= 0x0A010000 ) && ( (!((info.version >= 0x14020007) && (info.userVersion == 11))) ) ) {
		if ( (hasRadii != 0) ) {
			radii.resize(numVertices);
			for (unsigned int i3 = 0; i3 < radii.size(); i3++) {
				NifStream( radii[i3], in, info );
			};
		};
	};
	NifStream( numActive, in, info );
	NifStream( hasSizes, in, info );
	if ( (!((info.version >= 0x14020007) && (info.userVersion == 11))) ) {
		if ( (hasSizes != 0) ) {
			sizes.resize(numVertices);
			for (unsigned int i3 = 0; i3 < sizes.size(); i3++) {
				NifStream( sizes[i3], in, info );
			};
		};
	};
	if ( info.version >= 0x0A000100 ) {
		NifStream( hasRotations, in, info );
	};
	if ( ( info.version >= 0x0A000100 ) && ( (!((info.version >= 0x14020007) && (info.userVersion == 11))) ) ) {
		if ( (hasRotations != 0) ) {
			rotations.resize(numVertices);
			for (unsigned int i3 = 0; i3 < rotations.size(); i3++) {
				NifStream( rotations[i3], in, info );
			};
		};
	};
	if ( info.version >= 0x14000004 ) {
		NifStream( hasRotationAngles, in, info );
	};
	if ( (!((info.version >= 0x14020007) && (info.userVersion == 11))) ) {
		if ( (hasRotationAngles != 0) ) {
			rotationAngles.resize(numVertices);
			for (unsigned int i3 = 0; i3 < rotationAngles.size(); i3++) {
				NifStream( rotationAngles[i3], in, info );
			};
		};
	};
	if ( info.version >= 0x14000004 ) {
		NifStream( hasRotationAxes, in, info );
	};
	if ( ( info.version >= 0x14000004 ) && ( (!((info.version >= 0x14020007) && (info.userVersion == 11))) ) ) {
		if ( (hasRotationAxes != 0) ) {
			rotationAxes.resize(numVertices);
			for (unsigned int i3 = 0; i3 < rotationAxes.size(); i3++) {
				NifStream( rotationAxes[i3], in, info );
			};
		};
	};
	if ( ((info.version >= 0x14020007) && (info.userVersion == 11)) ) {
		NifStream( hasUnknownStuff1, in, info );
		NifStream( numUnknownStuff1, in, info );
		if ( (hasUnknownStuff1 != 0) ) {
			unknownStuff1.resize(numUnknownStuff1);
			for (unsigned int i3 = 0; i3 < unknownStuff1.size(); i3++) {
				NifStream( unknownStuff1[i3], in, info );
			};
		};
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiParticlesData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, missing_link_stack, info );
	numUnknownStuff1 = (short)(unknownStuff1.size());
	numUvSets = (byte)(uvSets.size());
	numVertices = (unsigned short)(vertices.size());
	if ( info.version >= 0x0A020000 ) {
		NifStream( name, out, info );
	};
	NifStream( numVertices, out, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( keepFlags, out, info );
		NifStream( compressFlags, out, info );
	};
	NifStream( hasVertices, out, info );
	if ( (!((info.version >= 0x14020007) && (info.userVersion == 11))) ) {
		if ( (hasVertices != 0) ) {
			for (unsigned int i3 = 0; i3 < vertices.size(); i3++) {
				NifStream( vertices[i3], out, info );
			};
		};
	};
	if ( info.version >= 0x0A000100 ) {
		NifStream( numUvSets, out, info );
		NifStream( tspaceFlag, out, info );
	};
	NifStream( hasNormals, out, info );
	if ( (!((info.version >= 0x14020007) && (info.userVersion == 11))) ) {
		if ( (hasNormals != 0) ) {
			for (unsigned int i3 = 0; i3 < normals.size(); i3++) {
				NifStream( normals[i3], out, info );
			};
		};
	};
	if ( ( info.version >= 0x0A010000 ) && ( (!((info.version >= 0x14020007) && (info.userVersion == 11))) ) ) {
		if ( ((hasNormals != 0) && (tspaceFlag & 240)) ) {
			for (unsigned int i3 = 0; i3 < binormals.size(); i3++) {
				NifStream( binormals[i3], out, info );
			};
			for (unsigned int i3 = 0; i3 < tangents.size(); i3++) {
				NifStream( tangents[i3], out, info );
			};
		};
	};
	NifStream( center, out, info );
	NifStream( radius, out, info );
	NifStream( hasVertexColors, out, info );
	if ( (!((info.version >= 0x14020007) && (info.userVersion == 11))) ) {
		if ( (hasVertexColors != 0) ) {
			for (unsigned int i3 = 0; i3 < vertexColors.size(); i3++) {
				NifStream( vertexColors[i3], out, info );
			};
		};
	};
	if ( info.version <= 0x04020200 ) {
		NifStream( numUvSets, out, info );
		NifStream( tspaceFlag, out, info );
	};
	if ( info.version <= 0x04000002 ) {
		NifStream( hasUv, out, info );
	};
	if ( (!((info.version >= 0x14020007) && (info.userVersion == 11))) ) {
		for (unsigned int i2 = 0; i2 < uvSets.size(); i2++) {
			for (unsigned int i3 = 0; i3 < uvSets[i2].size(); i3++) {
				NifStream( uvSets[i2][i3], out, info );
			};
		};
	};
	if ( info.version >= 0x0A000100 ) {
		NifStream( consistencyFlags, out, info );
	};
	if ( info.version >= 0x14000004 ) {
		if ( info.version < VER_3_3_0_13 ) {
			WritePtr32( &(*additionalData), out );
		} else {
			if ( additionalData != NULL ) {
				map<NiObjectRef,unsigned int>::const_iterator it = link_map.find( StaticCast<NiObject>(additionalData) );
				if (it != link_map.end()) {
					NifStream( it->second, out, info );
					missing_link_stack.push_back( NULL );
				} else {
					NifStream( 0xFFFFFFFF, out, info );
					missing_link_stack.push_back( additionalData );
				}
			} else {
				NifStream( 0xFFFFFFFF, out, info );
				missing_link_stack.push_back( NULL );
			}
		}
	};
	if ( info.version <= 0x04000002 ) {
		NifStream( numParticles, out, info );
	};
	if ( info.version <= 0x0A000100 ) {
		NifStream( particleRadius, out, info );
	};
	if ( info.version >= 0x0A010000 ) {
		NifStream( hasRadii, out, info );
	};
	if ( ( info.version >= 0x0A010000 ) && ( (!((info.version >= 0x14020007) && (info.userVersion == 11))) ) ) {
		if ( (hasRadii != 0) ) {
			for (unsigned int i3 = 0; i3 < radii.size(); i3++) {
				NifStream( radii[i3], out, info );
			};
		};
	};
	NifStream( numActive, out, info );
	NifStream( hasSizes, out, info );
	if ( (!((info.version >= 0x14020007) && (info.userVersion == 11))) ) {
		if ( (hasSizes != 0) ) {
			for (unsigned int i3 = 0; i3 < sizes.size(); i3++) {
				NifStream( sizes[i3], out, info );
			};
		};
	};
	if ( info.version >= 0x0A000100 ) {
		NifStream( hasRotations, out, info );
	};
	if ( ( info.version >= 0x0A000100 ) && ( (!((info.version >= 0x14020007) && (info.userVersion == 11))) ) ) {
		if ( (hasRotations != 0) ) {
			for (unsigned int i3 = 0; i3 < rotations.size(); i3++) {
				NifStream( rotations[i3], out, info );
			};
		};
	};
	if ( info.version >= 0x14000004 ) {
		NifStream( hasRotationAngles, out, info );
	};
	if ( (!((info.version >= 0x14020007) && (info.userVersion == 11))) ) {
		if ( (hasRotationAngles != 0) ) {
			for (unsigned int i3 = 0; i3 < rotationAngles.size(); i3++) {
				NifStream( rotationAngles[i3], out, info );
			};
		};
	};
	if ( info.version >= 0x14000004 ) {
		NifStream( hasRotationAxes, out, info );
	};
	if ( ( info.version >= 0x14000004 ) && ( (!((info.version >= 0x14020007) && (info.userVersion == 11))) ) ) {
		if ( (hasRotationAxes != 0) ) {
			for (unsigned int i3 = 0; i3 < rotationAxes.size(); i3++) {
				NifStream( rotationAxes[i3], out, info );
			};
		};
	};
	if ( ((info.version >= 0x14020007) && (info.userVersion == 11)) ) {
		NifStream( hasUnknownStuff1, out, info );
		NifStream( numUnknownStuff1, out, info );
		if ( (hasUnknownStuff1 != 0) ) {
			for (unsigned int i3 = 0; i3 < unknownStuff1.size(); i3++) {
				NifStream( unknownStuff1[i3], out, info );
			};
		};
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiParticlesData::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	numUnknownStuff1 = (short)(unknownStuff1.size());
	numUvSets = (byte)(uvSets.size());
	numVertices = (unsigned short)(vertices.size());
	out << "  Name:  " << name << endl;
	out << "  Num Vertices:  " << numVertices << endl;
	out << "  Keep Flags:  " << keepFlags << endl;
	out << "  Compress Flags:  " << compressFlags << endl;
	out << "  Has Vertices:  " << hasVertices << endl;
	if ( (hasVertices != 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < vertices.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Vertices[" << i2 << "]:  " << vertices[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Num UV Sets:  " << numUvSets << endl;
	out << "  TSpace Flag:  " << tspaceFlag << endl;
	out << "  Has Normals:  " << hasNormals << endl;
	if ( (hasNormals != 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < normals.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Normals[" << i2 << "]:  " << normals[i2] << endl;
			array_output_count++;
		};
	};
	if ( ((hasNormals != 0) && (tspaceFlag & 240)) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < binormals.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Binormals[" << i2 << "]:  " << binormals[i2] << endl;
			array_output_count++;
		};
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < tangents.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Tangents[" << i2 << "]:  " << tangents[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Center:  " << center << endl;
	out << "  Radius:  " << radius << endl;
	out << "  Has Vertex Colors:  " << hasVertexColors << endl;
	if ( (hasVertexColors != 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < vertexColors.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Vertex Colors[" << i2 << "]:  " << vertexColors[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Has UV:  " << hasUv << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < uvSets.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (unsigned int i2 = 0; i2 < uvSets[i1].size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      UV Sets[" << i2 << "]:  " << uvSets[i1][i2] << endl;
			array_output_count++;
		};
	};
	out << "  Consistency Flags:  " << consistencyFlags << endl;
	out << "  Additional Data:  " << additionalData << endl;
	out << "  Num Particles:  " << numParticles << endl;
	out << "  Particle Radius:  " << particleRadius << endl;
	out << "  Has Radii:  " << hasRadii << endl;
	if ( (hasRadii != 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < radii.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Radii[" << i2 << "]:  " << radii[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Num Active:  " << numActive << endl;
	out << "  Has Sizes:  " << hasSizes << endl;
	if ( (hasSizes != 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < sizes.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Sizes[" << i2 << "]:  " << sizes[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Has Rotations:  " << hasRotations << endl;
	if ( (hasRotations != 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < rotations.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Rotations[" << i2 << "]:  " << rotations[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Has Rotation Angles:  " << hasRotationAngles << endl;
	if ( (hasRotationAngles != 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < rotationAngles.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Rotation Angles[" << i2 << "]:  " << rotationAngles[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Has Rotation Axes:  " << hasRotationAxes << endl;
	if ( (hasRotationAxes != 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < rotationAxes.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Rotation Axes[" << i2 << "]:  " << rotationAxes[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Has Unknown Stuff 1:  " << hasUnknownStuff1 << endl;
	out << "  Num Unknown Stuff 1:  " << numUnknownStuff1 << endl;
	if ( (hasUnknownStuff1 != 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < unknownStuff1.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Stuff 1[" << i2 << "]:  " << unknownStuff1[i2] << endl;
			array_output_count++;
		};
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiParticlesData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, missing_link_stack, info );
	if ( info.version >= 0x14000004 ) {
		additionalData = FixLink<NiAdditionalGeometryData>( objects, link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiParticlesData::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( additionalData != NULL )
		refs.push_back(StaticCast<NiObject>(additionalData));
	return refs;
}

std::list<NiObject *> NiParticlesData::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiObject::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
