/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NICOLORDATA_H_
#define _NICOLORDATA_H_

#include "AKeyedData.h"
// Include structures
#include "../gen/KeyGroup.h"

#include "../gen/obj_defines.h"

class NiColorData;
typedef Ref<NiColorData> NiColorDataRef;

/*!
 * NiColorData - Color data for material color controller.
 */

class NIFLIB_API NiColorData : public NI_COLOR_DATA_PARENT {
public:
	NiColorData();
	~NiColorData();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	/*! Retrieves the type of color interpolation being used.
	 * \return The color key type specifing the type of interpolation being used.
	 * \sa NiColorData::SetKeyType
	 */
	KeyType GetKeyType() const;

	/*! Sets the type of color interpolation being used.  Does not affect existing key data.
	 * \param t The new color key type specifing the type of interpolation to be used.
	 * \sa NiColorData::GetKeyType
	 */
	void SetKeyType( KeyType t );

	/*! Retrieves the color key data.
	 * \return A vector containing Key<Color4> data which specify color over time.
	 * \sa NiColorData::SetKeys, Key
	 */
	vector< Key<Color4> > GetKeys() const;

	/*! Sets the color key data.
	 * \param keys A vector containing new Key<Color4> data which will replace any existing data.
	 * \sa NiColorData::GetKeys, Key
	 */
	void SetKeys( vector< Key<Color4> > const & keys );
protected:
	NI_COLOR_DATA_MEMBERS
};

#endif
