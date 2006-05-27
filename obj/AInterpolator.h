/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _AINTERPOLATOR_H_
#define _AINTERPOLATOR_H_

#include "xml_extract.h"
#include A_INTERPOLATOR_INCLUDE

/*
 * AInterpolator
 */

class AInterpolator;
typedef Ref<AInterpolator> AInterpolatorRef;

class AInterpolator : public A_INTERPOLATOR_PARENT {
public:
	AInterpolator();
	~AInterpolator();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version );
private:
	A_INTERPOLATOR_MEMBERS
};
#endif
