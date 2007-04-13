/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BSBOUND_H_
#define _BSBOUND_H_

#include "NiExtraData.h"
namespace Niflib {


//#include "../gen/obj_defines.h"

class BSBound;
typedef Ref<BSBound> BSBoundRef;

/*!
 * BSBound - Bethesda-specific collision bounding box for skeletons.
 */

class BSBound : public B_S_BOUND_PARENT {
public:
	NIFLIB_API BSBound();
	NIFLIB_API ~BSBound();
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
	 * Gets the center point of the bounding box.
	 * \return The center point of the bounding box.
	 */
	NIFLIB_API Vector3 GetCenter() const;

	/*!
	 * Sets the center point of the bounding box.
	 * \param[in] value The new center point of the bounding box.
	 */
	NIFLIB_API void SetCenter( const Vector3 & value );

	/*!
	 * Gets the dimensions of the bounding box from center.  The three radii.
	 * \return The radius of the bounding box along each axis.
	 */
	NIFLIB_API Vector3 GetDimensions() const;

	/*!
	 * Gets the dimensions of the bounding box from center.  The three radii.
	 * \param[in] value The new radius of the bounding box along each axis.
	 */
	NIFLIB_API void SetDimensions( const Vector3 & value );

protected:
	B_S_BOUND_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
