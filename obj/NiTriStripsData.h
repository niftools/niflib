/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NITRISTRIPSDATA_H_
#define _NITRISTRIPSDATA_H_

#include "NiTriBasedGeomData.h"

#include "../gen/obj_defines.h"

class NiTriStripsData;
typedef Ref<NiTriStripsData> NiTriStripsDataRef;

/*!
 * NiTriStripsData - Holds mesh data using strips of triangles.
 */

class DLLEXPORT NiTriStripsData : public NI_TRI_STRIPS_DATA_PARENT {
public:
	NiTriStripsData();
	~NiTriStripsData();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	//--Counts--//

	/*! Used to get the number of triangle strips that this mesh is divided into.
	 * \return The number of triangle strips used by this mesh.
	 * \sa NiTriStripData::SetStripCount
	 */
	ushort GetStripCount() const;

	/*! Used to resize the triangle strips array.  If the new size is smaller, strips at the end of the array will be deleted.
	 * \param n The new size of the triangle strips array.
	 * \sa NiTriStripData::GetStripCount
	 */
	void SetStripCount(int n);
	
	//--Getters--//

	/*! Used to retrieve all the triangles from a specific triangle strip.
	 * \param index The index of the triangle strip to retrieve the triangles from.  This is a zero-based index which must be a positive number less than that returned by NiTriStripsData::GetStripCount.
	 * \return A vector containing all the triangle faces from the triangle strip specified by index.
	 * \sa NiTriStripData::SetStrip, NiTriStripData::GetTriangles
	 */
	vector<ushort> GetStrip( int index ) const;

	/*! This is a conveniance function which returns all triangle faces in all triangle strips that make up this mesh.  It is similar to the ITriShapeData::GetTriangles function.
	 * \return A vector containing all the triangle faces from all the triangle strips that make up this mesh.
	 * \sa NiTriStripData::GetTriangles, NiTriStripData::GetStrip, NiTriStripData::SetStrip
	 */
	vector<Triangle> GetTriangles() const;

	//--Setter--/

	/*! Used to set the triangle face data in a specific triangle strip.
	 * \param index The index of the triangle strip to set the face data for.  This is a zero-based index which must be a positive number less than that returned by NiTriStripsData::GetStripCount.
	 * \sa NiTriStripData::GetStrip, NiTriStripData::GetTriangles
	 */
	void SetStrip( int index, const vector<ushort> & in );

private:
	ushort CalcTriangleCount() const;

protected:
	NI_TRI_STRIPS_DATA_MEMBERS
};

#endif
