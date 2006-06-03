/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NILOOKATINTERPOLATOR_H_
#define _NILOOKATINTERPOLATOR_H_

#include "NiInterpolator.h"
#include "Ref.h"
#include "obj/NiNode.h"
#include "obj/NiPoint3Interpolator.h"
#include "obj/NiFloatInterpolator.h"

#include "gen/obj_defines.h"

/*
 * NiLookAtInterpolator
 */

class NiLookAtInterpolator;
typedef Ref<NiLookAtInterpolator> NiLookAtInterpolatorRef;

class NiLookAtInterpolator : public NI_LOOK_AT_INTERPOLATOR_PARENT {
public:
  NiLookAtInterpolator();
  ~NiLookAtInterpolator();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  NI_LOOK_AT_INTERPOLATOR_MEMBERS
};

#endif
