/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "Ref.h"

template <class T>
Ref<T>::Ref( T * object = NULL ) : _object(object) {}

template <class T>
Ref<T>::Ref(const Ref & ref_to_copy ) {

}

template <class T>
Ref<T>::operator T*() const {

}

template <class T>
T& Ref<T>::operator*() const {

}

template <class T>
T* Ref<T>::operator->() const {

}

template <class T>
Ref<T> & Ref<T>::operator=( T * object ) {

}

template <class T>
Ref<T> & Ref<T>::operator=( const Ref & ref ) {

}

template <class T>
bool Ref<T>::operator<(const Ref & ref) const {
	return (_object < ref._object);
}

template <class T>
bool Ref<T>::operator==(T * object) const {

}

template <class T>
bool Ref<T>::operator!=(T * object) const {

}

template <class T>
bool Ref<T>::operator==(const Ref & ref) const {

}

template <class T>
bool Ref<T>::operator!=(const Ref & ref) const {

}
