/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NITRIBASEDGEOM_H_
#define _NITRIBASEDGEOM_H_

#include "NiAVObject.h"
#include "NiNode.h"
#include "../gen/SkinWeight.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class NiTriBasedGeomData;
class NiSkinInstance;
class NiObject;

#include "../gen/obj_defines.h"

class NiTriBasedGeom;
typedef Ref<NiTriBasedGeom> NiTriBasedGeomRef;

/*!
 * NiTriBasedGeom - Describes a mesh, built from triangles.
 */

class NIFLIB_API NiTriBasedGeom : public NI_TRI_BASED_GEOM_PARENT {
public:
	NiTriBasedGeom();
	~NiTriBasedGeom();
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

	/*!
	 * Binds this geometry to a list of bones.  Creates and attatches a
	 * NiSkinInstance and NiSkinData class. The bones must have a common
	 * ancestor in the scenegraph.  This becomes the skeleton root.
	 */
	void BindSkin( vector< Ref<NiNode> > bone_nodes, bool bind_to_scene = false );
	void UnbindSkin();
	/*!
	 * Sets the skin weights in the attached NiSkinData object.
	 * The version on this class calculates the center and radius of
	 * each set of affected vertices automatically.
	 */
	void SetBoneWeights( uint bone_index, const vector<SkinWeight> & n );

   void GenHardwareSkinInfo( int max_bones_per_partition = 4, int max_bones_per_vertex = 4 );

	Ref<NiSkinInstance> GetSkinInstance() const;

	Ref<NiTriBasedGeomData> GetData() const;
	void SetData( const Ref<NiTriBasedGeomData> & n );

	Ref<NiObject> GetUnknownLink() const;
	void SetUnknownLink( const Ref<NiObject> & n );

	string GetShader() const;
	void SetShader( const string & n );

	vector<Vector3> GetSkinInfluencedVertices() const;

	/*!
	 * Generate or update a NiStringExtraData block with precalculated
	 * tangent and binormal data (Oblivion specific)
	 */
	void UpdateTangentSpace();

protected:
	list< Ref<NiNode> > NiTriBasedGeom::ListAncestors( const Ref<NiNode> & leaf ) const;

	NI_TRI_BASED_GEOM_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
