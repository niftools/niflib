/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPSYSRESETONLOOPCTLR_H_
#define _NIPSYSRESETONLOOPCTLR_H_

#include "NiTimeController.h"

#include "../gen/obj_defines.h"

class NiPSysResetOnLoopCtlr;
typedef Ref<NiPSysResetOnLoopCtlr> NiPSysResetOnLoopCtlrRef;

/*!
 * NiPSysResetOnLoopCtlr - Unknown.
 */

class NiPSysResetOnLoopCtlr : public NI_P_SYS_RESET_ON_LOOP_CTLR_PARENT {
public:
	NiPSysResetOnLoopCtlr();
	~NiPSysResetOnLoopCtlr();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_P_SYS_RESET_ON_LOOP_CTLR_MEMBERS
};

#endif
