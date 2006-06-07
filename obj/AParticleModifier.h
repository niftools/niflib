/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _APARTICLEMODIFIER_H_
#define _APARTICLEMODIFIER_H_

#include "NiObject.h"

// Forward define of referenced blocks
#include "../Ref.h"
class NiParticleSystemController;

#include "../gen/obj_defines.h"

class AParticleModifier;
typedef Ref<AParticleModifier> AParticleModifierRef;

/*!
 * AParticleModifier - A particle system modifier.
 */

class DLLEXPORT AParticleModifier : public A_PARTICLE_MODIFIER_PARENT {
public:
	AParticleModifier();
	~AParticleModifier();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	A_PARTICLE_MODIFIER_MEMBERS
};

#endif
