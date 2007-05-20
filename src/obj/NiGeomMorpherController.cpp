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
#include "../../include/obj/NiGeomMorpherController.h"
#include "../../include/obj/NiMorphData.h"
#include "../../include/obj/NiInterpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiGeomMorpherController::TYPE("NiGeomMorpherController", &NiInterpController::TYPE );

NiGeomMorpherController::NiGeomMorpherController() : unknown((unsigned short)0), unknown2((byte)0), data(NULL), unknownByte((byte)0), numInterpolators((unsigned int)0), numUnknownInts((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiGeomMorpherController::~NiGeomMorpherController() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiGeomMorpherController::GetType() const {
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
		global_object_map["NiGeomMorpherController"] = NiGeomMorpherController::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiGeomMorpherController::Create() {
	return new NiGeomMorpherController;
}

void NiGeomMorpherController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiInterpController::Read( in, link_stack, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( unknown, in, info );
	};
	if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A01006A ) ) {
		NifStream( unknown2, in, info );
	};
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( unknownByte, in, info );
	if ( info.version >= 0x0A01006A ) {
		NifStream( numInterpolators, in, info );
		interpolators.resize(numInterpolators);
		for (unsigned int i2 = 0; i2 < interpolators.size(); i2++) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
	};
	if ( info.version >= 0x0A020000 ) {
		NifStream( numUnknownInts, in, info );
		unknownInts.resize(numUnknownInts);
		for (unsigned int i2 = 0; i2 < unknownInts.size(); i2++) {
			NifStream( unknownInts[i2], in, info );
		};
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiGeomMorpherController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiInterpController::Write( out, link_map, info );
	numUnknownInts = (unsigned int)(unknownInts.size());
	numInterpolators = (unsigned int)(interpolators.size());
	if ( info.version >= 0x0A010000 ) {
		NifStream( unknown, out, info );
	};
	if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A01006A ) ) {
		NifStream( unknown2, out, info );
	};
	if ( data != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(data) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	NifStream( unknownByte, out, info );
	if ( info.version >= 0x0A01006A ) {
		NifStream( numInterpolators, out, info );
		for (unsigned int i2 = 0; i2 < interpolators.size(); i2++) {
			if ( interpolators[i2] != NULL )
				NifStream( link_map.find( StaticCast<NiObject>(interpolators[i2]) )->second, out, info );
			else
				NifStream( 0xffffffff, out, info );
		};
	};
	if ( info.version >= 0x0A020000 ) {
		NifStream( numUnknownInts, out, info );
		for (unsigned int i2 = 0; i2 < unknownInts.size(); i2++) {
			NifStream( unknownInts[i2], out, info );
		};
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiGeomMorpherController::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiInterpController::asString();
	numUnknownInts = (unsigned int)(unknownInts.size());
	numInterpolators = (unsigned int)(interpolators.size());
	out << "  Unknown:  " << unknown << endl;
	out << "  Unknown 2:  " << unknown2 << endl;
	out << "  Data:  " << data << endl;
	out << "  Unknown Byte:  " << unknownByte << endl;
	out << "  Num Interpolators:  " << numInterpolators << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < interpolators.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Interpolators[" << i1 << "]:  " << interpolators[i1] << endl;
		array_output_count++;
	};
	out << "  Num Unknown Ints:  " << numUnknownInts << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < unknownInts.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Ints[" << i1 << "]:  " << unknownInts[i1] << endl;
		array_output_count++;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiGeomMorpherController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiInterpController::FixLinks( objects, link_stack, info );
	data = FixLink<NiMorphData>( objects, link_stack, info );
	if ( info.version >= 0x0A01006A ) {
		for (unsigned int i2 = 0; i2 < interpolators.size(); i2++) {
			interpolators[i2] = FixLink<NiInterpolator>( objects, link_stack, info );
		};
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiGeomMorpherController::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiInterpController::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	for (unsigned int i1 = 0; i1 < interpolators.size(); i1++) {
		if ( interpolators[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(interpolators[i1]));
	};
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

vector< Ref<NiInterpolator> > NiGeomMorpherController::GetInterpolators() const {
	return interpolators;
}

void NiGeomMorpherController::SetInterpolators( const vector< Ref<NiInterpolator> > & n ) {
	numInterpolators = (unsigned int)(n.size());
	interpolators = n;
}

Ref<NiMorphData> NiGeomMorpherController::GetData() const {
	return data;
}

void NiGeomMorpherController::SetData( NiMorphData * n ) {
	data = n;
}

//--END CUSTOM CODE--//
