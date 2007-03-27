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
	NIFLIB_API static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Center of the bounding box.
	 */
	NIFLIB_API Vector3 GetCenter() const;
	NIFLIB_API void SetCenter( const Vector3 & value );

	/*!
	 * Dimensions of the bounding box from center.
	 */
	NIFLIB_API Vector3 GetDimensions() const;
	NIFLIB_API void SetDimensions( const Vector3 & value );

protected:
	B_S_BOUND_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
