/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIDYNAMICEFFECT_H_
#define _NIDYNAMICEFFECT_H_

#include "NiAVObject.h"
#include "Ref.h"
#include "obj/NiAVObject.h"

#include "gen/obj_defines.h"

/*
 * NiDynamicEffect
 */

class NiDynamicEffect;
typedef Ref<NiDynamicEffect> NiDynamicEffectRef;

class NiDynamicEffect : public NI_DYNAMIC_EFFECT_PARENT {
public:
	NiDynamicEffect();
	~NiDynamicEffect();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual const Type & GetType() const;
protected:
	NI_DYNAMIC_EFFECT_MEMBERS
};

#endif
