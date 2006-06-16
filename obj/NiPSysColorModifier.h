/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPSYSCOLORMODIFIER_H_
#define _NIPSYSCOLORMODIFIER_H_

#include "NiPSysModifier.h"

// Forward define of referenced blocks
#include "../Ref.h"
class NiColorData;

#include "../gen/obj_defines.h"

class NiPSysColorModifier;
typedef Ref<NiPSysColorModifier> NiPSysColorModifierRef;

/*!
 * NiPSysColorModifier - Unknown particle modifier.
 */

class NIFLIB_API NiPSysColorModifier : public NI_P_SYS_COLOR_MODIFIER_PARENT {
public:
	NiPSysColorModifier();
	~NiPSysColorModifier();
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
	NI_P_SYS_COLOR_MODIFIER_MEMBERS
};

#endif
