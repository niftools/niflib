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
#include "../../include/obj/NiPhysXActorDesc.h"
#include "../../include/obj/NiPhysXShapeDesc.h"
#include "../../include/obj/NiObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPhysXActorDesc::TYPE("NiPhysXActorDesc", &NiObject::TYPE );

NiPhysXActorDesc::NiPhysXActorDesc() : unknownInt1((int)0), unknownInt2((int)0), unknownInt3((int)0), unknownInt4(0.0f), unknownInt5((int)0), unknownByte1((byte)0), unknownByte2((byte)0), unknownInt6((int)0), shapeDescription(NULL), unknownRef1(NULL), unknownRef2(NULL), unknownRef3(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiPhysXActorDesc::~NiPhysXActorDesc() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiPhysXActorDesc::GetType() const {
	return TYPE;
}

NiObject * NiPhysXActorDesc::Create() {
	return new NiPhysXActorDesc;
}

void NiPhysXActorDesc::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	NifStream( unknownInt1, in, info );
	NifStream( unknownInt2, in, info );
	NifStream( unknownQuat1, in, info );
	NifStream( unknownQuat2, in, info );
	NifStream( unknownQuat3, in, info );
	NifStream( unknownInt3, in, info );
	NifStream( unknownInt4, in, info );
	NifStream( unknownInt5, in, info );
	NifStream( unknownByte1, in, info );
	NifStream( unknownByte2, in, info );
	NifStream( unknownInt6, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPhysXActorDesc::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, info );
	NifStream( unknownInt1, out, info );
	NifStream( unknownInt2, out, info );
	NifStream( unknownQuat1, out, info );
	NifStream( unknownQuat2, out, info );
	NifStream( unknownQuat3, out, info );
	NifStream( unknownInt3, out, info );
	NifStream( unknownInt4, out, info );
	NifStream( unknownInt5, out, info );
	NifStream( unknownByte1, out, info );
	NifStream( unknownByte2, out, info );
	NifStream( unknownInt6, out, info );
	if ( info.version < VER_3_3_0_13 ) {
		NifStream( (unsigned int)&(*shapeDescription), out, info );
	} else {
		if ( shapeDescription != NULL ) {
			NifStream( link_map.find( StaticCast<NiObject>(shapeDescription) )->second, out, info );
		} else {
			NifStream( 0xFFFFFFFF, out, info );
		}
	}
	if ( info.version < VER_3_3_0_13 ) {
		NifStream( (unsigned int)&(*unknownRef1), out, info );
	} else {
		if ( unknownRef1 != NULL ) {
			NifStream( link_map.find( StaticCast<NiObject>(unknownRef1) )->second, out, info );
		} else {
			NifStream( 0xFFFFFFFF, out, info );
		}
	}
	if ( info.version < VER_3_3_0_13 ) {
		NifStream( (unsigned int)&(*unknownRef2), out, info );
	} else {
		if ( unknownRef2 != NULL ) {
			NifStream( link_map.find( StaticCast<NiObject>(unknownRef2) )->second, out, info );
		} else {
			NifStream( 0xFFFFFFFF, out, info );
		}
	}
	if ( info.version < VER_3_3_0_13 ) {
		NifStream( (unsigned int)&(*unknownRef3), out, info );
	} else {
		if ( unknownRef3 != NULL ) {
			NifStream( link_map.find( StaticCast<NiObject>(unknownRef3) )->second, out, info );
		} else {
			NifStream( 0xFFFFFFFF, out, info );
		}
	}

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiPhysXActorDesc::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	out << "  Unknown Quat 1:  " << unknownQuat1 << endl;
	out << "  Unknown Quat 2:  " << unknownQuat2 << endl;
	out << "  Unknown Quat 3:  " << unknownQuat3 << endl;
	out << "  Unknown Int 3:  " << unknownInt3 << endl;
	out << "  Unknown Int 4:  " << unknownInt4 << endl;
	out << "  Unknown Int 5:  " << unknownInt5 << endl;
	out << "  Unknown Byte 1:  " << unknownByte1 << endl;
	out << "  Unknown Byte 2:  " << unknownByte2 << endl;
	out << "  Unknown Int 6:  " << unknownInt6 << endl;
	out << "  Shape Description:  " << shapeDescription << endl;
	out << "  Unknown Ref 1:  " << unknownRef1 << endl;
	out << "  Unknown Ref 2:  " << unknownRef2 << endl;
	out << "  Unknown Ref 3:  " << unknownRef3 << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPhysXActorDesc::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, info );
	shapeDescription = FixLink<NiPhysXShapeDesc>( objects, link_stack, info );
	unknownRef1 = FixLink<NiObject>( objects, link_stack, info );
	unknownRef2 = FixLink<NiObject>( objects, link_stack, info );
	unknownRef3 = FixLink<NiObject>( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPhysXActorDesc::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( shapeDescription != NULL )
		refs.push_back(StaticCast<NiObject>(shapeDescription));
	if ( unknownRef1 != NULL )
		refs.push_back(StaticCast<NiObject>(unknownRef1));
	if ( unknownRef2 != NULL )
		refs.push_back(StaticCast<NiObject>(unknownRef2));
	if ( unknownRef3 != NULL )
		refs.push_back(StaticCast<NiObject>(unknownRef3));
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
