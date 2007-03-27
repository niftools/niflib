/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISKINDATA_H_
#define _NISKINDATA_H_

#include "NiObject.h"
// Include structures
#include "../Ref.h"
#include "../gen/SkinData.h"
namespace Niflib {

// Forward define of referenced blocks
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
	 * This constructor is called by NiGeometry when it creates a new skin
	 * instance using the BindSkin function.
	 */
	NIFLIB_HIDDEN NiSkinData( const Ref<NiGeometry> & owner );

	NIFLIB_API ~NiSkinData();

	//Run-Time Type Information
	NIFLIB_API static const Type & TypeConst() { return TYPE; }
private:	
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const { return TYPE; };
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	NIFLIB_API void ResetOffsets( const Ref<NiGeometry> & owner );
	NIFLIB_API Matrix44 GetOverallTransform() const;
	NIFLIB_API void SetOverallTransform( const Matrix44 & transform );
	NIFLIB_API unsigned int GetBoneCount() const;
	NIFLIB_API Matrix44 GetBoneTransform( unsigned int bone_index ) const;
	NIFLIB_API vector<SkinWeight> GetBoneWeights( unsigned int bone_index ) const;
	NIFLIB_API void SetBoneWeights( unsigned int bone_index, const vector<SkinWeight> & n, Vector3 center, float radius );

	NIFLIB_API void NormalizeWeights( unsigned numVertices );
	
	NIFLIB_API Ref<NiSkinPartition> GetSkinPartition() const;
	NIFLIB_API void SetSkinPartition(Ref<NiSkinPartition> skinPartition);

protected:
	NI_SKIN_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
