/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NITRIBASEDGEOM_H_
#define _NITRIBASEDGEOM_H_

#include "NiAVObject.h"

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
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	/*!
	 * Binds this geometry to a list of bones.  Creates and attatches a
	 * NiSkinInstance and NiSkinData class. The bones must have a common
	 * ancestor in the scenegraph.  This becomes the skeleton root.
	 */
	void BindSkin( Ref<NiNode> skeleton_root, vector< Ref<NiNode> > bone_nodes );
	void UnbindSkin();
	Ref<NiSkinInstance> GetSkinInstance() const;

	Ref<NiTriBasedGeomData> GetData() const;
	void SetData( const Ref<NiTriBasedGeomData> & n );

	Ref<NiObject> GetUnknownLink() const;
	void SetUnknownLink( const Ref<NiObject> & n );

	string GetShader() const;
	void SetShader( const string & n );

	
	
protected:
	NI_TRI_BASED_GEOM_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
