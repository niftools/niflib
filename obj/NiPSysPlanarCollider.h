/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPSYSPLANARCOLLIDER_H_
#define _NIPSYSPLANARCOLLIDER_H_

#include "NiObject.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class NiPSysSpawnModifier;
class NiObject;
class NiNode;

#include "../gen/obj_defines.h"

class NiPSysPlanarCollider;
typedef Ref<NiPSysPlanarCollider> NiPSysPlanarColliderRef;

/*!
 * NiPSysPlanarCollider - Unknown.
 */

class NIFLIB_API NiPSysPlanarCollider : public NI_P_SYS_PLANAR_COLLIDER_PARENT {
public:
	NiPSysPlanarCollider();
	~NiPSysPlanarCollider();
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
	NI_P_SYS_PLANAR_COLLIDER_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
