/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkNiTriStripsShape.h"
#include "../../include/obj/NiTriStripsData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkNiTriStripsShape::TYPE("bhkNiTriStripsShape", &BHK_NI_TRI_STRIPS_SHAPE_PARENT::TypeConst() );

bhkNiTriStripsShape::bhkNiTriStripsShape() BHK_NI_TRI_STRIPS_SHAPE_CONSTRUCT {}

bhkNiTriStripsShape::~bhkNiTriStripsShape() {}

void bhkNiTriStripsShape::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void bhkNiTriStripsShape::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string bhkNiTriStripsShape::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkNiTriStripsShape::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
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
   numUnknownInts2 = n;
   unknownInts2.assign(n, 1);
}

void bhkNiTriStripsShape::SetStripsData(int i, Ref<NiTriStripsData> &strips)
{
	stripsData[i] = strips;
}

Vector3 bhkNiTriStripsShape::GetScale() const {
	return scale;
}

void bhkNiTriStripsShape::SetScale( const Vector3 & n ) {
	scale = n;	
}

