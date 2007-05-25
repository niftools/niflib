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
#include "../../include/obj/hkPackedNiTriStripsData.h"
#include "../../include/gen/hkTriangle.h"
using namespace Niflib;

//Definition of TYPE constant
const Type hkPackedNiTriStripsData::TYPE("hkPackedNiTriStripsData", &bhkShapeCollection::TYPE );

hkPackedNiTriStripsData::hkPackedNiTriStripsData() : numTriangles((unsigned int)0), numVertices((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

hkPackedNiTriStripsData::~hkPackedNiTriStripsData() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & hkPackedNiTriStripsData::GetType() const {
	return TYPE;
}

//A static bool to force the initialization to happen pre-main
bool hkPackedNiTriStripsData::obj_initialized = hkPackedNiTriStripsData::Register();

bool hkPackedNiTriStripsData::Register() {
	//Register this object type with Niflib
	ObjectRegistry::RegisterObject( "hkPackedNiTriStripsData", hkPackedNiTriStripsData::Create );

	//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
	obj_initialized = true;
	return obj_initialized;
}

NiObject * hkPackedNiTriStripsData::Create() {
	return new hkPackedNiTriStripsData;
}

void hkPackedNiTriStripsData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkShapeCollection::Read( in, link_stack, info );
	NifStream( numTriangles, in, info );
	triangles.resize(numTriangles);
	for (unsigned int i1 = 0; i1 < triangles.size(); i1++) {
		NifStream( triangles[i1].triangle, in, info );
		NifStream( triangles[i1].unknownShort, in, info );
		NifStream( triangles[i1].normal, in, info );
	};
	NifStream( numVertices, in, info );
	vertices.resize(numVertices);
	for (unsigned int i1 = 0; i1 < vertices.size(); i1++) {
		NifStream( vertices[i1], in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void hkPackedNiTriStripsData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkShapeCollection::Write( out, link_map, info );
	numVertices = (unsigned int)(vertices.size());
	numTriangles = (unsigned int)(triangles.size());
	NifStream( numTriangles, out, info );
	for (unsigned int i1 = 0; i1 < triangles.size(); i1++) {
		NifStream( triangles[i1].triangle, out, info );
		NifStream( triangles[i1].unknownShort, out, info );
		NifStream( triangles[i1].normal, out, info );
	};
	NifStream( numVertices, out, info );
	for (unsigned int i1 = 0; i1 < vertices.size(); i1++) {
		NifStream( vertices[i1], out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string hkPackedNiTriStripsData::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkShapeCollection::asString();
	numVertices = (unsigned int)(vertices.size());
	numTriangles = (unsigned int)(triangles.size());
	out << "  Num Triangles:  " << numTriangles << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < triangles.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Triangle:  " << triangles[i1].triangle << endl;
		out << "    Unknown Short:  " << triangles[i1].unknownShort << endl;
		out << "    Normal:  " << triangles[i1].normal << endl;
	};
	out << "  Num Vertices:  " << numVertices << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < vertices.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Vertices[" << i1 << "]:  " << vertices[i1] << endl;
		array_output_count++;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void hkPackedNiTriStripsData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkShapeCollection::FixLinks( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> hkPackedNiTriStripsData::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkShapeCollection::GetRefs();
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
