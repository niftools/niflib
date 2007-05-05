/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIINTEGEREXTRADATA_H_
#define _NIINTEGEREXTRADATA_H_

#include "NiExtraData.h"
namespace Niflib {


//#include "../gen/obj_defines.h"

class NiIntegerExtraData;
typedef Ref<NiIntegerExtraData> NiIntegerExtraDataRef;

/*!
 * NiIntegerExtraData - Extra integer data.
 */

class NiIntegerExtraData : public NI_INTEGER_EXTRA_DATA_PARENT {
public:
	NIFLIB_API NiIntegerExtraData();
	NIFLIB_API ~NiIntegerExtraData();
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
	 * Retrieves the integer value stored in this object.
	 * \return The integer value stored in this object.
	 */
	NIFLIB_API unsigned int GetData() const;

	/*!
	 * Sets the integer value stored in this object.
	 * \param[in] n The new integer value to store in this object.
	 */
	NIFLIB_API void SetData( unsigned int n );

protected:
	NI_INTEGER_EXTRA_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
