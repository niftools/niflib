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
#include "../../include/obj/bhkCapsuleShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkCapsuleShape::TYPE("bhkCapsuleShape", &bhkConvexShape::TYPE );

bhkCapsuleShape::bhkCapsuleShape() : unknownShort1((unsigned short)0), unknownShort2((unsigned short)0), unknownShort3((unsigned short)0), unknownShort4((unsigned short)0), radius1(0.0f), radius2(0.0f) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

bhkCapsuleShape::~bhkCapsuleShape() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & bhkCapsuleShape::GetType() const {
	return TYPE;
}

NiObject * bhkCapsuleShape::Create() {
	return new bhkCapsuleShape;
}

void bhkCapsuleShape::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConvexShape::Read( in, link_stack, info );
	NifStream( unknownShort1, in, info );
	NifStream( unknownShort2, in, info );
	NifStream( unknownShort3, in, info );
	NifStream( unknownShort4, in, info );
	NifStream( firstPoint, in, info );
	NifStream( radius1, in, info );
	NifStream( secondPoint, in, info );
	NifStream( radius2, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkCapsuleShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConvexShape::Write( out, link_map, info );
	NifStream( unknownShort1, out, info );
	NifStream( unknownShort2, out, info );
	NifStream( unknownShort3, out, info );
	NifStream( unknownShort4, out, info );
	NifStream( firstPoint, out, info );
	NifStream( radius1, out, info );
	NifStream( secondPoint, out, info );
	NifStream( radius2, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string bhkCapsuleShape::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkConvexShape::asString();
	out << "  Unknown Short 1:  " << unknownShort1 << endl;
	out << "  Unknown Short 2:  " << unknownShort2 << endl;
	out << "  Unknown Short 3:  " << unknownShort3 << endl;
	out << "  Unknown Short 4:  " << unknownShort4 << endl;
	out << "  First Point:  " << firstPoint << endl;
	out << "  Radius 1:  " << radius1 << endl;
	out << "  Second Point:  " << secondPoint << endl;
	out << "  Radius 2:  " << radius2 << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkCapsuleShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConvexShape::FixLinks( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> bhkCapsuleShape::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkConvexShape::GetRefs();
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

float bhkCapsuleShape::GetRadius() const {
	return radius;
}

void bhkCapsuleShape::SetRadius( float value ) {
	radius = value;
}

Vector3 bhkCapsuleShape::GetFirstPoint() const {
	return firstPoint;
}

void bhkCapsuleShape::SetFirstPoint( const Vector3 & value ) {
	firstPoint = value;
}

float bhkCapsuleShape::GetRadius1() const {
	return radius1;
}

void bhkCapsuleShape::SetRadius1( float value ) {
	radius1 = value;
}

Vector3 bhkCapsuleShape::GetSecondPoint() const {
	return secondPoint;
}

void bhkCapsuleShape::SetSecondPoint( const Vector3 & value ) {
	secondPoint = value;
}

float bhkCapsuleShape::GetRadius2() const {
	return radius2;
}

void bhkCapsuleShape::SetRadius2( float value ) {
	radius2 = value;
}

//--END CUSTOM CODE--//
