/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPARTICLESYSTEMCONTROLLER_H_
#define _NIPARTICLESYSTEMCONTROLLER_H_

#include "NiTimeController.h"

// Include structures
#include "../Ref.h"
#include "../gen/Particle.h"
namespace Niflib {

// Forward define of referenced blocks
class NiObject;
class AParticleModifier;

//#include "../gen/obj_defines.h"

class NiParticleSystemController;
typedef Ref<NiParticleSystemController> NiParticleSystemControllerRef;

/*!
 * NiParticleSystemController - A generic particle system time controller
 * block.
 */

class NiParticleSystemController : public NI_PARTICLE_SYSTEM_CONTROLLER_PARENT {
public:
	NIFLIB_API NiParticleSystemController();
	NIFLIB_API ~NiParticleSystemController();
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

	//TODO:  This controller is not a priority and it has a lot of unknown data.
protected:
	NI_PARTICLE_SYSTEM_CONTROLLER_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
