/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiObject.h"

//Definition of TYPE constant
const Type NiObject::TYPE("NiObject", NULL );

//Static to track total number of objects in memory.  Initialize to zero.
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

void NiObject::AddRef() {
	++_ref_count;
}

void NiObject::SubtractRef() {
	--_ref_count;

	if ( _ref_count < 1 ) {
		delete this;
	}
}