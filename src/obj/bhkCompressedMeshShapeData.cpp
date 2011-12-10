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
#include "../../include/obj/bhkCompressedMeshShapeData.h"
#include "../../include/gen/bhkCMSD_Something.h"
#include "../../include/gen/bhkCMSDData.h"
#include "../../include/gen/bhkCMSDData.h"
#include "../../include/gen/bhkCMSD_Shape.h"
#include "../../include/gen/bhkCMSDContainer.h"
#include "../../include/gen/bhkCMSD_Shape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkCompressedMeshShapeData::TYPE("bhkCompressedMeshShapeData", &NiObject::TYPE );

bhkCompressedMeshShapeData::bhkCompressedMeshShapeData() : unknownInt1((unsigned int)0), unknownInt2((unsigned int)0), unknownShort1((unsigned short)0), unknownShort2((unsigned short)0), unknownShort3((unsigned short)0), unknownShort4((unsigned short)0), unknownFloat1(0.0f), unknownByte1((byte)0), unknownInt3((unsigned int)0), unknownInt4((unsigned int)0), unknownInt5((unsigned int)0), unknownByte2((byte)0), somethingCount((unsigned int)0), unknownInt6((unsigned int)0), numDataSet((unsigned int)0), unknownInt7((unsigned int)0), unknownInt8((unsigned int)0), unknownInt9((unsigned int)0), unknownFloat2(0.0f), numVertices((unsigned int)0), numBytes2((unsigned int)0), numSubshapes((unsigned int)0), unknownInt10((unsigned int)0), unknownInt11((unsigned int)0), unknownFloat3(0.0f), unknownInt12((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

bhkCompressedMeshShapeData::~bhkCompressedMeshShapeData() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & bhkCompressedMeshShapeData::GetType() const {
	return TYPE;
}

NiObject * bhkCompressedMeshShapeData::Create() {
	return new bhkCompressedMeshShapeData;
}

void bhkCompressedMeshShapeData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::Read( in, link_stack, info );
	NifStream( unknownInt1, in, info );
	NifStream( unknownInt2, in, info );
	NifStream( unknownShort1, in, info );
	NifStream( unknownShort2, in, info );
	NifStream( unknownShort3, in, info );
	NifStream( unknownShort4, in, info );
	NifStream( unknownFloat1, in, info );
	NifStream( unknownFloats1, in, info );
	NifStream( unknownFloats2, in, info );
	NifStream( unknownByte1, in, info );
	NifStream( unknownInt3, in, info );
	NifStream( unknownInt4, in, info );
	NifStream( unknownInt5, in, info );
	NifStream( unknownByte2, in, info );
	NifStream( somethingCount, in, info );
	unknownIntSomething.resize(somethingCount);
	for (unsigned int i1 = 0; i1 < unknownIntSomething.size(); i1++) {
		NifStream( unknownIntSomething[i1].largeInt, in, info );
		NifStream( unknownIntSomething[i1].unknownInteger, in, info );
	};
	NifStream( unknownInt6, in, info );
	NifStream( numDataSet, in, info );
	NifStream( unknownInt7, in, info );
	NifStream( unknownInt8, in, info );
	NifStream( unknownInt9, in, info );
	if ( (numDataSet >= 1) ) {
		dataSet1.resize(numDataSet);
		for (unsigned int i2 = 0; i2 < dataSet1.size(); i2++) {
			NifStream( dataSet1[i2].unknownFloats1, in, info );
			NifStream( dataSet1[i2].unknownInt1, in, info );
		};
	};
	if ( (numDataSet >= 2) ) {
		dataSet2.resize((numDataSet - 1));
		for (unsigned int i2 = 0; i2 < dataSet2.size(); i2++) {
			NifStream( dataSet2[i2].unknownFloats1, in, info );
			NifStream( dataSet2[i2].unknownInt1, in, info );
		};
	};
	NifStream( unknownFloat2, in, info );
	NifStream( numVertices, in, info );
	if ( (numVertices >= 1) ) {
		vertices.resize(numVertices);
		for (unsigned int i2 = 0; i2 < vertices.size(); i2++) {
			NifStream( vertices[i2], in, info );
		};
	};
	NifStream( numBytes2, in, info );
	if ( (numBytes2 >= 1) ) {
		unknownBytes.resize(numBytes2);
		for (unsigned int i2 = 0; i2 < unknownBytes.size(); i2++) {
			for (unsigned int i3 = 0; i3 < 12; i3++) {
				NifStream( unknownBytes[i2][i3], in, info );
			};
		};
	};
	NifStream( numSubshapes, in, info );
	if ( (numSubshapes >= 1) ) {
		NifStream( unknownFloats3, in, info );
		NifStream( unknownInt10, in, info );
		NifStream( unknownInt11, in, info );
		NifStream( unknownFloat3, in, info );
		for (unsigned int i2 = 0; i2 < 4; i2++) {
			NifStream( shapeSet1[i2].numShape, in, info );
			if ( (shapeSet1[i2].numShape >= 1) ) {
				shapeSet1[i2].shape.resize(shapeSet1[i2].numShape);
				for (unsigned int i4 = 0; i4 < shapeSet1[i2].shape.size(); i4++) {
					NifStream( shapeSet1[i2].shape[i4], in, info );
				};
			};
		};
		shapeSet2.resize((numSubshapes - 1));
		for (unsigned int i2 = 0; i2 < shapeSet2.size(); i2++) {
			NifStream( shapeSet2[i2].unknownFloats, in, info );
			NifStream( shapeSet2[i2].unknownInt, in, info );
			NifStream( shapeSet2[i2].unknownShort1, in, info );
			NifStream( shapeSet2[i2].unknownShort2, in, info );
			for (unsigned int i3 = 0; i3 < 4; i3++) {
				NifStream( shapeSet2[i2].shape[i3].numShape, in, info );
				if ( (shapeSet2[i2].shape[i3].numShape >= 1) ) {
					shapeSet2[i2].shape[i3].shape.resize(shapeSet2[i2].shape[i3].numShape);
					for (unsigned int i5 = 0; i5 < shapeSet2[i2].shape[i3].shape.size(); i5++) {
						NifStream( shapeSet2[i2].shape[i3].shape[i5], in, info );
					};
				};
			};
		};
	};
	NifStream( unknownInt12, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void bhkCompressedMeshShapeData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, missing_link_stack, info );
	numSubshapes = (unsigned int)(shapeSet2.size());
	numBytes2 = (unsigned int)(unknownBytes.size());
	numVertices = (unsigned int)(vertices.size());
	numDataSet = (unsigned int)(dataSet1.size());
	somethingCount = (unsigned int)(unknownIntSomething.size());
	NifStream( unknownInt1, out, info );
	NifStream( unknownInt2, out, info );
	NifStream( unknownShort1, out, info );
	NifStream( unknownShort2, out, info );
	NifStream( unknownShort3, out, info );
	NifStream( unknownShort4, out, info );
	NifStream( unknownFloat1, out, info );
	NifStream( unknownFloats1, out, info );
	NifStream( unknownFloats2, out, info );
	NifStream( unknownByte1, out, info );
	NifStream( unknownInt3, out, info );
	NifStream( unknownInt4, out, info );
	NifStream( unknownInt5, out, info );
	NifStream( unknownByte2, out, info );
	NifStream( somethingCount, out, info );
	for (unsigned int i1 = 0; i1 < unknownIntSomething.size(); i1++) {
		NifStream( unknownIntSomething[i1].largeInt, out, info );
		NifStream( unknownIntSomething[i1].unknownInteger, out, info );
	};
	NifStream( unknownInt6, out, info );
	NifStream( numDataSet, out, info );
	NifStream( unknownInt7, out, info );
	NifStream( unknownInt8, out, info );
	NifStream( unknownInt9, out, info );
	if ( (numDataSet >= 1) ) {
		for (unsigned int i2 = 0; i2 < dataSet1.size(); i2++) {
			NifStream( dataSet1[i2].unknownFloats1, out, info );
			NifStream( dataSet1[i2].unknownInt1, out, info );
		};
	};
	if ( (numDataSet >= 2) ) {
		for (unsigned int i2 = 0; i2 < dataSet2.size(); i2++) {
			NifStream( dataSet2[i2].unknownFloats1, out, info );
			NifStream( dataSet2[i2].unknownInt1, out, info );
		};
	};
	NifStream( unknownFloat2, out, info );
	NifStream( numVertices, out, info );
	if ( (numVertices >= 1) ) {
		for (unsigned int i2 = 0; i2 < vertices.size(); i2++) {
			NifStream( vertices[i2], out, info );
		};
	};
	NifStream( numBytes2, out, info );
	if ( (numBytes2 >= 1) ) {
		for (unsigned int i2 = 0; i2 < unknownBytes.size(); i2++) {
			for (unsigned int i3 = 0; i3 < 12; i3++) {
				NifStream( unknownBytes[i2][i3], out, info );
			};
		};
	};
	NifStream( numSubshapes, out, info );
	if ( (numSubshapes >= 1) ) {
		NifStream( unknownFloats3, out, info );
		NifStream( unknownInt10, out, info );
		NifStream( unknownInt11, out, info );
		NifStream( unknownFloat3, out, info );
		for (unsigned int i2 = 0; i2 < 4; i2++) {
			shapeSet1[i2].numShape = (unsigned int)(shapeSet1[i2].shape.size());
			NifStream( shapeSet1[i2].numShape, out, info );
			if ( (shapeSet1[i2].numShape >= 1) ) {
				for (unsigned int i4 = 0; i4 < shapeSet1[i2].shape.size(); i4++) {
					NifStream( shapeSet1[i2].shape[i4], out, info );
				};
			};
		};
		for (unsigned int i2 = 0; i2 < shapeSet2.size(); i2++) {
			NifStream( shapeSet2[i2].unknownFloats, out, info );
			NifStream( shapeSet2[i2].unknownInt, out, info );
			NifStream( shapeSet2[i2].unknownShort1, out, info );
			NifStream( shapeSet2[i2].unknownShort2, out, info );
			for (unsigned int i3 = 0; i3 < 4; i3++) {
				shapeSet2[i2].shape[i3].numShape = (unsigned int)(shapeSet2[i2].shape[i3].shape.size());
				NifStream( shapeSet2[i2].shape[i3].numShape, out, info );
				if ( (shapeSet2[i2].shape[i3].numShape >= 1) ) {
					for (unsigned int i5 = 0; i5 < shapeSet2[i2].shape[i3].shape.size(); i5++) {
						NifStream( shapeSet2[i2].shape[i3].shape[i5], out, info );
					};
				};
			};
		};
	};
	NifStream( unknownInt12, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string bhkCompressedMeshShapeData::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	numSubshapes = (unsigned int)(shapeSet2.size());
	numBytes2 = (unsigned int)(unknownBytes.size());
	numVertices = (unsigned int)(vertices.size());
	numDataSet = (unsigned int)(dataSet1.size());
	somethingCount = (unsigned int)(unknownIntSomething.size());
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	out << "  Unknown Short 1:  " << unknownShort1 << endl;
	out << "  Unknown Short 2:  " << unknownShort2 << endl;
	out << "  Unknown Short 3:  " << unknownShort3 << endl;
	out << "  Unknown Short 4:  " << unknownShort4 << endl;
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Unknown Floats 1:  " << unknownFloats1 << endl;
	out << "  Unknown Floats 2:  " << unknownFloats2 << endl;
	out << "  Unknown Byte 1:  " << unknownByte1 << endl;
	out << "  Unknown Int 3:  " << unknownInt3 << endl;
	out << "  Unknown Int 4:  " << unknownInt4 << endl;
	out << "  Unknown Int 5:  " << unknownInt5 << endl;
	out << "  Unknown Byte 2:  " << unknownByte2 << endl;
	out << "  Something Count:  " << somethingCount << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < unknownIntSomething.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Large Int:  " << unknownIntSomething[i1].largeInt << endl;
		out << "    Unknown Integer:  " << unknownIntSomething[i1].unknownInteger << endl;
	};
	out << "  Unknown Int 6:  " << unknownInt6 << endl;
	out << "  Num Data Set:  " << numDataSet << endl;
	out << "  Unknown Int 7:  " << unknownInt7 << endl;
	out << "  Unknown Int 8:  " << unknownInt8 << endl;
	out << "  Unknown Int 9:  " << unknownInt9 << endl;
	if ( (numDataSet >= 1) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < dataSet1.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Unknown Floats 1:  " << dataSet1[i2].unknownFloats1 << endl;
			out << "      Unknown Int 1:  " << dataSet1[i2].unknownInt1 << endl;
		};
	};
	if ( (numDataSet >= 2) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < dataSet2.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Unknown Floats 1:  " << dataSet2[i2].unknownFloats1 << endl;
			out << "      Unknown Int 1:  " << dataSet2[i2].unknownInt1 << endl;
		};
	};
	out << "  Unknown Float 2:  " << unknownFloat2 << endl;
	out << "  Num Vertices:  " << numVertices << endl;
	if ( (numVertices >= 1) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < vertices.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Vertices[" << i2 << "]:  " << vertices[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Num Bytes 2:  " << numBytes2 << endl;
	if ( (numBytes2 >= 1) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < unknownBytes.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			for (unsigned int i3 = 0; i3 < 12; i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					break;
				};
				out << "        Unknown Bytes[" << i3 << "]:  " << unknownBytes[i2][i3] << endl;
				array_output_count++;
			};
		};
	};
	out << "  Num Subshapes:  " << numSubshapes << endl;
	if ( (numSubshapes >= 1) ) {
		out << "    Unknown Floats 3:  " << unknownFloats3 << endl;
		out << "    Unknown Int 10:  " << unknownInt10 << endl;
		out << "    Unknown Int 11:  " << unknownInt11 << endl;
		out << "    Unknown Float 3:  " << unknownFloat3 << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < 4; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			shapeSet1[i2].numShape = (unsigned int)(shapeSet1[i2].shape.size());
			out << "      Num Shape:  " << shapeSet1[i2].numShape << endl;
			if ( (shapeSet1[i2].numShape >= 1) ) {
				array_output_count = 0;
				for (unsigned int i4 = 0; i4 < shapeSet1[i2].shape.size(); i4++) {
					if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
						out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
						break;
					};
					if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
						break;
					};
					out << "          Shape[" << i4 << "]:  " << shapeSet1[i2].shape[i4] << endl;
					array_output_count++;
				};
			};
		};
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < shapeSet2.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Unknown Floats:  " << shapeSet2[i2].unknownFloats << endl;
			out << "      Unknown Int:  " << shapeSet2[i2].unknownInt << endl;
			out << "      Unknown Short 1:  " << shapeSet2[i2].unknownShort1 << endl;
			out << "      Unknown Short 2:  " << shapeSet2[i2].unknownShort2 << endl;
			array_output_count = 0;
			for (unsigned int i3 = 0; i3 < 4; i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
					break;
				};
				shapeSet2[i2].shape[i3].numShape = (unsigned int)(shapeSet2[i2].shape[i3].shape.size());
				out << "        Num Shape:  " << shapeSet2[i2].shape[i3].numShape << endl;
				if ( (shapeSet2[i2].shape[i3].numShape >= 1) ) {
					array_output_count = 0;
					for (unsigned int i5 = 0; i5 < shapeSet2[i2].shape[i3].shape.size(); i5++) {
						if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
							out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
							break;
						};
						if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
							break;
						};
						out << "            Shape[" << i5 << "]:  " << shapeSet2[i2].shape[i3].shape[i5] << endl;
						array_output_count++;
					};
				};
			};
		};
	};
	out << "  Unknown Int 12:  " << unknownInt12 << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void bhkCompressedMeshShapeData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> bhkCompressedMeshShapeData::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

std::list<NiObject *> bhkCompressedMeshShapeData::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiObject::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
