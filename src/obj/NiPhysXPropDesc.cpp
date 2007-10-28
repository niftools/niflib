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
#include "../../include/obj/NiPhysXPropDesc.h"
#include "../../include/obj/NiPhysXActorDesc.h"
#include "../../include/obj/NiPhysXMaterialDesc.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPhysXPropDesc::TYPE("NiPhysXPropDesc", &NiObject::TYPE );

NiPhysXPropDesc::NiPhysXPropDesc() : unknownInt1((unsigned int)0), actorDescription(NULL), unknownInt2((unsigned int)0), unknownInt3((unsigned int)0), unknownInt4((unsigned int)0), unknownByte1((byte)0), unknownByte2((byte)0), materialDescription(NULL), unknownInt5((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiPhysXPropDesc::~NiPhysXPropDesc() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiPhysXPropDesc::GetType() const {
	return TYPE;
}

NiObject * NiPhysXPropDesc::Create() {
	return new NiPhysXPropDesc;
}

void NiPhysXPropDesc::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	NifStream( unknownInt1, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( unknownInt2, in, info );
	NifStream( unknownInt3, in, info );
	NifStream( unknownInt4, in, info );
	NifStream( unknownByte1, in, info );
	NifStream( unknownByte2, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( unknownInt5, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPhysXPropDesc::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, info );
	NifStream( unknownInt1, out, info );
	if ( info.version < VER_3_3_0_13 ) {
		NifStream( (unsigned int)&(*actorDescription), out, info );
	} else {
		if ( actorDescription != NULL ) {
			NifStream( link_map.find( StaticCast<NiObject>(actorDescription) )->second, out, info );
		} else {
			NifStream( 0xFFFFFFFF, out, info );
		}
	}
	NifStream( unknownInt2, out, info );
	NifStream( unknownInt3, out, info );
	NifStream( unknownInt4, out, info );
	NifStream( unknownByte1, out, info );
	NifStream( unknownByte2, out, info );
	if ( info.version < VER_3_3_0_13 ) {
		NifStream( (unsigned int)&(*materialDescription), out, info );
	} else {
		if ( materialDescription != NULL ) {
			NifStream( link_map.find( StaticCast<NiObject>(materialDescription) )->second, out, info );
		} else {
			NifStream( 0xFFFFFFFF, out, info );
		}
	}
	NifStream( unknownInt5, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiPhysXPropDesc::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	out << "  Actor Description:  " << actorDescription << endl;
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	out << "  Unknown Int 3:  " << unknownInt3 << endl;
	out << "  Unknown Int 4:  " << unknownInt4 << endl;
	out << "  Unknown Byte 1:  " << unknownByte1 << endl;
	out << "  Unknown Byte 2:  " << unknownByte2 << endl;
	out << "  Material Description:  " << materialDescription << endl;
	out << "  Unknown Int 5:  " << unknownInt5 << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPhysXPropDesc::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, info );
	actorDescription = FixLink<NiPhysXActorDesc>( objects, link_stack, info );
	materialDescription = FixLink<NiPhysXMaterialDesc>( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPhysXPropDesc::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( actorDescription != NULL )
		refs.push_back(StaticCast<NiObject>(actorDescription));
	if ( materialDescription != NULL )
		refs.push_back(StaticCast<NiObject>(materialDescription));
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
