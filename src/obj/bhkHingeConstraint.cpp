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
#include "../../include/obj/bhkHingeConstraint.h"
#include "../../include/gen/HingeDescriptor.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkHingeConstraint::TYPE("bhkHingeConstraint", &bhkConstraint::TYPE );

bhkHingeConstraint::bhkHingeConstraint() : unknownFloat1(0.0f), unknownByte1((byte)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

bhkHingeConstraint::~bhkHingeConstraint() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & bhkHingeConstraint::GetType() const {
	return TYPE;
}

NiObject * bhkHingeConstraint::Create() {
	return new bhkHingeConstraint;
}

void bhkHingeConstraint::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConstraint::Read( in, link_stack, info );
	NifStream( hinge.pivotA, in, info );
	NifStream( hinge.perp2AxleInA1, in, info );
	NifStream( hinge.perp2AxleInA2, in, info );
	NifStream( hinge.pivotB, in, info );
	NifStream( hinge.axleB, in, info );
	if ( info.version >= 0x14020007 ) {
		NifStream( hinge.unknownFloat1, in, info );
		NifStream( hinge.unknownInt2, in, info );
		NifStream( hinge.unknownInt3, in, info );
		NifStream( hinge.unknownInt4, in, info );
		NifStream( hinge.unknownInt5, in, info );
		NifStream( hinge.unknownInt6, in, info );
		NifStream( hinge.unknownInt7, in, info );
		NifStream( hinge.unknownInt8, in, info );
		NifStream( hinge.unknownInt9, in, info );
		NifStream( hinge.unknownInt10, in, info );
		NifStream( hinge.unknownByte1, in, info );
		NifStream( hinge.unknownByte2, in, info );
		NifStream( hinge.unknownByte3, in, info );
	};
	if ( info.version >= 0x14020007 ) {
		NifStream( unknownFloat1, in, info );
		NifStream( unknownByte1, in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkHingeConstraint::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConstraint::Write( out, link_map, info );
	NifStream( hinge.pivotA, out, info );
	NifStream( hinge.perp2AxleInA1, out, info );
	NifStream( hinge.perp2AxleInA2, out, info );
	NifStream( hinge.pivotB, out, info );
	NifStream( hinge.axleB, out, info );
	if ( info.version >= 0x14020007 ) {
		NifStream( hinge.unknownFloat1, out, info );
		NifStream( hinge.unknownInt2, out, info );
		NifStream( hinge.unknownInt3, out, info );
		NifStream( hinge.unknownInt4, out, info );
		NifStream( hinge.unknownInt5, out, info );
		NifStream( hinge.unknownInt6, out, info );
		NifStream( hinge.unknownInt7, out, info );
		NifStream( hinge.unknownInt8, out, info );
		NifStream( hinge.unknownInt9, out, info );
		NifStream( hinge.unknownInt10, out, info );
		NifStream( hinge.unknownByte1, out, info );
		NifStream( hinge.unknownByte2, out, info );
		NifStream( hinge.unknownByte3, out, info );
	};
	if ( info.version >= 0x14020007 ) {
		NifStream( unknownFloat1, out, info );
		NifStream( unknownByte1, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string bhkHingeConstraint::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	out << bhkConstraint::asString();
	out << "  Pivot A:  " << hinge.pivotA << endl;
	out << "  Perp2 Axle In A1:  " << hinge.perp2AxleInA1 << endl;
	out << "  Perp2 Axle In A2:  " << hinge.perp2AxleInA2 << endl;
	out << "  Pivot B:  " << hinge.pivotB << endl;
	out << "  Axle B:  " << hinge.axleB << endl;
	out << "  Unknown Float 1:  " << hinge.unknownFloat1 << endl;
	out << "  Unknown Int 2:  " << hinge.unknownInt2 << endl;
	out << "  Unknown Int 3:  " << hinge.unknownInt3 << endl;
	out << "  Unknown Int 4:  " << hinge.unknownInt4 << endl;
	out << "  Unknown Int 5:  " << hinge.unknownInt5 << endl;
	out << "  Unknown Int 6:  " << hinge.unknownInt6 << endl;
	out << "  Unknown Int 7:  " << hinge.unknownInt7 << endl;
	out << "  Unknown Int 8:  " << hinge.unknownInt8 << endl;
	out << "  Unknown Int 9:  " << hinge.unknownInt9 << endl;
	out << "  Unknown Int 10:  " << hinge.unknownInt10 << endl;
	out << "  Unknown Byte 1:  " << hinge.unknownByte1 << endl;
	out << "  Unknown Byte 2:  " << hinge.unknownByte2 << endl;
	out << "  Unknown Byte 3:  " << hinge.unknownByte3 << endl;
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Unknown Byte 1:  " << unknownByte1 << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkHingeConstraint::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConstraint::FixLinks( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> bhkHingeConstraint::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkConstraint::GetRefs();
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
