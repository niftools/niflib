/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPARTICLEGROWFADE_H_
#define _NIPARTICLEGROWFADE_H_

#include "AParticleModifier.h"
namespace Niflib {


//#include "../gen/obj_defines.h"

class NiParticleGrowFade;
typedef Ref<NiParticleGrowFade> NiParticleGrowFadeRef;

/*!
 * NiParticleGrowFade - This particle system modifier controls the
 * particle size. If it is present the particles start with size 0.0 .
 * Then they grow to their original size and stay there until they fade
 * to zero size again at the end of their lifetime cycle.
 */

class NiParticleGrowFade : public NI_PARTICLE_GROW_FADE_PARENT {
public:
	NIFLIB_API NiParticleGrowFade();
	NIFLIB_API ~NiParticleGrowFade();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

protected:
	NI_PARTICLE_GROW_FADE_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
