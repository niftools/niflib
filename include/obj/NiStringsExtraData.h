/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISTRINGSEXTRADATA_H_
#define _NISTRINGSEXTRADATA_H_

#include "NiExtraData.h"
namespace Niflib {


//#include "../gen/obj_defines.h"

class NiStringsExtraData;
typedef Ref<NiStringsExtraData> NiStringsExtraDataRef;

/*!
 * NiStringsExtraData - List of strings; for example, a list of all bone
 * names.
 */

class NiStringsExtraData : public NI_STRINGS_EXTRA_DATA_PARENT {
public:
	NIFLIB_API NiStringsExtraData();
	NIFLIB_API ~NiStringsExtraData();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Retrieves the string values stored in this object.
	 * \return The string values stored in this object.
	 */
	NIFLIB_API vector<string> GetData() const;

	/*!
	 * Sets the string values stored in this object.
	 * \param[in] n The new string values to store in this object.
	 */
	NIFLIB_API void SetData( const vector<string> & n );

protected:
	NI_STRINGS_EXTRA_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
