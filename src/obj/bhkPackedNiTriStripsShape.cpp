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
#include "../../include/obj/bhkPackedNiTriStripsShape.h"
#include "../../include/gen/OblivionSubShape.h"
#include "../../include/obj/hkPackedNiTriStripsData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkPackedNiTriStripsShape::TYPE("bhkPackedNiTriStripsShape", &bhkShapeCollection::TYPE );

bhkPackedNiTriStripsShape::bhkPackedNiTriStripsShape() : numSubShapes((unsigned short)0), scale(1.0f), data(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

bhkPackedNiTriStripsShape::~bhkPackedNiTriStripsShape() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & bhkPackedNiTriStripsShape::GetType() const {
	return TYPE;
}

NiObject * bhkPackedNiTriStripsShape::Create() {
	return new bhkPackedNiTriStripsShape;
}

void bhkPackedNiTriStripsShape::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	bhkShapeCollection::Read( in, link_stack, info );
	NifStream( numSubShapes, in, info );
	subShapes.resize(numSubShapes);
	for (unsigned int i1 = 0; i1 < subShapes.size(); i1++) {
		NifStream( subShapes[i1].layer, in, info );
		NifStream( subShapes[i1].colFilter, in, info );
		NifStream( subShapes[i1].unknownShort, in, info );
		NifStream( subShapes[i1].numVertices, in, info );
		NifStream( subShapes[i1].material, in, info );
	};
	for (unsigned int i1 = 0; i1 < 9; i1++) {
		NifStream( unknownFloats[i1], in, info );
	};
	NifStream( scale, in, info );
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		NifStream( unknownFloats2[i1], in, info );
	};
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkPackedNiTriStripsShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkShapeCollection::Write( out, link_map, info );
	numSubShapes = (unsigned short)(subShapes.size());
	NifStream( numSubShapes, out, info );
	for (unsigned int i1 = 0; i1 < subShapes.size(); i1++) {
		NifStream( subShapes[i1].layer, out, info );
		NifStream( subShapes[i1].colFilter, out, info );
		NifStream( subShapes[i1].unknownShort, out, info );
		NifStream( subShapes[i1].numVertices, out, info );
		NifStream( subShapes[i1].material, out, info );
	};
	for (unsigned int i1 = 0; i1 < 9; i1++) {
		NifStream( unknownFloats[i1], out, info );
	};
	NifStream( scale, out, info );
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		NifStream( unknownFloats2[i1], out, info );
	};
	if ( info.version < VER_3_3_0_13 ) {
		NifStream( (unsigned int)&(*data), out, info );
	} else {
		if ( data != NULL ) {
			NifStream( link_map.find( StaticCast<NiObject>(data) )->second, out, info );
		} else {
			NifStream( 0xFFFFFFFF, out, info );
		}
	}

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string bhkPackedNiTriStripsShape::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkShapeCollection::asString();
	numSubShapes = (unsigned short)(subShapes.size());
	out << "  Num Sub Shapes:  " << numSubShapes << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < subShapes.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Layer:  " << subShapes[i1].layer << endl;
		out << "    Col Filter:  " << subShapes[i1].colFilter << endl;
		out << "    Unknown Short:  " << subShapes[i1].unknownShort << endl;
		out << "    Num Vertices:  " << subShapes[i1].numVertices << endl;
		out << "    Material:  " << subShapes[i1].material << endl;
	};
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 9; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Floats[" << i1 << "]:  " << unknownFloats[i1] << endl;
		array_output_count++;
	};
	out << "  Scale:  " << scale << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Floats 2[" << i1 << "]:  " << unknownFloats2[i1] << endl;
		array_output_count++;
	};
	out << "  Data:  " << data << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkPackedNiTriStripsShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkShapeCollection::FixLinks( objects, link_stack, info );
	data = FixLink<hkPackedNiTriStripsData>( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> bhkPackedNiTriStripsShape::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkShapeCollection::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//
Ref<hkPackedNiTriStripsData> bhkPackedNiTriStripsShape::GetData() const {
	return data;
}

void bhkPackedNiTriStripsShape::SetData( hkPackedNiTriStripsData * n ) {
	data = n;
}

//--END CUSTOM CODE--//
