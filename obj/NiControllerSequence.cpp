/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiControllerSequence.h"
#include "../gen/ControllerLink.h"
#include "NiInterpolator.h"
#include "NiObject.h"
#include "NiStringPalette.h"
#include "../gen/ControllerLink.h"
#include "NiInterpolator.h"
#include "NiObject.h"
#include "NiStringPalette.h"
#include "NiTextKeyExtraData.h"
#include "NiControllerManager.h"
#include "NiStringPalette.h"
#include "NiTimeController.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiControllerSequence::TYPE("NiControllerSequence", &NI_CONTROLLER_SEQUENCE_PARENT::TypeConst() );

NiControllerSequence::NiControllerSequence() NI_CONTROLLER_SEQUENCE_CONSTRUCT {}

NiControllerSequence::~NiControllerSequence() {}

void NiControllerSequence::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_CONTROLLER_SEQUENCE_READ
}

void NiControllerSequence::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_CONTROLLER_SEQUENCE_WRITE
}

string NiControllerSequence::asString( bool verbose ) const {
	NI_CONTROLLER_SEQUENCE_STRING
}

void NiControllerSequence::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_CONTROLLER_SEQUENCE_FIXLINKS
}

list<NiObjectRef> NiControllerSequence::GetRefs() const {
	NI_CONTROLLER_SEQUENCE_GETREFS
}

const Type & NiControllerSequence::GetType() const {
	return TYPE;
};

NiControllerManager * NiControllerSequence::Parent() const { return NULL; }

void NiControllerSequence::SetTextKey( const string new_name, const Ref<NiTextKeyExtraData> & txt_key ) {
	//Set new name
	textKeys.name = new_name;
	throw runtime_error("The SetTextKey function cannot be implemented until prolems in the XML are solved.");
	//TODO: "ControllerLink" can only link to Interpolators.  This is incorrect.  Must be fixed in XML.
	//Need to set txt_key reference to a variable in textKeys
}

void NiControllerSequence::AddController( const string target_name, const Ref<NiTimeController> & obj ) {
	//Make sure the link isn't null
	if ( obj == NULL ) {
		throw runtime_error("Attempted to add a null controller to NiControllerSequence block.");
	}

	throw runtime_error("The AddController function cannot be implemented until prolems in the XML are solved.");
	//TODO:  ControllerLinks should store controllers, not interpolators.  Cannot implement this.
	//KfChild kc;

	
	//kc.block = new_link;

	////Check for a string palette
	//blk_ref str_pal = GetAttr("String Palette")->asLink();
	//if ( str_pal.is_null() == true ) {
	//	//No string palette, store name internally
	//	kc.name = new_name;
	//} else {
	//	//String palette exists - store name and controller type there

	//	//Make sure they didn't give us empty strings
	//	if ( new_name.size() == 0 || controller_type.size() == 0 ) {
	//		throw runtime_error( "You cannot use empty name or controller type strings when using a string palette.");
	//	}

	//	//Get palette
	//	string pal = str_pal->GetAttr("Palette")->asString();

	//	//--Search for copies of the text we want to add--//

	//	//Search for the name string
	//	int offset = (int)pal.find( new_name );
	//	if ( offset == -1 ) {
	//		//String not found, append it
	//		kc.name_offset = (uint)pal.size();
	//		pal.append( new_name + '\0' );
	//	} else {
	//		//String found, use existing offset
	//		kc.name_offset = offset;
	//	}

	//	//Search for the controller type string
	//	offset = (int)pal.find( controller_type );
	//	if ( offset == -1 ) {
	//		//String not found, append it
	//		kc.controller_offset = (uint)pal.size();
	//		pal.append( controller_type + '\0' );
	//	} else {
	//		//String found, use existing offset
	//		kc.controller_offset = offset;
	//	}

	//	//Store the palette back to the string pal block
	//	str_pal->GetAttr("Palette")->Set( pal );
	//}
	//
	//children.push_back( kc );

	////Add new child
	//AddChild( kc.block.get_block() );
	//
	////This should be impossible now, but don't want to forget it later
	//if ( kc.unk_link.is_null() != true ) {
	//	AddChild( kc.unk_link.get_block() );
	//}
}

