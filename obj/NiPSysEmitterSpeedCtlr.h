/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPSYSEMITTERSPEEDCTLR_H_
#define _NIPSYSEMITTERSPEEDCTLR_H_

#include "APSysCtlr.h"

#include "../gen/obj_defines.h"

class NiPSysEmitterSpeedCtlr;
typedef Ref<NiPSysEmitterSpeedCtlr> NiPSysEmitterSpeedCtlrRef;

/*!
 * NiPSysEmitterSpeedCtlr - Unknown.
 */

class DLLEXPORT NiPSysEmitterSpeedCtlr : public NI_P_SYS_EMITTER_SPEED_CTLR_PARENT {
public:
	NiPSysEmitterSpeedCtlr();
	~NiPSysEmitterSpeedCtlr();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_P_SYS_EMITTER_SPEED_CTLR_MEMBERS
};

#endif
