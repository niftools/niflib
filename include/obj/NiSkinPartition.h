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
class NiTriBasedGeom;
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
	virtual void FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

   int GetNumPartitions() const;

   ushort GetWeightsPerVertex( int partition ) const;

   ushort GetNumVertices( int partition ) const;

   vector<ushort> GetVertexMap( int partition ) const;

   vector<ushort> GetBoneMap( int partition ) const;

   bool HasVertexWeights( int partition ) const;
   vector<float> GetVertexWeights( int partition, int vertex ) const;

   bool HasVertexBoneIndices( int partition ) const;
   vector<ushort> GetVertexBoneIndices( int partition, int vertex ) const;

   /*! Used to get the number of triangle strips that a particular skin partition
    * isis divided into.
    * \param[in] partition The specific partition to get the strip count from.
    * \return The number of triangle strips used by this mesh.
    * \sa NiSkinPartition::SetStripCount
    */
   ushort GetStripCount( int partition ) const;

   /*! Used to retrieve all the triangles from a specific triangle strip in a
    * particular skin partition.
    * \param[in] partition The specific partition to get the triangles from.
    * \param[in] index The index of the triangle strip to retrieve the triangles from.  This is a zero-based index which must be a positive number less than that returned by NiTriStripsData::GetStripCount.
    * \return A vector containing all the triangle faces from the triangle strip specified by index.
    * \sa NiSkinPartition::SetStrip
    */
   vector<ushort> GetStrip( int partition, int index ) const;
   
   vector<Triangle> GetTriangles( int partition ) const;


protected:
   friend class NiTriBasedGeom;
   NiSkinPartition(Ref<NiTriBasedGeom> shape);
   NiSkinPartition(Ref<NiTriBasedGeom> shape, int maxBonesPerPartition, int maxBonesPerVertex);

   void SetNumPartitions( int value );
   void SetWeightsPerVertex( int partition, ushort value );
   void SetNumVertices( int partition, ushort value );
   void SetVertexMap( int partition, const vector<ushort>& vertexMap );
   void SetBoneMap( int partition, const vector<ushort>& boneMap );

   void EnableVertexWeights( int partition, bool enable);
   void SetVertexWeights( int partition, int vertex, const vector<float> & n );

   void EnableVertexBoneIndices( int partition, bool enable);
   void SetVertexBoneIndices( int partition, int vertex, const vector<ushort>& boneList );

   /*! Used to resize the triangle strips array from a particular skin partition.
    * If the new size is smaller, strips at the end of the array will be deleted.
    * \param[in] partition The specific partition to strip array from.
    * \param[in] n The new size of the triangle strips array.
    * \sa NiSkinPartition::GetStripCount
    */
   void SetStripCount( int partition, int n );

   /*! Used to set the triangle face data in a specific triangle strip from a
    * particular skin partition.
    * \param[in] partition The specific partition to get the strip count from.
	* \param[in] index The index of the triangle strip to set the face data for.  This is a zero-based index which must be a positive number less than that returned by NiTriStripsData::GetStripCount.
    * \param[in] in The vertex indices that make up this strip, in standard OpenGL triangle strip order.
    * \sa NiSkinPartition::GetStrip
    */
   void SetStrip( int partition, int index, const vector<ushort> & in );

   void SetTriangles( int partition, const vector<Triangle> & in );

protected:
	NI_SKIN_PARTITION_MEMBERS
private:
	void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
