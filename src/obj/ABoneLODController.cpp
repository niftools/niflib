/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/ABoneLODController.h"
#include "../../include/gen/NodeGroup.h"
#include "../../include/obj/NiNode.h"
#include <algorithm>
using namespace Niflib;

//Definition of TYPE constant
const Type ABoneLODController::TYPE("ABoneLODController", &A_BONE_L_O_D_CONTROLLER_PARENT::TypeConst() );

ABoneLODController::ABoneLODController() A_BONE_L_O_D_CONTROLLER_CONSTRUCT {}

ABoneLODController::~ABoneLODController() {}

void ABoneLODController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void ABoneLODController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string ABoneLODController::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void ABoneLODController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> ABoneLODController::GetRefs() const {
	return InternalGetRefs();
}

const Type & ABoneLODController::GetType() const {
	return TYPE;
};

/*!
 * A list of node groups (each group a sequence of bones?).
 */
int ABoneLODController::GetNodeGroupCount() const {
   return int(nodeGroups.size());
}

vector<Ref<NiNode> > ABoneLODController::GetNodeGroup( int index ) const {
   if (index < 0 || index >= int(nodeGroups.size()) ) {
      throw runtime_error("Invalid index referenced.");
   }
   vector<NiNodeRef> value;
   const vector<NiNode*>& nodes = nodeGroups[index].nodes;
   for (vector<NiNode*>::const_iterator itr = nodes.begin(); itr != nodes.end(); ++itr)
      value.push_back(*itr);
   return value;
}

void ABoneLODController::AddNodeToGroup( int index, NiNode * node ) {
   while (index >= int(nodeGroups.size()))
      nodeGroups.insert(nodeGroups.end(), NodeGroup() );
   numNodeGroups2 = nodeGroups.size();

   vector<NiNode*>& nodes = nodeGroups[index].nodes;
   vector<NiNode*>::iterator itr = std::find(nodes.begin(), nodes.end(), node);
   if (itr == nodes.end())
      nodes.push_back(node);
}

void ABoneLODController::RemoveNodeFromGroup( int index, NiNode * node ) {
   if (index < 0 || index >= int(nodeGroups.size()) ) {
      throw runtime_error("Invalid index referenced.");
   }
   vector<NiNode*>& nodes = nodeGroups[index].nodes;
   vector<NiNode*>::iterator itr = std::find(nodes.begin(), nodes.end(), node);
   if (itr == nodes.end())
      return;
   nodes.erase(itr);
}

void ABoneLODController::SetNodeGroup( int index, const vector<Ref<NiNode> >& group ) {
   while (index >= int(nodeGroups.size()))
      nodeGroups.insert(nodeGroups.end(), NodeGroup() );
   numNodeGroups2 = nodeGroups.size();
   nodeGroups[index].nodes.assign(group.begin(), group.end());
}

void ABoneLODController::RemoveNodeGroup( int index ) {
   if (index < 0 || index >= int(nodeGroups.size()) ) {
      throw runtime_error("Invalid index referenced.");
   }
   vector<NodeGroup>::iterator itr = nodeGroups.begin();
   std::advance(itr, index);
   nodeGroups.erase(itr);
   numNodeGroups2 = nodeGroups.size();
}

void ABoneLODController::ClearNodeGroups() {
   nodeGroups.clear();
   numNodeGroups2 = nodeGroups.size();
}

const Type & ABoneLODController::TypeConst() {
	return TYPE;
}
