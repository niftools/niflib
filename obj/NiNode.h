/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NINODE_H_
#define _NINODE_H_

#include "xml_extract.h"
#include NI_NODE_INCLUDE

/*
 * NiNode - A basic scene graph node.  Can have children.
 */

class NiNode;
typedef Ref<NiNode> NiNodeRef;

class NiNode : public NI_NODE_PARENT {
public:
	NiNode();
	~NiNode();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version );

	//TODO:  Add functions to get and set children and store a list of NiObjectNET references
private:
	NI_NODE_MEMBERS
};

#endif