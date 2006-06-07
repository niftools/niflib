/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIEXTRADATA_H_
#define _NIEXTRADATA_H_

#include "NiObject.h"

#include "../gen/obj_defines.h"

class NiExtraData;
typedef Ref<NiExtraData> NiExtraDataRef;

/*!
 * NiExtraData - A generic extra data block.
 */

class DLLEXPORT NiExtraData : public NI_EXTRA_DATA_PARENT {
public:
	NiExtraData();
	~NiExtraData();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	/*! Returns a reference to the next extra data used in early version NIF
	 * files which store extra data in a linked list.  This function should
	 * only be called by NiObjectNET as it is not always meaningful.
	 * \return A reference to the next extra data in early version NIF files.  May not always be meaningful.
	 */
	NiExtraDataRef GetNextExtraData() const;

	/*! Sets the next extra data in early version NIF files which store extra
	 * data in a linked list.  This function should only be called by
	 * NiObjectNET.
	 * \param obj A reference to the object to set as the one after this in the chain.
	 */
	void SetNextExtraData( const NiExtraDataRef & obj );

	/*! Retrieve the name of this NiExtraData object.  Names are only stored
	 * in later version NIF files so this may not be necessary depending on
	 * the target version.
	 * \return The name of this NiExtraData object.
	 */
	string GetName();

	/*! Sets the name of this NiExtraData object.  Will only be written to later
	 * version NIF files.
	 * \param new_name The new name for this NiExtraData object.
	 */
	void SetName( string & new_name );

	/*!
	 * Formats a human readable string that includes the type of the object
	 * \return A string in the form:  address(type) {name}
	 */
	virtual string GetIDString();

protected:
	NI_EXTRA_DATA_MEMBERS
};

#endif
