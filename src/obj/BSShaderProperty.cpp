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
#include "../../include/obj/BSShaderProperty.h"
#include "../../include/obj/NiExtraData.h"
#include "../../include/obj/NiTimeController.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSShaderProperty::TYPE("BSShaderProperty", &NiObject::TYPE );

BSShaderProperty::BSShaderProperty() : unknownFlag((unsigned int)0), extraData(NULL), numExtraDataList((unsigned int)0), controller(NULL), flags((unsigned short)1), shaderType((BSShaderType)SHADER_DEFAULT), shaderFlags((BSShaderFlags)0x82000000), unknownShort1((unsigned short)0), unknownInt2((int)1), envmapScale(1.0f) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

BSShaderProperty::~BSShaderProperty() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & BSShaderProperty::GetType() const {
	return TYPE;
}

NiObject * BSShaderProperty::Create() {
	return new BSShaderProperty;
}

void BSShaderProperty::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	if ( ( info.version >= 0x14020007 ) && ( (info.userVersion == 12) ) ) {
		NifStream( unknownFlag, in, info );
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
	NifStream( flags, in, info );
	NifStream( shaderType, in, info );
	NifStream( shaderFlags, in, info );
	if ( (info.userVersion == 12) ) {
		NifStream( unknownShort1, in, info );
	};
	NifStream( unknownInt2, in, info );
	NifStream( envmapScale, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSShaderProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, missing_link_stack, info );
	numExtraDataList = (unsigned int)(extraDataList.size());
	if ( ( info.version >= 0x14020007 ) && ( (info.userVersion == 12) ) ) {
		NifStream( unknownFlag, out, info );
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
	NifStream( flags, out, info );
	NifStream( shaderType, out, info );
	NifStream( shaderFlags, out, info );
	if ( (info.userVersion == 12) ) {
		NifStream( unknownShort1, out, info );
	};
	NifStream( unknownInt2, out, info );
	NifStream( envmapScale, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string BSShaderProperty::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	numExtraDataList = (unsigned int)(extraDataList.size());
	out << "  Unknown Flag:  " << unknownFlag << endl;
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
	out << "  Flags:  " << flags << endl;
	out << "  Shader Type:  " << shaderType << endl;
	out << "  Shader Flags:  " << shaderFlags << endl;
	out << "  Unknown Short 1:  " << unknownShort1 << endl;
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	out << "  Envmap Scale:  " << envmapScale << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSShaderProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, missing_link_stack, info );
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

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> BSShaderProperty::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( extraData != NULL )
		refs.push_back(StaticCast<NiObject>(extraData));
	for (unsigned int i1 = 0; i1 < extraDataList.size(); i1++) {
		if ( extraDataList[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(extraDataList[i1]));
	};
	if ( controller != NULL )
		refs.push_back(StaticCast<NiObject>(controller));
	return refs;
}

std::list<NiObject *> BSShaderProperty::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiObject::GetPtrs();
	for (unsigned int i1 = 0; i1 < extraDataList.size(); i1++) {
	};
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

unsigned short BSShaderProperty::GetFlags() const {
   return flags;
}

void BSShaderProperty::SetFlags( unsigned short value ) {
   flags = value;
}

BSShaderType BSShaderProperty::GetShaderType() const {
   return shaderType;
}

void BSShaderProperty::SetShaderType( const BSShaderType & value ) {
   shaderType = value;
}

BSShaderFlags BSShaderProperty::GetShaderFlags() const {
   return shaderFlags;
}

void BSShaderProperty::SetShaderFlags( const BSShaderFlags & value ) {
   shaderFlags = value;
}

float BSShaderProperty::GetEnvmapScale() const {
   return envmapScale;
}

void BSShaderProperty::SetEnvmapScale( float value ) {
   envmapScale = value;
}

//--END CUSTOM CODE--//
