/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _ROOTCOLLISIONNODE_H_
#define _ROOTCOLLISIONNODE_H_

#include "xml_extract.h"
#include ROOT_COLLISION_NODE_INCLUDE

/*
 * RootCollisionNode
 */

class RootCollisionNode;
typedef Ref<RootCollisionNode> RootCollisionNodeRef;

class RootCollisionNode : public ROOT_COLLISION_NODE_PARENT {
public:
  RootCollisionNode();
  ~RootCollisionNode();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  ROOT_COLLISION_NODE_MEMBERS
};

#endif
