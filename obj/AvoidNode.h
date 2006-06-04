/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _AVOIDNODE_H_
#define _AVOIDNODE_H_

#include "NiNode.h"

#include "gen/obj_defines.h"

/*
 * AvoidNode
 */

class AvoidNode;
typedef Ref<AvoidNode> AvoidNodeRef;

class AvoidNode : public AVOID_NODE_PARENT {
public:
	AvoidNode();
	~AvoidNode();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	AVOID_NODE_MEMBERS
};

#endif
