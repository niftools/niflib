/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIMESHPARTICLESYSTEM_H_
#define _NIMESHPARTICLESYSTEM_H_

#include "xml_extract.h"
#include NI_MESH_PARTICLE_SYSTEM_INCLUDE

/*
 * NiMeshParticleSystem
 */

class NiMeshParticleSystem;
typedef Ref<NiMeshParticleSystem> NiMeshParticleSystemRef;

class NiMeshParticleSystem : public NI_MESH_PARTICLE_SYSTEM_PARENT {
public:
	NiMeshParticleSystem();
	~NiMeshParticleSystem();
	//Run-Time Type Information
	static const Type TYPE;
	virtual const Type & GetType() const { return TYPE; };
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
private:
	NI_MESH_PARTICLE_SYSTEM_MEMBERS
};
#endif
