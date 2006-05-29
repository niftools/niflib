/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _APARTICLEMODIFIER_H_
#define _APARTICLEMODIFIER_H_

#include "xml_extract.h"
#include A_PARTICLE_MODIFIER_INCLUDE

/*
 * AParticleModifier
 */

class AParticleModifier;
typedef Ref<AParticleModifier> AParticleModifierRef;

class AParticleModifier : public A_PARTICLE_MODIFIER_PARENT {
public:
	AParticleModifier();
	~AParticleModifier();
	//Run-Time Type Information
	static const Type TYPE;
	virtual const Type & GetType() const { return TYPE; };
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
private:
	A_PARTICLE_MODIFIER_MEMBERS
};
#endif
