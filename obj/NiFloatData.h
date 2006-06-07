/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIFLOATDATA_H_
#define _NIFLOATDATA_H_

#include "AKeyedData.h"
// Include structures
#include "../gen/KeyGroup.h"

#include "../gen/obj_defines.h"

class NiFloatData;
typedef Ref<NiFloatData> NiFloatDataRef;

/*!
 * NiFloatData - Possibly the 1D position along a 3D path.
 */

class NIFLIB_API NiFloatData : public NI_FLOAT_DATA_PARENT {
public:
	NiFloatData();
	~NiFloatData();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	/*! Retrieves the type of float interpolation being used.
	 * \return The float key type specifing the type of interpolation being used.
	 * \sa NiFloatData::SetKeyType
	 */
	KeyType GetKeyType() const;

	/*! Sets the type of float interpolation being used.  Does not affect existing key data.
	 * \param t The new float key type specifing the type of interpolation to be used.
	 * \sa NiFloatData::GetKeyType
	 */
	void SetKeyType( KeyType t );

	/*! Retrieves the float key data.
	 * \return A vector containing Key<float> data which specify float values over time.
	 * \sa NiFloatData::SetKeys, Key
	 */
	vector< Key<float> > GetKeys() const;

	/*! Sets the float key data.
	 * \param keys A vector containing new Key<float> data which will replace any existing data.
	 * \sa NiFloatData::GetKeys, Key
	 */
	void SetKeys( vector< Key<float> > const & keys );

protected:
	NI_FLOAT_DATA_MEMBERS
};

#endif
