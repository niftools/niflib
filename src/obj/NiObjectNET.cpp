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
#include "../../include/obj/NiObjectNET.h"
#include "../../include/obj/NiExtraData.h"
#include "../../include/obj/NiTimeController.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiObjectNET::TYPE("NiObjectNET", &NiObject::TYPE );

NiObjectNET::NiObjectNET() : extraData(NULL), numExtraDataList((unsigned int)0), controller(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiObjectNET::~NiObjectNET() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//Clear Lists
	ClearExtraData();
	ClearControllers();

	//--END CUSTOM CODE--//
}

const Type & NiObjectNET::GetType() const {
	return TYPE;
}

NiObject * NiObjectNET::Create() {
	return new NiObjectNET;
}

void NiObjectNET::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	NifStream( name, in, info );
	if ( info.version <= 0x04020200 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	if ( info.version >= 0x0A000100 ) {
		NifStream( numExtraDataList, in, info );
		extraDataList.resize(numExtraDataList);
		for (unsigned int i2 = 0; i2 < extraDataList.size(); i2++) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
	};
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiObjectNET::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, info );
	numExtraDataList = (unsigned int)(extraDataList.size());
	NifStream( name, out, info );
	if ( info.version <= 0x04020200 ) {
		if ( info.version < VER_3_3_0_13 ) {
			NifStream( (unsigned int)&(*extraData), out, info );
		} else {
			if ( extraData != NULL ) {
				NifStream( link_map.find( StaticCast<NiObject>(extraData) )->second, out, info );
			} else {
				NifStream( 0xFFFFFFFF, out, info );
			}
		}
	};
	if ( info.version >= 0x0A000100 ) {
		NifStream( numExtraDataList, out, info );
		for (unsigned int i2 = 0; i2 < extraDataList.size(); i2++) {
			if ( info.version < VER_3_3_0_13 ) {
				NifStream( (unsigned int)&(*extraDataList[i2]), out, info );
			} else {
				if ( extraDataList[i2] != NULL ) {
					NifStream( link_map.find( StaticCast<NiObject>(extraDataList[i2]) )->second, out, info );
				} else {
					NifStream( 0xFFFFFFFF, out, info );
				}
			}
		};
	};
	if ( info.version < VER_3_3_0_13 ) {
		NifStream( (unsigned int)&(*controller), out, info );
	} else {
		if ( controller != NULL ) {
			NifStream( link_map.find( StaticCast<NiObject>(controller) )->second, out, info );
		} else {
			NifStream( 0xFFFFFFFF, out, info );
		}
	}

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiObjectNET::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	numExtraDataList = (unsigned int)(extraDataList.size());
	out << "  Name:  " << name << endl;
	out << "  Extra Data:  " << extraData << endl;
	out << "  Num Extra Data List:  " << numExtraDataList << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < extraDataList.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Extra Data List[" << i1 << "]:  " << extraDataList[i1] << endl;
		array_output_count++;
	};
	out << "  Controller:  " << controller << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiObjectNET::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, info );
	if ( info.version <= 0x04020200 ) {
		extraData = FixLink<NiExtraData>( objects, link_stack, info );
	};
	if ( info.version >= 0x0A000100 ) {
		for (unsigned int i2 = 0; i2 < extraDataList.size(); i2++) {
			extraDataList[i2] = FixLink<NiExtraData>( objects, link_stack, info );
		};
	};
	controller = FixLink<NiTimeController>( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiObjectNET::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( extraData != NULL )
		refs.push_back(StaticCast<NiObject>(extraData));
	for (unsigned int i1 = 0; i1 < extraDataList.size(); i1++) {
		if ( extraDataList[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(extraDataList[i1]));
	};
	if ( controller != NULL )
		refs.push_back(StaticCast<NiObject>(controller));
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

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

//--END CUSTOM CODE--//
