/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NICONTROLLERMANAGER_H_
#define _NICONTROLLERMANAGER_H_

#include "NiTimeController.h"
#include "Ref.h"
#include "obj/NiControllerSequence.h"
#include "obj/NiDefaultAVObjectPalette.h"

#include "gen/obj_defines.h"

/*
 * NiControllerManager
 */

class NiControllerManager;
typedef Ref<NiControllerManager> NiControllerManagerRef;

class NiControllerManager : public NI_CONTROLLER_MANAGER_PARENT {
public:
	NiControllerManager();
	~NiControllerManager();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual const Type & GetType() const;
protected:
	NI_CONTROLLER_MANAGER_MEMBERS
};

#endif
