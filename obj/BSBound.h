/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BSBOUND_H_
#define _BSBOUND_H_

#include "xml_extract.h"
#include B_S_BOUND_INCLUDE

/*
 * BSBound
 */

class BSBound;
typedef Ref<BSBound> BSBoundRef;

class BSBound : public B_S_BOUND_PARENT {
public:
	BSBound();
	~BSBound();
	//Run-Time Type Information
	static const Type TYPE;
	virtual const Type & GetType() const { return TYPE; };
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
private:
	B_S_BOUND_MEMBERS
};
#endif
