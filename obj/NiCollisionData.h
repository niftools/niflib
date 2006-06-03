/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NICOLLISIONDATA_H_
#define _NICOLLISIONDATA_H_

#include "NiObject.h"
class NiNode;

#include "gen/obj_defines.h"

/*
 * NiCollisionData
 */

class NiCollisionData;
typedef Ref<NiCollisionData> NiCollisionDataRef;

class NiCollisionData : public NI_COLLISION_DATA_PARENT {
public:
  NiCollisionData();
  ~NiCollisionData();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  NI_COLLISION_DATA_MEMBERS
};

#endif
