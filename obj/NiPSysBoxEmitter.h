/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPSYSBOXEMITTER_H_
#define _NIPSYSBOXEMITTER_H_

#include "NiPSysVolumeEmitter.h"

#include "gen/obj_defines.h"

/*
 * NiPSysBoxEmitter
 */

class NiPSysBoxEmitter;
typedef Ref<NiPSysBoxEmitter> NiPSysBoxEmitterRef;

class NiPSysBoxEmitter : public NI_P_SYS_BOX_EMITTER_PARENT {
public:
  NiPSysBoxEmitter();
  ~NiPSysBoxEmitter();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  NI_P_SYS_BOX_EMITTER_MEMBERS
};

#endif
