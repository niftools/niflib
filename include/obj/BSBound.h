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

class NIFLIB_API BSBound : public B_S_BOUND_PARENT {
public:
	BSBound();
	~BSBound();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	/*!
	 * Center of the bounding box.
	 */
	Vector3 GetCenter() const;
	void SetCenter( const Vector3 & value );

	/*!
	 * Dimensions of the bounding box from center.
	 */
	Vector3 GetDimensions() const;
	void SetDimensions( const Vector3 & value );

protected:
	B_S_BOUND_MEMBERS
private:
	void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
