/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NITRISHAPEDATA_H_
#define _NITRISHAPEDATA_H_

#include "NiTriBasedGeomData.h"
// Include structures
#include "../gen/MatchGroup.h"
namespace Niflib {

//#include "../gen/obj_defines.h"

class NiTriShapeData;
typedef Ref<NiTriShapeData> NiTriShapeDataRef;

/*!
 * NiTriShapeData - Holds mesh data using a list of singular triangles.
 */

class NiTriShapeData : public NI_TRI_SHAPE_DATA_PARENT {
public:
	NIFLIB_API NiTriShapeData();
	NIFLIB_API ~NiTriShapeData();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;
public:

	/*!
	 * A constructor which can be used to create a NiTriShapeData and initialize it with vertices.
	 * \param[in] verts The verticies to initialize the NiTriShapeData with.
	 */
	NIFLIB_API NiTriShapeData( const vector<Triangle>& verts );

	//--Match Detection--//
	
	//Reimplemented only to casue match detection data to be cleared
	//when vertices are updated.
	NIFLIB_API virtual void SetVertices( const vector<Vector3> & in );

	/*!
	 * This function generates match detection data based on the current
	 * vertex list.  The function of this data is unknown and appears to be
	 * optional.  The data contains a list of all the vertices that have
	 * identical positions are stored in the file.  If the vertex data is
	 * updated, match detection data will be cleared.
	 * \sa NiTriShapeData::HasMatchData
	 */
	NIFLIB_API void DoMatchDetection();

	/*!
	 * Used to determine whether current match detection data has been previously
	 * generated.
	 * \return true if there is current match data, false otherwise.
	 * \sa NiTriShapeData::DoMatchDetection
	 */
	NIFLIB_API bool HasMatchData();

	//--Getters--//

	/*!
	 * Returns the triangle faces that make up this mesh.
	 * \return A vector containing the triangle faces that make up this mesh.
	 * \sa ITriShapeData::SetTriangles
	 */
	NIFLIB_API virtual vector<Triangle> GetTriangles() const;

	//--Setters--//

	/*! Replaces the triangle face data in this mesh with new data.
	 * \param in A vector containing the new face data.  Maximum size is 65,535.
	 * \sa ITriShapeData::GetTriangles
	 */
	NIFLIB_API virtual void SetTriangles( const vector<Triangle> & in );

protected:
	NI_TRI_SHAPE_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
