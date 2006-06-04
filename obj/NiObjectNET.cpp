/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiObjectNET.h"
#include "NiExtraData.h"
#include "NiTimeController.h"

//Definition of TYPE constant
const Type NiObjectNET::TYPE("NiObjectNET", &NI_OBJECT_N_E_T_PARENT::TYPE );

NiObjectNET::NiObjectNET() NI_OBJECT_N_E_T_CONSTRUCT {}

NiObjectNET::~NiObjectNET() {}

void NiObjectNET::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_OBJECT_N_E_T_READ
}

void NiObjectNET::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_OBJECT_N_E_T_WRITE
}

string NiObjectNET::asString( bool verbose ) const {
	NI_OBJECT_N_E_T_STRING
}

void NiObjectNET::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_OBJECT_N_E_T_FIXLINKS
}

string NiObjectNET::GetName() {
	return name;
}

void NiObjectNET::SetName( string & new_name ) {
	name = new_name;
}

/*! Used to format a human readable string that includes the type of the object */
string NiObjectNET::GetIDString() {
	stringstream out;
	out << NiObject::GetIDString() << " {" << name << "}";
	return out.str();
}

