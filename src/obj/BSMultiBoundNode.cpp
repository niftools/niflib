/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

//--BEGIN FILE HEAD CUSTOM CODE--//

//--END CUSTOM CODE--//

#include "../../include/FixLink.h"
#include "../../include/ObjectRegistry.h"
#include "../../include/NIF_IO.h"
#include "../../include/obj/BSMultiBoundNode.h"
#include "../../include/obj/BSMultiBound.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSMultiBoundNode::TYPE("BSMultiBoundNode", &NiNode::TYPE );

BSMultiBoundNode::BSMultiBoundNode() : multiBound(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

BSMultiBoundNode::~BSMultiBoundNode() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & BSMultiBoundNode::GetType() const {
	return TYPE;
}

NiObject * BSMultiBoundNode::Create() {
	return new BSMultiBoundNode;
}

void BSMultiBoundNode::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiNode::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSMultiBoundNode::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiNode::Write( out, link_map, info );
	if ( info.version < VER_3_3_0_13 ) {
		WritePtr32( &(*multiBound), out );
	} else {
		if ( multiBound != NULL ) {
			NifStream( link_map.find( StaticCast<NiObject>(multiBound) )->second, out, info );
		} else {
			NifStream( 0xFFFFFFFF, out, info );
		}
	}

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string BSMultiBoundNode::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiNode::asString();
	out << "  Multi Bound:  " << multiBound << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSMultiBoundNode::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiNode::FixLinks( objects, link_stack, info );
	multiBound = FixLink<BSMultiBound>( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> BSMultiBoundNode::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiNode::GetRefs();
	if ( multiBound != NULL )
		refs.push_back(StaticCast<NiObject>(multiBound));
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
