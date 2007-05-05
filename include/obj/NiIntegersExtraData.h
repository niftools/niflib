/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIINTEGERSEXTRADATA_H_
#define _NIINTEGERSEXTRADATA_H_

#include "NiExtraData.h"
namespace Niflib {

//#include "../gen/obj_defines.h"

class NiIntegersExtraData;
typedef Ref<NiIntegersExtraData> NiIntegersExtraDataRef;

/*!
 * NiIntegersExtraData - Integers data.
 */

class NiIntegersExtraData : public NI_INTEGERS_EXTRA_DATA_PARENT {
public:
	NIFLIB_API NiIntegersExtraData();
	NIFLIB_API ~NiIntegersExtraData();
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
	 * Retrieves the integer values stored in this object.
	 * \return The integer values stored in this object.
	 */
	NIFLIB_API vector<unsigned int> GetData() const;

	/*!
	 * Sets the integer values stored in this object.
	 * \param[in] value The new integer values to store in this object.
	 */
	NIFLIB_API void SetData( const vector<unsigned int > & value );

protected:
	NI_INTEGERS_EXTRA_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
