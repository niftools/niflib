/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NITRANSFORMDATA_H_
#define _NITRANSFORMDATA_H_

#include "gen/obj_defines.h"
#include NI_TRANSFORM_DATA_INCLUDE

/*
 * NiTransformData
 */

class NiTransformData;
typedef Ref<NiTransformData> NiTransformDataRef;

class NiTransformData : public NI_TRANSFORM_DATA_PARENT {
public:
  NiTransformData();
  ~NiTransformData();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  NI_TRANSFORM_DATA_MEMBERS
};

#endif
