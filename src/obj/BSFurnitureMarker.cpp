/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/BSFurnitureMarker.h"
#include "../../include/gen/FurniturePosition.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSFurnitureMarker::TYPE("BSFurnitureMarker", &B_S_FURNITURE_MARKER_PARENT::TypeConst() );

BSFurnitureMarker::BSFurnitureMarker() B_S_FURNITURE_MARKER_CONSTRUCT {}

BSFurnitureMarker::~BSFurnitureMarker() {}

void BSFurnitureMarker::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void BSFurnitureMarker::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string BSFurnitureMarker::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void BSFurnitureMarker::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> BSFurnitureMarker::GetRefs() const {
	return InternalGetRefs();
}

const Type & BSFurnitureMarker::GetType() const {
	return TYPE;
};

vector<FurniturePosition> BSFurnitureMarker::GetFurniturePositions() const {
	return positions;
}
	
void BSFurnitureMarker::SetFurniturePositions( const vector<FurniturePosition> & n ) {
	numPositions = (unsigned int)(n.size());
	positions = n;
}

const Type & BSFurnitureMarker::TypeConst() {
	return TYPE;
}
