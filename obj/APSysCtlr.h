/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _APSYSCTLR_H_
#define _APSYSCTLR_H_

#include "xml_extract.h"
#include A_P_SYS_CTLR_INCLUDE

/*
 * APSysCtlr
 */

class APSysCtlr;
typedef Ref<APSysCtlr> APSysCtlrRef;

class APSysCtlr : public A_P_SYS_CTLR_PARENT {
public:
	APSysCtlr();
	~APSysCtlr();
	//Run-Time Type Information
	static const Type TYPE;
	virtual const Type & GetType() const { return TYPE; };
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
private:
	A_P_SYS_CTLR_MEMBERS
};
#endif
