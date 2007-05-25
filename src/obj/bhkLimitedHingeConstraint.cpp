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

bhkLimitedHingeConstraint::bhkLimitedHingeConstraint() {
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
	NifStream( limitedHinge.perp2axleina1, in, info );
	NifStream( limitedHinge.perp2axleina2, in, info );
	NifStream( limitedHinge.pivotB, in, info );
	NifStream( limitedHinge.axleB, in, info );
	NifStream( limitedHinge.perp2axleinb2, in, info );
	NifStream( limitedHinge.minAngle, in, info );
	NifStream( limitedHinge.maxAngle, in, info );
	NifStream( limitedHinge.maxFriction, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkLimitedHingeConstraint::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConstraint::Write( out, link_map, info );
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

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string bhkLimitedHingeConstraint::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkConstraint::asString();
	out << "  Pivot A:  " << limitedHinge.pivotA << endl;
	out << "  Axle A:  " << limitedHinge.axleA << endl;
	out << "  Perp2AxleInA1:  " << limitedHinge.perp2axleina1 << endl;
	out << "  Perp2AxleInA2:  " << limitedHinge.perp2axleina2 << endl;
	out << "  Pivot B:  " << limitedHinge.pivotB << endl;
	out << "  Axle B:  " << limitedHinge.axleB << endl;
	out << "  Perp2AxleInB2:  " << limitedHinge.perp2axleinb2 << endl;
	out << "  Min Angle:  " << limitedHinge.minAngle << endl;
	out << "  Max Angle:  " << limitedHinge.maxAngle << endl;
	out << "  Max Friction:  " << limitedHinge.maxFriction << endl;
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

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
