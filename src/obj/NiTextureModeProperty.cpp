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
#include "../../include/obj/NiTextureModeProperty.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTextureModeProperty::TYPE("NiTextureModeProperty", &NiProperty::TYPE );

NiTextureModeProperty::NiTextureModeProperty() : unknownShort((short)0), ps2L((unsigned short)0), ps2K((unsigned short)0xFFB5) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiTextureModeProperty::~NiTextureModeProperty() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiTextureModeProperty::GetType() const {
	return TYPE;
}

NiObject * NiTextureModeProperty::Create() {
	return new NiTextureModeProperty;
}

void NiTextureModeProperty::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiProperty::Read( in, link_stack, info );
	NifStream( unknownShort, in, info );
	if ( info.version <= 0x0A020000 ) {
		NifStream( ps2L, in, info );
		NifStream( ps2K, in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiTextureModeProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiProperty::Write( out, link_map, info );
	NifStream( unknownShort, out, info );
	if ( info.version <= 0x0A020000 ) {
		NifStream( ps2L, out, info );
		NifStream( ps2K, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiTextureModeProperty::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiProperty::asString();
	out << "  Unknown Short:  " << unknownShort << endl;
	out << "  PS2 L:  " << ps2L << endl;
	out << "  PS2 K:  " << ps2K << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiTextureModeProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiProperty::FixLinks( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiTextureModeProperty::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
