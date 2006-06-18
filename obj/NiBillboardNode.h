/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIBILLBOARDNODE_H_
#define _NIBILLBOARDNODE_H_

#include "NiNode.h"
namespace Niflib {


#include "../gen/obj_defines.h"

class NiBillboardNode;
typedef Ref<NiBillboardNode> NiBillboardNodeRef;

/*!
 * NiBillboardNode - These nodes will always be rotated to face the
 * camera creating a billboard effect for any attached objects.
 */

class NIFLIB_API NiBillboardNode : public NI_BILLBOARD_NODE_PARENT {
public:
	NiBillboardNode();
	~NiBillboardNode();
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
	NI_BILLBOARD_NODE_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
