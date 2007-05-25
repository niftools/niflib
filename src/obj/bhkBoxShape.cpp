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
#include "../../include/obj/bhkBoxShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkBoxShape::TYPE("bhkBoxShape", &bhkConvexShape::TYPE );

bhkBoxShape::bhkBoxShape() : unknownShort1((unsigned short)0), unknownShort2((unsigned short)0), unknownShort3((unsigned short)0), unknownShort4((unsigned short)0), min_Size(0.0f) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

bhkBoxShape::~bhkBoxShape() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & bhkBoxShape::GetType() const {
	return TYPE;
}

//A static bool to force the initialization to happen pre-main
bool bhkBoxShape::obj_initialized = bhkBoxShape::Register();

bool bhkBoxShape::Register() {
	//Register this object type with Niflib
	ObjectRegistry::RegisterObject( "bhkBoxShape", bhkBoxShape::Create );

	//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
	obj_initialized = true;
	return obj_initialized;
}

NiObject * bhkBoxShape::Create() {
	return new bhkBoxShape;
}

void bhkBoxShape::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConvexShape::Read( in, link_stack, info );
	NifStream( unknownShort1, in, info );
	NifStream( unknownShort2, in, info );
	NifStream( unknownShort3, in, info );
	NifStream( unknownShort4, in, info );
	NifStream( dimensions, in, info );
	NifStream( min_Size, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkBoxShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConvexShape::Write( out, link_map, info );
	NifStream( unknownShort1, out, info );
	NifStream( unknownShort2, out, info );
	NifStream( unknownShort3, out, info );
	NifStream( unknownShort4, out, info );
	NifStream( dimensions, out, info );
	NifStream( min_Size, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string bhkBoxShape::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkConvexShape::asString();
	out << "  Unknown Short 1:  " << unknownShort1 << endl;
	out << "  Unknown Short 2:  " << unknownShort2 << endl;
	out << "  Unknown Short 3:  " << unknownShort3 << endl;
	out << "  Unknown Short 4:  " << unknownShort4 << endl;
	out << "  Dimensions:  " << dimensions << endl;
	out << "  Min. size:  " << min_Size << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkBoxShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConvexShape::FixLinks( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> bhkBoxShape::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkConvexShape::GetRefs();
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

Vector3 bhkBoxShape::GetDimensions() const {
	return dimensions;
}

void bhkBoxShape::SetDimensions(const Vector3 &value) {
	dimensions = value;
}

//--END CUSTOM CODE--//
