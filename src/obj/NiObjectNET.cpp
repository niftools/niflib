/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiObjectNET.h"
#include "../../include/obj/NiExtraData.h"
#include "../../include/obj/NiTimeController.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiObjectNET::TYPE("NiObjectNET", &NI_OBJECT_N_E_T_PARENT::TYPE );

NiObjectNET::NiObjectNET() NI_OBJECT_N_E_T_CONSTRUCT {}

NiObjectNET::~NiObjectNET() {
	//Clear Lists
	ClearExtraData();
	ClearControllers();
}

void NiObjectNET::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiObjectNET::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiObjectNET::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiObjectNET::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiObjectNET::GetRefs() const {
	return InternalGetRefs();
}

string NiObjectNET::GetName() {
	return name;
}

void NiObjectNET::SetName( const string & new_name ) {
	name = new_name;
}

/*! Used to format a human readable string that includes the type of the object */
string NiObjectNET::GetIDString() const {
	stringstream out;
	out << NiObject::GetIDString() << " {" << name << "}";
	return out.str();
}

void NiObjectNET::AddExtraData( NiExtraData * obj, unsigned int version ) {
	if ( version >= VER_10_0_1_0 ) {
		//In later versions, extra data is just stored in a vector
		extraDataList.push_back( NiExtraDataRef(obj) );
	} else {
		//In earlier versions, extra data is a singly linked list
		//Insert at begining of list
		obj->SetNextExtraData( extraData);
		extraData = NiExtraDataRef(obj);
	}
}

void NiObjectNET::RemoveExtraData( NiExtraData * obj ) {
	//Search both types of extra data list for the one to remove
	NiExtraDataRef ref(obj);
	for ( vector< NiExtraDataRef >::iterator it = extraDataList.begin(); it != extraDataList.end(); ) {
		if ( *it == ref ) {
			it = extraDataList.erase( it );
		} else {
			++it;
		}
	}
	
	NiExtraDataRef * extra = &extraData;
	while ( (*extra) != NULL ) {
		if ( (*extra) == ref ) {
			//Cut this reference out of the list
			(*extra) = (*extra)->GetNextExtraData();
		} else {
			//Advance to the next extra data
			NiExtraDataRef temp = (*extra)->GetNextExtraData();
			extra = &temp;
			temp = NULL;
		}
	}
}

void NiObjectNET::ShiftExtraData( unsigned version ) {
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

bool NiObjectNET::IsAnimated() {
	return ( controller != NULL );
}

void NiObjectNET::AddController( NiTimeController * obj ) {
	//Insert at begining of list
	obj->SetTarget( this );
	obj->SetNextController( controller );
	controller = obj;
}

void NiObjectNET::RemoveController( NiTimeController * obj ) {
	NiTimeControllerRef ref(obj);
	for(NiTimeControllerRef last = controller, cont = last, next; cont != NULL; cont = next ) {
      next = cont->GetNextController();
		if ( cont == ref ) {
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

const Type & NiObjectNET::GetType() const {
	return TYPE;
};

namespace Niflib { 
	typedef NiObject*(*obj_factory_func)();
	extern map<string, obj_factory_func> global_object_map;

	//Initialization function
	static bool Initialization();

	//A static bool to force the initialization to happen pre-main
	static bool obj_initialized = Initialization();

	static bool Initialization() {
		//Add the function to the global object map
		global_object_map["NiObjectNET"] = NiObjectNET::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiObjectNET::Create() {
	return new NiObjectNET;
}
