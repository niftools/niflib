/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _NITEXTKEYEXTRADATA_H_
#define _NITEXTKEYEXTRADATA_H_

#include "NiExtraData.h"
namespace Niflib {

//#include "../gen/obj_defines.h"

class NiTextKeyExtraData;
typedef Ref<NiTextKeyExtraData> NiTextKeyExtraDataRef;

/*!
 * NiTextKeyExtraData - Extra data, used to name different animation
 * sequences.
 */

class NiTextKeyExtraData : public NI_TEXT_KEY_EXTRA_DATA_PARENT {
public:
	NIFLIB_API NiTextKeyExtraData();
	NIFLIB_API ~NiTextKeyExtraData();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	//--BEGIN MISC CUSTOM CODE--//

	/*! Retrieves the text note key data.
	 * \return A vector containing Key<string> data which specify text note over time.
	 * \sa NiKeyframeData::SetKeys, Key
	 */
	NIFLIB_API vector< Key<string> > GetKeys() const;

	/*! Sets the text note key data.
	 * \param keys A vector containing new Key<string> data which will replace any existing data.
	 * \sa NiKeyframeData::GetKeys, Key
	 */
	NIFLIB_API void SetKeys( vector< Key<string> > const & keys );

	//TODO:  There is an unknown member in this class

	//--END CUSTOM CODE--//

protected:
	NI_TEXT_KEY_EXTRA_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
