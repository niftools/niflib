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
#include "../../include/obj/NiNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiMeshPSysData::TYPE("NiMeshPSysData", &NiPSysData::TYPE );

NiMeshPSysData::NiMeshPSysData() : numVertices2((unsigned int)0), unknownByte3((byte)0), unknownInt2((unsigned int)1), numVertices3((unsigned int)0), unknownNode(NULL) {
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

NiObject * NiMeshPSysData::Create() {
	return new NiMeshPSysData;
}

void NiMeshPSysData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiPSysData::Read( in, link_stack, info );
	if ( info.version >= 0x0A020000 ) {
		NifStream( numVertices2, in, info );
		NifStream( unknownByte3, in, info );
		NifStream( unknownInt2, in, info );
		NifStream( numVertices3, in, info );
	};
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiMeshPSysData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiPSysData::Write( out, link_map, info );
	if ( info.version >= 0x0A020000 ) {
		NifStream( numVertices2, out, info );
		NifStream( unknownByte3, out, info );
		NifStream( unknownInt2, out, info );
		NifStream( numVertices3, out, info );
	};
	if ( info.version < VER_3_3_0_13 ) {
		NifStream( (unsigned int)&(*unknownNode), out, info );
	} else {
		if ( unknownNode != NULL ) {
			NifStream( link_map.find( StaticCast<NiObject>(unknownNode) )->second, out, info );
		} else {
			NifStream( 0xFFFFFFFF, out, info );
		}
	}

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiMeshPSysData::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiPSysData::asString();
	out << "  Num Vertices 2:  " << numVertices2 << endl;
	out << "  Unknown Byte 3:  " << unknownByte3 << endl;
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	out << "  Num Vertices 3:  " << numVertices3 << endl;
	out << "  Unknown Node:  " << unknownNode << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiMeshPSysData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiPSysData::FixLinks( objects, link_stack, info );
	unknownNode = FixLink<NiNode>( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiMeshPSysData::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysData::GetRefs();
	if ( unknownNode != NULL )
		refs.push_back(StaticCast<NiObject>(unknownNode));
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
