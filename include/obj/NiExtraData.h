/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIEXTRADATA_H_
#define _NIEXTRADATA_H_

#include "NiObject.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

//#include "../gen/obj_defines.h"

class NiExtraData;
typedef Ref<NiExtraData> NiExtraDataRef;

/*!
 * NiExtraData - A generic extra data block.
 */

class NiExtraData : public NI_EXTRA_DATA_PARENT {
public:
	NIFLIB_API NiExtraData();
	NIFLIB_API ~NiExtraData();
	//Run-Time Type Information
	NIFLIB_API static const Type & TypeConst();
private:	
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*! Returns a reference to the next extra data used in early version NIF
	 * files which store extra data in a linked list.  This function should
	 * only be called by NiObjectNET as it is not always meaningful.
	 * \return A reference to the next extra data in early version NIF files.  May not always be meaningful.
	 */
	NIFLIB_HIDDEN NiExtraDataRef GetNextExtraData() const;

	/*! Sets the next extra data in early version NIF files which store extra
	 * data in a linked list.  This function should only be called by
	 * NiObjectNET.
	 * \param obj A reference to the object to set as the one after this in the chain.
	 */
	NIFLIB_HIDDEN void SetNextExtraData( const NiExtraDataRef & obj );

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
	NIFLIB_API void SetName( const string & new_name );

	/*!
	 * Formats a human readable string that includes the type of the object
	 * \return A string in the form:  address(type) {name}
	 */
	NIFLIB_API virtual string GetIDString() const;

protected:
	NI_EXTRA_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
