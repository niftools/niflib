/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

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

class NIFLIB_API NiBoolData : public NI_BOOL_DATA_PARENT {
public:
	NiBoolData();
	~NiBoolData();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:	
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	/*! Retrieves the type of boolean interpolation being used.
	 * \return The boolean key type specifing the type of interpolation being used.
	 * \sa NiBoolData::SetKeyType
	 */
	KeyType GetKeyType() const;

	/*! Sets the type of boolean interpolation being used.  Does not affect existing key data.
	 * \param t The new boolean key type specifing the type of interpolation to be used.
	 * \sa NiBoolData::GetKeyType
	 */
	void SetKeyType( KeyType t );

	/*! Retrieves the boolean key data.
	 * \return A vector containing Key<unsigned char> data which specify boolean values over time.
	 * \sa NiBoolData::SetKeys, Key
	 */
	vector< Key<unsigned char> > GetKeys() const;

	/*! Sets the boolean key data.
	 * \param keys A vector containing new Key<unsigned char> data which will replace any existing data.
	 * \sa NiBoolData::GetKeys, Key
	 */
	void SetKeys( vector< Key<unsigned char> > const & keys );

protected:
	NI_BOOL_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
