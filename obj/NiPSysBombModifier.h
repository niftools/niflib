/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPSYSBOMBMODIFIER_H_
#define _NIPSYSBOMBMODIFIER_H_

#include "xml_extract.h"
#include NI_P_SYS_BOMB_MODIFIER_INCLUDE

/*
 * NiPSysBombModifier
 */

class NiPSysBombModifier;
typedef Ref<NiPSysBombModifier> NiPSysBombModifierRef;

class NiPSysBombModifier : public NI_P_SYS_BOMB_MODIFIER_PARENT {
public:
	NiPSysBombModifier();
	~NiPSysBombModifier();
	//Run-Time Type Information
	static const Type TYPE;
	virtual const Type & GetType() const { return TYPE; };
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
private:
	NI_P_SYS_BOMB_MODIFIER_MEMBERS
};
#endif
