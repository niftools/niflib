/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPSYSEMITTERDECLINATIONCTLR_H_
#define _NIPSYSEMITTERDECLINATIONCTLR_H_

#include "APSysCtlr.h"

#include "gen/obj_defines.h"

class NiPSysEmitterDeclinationCtlr;
typedef Ref<NiPSysEmitterDeclinationCtlr> NiPSysEmitterDeclinationCtlrRef;

/*!
 * NiPSysEmitterDeclinationCtlr - Unknown.
 */

class NiPSysEmitterDeclinationCtlr : public NI_P_SYS_EMITTER_DECLINATION_CTLR_PARENT {
public:
	NiPSysEmitterDeclinationCtlr();
	~NiPSysEmitterDeclinationCtlr();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_P_SYS_EMITTER_DECLINATION_CTLR_MEMBERS
};

#endif
