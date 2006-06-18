/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIMESHPSYSDATA_H_
#define _NIMESHPSYSDATA_H_

#include "APSysData.h"

// Include structures
#include "../Ref.h"
namespace NifLib {

// Forward define of referenced blocks
class NiPSysModifier;
class NiNode;

#include "../gen/obj_defines.h"

class NiMeshPSysData;
typedef Ref<NiMeshPSysData> NiMeshPSysDataRef;

/*!
 * NiMeshPSysData - Particle meshes data.
 */

class NIFLIB_API NiMeshPSysData : public NI_MESH_P_SYS_DATA_PARENT {
public:
	NiMeshPSysData();
	~NiMeshPSysData();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

protected:
	NI_MESH_P_SYS_DATA_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
