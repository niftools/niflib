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

#include "../gen/obj_defines.h"

class NiSkinInstance;
typedef Ref<NiSkinInstance> NiSkinInstanceRef;

/*!
 * NiSkinInstance - Skinning instance.
 */

class NIFLIB_API NiSkinInstance : public NI_SKIN_INSTANCE_PARENT {
public:
	NiSkinInstance();

	/*!
	 * This constructor is called by NiTriBasedGeom when it creates a new skin
	 * instance using the BindSkin function.
	 */
	NiSkinInstance( Ref<NiNode> skeleton_root, vector< Ref<NiNode> > bone_nodes );

	~NiSkinInstance();
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

	uint GetBoneCount() const;
	vector< Ref<NiNode> > GetBones() const;
	Ref<NiNode> GetSkeletonRoot() const;

	Ref<NiSkinData> GetSkinData() const;
	void SetSkinData( const Ref<NiSkinData> & n );

	Ref<NiSkinPartition> GetSkinPartition() const;
	void SetSkinPartition( const Ref<NiSkinPartition> & n );

	/*! 
	 * Called by skeleton root NiNode when it self destructs to inform this skin
	 * instance that the skeleton has been lost.  Should not be called directly.
	 */
	void SkeletonLost();

protected:
	NI_SKIN_INSTANCE_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
