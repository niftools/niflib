/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NITRIBASEDGEOM_H_
#define _NITRIBASEDGEOM_H_

#include "NiGeometry.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks

//#include "../gen/obj_defines.h"

class NiTriBasedGeom;
typedef Ref<NiTriBasedGeom> NiTriBasedGeomRef;

/*!
 * NiTriBasedGeom - Describes a mesh, built from triangles.
 */

class NiTriBasedGeom : public NI_TRI_BASED_GEOM_PARENT {
public:
	NIFLIB_API NiTriBasedGeom();
	NIFLIB_API ~NiTriBasedGeom();
	//Run-Time Type Information
	NIFLIB_API static const Type & TypeConst() { return TYPE; }
private:	
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const { return TYPE; };
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	NIFLIB_API void GenHardwareSkinInfo( int max_bones_per_partition = 4, int max_bones_per_vertex = 4 );

	/*!
	 * Generate or update a NiStringExtraData block with precalculated
	 * tangent and binormal data (Oblivion specific)
	 */
	NIFLIB_API void UpdateTangentSpace();

protected:
	NI_TRI_BASED_GEOM_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
