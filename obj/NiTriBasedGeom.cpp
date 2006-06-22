/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiTriBasedGeom.h"
#include "NiTriBasedGeomData.h"
#include "NiSkinInstance.h"
#include "NiObject.h"
#include "NiSkinData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTriBasedGeom::TYPE("NiTriBasedGeom", &NI_TRI_BASED_GEOM_PARENT::TypeConst() );

NiTriBasedGeom::NiTriBasedGeom() NI_TRI_BASED_GEOM_CONSTRUCT {}

NiTriBasedGeom::~NiTriBasedGeom() {}

void NiTriBasedGeom::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_TRI_BASED_GEOM_READ
}

void NiTriBasedGeom::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_TRI_BASED_GEOM_WRITE
}

string NiTriBasedGeom::asString( bool verbose ) const {
	NI_TRI_BASED_GEOM_STRING
}

void NiTriBasedGeom::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_TRI_BASED_GEOM_FIXLINKS
}

list<NiObjectRef> NiTriBasedGeom::GetRefs() const {
	NI_TRI_BASED_GEOM_GETREFS
}

const Type & NiTriBasedGeom::GetType() const {
	return TYPE;
};

Ref<NiTriBasedGeomData> NiTriBasedGeom::GetData() const {
	return data;
}

void NiTriBasedGeom::SetData( const Ref<NiTriBasedGeomData> & n ) {
	data = n;
}

Ref<NiObject> NiTriBasedGeom::GetUnknownLink() const {
	return unknownLink;
}

void NiTriBasedGeom::SetUnknownLink( const Ref<NiObject> & n ) {
	unknownLink = n;
}

string NiTriBasedGeom::GetShader() const {
	return shaderName;
}

void NiTriBasedGeom::SetShader( const string & n ) {
	//Check if name is blank, if so clear shader
	if ( n.size() == 0 ) {
		hasShader = false;
		shaderName.clear();
	} else {
		shaderName = n;
	}
}

Ref<NiSkinInstance> NiTriBasedGeom::GetSkinInstance() const {
	return skinInstance;
}

void NiTriBasedGeom::BindSkin( Ref<NiNode> skeleton_root, vector< Ref<NiNode> > bone_nodes ) {
	//Ensure skin is not aleady bound
	if ( skinInstance != 0 ) {
		throw runtime_error("You have attempted to re-bind a skin that is already bound.  Unbind it first.");
	}

	//Create a skin instance using the bone and root data
	skinInstance = new NiSkinInstance( skeleton_root, bone_nodes );

	//Create a NiSkinData object based on this mesh
	skinInstance->SetSkinData( new NiSkinData( this ) );
};

void NiTriBasedGeom::UnbindSkin() {
	//Clear skin instance
	skinInstance = NULL;
}