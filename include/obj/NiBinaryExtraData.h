/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIBINARYEXTRADATA_H_
#define _NIBINARYEXTRADATA_H_

#include "NiExtraData.h"
// Include structures
#include "../gen/ByteArray.h"
namespace Niflib {

//#include "../gen/obj_defines.h"

class NiBinaryExtraData;
typedef Ref<NiBinaryExtraData> NiBinaryExtraDataRef;

/*!
 * NiBinaryExtraData - Binary extra data object. Used to store normals and
 * binormals in Oblivion.
 */

class NiBinaryExtraData : public NI_BINARY_EXTRA_DATA_PARENT {
public:
	NIFLIB_API NiBinaryExtraData();
	NIFLIB_API ~NiBinaryExtraData();
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
	 * Retrieves the binary data stored in this object.
	 * \return The binary data stored in this object.
	 */
	NIFLIB_API vector<byte> GetData() const;

	/*!
	 * Sets the binary data stored in this object.  Removes any previous data.
	 * \param[in] n The new binary data to store in this object.
	 */
	NIFLIB_API void SetData( const vector<byte> & n );

protected:
	NI_BINARY_EXTRA_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
