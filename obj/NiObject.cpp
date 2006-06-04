/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiObject.h"

//Definition of TYPE constant
const Type NiObject::TYPE("NiObject", NULL );

//Static to track total number of objects in memory.  Initialize to zero.
unsigned int NiObject::objectsInMemory = 0;

NiObject::NiObject() : _ref_count(0) {}
NiObject::~NiObject() {}

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

void NiObject::AddRef() {
	++_ref_count;
}

void NiObject::SubtractRef() {
	--_ref_count;

	if ( _ref_count < 0 ) {
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
string NiObject::GetIDString() {
	stringstream out;
	out << this << "(" << this->GetType().GetTypeName() << ")";
	return out.str();
}
