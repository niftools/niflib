/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NITRISHAPEDATA_H_
#define _NITRISHAPEDATA_H_

#include "NiTriBasedGeomData.h"
// Include structures
#include "../gen/MatchGroup.h"

#include "../gen/obj_defines.h"

class NiTriShapeData;
typedef Ref<NiTriShapeData> NiTriShapeDataRef;

/*!
 * NiTriShapeData - Holds mesh data using a list of singular triangles.
 */

class NiTriShapeData : public NI_TRI_SHAPE_DATA_PARENT {
public:
	NiTriShapeData();
	~NiTriShapeData();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_TRI_SHAPE_DATA_MEMBERS

	//--Match Detection--//
	
	//Re-implemented only to casue match detection data to be cleared
	//when vertices are updated.
	virtual void SetVertices( const vector<Vector3> & in );

	/*! This function generates match detection data based on the current
	 * vertex list.  The function of this data is unknown and appears to be
	 * optional.  The data contains a list of all the vertices that have
	 * identical positions are stored in the file.  If the vertex data is
	 * updated, match detection data will be cleared.
	 * \sa NiTriShapeData::HasMatchData
	 */
	void DoMatchDetection();

	/*! Used to determine whether current match detection data has been previously
	 * generated.
	 * \return true if there is current match data, false otherwise.
	 * \sa NiTriShapeData::DoMatchDetection
	 */
	bool HasMatchData();

	//--Getters--//

	/*! Returns the triangle faces that make up this mesh.
	 * \return A vector containing the triangle faces that make up this mesh.
	 * \sa ITriShapeData::SetTriangles
	 */
	virtual vector<Triangle> GetTriangles() const;

	//--Setters--//

	/*! Replaces the triangle face data in this mesh with new data.
	 * \param in A vector containing the new face data.  Maximum size is 65,535.
	 * \sa ITriShapeData::GetTriangles
	 */
	void SetTriangles( const vector<Triangle> & in );
};

#endif
