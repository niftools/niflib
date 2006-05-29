/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKCONVEXVERTICESSHAPE_H_
#define _BHKCONVEXVERTICESSHAPE_H_

#include "xml_extract.h"
#include BHK_CONVEX_VERTICES_SHAPE_INCLUDE

/*
 * bhkConvexVerticesShape
 */

class bhkConvexVerticesShape;
typedef Ref<bhkConvexVerticesShape> bhkConvexVerticesShapeRef;

class bhkConvexVerticesShape : public BHK_CONVEX_VERTICES_SHAPE_PARENT {
public:
  bhkConvexVerticesShape();
  ~bhkConvexVerticesShape();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  BHK_CONVEX_VERTICES_SHAPE_MEMBERS
};

#endif
