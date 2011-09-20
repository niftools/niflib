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
#include "../../include/obj/BSSegmentedTriShape.h"
#include "../../include/gen/BSSegmentedTriangle.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSSegmentedTriShape::TYPE("BSSegmentedTriShape", &NiTriShape::TYPE );

BSSegmentedTriShape::BSSegmentedTriShape() : numSegTriangles((int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

BSSegmentedTriShape::~BSSegmentedTriShape() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & BSSegmentedTriShape::GetType() const {
	return TYPE;
}

NiObject * BSSegmentedTriShape::Create() {
	return new BSSegmentedTriShape;
}

void BSSegmentedTriShape::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiTriShape::Read( in, link_stack, info );
	NifStream( numSegTriangles, in, info );
	segTriangles.resize(numSegTriangles);
	for (unsigned int i1 = 0; i1 < segTriangles.size(); i1++) {
		NifStream( segTriangles[i1].unknownInt1, in, info );
		NifStream( segTriangles[i1].unknownInt2, in, info );
		NifStream( segTriangles[i1].unknownByte1, in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSSegmentedTriShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiTriShape::Write( out, link_map, missing_link_stack, info );
	numSegTriangles = (int)(segTriangles.size());
	NifStream( numSegTriangles, out, info );
	for (unsigned int i1 = 0; i1 < segTriangles.size(); i1++) {
		NifStream( segTriangles[i1].unknownInt1, out, info );
		NifStream( segTriangles[i1].unknownInt2, out, info );
		NifStream( segTriangles[i1].unknownByte1, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string BSSegmentedTriShape::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiTriShape::asString();
	numSegTriangles = (int)(segTriangles.size());
	out << "  Num Seg Triangles:  " << numSegTriangles << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < segTriangles.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown Int 1:  " << segTriangles[i1].unknownInt1 << endl;
		out << "    Unknown Int 2:  " << segTriangles[i1].unknownInt2 << endl;
		out << "    Unknown Byte 1:  " << segTriangles[i1].unknownByte1 << endl;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSSegmentedTriShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiTriShape::FixLinks( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> BSSegmentedTriShape::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTriShape::GetRefs();
	return refs;
}

std::list<NiObject *> BSSegmentedTriShape::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiTriShape::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
