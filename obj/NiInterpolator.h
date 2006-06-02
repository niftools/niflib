/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIINTERPOLATOR_H_
#define _NIINTERPOLATOR_H_

#include "gen/obj_defines.h"
#include NI_INTERPOLATOR_INCLUDE

/*
 * NiInterpolator
 */

class NiInterpolator;
typedef Ref<NiInterpolator> NiInterpolatorRef;

class NiInterpolator : public NI_INTERPOLATOR_PARENT {
public:
  NiInterpolator();
  ~NiInterpolator();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  NI_INTERPOLATOR_MEMBERS
};

#endif
