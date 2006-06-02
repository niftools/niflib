/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIBSPLINECOMPPOINT3INTERPOLATOR_H_
#define _NIBSPLINECOMPPOINT3INTERPOLATOR_H_

#include "gen/obj_defines.h"
#include NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_INCLUDE

/*
 * NiBSplineCompPoint3Interpolator
 */

class NiBSplineCompPoint3Interpolator;
typedef Ref<NiBSplineCompPoint3Interpolator> NiBSplineCompPoint3InterpolatorRef;

class NiBSplineCompPoint3Interpolator : public NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_PARENT {
public:
  NiBSplineCompPoint3Interpolator();
  ~NiBSplineCompPoint3Interpolator();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_MEMBERS
};

#endif
