/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _NIBOOLDATA_H_
#define _NIBOOLDATA_H_

#include "AKeyedData.h"
// Include structures
#include "../gen/KeyGroup.h"
namespace Niflib {

//#include "../gen/obj_defines.h"

class NiBoolData;
typedef Ref<NiBoolData> NiBoolDataRef;

/*!
 * NiBoolData - Timed boolean data.
 */

class NiBoolData : public NI_BOOL_DATA_PARENT {
public:
	NIFLIB_API NiBoolData();
	NIFLIB_API ~NiBoolData();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*! Retrieves the type of boolean interpolation being used.
	 * \return The boolean key type specifing the type of interpolation being used.
	 * \sa NiBoolData::SetKeyType
	 */
	NIFLIB_API KeyType GetKeyType() const;

	/*! Sets the type of boolean interpolation being used.  Does not affect existing key data.
	 * \param t The new boolean key type specifing the type of interpolation to be used.
	 * \sa NiBoolData::GetKeyType
	 */
	NIFLIB_API void SetKeyType( KeyType t );

	/*! Retrieves the boolean key data.
	 * \return A vector containing Key<unsigned char> data which specify boolean values over time.
	 * \sa NiBoolData::SetKeys, Key
	 */
	NIFLIB_API vector< Key<unsigned char> > GetKeys() const;

	/*! Sets the boolean key data.
	 * \param keys A vector containing new Key<unsigned char> data which will replace any existing data.
	 * \sa NiBoolData::GetKeys, Key
	 */
	NIFLIB_API void SetKeys( vector< Key<unsigned char> > const & keys );

protected:
	NI_BOOL_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
