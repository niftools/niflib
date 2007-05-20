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
#include "../../include/NIF_IO.h"
#include "../../include/obj/NiAlphaProperty.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiAlphaProperty::TYPE("NiAlphaProperty", &NiProperty::TYPE );

NiAlphaProperty::NiAlphaProperty() : flags((unsigned short)237), threshold((byte)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiAlphaProperty::~NiAlphaProperty() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiAlphaProperty::GetType() const {
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
		//Add the function to the global object map
		global_object_map["NiAlphaProperty"] = NiAlphaProperty::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiAlphaProperty::Create() {
	return new NiAlphaProperty;
}

void NiAlphaProperty::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiProperty::Read( in, link_stack, info );
	NifStream( flags, in, info );
	NifStream( threshold, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiAlphaProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiProperty::Write( out, link_map, info );
	NifStream( flags, out, info );
	NifStream( threshold, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiAlphaProperty::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	out << "  Threshold:  " << threshold << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiAlphaProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiProperty::FixLinks( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiAlphaProperty::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

unsigned short NiAlphaProperty::GetFlags() const {
	return flags;
}

void NiAlphaProperty::SetFlags( unsigned short n ) {
	flags = n;
}

byte NiAlphaProperty::GetTestThreshold() const {
	return threshold;
}

void NiAlphaProperty::SetTestThreshold( byte n ) {
	threshold = n;
}

#define NIFLIB_GET_FLAG(value, shift, mask) \
   (( value >> shift ) & mask)

#define NIFLIB_MASK_FLAG(flag, value, shift, mask) \
   ((flag & ~(mask << shift)) | ((value & mask) << shift))

NiAlphaProperty::BlendFunc NiAlphaProperty::GetSourceBlendFunc() const {
   return (NiAlphaProperty::BlendFunc)NIFLIB_GET_FLAG(flags, 1, 0x0f);
}

void NiAlphaProperty::SetSourceBlendFunc(BlendFunc value) {
   flags = NIFLIB_MASK_FLAG(flags, value, 1, 0x0f);
}

NiAlphaProperty::BlendFunc NiAlphaProperty::GetDestBlendFunc() const {
   return (NiAlphaProperty::BlendFunc)(( flags >> 5 ) & 0x0f);
}

void NiAlphaProperty::SetDestBlendFunc(BlendFunc value) {
   flags = NIFLIB_MASK_FLAG(flags, value, 5, 0x0f);
}

NiAlphaProperty::TestFunc NiAlphaProperty::GetTestFunc() const {
   return (NiAlphaProperty::TestFunc)NIFLIB_GET_FLAG(flags, 10, 0x7);
}

void NiAlphaProperty::SetTestFunc(TestFunc value) {
   flags = NIFLIB_MASK_FLAG(flags, value, 10, 0x7);
}

bool NiAlphaProperty::GetBlendState() const {
   return NIFLIB_GET_FLAG(flags, 0, 0x1) ? true : false;
}

void NiAlphaProperty::SetBlendState(bool value) {
   flags = NIFLIB_MASK_FLAG(flags, value?1:0, 0, 0x1);
}

bool NiAlphaProperty::GetTestState() const {
   return NIFLIB_GET_FLAG(flags, 9, 0x1) ? true : false;
}

void NiAlphaProperty::SetTestState(bool value) {
   flags = NIFLIB_MASK_FLAG(flags, value?1:0, 9, 0x1);
}

bool NiAlphaProperty::GetTriangleSortMode() const {
   return NIFLIB_GET_FLAG(flags, 13, 0x1) ? false : true;
}
void NiAlphaProperty::SetTriangleSortMode(bool value) {
   flags = NIFLIB_MASK_FLAG(flags, value?0:1, 13, 0x1);
}

//--END CUSTOM CODE--//
