/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIBSPARRAYCONTROLLER_H_
#define _NIBSPARRAYCONTROLLER_H_

#include "gen/obj_defines.h"
#include NI_B_S_P_ARRAY_CONTROLLER_INCLUDE

/*
 * NiBSPArrayController
 */

class NiBSPArrayController;
typedef Ref<NiBSPArrayController> NiBSPArrayControllerRef;

class NiBSPArrayController : public NI_B_S_P_ARRAY_CONTROLLER_PARENT {
public:
  NiBSPArrayController();
  ~NiBSPArrayController();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  NI_B_S_P_ARRAY_CONTROLLER_MEMBERS
};

#endif
