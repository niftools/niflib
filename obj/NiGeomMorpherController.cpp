/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiGeomMorpherController.h"
#include "NiMorphData.h"
#include "NiInterpolator.h"

//Definition of TYPE constant
const Type NiGeomMorpherController::TYPE("NiGeomMorpherController", &NI_GEOM_MORPHER_CONTROLLER_PARENT::TypeConst() );

NiGeomMorpherController::NiGeomMorpherController() NI_GEOM_MORPHER_CONTROLLER_CONSTRUCT {}

NiGeomMorpherController::~NiGeomMorpherController() {}

void NiGeomMorpherController::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_GEOM_MORPHER_CONTROLLER_READ
}

void NiGeomMorpherController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_GEOM_MORPHER_CONTROLLER_WRITE
}

string NiGeomMorpherController::asString( bool verbose ) const {
	NI_GEOM_MORPHER_CONTROLLER_STRING
}

void NiGeomMorpherController::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_GEOM_MORPHER_CONTROLLER_FIXLINKS
}

list<NiObjectRef> NiGeomMorpherController::GetRefs() const {
	NI_GEOM_MORPHER_CONTROLLER_GETREFS
}

const Type & NiGeomMorpherController::GetType() const {
	return TYPE;
};

vector< Ref<NiInterpolator> > NiGeomMorpherController::GetInterpolators() const {
	return interpolators;
}

void NiGeomMorpherController::SetInterpolators( const vector< Ref<NiInterpolator> > & n ) {
	numInterpolators = uint(n.size());
	interpolators = n;
}

Ref<NiMorphData> NiGeomMorpherController::GetData() const {
	return data;
}

void NiGeomMorpherController::SetData( const Ref<NiMorphData> & n ) {
	data = n;
}