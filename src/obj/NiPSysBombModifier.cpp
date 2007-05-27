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
#include "../../include/obj/NiPSysBombModifier.h"
#include "../../include/obj/NiNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysBombModifier::TYPE("NiPSysBombModifier", &NiPSysModifier::TYPE );

NiPSysBombModifier::NiPSysBombModifier() : unknownLink(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiPSysBombModifier::~NiPSysBombModifier() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiPSysBombModifier::GetType() const {
	return TYPE;
}

NiObject * NiPSysBombModifier::Create() {
	return new NiPSysBombModifier;
}

void NiPSysBombModifier::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiPSysModifier::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	for (unsigned int i1 = 0; i1 < 2; i1++) {
		NifStream( unknownInts1[i1], in, info );
	};
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		NifStream( unknownFloats[i1], in, info );
	};
	for (unsigned int i1 = 0; i1 < 2; i1++) {
		NifStream( unknownInts2[i1], in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiPSysBombModifier::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiPSysModifier::Write( out, link_map, info );
	if ( info.version < VER_3_3_0_13 ) {
		NifStream( (unsigned int)&(*unknownLink), out, info );
	} else {
		if ( unknownLink != NULL ) {
			NifStream( link_map.find( StaticCast<NiObject>(unknownLink) )->second, out, info );
		} else {
			NifStream( 0xFFFFFFFF, out, info );
		}
	}
	for (unsigned int i1 = 0; i1 < 2; i1++) {
		NifStream( unknownInts1[i1], out, info );
	};
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		NifStream( unknownFloats[i1], out, info );
	};
	for (unsigned int i1 = 0; i1 < 2; i1++) {
		NifStream( unknownInts2[i1], out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiPSysBombModifier::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiPSysModifier::asString();
	out << "  Unknown Link:  " << unknownLink << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 2; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Ints 1[" << i1 << "]:  " << unknownInts1[i1] << endl;
		array_output_count++;
	};
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Floats[" << i1 << "]:  " << unknownFloats[i1] << endl;
		array_output_count++;
	};
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 2; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Ints 2[" << i1 << "]:  " << unknownInts2[i1] << endl;
		array_output_count++;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiPSysBombModifier::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiPSysModifier::FixLinks( objects, link_stack, info );
	unknownLink = FixLink<NiNode>( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPSysBombModifier::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
