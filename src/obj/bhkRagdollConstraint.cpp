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
#include "../../include/obj/bhkRagdollConstraint.h"
#include "../../include/gen/RagdollDescriptor.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkRagdollConstraint::TYPE("bhkRagdollConstraint", &bhkConstraint::TYPE );

bhkRagdollConstraint::bhkRagdollConstraint() : unknownFloat1(0.0f), isDeathPose((byte)0), unknownInt1((int)0), unknownInt2((int)0), unknownInt3((int)0), unknownInt4((int)0), unknownInt5((int)0), unknownInt6((int)0), unknownByte1((byte)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

bhkRagdollConstraint::~bhkRagdollConstraint() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & bhkRagdollConstraint::GetType() const {
	return TYPE;
}

NiObject * bhkRagdollConstraint::Create() {
	return new bhkRagdollConstraint;
}

void bhkRagdollConstraint::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConstraint::Read( in, link_stack, info );
	NifStream( ragdoll.pivotA, in, info );
	NifStream( ragdoll.planeA, in, info );
	NifStream( ragdoll.twistA, in, info );
	NifStream( ragdoll.pivotB, in, info );
	NifStream( ragdoll.planeB, in, info );
	NifStream( ragdoll.twistB, in, info );
	NifStream( ragdoll.coneMaxAngle, in, info );
	NifStream( ragdoll.planeMinAngle, in, info );
	NifStream( ragdoll.planeMaxAngle, in, info );
	NifStream( ragdoll.twistMinAngle, in, info );
	NifStream( ragdoll.twistMaxAngle, in, info );
	NifStream( ragdoll.maxFriction, in, info );
	if ( info.version >= 0x14020007 ) {
		NifStream( ragdoll.unknownFloat1, in, info );
		NifStream( ragdoll.unknownFloat2, in, info );
		NifStream( ragdoll.unknownFloat3, in, info );
		NifStream( ragdoll.unknownFloat4, in, info );
		NifStream( ragdoll.unknownFloat5, in, info );
		NifStream( ragdoll.unknownFloat6, in, info );
		NifStream( ragdoll.unknownFloat7, in, info );
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

void bhkRagdollConstraint::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConstraint::Write( out, link_map, info );
	NifStream( ragdoll.pivotA, out, info );
	NifStream( ragdoll.planeA, out, info );
	NifStream( ragdoll.twistA, out, info );
	NifStream( ragdoll.pivotB, out, info );
	NifStream( ragdoll.planeB, out, info );
	NifStream( ragdoll.twistB, out, info );
	NifStream( ragdoll.coneMaxAngle, out, info );
	NifStream( ragdoll.planeMinAngle, out, info );
	NifStream( ragdoll.planeMaxAngle, out, info );
	NifStream( ragdoll.twistMinAngle, out, info );
	NifStream( ragdoll.twistMaxAngle, out, info );
	NifStream( ragdoll.maxFriction, out, info );
	if ( info.version >= 0x14020007 ) {
		NifStream( ragdoll.unknownFloat1, out, info );
		NifStream( ragdoll.unknownFloat2, out, info );
		NifStream( ragdoll.unknownFloat3, out, info );
		NifStream( ragdoll.unknownFloat4, out, info );
		NifStream( ragdoll.unknownFloat5, out, info );
		NifStream( ragdoll.unknownFloat6, out, info );
		NifStream( ragdoll.unknownFloat7, out, info );
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

std::string bhkRagdollConstraint::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	out << bhkConstraint::asString();
	out << "  Pivot A:  " << ragdoll.pivotA << endl;
	out << "  Plane A:  " << ragdoll.planeA << endl;
	out << "  Twist A:  " << ragdoll.twistA << endl;
	out << "  Pivot B:  " << ragdoll.pivotB << endl;
	out << "  Plane B:  " << ragdoll.planeB << endl;
	out << "  Twist B:  " << ragdoll.twistB << endl;
	out << "  Cone Max Angle:  " << ragdoll.coneMaxAngle << endl;
	out << "  Plane Min Angle:  " << ragdoll.planeMinAngle << endl;
	out << "  Plane Max Angle:  " << ragdoll.planeMaxAngle << endl;
	out << "  Twist Min Angle:  " << ragdoll.twistMinAngle << endl;
	out << "  Twist Max Angle:  " << ragdoll.twistMaxAngle << endl;
	out << "  Max Friction:  " << ragdoll.maxFriction << endl;
	out << "  Unknown Float 1:  " << ragdoll.unknownFloat1 << endl;
	out << "  Unknown Float 2:  " << ragdoll.unknownFloat2 << endl;
	out << "  Unknown Float 3:  " << ragdoll.unknownFloat3 << endl;
	out << "  Unknown Float 4:  " << ragdoll.unknownFloat4 << endl;
	out << "  Unknown Float 5:  " << ragdoll.unknownFloat5 << endl;
	out << "  Unknown Float 6:  " << ragdoll.unknownFloat6 << endl;
	out << "  Unknown Float 7:  " << ragdoll.unknownFloat7 << endl;
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

void bhkRagdollConstraint::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConstraint::FixLinks( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> bhkRagdollConstraint::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkConstraint::GetRefs();
	return refs;
}

std::list<NiObject *> bhkRagdollConstraint::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = bhkConstraint::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
