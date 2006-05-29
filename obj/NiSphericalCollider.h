/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISPHERICALCOLLIDER_H_
#define _NISPHERICALCOLLIDER_H_

#include "xml_extract.h"
#include NI_SPHERICAL_COLLIDER_INCLUDE

/*
 * NiSphericalCollider
 */

class NiSphericalCollider;
typedef Ref<NiSphericalCollider> NiSphericalColliderRef;

class NiSphericalCollider : public NI_SPHERICAL_COLLIDER_PARENT {
public:
  NiSphericalCollider();
  ~NiSphericalCollider();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  NI_SPHERICAL_COLLIDER_MEMBERS
};

#endif
