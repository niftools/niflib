/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiControllerManager.h"
#include "../../include/obj/NiControllerSequence.h"
#include "../../include/obj/NiDefaultAVObjectPalette.h"
#include <algorithm>
using namespace Niflib;

//Definition of TYPE constant
const Type NiControllerManager::TYPE("NiControllerManager", &NI_CONTROLLER_MANAGER_PARENT::TypeConst() );

NiControllerManager::NiControllerManager() NI_CONTROLLER_MANAGER_CONSTRUCT {}

NiControllerManager::~NiControllerManager() {}

void NiControllerManager::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiControllerManager::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiControllerManager::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiControllerManager::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiControllerManager::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiControllerManager::GetType() const {
	return TYPE;
};

bool NiControllerManager::GetCumulative() const {
	return cumulative;
}

void NiControllerManager::SetCumulative( bool value ) {
	cumulative = value;
}

vector<Ref<NiControllerSequence > > NiControllerManager::GetControllerSequences() const {
	return controllerSequences;
}

void NiControllerManager::SetControllerSequences( const vector<Ref<NiControllerSequence > >& value ) {
   ClearSequences();
	controllerSequences = value;
   for (vector<NiControllerSequenceRef>::iterator it = controllerSequences.begin(); it != controllerSequences.end(); ++it) {
      (*it)->SetParent(this);
   }
}

void NiControllerManager::AddSequence( Ref<NiControllerSequence > & obj ) {
   vector<NiControllerSequenceRef>::iterator begin = controllerSequences.begin();
   vector<NiControllerSequenceRef>::iterator end = controllerSequences.end();
   vector<NiControllerSequenceRef>::iterator it = std::find(begin, end, obj);
   if (it == end) {
      controllerSequences.insert(end, obj);  
      obj->SetParent(this);
   }
}

void NiControllerManager::RemoveSequence( Ref<NiControllerSequence > obj ) {
   vector<NiControllerSequenceRef>::iterator begin = controllerSequences.begin();
   vector<NiControllerSequenceRef>::iterator end = controllerSequences.end();
   vector<NiControllerSequenceRef>::iterator it = std::find(begin, end, obj);
   if (it != end) {
      (*it)->SetParent(NULL);
      controllerSequences.erase(it);  
   }
}

void NiControllerManager::ClearSequences() {
   for (vector<NiControllerSequenceRef>::iterator it = controllerSequences.begin(); it != controllerSequences.end(); ++it) {
      (*it)->SetParent(NULL);
   }
   controllerSequences.clear();
}


Ref<NiDefaultAVObjectPalette > NiControllerManager::GetObjectPalette() const {
	return objectPalette;
}

void NiControllerManager::SetObjectPalette( Ref<NiDefaultAVObjectPalette > value ) {
	objectPalette = value;
}

const Type & NiControllerManager::TypeConst() {
	return TYPE;
}
