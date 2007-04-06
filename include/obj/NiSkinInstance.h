/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISKININSTANCE_H_
#define _NISKININSTANCE_H_

#include "NiObject.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
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
	NIFLIB_HIDDEN NiSkinInstance( Ref<NiNode> skeleton_root, vector< Ref<NiNode> > bone_nodes );
#endif

	NIFLIB_API ~NiSkinInstance();
	//Run-Time Type Information
	NIFLIB_API static const Type & TypeConst();
private:	
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	NIFLIB_API unsigned int GetBoneCount() const;
	NIFLIB_API vector< Ref<NiNode> > GetBones() const;
	NIFLIB_API Ref<NiNode> GetSkeletonRoot() const;

	NIFLIB_API Ref<NiSkinData> GetSkinData() const;
	NIFLIB_API void SetSkinData( const Ref<NiSkinData> & n );

	NIFLIB_API Ref<NiSkinPartition> GetSkinPartition() const;
	NIFLIB_API void SetSkinPartition( const Ref<NiSkinPartition> & n );

	/*! 
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
