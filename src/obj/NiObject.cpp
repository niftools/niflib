/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

//--BEGIN FILE HEAD CUSTOM CODE--//
#include "../../include/niflib.h"
//--END CUSTOM CODE--//

#include "../../include/FixLink.h"
#include "../../include/NIF_IO.h"
#include "../../include/obj/NiObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiObject::TYPE("NiObject", NULL );

NiObject::NiObject() {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	_ref_count = 0;
	objectsInMemory++;

	//--END CUSTOM CODE--//
}

NiObject::~NiObject() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	objectsInMemory--;
	//--END CUSTOM CODE--//
}

const Type & NiObject::GetType() const {
	return TYPE;
}

namespace Niflib {
	typedef NiObject*(*obj_factory_func)();
	extern map<string, obj_factory_func> global_object_map;

	//Initialization function
	static bool Initialization();

	//A static bool to force the initialization to happen pre-main
	static bool obj_initialized = Initialization();

	static bool Initialization() {
		//Add the function to the global object map
		global_object_map["NiObject"] = NiObject::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiObject::Create() {
	return new NiObject;
}

void NiObject::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//


	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiObject::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//


	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiObject::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiObject::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//


	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiObject::GetRefs() const {
	list<Ref<NiObject> > refs;
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

unsigned int NiObject::objectsInMemory = 0;

bool NiObject::IsSameType( const Type & compare_to) const {
	return GetType().IsSameType( compare_to );
}

bool NiObject::IsSameType( const NiObject * object ) const {
	return GetType().IsSameType( object->GetType() );
}

bool NiObject::IsDerivedType( const Type & compare_to) const {
	return GetType().IsDerivedType( compare_to );
}

bool NiObject::IsDerivedType( const NiObject * object ) const {
	return GetType().IsDerivedType( object->GetType() );
}

void NiObject::AddRef() const {
	++_ref_count;
}

void NiObject::SubtractRef() const {
	_ref_count--;
	if ( _ref_count < 1 ) {
		delete this;
	}
}

unsigned int NiObject::NumObjectsInMemory() {
	return objectsInMemory;
}

/*! Used to format a human readable string that includes the type of the object */
string NiObject::GetIDString() const {
	stringstream out;
	out << this << "(" << this->GetType().GetTypeName() << ")";
	return out.str();
}

NiObjectRef NiObject::Clone( unsigned int version, unsigned int user_version ) {
	//Create a string stream to temporarily hold the state-save of this object
	stringstream tmp;

	//Create a new object of the same type
	NiObjectRef clone = CreateObject( this->GetType().GetTypeName() );

	//Dummy map
	map<NiObjectRef,unsigned int> link_map;

	//Write this object's data to the stream
	NifInfo info( version, user_version );
	this->Write( tmp, link_map, info );

	//Dummy stack
	list<unsigned int> link_stack;

	//Read the data back from the stream into the clone
	clone->Read( tmp, link_stack, info );

	//We don't fix the links, causing the clone to be a copy of all
	//data but have none of the linkage of the original.

	//return new object
	return clone;
};

unsigned int NiObject::GetNumRefs() {
	return _ref_count;
}

//--END CUSTOM CODE--//
