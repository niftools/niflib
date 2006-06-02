/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BSKEYFRAMECONTROLLER_H_
#define _BSKEYFRAMECONTROLLER_H_

#include "gen/obj_defines.h"
#include B_S_KEYFRAME_CONTROLLER_INCLUDE

/*
 * BSKeyframeController
 */

class BSKeyframeController;
typedef Ref<BSKeyframeController> BSKeyframeControllerRef;

class BSKeyframeController : public B_S_KEYFRAME_CONTROLLER_PARENT {
public:
  BSKeyframeController();
  ~BSKeyframeController();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  B_S_KEYFRAME_CONTROLLER_MEMBERS
};

#endif
