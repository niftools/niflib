/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPARTICLESYSTEMCONTROLLER_H_
#define _NIPARTICLESYSTEMCONTROLLER_H_

#include "gen/obj_defines.h"
#include NI_PARTICLE_SYSTEM_CONTROLLER_INCLUDE

/*
 * NiParticleSystemController
 */

class NiParticleSystemController;
typedef Ref<NiParticleSystemController> NiParticleSystemControllerRef;

class NiParticleSystemController : public NI_PARTICLE_SYSTEM_CONTROLLER_PARENT {
public:
  NiParticleSystemController();
  ~NiParticleSystemController();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  NI_PARTICLE_SYSTEM_CONTROLLER_MEMBERS
};

#endif
