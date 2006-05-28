/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "Ref.h"

template <class T>
Ref<T>::Ref( T * object = NULL ) : _object(object) {}

template <class T>
Ref<T>::Ref(const Ref & ref_to_copy ) {
	_object = ref_to_copy._object;
	//If object isn't null, increment reference count
	if ( _object != NULL ) {
		_object->AddRef();
	}
}

template <class T>
Ref<T>::operator T*() const {
	return _object;
}

template <class T>
T& Ref<T>::operator*() const {
	return _object;
}

template <class T>
T* Ref<T>::operator->() const {
	return _object;
}

template <class T>
Ref<T> & Ref<T>::operator=( T * object ) {
	//Check if referenced objects are already the same
	if ( _object == object ) {
		return this; //Do nothing
	}

	//Decriment reference count on previously referenced object, if any
	if ( _object != NULL ) {
		_object->SubtractRef();
	}

	//Change reference to new object
	_object = object;

	//Increment reerence count on new object if it is not NULL
	if ( _object != NULL ) {
		_object->AddRef();
	}
}

template <class T>
Ref<T> & Ref<T>::operator=( const Ref & ref ) {
	//Check if referenced objects are already the same
	if ( _object == ref._object ) {
		return this; //Do nothing
	}

	//Decriment reference count on previously referenced object, if any
	if ( _object != NULL ) {
		_object->SubtractRef();
	}

	//Change reference to new object
	_object = ref._object;

	//Increment reerence count on new object if it is not NULL
	if ( _object != NULL ) {
		_object->AddRef();
	}
}

template <class T>
bool Ref<T>::operator<(const Ref & ref) const {
	return (_object < ref._object);
}

template <class T>
bool Ref<T>::operator==(T * object) const {
	//Compare pointer values of referenced objects
	return ( _object == object );
}

template <class T>
bool Ref<T>::operator!=(T * object) const {
	//Compare pointer values of referenced objects
	return ( _object != object );
}

template <class T>
bool Ref<T>::operator==(const Ref & ref) const {
	//Compare pointer values of referenced objects
	return ( _object == ref._object );
}

template <class T>
bool Ref<T>::operator!=(const Ref & ref) const {
	//Compare pointer values of referenced objects
	return ( _object != ref._object );
}
