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

//#include "../gen/obj_defines.h"

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
	virtual void Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	/*!
	 * Binds this geometry to a list of bones.  Creates and attatches a
	 * NiSkinInstance and NiSkinData class. The bones must have a common
	 * ancestor in the scenegraph.  This becomes the skeleton root.
	 */
	void BindSkin( vector< Ref<NiNode> > bone_nodes );

	void UnbindSkin();

	/*!
	 * Sets the skin weights in the attached NiSkinData object.
	 * The version on this class calculates the center and radius of
	 * each set of affected vertices automatically.
	 */
	void SetBoneWeights( unsigned int bone_index, const vector<SkinWeight> & n );

	Ref<NiSkinInstance> GetSkinInstance() const;

	Ref<NiGeometryData> GetData() const;
	void SetData( const Ref<NiGeometryData> & n );

	Ref<NiObject> GetUnknownLink() const;
	void SetUnknownLink( const Ref<NiObject> & n );

	string GetShader() const;
	void SetShader( const string & n );

	/*
	 * Returns the position of the verticies and values of the normals after they
	 * have been deformed by the positions of their skin influences.
	 * \param[out] vertices A vector that will be filled with the skin deformed position of the verticies.
	 * \param[out] normals A vector thta will be filled with the skin deformed normal values.
	 */
	void GetSkinDeformation( vector<Vector3> & vertices, vector<Vector3> & normals ) const;

	/*
	 * Applies the local transform values to the vertices of the geometry and
	 * zeros them out to the identity.
	 */
	void ApplyTransforms();

	/*
	 * Propogates the transforms between this skin and the skeleton root,
	 * and then applies them to the verticies of this skin.  Sets the overall
	 * skin data transform to the identity.
	 */
	void ApplySkinOffset();

	void NormalizeSkinWeights();

	/*
	 * Used to determine whether this mesh is influenced by bones as a skin.
	 * \return true if this mesh is a skin, false otherwise.
	 */
	bool IsSkin();

protected:
	list< Ref<NiNode> > ListAncestors( const Ref<NiNode> & leaf ) const;
	NI_GEOMETRY_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
