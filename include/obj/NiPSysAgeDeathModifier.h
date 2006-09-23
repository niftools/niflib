/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPSYSAGEDEATHMODIFIER_H_
#define _NIPSYSAGEDEATHMODIFIER_H_

#include "NiPSysModifier.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class NiPSysSpawnModifier;

#include "../gen/obj_defines.h"

class NiPSysAgeDeathModifier;
typedef Ref<NiPSysAgeDeathModifier> NiPSysAgeDeathModifierRef;

/*!
 * NiPSysAgeDeathModifier - Unknown particle modifier.
 */

class NIFLIB_API NiPSysAgeDeathModifier : public NI_P_SYS_AGE_DEATH_MODIFIER_PARENT {
public:
	NiPSysAgeDeathModifier();
	~NiPSysAgeDeathModifier();
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
	NI_P_SYS_AGE_DEATH_MODIFIER_MEMBERS
private:
	void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
