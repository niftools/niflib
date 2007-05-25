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
#include "../../include/obj/bhkNiTriStripsShape.h"
#include "../../include/gen/OblivionColFilter.h"
#include "../../include/obj/NiTriStripsData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkNiTriStripsShape::TYPE("bhkNiTriStripsShape", &bhkShapeCollection::TYPE );

bhkNiTriStripsShape::bhkNiTriStripsShape() : unknownFloat1(0.1f), unknownInt1((unsigned int)0x004ABE60), unknownInt2((unsigned int)1), scale(1.0f, 1.0f, 1.0f), unknownInt3((unsigned int)0), numStripsData((unsigned int)0), numDataLayers((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

bhkNiTriStripsShape::~bhkNiTriStripsShape() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & bhkNiTriStripsShape::GetType() const {
	return TYPE;
}

namespace Niflib {
	typedef NiObject*(*obj_factory_func)();
	extern map<string, obj_factory_func> global_object_map;

	//Initialization function
	static bool Initialization();

	//A static bool to force the initialization to happen pre-main
	static bool obj_initialized = Initialization();

	static bool Initialization() {
		//Register this object type with Niflib
		ObjectRegistry::RegisterObject( "bhkNiTriStripsShape", bhkNiTriStripsShape::Create );

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * bhkNiTriStripsShape::Create() {
	return new bhkNiTriStripsShape;
}

void bhkNiTriStripsShape::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	bhkShapeCollection::Read( in, link_stack, info );
	NifStream( material, in, info );
	NifStream( unknownFloat1, in, info );
	NifStream( unknownInt1, in, info );
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		NifStream( unknownInts1[i1], in, info );
	};
	NifStream( unknownInt2, in, info );
	NifStream( scale, in, info );
	NifStream( unknownInt3, in, info );
	NifStream( numStripsData, in, info );
	stripsData.resize(numStripsData);
	for (unsigned int i1 = 0; i1 < stripsData.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( numDataLayers, in, info );
	dataLayers.resize(numDataLayers);
	for (unsigned int i1 = 0; i1 < dataLayers.size(); i1++) {
		NifStream( dataLayers[i1].layer, in, info );
		NifStream( dataLayers[i1].colFilter, in, info );
		NifStream( dataLayers[i1].unknownShort, in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkNiTriStripsShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkShapeCollection::Write( out, link_map, info );
	numDataLayers = (unsigned int)(dataLayers.size());
	numStripsData = (unsigned int)(stripsData.size());
	NifStream( material, out, info );
	NifStream( unknownFloat1, out, info );
	NifStream( unknownInt1, out, info );
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		NifStream( unknownInts1[i1], out, info );
	};
	NifStream( unknownInt2, out, info );
	NifStream( scale, out, info );
	NifStream( unknownInt3, out, info );
	NifStream( numStripsData, out, info );
	for (unsigned int i1 = 0; i1 < stripsData.size(); i1++) {
		if ( stripsData[i1] != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(stripsData[i1]) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
	NifStream( numDataLayers, out, info );
	for (unsigned int i1 = 0; i1 < dataLayers.size(); i1++) {
		NifStream( dataLayers[i1].layer, out, info );
		NifStream( dataLayers[i1].colFilter, out, info );
		NifStream( dataLayers[i1].unknownShort, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string bhkNiTriStripsShape::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkShapeCollection::asString();
	numDataLayers = (unsigned int)(dataLayers.size());
	numStripsData = (unsigned int)(stripsData.size());
	out << "  Material:  " << material << endl;
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Ints 1[" << i1 << "]:  " << unknownInts1[i1] << endl;
		array_output_count++;
	};
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	out << "  Scale:  " << scale << endl;
	out << "  Unknown Int 3:  " << unknownInt3 << endl;
	out << "  Num Strips Data:  " << numStripsData << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < stripsData.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Strips Data[" << i1 << "]:  " << stripsData[i1] << endl;
		array_output_count++;
	};
	out << "  Num Data Layers:  " << numDataLayers << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < dataLayers.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Layer:  " << dataLayers[i1].layer << endl;
		out << "    Col Filter:  " << dataLayers[i1].colFilter << endl;
		out << "    Unknown Short:  " << dataLayers[i1].unknownShort << endl;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkNiTriStripsShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkShapeCollection::FixLinks( objects, link_stack, info );
	for (unsigned int i1 = 0; i1 < stripsData.size(); i1++) {
		stripsData[i1] = FixLink<NiTriStripsData>( objects, link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> bhkNiTriStripsShape::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkShapeCollection::GetRefs();
	for (unsigned int i1 = 0; i1 < stripsData.size(); i1++) {
		if ( stripsData[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(stripsData[i1]));
	};
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

void bhkNiTriStripsShape::SetNumStripsData(int n)
{
	numStripsData = n;
	stripsData.resize(n);

   // This is currently a kludge for compatibility with the max NifExporter as we dont know what this 
   //   does but its always same number of strips and usually 1 or 4
   //numUnknownInts2 = n;
   //unknownInts2.assign(n, 1);

	//TODO:  Understand why these are gone and what to do about it
}

void bhkNiTriStripsShape::SetStripsData( int index, NiTriStripsData * strips )
{
	stripsData[index] = strips;
}

Vector3 bhkNiTriStripsShape::GetScale() const {
	return scale;
}

void bhkNiTriStripsShape::SetScale( const Vector3 & n ) {
	scale = n;	
}

//--END CUSTOM CODE--//
