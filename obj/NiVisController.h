/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIVISCONTROLLER_H_
#define _NIVISCONTROLLER_H_

#include "NiSingleInterpolatorController.h"
#include "Ref.h"
#include "obj/NiVisData.h"

#include "gen/obj_defines.h"

/*
 * NiVisController
 */

class NiVisController;
typedef Ref<NiVisController> NiVisControllerRef;

class NiVisController : public NI_VIS_CONTROLLER_PARENT {
public:
  NiVisController();
  ~NiVisController();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  NI_VIS_CONTROLLER_MEMBERS
};

#endif
