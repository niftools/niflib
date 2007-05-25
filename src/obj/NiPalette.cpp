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
#include "../../include/obj/NiPalette.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPalette::TYPE("NiPalette", &NiObject::TYPE );

NiPalette::NiPalette() : unknownByte((byte)0), numEntries_((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiPalette::~NiPalette() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiPalette::GetType() const {
	return TYPE;
}

NiObject * NiPalette::Create() {
	return new NiPalette;
}

void NiPalette::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::Read( in, link_stack, info );
	NifStream( unknownByte, in, info );
	NifStream( numEntries_, in, info );
	for (unsigned int i1 = 0; i1 < 256; i1++) {
		for (unsigned int i2 = 0; i2 < 4; i2++) {
			NifStream( palette[i1][i2], in, info );
		};
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiPalette::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, info );
	NifStream( unknownByte, out, info );
	NifStream( numEntries_, out, info );
	for (unsigned int i1 = 0; i1 < 256; i1++) {
		for (unsigned int i2 = 0; i2 < 4; i2++) {
			NifStream( palette[i1][i2], out, info );
		};
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiPalette::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	out << "  Unknown Byte:  " << unknownByte << endl;
	out << "  Num Entries?:  " << numEntries_ << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 256; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (unsigned int i2 = 0; i2 < 4; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Palette[" << i2 << "]:  " << palette[i1][i2] << endl;
			array_output_count++;
		};
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiPalette::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPalette::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

vector<Color4> NiPalette::GetPalette() const {
	vector<Color4> color_pal(256);

	for ( unsigned int i = 0; i < 256; ++i ) {
		
		color_pal[i].r = float(palette[i][0]) / 255.0f;
		color_pal[i].g = float(palette[i][1]) / 255.0f;
		color_pal[i].b = float(palette[i][2]) / 255.0f;
		color_pal[i].a = float(palette[i][3]) / 255.0f;
	}

	return color_pal;
}

void NiPalette::SetPalette( const vector<Color4> & new_pal ) {
	if ( new_pal.size() != 256 ) {
		throw runtime_error( "Palette size must be 256" );
	}

	for ( unsigned int i = 0; i < 256; ++i ) {
		palette[i][0] = int( new_pal[i].r * 255.0f );
		palette[i][1] = int( new_pal[i].g * 255.0f );
		palette[i][2] = int( new_pal[i].b * 255.0f );
		palette[i][3] = int( new_pal[i].a * 255.0f );
	}
}

//--END CUSTOM CODE--//