void NiControllerSequence::AddInterpolator( const string target_name, const Ref<NiInterpolator> & obj, string controller_type ) {
	//Make sure the link isn't null
	if ( obj == NULL ) {
		throw runtime_error("Attempted to add a null interpolator to NiControllerSequence block.");
	}

	throw runtime_error("The AddInterpolator function cannot be implemented until prolems in the XML are solved.");

	//TODO: Hold off on this until the XML for this block is fixed up.
	//KfChild kc;

	//kc.block = new_link;

	////Check for a string palette
	//blk_ref str_pal = GetAttr("String Palette")->asLink();
	//if ( str_pal.is_null() == true ) {
	//	//No string palette, store name internally
	//	kc.name = new_name;
	//} else {
	//	//String palette exists - store name and controller type there

	//	//Make sure they didn't give us empty strings
	//	if ( new_name.size() == 0 || controller_type.size() == 0 ) {
	//		throw runtime_error( "You cannot use empty name or controller type strings when using a string palette.");
	//	}

	//	//Get palette
	//	string pal = str_pal->GetAttr("Palette")->asString();

	//	//--Search for copies of the text we want to add--//

	//	//Search for the name string
	//	int offset = (int)pal.find( new_name );
	//	if ( offset == -1 ) {
	//		//String not found, append it
	//		kc.name_offset = (uint)pal.size();
	//		pal.append( new_name + '\0' );
	//	} else {
	//		//String found, use existing offset
	//		kc.name_offset = offset;
	//	}

	//	//Search for the controller type string
	//	offset = (int)pal.find( controller_type );
	//	if ( offset == -1 ) {
	//		//String not found, append it
	//		kc.controller_offset = (uint)pal.size();
	//		pal.append( controller_type + '\0' );
	//	} else {
	//		//String found, use existing offset
	//		kc.controller_offset = offset;
	//	}

	//	//Store the palette back to the string pal block
	//	str_pal->GetAttr("Palette")->Set( pal );
	//}
	//
	//children.push_back( kc );

	////Add new child
	//AddChild( kc.block.get_block() );
	//
	////This should be impossible now, but don't want to forget it later
	//if ( kc.unk_link.is_null() != true ) {
	//	AddChild( kc.unk_link.get_block() );
	//}
}

void NiControllerSequence::ClearChildren() {
	
	throw runtime_error("The AddInterpolator function cannot be implemented until prolems in the XML are solved.");

	//TODO: Hold off on this until the XML is sorted out
	////Cycle through all Kf Children, removing them as parents from the blocks they refer to
	//for (uint i = 0; i < children.size(); ++i ) {
	//	if ( children[i].block.is_null() != true ) {
	//		RemoveChild( children[i].block.get_block() );
	//	}
	//	if ( children[i].unk_link.is_null() != true ) {
	//		RemoveChild( children[i].unk_link.get_block() );
	//	}
	//}

	////Clear list
	//children.clear();

	////Check for a string palette
	//blk_ref str_pal = GetAttr("String Palette")->asLink();
	//if ( str_pal.is_null() == false ) {
	//	//There's a string palette, so clear it out
	//	str_pal->GetAttr("Palette")->Set( "" );
	//}
}

string NiControllerSequence::GetSubStr( const string & pal, short offset ) const {
	string out;
	
	// -1 is a null offset
	if ( offset == -1 ) {
		return out;
	}

	for ( uint i = offset; i < pal.size(); ++i ) {
		if ( pal[i] == '\0' ) {
			break;
		}
		out.push_back( pal[i] );
	}

	return out;
}
