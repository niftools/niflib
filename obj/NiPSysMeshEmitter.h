/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPSYSMESHEMITTER_H_
#define _NIPSYSMESHEMITTER_H_

#include "NiPSysEmitter.h"

// Forward define of referenced blocks
#include "../Ref.h"
class NiTriBasedGeom;

#include "../gen/obj_defines.h"

class NiPSysMeshEmitter;
typedef Ref<NiPSysMeshEmitter> NiPSysMeshEmitterRef;

/*!
 * NiPSysMeshEmitter - Unknown.
 */

class NiPSysMeshEmitter : public NI_P_SYS_MESH_EMITTER_PARENT {
public:
	NiPSysMeshEmitter();
	~NiPSysMeshEmitter();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_P_SYS_MESH_EMITTER_MEMBERS
};

#endif
