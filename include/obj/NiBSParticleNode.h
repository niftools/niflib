/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIBSPARTICLENODE_H_
#define _NIBSPARTICLENODE_H_

#include "NiNode.h"
namespace Niflib {

#include "../gen/obj_defines.h"

class NiBSParticleNode;
typedef Ref<NiBSParticleNode> NiBSParticleNodeRef;

/*!
 * NiBSParticleNode - Unknown.
 */

class NIFLIB_API NiBSParticleNode : public NI_B_S_PARTICLE_NODE_PARENT {
public:
	NiBSParticleNode();
	~NiBSParticleNode();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

protected:
	NI_B_S_PARTICLE_NODE_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
