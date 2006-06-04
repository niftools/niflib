/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NILODNODE_H_
#define _NILODNODE_H_

#include "NiNode.h"
// Include structures
#include "gen/LODRange.h"

// Forward define of referenced blocks
#include "Ref.h"
class NiRangeLODData;

#include "gen/obj_defines.h"

/*
 * NiLODNode
 */

class NiLODNode;
typedef Ref<NiLODNode> NiLODNodeRef;

class NiLODNode : public NI_L_O_D_NODE_PARENT {
public:
	NiLODNode();
	~NiLODNode();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual const Type & GetType() const;
protected:
	NI_L_O_D_NODE_MEMBERS
};

#endif
