/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIFLIPCONTROLLER_H_
#define _NIFLIPCONTROLLER_H_

#include "NiSingleInterpolatorController.h"
#include "Ref.h"
#include "obj/NiSourceTexture.h"

#include "gen/obj_defines.h"

/*
 * NiFlipController
 */

class NiFlipController;
typedef Ref<NiFlipController> NiFlipControllerRef;

class NiFlipController : public NI_FLIP_CONTROLLER_PARENT {
public:
	NiFlipController();
	~NiFlipController();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual const Type & GetType() const;
protected:
	NI_FLIP_CONTROLLER_MEMBERS
};

#endif
