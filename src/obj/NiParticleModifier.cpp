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
#include "../../include/obj/NiParticleModifier.h"
#include "../../include/obj/NiParticleSystemController.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiParticleModifier::TYPE("NiParticleModifier", &NiObject::TYPE );

NiParticleModifier::NiParticleModifier() : nextModifier(NULL), controller(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiParticleModifier::~NiParticleModifier() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiParticleModifier::GetType() const {
	return TYPE;
}

NiObject * NiParticleModifier::Create() {
	return new NiParticleModifier;
}

void NiParticleModifier::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	if ( info.version >= 0x04000002 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiParticleModifier::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, info );
	if ( info.version < VER_3_3_0_13 ) {
		WritePtr32( &(*nextModifier), out );
	} else {
		if ( nextModifier != NULL ) {
			NifStream( link_map.find( StaticCast<NiObject>(nextModifier) )->second, out, info );
		} else {
			NifStream( 0xFFFFFFFF, out, info );
		}
	}
	if ( info.version >= 0x04000002 ) {
		if ( info.version < VER_3_3_0_13 ) {
			WritePtr32( &(*controller), out );
		} else {
			if ( controller != NULL ) {
				NifStream( link_map.find( StaticCast<NiObject>(controller) )->second, out, info );
			} else {
				NifStream( 0xFFFFFFFF, out, info );
			}
		}
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiParticleModifier::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	out << "  Next Modifier:  " << nextModifier << endl;
	out << "  Controller:  " << controller << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiParticleModifier::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, info );
	nextModifier = FixLink<NiParticleModifier>( objects, link_stack, info );
	if ( info.version >= 0x04000002 ) {
		controller = FixLink<NiParticleSystemController>( objects, link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiParticleModifier::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( nextModifier != NULL )
		refs.push_back(StaticCast<NiObject>(nextModifier));
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
