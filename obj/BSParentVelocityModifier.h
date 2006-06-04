/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BSPARENTVELOCITYMODIFIER_H_
#define _BSPARENTVELOCITYMODIFIER_H_

#include "NiPSysModifier.h"

#include "gen/obj_defines.h"

/*
 * BSParentVelocityModifier
 */

class BSParentVelocityModifier;
typedef Ref<BSParentVelocityModifier> BSParentVelocityModifierRef;

class BSParentVelocityModifier : public B_S_PARENT_VELOCITY_MODIFIER_PARENT {
public:
	BSParentVelocityModifier();
	~BSParentVelocityModifier();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	B_S_PARENT_VELOCITY_MODIFIER_MEMBERS
};

#endif
