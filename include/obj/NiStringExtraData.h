/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISTRINGEXTRADATA_H_
#define _NISTRINGEXTRADATA_H_

#include "NiExtraData.h"
namespace Niflib {


//#include "../gen/obj_defines.h"

class NiStringExtraData;
typedef Ref<NiStringExtraData> NiStringExtraDataRef;

/*!
 * NiStringExtraData - Apparently commands for an optimizer instructing
 * it to keep things it would normally discard. Also refers to NiNode
 * objects (through their name) in animation .kf files.
 */

class NiStringExtraData : public NI_STRING_EXTRA_DATA_PARENT {
public:
	NIFLIB_API NiStringExtraData();
	NIFLIB_API ~NiStringExtraData();
	//Run-Time Type Information
	NIFLIB_API static const Type & TypeConst();
private:
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Retrieves the string value stored in this object.
	 * \return The string value stored in this object.
	 */
	NIFLIB_API string GetData() const;

	/*!
	 * Sets the string value stored in this object.
	 * \param[in] n The new string value to store in this object.
	 */
	NIFLIB_API void SetData( const string & n );

protected:
	NI_STRING_EXTRA_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
