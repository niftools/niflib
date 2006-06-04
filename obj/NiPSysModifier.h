/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPSYSMODIFIER_H_
#define _NIPSYSMODIFIER_H_

#include "NiObject.h"

// Forward define of referenced blocks
#include "Ref.h"
class NiParticleSystem;

#include "gen/obj_defines.h"

/*
 * NiPSysModifier
 */

class NiPSysModifier;
typedef Ref<NiPSysModifier> NiPSysModifierRef;

class NiPSysModifier : public NI_P_SYS_MODIFIER_PARENT {
public:
	NiPSysModifier();
	~NiPSysModifier();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual const Type & GetType() const;
protected:
	NI_P_SYS_MODIFIER_MEMBERS
};

#endif
