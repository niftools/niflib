/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _NIPOSDATA_H_
#define _NIPOSDATA_H_

#include "AKeyedData.h"
// Include structures
#include "../gen/KeyGroup.h"
namespace Niflib {

//#include "../gen/obj_defines.h"

class NiPosData;
typedef Ref<NiPosData> NiPosDataRef;

/*!
 * NiPosData - Position data.
 */

class NiPosData : public NI_POS_DATA_PARENT {
public:
	NIFLIB_API NiPosData();
	NIFLIB_API ~NiPosData();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*! Retrieves the type of position interpolation being used.
	 * \return The position key type specifing the type of interpolation being used.
	 * \sa NiPosData::SetKeyType
	 */
	NIFLIB_API KeyType GetKeyType() const;

	/*! Sets the type of position interpolation being used.  Does not affect existing key data.
	 * \param t The new position key type specifing the type of interpolation to be used.
	 * \sa NiPosData::GetKeyType
	 */
	NIFLIB_API void SetKeyType( KeyType t );

	/*! Retrieves the position key data.
	 * \return A vector containing Key<Vector3> data which specify position over time.
	 * \sa NiPosData::SetKeys, Key
	 */
	NIFLIB_API vector< Key<Vector3> > GetKeys() const;

	/*! Sets the position key data.
	 * \param keys A vector containing new Key<Vector3> data which will replace any existing data.
	 * \sa NIPosData::GetKeys, Key
	 */
	NIFLIB_API void SetKeys( vector< Key<Vector3> > const & keys );

protected:
	NI_POS_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
