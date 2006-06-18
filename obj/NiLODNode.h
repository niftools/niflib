/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NILODNODE_H_
#define _NILODNODE_H_

#include "NiNode.h"

// Include structures
#include "../gen/LODRange.h"
#include "../Ref.h"
namespace NifLib {

// Forward define of referenced blocks
class NiRangeLODData;

#include "../gen/obj_defines.h"

class NiLODNode;
typedef Ref<NiLODNode> NiLODNodeRef;

/*!
 * NiLODNode - Level of detail selector. Links to different levels of
 * detail of the same model, used to switch a geometry at a specified
 * distance.
 */

class NIFLIB_API NiLODNode : public NI_L_O_D_NODE_PARENT {
public:
	NiLODNode();
	~NiLODNode();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

protected:
	NI_L_O_D_NODE_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
