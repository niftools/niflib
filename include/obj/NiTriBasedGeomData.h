/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NITRIBASEDGEOMDATA_H_
#define _NITRIBASEDGEOMDATA_H_

#include "NiGeometryData.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class NiObject;

//#include "../gen/obj_defines.h"

class NiTriBasedGeomData;
typedef Ref<NiTriBasedGeomData> NiTriBasedGeomDataRef;

/*!
 * NiTriBasedGeomData - Mesh data: vertices, vertex normals, etc.
 */

class NIFLIB_API NiTriBasedGeomData : public NI_TRI_BASED_GEOM_DATA_PARENT {
public:
	NiTriBasedGeomData();
	~NiTriBasedGeomData();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:	
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;



	/*! Returns the triangle faces that make up this mesh.
	 * \return A vector containing the triangle faces that make up this mesh.
	 * \sa SetTriangles
	 */
	virtual vector<Triangle> GetTriangles() const { return vector<Triangle>(); }  //TODO:  Make this pure virtual?

   /*! Replaces the triangle face data in this mesh with new data.
   * \param in A vector containing the new face data.  Maximum size is 65,535.
   * \sa GetTriangles
   */
   virtual void SetTriangles( const vector<Triangle> & in );

protected:
	NI_TRI_BASED_GEOM_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
