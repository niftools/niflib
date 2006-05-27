/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPSYSRESETONLOOPCTLR_H_
#define _NIPSYSRESETONLOOPCTLR_H_

#include "xml_extract.h"
#include NI_P_SYS_RESET_ON_LOOP_CTLR_INCLUDE

/*
 * NiPSysResetOnLoopCtlr
 */

class NiPSysResetOnLoopCtlr;
typedef Ref<NiPSysResetOnLoopCtlr> NiPSysResetOnLoopCtlrRef;

class NiPSysResetOnLoopCtlr : public NI_P_SYS_RESET_ON_LOOP_CTLR_PARENT {
public:
	NiPSysResetOnLoopCtlr();
	~NiPSysResetOnLoopCtlr();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version );
private:
	NI_P_SYS_RESET_ON_LOOP_CTLR_MEMBERS
};
#endif
