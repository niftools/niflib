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
#include "../../include/obj/bhkMoppBvTreeShape.h"
#include "../../include/obj/bhkShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkMoppBvTreeShape::TYPE("bhkMoppBvTreeShape", &bhkBvTreeShape::TYPE );

bhkMoppBvTreeShape::bhkMoppBvTreeShape() : shape(NULL), unknownFloat(0.0f), moppDataSize((unsigned int)0), scalingFactor(0.0f) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

bhkMoppBvTreeShape::~bhkMoppBvTreeShape() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & bhkMoppBvTreeShape::GetType() const {
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
		global_object_map["bhkMoppBvTreeShape"] = bhkMoppBvTreeShape::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * bhkMoppBvTreeShape::Create() {
	return new bhkMoppBvTreeShape;
}

void bhkMoppBvTreeShape::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	bhkBvTreeShape::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( material, in, info );
	for (unsigned int i1 = 0; i1 < 8; i1++) {
		NifStream( unknown8Bytes[i1], in, info );
	};
	NifStream( unknownFloat, in, info );
	NifStream( moppDataSize, in, info );
	if ( info.version >= 0x14000005 ) {
		NifStream( objectCorner, in, info );
		NifStream( scalingFactor, in, info );
	};
	moppData.resize(moppDataSize);
	for (unsigned int i1 = 0; i1 < moppData.size(); i1++) {
		NifStream( moppData[i1], in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkMoppBvTreeShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkBvTreeShape::Write( out, link_map, info );
	moppDataSize = (unsigned int)(moppData.size());
	if ( shape != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(shape) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	NifStream( material, out, info );
	for (unsigned int i1 = 0; i1 < 8; i1++) {
		NifStream( unknown8Bytes[i1], out, info );
	};
	NifStream( unknownFloat, out, info );
	NifStream( moppDataSize, out, info );
	if ( info.version >= 0x14000005 ) {
		NifStream( objectCorner, out, info );
		NifStream( scalingFactor, out, info );
	};
	for (unsigned int i1 = 0; i1 < moppData.size(); i1++) {
		NifStream( moppData[i1], out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string bhkMoppBvTreeShape::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkBvTreeShape::asString();
	moppDataSize = (unsigned int)(moppData.size());
	out << "  Shape:  " << shape << endl;
	out << "  Material:  " << material << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 8; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown 8 Bytes[" << i1 << "]:  " << unknown8Bytes[i1] << endl;
		array_output_count++;
	};
	out << "  Unknown Float:  " << unknownFloat << endl;
	out << "  MOPP Data Size:  " << moppDataSize << endl;
	out << "  Object Corner:  " << objectCorner << endl;
	out << "  Scaling Factor:  " << scalingFactor << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < moppData.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    MOPP Data[" << i1 << "]:  " << moppData[i1] << endl;
		array_output_count++;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkMoppBvTreeShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkBvTreeShape::FixLinks( objects, link_stack, info );
	shape = FixLink<bhkShape>( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> bhkMoppBvTreeShape::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkBvTreeShape::GetRefs();
	if ( shape != NULL )
		refs.push_back(StaticCast<NiObject>(shape));
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
