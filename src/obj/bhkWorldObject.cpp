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
#include "../../include/obj/bhkWorldObject.h"
#include "../../include/obj/bhkShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkWorldObject::TYPE("bhkWorldObject", &bhkSerializable::TYPE );

bhkWorldObject::bhkWorldObject() : shape(NULL), layer((OblivionLayer)1), colFilter((byte)0), unknownShort((unsigned short)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

bhkWorldObject::~bhkWorldObject() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & bhkWorldObject::GetType() const {
	return TYPE;
}

//A static bool to force the initialization to happen pre-main
bool bhkWorldObject::obj_initialized = bhkWorldObject::Register();

bool bhkWorldObject::Register() {
	//Register this object type with Niflib
	ObjectRegistry::RegisterObject( "bhkWorldObject", bhkWorldObject::Create );

	//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
	obj_initialized = true;
	return obj_initialized;
}

NiObject * bhkWorldObject::Create() {
	return new bhkWorldObject;
}

void bhkWorldObject::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	bhkSerializable::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( layer, in, info );
	NifStream( colFilter, in, info );
	NifStream( unknownShort, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkWorldObject::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkSerializable::Write( out, link_map, info );
	if ( shape != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(shape) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	NifStream( layer, out, info );
	NifStream( colFilter, out, info );
	NifStream( unknownShort, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string bhkWorldObject::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkSerializable::asString();
	out << "  Shape:  " << shape << endl;
	out << "  Layer:  " << layer << endl;
	out << "  Col Filter:  " << colFilter << endl;
	out << "  Unknown Short:  " << unknownShort << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkWorldObject::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkSerializable::FixLinks( objects, link_stack, info );
	shape = FixLink<bhkShape>( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> bhkWorldObject::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkSerializable::GetRefs();
	if ( shape != NULL )
		refs.push_back(StaticCast<NiObject>(shape));
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

Ref<bhkShape > bhkWorldObject::GetShape() const {
	return shape;
}

void bhkWorldObject::SetShape( bhkShape * value ) {
	shape = value;
}

OblivionLayer bhkWorldObject::GetLayer() const {
	return layer;
}

void bhkWorldObject::SetLayer( OblivionLayer value ) {
	layer = value;
}

//--END CUSTOM CODE--//
