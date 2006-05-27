/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIBSPARTICLENODE_H_
#define _NIBSPARTICLENODE_H_

#include "xml_extract.h"
#include NI_B_S_PARTICLE_NODE_INCLUDE

/*
 * NiBSParticleNode
 */

class NiBSParticleNode;
typedef Ref<NiBSParticleNode> NiBSParticleNodeRef;

class NiBSParticleNode : public NI_B_S_PARTICLE_NODE_PARENT {
public:
	NiBSParticleNode();
	~NiBSParticleNode();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version );
private:
	NI_B_S_PARTICLE_NODE_MEMBERS
};
#endif
