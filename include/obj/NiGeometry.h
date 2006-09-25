/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIGEOMETRY_H_
#define _NIGEOMETRY_H_

#include "NiAVObject.h"

// Include structures
#include "../Ref.h"
#include "../gen/SkinWeight.h"

namespace Niflib {

// Forward define of referenced blocks
class NiObject;
class NiGeometryData;
class NiSkinInstance;
class NiNode;

#include "../gen/obj_defines.h"

class NiGeometry;
typedef Ref<NiGeometry> NiGeometryRef;

/*!
 * NiGeometry - Describes a visible scene element with vertices like a
 * mesh, a particle system, lines, etc.
 */

class NIFLIB_API NiGeometry : public NI_GEOMETRY_PARENT {
public:
	NiGeometry();
	~NiGeometry();
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

	Ref<NiSkinInstance> GetSkinInstance() const;

	Ref<NiGeometryData> GetData() const;
	void SetData( const Ref<NiGeometryData> & n );

	Ref<NiObject> GetUnknownLink() const;
	void SetUnknownLink( const Ref<NiObject> & n );

	string GetShader() const;
	void SetShader( const string & n );

	vector<Vector3> GetSkinInfluencedVertices() const;

protected:
	list< Ref<NiNode> > ListAncestors( const Ref<NiNode> & leaf ) const;
	NI_GEOMETRY_MEMBERS
private:
	void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
