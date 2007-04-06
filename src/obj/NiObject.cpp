/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiObject.h"
#include "../../include/niflib.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiObject::TYPE("NiObject", NULL );

//Static to track total number of objects in memory.  Initialize to zero.
unsigned int NiObject::objectsInMemory = 0;

NiObject::NiObject() : _ref_count(0) {
	objectsInMemory++;
}
NiObject::~NiObject() {
	objectsInMemory--;
}

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

void NiObject::RemoveCrossRef( NiObject * block_to_remove ) {}
void NiObject::IncCrossRef( NiObject * block ) {}
void NiObject::DecCrossRef( NiObject* block ) {}
void NiObject::ReassignCrossRefs( const map<string,NiObjectRef> & name_map ) {}

unsigned int NiObject::NumObjectsInMemory() {
	return objectsInMemory;
}

//These should be pure virtual eventually
string NiObject::asString( bool verbose ) const {
	return string();
}

list<NiObjectRef> NiObject::GetRefs() const {
	return list<NiObjectRef>();
}

/*! Used to format a human readable string that includes the type of the object */
string NiObject::GetIDString() const {
	stringstream out;
	out << this << "(" << this->GetType().GetTypeName() << ")";
	return out.str();
}

NiObjectRef NiObject::Clone( unsigned int version, unsigned int user_version ) {
	//Create a string stream to temporarily hold the state-save of this block
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

const Type & NiObject::GetType() const {
	return TYPE;
};

unsigned int NiObject::GetNumRefs() {
	return _ref_count;
}

const Type & NiObject::TypeConst() {
	return TYPE;
}
