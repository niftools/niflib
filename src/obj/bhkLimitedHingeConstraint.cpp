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
#include "../../include/obj/bhkLimitedHingeConstraint.h"
#include "../../include/gen/LimitedHingeDescriptor.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkLimitedHingeConstraint::TYPE("bhkLimitedHingeConstraint", &bhkConstraint::TYPE );

bhkLimitedHingeConstraint::bhkLimitedHingeConstraint() : unknownFloat1(0.0f), isDeathPose((byte)0), unknownInt1((int)0), unknownInt2((int)0), unknownInt3((int)0), unknownInt4((int)0), unknownInt5((int)0), unknownInt6((int)0), unknownByte1((byte)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

bhkLimitedHingeConstraint::~bhkLimitedHingeConstraint() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & bhkLimitedHingeConstraint::GetType() const {
	return TYPE;
}

NiObject * bhkLimitedHingeConstraint::Create() {
	return new bhkLimitedHingeConstraint;
}

void bhkLimitedHingeConstraint::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConstraint::Read( in, link_stack, info );
	NifStream( limitedHinge.pivotA, in, info );
	NifStream( limitedHinge.axleA, in, info );
	NifStream( limitedHinge.perp2AxleInA1, in, info );
	NifStream( limitedHinge.perp2AxleInA2, in, info );
	NifStream( limitedHinge.pivotB, in, info );
	NifStream( limitedHinge.axleB, in, info );
	NifStream( limitedHinge.perp2AxleInB2, in, info );
	NifStream( limitedHinge.minAngle, in, info );
	NifStream( limitedHinge.maxAngle, in, info );
	NifStream( limitedHinge.maxFriction, in, info );
	if ( info.version >= 0x14020007 ) {
		NifStream( limitedHinge.unknownFloat1, in, info );
		NifStream( limitedHinge.unknownFloat2, in, info );
		NifStream( limitedHinge.unknownFloat3, in, info );
	};
	if ( info.version >= 0x14020007 ) {
		NifStream( unknownFloat1, in, info );
		NifStream( isDeathPose, in, info );
		if ( isDeathPose ) {
			NifStream( unknownInt1, in, info );
			NifStream( unknownInt2, in, info );
			NifStream( unknownInt3, in, info );
			NifStream( unknownInt4, in, info );
			NifStream( unknownInt5, in, info );
			NifStream( unknownInt6, in, info );
			NifStream( unknownByte1, in, info );
		};
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkLimitedHingeConstraint::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConstraint::Write( out, link_map, info );
	NifStream( limitedHinge.pivotA, out, info );
	NifStream( limitedHinge.axleA, out, info );
	NifStream( limitedHinge.perp2AxleInA1, out, info );
	NifStream( limitedHinge.perp2AxleInA2, out, info );
	NifStream( limitedHinge.pivotB, out, info );
	NifStream( limitedHinge.axleB, out, info );
	NifStream( limitedHinge.perp2AxleInB2, out, info );
	NifStream( limitedHinge.minAngle, out, info );
	NifStream( limitedHinge.maxAngle, out, info );
	NifStream( limitedHinge.maxFriction, out, info );
	if ( info.version >= 0x14020007 ) {
		NifStream( limitedHinge.unknownFloat1, out, info );
		NifStream( limitedHinge.unknownFloat2, out, info );
		NifStream( limitedHinge.unknownFloat3, out, info );
	};
	if ( info.version >= 0x14020007 ) {
		NifStream( unknownFloat1, out, info );
		NifStream( isDeathPose, out, info );
		if ( isDeathPose ) {
			NifStream( unknownInt1, out, info );
			NifStream( unknownInt2, out, info );
			NifStream( unknownInt3, out, info );
			NifStream( unknownInt4, out, info );
			NifStream( unknownInt5, out, info );
			NifStream( unknownInt6, out, info );
			NifStream( unknownByte1, out, info );
		};
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string bhkLimitedHingeConstraint::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	out << bhkConstraint::asString();
	out << "  Pivot A:  " << limitedHinge.pivotA << endl;
	out << "  Axle A:  " << limitedHinge.axleA << endl;
	out << "  Perp2 Axle In A1:  " << limitedHinge.perp2AxleInA1 << endl;
	out << "  Perp2 Axle In A2:  " << limitedHinge.perp2AxleInA2 << endl;
	out << "  Pivot B:  " << limitedHinge.pivotB << endl;
	out << "  Axle B:  " << limitedHinge.axleB << endl;
	out << "  Perp2 Axle In B2:  " << limitedHinge.perp2AxleInB2 << endl;
	out << "  Min Angle:  " << limitedHinge.minAngle << endl;
	out << "  Max Angle:  " << limitedHinge.maxAngle << endl;
	out << "  Max Friction:  " << limitedHinge.maxFriction << endl;
	out << "  Unknown Float 1:  " << limitedHinge.unknownFloat1 << endl;
	out << "  Unknown Float 2:  " << limitedHinge.unknownFloat2 << endl;
	out << "  Unknown Float 3:  " << limitedHinge.unknownFloat3 << endl;
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Is Death Pose:  " << isDeathPose << endl;
	if ( isDeathPose ) {
		out << "    Unknown Int 1:  " << unknownInt1 << endl;
		out << "    Unknown Int 2:  " << unknownInt2 << endl;
		out << "    Unknown Int 3:  " << unknownInt3 << endl;
		out << "    Unknown Int 4:  " << unknownInt4 << endl;
		out << "    Unknown Int 5:  " << unknownInt5 << endl;
		out << "    Unknown Int 6:  " << unknownInt6 << endl;
		out << "    Unknown Byte 1:  " << unknownByte1 << endl;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkLimitedHingeConstraint::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConstraint::FixLinks( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> bhkLimitedHingeConstraint::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkConstraint::GetRefs();
	return refs;
}

std::list<NiObject *> bhkLimitedHingeConstraint::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = bhkConstraint::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
