/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _REF_H_
#define _REF_H_

/**
 * Smart Pointer Template
 */
template <class T> class Ref {
public:
	Ref( T * object = NULL ) {}
	Ref(const Ref & ref_to_copy );

	operator T*() const;
	T& operator*() const;
	T* operator->() const;

	Ref & operator=( T * object );
	Ref & operator=( const Ref & ref );

	bool operator<(const Ref & ref) const;

	bool operator==(T * object) const;
	bool operator!=(T * object) const;
	bool operator==(const Ref & ref) const;
	bool operator!=(const Ref & ref) const;

protected:
	//The shared object
	T* _object;
};

#endif