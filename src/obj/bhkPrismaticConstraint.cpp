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
#include "../../include/obj/bhkPrismaticConstraint.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkPrismaticConstraint::TYPE("bhkPrismaticConstraint", &bhkConstraint::TYPE );

bhkPrismaticConstraint::bhkPrismaticConstraint() : minDistance(0.0f), maxDistance(0.0f), friction(0.0f), unknownByte1((byte)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

bhkPrismaticConstraint::~bhkPrismaticConstraint() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & bhkPrismaticConstraint::GetType() const {
	return TYPE;
}

NiObject * bhkPrismaticConstraint::Create() {
	return new bhkPrismaticConstraint;
}

void bhkPrismaticConstraint::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConstraint::Read( in, link_stack, info );
	NifStream( pivotA, in, info );
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		NifStream( rotation[i1], in, info );
	};
	NifStream( pivotB, in, info );
	NifStream( slidingAxis, in, info );
	NifStream( plane, in, info );
	NifStream( minDistance, in, info );
	NifStream( maxDistance, in, info );
	NifStream( friction, in, info );
	if ( info.version >= 0x14020007 ) {
		NifStream( unknownByte1, in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkPrismaticConstraint::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConstraint::Write( out, link_map, missing_link_stack, info );
	NifStream( pivotA, out, info );
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		NifStream( rotation[i1], out, info );
	};
	NifStream( pivotB, out, info );
	NifStream( slidingAxis, out, info );
	NifStream( plane, out, info );
	NifStream( minDistance, out, info );
	NifStream( maxDistance, out, info );
	NifStream( friction, out, info );
	if ( info.version >= 0x14020007 ) {
		NifStream( unknownByte1, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string bhkPrismaticConstraint::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkConstraint::asString();
	out << "  Pivot A:  " << pivotA << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Rotation[" << i1 << "]:  " << rotation[i1] << endl;
		array_output_count++;
	};
	out << "  Pivot B:  " << pivotB << endl;
	out << "  Sliding Axis:  " << slidingAxis << endl;
	out << "  Plane:  " << plane << endl;
	out << "  Min Distance:  " << minDistance << endl;
	out << "  Max Distance:  " << maxDistance << endl;
	out << "  Friction:  " << friction << endl;
	out << "  Unknown Byte 1:  " << unknownByte1 << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkPrismaticConstraint::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConstraint::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> bhkPrismaticConstraint::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkConstraint::GetRefs();
	return refs;
}

std::list<NiObject *> bhkPrismaticConstraint::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = bhkConstraint::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
