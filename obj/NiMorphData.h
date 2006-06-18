/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIMORPHDATA_H_
#define _NIMORPHDATA_H_

#include "NiObject.h"
// Include structures
#include "../gen/Morph.h"
namespace NifLib {

#include "../gen/obj_defines.h"

class NiMorphData;
typedef Ref<NiMorphData> NiMorphDataRef;

/*!
 * NiMorphData - Geometry morphing data.
 */

class NIFLIB_API NiMorphData : public NI_MORPH_DATA_PARENT {
public:
	NiMorphData();
	~NiMorphData();
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

	/*! Retrieves the number of verticies used in the morph targets.  This must be the same as the number of verticies in the base mesh that the morph controller for which this block stores data is attatched.  This is not done automatically by Niflib.
	 * \return The number of vertices used in the morph target meshes.
	 * \sa NiMorphData::SetVertexCount
	 */
	int GetVertexCount() const;

	/*! Sets the number of verticies used in the morph targets.  This must be the same as the number of verticies in the base mesh that the morph controller for which this block stores data is attatched.  This is not done automatically by Niflib.  If the new size is smaller, vertices at the ends of the morph targets will be lost.
	 * \param n The new size of the morph target's vertex arrays.
	 * \sa NiMorphData::GetVertexCount
	 */
	void SetVertexCount( int n );

	/*! Retrieves the number of morph targets used by this morph controller data.
	 * \return The number of morph targets used by this morph controller data.
	 * \sa NiMorphData::SetMorphCount
	 */
	int GetMorphCount() const;

	/*! Resizes the morph target array used by this morph controller data.  If the new size is smaller, morph targets at the end of the array and all associated data will be lost.
	 * \param n The new size of the morph target array.
	 * \sa NiMorphData::GetMorphCount
	 */
	void SetMorphCount( int n );

	/*! Retrieves the type of morph interpolation being used by a specific morph target.
	 * \param n The index of the morph to get the interpolation key type from.  A zero-based positive value which must be less than that returned by IMoprhData::GetMorphCount.
	 * \return The morph key type specifing the type of interpolation being used by the specified morph target.
	 * \sa NiMorphData::SetMorphKeyType
	 */
	KeyType GetMorphKeyType( int n ) const;
	
	/*! Sets the type of morph interpolation being used by a specific morph target.  Does not affect existing key data.
	 * \param n The index of the morph to get the interpolation key type from.  A zero-based positive value which must be less than that returned by IMoprhData::GetMorphCount.
	 * \param t The new morph key type specifing the type of interpolation to be used by the specified morph target.
	 * \sa NiMorphData::GetMorphKeyType
	 */
	void SetMorphKeyType( int n, KeyType t );

	/*! Retrieves the morph key data for a specified morph target.
	 * \return A vector containing Key<float> data which specify the influence of this morph target over time.
	 * \sa NiMorphData::SetMorphKeys, Key
	 */
	vector< Key<float> > GetMorphKeys( int n ) const;

	/*! Sets the morph key data.
	 * \param n The index of the morph target to set the keys for.
	 * \param keys A vector containing new Key<float> data which will replace any existing data for this morph target.
	 * \sa NiMorphData::GetMorphKeys, Key
	 */
	void SetMorphKeys( int n, vector< Key<float> > const & keys );

	/*! Retrieves the vertex data from the specified morph target
	 * \param n The index of the morph target to retrieve vertex data for.  This is a zero-based index whoes value that must be less than that returned by NiMorphData::GetMorphCount.
	 * \return A vector containing the vertices used by this morph target.  The size will be equal to the value returned by NiMorphData::GetVertexCount.
	 * \sa NiMorphData::SetMorphVerts
	 */
	vector<Vector3> GetMorphVerts( int n) const;

	/*! Sets the vertex data for a specified morph target
	 * \param n The index of the morph target to set vertex data for.  This is a zero-based index whoes value that must be less than that returned by NiMorphData::GetMorphCount.
	 * \param in A vector containing the new vertices to be used by this morph target.  The size will be equal to the value returned by NiMorphData::GetVertexCount.
	 * \sa NiMorphData::SetMorphVerts
	 */
	void SetMorphVerts( int n, const vector<Vector3> & in );

protected:
	NI_MORPH_DATA_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
