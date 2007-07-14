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
#include "../../include/obj/NiBSplineData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBSplineData::TYPE("NiBSplineData", &NiObject::TYPE );

NiBSplineData::NiBSplineData() : floatCount((unsigned int)0), shortCount((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiBSplineData::~NiBSplineData() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiBSplineData::GetType() const {
	return TYPE;
}

NiObject * NiBSplineData::Create() {
	return new NiBSplineData;
}

void NiBSplineData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::Read( in, link_stack, info );
	NifStream( floatCount, in, info );
	floatControlPoints.resize(floatCount);
	for (unsigned int i1 = 0; i1 < floatControlPoints.size(); i1++) {
		NifStream( floatControlPoints[i1], in, info );
	};
	NifStream( shortCount, in, info );
	shortControlPoints.resize(shortCount);
	for (unsigned int i1 = 0; i1 < shortControlPoints.size(); i1++) {
		NifStream( shortControlPoints[i1], in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiBSplineData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, info );
	shortCount = (unsigned int)(shortControlPoints.size());
	floatCount = (unsigned int)(floatControlPoints.size());
	NifStream( floatCount, out, info );
	for (unsigned int i1 = 0; i1 < floatControlPoints.size(); i1++) {
		NifStream( floatControlPoints[i1], out, info );
	};
	NifStream( shortCount, out, info );
	for (unsigned int i1 = 0; i1 < shortControlPoints.size(); i1++) {
		NifStream( shortControlPoints[i1], out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiBSplineData::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	shortCount = (unsigned int)(shortControlPoints.size());
	floatCount = (unsigned int)(floatControlPoints.size());
	out << "  Float Count:  " << floatCount << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < floatControlPoints.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Float Control Points[" << i1 << "]:  " << floatControlPoints[i1] << endl;
		array_output_count++;
	};
	out << "  Short Count:  " << shortCount << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < shortControlPoints.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Short Control Points[" << i1 << "]:  " << shortControlPoints[i1] << endl;
		array_output_count++;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiBSplineData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiBSplineData::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

vector<float> NiBSplineData::GetFloatControlPoints() const 
{
	return floatControlPoints;
}

vector<float> NiBSplineData::GetFloatControlPointRange(int offset, int count) const
{
	vector<float> value;
	if (offset < 0 || count < 0 || ((offset + count) > int(floatControlPoints.size())))
		throw runtime_error("Invalid offset or count.");
	vector<float>::const_iterator srcbeg = floatControlPoints.begin(), srcend = floatControlPoints.begin(); 
	std::advance(srcbeg, offset);
	std::advance(srcend, offset + count);
	return vector<float>(srcbeg, srcend);
}

vector<short > NiBSplineData::GetShortControlPoints() const 
{
	return shortControlPoints;
}

vector<short > NiBSplineData::GetShortControlPointRange(int offset, int count) const
{
   vector<short> value;
   if (offset < 0 || count < 0 || ((offset + count) > int(shortControlPoints.size())))
      throw runtime_error("Invalid offset or count.");
   vector<short>::const_iterator srcbeg = shortControlPoints.begin(), srcend = shortControlPoints.begin(); 
   std::advance(srcbeg, offset);
   std::advance(srcend, offset + count);
   return vector<short>(srcbeg, srcend);
}

//--END CUSTOM CODE--//
