/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPSYSGRAVITYMODIFIER_H_
#define _NIPSYSGRAVITYMODIFIER_H_

#include "NiPSysModifier.h"
namespace Niflib {

// Forward define of referenced blocks
class NiNode;

//#include "../gen/obj_defines.h"

class NiPSysGravityModifier;
typedef Ref<NiPSysGravityModifier> NiPSysGravityModifierRef;

/*!
 * NiPSysGravityModifier - Unknown particle system modifier.
 */

class NiPSysGravityModifier : public NI_P_SYS_GRAVITY_MODIFIER_PARENT {
public:
	NIFLIB_API NiPSysGravityModifier();
	NIFLIB_API ~NiPSysGravityModifier();
	//Run-Time Type Information
	NIFLIB_API static const Type & TypeConst();
private:
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

protected:
	NI_P_SYS_GRAVITY_MODIFIER_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
