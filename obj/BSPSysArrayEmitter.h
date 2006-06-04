/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BSPSYSARRAYEMITTER_H_
#define _BSPSYSARRAYEMITTER_H_

#include "NiPSysVolumeEmitter.h"

#include "gen/obj_defines.h"

/*
 * BSPSysArrayEmitter
 */

class BSPSysArrayEmitter;
typedef Ref<BSPSysArrayEmitter> BSPSysArrayEmitterRef;

class BSPSysArrayEmitter : public B_S_P_SYS_ARRAY_EMITTER_PARENT {
public:
	BSPSysArrayEmitter();
	~BSPSysArrayEmitter();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	B_S_P_SYS_ARRAY_EMITTER_MEMBERS
};

#endif
