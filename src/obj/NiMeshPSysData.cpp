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
#include "../../include/obj/NiMeshPSysData.h"
#include "../../include/obj/NiObject.h"
#include "../../include/obj/NiNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiMeshPSysData::TYPE("NiMeshPSysData", &NiPSysData::TYPE );

NiMeshPSysData::NiMeshPSysData() : modifier(NULL), unknownByte2((byte)0), numUnknownLinks((unsigned int)0), numVertices2((unsigned int)0), unknownByte3((byte)0), unknownInt2((unsigned int)1), numVertices3((unsigned int)0), unknownLink2(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiMeshPSysData::~NiMeshPSysData() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiMeshPSysData::GetType() const {
	return TYPE;
}

//A static bool to force the initialization to happen pre-main
bool NiMeshPSysData::obj_initialized = NiMeshPSysData::Register();

bool NiMeshPSysData::Register() {
	//Register this object type with Niflib
	ObjectRegistry::RegisterObject( "NiMeshPSysData", NiMeshPSysData::Create );

	//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
	obj_initialized = true;
	return obj_initialized;
}

NiObject * NiMeshPSysData::Create() {
	return new NiMeshPSysData;
}

void NiMeshPSysData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiPSysData::Read( in, link_stack, info );
	if ( info.version <= 0x14000004 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	if ( ( info.version >= 0x0A020000 ) && ( info.version <= 0x14000004 ) ) {
		NifStream( unknownByte2, in, info );
		NifStream( numUnknownLinks, in, info );
		unknownLinks.resize(numUnknownLinks);
		for (unsigned int i2 = 0; i2 < unknownLinks.size(); i2++) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
	};
	if ( info.version >= 0x14000005 ) {
		NifStream( numVertices2, in, info );
		NifStream( unknownByte3, in, info );
		NifStream( unknownInt2, in, info );
		NifStream( numVertices3, in, info );
	};
	if ( info.version >= 0x0A020000 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiMeshPSysData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiPSysData::Write( out, link_map, info );
	numUnknownLinks = (unsigned int)(unknownLinks.size());
	if ( info.version <= 0x14000004 ) {
		if ( modifier != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(modifier) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
	if ( ( info.version >= 0x0A020000 ) && ( info.version <= 0x14000004 ) ) {
		NifStream( unknownByte2, out, info );
		NifStream( numUnknownLinks, out, info );
		for (unsigned int i2 = 0; i2 < unknownLinks.size(); i2++) {
			if ( unknownLinks[i2] != NULL )
				NifStream( link_map.find( StaticCast<NiObject>(unknownLinks[i2]) )->second, out, info );
			else
				NifStream( 0xffffffff, out, info );
		};
	};
	if ( info.version >= 0x14000005 ) {
		NifStream( numVertices2, out, info );
		NifStream( unknownByte3, out, info );
		NifStream( unknownInt2, out, info );
		NifStream( numVertices3, out, info );
	};
	if ( info.version >= 0x0A020000 ) {
		if ( unknownLink2 != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(unknownLink2) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiMeshPSysData::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiPSysData::asString();
	numUnknownLinks = (unsigned int)(unknownLinks.size());
	out << "  Modifier:  " << modifier << endl;
	out << "  Unknown Byte 2:  " << unknownByte2 << endl;
	out << "  Num Unknown Links:  " << numUnknownLinks << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < unknownLinks.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Links[" << i1 << "]:  " << unknownLinks[i1] << endl;
		array_output_count++;
	};
	out << "  Num Vertices 2:  " << numVertices2 << endl;
	out << "  Unknown Byte 3:  " << unknownByte3 << endl;
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	out << "  Num Vertices 3:  " << numVertices3 << endl;
	out << "  Unknown Link 2:  " << unknownLink2 << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiMeshPSysData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiPSysData::FixLinks( objects, link_stack, info );
	if ( info.version <= 0x14000004 ) {
		modifier = FixLink<NiObject>( objects, link_stack, info );
	};
	if ( ( info.version >= 0x0A020000 ) && ( info.version <= 0x14000004 ) ) {
		for (unsigned int i2 = 0; i2 < unknownLinks.size(); i2++) {
			unknownLinks[i2] = FixLink<NiObject>( objects, link_stack, info );
		};
	};
	if ( info.version >= 0x0A020000 ) {
		unknownLink2 = FixLink<NiNode>( objects, link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiMeshPSysData::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysData::GetRefs();
	if ( modifier != NULL )
		refs.push_back(StaticCast<NiObject>(modifier));
	for (unsigned int i1 = 0; i1 < unknownLinks.size(); i1++) {
		if ( unknownLinks[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(unknownLinks[i1]));
	};
	if ( unknownLink2 != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink2));
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
