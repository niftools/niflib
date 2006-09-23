/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIBSANIMATIONNODE_H_
#define _NIBSANIMATIONNODE_H_

#include "NiNode.h"
namespace Niflib {

#include "../gen/obj_defines.h"

class NiBSAnimationNode;
typedef Ref<NiBSAnimationNode> NiBSAnimationNodeRef;

/*!
 * NiBSAnimationNode - Bethesda-specific extension of Node with animation
 * properties stored in the flags.
 */

class NIFLIB_API NiBSAnimationNode : public NI_B_S_ANIMATION_NODE_PARENT {
public:
	NiBSAnimationNode();
	~NiBSAnimationNode();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

protected:
	NI_B_S_ANIMATION_NODE_MEMBERS
private:
	void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
