/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NICONTROLLERSEQUENCE_H_
#define _NICONTROLLERSEQUENCE_H_

#include "NiObject.h"
#include "gen/ControllerLink.h"
#include "Ref.h"
#include "obj/NiTextKeyExtraData.h"
#include "obj/NiStringPalette.h"
class NiControllerManager;

#include "gen/obj_defines.h"

/*
 * NiControllerSequence
 */

class NiControllerSequence;
typedef Ref<NiControllerSequence> NiControllerSequenceRef;

class NiControllerSequence : public NI_CONTROLLER_SEQUENCE_PARENT {
public:
  NiControllerSequence();
  ~NiControllerSequence();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  NiControllerManager * NiControllerSequence::Parent() const;
  NI_CONTROLLER_SEQUENCE_MEMBERS
};

#endif
