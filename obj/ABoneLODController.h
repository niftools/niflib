/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _ABONELODCONTROLLER_H_
#define _ABONELODCONTROLLER_H_

#include "xml_extract.h"
#include A_BONE_L_O_D_CONTROLLER_INCLUDE

/*
 * ABoneLODController
 */

class ABoneLODController;
typedef Ref<ABoneLODController> ABoneLODControllerRef;

class ABoneLODController : public A_BONE_L_O_D_CONTROLLER_PARENT {
public:
	ABoneLODController();
	~ABoneLODController();
	//Run-Time Type Information
	static const Type TYPE;
	virtual const Type & GetType() const { return TYPE; };
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
private:
	A_BONE_L_O_D_CONTROLLER_MEMBERS
};
#endif
