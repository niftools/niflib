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
class NiTriBasedGeom;

#include "../gen/obj_defines.h"

class NiSkinData;
typedef Ref<NiSkinData> NiSkinDataRef;

/*!
 * NiSkinData - Skinning data.
 */

class NIFLIB_API NiSkinData : public NI_SKIN_DATA_PARENT {
public:
	NiSkinData();

	/*!
	 * This constructor is called by NiTriBasedGeom when it creates a new skin
	 * instance using the BindSkin function.
	 */
	NiSkinData( const Ref<NiTriBasedGeom> & owner );

	~NiSkinData();

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

	Matrix44 GetOverallTransform() const;
	uint GetBoneCount() const;
	Matrix44 GetBoneTransform( uint bone_index ) const;
	vector<SkinWeight> GetBoneWeights( uint bone_index ) const;
   void SetBoneWeights( uint bone_index, const vector<SkinWeight> & n, Vector3 center, float radius );

protected:
	NI_SKIN_DATA_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
