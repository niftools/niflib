/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPSYSCOLLIDERMANAGER_H_
#define _NIPSYSCOLLIDERMANAGER_H_

#include "NiPSysModifier.h"

// Forward define of referenced blocks
#include "Ref.h"
class NiPSysPlanarCollider;

#include "gen/obj_defines.h"

/*
 * NiPSysColliderManager
 */

class NiPSysColliderManager;
typedef Ref<NiPSysColliderManager> NiPSysColliderManagerRef;

class NiPSysColliderManager : public NI_P_SYS_COLLIDER_MANAGER_PARENT {
public:
	NiPSysColliderManager();
	~NiPSysColliderManager();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_P_SYS_COLLIDER_MANAGER_MEMBERS
};

#endif
