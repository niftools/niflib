/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiNode.h"

//Definition of TYPE constant
const Type NiNode::TYPE("NiNode", &NiAVObject::TYPE );

template <class T>
Ref<T>::Ref( T * object = NULL );

template <class T>
Ref::Ref(const Ref & ref_to_copy );

template <class T>
Ref::operator T*() const;

template <class T>
T& Ref::operator*() const;

template <class T>
T* Ref::operator->() const;

template <class T>
Ref & Ref::operator=( T * object );

template <class T>
Ref & Ref::operator=( const Ref & ref );

template <class T>
bool Ref::operator<(const Ref & ref) const {
	return (_object < ref._object);
}

template <class T>
bool Ref::operator==(T * object) const;

template <class T>
bool Ref::operator!=(T * object) const;

template <class T>
bool Ref::operator==(const Ref & ref) const;

bool Ref::operator!=(const Ref & ref) const;
