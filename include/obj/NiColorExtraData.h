/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _NICOLOREXTRADATA_H_
#define _NICOLOREXTRADATA_H_

#include "NiExtraData.h"
namespace Niflib {


//#include "../gen/obj_defines.h"

class NiColorExtraData;
typedef Ref<NiColorExtraData> NiColorExtraDataRef;

/*!
 * NiColorExtraData - Unknown.
 */

class NiColorExtraData : public NI_COLOR_EXTRA_DATA_PARENT {
public:
	NIFLIB_API NiColorExtraData();
	NIFLIB_API ~NiColorExtraData();
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

	/*!
	 * Retrieves the RGBA color value stored in this object.
	 * \return The RGBA color value stored in this object.
	 */
	NIFLIB_API Color4 GetData() const;

	/*!
	 * Sets the RGBA color value stored in this object.
	 * \param[in] n The new RGBA color value to store in this object.
	 */
	NIFLIB_API void SetData( const Color4 & n );

	//--END CUSTOM CODE--//

protected:
	NI_COLOR_EXTRA_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
