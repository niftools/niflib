/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NITRIBASEDGEOMDATA_H_
#define _NITRIBASEDGEOMDATA_H_

#include "NiObject.h"
#include "Ref.h"
#include "obj/NiObject.h"

#include "gen/obj_defines.h"

/*
 * NiTriBasedGeomData
 */

class NiTriBasedGeomData;
typedef Ref<NiTriBasedGeomData> NiTriBasedGeomDataRef;

class NiTriBasedGeomData : public NI_TRI_BASED_GEOM_DATA_PARENT {
public:
  NiTriBasedGeomData();
  ~NiTriBasedGeomData();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  Vector3 Center() const;
  float Radius() const;
  NI_TRI_BASED_GEOM_DATA_MEMBERS
};

#endif
