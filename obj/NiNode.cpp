/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiNode.h"
#include "NiAVObject.h"
#include "NiDynamicEffect.h"
#include "NiSkinInstance.h"

//Definition of TYPE constant
const Type NiNode::TYPE("NiNode", &NI_NODE_PARENT::TYPE );

NiNode::NiNode() NI_NODE_CONSTRUCT {}

NiNode::~NiNode() {
	//Clear Children
	ClearChildren();
}

void NiNode::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_NODE_READ
}

void NiNode::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_NODE_WRITE
}

string NiNode::asString( bool verbose ) const {
	NI_NODE_STRING
}

void NiNode::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_NODE_FIXLINKS
	//Connect children to their parents and remove any NULL ones
	for ( vector< NiAVObjectRef >::iterator it = children.begin(); it != children.end(); ) {
		if ( *it == NULL) {
			it = children.erase( it );
		} else {
			(*it)->SetParent(this);
			++it;
		}
	}
}

list<NiObjectRef> NiNode::GetRefs() const {
	NI_NODE_GETREFS
}

const Type & NiNode::GetType() const {
	return TYPE;
};

void NiNode::AddChild( Ref<NiAVObject> & obj ) {
	if ( obj->GetParent() != NULL ) {
		throw runtime_error( "You have attempted to add a child to a NiNode which already is the child of another NiNode." );
	}
	obj->SetParent( this );
	children.push_back( obj );
}

void NiNode::RemoveChild( Ref<NiAVObject> obj ) {
	//Search child list for the one to remove
	for ( vector< NiAVObjectRef >::iterator it = children.begin(); it != children.end(); ) {
		if ( *it == obj ) {
			//Ensure that this child is not a skin influence
			NiNodeRef niNode = DynamicCast<NiNode>((*it));
			if ( niNode != NULL && niNode->IsSkinInfluence() == true ) {
				throw runtime_error("You cannot remove a node child that is a skin influence.  Detatch the skin first.");
			}
			(*it)->SetParent(NULL);
			it = children.erase( it );
		} else {
			++it;
		}
	}
}

void NiNode::ClearChildren() {
	for ( vector< NiAVObjectRef >::iterator it = children.begin(); it != children.end(); ++it) {
      if (*it) (*it)->SetParent(NULL);
	}
	children.clear();
}

vector< Ref<NiAVObject> > NiNode::GetChildren() const {
	return children;
}

bool NiNode::IsSkeletonRoot() const {
	return ( skins.size() > 0 );
}

bool NiNode::IsSkinInfluence() const {
	return ((flags & 8) == 0);
}

void NiNode::GoToSkeletonBindPosition() {
	//TODO:: Implement GoToSkeletonBindPosition()
}

void NiNode::AddSkin( NiSkinInstance * skin_inst ) {
	//Ensure that all bones are below this node on the scene graph
	vector<NiNodeRef> bones = skin_inst->GetBones();
	for ( uint i = 0; i < bones.size(); ++i ) {
		bool is_decended = false;
		NiNodeRef node = bones[i];
		while ( node != NULL ) {
			if ( node == this ) {
				is_decended = true;
				break;
			}
			node = node->GetParent();
		}
		if ( is_decended == false ) {
			throw runtime_error( "All bones must be lower than the skeleton root in the scene graph." );
		}
	}

	//Flag any bones that are part of this skin instance
	for ( uint i = 0; i < bones.size(); ++i ) {
		bones[i]->SetSkinFlag(true);
	}
	
	skins.push_back( skin_inst );
}

void NiNode::RemoveSkin( NiSkinInstance * skin_inst ) {
	//Unflag any bones that were part of this skin instance
	vector<NiNodeRef> bones = skin_inst->GetBones();
	for ( uint i = 0; i < bones.size(); ++i ) {
		bones[i]->SetSkinFlag(false);
	}
	
	//Remove the reference
	skins.remove( skin_inst);

	//Ensure that any multiply referenced bone nodes still
	//have their skin flag set
	for ( list<NiSkinInstance*>::iterator it = skins.begin(); it != skins.end(); ++it ) {
		bones = (*it)->GetBones();
		for ( uint i = 0; i < bones.size(); ++i ) {
			bones[i]->SetSkinFlag(true);
		}
	}
}

void NiNode::SetSkinFlag( bool n ) {
	if ( IsSkinInfluence() == n ) {
		//Already set to the requested value
		return;
	} else {
		//Requested value is different, flip bit
		flags ^= 8;
	}
}