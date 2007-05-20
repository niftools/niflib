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
#include "../../include/NIF_IO.h"
#include "../../include/obj/NiLookAtInterpolator.h"
#include "../../include/obj/NiNode.h"
#include "../../include/obj/NiPoint3Interpolator.h"
#include "../../include/obj/NiFloatInterpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiLookAtInterpolator::TYPE("NiLookAtInterpolator", &NiInterpolator::TYPE );

NiLookAtInterpolator::NiLookAtInterpolator() : unknownShort((unsigned short)0), lookAt(NULL), unknownFloat(0.0f), scale(0.0f), unknownLink1(NULL), unknownLink2(NULL), unknownLink3(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiLookAtInterpolator::~NiLookAtInterpolator() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiLookAtInterpolator::GetType() const {
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
		//Add the function to the global object map
		global_object_map["NiLookAtInterpolator"] = NiLookAtInterpolator::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiLookAtInterpolator::Create() {
	return new NiLookAtInterpolator;
}

void NiLookAtInterpolator::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiInterpolator::Read( in, link_stack, info );
	NifStream( unknownShort, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( unknownFloat, in, info );
	NifStream( translation, in, info );
	NifStream( rotation, in, info );
	NifStream( scale, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiLookAtInterpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiInterpolator::Write( out, link_map, info );
	NifStream( unknownShort, out, info );
	if ( lookAt != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(lookAt) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	NifStream( unknownFloat, out, info );
	NifStream( translation, out, info );
	NifStream( rotation, out, info );
	NifStream( scale, out, info );
	if ( unknownLink1 != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(unknownLink1) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	if ( unknownLink2 != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(unknownLink2) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	if ( unknownLink3 != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(unknownLink3) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiLookAtInterpolator::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiInterpolator::asString();
	out << "  Unknown Short:  " << unknownShort << endl;
	out << "  Look At:  " << lookAt << endl;
	out << "  Unknown Float:  " << unknownFloat << endl;
	out << "  Translation:  " << translation << endl;
	out << "  Rotation:  " << rotation << endl;
	out << "  Scale:  " << scale << endl;
	out << "  Unknown Link 1:  " << unknownLink1 << endl;
	out << "  Unknown Link 2:  " << unknownLink2 << endl;
	out << "  Unknown Link 3:  " << unknownLink3 << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiLookAtInterpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiInterpolator::FixLinks( objects, link_stack, info );
	lookAt = FixLink<NiNode>( objects, link_stack, info );
	unknownLink1 = FixLink<NiPoint3Interpolator>( objects, link_stack, info );
	unknownLink2 = FixLink<NiFloatInterpolator>( objects, link_stack, info );
	unknownLink3 = FixLink<NiFloatInterpolator>( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiLookAtInterpolator::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiInterpolator::GetRefs();
	if ( lookAt != NULL )
		refs.push_back(StaticCast<NiObject>(lookAt));
	if ( unknownLink1 != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink1));
	if ( unknownLink2 != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink2));
	if ( unknownLink3 != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink3));
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

Ref<NiNode> NiLookAtInterpolator::GetLookAt() const {
	return lookAt;
}

void NiLookAtInterpolator::SetLookAt( Ref<NiNode > value ) {
	lookAt = value;
}

Vector3 NiLookAtInterpolator::GetTranslation() const {
	return translation;
}

void NiLookAtInterpolator::SetTranslation( Vector3 value ) {
	translation = value;
}

Quaternion NiLookAtInterpolator::GetRotation() const {
	return rotation;
}

void NiLookAtInterpolator::SetRotation( Quaternion value ) {
	rotation = value;
}

float NiLookAtInterpolator::GetScale() const {
	return scale;
}

void NiLookAtInterpolator::SetScale( float value ) {
	scale = value;
}

//--END CUSTOM CODE--//
