/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPOSDATA_H_
#define _NIPOSDATA_H_

#include "AKeyedData.h"
// Include structures
#include "../gen/KeyGroup.h"

#include "../gen/obj_defines.h"

class NiPosData;
typedef Ref<NiPosData> NiPosDataRef;

/*!
 * NiPosData - Position data.
 */

class NIFLIB_API NiPosData : public NI_POS_DATA_PARENT {
public:
	NiPosData();
	~NiPosData();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	/*! Retrieves the type of position interpolation being used.
	 * \return The position key type specifing the type of interpolation being used.
	 * \sa NiPosData::SetKeyType
	 */
	KeyType GetKeyType() const;

	/*! Sets the type of position interpolation being used.  Does not affect existing key data.
	 * \param t The new position key type specifing the type of interpolation to be used.
	 * \sa NiPosData::GetKeyType
	 */
	void SetKeyType( KeyType t );

	/*! Retrieves the position key data.
	 * \return A vector containing Key<Vector3> data which specify position over time.
	 * \sa NiPosData::SetKeys, Key
	 */
	vector< Key<Vector3> > GetKeys() const;

	/*! Sets the position key data.
	 * \param keys A vector containing new Key<Vector3> data which will replace any existing data.
	 * \sa NIPosData::GetKeys, Key
	 */
	void SetKeys( vector< Key<Vector3> > const & keys );

protected:
	NI_POS_DATA_MEMBERS
};

#endif
