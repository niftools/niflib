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
#include "../../include/obj/NiMultiTextureProperty.h"
#include "../../include/gen/MultiTextureElement.h"
#include "../../include/obj/NiImage.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiMultiTextureProperty::TYPE("NiMultiTextureProperty", &NiProperty::TYPE );

NiMultiTextureProperty::NiMultiTextureProperty() : flags((unsigned short)0), unknownInt((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiMultiTextureProperty::~NiMultiTextureProperty() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiMultiTextureProperty::GetType() const {
	return TYPE;
}

NiObject * NiMultiTextureProperty::Create() {
	return new NiMultiTextureProperty;
}

void NiMultiTextureProperty::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiProperty::Read( in, link_stack, info );
	NifStream( flags, in, info );
	NifStream( unknownInt, in, info );
	for (unsigned int i1 = 0; i1 < 5; i1++) {
		NifStream( textureElements[i1].hasImage, in, info );
		if ( textureElements[i1].hasImage ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
			NifStream( textureElements[i1].unknownInt1, in, info );
			NifStream( textureElements[i1].unknownInt2, in, info );
			NifStream( textureElements[i1].unknownInt3, in, info );
			NifStream( textureElements[i1].unknownShort1, in, info );
			NifStream( textureElements[i1].unknownShort2, in, info );
			NifStream( textureElements[i1].unknownShort3, in, info );
		};
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiMultiTextureProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiProperty::Write( out, link_map, info );
	NifStream( flags, out, info );
	NifStream( unknownInt, out, info );
	for (unsigned int i1 = 0; i1 < 5; i1++) {
		NifStream( textureElements[i1].hasImage, out, info );
		if ( textureElements[i1].hasImage ) {
			if ( textureElements[i1].image != NULL )
				NifStream( link_map.find( StaticCast<NiObject>(textureElements[i1].image) )->second, out, info );
			else
				NifStream( 0xffffffff, out, info );
			NifStream( textureElements[i1].unknownInt1, out, info );
			NifStream( textureElements[i1].unknownInt2, out, info );
			NifStream( textureElements[i1].unknownInt3, out, info );
			NifStream( textureElements[i1].unknownShort1, out, info );
			NifStream( textureElements[i1].unknownShort2, out, info );
			NifStream( textureElements[i1].unknownShort3, out, info );
		};
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiMultiTextureProperty::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	out << "  Unknown Int:  " << unknownInt << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 5; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Has Image:  " << textureElements[i1].hasImage << endl;
		if ( textureElements[i1].hasImage ) {
			out << "      Image:  " << textureElements[i1].image << endl;
			out << "      Unknown Int 1:  " << textureElements[i1].unknownInt1 << endl;
			out << "      Unknown Int 2:  " << textureElements[i1].unknownInt2 << endl;
			out << "      Unknown Int 3:  " << textureElements[i1].unknownInt3 << endl;
			out << "      Unknown Short 1:  " << textureElements[i1].unknownShort1 << endl;
			out << "      Unknown Short 2:  " << textureElements[i1].unknownShort2 << endl;
			out << "      Unknown Short 3:  " << textureElements[i1].unknownShort3 << endl;
		};
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiMultiTextureProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiProperty::FixLinks( objects, link_stack, info );
	for (unsigned int i1 = 0; i1 < 5; i1++) {
		if ( textureElements[i1].hasImage ) {
			textureElements[i1].image = FixLink<NiImage>( objects, link_stack, info );
		};
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiMultiTextureProperty::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	for (unsigned int i1 = 0; i1 < 5; i1++) {
		if ( textureElements[i1].image != NULL )
			refs.push_back(StaticCast<NiObject>(textureElements[i1].image));
	};
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
