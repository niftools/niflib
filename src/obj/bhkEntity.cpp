/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkEntity.h"
#include "../../include/obj/bhkShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkEntity::TYPE("bhkEntity", &BHK_ENTITY_PARENT::TYPE );

bhkEntity::bhkEntity() BHK_ENTITY_CONSTRUCT {}

bhkEntity::~bhkEntity() {}

void bhkEntity::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void bhkEntity::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string bhkEntity::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkEntity::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> bhkEntity::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkEntity::GetType() const {
	return TYPE;
};

Ref<bhkShape > bhkEntity::GetShape() const {
	return shape;
}

void bhkEntity::SetShape( bhkShape * value ) {
	shape = value;
}

OblivionLayer bhkEntity::GetLayer() const {
	return layer;
}

void bhkEntity::SetLayer( OblivionLayer value ) {
	layer = value;
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
		global_object_map["bhkEntity"] = bhkEntity::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * bhkEntity::Create() {
	return new bhkEntity;
}
