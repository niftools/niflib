/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIFLOATDATA_H_
#define _NIFLOATDATA_H_

#include "AKeyedData.h"
// Include structures
#include "../gen/KeyGroup.h"
namespace Niflib {

//#include "../gen/obj_defines.h"

class NiFloatData;
typedef Ref<NiFloatData> NiFloatDataRef;

/*!
 * NiFloatData - Possibly the 1D position along a 3D path.
 */

class NiFloatData : public NI_FLOAT_DATA_PARENT {
public:
	NIFLIB_API NiFloatData();
	NIFLIB_API ~NiFloatData();
	//Run-Time Type Information
	NIFLIB_API static const Type & TypeConst() { return TYPE; }
private:	
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*! Retrieves the type of float interpolation being used.
	 * \return The float key type specifing the type of interpolation being used.
	 * \sa NiFloatData::SetKeyType
	 */
	NIFLIB_API KeyType GetKeyType() const;

	/*! Sets the type of float interpolation being used.  Does not affect existing key data.
	 * \param t The new float key type specifing the type of interpolation to be used.
	 * \sa NiFloatData::GetKeyType
	 */
	NIFLIB_API void SetKeyType( KeyType t );

	/*! Retrieves the float key data.
	 * \return A vector containing Key<float> data which specify float values over time.
	 * \sa NiFloatData::SetKeys, Key
	 */
	NIFLIB_API vector< Key<float> > GetKeys() const;

	/*! Sets the float key data.
	 * \param keys A vector containing new Key<float> data which will replace any existing data.
	 * \sa NiFloatData::GetKeys, Key
	 */
	NIFLIB_API void SetKeys( vector< Key<float> > const & keys );

protected:
	NI_FLOAT_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
