/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _ABSPLINECOMPINTERPOLATOR_H_
#define _ABSPLINECOMPINTERPOLATOR_H_

#include "xml_extract.h"
#include A_B_SPLINE_COMP_INTERPOLATOR_INCLUDE

/*
 * ABSplineCompInterpolator
 */

class ABSplineCompInterpolator;
typedef Ref<ABSplineCompInterpolator> ABSplineCompInterpolatorRef;

class ABSplineCompInterpolator : public A_B_SPLINE_COMP_INTERPOLATOR_PARENT {
public:
	ABSplineCompInterpolator();
	~ABSplineCompInterpolator();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version );
private:
	A_B_SPLINE_COMP_INTERPOLATOR_MEMBERS
};
#endif
