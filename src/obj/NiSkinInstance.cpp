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
#include "../../include/NIF_IO.h"
#include "../../include/obj/NiSkinInstance.h"
#include "../../include/obj/NiSkinData.h"
#include "../../include/obj/NiSkinPartition.h"
#include "../../include/obj/NiNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiSkinInstance::TYPE("NiSkinInstance", &NiObject::TYPE );

NiSkinInstance::NiSkinInstance() : data(NULL), skinPartition(NULL), skeletonRoot(NULL), numBones((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiSkinInstance::~NiSkinInstance() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//Unflag any bones that were part of this skin instance
	for ( unsigned int i = 0; i < bones.size(); ++i ) {
		bones[i]->SetSkinFlag(false);
	}

	//Inform Skeleton Root of detatchment and clear it.
	if ( skeletonRoot != NULL ) {
		skeletonRoot->RemoveSkin( this );
		skeletonRoot = NULL;
	}

	//--END CUSTOM CODE--//
}

const Type & NiSkinInstance::GetType() const {
	return TYPE;
}

namespace Niflib {
	typedef NiObject*(*obj_factory_func)();
	extern map<string, obj_factory_func> global_object_map;

	//Initialization function
	static bool Initialization();

	//A static bool to force the initialization to happen pre-main
	static bool obj_initialized = Initialization();

	static bool Initialization() {
		//Add the function to the global object map
		global_object_map["NiSkinInstance"] = NiSkinInstance::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiSkinInstance::Create() {
	return new NiSkinInstance;
}

void NiSkinInstance::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	if ( info.version >= 0x0A020000 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( numBones, in, info );
	bones.resize(numBones);
	for (unsigned int i1 = 0; i1 < bones.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiSkinInstance::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, info );
	numBones = (unsigned int)(bones.size());
	if ( data != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(data) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	if ( info.version >= 0x0A020000 ) {
		if ( skinPartition != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(skinPartition) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
	if ( skeletonRoot != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(skeletonRoot) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	NifStream( numBones, out, info );
	for (unsigned int i1 = 0; i1 < bones.size(); i1++) {
		if ( bones[i1] != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(bones[i1]) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiSkinInstance::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	numBones = (unsigned int)(bones.size());
	out << "  Data:  " << data << endl;
	out << "  Skin Partition:  " << skinPartition << endl;
	out << "  Skeleton Root:  " << skeletonRoot << endl;
	out << "  Num Bones:  " << numBones << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < bones.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Bones[" << i1 << "]:  " << bones[i1] << endl;
		array_output_count++;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiSkinInstance::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, info );
	data = FixLink<NiSkinData>( objects, link_stack, info );
	if ( info.version >= 0x0A020000 ) {
		skinPartition = FixLink<NiSkinPartition>( objects, link_stack, info );
	};
	skeletonRoot = FixLink<NiNode>( objects, link_stack, info );
	for (unsigned int i1 = 0; i1 < bones.size(); i1++) {
		bones[i1] = FixLink<NiNode>( objects, link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//Inform newly fixed skeleton root of attachment
	if ( skeletonRoot != NULL ) {
		skeletonRoot->AddSkin( this );
	}

	//Ensure that bones have the flag set properly
	for ( unsigned int i = 0; i < bones.size(); ++i ) {
		bones[i]->SetSkinFlag(true);
	}

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiSkinInstance::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	if ( skinPartition != NULL )
		refs.push_back(StaticCast<NiObject>(skinPartition));
	for (unsigned int i1 = 0; i1 < bones.size(); i1++) {
	};
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

vector< Ref<NiNode> > NiSkinInstance::GetBones() const {
	vector<NiNodeRef> ref_bones( bones.size() );
	for (unsigned int i = 0; i < bones.size(); ++i ) {
		ref_bones[i] = bones[i];
	}
	return ref_bones;
}

Ref<NiSkinData> NiSkinInstance::GetSkinData() const {
	return data;
}

void NiSkinInstance::SetSkinData( NiSkinData * n ) {
	data = n;
}

Ref<NiSkinPartition> NiSkinInstance::GetSkinPartition() const {
	return skinPartition;
}

void NiSkinInstance::SetSkinPartition( NiSkinPartition * n ) {
	skinPartition = n;
}

void NiSkinInstance::SkeletonLost() {
	skeletonRoot = NULL;

	//Clear bone list
	bones.clear();

	//Destroy skin data
	data = NULL;
	skinPartition = NULL;
}

unsigned int NiSkinInstance::GetBoneCount() const {
	return (unsigned int)(bones.size());
}

Ref<NiNode> NiSkinInstance::GetSkeletonRoot() const {
	return skeletonRoot;
}

NiSkinInstance::NiSkinInstance( NiNode * skeleton_root, vector< Ref<NiNode> > bone_nodes ) {
	//Call normal constructor
	NiSkinInstance();

	//Ensure that all bones are below the skeleton root node on the scene graph
	for ( unsigned int i = 0; i < bone_nodes.size(); ++i ) {
		bool is_decended = false;
		NiNodeRef node = bone_nodes[i];
		while ( node != NULL ) {
			if ( node == skeleton_root ) {
				is_decended = true;
				break;
			}
			node = node->GetParent();
		}
		if ( is_decended == false ) {
			throw runtime_error( "All bones must be lower than the skeleton root in the scene graph." );
		}
	}

	//Add the bones to the internal list
	bones.resize( bone_nodes.size() );
	for ( unsigned int i = 0; i < bone_nodes.size(); ++i ) {
		bones[i] = bone_nodes[i];
	}

	//Flag any bones that are part of this skin instance
	for ( unsigned int i = 0; i < bones.size(); ++i ) {
		bones[i]->SetSkinFlag(true);
	}

	//Store skeleton root and inform it of this attachment
	skeletonRoot = skeleton_root;
	skeletonRoot->AddSkin( this );
}

//--END CUSTOM CODE--//
