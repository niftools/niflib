/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIOBJECT_H_
#define _NIOBJECT_H_

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <list>
#include <map>
#include <vector>
#include "../NIF_IO.h"
#include "../Ref.h"
#include "../Type.h"
#include "../gen/obj_defines.h"
namespace Niflib {

using namespace std;

class NiObject;
typedef Ref<NiObject> NiObjectRef;

/**
 * NiObject - Base NIF object from which all other NIF objects derive
 */
class NiObject {
public:
	/*! Constructor */
	NIFLIB_API NiObject();

	/*! Destructor */
	NIFLIB_API virtual ~NiObject();

	/*!
	 * Used to determine the type of a particular instance of this object.
	 * \return The type constant for the actual type of the object.
	 */
	NIFLIB_API virtual const Type & GetType() const;

	/*!
	 * Used to determine whether this object is exactly the same type as the given type constant.
	 * \return True if this object is exactly the same type as that represented by the given type constant.  False otherwise.
	 */
	NIFLIB_API bool IsSameType( const Type & compare_to ) const;

	/*!
	 * Used to determine whether this object is exactly the same type as another object.
	 * \return True if this object is exactly the same type as the given object.  False otherwise.
	 */
	NIFLIB_API bool IsSameType( const NiObject * object ) const;

	/*!
	 * Used to determine whether this object is a derived type of the given type constant.  For example, all NIF objects are derived types of NiObject, and a NiNode is also a derived type of NiObjectNET and NiAVObject.
	 * \return True if this object is derived from the type represented by the given type constant.  False otherwise.
	 */
	NIFLIB_API bool IsDerivedType( const Type & compare_to ) const;

	/*!
	 * Used to determine whether this object is a derived type of another object.  For example, all NIF objects are derived types of NiObject, and a NiNode is also a derived type of NiObjectNET and NiAVObject.
	 * \return True if this object is derived from the type of of the given object.  False otherwise.
	 */
	NIFLIB_API bool IsDerivedType( const NiObject * objct ) const;

	/*! Returns A new object that contains all the same data that this object does,
	 * but occupies a different part of memory.  The data stored in a NIF file varies
	 * from version to version.  Usually you are safe with the default option
	 * (the highest availiable version) but you may need to use an earlier version
	 * if you need to clone an obsolete piece of information.
	 * \param[in] version The version number to use in the memory streaming operation.  Default is the highest version availiable.
	 * \param[in] user_version The game-specific version number extention.
	 * \return A cloned copy of this object as a new object.
	 */
	NIFLIB_API NiObjectRef Clone( unsigned int version = 0xFFFFFFFF, unsigned int user_version = 0 );

	/*!
	 * Summarizes the information contained in this object in English.
	 * \param[in] verbose Determines whether or not detailed information about large areas of data will be printed out.
	 * \return A string containing a summary of the information within the object in English.  This is the function that Niflyze calls to generate its analysis, so the output is the same.
	 */
	NIFLIB_API virtual string asString( bool verbose = false ) const;

	/*!
	 * Formats a human readable string that includes the type of the object, and its name, if any
	 * \return A string in the form:  address(type), or adress(type) {name}
	 */
	NIFLIB_API virtual string GetIDString() const;
	

	/*!
	 * Returns the total number of NIF objects of any kind that have been allocated by Niflib for any reason.  This is for debugging or informational purpouses.  Mostly usful for tracking down memory leaks.
	 * \return The total number of NIF objects that have been allocated.
	 */
	NIFLIB_API static unsigned int NumObjectsInMemory();

	//Reference Counting

	/*!
	 * Increments the reference count on this object.  This should be taken care of automatically as long as you use Ref<T> smart pointers.  However, if you use bare pointers you may call this function yourself, though it is not recomended.
	 */
	NIFLIB_API void AddRef() const;

	/*!
	 * Decriments the reference count on this object.  This should be taken care of automatically as long as you use Ref<T> smart pointers.  However, if you use bare pointers you may call this function yourself, though it is not recomended.
	 */
	NIFLIB_API void SubtractRef() const;

	/*!
	 * Returns the number of references that currently exist for this object.
	 * \return The number of references to this object that are in use.
	 */
	NIFLIB_API unsigned int GetNumRefs();

	//--NIFLIB_HIDDEN functions.  For internal use only--//

	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	//Streaming Functions

	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {}
	
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {}

	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {}

	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
private:
	
	mutable unsigned int _ref_count;
	list<NiObject*> _cross_refs;
	static unsigned int objectsInMemory;
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};


/*
 * Casting Templates
 */

template <class T> Ref<T> StaticCast( NiObject * object ) {
	return (T*)object;
}

//SWIG doesn't want two versions of the same thing
#ifndef SWIG
template <class T> Ref<const T> StaticCast (const NiObject * object) {
	return (const T*)object;
}
#endif

template <class T> Ref<T> DynamicCast( NiObject * object ) {
	if ( object && object->IsDerivedType(T::TYPE) ) {
		return (T*)object;
	} else {
		return NULL;
	}
}

//SWIG doesn't want two versions of the same thing
#ifndef SWIG
template <class T> Ref<const T> DynamicCast( const NiObject * object ) {
	if ( object && object->IsDerivedType(T::TYPE) ) {
		return (const T*)object;
	} else {
		return NULL;
	}
}
#endif

#ifdef USE_NIFLIB_TEMPLATE_HELPERS
template <typename T, typename U> Ref<T> StaticCast( Ref<U>& object ) {
   return object;
}

template <typename T, typename U> Ref<T> DynamicCast( Ref<U>& object ) {
   return object;
}

template <typename T, typename U> Ref<T> StaticCast( const Ref<U>& object ) {
   return Ref<T>(object);
}

template <typename T, typename U> Ref<T> DynamicCast( const Ref<U>& object ) {
   return Ref<T>(object);
}

/*!
 * Dynamically cast from a collection of objects to another collection
 * \param objs A collection of object references to be dynamically casted to the specified type.
 * \return A collection of objects that support the requested type.
 */
template <typename U, typename T>
inline vector<Ref<U> > DynamicCast( vector<Ref<T> > const & objs ) {
   vector<Ref<U> > retval;
   for (vector<Ref<T> >::const_iterator itr = objs.begin(), end = objs.end(); itr != end; ++itr) {
      Ref<U> obj = DynamicCast<U>(*itr);
      if (obj) retval.insert(retval.end(), obj);
   }
   return retval;
}

/*!
* Dynamically cast from a collection of objects to another collection
* \param objs A collection of object references to be dynamically casted to the specified type.
* \return A collection of objects that support the requested type.
*/
template <typename U, typename T>
inline list<Ref<U> > DynamicCast( list<Ref<T> > const & objs ) {
   list<Ref<U> > retval;
   for (list<Ref<T> >::const_iterator itr = objs.begin(), end = objs.end(); itr != end; ++itr) {
      Ref<U> obj = DynamicCast<U>(*itr);
      if (obj) retval.insert(retval.end(), obj);
   }
   return retval;
}
#endif
}
#endif
