/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISKINDATA_H_
#define _NISKINDATA_H_

#include "NiObject.h"
// Include structures
#include "../Ref.h"
#include "../gen/SkinData.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiSkinPartition;
class NiGeometry;

//#include "../gen/obj_defines.h"

class NiSkinData;
typedef Ref<NiSkinData> NiSkinDataRef;

/*!
 * NiSkinData - Skinning data.
 */

class NiSkinData : public NI_SKIN_DATA_PARENT {
public:
	NIFLIB_API NiSkinData();

	/*!
	 * NIFLIB_HIDDEN function.  For internal use only.
	 * This constructor is called by NiGeometry when it creates a new skin instance using the BindSkin function.
	 */
	NIFLIB_HIDDEN NiSkinData( NiGeometry * owner );

	NIFLIB_API ~NiSkinData();

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

	/*!
	 * Retrieves the current overall transform for this skin.  This is the transform from the geometry node back to its skeleton root.
	 * \return The current overall transform for this skin.
	 */
	NIFLIB_API Matrix44 GetOverallTransform() const;

	/*!
	 * Sets the overall transform for this skin.  This is the transform from the geometry node back to the skeleton root.
	 * \param[in] transform The new overall transform for this skin.
	 */
	NIFLIB_API void SetOverallTransform( const Matrix44 & transform );

	/*!
	 * Retrieves the number of bones influences affecting this skin.  These are NiNodes which cause the skin to deform when they move.
	 * \return The number of bonees influencing this skin.
	 */
	NIFLIB_API unsigned int GetBoneCount() const;

	/*!
	 * Retrieves the transform for a particular bone.  This is the transform from geometry node back to this bone in skeleton root coordinates.
	 * \param[in] bone_index The numeric index of the bone that the transform matrix should be returned for.  Must be >= zero and < the number returned by GetBoneCount.
	 * \return The transform matrix for the specified bone.
	 */
	NIFLIB_API Matrix44 GetBoneTransform( unsigned int bone_index ) const;

	/*!
	 * Retrieves the skin weights for a particular bone.  This information includes the vertex index into the geometry data's vertex array, and the percentage weight that defines how much the movement of this bone influences its position.
	 * \param[in] bone_index The numeric index of the bone that the skin weight data should be returned for.  Must be >= zero and < the number returned by GetBoneCount.
	 * \return The skin weight data for the specified bone.
	 */
	NIFLIB_API vector<SkinWeight> GetBoneWeights( unsigned int bone_index ) const;

	/*!
	 * Sets the skin weights for a particular bone.  This information includes the vertex index into the geometry data's vertex array, and the percentage weight that defines how much the movement of this bone influences its position.
	 * \param[in] bone_index The numeric index of the bone that the skin weight data should be set for.  Must be >= zero and < the number returned by GetBoneCount.
	 * \param[in] weights The new skin weight data for the specified bone.
	 * \param[in] center The center point of all the vertices affected by this bone.  This is the mid point between the minimums and maximums in each of the 3 directions.
	 * \param[in] radius The radius of a bounding circle centered at the center point which contains all the vertices affected by this bone.  This is the distance from the center to vertex that is the greatest distance away.
	 * \return The skin weight data for the specified bone.
	 */
	NIFLIB_API void SetBoneWeights( unsigned int bone_index, const vector<SkinWeight> & weights, Vector3 center, float radius );
	
	/*!
	 * Returns a reference to the hardware skin partition data object, if any.
	 * \return The hardware skin partition data, or NULL if none is used.
	 */
	NIFLIB_API Ref<NiSkinPartition> GetSkinPartition() const;

	/*
	 * NIFLIB_HIDDEN function.  For internal use only.
	 * This can be used to set or clear the hardware skin partition data.  To create partition data, the NiTriBasedGeom::GenHardwareSkinInfo function should be used.
	 * \param[in] skinPartition The new hardware skin partition data object to use, or NULL to clear the existing one.
	 */
	NIFLIB_HIDDEN void SetSkinPartition( NiSkinPartition * skinPartition );

	/*
	 * NIFLIB_HIDDEN function.  For internal use only.
	 * This is called by NiGeometry when the NormalizeSkinWeights function of that object is called, which is a public function.
	 */
	NIFLIB_HIDDEN void NormalizeWeights( unsigned numVertices );
	/*!
	 * NIFLIB_HIDDEN function.  For internal use only.
	 * This function resets the bone offsets to their current positions, effetivley changing the bind pose.  This does not cause any tranformations to the vertex positions, however, so is mostly usful for instances where the world positions of the old and new bind pose are equivalent, but result from different local transformations along the way.  It is called by NiGeometry when the interum transforms are flattened.
	 */
	NIFLIB_HIDDEN void ResetOffsets( NiGeometry * owner );

protected:
	NI_SKIN_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
