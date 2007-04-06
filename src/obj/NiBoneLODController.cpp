/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBoneLODController.h"
#include "../../include/gen/SkinShapeGroup.h"
#include "../../include/gen/SkinShape.h"
#include "../../include/obj/NiTriShape.h"
#include "../../include/obj/NiSkinInstance.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBoneLODController::TYPE("NiBoneLODController", &NI_BONE_L_O_D_CONTROLLER_PARENT::TypeConst() );

NiBoneLODController::NiBoneLODController() NI_BONE_L_O_D_CONTROLLER_CONSTRUCT {}

NiBoneLODController::~NiBoneLODController() {}

void NiBoneLODController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiBoneLODController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiBoneLODController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBoneLODController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiBoneLODController::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBoneLODController::GetType() const {
	return TYPE;
};

const Type & NiBoneLODController::TypeConst() {
	return TYPE;
}
