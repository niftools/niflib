/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NITRISTRIPSDATA_H_
#define _NITRISTRIPSDATA_H_

#include "NiTriBasedGeomData.h"

#include "gen/obj_defines.h"

/*
 * NiTriStripsData
 */

class NiTriStripsData;
typedef Ref<NiTriStripsData> NiTriStripsDataRef;

class NiTriStripsData : public NI_TRI_STRIPS_DATA_PARENT {
public:
  NiTriStripsData();
  ~NiTriStripsData();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  NI_TRI_STRIPS_DATA_MEMBERS
};

#endif
