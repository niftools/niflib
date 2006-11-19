/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NINODE_H_
#define _NINODE_H_

#include "NiAVObject.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class NiAVObject;
class NiDynamicEffect;

//#include "../gen/obj_defines.h"

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
	static const Type & TypeConst() { return TYPE; }
private:	
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	void AddChild( Ref<NiAVObject> obj );
	void RemoveChild( Ref<NiAVObject> obj );
	void ClearChildren();
	vector< Ref<NiAVObject> > GetChildren() const;
#ifdef USE_NIFLIB_TEMPLATE_HELPERS
   template <typename ChildEquivalence>
   inline void SortChildren(ChildEquivalence pred) {
      std::stable_sort(children.begin(), children.end(), pred);
   }
#endif

   void AddEffect( Ref<NiDynamicEffect> effect );
   void RemoveEffect( Ref<NiDynamicEffect> effect );
   void ClearEffects();
   vector< Ref<NiDynamicEffect> > GetEffects() const;

	/*! Checks if this node has any skins attached. */
	bool IsSkeletonRoot() const;

	/*! Checks if this node influences the vertices in any skins. */
	bool IsSkinInfluence() const;

	/*! 
	 * Applies a huristic to guess whether this node was created as a proxy
	 * when a mesh which had more than one material in the original model
	 * was split in an exporter.
	 * /return Whether or not this node is probably a split mesh proxy
	 */
	bool IsSplitMeshProxy() const;
	   

	/*! 
	 * Causes all children's transforms to be changed so that all the skin
	 * pieces line up without any vertex transformations.
	 */
	void GoToSkeletonBindPosition();

	/*!
	 * Applies the local transforms of this node to its children,
	 * causing itself to be cleared to identity transforms.
	 */
	void PropagateTransform();

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
private:
	void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
