/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPSYSGRAVITYMODIFIER_H_
#define _NIPSYSGRAVITYMODIFIER_H_

#include "NiPSysModifier.h"

// Forward define of referenced blocks
#include "Ref.h"
class NiNode;

#include "gen/obj_defines.h"

/*
 * NiPSysGravityModifier
 */

class NiPSysGravityModifier;
typedef Ref<NiPSysGravityModifier> NiPSysGravityModifierRef;

class NiPSysGravityModifier : public NI_P_SYS_GRAVITY_MODIFIER_PARENT {
public:
	NiPSysGravityModifier();
	~NiPSysGravityModifier();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_P_SYS_GRAVITY_MODIFIER_MEMBERS
};

#endif
