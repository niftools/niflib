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
#include "../../include/obj/BSKeyframeController.h"
#include "../../include/obj/NiKeyframeData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSKeyframeController::TYPE("BSKeyframeController", &NiKeyframeController::TYPE );

BSKeyframeController::BSKeyframeController() : data2(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

BSKeyframeController::~BSKeyframeController() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & BSKeyframeController::GetType() const {
	return TYPE;
}

//A static bool to force the initialization to happen pre-main
bool BSKeyframeController::obj_initialized = BSKeyframeController::Register();

bool BSKeyframeController::Register() {
	//Register this object type with Niflib
	ObjectRegistry::RegisterObject( "BSKeyframeController", BSKeyframeController::Create );

	//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
	obj_initialized = true;
	return obj_initialized;
}

NiObject * BSKeyframeController::Create() {
	return new BSKeyframeController;
}

void BSKeyframeController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiKeyframeController::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void BSKeyframeController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiKeyframeController::Write( out, link_map, info );
	if ( data2 != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(data2) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string BSKeyframeController::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiKeyframeController::asString();
	out << "  Data 2:  " << data2 << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void BSKeyframeController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiKeyframeController::FixLinks( objects, link_stack, info );
	data2 = FixLink<NiKeyframeData>( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> BSKeyframeController::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiKeyframeController::GetRefs();
	if ( data2 != NULL )
		refs.push_back(StaticCast<NiObject>(data2));
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
