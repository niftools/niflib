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
#include "../../include/obj/NiDefaultAVObjectPalette.h"
#include "../../include/gen/AVObject.h"
#include "../../include/obj/NiAVObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiDefaultAVObjectPalette::TYPE("NiDefaultAVObjectPalette", &NiAVObjectPalette::TYPE );

NiDefaultAVObjectPalette::NiDefaultAVObjectPalette() : unknownInt((unsigned int)0), numObjs((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiDefaultAVObjectPalette::~NiDefaultAVObjectPalette() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiDefaultAVObjectPalette::GetType() const {
	return TYPE;
}

//A static bool to force the initialization to happen pre-main
bool NiDefaultAVObjectPalette::obj_initialized = NiDefaultAVObjectPalette::Register();

bool NiDefaultAVObjectPalette::Register() {
	//Register this object type with Niflib
	ObjectRegistry::RegisterObject( "NiDefaultAVObjectPalette", NiDefaultAVObjectPalette::Create );

	//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
	obj_initialized = true;
	return obj_initialized;
}

NiObject * NiDefaultAVObjectPalette::Create() {
	return new NiDefaultAVObjectPalette;
}

void NiDefaultAVObjectPalette::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiAVObjectPalette::Read( in, link_stack, info );
	NifStream( unknownInt, in, info );
	NifStream( numObjs, in, info );
	objs.resize(numObjs);
	for (unsigned int i1 = 0; i1 < objs.size(); i1++) {
		NifStream( objs[i1].name, in, info );
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiDefaultAVObjectPalette::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiAVObjectPalette::Write( out, link_map, info );
	numObjs = (unsigned int)(objs.size());
	NifStream( unknownInt, out, info );
	NifStream( numObjs, out, info );
	for (unsigned int i1 = 0; i1 < objs.size(); i1++) {
		NifStream( objs[i1].name, out, info );
		if ( objs[i1].avObject != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(objs[i1].avObject) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiDefaultAVObjectPalette::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiAVObjectPalette::asString();
	numObjs = (unsigned int)(objs.size());
	out << "  Unknown Int:  " << unknownInt << endl;
	out << "  Num Objs:  " << numObjs << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < objs.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Name:  " << objs[i1].name << endl;
		out << "    AV Object:  " << objs[i1].avObject << endl;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiDefaultAVObjectPalette::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiAVObjectPalette::FixLinks( objects, link_stack, info );
	for (unsigned int i1 = 0; i1 < objs.size(); i1++) {
		objs[i1].avObject = FixLink<NiAVObject>( objects, link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiDefaultAVObjectPalette::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiAVObjectPalette::GetRefs();
	for (unsigned int i1 = 0; i1 < objs.size(); i1++) {
	};
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

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

//--END CUSTOM CODE--//
