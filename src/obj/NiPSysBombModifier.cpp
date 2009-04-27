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
#include "../../include/obj/NiPSysBombModifier.h"
#include "../../include/obj/NiNode.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysBombModifier::TYPE("NiPSysBombModifier", &NiPSysModifier::TYPE );

NiPSysBombModifier::NiPSysBombModifier() : bombObject(NULL), decay(0.0f), deltaV(0.0f), decayType((DecayType)0), symmetryType((SymmetryType)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiPSysBombModifier::~NiPSysBombModifier() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiPSysBombModifier::GetType() const {
	return TYPE;
}

NiObject * NiPSysBombModifier::Create() {
	return new NiPSysBombModifier;
}

void NiPSysBombModifier::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiPSysModifier::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( bombAxis, in, info );
	NifStream( decay, in, info );
	NifStream( deltaV, in, info );
	NifStream( decayType, in, info );
	NifStream( symmetryType, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiPSysBombModifier::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiPSysModifier::Write( out, link_map, info );
	if ( info.version < VER_3_3_0_13 ) {
		NifStream( (unsigned int)&(*bombObject), out, info );
	} else {
		if ( bombObject != NULL ) {
			NifStream( link_map.find( StaticCast<NiObject>(bombObject) )->second, out, info );
		} else {
			NifStream( 0xFFFFFFFF, out, info );
		}
	}
	NifStream( bombAxis, out, info );
	NifStream( decay, out, info );
	NifStream( deltaV, out, info );
	NifStream( decayType, out, info );
	NifStream( symmetryType, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiPSysBombModifier::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiPSysModifier::asString();
	out << "  Bomb Object:  " << bombObject << endl;
	out << "  Bomb Axis:  " << bombAxis << endl;
	out << "  Decay:  " << decay << endl;
	out << "  Delta V:  " << deltaV << endl;
	out << "  Decay Type:  " << decayType << endl;
	out << "  Symmetry Type:  " << symmetryType << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiPSysBombModifier::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiPSysModifier::FixLinks( objects, link_stack, info );
	bombObject = FixLink<NiNode>( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPSysBombModifier::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
