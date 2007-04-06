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

class NiGeometry : public NI_GEOMETRY_PARENT {
public:
	NIFLIB_API NiGeometry();
	NIFLIB_API ~NiGeometry();
	//Run-Time Type Information
	NIFLIB_API static const Type & TypeConst();
private:
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Binds this geometry to a list of bones.  Creates and attatches a
	 * NiSkinInstance and NiSkinData class. The bones must have a common
	 * ancestor in the scenegraph.  This becomes the skeleton root.
	 */
	NIFLIB_API void BindSkin( vector< Ref<NiNode> > bone_nodes );

	NIFLIB_API void UnbindSkin();

	/*!
	 * Sets the skin weights in the attached NiSkinData object.
	 * The version on this class calculates the center and radius of
	 * each set of affected vertices automatically.
	 */
	NIFLIB_API void SetBoneWeights( unsigned int bone_index, const vector<SkinWeight> & n );

	NIFLIB_API Ref<NiSkinInstance> GetSkinInstance() const;

	NIFLIB_API Ref<NiGeometryData> GetData() const;
	NIFLIB_API void SetData( const Ref<NiGeometryData> & n );

	NIFLIB_API Ref<NiObject> GetUnknownLink() const;
	NIFLIB_API void SetUnknownLink( const Ref<NiObject> & n );

	NIFLIB_API string GetShader() const;
	NIFLIB_API void SetShader( const string & n );

	/*
	 * Returns the position of the verticies and values of the normals after they
	 * have been deformed by the positions of their skin influences.
	 * \param[out] vertices A vector that will be filled with the skin deformed position of the verticies.
	 * \param[out] normals A vector thta will be filled with the skin deformed normal values.
	 */
	NIFLIB_API void GetSkinDeformation( vector<Vector3> & vertices, vector<Vector3> & normals ) const;

	/*
	 * Applies the local transform values to the vertices of the geometry and
	 * zeros them out to the identity.
	 */
	NIFLIB_API void ApplyTransforms();

	/*
	 * Propogates the transforms between this skin and the skeleton root,
	 * and then applies them to the verticies of this skin.  Sets the overall
	 * skin data transform to the identity.
	 */
	NIFLIB_API void ApplySkinOffset();

	NIFLIB_API void NormalizeSkinWeights();

	/*
	 * Used to determine whether this mesh is influenced by bones as a skin.
	 * \return true if this mesh is a skin, false otherwise.
	 */
	NIFLIB_API bool IsSkin();

protected:
	list< Ref<NiNode> > ListAncestors( const Ref<NiNode> & leaf ) const;
	NI_GEOMETRY_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
