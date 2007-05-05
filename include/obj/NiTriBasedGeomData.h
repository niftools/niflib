/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NITRIBASEDGEOMDATA_H_
#define _NITRIBASEDGEOMDATA_H_

#include "NiGeometryData.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiObject;

//#include "../gen/obj_defines.h"

class NiTriBasedGeomData;
typedef Ref<NiTriBasedGeomData> NiTriBasedGeomDataRef;

/*!
 * NiTriBasedGeomData - Mesh data: vertices, vertex normals, etc.
 */

class NiTriBasedGeomData : public NI_TRI_BASED_GEOM_DATA_PARENT {
public:
	NIFLIB_API NiTriBasedGeomData();
	NIFLIB_API ~NiTriBasedGeomData();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Returns the triangle faces that make up this mesh.
	 * \return A vector containing the triangle faces that make up this mesh.
	 * \sa SetTriangles
	 */
	NIFLIB_API virtual vector<Triangle> GetTriangles() const;

	/*!
	 * Replaces the triangle face data in this mesh with new data.
	 * \param in A vector containing the new face data.  Maximum size is 65,535.
	 * \sa GetTriangles
	 */
	NIFLIB_API virtual void SetTriangles( const vector<Triangle> & in );

protected:
	NI_TRI_BASED_GEOM_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
