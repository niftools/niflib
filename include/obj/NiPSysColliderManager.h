/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPSYSCOLLIDERMANAGER_H_
#define _NIPSYSCOLLIDERMANAGER_H_

#include "NiPSysModifier.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiPSysPlanarCollider;

//#include "../gen/obj_defines.h"

class NiPSysColliderManager;
typedef Ref<NiPSysColliderManager> NiPSysColliderManagerRef;

/*!
 * NiPSysColliderManager - Unknown.
 */

class NiPSysColliderManager : public NI_P_SYS_COLLIDER_MANAGER_PARENT {
public:
	NIFLIB_API NiPSysColliderManager();
	NIFLIB_API ~NiPSysColliderManager();
	//Run-Time Type Information
	NIFLIB_API static const Type & TypeConst();
private:
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

protected:
	NI_P_SYS_COLLIDER_MANAGER_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
