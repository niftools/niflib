/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiObjectNET.h"
#include "../../include/obj/NiExtraData.h"
#include "../../include/obj/NiTimeController.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiObjectNET::TYPE("NiObjectNET", &NI_OBJECT_N_E_T_PARENT::TypeConst() );

NiObjectNET::NiObjectNET() NI_OBJECT_N_E_T_CONSTRUCT {}

NiObjectNET::~NiObjectNET() {
	//Clear Lists
	ClearExtraData();
	ClearControllers();
}

void NiObjectNET::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_OBJECT_N_E_T_READ
}

void NiObjectNET::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_OBJECT_N_E_T_WRITE
}

string NiObjectNET::asString( bool verbose ) const {
	NI_OBJECT_N_E_T_STRING
}

void NiObjectNET::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_OBJECT_N_E_T_FIXLINKS
}

list<NiObjectRef> NiObjectNET::GetRefs() const {
	NI_OBJECT_N_E_T_GETREFS
}

string NiObjectNET::GetName() {
	return name;
}

void NiObjectNET::SetName( const string & new_name ) {
	name = new_name;
}

/*! Used to format a human readable string that includes the type of the object */
string NiObjectNET::GetIDString() {
	stringstream out;
	out << NiObject::GetIDString() << " {" << name << "}";
	return out.str();
}

void NiObjectNET::AddExtraData( Ref<NiExtraData> & obj, uint version ) {
	if ( version >= VER_10_0_1_0 ) {
		//In later versions, extra data is just stored in a vector
		extraDataList.push_back( obj );
	} else {
		//In earlier versions, extra data is a singly linked list
		//Insert at begining of list
		obj->SetNextExtraData( extraData);
		extraData = obj;
	}
}

void NiObjectNET::RemoveExtraData( Ref<NiExtraData> obj ) {
	//Search both types of extra data list for the one to remove
	for ( vector< NiExtraDataRef >::iterator it = extraDataList.begin(); it != extraDataList.end(); ) {
		if ( *it == obj ) {
			it = extraDataList.erase( it );
		} else {
			++it;
		}
	}
	
	NiExtraDataRef * extra = &extraData;
	while ( (*extra) != NULL ) {
		if ( (*extra) == obj ) {
			//Cut this reference out of the list
			(*extra) = (*extra)->GetNextExtraData();
		} else {
			//Advance to the next extra data
			extra = &((*extra)->GetNextExtraData());
		}
	}
}

void NiObjectNET::ShiftExtraData( uint version ) {
	//Shift any extra data references that are stored in a way that doesn't match
	//the requested version to the way that does
	if ( version >= VER_10_0_1_0 ) {
		//In later versions, extra data is just stored in a vector
		//Empty the linked list into the vector

		NiExtraDataRef extra = extraData;
		while ( extra != NULL ) {
			extraDataList.push_back( extra );
			extra = extra->GetNextExtraData();
			extraDataList.back()->SetNextExtraData(NULL);
		}
		extraData = NULL;
	} else {
		//In earlier versions, extra data is a singly linked list
		//Insert at begining of list
		//Empty the list into the linked list
		for ( vector< NiExtraDataRef >::iterator it = extraDataList.begin(); it != extraDataList.end(); ++it) {
			(*it)->SetNextExtraData( extraData );
			extraData = (*it);
		}
		extraDataList.clear();
	}
}

void NiObjectNET::ClearExtraData() {
	extraDataList.clear();
	extraData = NULL;
}

list< Ref<NiExtraData> > NiObjectNET::GetExtraData() const {
	list< Ref<NiExtraData> > extras;
	for ( vector< NiExtraDataRef >::const_iterator it = extraDataList.begin(); it != extraDataList.end(); ++it) {
		extras.push_back( *it );
	}

	NiExtraDataRef extra = extraData;
	while ( extra != NULL ) {
		extras.push_back( extra );
		extra = extra->GetNextExtraData();
	}

	return extras;
}

void NiObjectNET::AddController( Ref<NiTimeController> & obj ) {
	//Insert at begining of list
	obj->SetTarget( this );
	obj->SetNextController( controller );
	controller = obj;
}

void NiObjectNET::RemoveController( Ref<NiTimeController> obj ) {
	for(NiTimeControllerRef last = controller, cont = last, next; cont != NULL; cont = next ) {
      next = cont->GetNextController();
		if ( cont == obj ) {
			//Cut this reference out of the list
			cont->SetTarget( NULL );
         cont->SetNextController( NiTimeControllerRef() );
         if (cont == controller)
            controller = next;
         else
            last->SetNextController(next);
		} else {
			//Advance last to current controller
         last = cont;
		}
	}
}
void NiObjectNET::ClearControllers() {
	NiTimeControllerRef * cont = &controller;
	while ( (*cont) != NULL ) {
	   (*cont)->SetTarget(NULL);
      (*cont) = (*cont)->GetNextController();
	}
}

list< Ref<NiTimeController> > NiObjectNET::GetControllers() const {
	list< Ref<NiTimeController> > conts;

	NiTimeControllerRef cont = controller;
	while ( cont != NULL ) {
		conts.push_back( cont );
		cont = cont->GetNextController();
	}

	return conts;
}