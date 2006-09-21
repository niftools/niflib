/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIAUTONORMALPARTICLES_H_
#define _NIAUTONORMALPARTICLES_H_

#include "NiParticles.h"
namespace Niflib {

#include "../gen/obj_defines.h"

class NiAutoNormalParticles;
typedef Ref<NiAutoNormalParticles> NiAutoNormalParticlesRef;

/*!
 * NiAutoNormalParticles - Unknown.
 */

class NIFLIB_API NiAutoNormalParticles : public NI_AUTO_NORMAL_PARTICLES_PARENT {
public:
	NiAutoNormalParticles();
	~NiAutoNormalParticles();
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
	NI_AUTO_NORMAL_PARTICLES_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
