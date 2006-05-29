/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIBSPLINECOMPTRANSFORMINTERPOLATOR_H_
#define _NIBSPLINECOMPTRANSFORMINTERPOLATOR_H_

#include "xml_extract.h"
#include NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_INCLUDE

/*
 * NiBSplineCompTransformInterpolator
 */

class NiBSplineCompTransformInterpolator;
typedef Ref<NiBSplineCompTransformInterpolator> NiBSplineCompTransformInterpolatorRef;

class NiBSplineCompTransformInterpolator : public NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_PARENT {
public:
  NiBSplineCompTransformInterpolator();
  ~NiBSplineCompTransformInterpolator();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_MEMBERS
};

#endif
