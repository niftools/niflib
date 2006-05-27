/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIBONELODCONTROLLER_H_
#define _NIBONELODCONTROLLER_H_

#include "xml_extract.h"
#include NI_BONE_L_O_D_CONTROLLER_INCLUDE

/*
 * NiBoneLODController
 */

class NiBoneLODController;
typedef Ref<NiBoneLODController> NiBoneLODControllerRef;

class NiBoneLODController : public NI_BONE_L_O_D_CONTROLLER_PARENT {
public:
	NiBoneLODController();
	~NiBoneLODController();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version );
private:
	NI_BONE_L_O_D_CONTROLLER_MEMBERS
};
#endif
