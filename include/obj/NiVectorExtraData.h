/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIVECTOREXTRADATA_H_
#define _NIVECTOREXTRADATA_H_

#include "NiExtraData.h"
namespace Niflib {


//#include "../gen/obj_defines.h"

class NiVectorExtraData;
typedef Ref<NiVectorExtraData> NiVectorExtraDataRef;

/*!
 * NiVectorExtraData - Extra vector data.
 */

class NiVectorExtraData : public NI_VECTOR_EXTRA_DATA_PARENT {
public:
	NIFLIB_API NiVectorExtraData();
	NIFLIB_API ~NiVectorExtraData();
	//Run-Time Type Information
	NIFLIB_API static const Type & TypeConst();
private:
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Retrieves the vector value stored in this object.
	 * \return The vector value stored in this object.
	 */
	NIFLIB_API Vector3 GetData() const;

	/*!
	 * Sets the vector value stored in this object.
	 * \param[in] n The new vector value to store in this object.
	 */
	NIFLIB_API void SetData( const Vector3 & n );

	//TODO:  There is an unknown member in this class
protected:
	NI_VECTOR_EXTRA_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
