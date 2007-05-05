/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BSXFLAGS_H_
#define _BSXFLAGS_H_

#include "NiExtraData.h"
namespace Niflib {

//#include "../gen/obj_defines.h"

class BSXFlags;
typedef Ref<BSXFlags> BSXFlagsRef;

/*!
 * BSXFlags - Unknown.
 */

class BSXFlags : public B_S_X_FLAGS_PARENT {
public:
	NIFLIB_API BSXFlags();
	NIFLIB_API ~BSXFlags();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Gets the BSX Flag data.
	 * \return The flag data.
	 */
	NIFLIB_API unsigned int GetFlags() const;

	/*!
	 * Sets the BSX Flag data.
	 * \param[in] value The new flag data.
	 */
	NIFLIB_API void SetFlags( unsigned int value );

protected:
	B_S_X_FLAGS_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
