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
#include "../../include/obj/BSLightingShaderProperty.h"
#include "../../include/obj/BSShaderTextureSet.h"
#include "../../include/obj/NiExtraData.h"
#include "../../include/obj/NiTimeController.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSLightingShaderProperty::TYPE("BSLightingShaderProperty", &NiProperty::TYPE );

BSLightingShaderProperty::BSLightingShaderProperty() : shaderType((unsigned int)0), extraData(NULL), numExtraDataList((unsigned int)0), controller(NULL), shaderFlags1((SkyrimLightingShaderFlags1)0), shaderFlags2((SkyrimLightingShaderFlags2)0), textureSet(NULL), emissiveSaturation(0.0f), unknownInt7((unsigned int)0), transparency(0.0f), unknownFloat2(0.0f), glossiness(0.0f), specularStrength(0.0f), lightingEffect1(0.0f), lightingEffect2(0.0f), environmentMapStrength(0.0f), unknownFloat9(0.0f), eyeCubemapScale(0.0f) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

BSLightingShaderProperty::~BSLightingShaderProperty() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & BSLightingShaderProperty::GetType() const {
	return TYPE;
}

NiObject * BSLightingShaderProperty::Create() {
	return new BSLightingShaderProperty;
}

void BSLightingShaderProperty::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiProperty::Read( in, link_stack, info );
	if ( ( info.version >= 0x14020007 ) && ( (info.userVersion == 12) ) ) {
		NifStream( shaderType, in, info );
	};
	NifStream( name, in, info );
	if ( ( info.version >= 0x03000000 ) && ( info.version <= 0x04020200 ) ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	if ( info.version >= 0x0A000100 ) {
		NifStream( numExtraDataList, in, info );
		extraDataList.resize(numExtraDataList);
		for (unsigned int i2 = 0; i2 < extraDataList.size(); i2++) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
	};
	if ( info.version >= 0x03000000 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	if ( (info.userVersion == 12) ) {
		NifStream( shaderFlags1, in, info );
		NifStream( shaderFlags2, in, info );
	};
	NifStream( textureTranslation1, in, info );
	NifStream( textureTranslation2, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( emissiveColor, in, info );
	NifStream( emissiveSaturation, in, info );
	NifStream( unknownInt7, in, info );
	NifStream( transparency, in, info );
	NifStream( unknownFloat2, in, info );
	NifStream( glossiness, in, info );
	NifStream( specularColor, in, info );
	NifStream( specularStrength, in, info );
	NifStream( lightingEffect1, in, info );
	NifStream( lightingEffect2, in, info );
	if ( (shaderType == 1) ) {
		NifStream( environmentMapStrength, in, info );
	};
	if ( (shaderType == 5) ) {
		NifStream( unknownFloatSet1, in, info );
	};
	if ( (shaderType == 6) ) {
		NifStream( unknownColor1, in, info );
	};
	if ( (shaderType == 7) ) {
		for (unsigned int i2 = 0; i2 < 2; i2++) {
			NifStream( unknownFloatSet3[i2], in, info );
		};
	};
	if ( (shaderType == 11) ) {
		NifStream( unknownFloat9, in, info );
		NifStream( unknownColor2, in, info );
	};
	if ( (shaderType == 14) ) {
		NifStream( unknownFloatSet5, in, info );
	};
	if ( (shaderType == 16) ) {
		NifStream( eyeCubemapScale, in, info );
		NifStream( leftEyeReflectionCenter, in, info );
		NifStream( rightEyeReflectionCenter, in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSLightingShaderProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiProperty::Write( out, link_map, missing_link_stack, info );
	numExtraDataList = (unsigned int)(extraDataList.size());
	if ( ( info.version >= 0x14020007 ) && ( (info.userVersion == 12) ) ) {
		NifStream( shaderType, out, info );
	};
	NifStream( name, out, info );
	if ( ( info.version >= 0x03000000 ) && ( info.version <= 0x04020200 ) ) {
		if ( info.version < VER_3_3_0_13 ) {
			WritePtr32( &(*extraData), out );
		} else {
			if ( extraData != NULL ) {
				map<NiObjectRef,unsigned int>::const_iterator it = link_map.find( StaticCast<NiObject>(extraData) );
				if (it != link_map.end()) {
					NifStream( it->second, out, info );
					missing_link_stack.push_back( NULL );
				} else {
					NifStream( 0xFFFFFFFF, out, info );
					missing_link_stack.push_back( extraData );
				}
			} else {
				NifStream( 0xFFFFFFFF, out, info );
				missing_link_stack.push_back( NULL );
			}
		}
	};
	if ( info.version >= 0x0A000100 ) {
		NifStream( numExtraDataList, out, info );
		for (unsigned int i2 = 0; i2 < extraDataList.size(); i2++) {
			if ( info.version < VER_3_3_0_13 ) {
				WritePtr32( &(*extraDataList[i2]), out );
			} else {
				if ( extraDataList[i2] != NULL ) {
					map<NiObjectRef,unsigned int>::const_iterator it = link_map.find( StaticCast<NiObject>(extraDataList[i2]) );
					if (it != link_map.end()) {
						NifStream( it->second, out, info );
						missing_link_stack.push_back( NULL );
					} else {
						NifStream( 0xFFFFFFFF, out, info );
						missing_link_stack.push_back( extraDataList[i2] );
					}
				} else {
					NifStream( 0xFFFFFFFF, out, info );
					missing_link_stack.push_back( NULL );
				}
			}
		};
	};
	if ( info.version >= 0x03000000 ) {
		if ( info.version < VER_3_3_0_13 ) {
			WritePtr32( &(*controller), out );
		} else {
			if ( controller != NULL ) {
				map<NiObjectRef,unsigned int>::const_iterator it = link_map.find( StaticCast<NiObject>(controller) );
				if (it != link_map.end()) {
					NifStream( it->second, out, info );
					missing_link_stack.push_back( NULL );
				} else {
					NifStream( 0xFFFFFFFF, out, info );
					missing_link_stack.push_back( controller );
				}
			} else {
				NifStream( 0xFFFFFFFF, out, info );
				missing_link_stack.push_back( NULL );
			}
		}
	};
	if ( (info.userVersion == 12) ) {
		NifStream( shaderFlags1, out, info );
		NifStream( shaderFlags2, out, info );
	};
	NifStream( textureTranslation1, out, info );
	NifStream( textureTranslation2, out, info );
	if ( info.version < VER_3_3_0_13 ) {
		WritePtr32( &(*textureSet), out );
	} else {
		if ( textureSet != NULL ) {
			map<NiObjectRef,unsigned int>::const_iterator it = link_map.find( StaticCast<NiObject>(textureSet) );
			if (it != link_map.end()) {
				NifStream( it->second, out, info );
				missing_link_stack.push_back( NULL );
			} else {
				NifStream( 0xFFFFFFFF, out, info );
				missing_link_stack.push_back( textureSet );
			}
		} else {
			NifStream( 0xFFFFFFFF, out, info );
			missing_link_stack.push_back( NULL );
		}
	}
	NifStream( emissiveColor, out, info );
	NifStream( emissiveSaturation, out, info );
	NifStream( unknownInt7, out, info );
	NifStream( transparency, out, info );
	NifStream( unknownFloat2, out, info );
	NifStream( glossiness, out, info );
	NifStream( specularColor, out, info );
	NifStream( specularStrength, out, info );
	NifStream( lightingEffect1, out, info );
	NifStream( lightingEffect2, out, info );
	if ( (shaderType == 1) ) {
		NifStream( environmentMapStrength, out, info );
	};
	if ( (shaderType == 5) ) {
		NifStream( unknownFloatSet1, out, info );
	};
	if ( (shaderType == 6) ) {
		NifStream( unknownColor1, out, info );
	};
	if ( (shaderType == 7) ) {
		for (unsigned int i2 = 0; i2 < 2; i2++) {
			NifStream( unknownFloatSet3[i2], out, info );
		};
	};
	if ( (shaderType == 11) ) {
		NifStream( unknownFloat9, out, info );
		NifStream( unknownColor2, out, info );
	};
	if ( (shaderType == 14) ) {
		NifStream( unknownFloatSet5, out, info );
	};
	if ( (shaderType == 16) ) {
		NifStream( eyeCubemapScale, out, info );
		NifStream( leftEyeReflectionCenter, out, info );
		NifStream( rightEyeReflectionCenter, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string BSLightingShaderProperty::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiProperty::asString();
	numExtraDataList = (unsigned int)(extraDataList.size());
	out << "  Shader Type:  " << shaderType << endl;
	out << "  Name:  " << name << endl;
	out << "  Extra Data:  " << extraData << endl;
	out << "  Num Extra Data List:  " << numExtraDataList << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < extraDataList.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Extra Data List[" << i1 << "]:  " << extraDataList[i1] << endl;
		array_output_count++;
	};
	out << "  Controller:  " << controller << endl;
	out << "  Shader Flags 1:  " << shaderFlags1 << endl;
	out << "  Shader Flags 2:  " << shaderFlags2 << endl;
	out << "  Texture Translation 1:  " << textureTranslation1 << endl;
	out << "  Texture Translation 2:  " << textureTranslation2 << endl;
	out << "  Texture Set:  " << textureSet << endl;
	out << "  Emissive Color:  " << emissiveColor << endl;
	out << "  Emissive Saturation:  " << emissiveSaturation << endl;
	out << "  Unknown Int 7:  " << unknownInt7 << endl;
	out << "  Transparency:  " << transparency << endl;
	out << "  Unknown Float 2:  " << unknownFloat2 << endl;
	out << "  Glossiness:  " << glossiness << endl;
	out << "  Specular Color:  " << specularColor << endl;
	out << "  Specular Strength:  " << specularStrength << endl;
	out << "  Lighting Effect 1:  " << lightingEffect1 << endl;
	out << "  Lighting Effect 2:  " << lightingEffect2 << endl;
	if ( (shaderType == 1) ) {
		out << "    Environment Map Strength:  " << environmentMapStrength << endl;
	};
	if ( (shaderType == 5) ) {
		out << "    Unknown Float Set 1:  " << unknownFloatSet1 << endl;
	};
	if ( (shaderType == 6) ) {
		out << "    Unknown Color 1:  " << unknownColor1 << endl;
	};
	if ( (shaderType == 7) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < 2; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Float Set 3[" << i2 << "]:  " << unknownFloatSet3[i2] << endl;
			array_output_count++;
		};
	};
	if ( (shaderType == 11) ) {
		out << "    Unknown Float 9:  " << unknownFloat9 << endl;
		out << "    Unknown Color 2:  " << unknownColor2 << endl;
	};
	if ( (shaderType == 14) ) {
		out << "    Unknown Float Set 5:  " << unknownFloatSet5 << endl;
	};
	if ( (shaderType == 16) ) {
		out << "    Eye Cubemap Scale:  " << eyeCubemapScale << endl;
		out << "    Left Eye Reflection Center:  " << leftEyeReflectionCenter << endl;
		out << "    Right Eye Reflection Center:  " << rightEyeReflectionCenter << endl;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSLightingShaderProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiProperty::FixLinks( objects, link_stack, missing_link_stack, info );
	if ( ( info.version >= 0x03000000 ) && ( info.version <= 0x04020200 ) ) {
		extraData = FixLink<NiExtraData>( objects, link_stack, missing_link_stack, info );
	};
	if ( info.version >= 0x0A000100 ) {
		for (unsigned int i2 = 0; i2 < extraDataList.size(); i2++) {
			extraDataList[i2] = FixLink<NiExtraData>( objects, link_stack, missing_link_stack, info );
		};
	};
	if ( info.version >= 0x03000000 ) {
		controller = FixLink<NiTimeController>( objects, link_stack, missing_link_stack, info );
	};
	textureSet = FixLink<BSShaderTextureSet>( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> BSLightingShaderProperty::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	if ( extraData != NULL )
		refs.push_back(StaticCast<NiObject>(extraData));
	for (unsigned int i1 = 0; i1 < extraDataList.size(); i1++) {
		if ( extraDataList[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(extraDataList[i1]));
	};
	if ( controller != NULL )
		refs.push_back(StaticCast<NiObject>(controller));
	if ( textureSet != NULL )
		refs.push_back(StaticCast<NiObject>(textureSet));
	return refs;
}

std::list<NiObject *> BSLightingShaderProperty::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiProperty::GetPtrs();
	for (unsigned int i1 = 0; i1 < extraDataList.size(); i1++) {
	};
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
