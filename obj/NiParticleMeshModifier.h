/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPARTICLEMESHMODIFIER_H_
#define _NIPARTICLEMESHMODIFIER_H_

#include "AParticleModifier.h"

// Forward define of referenced blocks
#include "Ref.h"
class NiTriBasedGeom;

#include "gen/obj_defines.h"

/*
 * NiParticleMeshModifier
 */

class NiParticleMeshModifier;
typedef Ref<NiParticleMeshModifier> NiParticleMeshModifierRef;

class NiParticleMeshModifier : public NI_PARTICLE_MESH_MODIFIER_PARENT {
public:
	NiParticleMeshModifier();
	~NiParticleMeshModifier();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_PARTICLE_MESH_MODIFIER_MEMBERS
};

#endif
