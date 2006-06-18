/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPARTICLECOLORMODIFIER_H_
#define _NIPARTICLECOLORMODIFIER_H_

#include "AParticleModifier.h"

// Include structures
#include "../Ref.h"
namespace NifLib {

// Forward define of referenced blocks
class NiColorData;

#include "../gen/obj_defines.h"

class NiParticleColorModifier;
typedef Ref<NiParticleColorModifier> NiParticleColorModifierRef;

/*!
 * NiParticleColorModifier - Unknown.
 */

class NIFLIB_API NiParticleColorModifier : public NI_PARTICLE_COLOR_MODIFIER_PARENT {
public:
	NiParticleColorModifier();
	~NiParticleColorModifier();
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
	NI_PARTICLE_COLOR_MODIFIER_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
