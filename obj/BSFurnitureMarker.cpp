/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "BSFurnitureMarker.h"

//Definition of TYPE constant
const Type BSFurnitureMarker::TYPE("BSFurnitureMarker", &B_S_FURNITURE_MARKER_PARENT::TYPE );

BSFurnitureMarker::BSFurnitureMarker() B_S_FURNITURE_MARKER_CONSTRUCT {}

BSFurnitureMarker::~BSFurnitureMarker() {}

void BSFurnitureMarker::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	B_S_FURNITURE_MARKER_READ
}

void BSFurnitureMarker::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	B_S_FURNITURE_MARKER_WRITE
}

string BSFurnitureMarker::asString( bool verbose ) const {
	B_S_FURNITURE_MARKER_STRING
}

void BSFurnitureMarker::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	B_S_FURNITURE_MARKER_FIXLINKS
}

