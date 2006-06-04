/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPSYSDATA_H_
#define _NIPSYSDATA_H_

#include "APSysData.h"

#include "gen/obj_defines.h"

/*
 * NiPSysData
 */

class NiPSysData;
typedef Ref<NiPSysData> NiPSysDataRef;

class NiPSysData : public NI_P_SYS_DATA_PARENT {
public:
	NiPSysData();
	~NiPSysData();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_P_SYS_DATA_MEMBERS
};

#endif
