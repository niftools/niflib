/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiDefaultAVObjectPalette.h"
#include "../../include/gen/AVObject.h"
#include "../../include/obj/NiAVObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiDefaultAVObjectPalette::TYPE("NiDefaultAVObjectPalette", &NI_DEFAULT_A_V_OBJECT_PALETTE_PARENT::TYPE );

NiDefaultAVObjectPalette::NiDefaultAVObjectPalette() NI_DEFAULT_A_V_OBJECT_PALETTE_CONSTRUCT {}

NiDefaultAVObjectPalette::~NiDefaultAVObjectPalette() {}

void NiDefaultAVObjectPalette::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiDefaultAVObjectPalette::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiDefaultAVObjectPalette::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiDefaultAVObjectPalette::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiDefaultAVObjectPalette::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiDefaultAVObjectPalette::GetType() const {
	return TYPE;
};

vector<Ref<NiAVObject> > NiDefaultAVObjectPalette::GetObjs() const {
   vector<NiAVObjectRef> objRefs;
   for (vector<AVObject>::const_iterator itr = objs.begin(); itr != objs.end(); ++itr) {
      objRefs.push_back(itr->avObject);
   }
	return objRefs;
}

void NiDefaultAVObjectPalette::SetObjs( const vector<Ref<NiAVObject> >& value ) {
   objs.clear();
   for (vector<NiAVObjectRef>::const_iterator itr = value.begin(); itr != value.end(); ++itr) {
      AVObject obj;
      obj.name = (*itr)->GetName();
      obj.avObject = (*itr);
      objs.push_back(obj);
   }
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
		global_object_map["NiDefaultAVObjectPalette"] = NiDefaultAVObjectPalette::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiDefaultAVObjectPalette::Create() {
	return new NiDefaultAVObjectPalette;
}
