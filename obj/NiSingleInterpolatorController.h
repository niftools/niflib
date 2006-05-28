/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _ASINGLEINTERPOLATORCONTROLLER_H_
#define _ASINGLEINTERPOLATORCONTROLLER_H_

#include "xml_extract.h"
#include A_SINGLE_INTERPOLATOR_CONTROLLER_INCLUDE

/*
 * NiSingleInterpolatorController
 */

class NiSingleInterpolatorController;
typedef Ref<NiSingleInterpolatorController> NiSingleInterpolatorControllerRef;

class NiSingleInterpolatorController : public A_SINGLE_INTERPOLATOR_CONTROLLER_PARENT {
public:
	NiSingleInterpolatorController();
	~NiSingleInterpolatorController();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version );
private:
	A_SINGLE_INTERPOLATOR_CONTROLLER_MEMBERS
};
#endif
