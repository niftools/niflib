/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiSkinPartition.h"

//Definition of TYPE constant
const Type NiSkinPartition::TYPE("NiSkinPartition", &NI_SKIN_PARTITION_PARENT::TYPE );

NiSkinPartition::NiSkinPartition() NI_SKIN_PARTITION_CONSTRUCT {}

NiSkinPartition::~NiSkinPartition() {}

void NiSkinPartition::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	NI_SKIN_PARTITION_READ
}

void NiSkinPartition::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_SKIN_PARTITION_WRITE
}

string NiSkinPartition::asString( bool verbose ) const {
	NI_SKIN_PARTITION_STRING
}

void NiSkinPartition::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	NI_SKIN_PARTITION_FIXLINKS
}

