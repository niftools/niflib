/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NITRIBASEDGEOMDATA_H_
#define _NITRIBASEDGEOMDATA_H_

#include "NiObject.h"

// Forward define of referenced blocks
#include "../Ref.h"
class NiObject;

#include "../gen/obj_defines.h"

class NiTriBasedGeomData;
typedef Ref<NiTriBasedGeomData> NiTriBasedGeomDataRef;

/*!
 * NiTriBasedGeomData - Mesh data: vertices, vertex normals, etc.
 */

class NiTriBasedGeomData : public NI_TRI_BASED_GEOM_DATA_PARENT {
public:
	NiTriBasedGeomData();
	~NiTriBasedGeomData();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	//--Counts--//

	/*! Returns the number of verticies that make up this mesh.  This is also the number of normals, colors, and UV coordinates if these are used.
	 * \return The number of vertices that make up this mesh.
	 * \sa IShapeData::SetVertexCount
	 */
	int GetVertexCount() const { return int(vertices.size()); }

	/*! Returns the number of texture coordinate sets used by this mesh.  For each UV set, there is a pair of texture coordinates for every vertex in the mesh.  Each set corresponds to a texture entry in the NiTexturingPropery block.
	 * \return The number of texture cooridnate sets used by this mesh.  Can be zero.
	 * \sa IShapeData::SetUVSetCount, ITexturingProperty
	 */
	short GetUVSetCount() const { return short(uvSets.size()); }

	/*! Changes the number of vertices used by this mesh.  If the mesh already contains data, it will be retained so long as the new number is higher than the old number.  Otherwise any verticies above the new number will be deleted.  This also resizes any normal, color, or UV data associated with these verticies.  Triangles and triangle strips that may be attached via other interfaces are not culled of references to newly invalid vertices, however.
	 * \param n The new size of the vertex array.
	 * \sa IShapeData::GetVertexCount
	 */
	void SetVertexCount(int n);

	/*! Changes the number of UV sets used by this mesh.  If he new size is smaller, data at the end of the array will be lost.  Otherwise it will be retained.  The number of UV sets must correspond with the number of textures defined in the corresponding NiTexturingProperty block.
	 * \param n The new size of the uv set array.
	 * \sa IShapeData::GetUVSetCount, ITexturingProperty
	 */
	void SetUVSetCount(int n);

	//--Getters--//

	/*! Used to retrive the vertices used by this mesh.  The size of the vector will be the same as the vertex count retrieved with the IShapeData::GetVertexCount function.
	 * \return A vector cntaining the vertices used by this mesh.
	 * \sa IShapeData::SetVertices, IShapeData::GetVertexCount, IShapeData::SetVertexCount.
	 */
	vector<Vector3> GetVertices() const { return vertices; }

	/*! Used to retrive the normals used by this mesh.  The size of the vector will either be zero if no normals are used, or be the same as the vertex count retrieved with the IShapeData::GetVertexCount function.
	 * \return A vector cntaining the normals used by this mesh, if any.
	 * \sa IShapeData::SetNormals, IShapeData::GetVertexCount, IShapeData::SetVertexCount.
	 */
	vector<Vector3> GetNormals() const { return normals; }

	/*! Used to retrive the vertex colors used by this mesh.  The size of the vector will either be zero if no vertex colors are used, or be the same as the vertex count retrieved with the IShapeData::GetVertexCount function.
	 * \return A vector cntaining the vertex colors used by this mesh, if any.
	 * \sa IShapeData::SetVertexColors, IShapeData::GetVertexCount, IShapeData::SetVertexCount.
	 */
	vector<Color4> GetColors() const { return vertexColors; }

	/*! Used to retrive the texture coordinates from one of the texture sets used by this mesh.  The function will throw an exception if a texture set index that does not exist is specified.  The size of the vector will be the same as the vertex count retrieved with the IShapeData::GetVertexCount function.
	 * \param index The index of the texture coordinate set to retrieve the texture coordinates from.  This index is zero based and must be a positive number smaller than that returned by the IShapeData::GetUVSetCount function.  If there are no texture coordinate sets, this function will throw an exception.
	 * \return A vector cntaining the the texture coordinates used by the requested texture coordinate set.
	 * \sa IShapeData::SetUVSet, IShapeData::GetUVSetCount, IShapeData::SetUVSetCount, IShapeData::GetVertexCount, IShapeData::SetVertexCount.
	 */
	vector<TexCoord> GetUVSet( int index ) const { return uvSets[index]; }
	
//--Setters--//

	/*! Used to set the vertex data used by this mesh.  The size of the vector must be the same as the vertex count retrieved with the IShapeData::GetVertexCount function or the function will throw an exception.
	 * \param in A vector containing the vertices to replace those in the mesh with.  Note that there is no way to set vertices one at a time, they must be sent in one batch.
	 * \sa IShapeData::GetVertices, IShapeData::GetVertexCount, IShapeData::SetVertexCount.
	 */
	void SetVertices( const vector<Vector3> & in );

	/*! Used to set the normal data used by this mesh.  The size of the vector must either be zero, or the same as the vertex count retrieved with the IShapeData::GetVertexCount function or the function will throw an exception.
	 * \param in A vector containing the normals to replace those in the mesh with.  Note that there is no way to set normals one at a time, they must be sent in one batch.  Use an empty vector to signify that this mesh will not be using normals.
	 * \sa IShapeData::GetNormals, IShapeData::GetVertexCount, IShapeData::SetVertexCount.
	 */
	void SetNormals( const vector<Vector3> & in );

	/*! Used to set the vertex color data used by this mesh.  The size of the vector must either be zero, or the same as the vertex count retrieved with the IShapeData::GetVertexCount function or the function will throw an exception.
	 * \param in A vector containing the vertex colors to replace those in the mesh with.  Note that there is no way to set vertex colors one at a time, they must be sent in one batch.  Use an empty vector to signify that this mesh will not be using vertex colors.
	 * \sa IShapeData::GetColors, IShapeData::GetVertexCount, IShapeData::SetVertexCount.
	 */
	void SetVertexColors( const vector<Color4> & in );

	/*! Used to set the texture coordinate data from one of the texture sets used by this mesh.  The function will throw an exception if a texture set index that does not exist is specified.  The size of the vector must be the same as the vertex count retrieved with the IShapeData::GetVertexCount function, or the function will throw an exception.
	 * \param index The index of the texture coordinate set to retrieve the texture coordinates from.  This index is zero based and must be a positive number smaller than that returned by the IShapeData::GetUVSetCount function.  If there are no texture coordinate sets, this function will throw an exception.
	 * \param in A vector containing the the new texture coordinates to replace those in the requested texture coordinate set.
	 * \sa IShapeData::GetUVSet, IShapeData::GetUVSetCount, IShapeData::SetUVSetCount, IShapeData::GetVertexCount, IShapeData::SetVertexCount.
	 */
	void SetUVSet( int index, const vector<TexCoord> & in );

protected:
	Vector3 Center() const;
	float Radius() const;
	void CalcCentAndRad( Vector3 & center, float & radius ) const;
	NI_TRI_BASED_GEOM_DATA_MEMBERS
};

#endif
