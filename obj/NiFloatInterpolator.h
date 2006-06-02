/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIFLOATINTERPOLATOR_H_
#define _NIFLOATINTERPOLATOR_H_

#include "gen/obj_defines.h"
#include NI_FLOAT_INTERPOLATOR_INCLUDE

/*
 * NiFloatInterpolator
 */

class NiFloatInterpolator;
typedef Ref<NiFloatInterpolator> NiFloatInterpolatorRef;

class NiFloatInterpolator : public NI_FLOAT_INTERPOLATOR_PARENT {
public:
  NiFloatInterpolator();
  ~NiFloatInterpolator();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  NI_FLOAT_INTERPOLATOR_MEMBERS
};

#endif
