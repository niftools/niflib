/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIMATERIALCOLORCONTROLLER_H_
#define _NIMATERIALCOLORCONTROLLER_H_

#include "gen/obj_defines.h"
#include NI_MATERIAL_COLOR_CONTROLLER_INCLUDE

/*
 * NiMaterialColorController
 */

class NiMaterialColorController;
typedef Ref<NiMaterialColorController> NiMaterialColorControllerRef;

class NiMaterialColorController : public NI_MATERIAL_COLOR_CONTROLLER_PARENT {
public:
  NiMaterialColorController();
  ~NiMaterialColorController();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  NI_MATERIAL_COLOR_CONTROLLER_MEMBERS
};

#endif
