/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BSBOUND_H_
#define _BSBOUND_H_

#include "NiExtraData.h"

#include "../gen/obj_defines.h"

class BSBound;
typedef Ref<BSBound> BSBoundRef;

/*!
 * BSBound - Unknown.
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
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	B_S_BOUND_MEMBERS
};

#endif
