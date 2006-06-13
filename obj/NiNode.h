/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NINODE_H_
#define _NINODE_H_

#include "NiAVObject.h"

// Forward define of referenced blocks
class NiAVObject;
class NiDynamicEffect;

#include "../gen/obj_defines.h"

class NiNode;
class NiAVObject;
class NiSkinInstance;
typedef Ref<NiNode> NiNodeRef;

/*!
 * NiNode - Generic node block for grouping.
 */

class NIFLIB_API NiNode : public NI_NODE_PARENT {
public:
	NiNode();
	~NiNode();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	void AddChild( Ref<NiAVObject> & obj );
	void RemoveChild( Ref<NiAVObject> obj );
	void ClearChildren();
	vector< Ref<NiAVObject> > GetChildren() const;

	/*! Checks if this node has any skins attached. */
	bool IsSkeletonRoot() const;

	/*! Checks if this node influences the vertices in any skins. */
	bool IsSkinInfluence() const;

	/*! Causes all children's transforms to be changed so that all the skin
	 * pieces line up without any vertex transformations.
	 */
	void GoToSkeletonBindPosition();

	/*! 
	 * Should only be called by NiTriBasedGeom
	 * Adds a new SkinInstance to the specified mesh.
	 * The bones must be below this node in the scene graph tree
	 */
	void AddSkin( NiSkinInstance * skin_inst );

	/*! 
	 * Should only be called by NiTriBasedGeom
	 * Detaches the skin associated with a child mesh.
	 */
	void RemoveSkin( NiSkinInstance * skin_inst );

	/*! Should not be called directly */
	void SetSkinFlag( bool n );

private:
	void NiNode::RepositionGeom( NiAVObjectRef root );
protected:
	list<NiSkinInstance*> skins;
	NI_NODE_MEMBERS
};

#endif
