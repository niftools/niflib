/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPARTICLEGROWFADE_H_
#define _NIPARTICLEGROWFADE_H_

#include "AParticleModifier.h"

#include "gen/obj_defines.h"

class NiParticleGrowFade;
typedef Ref<NiParticleGrowFade> NiParticleGrowFadeRef;

/*!
 * NiParticleGrowFade - This particle system modifier controls the
 * particle size. If it is present the particles start with size 0.0 .
 * Then they grow to their original size and stay there until they fade
 * to zero size again at the end of their lifetime cycle.
 */

class NiParticleGrowFade : public NI_PARTICLE_GROW_FADE_PARENT {
public:
	NiParticleGrowFade();
	~NiParticleGrowFade();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_PARTICLE_GROW_FADE_MEMBERS
};

#endif
