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
#include "../../include/obj/NiLight.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiLight::TYPE("NiLight", &NiDynamicEffect::TYPE );

NiLight::NiLight() : dimmer(0.0f) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiLight::~NiLight() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiLight::GetType() const {
	return TYPE;
}

//A static bool to force the initialization to happen pre-main
bool NiLight::obj_initialized = NiLight::Register();

bool NiLight::Register() {
	//Register this object type with Niflib
	ObjectRegistry::RegisterObject( "NiLight", NiLight::Create );

	//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
	obj_initialized = true;
	return obj_initialized;
}

NiObject * NiLight::Create() {
	return new NiLight;
}

void NiLight::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiDynamicEffect::Read( in, link_stack, info );
	NifStream( dimmer, in, info );
	NifStream( ambientColor, in, info );
	NifStream( diffuseColor, in, info );
	NifStream( specularColor, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiLight::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiDynamicEffect::Write( out, link_map, info );
	NifStream( dimmer, out, info );
	NifStream( ambientColor, out, info );
	NifStream( diffuseColor, out, info );
	NifStream( specularColor, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiLight::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiDynamicEffect::asString();
	out << "  Dimmer:  " << dimmer << endl;
	out << "  Ambient Color:  " << ambientColor << endl;
	out << "  Diffuse Color:  " << diffuseColor << endl;
	out << "  Specular Color:  " << specularColor << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiLight::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiDynamicEffect::FixLinks( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiLight::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiDynamicEffect::GetRefs();
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

float NiLight::GetDimmer() const {
	return dimmer;
}

void NiLight::SetDimmer( float value ) {
	dimmer = value;
}

Color3 NiLight::GetAmbientColor() const {
	return ambientColor;
}

void NiLight::SetAmbientColor( Color3 value ) {
	ambientColor = value;
}

Color3 NiLight::GetDiffuseColor() const {
	return diffuseColor;
}

void NiLight::SetDiffuseColor( Color3 value ) {
	diffuseColor = value;
}

Color3 NiLight::GetSpecularColor() const {
	return specularColor;
}

void NiLight::SetSpecularColor( Color3 value ) {
	specularColor = value;
}

//--END CUSTOM CODE--//
