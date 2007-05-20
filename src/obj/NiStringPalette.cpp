/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiStringPalette.h"
#include "../../include/gen/StringPalette.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiStringPalette::TYPE("NiStringPalette", &NI_STRING_PALETTE_PARENT::TYPE );

NiStringPalette::NiStringPalette() NI_STRING_PALETTE_CONSTRUCT {}

NiStringPalette::~NiStringPalette() {}

void NiStringPalette::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiStringPalette::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiStringPalette::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiStringPalette::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiStringPalette::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiStringPalette::GetType() const {
	return TYPE;
};

//--BEGIN MISC CUSTOM CODE--//

string NiStringPalette::GetPaletteString() const {
	return palette.palette;
}
	
void NiStringPalette::SetPaletteString( const string & n ) {
	palette.palette = n;
}

string NiStringPalette::GetSubStr( short offset ) const {
	string out;
	
	// -1 is a null offset
	if ( offset == -1 ) {
		return out;
	}

	for ( unsigned int i = offset; i < palette.palette.size(); ++i ) {
		if ( palette.palette[i] == '\0' ) {
			break;
		}
		out.push_back( palette.palette[i] );
	}

	return out;
}

unsigned int NiStringPalette::AddSubStr( const string & n ) {
	//Search for the string
   //  When searching for strings also search for ending null.
	unsigned int offset = (unsigned int)palette.palette.find( n.c_str(), 0, n.size()+1 );
	
	//If string was not found, append it
	if ( offset == 0xFFFFFFFF ) {
		offset = (unsigned int)palette.palette.size();
		palette.palette.append( n + '\0' );
	}

	//Return the offset where the string was found or appended
	return offset;
}

//--END CUSTOM CODE--//

namespace Niflib { 
	typedef NiObject*(*obj_factory_func)();
	extern map<string, obj_factory_func> global_object_map;

	//Initialization function
	static bool Initialization();

	//A static bool to force the initialization to happen pre-main
	static bool obj_initialized = Initialization();

	static bool Initialization() {
		//Add the function to the global object map
		global_object_map["NiStringPalette"] = NiStringPalette::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiStringPalette::Create() {
	return new NiStringPalette;
}
