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
#include "../../include/obj/NiCollisionData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiCollisionData::TYPE("NiCollisionData", &NiCollisionObject::TYPE );

NiCollisionData::NiCollisionData() : unknownInt1((unsigned int)0), unknownInt2((unsigned int)0), unknownByte((byte)0), collisionType((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiCollisionData::~NiCollisionData() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiCollisionData::GetType() const {
	return TYPE;
}

NiObject * NiCollisionData::Create() {
	return new NiCollisionData;
}

void NiCollisionData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiCollisionObject::Read( in, link_stack, info );
	NifStream( unknownInt1, in, info );
	if ( ( info.version >= 0x0A010000 ) && ( info.version <= 0x0A010000 ) ) {
		NifStream( unknownInt2, in, info );
	};
	NifStream( unknownByte, in, info );
	NifStream( collisionType, in, info );
	if ( (collisionType == 0) ) {
		NifStream( unknownInt2, in, info );
		NifStream( unknownVector, in, info );
	};
	if ( (collisionType == 2) ) {
		for (unsigned int i2 = 0; i2 < 8; i2++) {
			NifStream( unknownFloat1[i2], in, info );
		};
	};
	if ( (collisionType == 1) ) {
		for (unsigned int i2 = 0; i2 < 15; i2++) {
			NifStream( unknownFloat2[i2], in, info );
		};
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiCollisionData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiCollisionObject::Write( out, link_map, info );
	NifStream( unknownInt1, out, info );
	if ( ( info.version >= 0x0A010000 ) && ( info.version <= 0x0A010000 ) ) {
		NifStream( unknownInt2, out, info );
	};
	NifStream( unknownByte, out, info );
	NifStream( collisionType, out, info );
	if ( (collisionType == 0) ) {
		NifStream( unknownInt2, out, info );
		NifStream( unknownVector, out, info );
	};
	if ( (collisionType == 2) ) {
		for (unsigned int i2 = 0; i2 < 8; i2++) {
			NifStream( unknownFloat1[i2], out, info );
		};
	};
	if ( (collisionType == 1) ) {
		for (unsigned int i2 = 0; i2 < 15; i2++) {
			NifStream( unknownFloat2[i2], out, info );
		};
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiCollisionData::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiCollisionObject::asString();
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	out << "  Unknown Byte:  " << unknownByte << endl;
	out << "  Collision Type:  " << collisionType << endl;
	if ( (collisionType == 0) ) {
		out << "    Unknown Vector:  " << unknownVector << endl;
	};
	if ( (collisionType == 2) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < 8; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Float 1[" << i2 << "]:  " << unknownFloat1[i2] << endl;
			array_output_count++;
		};
	};
	if ( (collisionType == 1) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < 15; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Float 2[" << i2 << "]:  " << unknownFloat2[i2] << endl;
			array_output_count++;
		};
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiCollisionData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiCollisionObject::FixLinks( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiCollisionData::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiCollisionObject::GetRefs();
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
