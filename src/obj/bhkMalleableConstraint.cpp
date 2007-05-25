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
#include "../../include/obj/bhkMalleableConstraint.h"
#include "../../include/gen/RagdollDescriptor.h"
#include "../../include/gen/LimitedHingeDescriptor.h"
#include "../../include/obj/NiObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkMalleableConstraint::TYPE("bhkMalleableConstraint", &bhkConstraint::TYPE );

bhkMalleableConstraint::bhkMalleableConstraint() : type((unsigned int)0), unknownInt2((unsigned int)0), unknownLink1(NULL), unknownLink2(NULL), unknownInt3((unsigned int)0), tau(0.0f), damping(0.0f) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

bhkMalleableConstraint::~bhkMalleableConstraint() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & bhkMalleableConstraint::GetType() const {
	return TYPE;
}

NiObject * bhkMalleableConstraint::Create() {
	return new bhkMalleableConstraint;
}

void bhkMalleableConstraint::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	bhkConstraint::Read( in, link_stack, info );
	NifStream( type, in, info );
	NifStream( unknownInt2, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( unknownInt3, in, info );
	if ( (type == 7) ) {
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
	};
	if ( (type == 2) ) {
		NifStream( limitedHinge.pivotA, in, info );
		NifStream( limitedHinge.axleA, in, info );
		NifStream( limitedHinge.perp2axleina1, in, info );
		NifStream( limitedHinge.perp2axleina2, in, info );
		NifStream( limitedHinge.pivotB, in, info );
		NifStream( limitedHinge.axleB, in, info );
		NifStream( limitedHinge.perp2axleinb2, in, info );
		NifStream( limitedHinge.minAngle, in, info );
		NifStream( limitedHinge.maxAngle, in, info );
		NifStream( limitedHinge.maxFriction, in, info );
	};
	NifStream( tau, in, info );
	NifStream( damping, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkMalleableConstraint::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConstraint::Write( out, link_map, info );
	NifStream( type, out, info );
	NifStream( unknownInt2, out, info );
	if ( unknownLink1 != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(unknownLink1) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	if ( unknownLink2 != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(unknownLink2) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	NifStream( unknownInt3, out, info );
	if ( (type == 7) ) {
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
	};
	if ( (type == 2) ) {
		NifStream( limitedHinge.pivotA, out, info );
		NifStream( limitedHinge.axleA, out, info );
		NifStream( limitedHinge.perp2axleina1, out, info );
		NifStream( limitedHinge.perp2axleina2, out, info );
		NifStream( limitedHinge.pivotB, out, info );
		NifStream( limitedHinge.axleB, out, info );
		NifStream( limitedHinge.perp2axleinb2, out, info );
		NifStream( limitedHinge.minAngle, out, info );
		NifStream( limitedHinge.maxAngle, out, info );
		NifStream( limitedHinge.maxFriction, out, info );
	};
	NifStream( tau, out, info );
	NifStream( damping, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string bhkMalleableConstraint::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkConstraint::asString();
	out << "  Type:  " << type << endl;
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	out << "  Unknown Link 1:  " << unknownLink1 << endl;
	out << "  Unknown Link 2:  " << unknownLink2 << endl;
	out << "  Unknown Int 3:  " << unknownInt3 << endl;
	if ( (type == 7) ) {
		out << "    Pivot A:  " << ragdoll.pivotA << endl;
		out << "    Plane A:  " << ragdoll.planeA << endl;
		out << "    Twist A:  " << ragdoll.twistA << endl;
		out << "    Pivot B:  " << ragdoll.pivotB << endl;
		out << "    Plane B:  " << ragdoll.planeB << endl;
		out << "    Twist B:  " << ragdoll.twistB << endl;
		out << "    Cone Min Angle:  " << ragdoll.coneMinAngle << endl;
		out << "    Plane Min Angle:  " << ragdoll.planeMinAngle << endl;
		out << "    Plane Max Angle:  " << ragdoll.planeMaxAngle << endl;
		out << "    Twist Min Angle:  " << ragdoll.twistMinAngle << endl;
		out << "    Twist Max Angle:  " << ragdoll.twistMaxAngle << endl;
		out << "    Max Friction:  " << ragdoll.maxFriction << endl;
	};
	if ( (type == 2) ) {
		out << "    Pivot A:  " << limitedHinge.pivotA << endl;
		out << "    Axle A:  " << limitedHinge.axleA << endl;
		out << "    Perp2AxleInA1:  " << limitedHinge.perp2axleina1 << endl;
		out << "    Perp2AxleInA2:  " << limitedHinge.perp2axleina2 << endl;
		out << "    Pivot B:  " << limitedHinge.pivotB << endl;
		out << "    Axle B:  " << limitedHinge.axleB << endl;
		out << "    Perp2AxleInB2:  " << limitedHinge.perp2axleinb2 << endl;
		out << "    Min Angle:  " << limitedHinge.minAngle << endl;
		out << "    Max Angle:  " << limitedHinge.maxAngle << endl;
		out << "    Max Friction:  " << limitedHinge.maxFriction << endl;
	};
	out << "  Tau:  " << tau << endl;
	out << "  Damping:  " << damping << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkMalleableConstraint::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConstraint::FixLinks( objects, link_stack, info );
	unknownLink1 = FixLink<NiObject>( objects, link_stack, info );
	unknownLink2 = FixLink<NiObject>( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> bhkMalleableConstraint::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkConstraint::GetRefs();
	if ( unknownLink1 != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink1));
	if ( unknownLink2 != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink2));
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
