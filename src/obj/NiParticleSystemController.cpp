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
#include "../../include/obj/NiParticleSystemController.h"
#include "../../include/gen/Particle.h"
#include "../../include/gen/Particle.h"
#include "../../include/obj/NiObject.h"
#include "../../include/obj/AParticleModifier.h"
#include "../../include/obj/NiColorData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiParticleSystemController::TYPE("NiParticleSystemController", &NiTimeController::TYPE );

NiParticleSystemController::NiParticleSystemController() : speed(0.0f), speedRandom(0.0f), verticalDirection(0.0f), verticalAngle(0.0f), horizontalDirection(0.0f), horizontalAngle(0.0f), unknownFloat5(0.0f), unknownFloat6(0.0f), unknownFloat7(0.0f), unknownFloat8(0.0f), unknownFloat9(0.0f), unknownFloat10(0.0f), unknownFloat11(0.0f), size(0.0f), emitStartTime(0.0f), emitStopTime(0.0f), unknownByte((byte)0), emitRate(0.0f), lifetime(0.0f), lifetimeRandom(0.0f), emitFlags((unsigned short)0), emitter(NULL), unknownShort2_((unsigned short)0), unknownFloat13_(0.0f), unknownInt1_((unsigned int)0), unknownInt2_((unsigned int)0), unknownShort3_((unsigned short)0), numParticles((unsigned short)0), numValid((unsigned short)0), unknownLink(NULL), particleExtra(NULL), unknownLink2(NULL), trailer((byte)0), colorData(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiParticleSystemController::~NiParticleSystemController() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiParticleSystemController::GetType() const {
	return TYPE;
}

//A static bool to force the initialization to happen pre-main
bool NiParticleSystemController::obj_initialized = NiParticleSystemController::Register();

bool NiParticleSystemController::Register() {
	//Register this object type with Niflib
	ObjectRegistry::RegisterObject( "NiParticleSystemController", NiParticleSystemController::Create );

	//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
	obj_initialized = true;
	return obj_initialized;
}

NiObject * NiParticleSystemController::Create() {
	return new NiParticleSystemController;
}

void NiParticleSystemController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiTimeController::Read( in, link_stack, info );
	NifStream( speed, in, info );
	NifStream( speedRandom, in, info );
	NifStream( verticalDirection, in, info );
	NifStream( verticalAngle, in, info );
	NifStream( horizontalDirection, in, info );
	NifStream( horizontalAngle, in, info );
	NifStream( unknownFloat5, in, info );
	NifStream( unknownFloat6, in, info );
	NifStream( unknownFloat7, in, info );
	NifStream( unknownFloat8, in, info );
	NifStream( unknownFloat9, in, info );
	NifStream( unknownFloat10, in, info );
	NifStream( unknownFloat11, in, info );
	NifStream( size, in, info );
	NifStream( emitStartTime, in, info );
	NifStream( emitStopTime, in, info );
	if ( info.version >= 0x04000002 ) {
		NifStream( unknownByte, in, info );
	};
	NifStream( emitRate, in, info );
	NifStream( lifetime, in, info );
	NifStream( lifetimeRandom, in, info );
	if ( info.version >= 0x04000002 ) {
		NifStream( emitFlags, in, info );
	};
	NifStream( startRandom, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	if ( info.version >= 0x04000002 ) {
		NifStream( unknownShort2_, in, info );
		NifStream( unknownFloat13_, in, info );
		NifStream( unknownInt1_, in, info );
		NifStream( unknownInt2_, in, info );
		NifStream( unknownShort3_, in, info );
	};
	if ( info.version <= 0x03010000 ) {
		NifStream( particle.velocity, in, info );
		NifStream( particle.unknownVector, in, info );
		NifStream( particle.lifetime, in, info );
		NifStream( particle.lifespan, in, info );
		NifStream( particle.timestamp, in, info );
		NifStream( particle.unknownShort, in, info );
		NifStream( particle.vertexId, in, info );
	};
	if ( info.version >= 0x04000002 ) {
		NifStream( numParticles, in, info );
		NifStream( numValid, in, info );
		particles.resize(numParticles);
		for (unsigned int i2 = 0; i2 < particles.size(); i2++) {
			NifStream( particles[i2].velocity, in, info );
			NifStream( particles[i2].unknownVector, in, info );
			NifStream( particles[i2].lifetime, in, info );
			NifStream( particles[i2].lifespan, in, info );
			NifStream( particles[i2].timestamp, in, info );
			NifStream( particles[i2].unknownShort, in, info );
			NifStream( particles[i2].vertexId, in, info );
		};
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	if ( info.version >= 0x04000002 ) {
		NifStream( trailer, in, info );
	};
	if ( info.version <= 0x03010000 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
		for (unsigned int i2 = 0; i2 < 2; i2++) {
			NifStream( unkownFloats[i2], in, info );
		};
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiParticleSystemController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiTimeController::Write( out, link_map, info );
	numParticles = (unsigned short)(particles.size());
	NifStream( speed, out, info );
	NifStream( speedRandom, out, info );
	NifStream( verticalDirection, out, info );
	NifStream( verticalAngle, out, info );
	NifStream( horizontalDirection, out, info );
	NifStream( horizontalAngle, out, info );
	NifStream( unknownFloat5, out, info );
	NifStream( unknownFloat6, out, info );
	NifStream( unknownFloat7, out, info );
	NifStream( unknownFloat8, out, info );
	NifStream( unknownFloat9, out, info );
	NifStream( unknownFloat10, out, info );
	NifStream( unknownFloat11, out, info );
	NifStream( size, out, info );
	NifStream( emitStartTime, out, info );
	NifStream( emitStopTime, out, info );
	if ( info.version >= 0x04000002 ) {
		NifStream( unknownByte, out, info );
	};
	NifStream( emitRate, out, info );
	NifStream( lifetime, out, info );
	NifStream( lifetimeRandom, out, info );
	if ( info.version >= 0x04000002 ) {
		NifStream( emitFlags, out, info );
	};
	NifStream( startRandom, out, info );
	if ( emitter != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(emitter) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	if ( info.version >= 0x04000002 ) {
		NifStream( unknownShort2_, out, info );
		NifStream( unknownFloat13_, out, info );
		NifStream( unknownInt1_, out, info );
		NifStream( unknownInt2_, out, info );
		NifStream( unknownShort3_, out, info );
	};
	if ( info.version <= 0x03010000 ) {
		NifStream( particle.velocity, out, info );
		NifStream( particle.unknownVector, out, info );
		NifStream( particle.lifetime, out, info );
		NifStream( particle.lifespan, out, info );
		NifStream( particle.timestamp, out, info );
		NifStream( particle.unknownShort, out, info );
		NifStream( particle.vertexId, out, info );
	};
	if ( info.version >= 0x04000002 ) {
		NifStream( numParticles, out, info );
		NifStream( numValid, out, info );
		for (unsigned int i2 = 0; i2 < particles.size(); i2++) {
			NifStream( particles[i2].velocity, out, info );
			NifStream( particles[i2].unknownVector, out, info );
			NifStream( particles[i2].lifetime, out, info );
			NifStream( particles[i2].lifespan, out, info );
			NifStream( particles[i2].timestamp, out, info );
			NifStream( particles[i2].unknownShort, out, info );
			NifStream( particles[i2].vertexId, out, info );
		};
		if ( unknownLink != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(unknownLink) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
	if ( particleExtra != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(particleExtra) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	if ( unknownLink2 != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(unknownLink2) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	if ( info.version >= 0x04000002 ) {
		NifStream( trailer, out, info );
	};
	if ( info.version <= 0x03010000 ) {
		if ( colorData != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(colorData) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
		for (unsigned int i2 = 0; i2 < 2; i2++) {
			NifStream( unkownFloats[i2], out, info );
		};
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiParticleSystemController::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiTimeController::asString();
	numParticles = (unsigned short)(particles.size());
	out << "  Speed:  " << speed << endl;
	out << "  Speed Random:  " << speedRandom << endl;
	out << "  Vertical Direction:  " << verticalDirection << endl;
	out << "  Vertical Angle:  " << verticalAngle << endl;
	out << "  Horizontal Direction:  " << horizontalDirection << endl;
	out << "  Horizontal Angle:  " << horizontalAngle << endl;
	out << "  Unknown Float 5:  " << unknownFloat5 << endl;
	out << "  Unknown Float 6:  " << unknownFloat6 << endl;
	out << "  Unknown Float 7:  " << unknownFloat7 << endl;
	out << "  Unknown Float 8:  " << unknownFloat8 << endl;
	out << "  Unknown Float 9:  " << unknownFloat9 << endl;
	out << "  Unknown Float 10:  " << unknownFloat10 << endl;
	out << "  Unknown Float 11:  " << unknownFloat11 << endl;
	out << "  Size:  " << size << endl;
	out << "  Emit Start Time:  " << emitStartTime << endl;
	out << "  Emit Stop Time:  " << emitStopTime << endl;
	out << "  Unknown Byte:  " << unknownByte << endl;
	out << "  Emit Rate:  " << emitRate << endl;
	out << "  Lifetime:  " << lifetime << endl;
	out << "  Lifetime Random:  " << lifetimeRandom << endl;
	out << "  Emit Flags:  " << emitFlags << endl;
	out << "  Start Random:  " << startRandom << endl;
	out << "  Emitter:  " << emitter << endl;
	out << "  Unknown Short 2?:  " << unknownShort2_ << endl;
	out << "  Unknown Float 13?:  " << unknownFloat13_ << endl;
	out << "  Unknown Int 1?:  " << unknownInt1_ << endl;
	out << "  Unknown Int 2?:  " << unknownInt2_ << endl;
	out << "  Unknown Short 3?:  " << unknownShort3_ << endl;
	out << "  Velocity:  " << particle.velocity << endl;
	out << "  Unknown Vector:  " << particle.unknownVector << endl;
	out << "  Lifetime:  " << particle.lifetime << endl;
	out << "  Lifespan:  " << particle.lifespan << endl;
	out << "  Timestamp:  " << particle.timestamp << endl;
	out << "  Unknown Short:  " << particle.unknownShort << endl;
	out << "  Vertex ID:  " << particle.vertexId << endl;
	out << "  Num Particles:  " << numParticles << endl;
	out << "  Num Valid:  " << numValid << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < particles.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Velocity:  " << particles[i1].velocity << endl;
		out << "    Unknown Vector:  " << particles[i1].unknownVector << endl;
		out << "    Lifetime:  " << particles[i1].lifetime << endl;
		out << "    Lifespan:  " << particles[i1].lifespan << endl;
		out << "    Timestamp:  " << particles[i1].timestamp << endl;
		out << "    Unknown Short:  " << particles[i1].unknownShort << endl;
		out << "    Vertex ID:  " << particles[i1].vertexId << endl;
	};
	out << "  Unknown Link:  " << unknownLink << endl;
	out << "  Particle Extra:  " << particleExtra << endl;
	out << "  Unknown Link 2:  " << unknownLink2 << endl;
	out << "  Trailer:  " << trailer << endl;
	out << "  Color Data:  " << colorData << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 2; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unkown Floats[" << i1 << "]:  " << unkownFloats[i1] << endl;
		array_output_count++;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiParticleSystemController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiTimeController::FixLinks( objects, link_stack, info );
	emitter = FixLink<NiObject>( objects, link_stack, info );
	if ( info.version >= 0x04000002 ) {
		unknownLink = FixLink<NiObject>( objects, link_stack, info );
	};
	particleExtra = FixLink<AParticleModifier>( objects, link_stack, info );
	unknownLink2 = FixLink<NiObject>( objects, link_stack, info );
	if ( info.version <= 0x03010000 ) {
		colorData = FixLink<NiColorData>( objects, link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiParticleSystemController::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	if ( unknownLink != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink));
	if ( particleExtra != NULL )
		refs.push_back(StaticCast<NiObject>(particleExtra));
	if ( unknownLink2 != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink2));
	if ( colorData != NULL )
		refs.push_back(StaticCast<NiObject>(colorData));
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
