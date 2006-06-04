/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPSYSEMITTERCTLR_H_
#define _NIPSYSEMITTERCTLR_H_

#include "APSysCtlr.h"

// Forward define of referenced blocks
#include "Ref.h"
class NiInterpolator;

#include "gen/obj_defines.h"

class NiPSysEmitterCtlr;
typedef Ref<NiPSysEmitterCtlr> NiPSysEmitterCtlrRef;

/*!
 * NiPSysEmitterCtlr - Particle system emitter controller.
 */

class NiPSysEmitterCtlr : public NI_P_SYS_EMITTER_CTLR_PARENT {
public:
	NiPSysEmitterCtlr();
	~NiPSysEmitterCtlr();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_P_SYS_EMITTER_CTLR_MEMBERS
};

#endif
