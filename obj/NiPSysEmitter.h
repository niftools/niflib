/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPSYSEMITTER_H_
#define _NIPSYSEMITTER_H_

#include "gen/obj_defines.h"
#include NI_P_SYS_EMITTER_INCLUDE

/*
 * NiPSysEmitter
 */

class NiPSysEmitter;
typedef Ref<NiPSysEmitter> NiPSysEmitterRef;

class NiPSysEmitter : public NI_P_SYS_EMITTER_PARENT {
public:
  NiPSysEmitter();
  ~NiPSysEmitter();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  NI_P_SYS_EMITTER_MEMBERS
};

#endif
