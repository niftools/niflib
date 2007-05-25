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

bhkRagdollConstraint::bhkRagdollConstraint() {
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
	NifStream( ragdoll.coneMinAngle, in, info );
	NifStream( ragdoll.planeMinAngle, in, info );
	NifStream( ragdoll.planeMaxAngle, in, info );
	NifStream( ragdoll.twistMinAngle, in, info );
	NifStream( ragdoll.twistMaxAngle, in, info );
	NifStream( ragdoll.maxFriction, in, info );

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
	NifStream( ragdoll.coneMinAngle, out, info );
	NifStream( ragdoll.planeMinAngle, out, info );
	NifStream( ragdoll.planeMaxAngle, out, info );
	NifStream( ragdoll.twistMinAngle, out, info );
	NifStream( ragdoll.twistMaxAngle, out, info );
	NifStream( ragdoll.maxFriction, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string bhkRagdollConstraint::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkConstraint::asString();
	out << "  Pivot A:  " << ragdoll.pivotA << endl;
	out << "  Plane A:  " << ragdoll.planeA << endl;
	out << "  Twist A:  " << ragdoll.twistA << endl;
	out << "  Pivot B:  " << ragdoll.pivotB << endl;
	out << "  Plane B:  " << ragdoll.planeB << endl;
	out << "  Twist B:  " << ragdoll.twistB << endl;
	out << "  Cone Min Angle:  " << ragdoll.coneMinAngle << endl;
	out << "  Plane Min Angle:  " << ragdoll.planeMinAngle << endl;
	out << "  Plane Max Angle:  " << ragdoll.planeMaxAngle << endl;
	out << "  Twist Min Angle:  " << ragdoll.twistMinAngle << endl;
	out << "  Twist Max Angle:  " << ragdoll.twistMaxAngle << endl;
	out << "  Max Friction:  " << ragdoll.maxFriction << endl;
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

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
