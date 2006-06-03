/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKSIMPLESHAPEPHANTOM_H_
#define _BHKSIMPLESHAPEPHANTOM_H_

#include "bhkEntity.h"

#include "gen/obj_defines.h"

/*
 * bhkSimpleShapePhantom
 */

class bhkSimpleShapePhantom;
typedef Ref<bhkSimpleShapePhantom> bhkSimpleShapePhantomRef;

class bhkSimpleShapePhantom : public BHK_SIMPLE_SHAPE_PHANTOM_PARENT {
public:
  bhkSimpleShapePhantom();
  ~bhkSimpleShapePhantom();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  BHK_SIMPLE_SHAPE_PHANTOM_MEMBERS
};

#endif
