/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NITEXTKEYEXTRADATA_H_
#define _NITEXTKEYEXTRADATA_H_

#include "NiExtraData.h"

#include "../gen/obj_defines.h"

class NiTextKeyExtraData;
typedef Ref<NiTextKeyExtraData> NiTextKeyExtraDataRef;

/*!
 * NiTextKeyExtraData - Extra data, used to name different animation
 * sequences.
 */

class NIFLIB_API NiTextKeyExtraData : public NI_TEXT_KEY_EXTRA_DATA_PARENT {
public:
	NiTextKeyExtraData();
	~NiTextKeyExtraData();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	const Type & GetType() const;

	/*! Retrieves the text note key data.
	 * \return A vector containing Key<string> data which specify text note over time.
	 * \sa NiKeyframeData::SetKeys, Key
	 */
	vector< Key<string> > GetKeys() const;

	/*! Sets the text note key data.
	 * \param keys A vector containing new Key<string> data which will replace any existing data.
	 * \sa NiKeyframeData::GetKeys, Key
	 */
	void SetKeys( vector< Key<string> > const & keys );

protected:
	NI_TEXT_KEY_EXTRA_DATA_MEMBERS
};

#endif
