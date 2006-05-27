/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NILOOKATCONTROLLER_H_
#define _NILOOKATCONTROLLER_H_

#include "xml_extract.h"
#include NI_LOOK_AT_CONTROLLER_INCLUDE

/*
 * NiLookAtController
 */

class NiLookAtController;
typedef Ref<NiLookAtController> NiLookAtControllerRef;

class NiLookAtController : public NI_LOOK_AT_CONTROLLER_PARENT {
public:
	NiLookAtController();
	~NiLookAtController();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version );
private:
	NI_LOOK_AT_CONTROLLER_MEMBERS
};
#endif
