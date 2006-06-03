/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKBOXSHAPE_H_
#define _BHKBOXSHAPE_H_

#include "bhkConvexShape.h"

#include "gen/obj_defines.h"

/*
 * bhkBoxShape
 */

class bhkBoxShape;
typedef Ref<bhkBoxShape> bhkBoxShapeRef;

class bhkBoxShape : public BHK_BOX_SHAPE_PARENT {
public:
  bhkBoxShape();
  ~bhkBoxShape();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  BHK_BOX_SHAPE_MEMBERS
};

#endif
