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
#include "../../include/obj/NiPSysData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysData::TYPE("NiPSysData", &NiRotatingParticlesData::TYPE );

NiPSysData::NiPSysData() : hasUnknownFloats3(false), hasUnknownFloats4(false), hasUnknownFloats6(false), unknownInt1((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiPSysData::~NiPSysData() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiPSysData::GetType() const {
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
		//Register this object type with Niflib
		ObjectRegistry::RegisterObject( "NiPSysData", NiPSysData::Create );

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiPSysData::Create() {
	return new NiPSysData;
}

void NiPSysData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiRotatingParticlesData::Read( in, link_stack, info );
	if ( info.version <= 0x0A020000 ) {
		unknownFloats2.resize(numVertices);
		for (unsigned int i2 = 0; i2 < unknownFloats2.size(); i2++) {
			for (unsigned int i3 = 0; i3 < 10; i3++) {
				NifStream( unknownFloats2[i2][i3], in, info );
			};
		};
	};
	if ( info.version >= 0x14000004 ) {
		NifStream( hasUnknownFloats3, in, info );
		if ( (hasUnknownFloats3 != 0) ) {
			unknownFloats1.resize(numVertices);
			for (unsigned int i3 = 0; i3 < unknownFloats1.size(); i3++) {
				NifStream( unknownFloats1[i3], in, info );
			};
		};
		NifStream( hasUnknownFloats4, in, info );
	};
	if ( (hasUnknownFloats4 != 0) ) {
		unknownFloats4.resize(numVertices);
		for (unsigned int i2 = 0; i2 < unknownFloats4.size(); i2++) {
			for (unsigned int i3 = 0; i3 < 4; i3++) {
				NifStream( unknownFloats4[i2][i3], in, info );
			};
		};
	};
	if ( info.version >= 0x14000004 ) {
		unknownFloats5.resize(numVertices);
		for (unsigned int i2 = 0; i2 < unknownFloats5.size(); i2++) {
			for (unsigned int i3 = 0; i3 < 7; i3++) {
				NifStream( unknownFloats5[i2][i3], in, info );
			};
		};
		NifStream( hasUnknownFloats6, in, info );
		if ( (hasUnknownFloats6 != 0) ) {
			unknownFloats6.resize(numVertices);
			for (unsigned int i3 = 0; i3 < unknownFloats6.size(); i3++) {
				NifStream( unknownFloats6[i3], in, info );
			};
		};
	};
	NifStream( unknownInt1, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiPSysData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiRotatingParticlesData::Write( out, link_map, info );
	if ( info.version <= 0x0A020000 ) {
		for (unsigned int i2 = 0; i2 < unknownFloats2.size(); i2++) {
			for (unsigned int i3 = 0; i3 < 10; i3++) {
				NifStream( unknownFloats2[i2][i3], out, info );
			};
		};
	};
	if ( info.version >= 0x14000004 ) {
		NifStream( hasUnknownFloats3, out, info );
		if ( (hasUnknownFloats3 != 0) ) {
			for (unsigned int i3 = 0; i3 < unknownFloats1.size(); i3++) {
				NifStream( unknownFloats1[i3], out, info );
			};
		};
		NifStream( hasUnknownFloats4, out, info );
	};
	if ( (hasUnknownFloats4 != 0) ) {
		for (unsigned int i2 = 0; i2 < unknownFloats4.size(); i2++) {
			for (unsigned int i3 = 0; i3 < 4; i3++) {
				NifStream( unknownFloats4[i2][i3], out, info );
			};
		};
	};
	if ( info.version >= 0x14000004 ) {
		for (unsigned int i2 = 0; i2 < unknownFloats5.size(); i2++) {
			for (unsigned int i3 = 0; i3 < 7; i3++) {
				NifStream( unknownFloats5[i2][i3], out, info );
			};
		};
		NifStream( hasUnknownFloats6, out, info );
		if ( (hasUnknownFloats6 != 0) ) {
			for (unsigned int i3 = 0; i3 < unknownFloats6.size(); i3++) {
				NifStream( unknownFloats6[i3], out, info );
			};
		};
	};
	NifStream( unknownInt1, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiPSysData::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiRotatingParticlesData::asString();
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < unknownFloats2.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (unsigned int i2 = 0; i2 < 10; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Floats 2[" << i2 << "]:  " << unknownFloats2[i1][i2] << endl;
			array_output_count++;
		};
	};
	out << "  Has Unknown Floats 3:  " << hasUnknownFloats3 << endl;
	if ( (hasUnknownFloats3 != 0) ) {
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
	out << "  Has Unknown Floats 4:  " << hasUnknownFloats4 << endl;
	if ( (hasUnknownFloats4 != 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < unknownFloats4.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			for (unsigned int i3 = 0; i3 < 4; i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					break;
				};
				out << "        Unknown Floats 4[" << i3 << "]:  " << unknownFloats4[i2][i3] << endl;
				array_output_count++;
			};
		};
	};
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < unknownFloats5.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (unsigned int i2 = 0; i2 < 7; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Floats 5[" << i2 << "]:  " << unknownFloats5[i1][i2] << endl;
			array_output_count++;
		};
	};
	out << "  Has Unknown Floats 6:  " << hasUnknownFloats6 << endl;
	if ( (hasUnknownFloats6 != 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < unknownFloats6.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Floats 6[" << i2 << "]:  " << unknownFloats6[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiPSysData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiRotatingParticlesData::FixLinks( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPSysData::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiRotatingParticlesData::GetRefs();
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
