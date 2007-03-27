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

class NiNode : public NI_NODE_PARENT {
public:
	NIFLIB_API NiNode();
	NIFLIB_API ~NiNode();
	//Run-Time Type Information
	NIFLIB_API static const Type & TypeConst() { return TYPE; }
private:	
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	NIFLIB_API void AddChild( Ref<NiAVObject> obj );
	NIFLIB_API void RemoveChild( Ref<NiAVObject> obj );
	NIFLIB_API void ClearChildren();
	NIFLIB_API vector< Ref<NiAVObject> > GetChildren() const;
#ifdef USE_NIFLIB_TEMPLATE_HELPERS
	template <typename ChildEquivalence>
	inline void SortChildren(ChildEquivalence pred) {
		std::stable_sort(children.begin(), children.end(), pred);
	}
#endif

	NIFLIB_API void AddEffect( Ref<NiDynamicEffect> effect );
	NIFLIB_API void RemoveEffect( Ref<NiDynamicEffect> effect );
	NIFLIB_API void ClearEffects();
	NIFLIB_API vector< Ref<NiDynamicEffect> > GetEffects() const;

	/*! Checks if this node has any skins attached. */
	NIFLIB_API bool IsSkeletonRoot() const;

	/*! Checks if this node influences the vertices in any skins. */
	NIFLIB_API bool IsSkinInfluence() const;

	/*! 
	 * Applies a huristic to guess whether this node was created as a proxy
	 * when a mesh which had more than one material in the original model
	 * was split in an exporter.
	 * /return Whether or not this node is probably a split mesh proxy
	 */
	NIFLIB_API bool IsSplitMeshProxy() const;
	   

	/*! 
	 * Causes all children's transforms to be changed so that all the skin
	 * pieces line up without any vertex transformations.
	 */
	NIFLIB_API void GoToSkeletonBindPosition();

	/*!
	 * Applies the local transforms of this node to its children,
	 * causing itself to be cleared to identity transforms.
	 */
	NIFLIB_API void PropagateTransform();

	/*! 
	 * Should only be called by NiTriBasedGeom
	 * Adds a new SkinInstance to the specified mesh.
	 * The bones must be below this node in the scene graph tree
	 */
	NIFLIB_HIDDEN void AddSkin( NiSkinInstance * skin_inst );

	/*! 
	 * Should only be called by NiTriBasedGeom
	 * Detaches the skin associated with a child mesh.
	 */
	NIFLIB_HIDDEN void RemoveSkin( NiSkinInstance * skin_inst );

	/*! Should not be called directly */
	NIFLIB_HIDDEN void SetSkinFlag( bool n );

private:
	void RepositionGeom( NiAVObjectRef root );
protected:
	list<NiSkinInstance*> skins;
	NI_NODE_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
