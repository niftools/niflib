/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPARTICLEMESHESDATA_H_
#define _NIPARTICLEMESHESDATA_H_

#include "NiParticlesData.h"

// Forward define of referenced blocks
#include "../Ref.h"
class NiTriBasedGeom;

#include "../gen/obj_defines.h"

class NiParticleMeshesData;
typedef Ref<NiParticleMeshesData> NiParticleMeshesDataRef;

/*!
 * NiParticleMeshesData - Particle meshes data.
 */

class NiParticleMeshesData : public NI_PARTICLE_MESHES_DATA_PARENT {
public:
	NiParticleMeshesData();
	~NiParticleMeshesData();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_PARTICLE_MESHES_DATA_MEMBERS
};

#endif
