/* Copyright (c) 2005, NIF File Format Library and Tools
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above
     copyright notice, this list of conditions and the following
     disclaimer in the documentation and/or other materials provided
     with the distribution.

   * Neither the name of the NIF File Format Library and Tools
     project nor the names of its contributors may be used to endorse
     or promote products derived from this software without specific
     prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE. */

#include "NiObject.h"

//Definition of TYPE constant
const Type NiObject::TYPE("NiObject", NULL );

//Static to track total number of objects in memory.  Initialize to zero.
unsigned int NiObject::objectsInMemory = 0;

/*
 * Type Methods
 */

bool Type::IsSameType( const Type & compare_to ) const {
	return &compare_to == this;
}

bool Type::IsDerivedType( const Type & compare_to ) const {

	const Type * search = this;
	while ( search != NULL ) {
		if ( search == &compare_to ) {
			return true;
		}
		search = search->base_type;
	}
	return false;
}

/*
 * NiObject Methods
 */

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