/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPARTICLES_H_
#define _NIPARTICLES_H_

#include "NiTriBasedGeom.h"

#include "../gen/obj_defines.h"

class NiParticles;
typedef Ref<NiParticles> NiParticlesRef;

/*!
 * NiParticles - Generic particle system node.
 */

class NiParticles : public NI_PARTICLES_PARENT {
public:
	NiParticles();
	~NiParticles();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_PARTICLES_MEMBERS
};

#endif
