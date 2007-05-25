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
using namespace Niflib;

//Definition of TYPE constant
const Type NiParticlesData::TYPE("NiParticlesData", &NiGeometryData::TYPE );

NiParticlesData::NiParticlesData() : numParticles((unsigned short)0), size(0.0f), numActive((unsigned short)0), unknownShort((unsigned short)0), hasSizes(false), hasUnknownFloats1(false), hasRotations1(false) {
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

	NiGeometryData::Read( in, link_stack, info );
	if ( info.version <= 0x04000002 ) {
		NifStream( numParticles, in, info );
	};
	if ( info.version <= 0x0A000100 ) {
		NifStream( size, in, info );
	};
	if ( info.version <= 0x04000002 ) {
		NifStream( numActive, in, info );
	};
	if ( ( info.version >= 0x0401000C ) && ( info.version <= 0x0A000100 ) ) {
		NifStream( unknownShort, in, info );
	};
	NifStream( hasSizes, in, info );
	if ( (hasSizes != 0) ) {
		sizes.resize(numVertices);
		for (unsigned int i2 = 0; i2 < sizes.size(); i2++) {
			NifStream( sizes[i2], in, info );
		};
	};
	if ( info.version >= 0x0A010000 ) {
		NifStream( numActive, in, info );
		NifStream( hasUnknownFloats1, in, info );
		if ( (hasUnknownFloats1 != 0) ) {
			unknownFloats1.resize(numVertices);
			for (unsigned int i3 = 0; i3 < unknownFloats1.size(); i3++) {
				NifStream( unknownFloats1[i3], in, info );
			};
		};
	};
	if ( info.version >= 0x0A000100 ) {
		NifStream( hasRotations1, in, info );
		if ( (hasRotations1 != 0) ) {
			rotations1.resize(numVertices);
			for (unsigned int i3 = 0; i3 < rotations1.size(); i3++) {
				NifStream( rotations1[i3], in, info );
			};
		};
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiParticlesData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiGeometryData::Write( out, link_map, info );
	if ( info.version <= 0x04000002 ) {
		NifStream( numParticles, out, info );
	};
	if ( info.version <= 0x0A000100 ) {
		NifStream( size, out, info );
	};
	if ( info.version <= 0x04000002 ) {
		NifStream( numActive, out, info );
	};
	if ( ( info.version >= 0x0401000C ) && ( info.version <= 0x0A000100 ) ) {
		NifStream( unknownShort, out, info );
	};
	NifStream( hasSizes, out, info );
	if ( (hasSizes != 0) ) {
		for (unsigned int i2 = 0; i2 < sizes.size(); i2++) {
			NifStream( sizes[i2], out, info );
		};
	};
	if ( info.version >= 0x0A010000 ) {
		NifStream( numActive, out, info );
		NifStream( hasUnknownFloats1, out, info );
		if ( (hasUnknownFloats1 != 0) ) {
			for (unsigned int i3 = 0; i3 < unknownFloats1.size(); i3++) {
				NifStream( unknownFloats1[i3], out, info );
			};
		};
	};
	if ( info.version >= 0x0A000100 ) {
		NifStream( hasRotations1, out, info );
		if ( (hasRotations1 != 0) ) {
			for (unsigned int i3 = 0; i3 < rotations1.size(); i3++) {
				NifStream( rotations1[i3], out, info );
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
	out << NiGeometryData::asString();
	out << "  Num Particles:  " << numParticles << endl;
	out << "  Size:  " << size << endl;
	out << "  Num Active:  " << numActive << endl;
	out << "  Unknown Short:  " << unknownShort << endl;
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
	out << "  Has Unknown Floats 1:  " << hasUnknownFloats1 << endl;
	if ( (hasUnknownFloats1 != 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < unknownFloats1.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Floats 1[" << i2 << "]:  " << unknownFloats1[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Has Rotations 1:  " << hasRotations1 << endl;
	if ( (hasRotations1 != 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < rotations1.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Rotations 1[" << i2 << "]:  " << rotations1[i2] << endl;
			array_output_count++;
		};
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiParticlesData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiGeometryData::FixLinks( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiParticlesData::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiGeometryData::GetRefs();
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
