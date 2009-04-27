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
#include "../../include/obj/NiPSysMeshEmitter.h"
#include "../../include/obj/NiTriBasedGeom.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysMeshEmitter::TYPE("NiPSysMeshEmitter", &NiPSysEmitter::TYPE );

NiPSysMeshEmitter::NiPSysMeshEmitter() : numEmitterMeshes((unsigned int)0), initialVelocityType((VelocityType)0), emissionType((EmitFrom)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiPSysMeshEmitter::~NiPSysMeshEmitter() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiPSysMeshEmitter::GetType() const {
	return TYPE;
}

NiObject * NiPSysMeshEmitter::Create() {
	return new NiPSysMeshEmitter;
}

void NiPSysMeshEmitter::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiPSysEmitter::Read( in, link_stack, info );
	NifStream( numEmitterMeshes, in, info );
	emitterMeshes.resize(numEmitterMeshes);
	for (unsigned int i1 = 0; i1 < emitterMeshes.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( initialVelocityType, in, info );
	NifStream( emissionType, in, info );
	NifStream( emissionAxis, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiPSysMeshEmitter::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiPSysEmitter::Write( out, link_map, info );
	numEmitterMeshes = (unsigned int)(emitterMeshes.size());
	NifStream( numEmitterMeshes, out, info );
	for (unsigned int i1 = 0; i1 < emitterMeshes.size(); i1++) {
		if ( info.version < VER_3_3_0_13 ) {
			NifStream( (unsigned int)&(*emitterMeshes[i1]), out, info );
		} else {
			if ( emitterMeshes[i1] != NULL ) {
				NifStream( link_map.find( StaticCast<NiObject>(emitterMeshes[i1]) )->second, out, info );
			} else {
				NifStream( 0xFFFFFFFF, out, info );
			}
		}
	};
	NifStream( initialVelocityType, out, info );
	NifStream( emissionType, out, info );
	NifStream( emissionAxis, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiPSysMeshEmitter::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiPSysEmitter::asString();
	numEmitterMeshes = (unsigned int)(emitterMeshes.size());
	out << "  Num Emitter Meshes:  " << numEmitterMeshes << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < emitterMeshes.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Emitter Meshes[" << i1 << "]:  " << emitterMeshes[i1] << endl;
		array_output_count++;
	};
	out << "  Initial Velocity Type:  " << initialVelocityType << endl;
	out << "  Emission Type:  " << emissionType << endl;
	out << "  Emission Axis:  " << emissionAxis << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiPSysMeshEmitter::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiPSysEmitter::FixLinks( objects, link_stack, info );
	for (unsigned int i1 = 0; i1 < emitterMeshes.size(); i1++) {
		emitterMeshes[i1] = FixLink<NiTriBasedGeom>( objects, link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPSysMeshEmitter::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysEmitter::GetRefs();
	for (unsigned int i1 = 0; i1 < emitterMeshes.size(); i1++) {
		if ( emitterMeshes[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(emitterMeshes[i1]));
	};
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
