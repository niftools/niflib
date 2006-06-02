/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKPACKEDNITRISTRIPSSHAPE_H_
#define _BHKPACKEDNITRISTRIPSSHAPE_H_

#include "gen/obj_defines.h"
#include BHK_PACKED_NI_TRI_STRIPS_SHAPE_INCLUDE

/*
 * bhkPackedNiTriStripsShape
 */

class bhkPackedNiTriStripsShape;
typedef Ref<bhkPackedNiTriStripsShape> bhkPackedNiTriStripsShapeRef;

class bhkPackedNiTriStripsShape : public BHK_PACKED_NI_TRI_STRIPS_SHAPE_PARENT {
public:
  bhkPackedNiTriStripsShape();
  ~bhkPackedNiTriStripsShape();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  BHK_PACKED_NI_TRI_STRIPS_SHAPE_MEMBERS
};

#endif
