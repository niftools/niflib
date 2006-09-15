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



/**
 * NiObject - Base Object class from which all other objects derive
 */

class NiObject;
typedef Ref<NiObject> NiObjectRef;

class NiObject {
public:
	NIFLIB_API NiObject();
	NIFLIB_API virtual ~NiObject();
	//Run-Time Type Information
	NIFLIB_API static const Type & TypeConst() { return TYPE; }
private:	
	static const Type TYPE;
public:

	/*!
	 * Used to determine an object's type.  These type strings are the same as the class names of the blocks in the <a href = "http://www.niftools.org/docsys/">NIF File Format Browser</a>.
	 * \return A string containing the type of the object.  Ex. NiNode, NiTriShapeData, NiParticleSystemController, etc.
	 * 
	 * <b>Example:</b> 
	 * \code
	 * blk_ref my_block = ReadNifTree("test_in.nif");
	 * cout << my_block->GetType();
	 * \endcode
	 * 
	 * <b>In Python:</b>
	 * \code
	 * my_block = ReadNifTree("test_in.nif")
	 * print block.GetType()
	 * \endcode
	 */
	NIFLIB_API virtual const Type & GetType() const { return TYPE; };

	NIFLIB_API bool IsSameType( const Type & compare_to ) const;
	NIFLIB_API bool IsSameType( const NiObject * object ) const;
	NIFLIB_API bool IsDerivedType (const Type & compare_to ) const;
	NIFLIB_API bool IsDerivedType( const NiObject * objct ) const;

	//Streaming Functions
	NIFLIB_HIDDEN virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {}
	NIFLIB_HIDDEN virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {}
	NIFLIB_HIDDEN virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {}

	//Reference Counting
	NIFLIB_API void AddRef() const; //Should not be called directly
	NIFLIB_API void SubtractRef() const; //Should not be called directly
	NIFLIB_API unsigned int GetNumRefs() { return _ref_count; }

	/*! Returns A new block that contains all the same data that this block does, but occupies a different part of memory.  The data stored in a NIF file varies from version to version.  Usually you are safe with the default option (the highest availiable version) but you may need to use an earlier version if you need to clone an obsolete piece of information.
	 * \param version The version number to use in the memory streaming operation.  Default is the highest version availiable.
	 * \return A cloned copy of this block as a new block.
	 */
	NIFLIB_API NiObjectRef Clone( unsigned int version = 0xFFFFFFFF, unsigned int user_version = 0 );

	/*!
	 * Summarizes the information contained in this block in English.
	 * \param verbose Determines whether or not detailed information about large areas of data will be printed out.
	 * \return A string containing a summary of the information within the block in English.  This is the function that Niflyze calls to generate its analysis, so the output is the same.
	 * 
	 * <b>Example:</b> 
	 * \code
	 * blk_ref my_block = ReadNifTree("test_in.nif");
	 * cout << my_block->asString();
	 * \endcode
	 * 
	 * <b>In Python:</b>
	 * \code
	 * my_block = ReadNifTree("test_in.nif")
	 * print block.asString()
	 * \endcode
	 * 
	 * \sa IAttr::asString, SetVerboseMode
	 */
	NIFLIB_API virtual string asString( bool verbose = false ) const;

	/*!
	 * Formats a human readable string that includes the type of the object
	 * \return A string in the form:  address(type)
	 */
	NIFLIB_API virtual string GetIDString();

	/*!
	 * Used to retrieve all blocks that the current block is linked to through <i>all</i> attributes.
	 * \return A list of references to blocks that this attribute links its owner block to.
	 * 
	 * <b>Example:</b> 
	 * \code
	 * blk_ref my_block = ReadNifTree("test_in.nif");
	 * list<blk_ref> attr_list = my_block->GetRefs();
	 * \endcode
	 * 
	 * <b>In Python:</b>
	 * \code
	 * my_block = ReadNifTree("test_in.nif")
	 * attr_list = my_block.GetRefs()
	 * \endcode
	 */
	NIFLIB_API virtual list<NiObjectRef> GetRefs() const;
	
	// Python Operator Overloads
	NIFLIB_API string __str__() const {
		return asString();
	};

	NIFLIB_API virtual void RemoveCrossRef( NiObject * block_to_remove );

	NIFLIB_API void IncCrossRef( NiObject * block );
	NIFLIB_API void DecCrossRef( NiObject* block );
	NIFLIB_API virtual void ReassignCrossRefs( const map<string,NiObjectRef> & name_map );
	
	NIFLIB_API static unsigned int NumObjectsInMemory();
private:
	mutable unsigned int _ref_count;
	list<NiObject*> _cross_refs;
	static unsigned int objectsInMemory;
	STANDARD_INTERNAL_METHODS
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
	if ( object && object->IsDerivedType(T::TypeConst()) ) {
		return (T*)object;
	} else {
		return NULL;
	}
}

//SWIG doesn't want two versions of the same thing
#ifndef SWIG
template <class T> Ref<const T> DynamicCast( const NiObject * object ) {
	if ( object && object->IsDerivedType(T::TypeConst()) ) {
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
