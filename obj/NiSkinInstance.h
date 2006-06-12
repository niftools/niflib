/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISKININSTANCE_H_
#define _NISKININSTANCE_H_

#include "NiObject.h"

// Forward define of referenced blocks
#include "../Ref.h"
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
	~NiSkinInstance();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	vector< Ref<NiNode> > GetBones() const;

	/*!
	 * Binds any geometry that uses this skin instance to a list of bones.
	 * The bones must have a common ancestor in the scenegraph.  This becomes
	 * the skeleton root.
	 */
	void Bind( Ref<NiNode> skeleton_root, vector< Ref<NiNode> > bone_nodes );

	/*! 
	 * Detatches this skin instance from any bones it was previously bound to.
	 */
	void Unbind();

	/*! 
	 * Calculates a NiSkinPartition and attaches it to both pointers, the one
	 * used in later versions in this class, and the one in the attached
	 * NiSkinData class.  This way it will be written regardless of the
	 * version.  SkinData must be set before this can be calculated.
	 */
	void CalcHardwareSkinningData ();

	Ref<NiSkinData> GetSkinData() const;
	void SetSkinData( const Ref<NiSkinData> & n );

	Ref<NiSkinPartition> GetSkinPartition() const;
	void SetSkinPartition( const Ref<NiSkinPartition> & n );

protected:
	NI_SKIN_INSTANCE_MEMBERS
};

#endif
