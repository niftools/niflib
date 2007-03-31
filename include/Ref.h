/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIFLIB_REF_H_
#define _NIFLIB_REF_H_

#include <ostream>
namespace Niflib {

using namespace std;

/**
 * Smart Pointer Template
 */

template<class T> class Ref;
template<class T> ostream & operator<<(ostream &, const Ref<T> &);

template <class T> class Ref {
public:
	Ref( T * object = NULL );
	Ref(const Ref & ref_to_copy );

#ifdef USE_NIFLIB_TEMPLATE_HELPERS
   template<typename U> Ref( const Ref<U>& other ) { 
      if ( (NULL != other._object) && other._object->IsDerivedType(T::TypeConst()) ) {
         _object = static_cast<T*>(other._object);
         if ( _object != NULL )
            _object->AddRef();
      } else {
         _object = NULL;
      }
   }
#endif

	~Ref();

	T& operator*() const;

	bool operator<(const Ref & ref) const;

	bool operator==(T * object) const;
	bool operator!=(T * object) const;
	bool operator==(const Ref & ref) const;
	bool operator!=(const Ref & ref) const;

	//These operators generate problems in SWIG
#ifndef SWIG
   friend ostream & operator<< <T>(ostream & os, const Ref & ref);
	Ref & operator=( T * object );
	Ref & operator=( const Ref & ref );
	operator T*() const;
#endif
	T* operator->() const;

	//SWIG specific operators
	string __str__();
	string __repr__();
	T* __call__() const;

protected:
#ifdef USE_NIFLIB_TEMPLATE_HELPERS
   template<typename U> friend class Ref;
#endif
	//The shared object
	T* _object;
};

template <class T>
Ref<T>::Ref( T * object ) : _object(object) {
   //If object isn't null, increment reference count
   if ( _object != NULL ) {
      _object->AddRef();
   }
}

template <class T>
Ref<T>::Ref(const Ref & ref_to_copy ) {
	_object = ref_to_copy._object;
	//If object isn't null, increment reference count
	if ( _object != NULL ) {
		_object->AddRef();
	}
}

template <class T>
Ref<T>::~Ref() {
	//if object insn't null, decrement reference count
	if ( _object != NULL ) {
		_object->SubtractRef();
	}
}

template <class T>
Ref<T>::operator T*() const {
	return _object;
}



template <class T>
T* Ref<T>::operator->() const {
	return _object;
}

//These operators generate warnings in SWIG
#ifndef SWIG

template <class T>
T& Ref<T>::operator*() const {
	return *_object;
}

template <class T>
Ref<T> & Ref<T>::operator=( T * object ) {
	//Check if referenced objects are already the same
	if ( _object == object ) {
		return *this; //Do nothing
	}

	//Increment reference count on new object if it is not NULL
	if ( object != NULL ) {
		object->AddRef();
	}

	//Decriment reference count on previously referenced object, if any
	if ( _object != NULL ) {
		_object->SubtractRef();
	}

	//Change reference to new object
	_object = object;

	return *this;
}


template <class T>
Ref<T> & Ref<T>::operator=( const Ref & ref ) {
	//Check if referenced objects are already the same
	if ( _object == ref._object ) {
		return *this; //Do nothing
	}

	//Increment reference count on new object if it is not NULL
	if ( ref._object != NULL ) {
		ref._object->AddRef();
	}

	//Decriment reference count on previously referenced object, if any
	if ( _object != NULL ) {
		_object->SubtractRef();
	}

	//Change reference to new object
	_object = ref._object;

	return *this;
}
#endif

//Template functions must be in the header file

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

#ifndef SWIG
template <class T>
ostream & operator<<(ostream & os, const Ref<T> & ref) {
	if (ref._object) {
		os << ref->GetIDString();
	} else {
		os << "NULL";
	}
	return os;
}
#endif

//SWIG functions
template <class T>
string Ref<T>::__str__() {
	if (_object) {
		return _object->asString();
	} else {
		return string("None");
	}
}

template <class T>
string Ref<T>::__repr__() {
	if (_object) {
		return _object->GetIDString();
	} else {
		return string("None");
	}
}

template <class T>
T* Ref<T>::__call__() const {
	return _object;
}


}


#endif
