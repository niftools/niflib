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
#include "../../include/obj/NiCollisionObject.h"
#include "../../include/obj/NiAVObject.h"
#include "../../include/obj/NiObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiCollisionObject::TYPE("NiCollisionObject", &NiObject::TYPE );

NiCollisionObject::NiCollisionObject() : target(NULL), unknownShort((unsigned short)1), body(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiCollisionObject::~NiCollisionObject() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiCollisionObject::GetType() const {
	return TYPE;
}

//A static bool to force the initialization to happen pre-main
bool NiCollisionObject::obj_initialized = NiCollisionObject::Register();

bool NiCollisionObject::Register() {
	//Register this object type with Niflib
	ObjectRegistry::RegisterObject( "NiCollisionObject", NiCollisionObject::Create );

	//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
	obj_initialized = true;
	return obj_initialized;
}

NiObject * NiCollisionObject::Create() {
	return new NiCollisionObject;
}

void NiCollisionObject::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	if ( info.version >= 0x14000004 ) {
		NifStream( unknownShort, in, info );
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiCollisionObject::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, info );
	if ( target != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(target) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	if ( info.version >= 0x14000004 ) {
		NifStream( unknownShort, out, info );
		if ( body != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(body) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiCollisionObject::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	out << "  Target:  " << target << endl;
	out << "  Unknown Short:  " << unknownShort << endl;
	out << "  Body:  " << body << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiCollisionObject::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, info );
	target = FixLink<NiAVObject>( objects, link_stack, info );
	if ( info.version >= 0x14000004 ) {
		body = FixLink<NiObject>( objects, link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiCollisionObject::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( body != NULL )
		refs.push_back(StaticCast<NiObject>(body));
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

Ref<NiAVObject> NiCollisionObject::GetTarget() const {
	return target;
}

void NiCollisionObject::SetTarget( NiAVObject * value ) {
	target = value;
}

Ref<NiObject > NiCollisionObject::GetBody() const {
	return body;
}

void NiCollisionObject::SetBody( NiObject * value ) {
	body = value;
}

//--END CUSTOM CODE--//
