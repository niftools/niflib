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
#include "../../include/obj/Lighting30ShaderProperty.h"
using namespace Niflib;

//Definition of TYPE constant
const Type Lighting30ShaderProperty::TYPE("Lighting30ShaderProperty", &NiShadeProperty::TYPE );

Lighting30ShaderProperty::Lighting30ShaderProperty() : unknownInt1((int)0), unknownFloat1(0.0f), unknownInt2((int)0), unknownFloat2(0.0f), unknownInt3((int)0), unknownInt4((int)0), unknownInt5((int)0), unknownInt6((int)0), unknownFloat3(0.0f), unknownFloat4(0.0f) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

Lighting30ShaderProperty::~Lighting30ShaderProperty() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & Lighting30ShaderProperty::GetType() const {
	return TYPE;
}

NiObject * Lighting30ShaderProperty::Create() {
	return new Lighting30ShaderProperty;
}

void Lighting30ShaderProperty::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiShadeProperty::Read( in, link_stack, info );
	NifStream( unknownInt1, in, info );
	NifStream( unknownFloat1, in, info );
	NifStream( unknownInt2, in, info );
	NifStream( unknownFloat2, in, info );
	NifStream( unknownInt3, in, info );
	NifStream( unknownInt4, in, info );
	NifStream( unknownInt5, in, info );
	NifStream( unknownInt6, in, info );
	NifStream( unknownFloat3, in, info );
	NifStream( unknownFloat4, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void Lighting30ShaderProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiShadeProperty::Write( out, link_map, info );
	NifStream( unknownInt1, out, info );
	NifStream( unknownFloat1, out, info );
	NifStream( unknownInt2, out, info );
	NifStream( unknownFloat2, out, info );
	NifStream( unknownInt3, out, info );
	NifStream( unknownInt4, out, info );
	NifStream( unknownInt5, out, info );
	NifStream( unknownInt6, out, info );
	NifStream( unknownFloat3, out, info );
	NifStream( unknownFloat4, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string Lighting30ShaderProperty::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiShadeProperty::asString();
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	out << "  Unknown Float 2:  " << unknownFloat2 << endl;
	out << "  Unknown Int 3:  " << unknownInt3 << endl;
	out << "  Unknown Int 4:  " << unknownInt4 << endl;
	out << "  Unknown Int 5:  " << unknownInt5 << endl;
	out << "  Unknown Int 6:  " << unknownInt6 << endl;
	out << "  Unknown Float 3:  " << unknownFloat3 << endl;
	out << "  Unknown Float 4:  " << unknownFloat4 << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void Lighting30ShaderProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiShadeProperty::FixLinks( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> Lighting30ShaderProperty::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiShadeProperty::GetRefs();
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
