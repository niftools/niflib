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
#include "../../include/obj/BSLagBoneController.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSLagBoneController::TYPE("BSLagBoneController", &NiTimeController::TYPE );

BSLagBoneController::BSLagBoneController() : unknownFloat2(0.0f), unknownFloat3(0.0f), unknownFloat4(0.0f) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

BSLagBoneController::~BSLagBoneController() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & BSLagBoneController::GetType() const {
	return TYPE;
}

NiObject * BSLagBoneController::Create() {
	return new BSLagBoneController;
}

void BSLagBoneController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiTimeController::Read( in, link_stack, info );
	NifStream( unknownFloat2, in, info );
	NifStream( unknownFloat3, in, info );
	NifStream( unknownFloat4, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSLagBoneController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiTimeController::Write( out, link_map, missing_link_stack, info );
	NifStream( unknownFloat2, out, info );
	NifStream( unknownFloat3, out, info );
	NifStream( unknownFloat4, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string BSLagBoneController::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	out << NiTimeController::asString();
	out << "  Unknown Float 2:  " << unknownFloat2 << endl;
	out << "  Unknown Float 3:  " << unknownFloat3 << endl;
	out << "  Unknown Float 4:  " << unknownFloat4 << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSLagBoneController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiTimeController::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> BSLagBoneController::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	return refs;
}

std::list<NiObject *> BSLagBoneController::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiTimeController::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
