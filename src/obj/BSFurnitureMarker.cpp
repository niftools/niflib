/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/BSFurnitureMarker.h"
#include "../../include/gen/FurniturePosition.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSFurnitureMarker::TYPE("BSFurnitureMarker", &B_S_FURNITURE_MARKER_PARENT::TypeConst() );

BSFurnitureMarker::BSFurnitureMarker() B_S_FURNITURE_MARKER_CONSTRUCT {}

BSFurnitureMarker::~BSFurnitureMarker() {}

void BSFurnitureMarker::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void BSFurnitureMarker::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string BSFurnitureMarker::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void BSFurnitureMarker::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
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
	numPositions = uint(n.size());
	positions = n;
}

