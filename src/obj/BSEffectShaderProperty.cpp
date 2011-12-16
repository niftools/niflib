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
#include "../../include/obj/BSEffectShaderProperty.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSEffectShaderProperty::TYPE("BSEffectShaderProperty", &NiProperty::TYPE );

BSEffectShaderProperty::BSEffectShaderProperty() : unknownByte1((byte)0), unknownShort1((unsigned short)0), unknownByte2((byte)0), unknownInt1((unsigned int)0), unknownShort2((unsigned short)0), effectShaderFlags((SkyrimEffectShaderFlags)0), unknownFloat1(0.0f), unknownFloat2(0.0f), unknownFloat3(0.0f), unknownFloat4(0.0f), emissiveSaturation(0.0f), emissiveStrength(0.0f), unknownFloat5(0.0f) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

BSEffectShaderProperty::~BSEffectShaderProperty() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & BSEffectShaderProperty::GetType() const {
	return TYPE;
}

NiObject * BSEffectShaderProperty::Create() {
	return new BSEffectShaderProperty;
}

void BSEffectShaderProperty::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiProperty::Read( in, link_stack, info );
	NifStream( unknownByte1, in, info );
	NifStream( unknownShort1, in, info );
	NifStream( unknownByte2, in, info );
	NifStream( unknownInt1, in, info );
	NifStream( textureTranslation1, in, info );
	NifStream( textureTranslation2, in, info );
	NifStream( sourceTexture, in, info );
	NifStream( unknownShort2, in, info );
	NifStream( effectShaderFlags, in, info );
	NifStream( unknownFloat1, in, info );
	NifStream( unknownFloat2, in, info );
	NifStream( unknownFloat3, in, info );
	NifStream( unknownFloat4, in, info );
	NifStream( emissiveColor, in, info );
	NifStream( emissiveSaturation, in, info );
	NifStream( emissiveStrength, in, info );
	NifStream( unknownFloat5, in, info );
	NifStream( gradientTexture, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSEffectShaderProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiProperty::Write( out, link_map, missing_link_stack, info );
	NifStream( unknownByte1, out, info );
	NifStream( unknownShort1, out, info );
	NifStream( unknownByte2, out, info );
	NifStream( unknownInt1, out, info );
	NifStream( textureTranslation1, out, info );
	NifStream( textureTranslation2, out, info );
	NifStream( sourceTexture, out, info );
	NifStream( unknownShort2, out, info );
	NifStream( effectShaderFlags, out, info );
	NifStream( unknownFloat1, out, info );
	NifStream( unknownFloat2, out, info );
	NifStream( unknownFloat3, out, info );
	NifStream( unknownFloat4, out, info );
	NifStream( emissiveColor, out, info );
	NifStream( emissiveSaturation, out, info );
	NifStream( emissiveStrength, out, info );
	NifStream( unknownFloat5, out, info );
	NifStream( gradientTexture, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string BSEffectShaderProperty::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	out << NiProperty::asString();
	out << "  Unknown Byte 1:  " << unknownByte1 << endl;
	out << "  Unknown Short 1:  " << unknownShort1 << endl;
	out << "  Unknown Byte 2:  " << unknownByte2 << endl;
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	out << "  Texture Translation 1:  " << textureTranslation1 << endl;
	out << "  Texture Translation 2:  " << textureTranslation2 << endl;
	out << "  Source Texture:  " << sourceTexture << endl;
	out << "  Unknown Short 2:  " << unknownShort2 << endl;
	out << "  Effect Shader Flags:  " << effectShaderFlags << endl;
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Unknown Float 2:  " << unknownFloat2 << endl;
	out << "  Unknown Float 3:  " << unknownFloat3 << endl;
	out << "  Unknown Float 4:  " << unknownFloat4 << endl;
	out << "  Emissive Color:  " << emissiveColor << endl;
	out << "  Emissive Saturation:  " << emissiveSaturation << endl;
	out << "  Emissive Strength:  " << emissiveStrength << endl;
	out << "  Unknown Float 5:  " << unknownFloat5 << endl;
	out << "  Gradient Texture:  " << gradientTexture << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSEffectShaderProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiProperty::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> BSEffectShaderProperty::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	return refs;
}

std::list<NiObject *> BSEffectShaderProperty::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiProperty::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
