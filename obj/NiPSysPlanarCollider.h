/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPSYSPLANARCOLLIDER_H_
#define _NIPSYSPLANARCOLLIDER_H_

#include "NiObject.h"
#include "Ref.h"
#include "obj/NiPSysSpawnModifier.h"
#include "obj/NiObject.h"
#include "obj/NiNode.h"
class NiObject;

#include "gen/obj_defines.h"

/*
 * NiPSysPlanarCollider
 */

class NiPSysPlanarCollider;
typedef Ref<NiPSysPlanarCollider> NiPSysPlanarColliderRef;

class NiPSysPlanarCollider : public NI_P_SYS_PLANAR_COLLIDER_PARENT {
public:
	NiPSysPlanarCollider();
	~NiPSysPlanarCollider();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual const Type & GetType() const;
protected:
	NI_P_SYS_PLANAR_COLLIDER_MEMBERS
};

#endif
