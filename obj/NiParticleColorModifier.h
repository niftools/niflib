/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPARTICLECOLORMODIFIER_H_
#define _NIPARTICLECOLORMODIFIER_H_

#include "AParticleModifier.h"

// Forward define of referenced blocks
#include "Ref.h"
class NiColorData;

#include "gen/obj_defines.h"

/*
 * NiParticleColorModifier
 */

class NiParticleColorModifier;
typedef Ref<NiParticleColorModifier> NiParticleColorModifierRef;

class NiParticleColorModifier : public NI_PARTICLE_COLOR_MODIFIER_PARENT {
public:
	NiParticleColorModifier();
	~NiParticleColorModifier();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_PARTICLE_COLOR_MODIFIER_MEMBERS
};

#endif
