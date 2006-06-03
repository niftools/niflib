/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPATHINTERPOLATOR_H_
#define _NIPATHINTERPOLATOR_H_

#include "NiBlendInterpolator.h"
#include "Ref.h"
#include "obj/NiPosData.h"
#include "obj/NiFloatData.h"

#include "gen/obj_defines.h"

/*
 * NiPathInterpolator
 */

class NiPathInterpolator;
typedef Ref<NiPathInterpolator> NiPathInterpolatorRef;

class NiPathInterpolator : public NI_PATH_INTERPOLATOR_PARENT {
public:
  NiPathInterpolator();
  ~NiPathInterpolator();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  NI_PATH_INTERPOLATOR_MEMBERS
};

#endif
