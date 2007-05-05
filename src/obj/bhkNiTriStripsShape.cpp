/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkNiTriStripsShape.h"
#include "../../include/obj/NiTriStripsData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkNiTriStripsShape::TYPE("bhkNiTriStripsShape", &BHK_NI_TRI_STRIPS_SHAPE_PARENT::TYPE );

bhkNiTriStripsShape::bhkNiTriStripsShape() BHK_NI_TRI_STRIPS_SHAPE_CONSTRUCT {}

bhkNiTriStripsShape::~bhkNiTriStripsShape() {}

void bhkNiTriStripsShape::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void bhkNiTriStripsShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string bhkNiTriStripsShape::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkNiTriStripsShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> bhkNiTriStripsShape::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkNiTriStripsShape::GetType() const {
	return TYPE;
};

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

namespace Niflib { 
	typedef NiObject*(*obj_factory_func)();
	extern map<string, obj_factory_func> global_object_map;

	//Initialization function
	static bool Initialization();

	//A static bool to force the initialization to happen pre-main
	static bool obj_initialized = Initialization();

	static bool Initialization() {
		//Add the function to the global object map
		global_object_map["bhkNiTriStripsShape"] = bhkNiTriStripsShape::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * bhkNiTriStripsShape::Create() {
	return new bhkNiTriStripsShape;
}
