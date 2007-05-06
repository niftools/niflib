/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _NISKININSTANCE_H_
#define _NISKININSTANCE_H_

#include "NiObject.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiSkinData;
class NiSkinPartition;
class NiNode;

//#include "../gen/obj_defines.h"

class NiSkinInstance;
typedef Ref<NiSkinInstance> NiSkinInstanceRef;

/*!
 * NiSkinInstance - Skinning instance.
 */

class NiSkinInstance : public NI_SKIN_INSTANCE_PARENT {
public:
	NIFLIB_API NiSkinInstance();

	/*!
	 * This constructor is called by NiTriBasedGeom when it creates a new skin
	 * instance using the BindSkin function.
	 */
#ifndef SWIG // for some reason SWIG cannot properly hide this function in NiSkinInstanceRef
	NIFLIB_HIDDEN NiSkinInstance( NiNode * skeleton_root, vector< Ref<NiNode> > bone_nodes );
#endif

	NIFLIB_API ~NiSkinInstance();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Retrieves the number of NiNode bones that influence this skin.
	 * \return The number of bones that influence this skin.
	 */
	NIFLIB_API unsigned int GetBoneCount() const;

	/*!
	 * Retrieves a list of references to all the NiNode bones that influence this skin.
	 * \return All the bones that influence this skin.
	 */
	NIFLIB_API vector< Ref<NiNode> > GetBones() const;

	/*!
	 * Retrieves the root node of the skeleton that influences this skin.  This is the common ancestor of all bones and the skin itself.
	 * \return The skeleton root.
	 */
	NIFLIB_API Ref<NiNode> GetSkeletonRoot() const;

	/*!
	 * Retrieves the root node of the skeleton that influences this skin.  This is the common ancestor of all bones and the skin itself.
	 * \return The skeleton root.
	 */
	NIFLIB_API Ref<NiSkinData> GetSkinData() const;


	/*!
	 * Retrieves the hardare skin partition, if any.
	 * \return The skeleton root.
	 */
	NIFLIB_API Ref<NiSkinPartition> GetSkinPartition() const;

	/*! 
	 * NIFLIB_HIDDEN function.  For internal use only.
	 * Called by NiGeometry during the skin binding process.
	 */
	NIFLIB_HIDDEN void SetSkinData( NiSkinData * n );

	/*
	 * NIFLIB_HIDDEN function.  For internal use only.
	 * This can be used to set or clear the hardware skin partition data.  To create partition data, the NiTriBasedGeom::GenHardwareSkinInfo function should be used.
	 * \param[in] n The new hardware skin partition data object to use, or NULL to clear the existing one.
	 */
	NIFLIB_HIDDEN void SetSkinPartition( NiSkinPartition * n );

	/*! 
	 * NIFLIB_HIDDEN function.  For internal use only.
	 * Called by skeleton root NiNode when it self destructs to inform this skin
	 * instance that the skeleton has been lost.  Should not be called directly.
	 */
	NIFLIB_HIDDEN void SkeletonLost();

protected:
	NI_SKIN_INSTANCE_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
