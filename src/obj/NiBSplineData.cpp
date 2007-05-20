/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiBSplineData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBSplineData::TYPE("NiBSplineData", &NI_B_SPLINE_DATA_PARENT::TYPE );

NiBSplineData::NiBSplineData() NI_B_SPLINE_DATA_CONSTRUCT {}

NiBSplineData::~NiBSplineData() {}

void NiBSplineData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiBSplineData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiBSplineData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBSplineData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiBSplineData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBSplineData::GetType() const {
	return TYPE;
};

//--BEGIN MISC CUSTOM CODE--//

vector<short > NiBSplineData::GetControlPoints() const 
{
	return controlPoints;
}

vector<short > NiBSplineData::GetControlPointRange(int offset, int count) const
{
   vector<short> value;
   if (offset < 0 || count < 0 || ((offset + count) > int(controlPoints.size())))
      throw runtime_error("Invalid offset or count.");
   vector<short>::const_iterator srcbeg = controlPoints.begin(), srcend = controlPoints.begin(); 
   std::advance(srcbeg, offset);
   std::advance(srcend, offset + count);
   return vector<short>(srcbeg, srcend);
}

//--END CUSTOM CODE--//

namespace Niflib { 
	typedef NiObject*(*obj_factory_func)();
	extern map<string, obj_factory_func> global_object_map;

	//Initialization function
	static bool Initialization();

	//A static bool to force the initialization to happen pre-main
	static bool obj_initialized = Initialization();

	static bool Initialization() {
		//Add the function to the global object map
		global_object_map["NiBSplineData"] = NiBSplineData::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiBSplineData::Create() {
	return new NiBSplineData;
}
