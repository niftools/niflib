/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _ABHKCONSTRAINT_H_
#define _ABHKCONSTRAINT_H_

#include "bhkSerializable.h"
class bhkShape;

#include "gen/obj_defines.h"

/*
 * AbhkConstraint
 */

class AbhkConstraint;
typedef Ref<AbhkConstraint> AbhkConstraintRef;

class AbhkConstraint : public ABHK_CONSTRAINT_PARENT {
public:
  AbhkConstraint();
  ~AbhkConstraint();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  ABHK_CONSTRAINT_MEMBERS
};

#endif
