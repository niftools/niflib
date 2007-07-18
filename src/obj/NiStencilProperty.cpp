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
#include "../../include/obj/NiStencilProperty.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiStencilProperty::TYPE("NiStencilProperty", &NiProperty::TYPE );

NiStencilProperty::NiStencilProperty() : flags((unsigned short)0), stencilEnabled((byte)0), stencilRef((unsigned int)0), stencilMask((unsigned int)4294967295) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiStencilProperty::~NiStencilProperty() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiStencilProperty::GetType() const {
	return TYPE;
}

NiObject * NiStencilProperty::Create() {
	return new NiStencilProperty;
}

void NiStencilProperty::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiProperty::Read( in, link_stack, info );
	if ( info.version <= 0x0A000102 ) {
		NifStream( flags, in, info );
	};
	NifStream( stencilEnabled, in, info );
	NifStream( stencilFunction, in, info );
	if ( info.version <= 0x14000005 ) {
		NifStream( stencilRef, in, info );
		NifStream( stencilMask, in, info );
		NifStream( failAction, in, info );
		NifStream( zFailAction, in, info );
		NifStream( passAction, in, info );
		NifStream( drawMode, in, info );
	};
	if ( info.version >= 0x14010003 ) {
		for (unsigned int i2 = 0; i2 < 5; i2++) {
			NifStream( unknownBytes[i2], in, info );
		};
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiStencilProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiProperty::Write( out, link_map, info );
	if ( info.version <= 0x0A000102 ) {
		NifStream( flags, out, info );
	};
	NifStream( stencilEnabled, out, info );
	NifStream( stencilFunction, out, info );
	if ( info.version <= 0x14000005 ) {
		NifStream( stencilRef, out, info );
		NifStream( stencilMask, out, info );
		NifStream( failAction, out, info );
		NifStream( zFailAction, out, info );
		NifStream( passAction, out, info );
		NifStream( drawMode, out, info );
	};
	if ( info.version >= 0x14010003 ) {
		for (unsigned int i2 = 0; i2 < 5; i2++) {
			NifStream( unknownBytes[i2], out, info );
		};
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiStencilProperty::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	out << "  Stencil Enabled:  " << stencilEnabled << endl;
	out << "  Stencil Function:  " << stencilFunction << endl;
	out << "  Stencil Ref:  " << stencilRef << endl;
	out << "  Stencil Mask:  " << stencilMask << endl;
	out << "  Fail Action:  " << failAction << endl;
	out << "  Z Fail Action:  " << zFailAction << endl;
	out << "  Pass Action:  " << passAction << endl;
	out << "  Draw Mode:  " << drawMode << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 5; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Bytes[" << i1 << "]:  " << unknownBytes[i1] << endl;
		array_output_count++;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiStencilProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiProperty::FixLinks( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiStencilProperty::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

unsigned short NiStencilProperty::GetFlags() const {
   return flags;
}

void NiStencilProperty::SetFlags(unsigned short value) {
   flags = value;
}

bool NiStencilProperty::GetStencilState() const {
   return (stencilEnabled != 0);
}

void NiStencilProperty::SetStencilState(bool value) {
   stencilEnabled = value;
}

CompareMode NiStencilProperty::GetStencilFunction() const {
   return stencilFunction;
}

void NiStencilProperty::SetStencilFunction(CompareMode value) {
   stencilFunction = value;
}

unsigned int NiStencilProperty::GetStencilRef() const {
   return stencilRef;
}

void NiStencilProperty::SetStencilRef(unsigned int value) {
   stencilRef = value;
}

unsigned int NiStencilProperty::GetStencilMask() const {
   return stencilMask;
}

void NiStencilProperty::SetStencilMask(unsigned int value) {
   stencilMask = value;
}

StencilAction NiStencilProperty::GetFailAction() const {
   return failAction;
}

void NiStencilProperty::SetFailAction(StencilAction value) {
   failAction = value;
}

StencilAction NiStencilProperty::GetZFailAction() const {
   return zFailAction;
}

void NiStencilProperty::SetZFailAction(StencilAction value) {
   zFailAction = value;
}

StencilAction NiStencilProperty::GetPassAction() const {
   return passAction;
}

void NiStencilProperty::SetPassAction(StencilAction value) {
   passAction = value;
}

FaceDrawMode NiStencilProperty::GetFaceDrawMode() const {
   return drawMode;
}

void NiStencilProperty::SetFaceDrawMode(FaceDrawMode value) {
   drawMode = value;
}

//--END CUSTOM CODE--//
