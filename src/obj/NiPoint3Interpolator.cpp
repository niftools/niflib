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
#include "../../include/obj/NiPoint3Interpolator.h"
#include "../../include/obj/NiPosData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPoint3Interpolator::TYPE("NiPoint3Interpolator", &NiKeyBasedInterpolator::TYPE );

NiPoint3Interpolator::NiPoint3Interpolator() : data(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiPoint3Interpolator::~NiPoint3Interpolator() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiPoint3Interpolator::GetType() const {
	return TYPE;
}

//A static bool to force the initialization to happen pre-main
bool NiPoint3Interpolator::obj_initialized = NiPoint3Interpolator::Register();

bool NiPoint3Interpolator::Register() {
	//Register this object type with Niflib
	ObjectRegistry::RegisterObject( "NiPoint3Interpolator", NiPoint3Interpolator::Create );

	//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
	obj_initialized = true;
	return obj_initialized;
}

NiObject * NiPoint3Interpolator::Create() {
	return new NiPoint3Interpolator;
}

void NiPoint3Interpolator::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiKeyBasedInterpolator::Read( in, link_stack, info );
	NifStream( point3Value, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiPoint3Interpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiKeyBasedInterpolator::Write( out, link_map, info );
	NifStream( point3Value, out, info );
	if ( data != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(data) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiPoint3Interpolator::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiKeyBasedInterpolator::asString();
	out << "  Point 3 Value:  " << point3Value << endl;
	out << "  Data:  " << data << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiPoint3Interpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiKeyBasedInterpolator::FixLinks( objects, link_stack, info );
	data = FixLink<NiPosData>( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPoint3Interpolator::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiKeyBasedInterpolator::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

Vector3 NiPoint3Interpolator::GetPoint3Value() const {
	return point3Value;
}

void NiPoint3Interpolator::SetPoint3Value( Vector3 value ) {
	point3Value = value;
}

Ref<NiPosData > NiPoint3Interpolator::GetData() const {
	return data;
}

void NiPoint3Interpolator::SetData( NiPosData * value ) {
	data = value;
}

//--END CUSTOM CODE--//
