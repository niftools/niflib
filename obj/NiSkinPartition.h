/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISKINPARTITION_H_
#define _NISKINPARTITION_H_

#include "NiObject.h"

// Include structures
#include "../gen/SkinPartition.h"
namespace Niflib {


#include "../gen/obj_defines.h"

class NiSkinPartition;
typedef Ref<NiSkinPartition> NiSkinPartitionRef;

/*!
 * NiSkinPartition - Skinning data, optimized for hardware skinning. The
 * mesh is partitioned in submeshes such that each vertex of a submesh is
 * influenced only by a limited and fixed number of bones.
 */

class NIFLIB_API NiSkinPartition : public NI_SKIN_PARTITION_PARENT {
public:
	NiSkinPartition();
	~NiSkinPartition();
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

   int GetNumPartitions() const;
   void SetNumPartitions( int value );

   ushort GetWeightsPerVertex( int partition ) const;
   void SetWeightsPerVertex( int partition, ushort value );

   ushort GetNumVertices( int partition ) const;
   void SetNumVertices( int partition, ushort value );

   vector<ushort> GetVertexMap( int partition ) const;
   void SetVertexMap( int partition, const vector<ushort>& vertexMap );

   vector<ushort> GetBoneMap( int partition ) const;
   void SetBoneMap( int partition, const vector<ushort>& boneMap );

   bool HasVertexWeights( int partition ) const;
   void EnableVertexWeights( int partition, bool enable);

   vector<float> GetVertexWeights( int partition, int vertex ) const;
   void SetVertexWeights( int partition, int vertex, const vector<float> & n );

   bool HasVertexBoneIndices( int partition ) const;
   void EnableVertexBoneIndices( int partition, bool enable);
   vector<ushort> GetVertexBoneIndices( int partition, int vertex ) const;
   void SetVertexBoneIndices( int partition, int vertex, const vector<ushort>& boneList );

   /*! Used to get the number of triangle strips that this mesh is divided into.
   * \return The number of triangle strips used by this mesh.
   * \sa NiSkinPartition::SetStripCount
   */
   ushort GetStripCount( int partition ) const;

   /*! Used to resize the triangle strips array.  If the new size is smaller, strips at the end of the array will be deleted.
   * \param n The new size of the triangle strips array.
   * \sa NiSkinPartition::GetStripCount
   */
   void SetStripCount( int partition, int n );

   /*! Used to retrieve all the triangles from a specific triangle strip.
   * \param index The index of the triangle strip to retrieve the triangles from.  This is a zero-based index which must be a positive number less than that returned by NiTriStripsData::GetStripCount.
   * \return A vector containing all the triangle faces from the triangle strip specified by index.
   * \sa NiSkinPartition::SetStrip
   */
   vector<ushort> GetStrip( int partition, int index ) const;
   
   /*! Used to set the triangle face data in a specific triangle strip.
   * \param index The index of the triangle strip to set the face data for.  This is a zero-based index which must be a positive number less than that returned by NiTriStripsData::GetStripCount.
   * \param in The vertex indices that make up this strip, in standard OpenGL triangle strip order.
   * \sa NiSkinPartition::GetStrip
   */
   void SetStrip( int partition, int index, const vector<ushort> & in );

   vector<Triangle> GetTriangles( int partition ) const;
   void SetTriangles( int partition, const vector<Triangle> & in );

protected:
	NI_SKIN_PARTITION_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
