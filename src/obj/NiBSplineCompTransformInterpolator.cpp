/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

//--BEGIN FILE HEAD CUSTOM CODE--//
#include "../../include/obj/NiBSplineBasisData.h"
#include "../../include/obj/NiBSplineData.h"

static const int SizeofQuat = 4;
static const int SizeofTrans = 3;
static const int SizeofScale = 1;

//--END CUSTOM CODE--//

#include "../../include/FixLink.h"
#include "../../include/ObjectRegistry.h"
#include "../../include/NIF_IO.h"
#include "../../include/obj/NiBSplineCompTransformInterpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBSplineCompTransformInterpolator::TYPE("NiBSplineCompTransformInterpolator", &NiBSplineTransformInterpolator::TYPE );

NiBSplineCompTransformInterpolator::NiBSplineCompTransformInterpolator() : scale(0.0f), translateOffset((unsigned int)0), rotateOffset((unsigned int)0), scaleOffset((unsigned int)0), translateBias(0.0f), translateMultiplier(0.0f), rotationBias(0.0f), rotationMultiplier(0.0f), scaleBias(0.0f), scaleMultiplier(0.0f) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiBSplineCompTransformInterpolator::~NiBSplineCompTransformInterpolator() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiBSplineCompTransformInterpolator::GetType() const {
	return TYPE;
}

namespace Niflib {
	typedef NiObject*(*obj_factory_func)();
	extern map<string, obj_factory_func> global_object_map;

	//Initialization function
	static bool Initialization();

	//A static bool to force the initialization to happen pre-main
	static bool obj_initialized = Initialization();

	static bool Initialization() {
		//Register this object type with Niflib
		ObjectRegistry::RegisterObject( "NiBSplineCompTransformInterpolator", NiBSplineCompTransformInterpolator::Create );

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiBSplineCompTransformInterpolator::Create() {
	return new NiBSplineCompTransformInterpolator;
}

void NiBSplineCompTransformInterpolator::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiBSplineTransformInterpolator::Read( in, link_stack, info );
	NifStream( translation, in, info );
	NifStream( rotation, in, info );
	NifStream( scale, in, info );
	NifStream( translateOffset, in, info );
	NifStream( rotateOffset, in, info );
	NifStream( scaleOffset, in, info );
	NifStream( translateBias, in, info );
	NifStream( translateMultiplier, in, info );
	NifStream( rotationBias, in, info );
	NifStream( rotationMultiplier, in, info );
	NifStream( scaleBias, in, info );
	NifStream( scaleMultiplier, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiBSplineCompTransformInterpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiBSplineTransformInterpolator::Write( out, link_map, info );
	NifStream( translation, out, info );
	NifStream( rotation, out, info );
	NifStream( scale, out, info );
	NifStream( translateOffset, out, info );
	NifStream( rotateOffset, out, info );
	NifStream( scaleOffset, out, info );
	NifStream( translateBias, out, info );
	NifStream( translateMultiplier, out, info );
	NifStream( rotationBias, out, info );
	NifStream( rotationMultiplier, out, info );
	NifStream( scaleBias, out, info );
	NifStream( scaleMultiplier, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiBSplineCompTransformInterpolator::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiBSplineTransformInterpolator::asString();
	out << "  Translation:  " << translation << endl;
	out << "  Rotation:  " << rotation << endl;
	out << "  Scale:  " << scale << endl;
	out << "  Translate Offset:  " << translateOffset << endl;
	out << "  Rotate Offset:  " << rotateOffset << endl;
	out << "  Scale Offset:  " << scaleOffset << endl;
	out << "  Translate Bias:  " << translateBias << endl;
	out << "  Translate Multiplier:  " << translateMultiplier << endl;
	out << "  Rotation Bias:  " << rotationBias << endl;
	out << "  Rotation Multiplier:  " << rotationMultiplier << endl;
	out << "  Scale Bias:  " << scaleBias << endl;
	out << "  Scale Multiplier:  " << scaleMultiplier << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiBSplineCompTransformInterpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiBSplineTransformInterpolator::FixLinks( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiBSplineCompTransformInterpolator::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiBSplineTransformInterpolator::GetRefs();
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

Vector3 NiBSplineCompTransformInterpolator::GetTranslation() const {
	return translation;
}

void NiBSplineCompTransformInterpolator::SetTranslation( Vector3 value ) {
	translation = value;
}

Quaternion NiBSplineCompTransformInterpolator::GetRotation() const {
	return rotation;
}

void NiBSplineCompTransformInterpolator::SetRotation( Quaternion value ) {
	rotation = value;
}

float NiBSplineCompTransformInterpolator::GetScale() const {
	return scale;
}

void NiBSplineCompTransformInterpolator::SetScale( float value ) {
	scale = value;
}

float NiBSplineCompTransformInterpolator::GetTranslateBias() const {
	return translateBias;
}

void NiBSplineCompTransformInterpolator::SetTranslateBias( float value ) {
	translateBias = value;
}

float NiBSplineCompTransformInterpolator::GetTranslateMultiplier() const {
	return translateMultiplier;
}

void NiBSplineCompTransformInterpolator::SetTranslateMultiplier( float value ) {
	translateMultiplier = value;
}

float NiBSplineCompTransformInterpolator::GetRotationBias() const {
	return rotationBias;
}

void NiBSplineCompTransformInterpolator::SetRotationBias( float value ) {
	rotationBias = value;
}

float NiBSplineCompTransformInterpolator::GetRotationMultiplier() const {
	return rotationMultiplier;
}

void NiBSplineCompTransformInterpolator::SetRotationMultiplier( float value ) {
	rotationMultiplier = value;
}

float NiBSplineCompTransformInterpolator::GetScaleBias() const {
	return scaleBias;
}

void NiBSplineCompTransformInterpolator::SetScaleBias( float value ) {
	scaleBias = value;
}

float NiBSplineCompTransformInterpolator::GetScaleMultiplier() const {
	return scaleMultiplier;
}

void NiBSplineCompTransformInterpolator::SetScaleMultiplier( float value ) {
	scaleMultiplier = value;
}

vector< Quaternion > NiBSplineCompTransformInterpolator::GetQuatRotateControlData() const
{
   vector< Quaternion > value;
   if ((rotateOffset != USHRT_MAX) && splineData && basisData) { // has rotation data
      int nctrl = basisData->GetNumControlPt();
      int npts = nctrl * SizeofQuat;
      vector<short> points = splineData->GetControlPointRange(rotateOffset, npts);
      value.reserve(nctrl);
      for (int i=0; i<npts; ) {
         Quaternion key;
         key.w = float(points[i++]) / float (32767) * rotationMultiplier + rotationBias;
         key.x = float(points[i++]) / float (32767) * rotationMultiplier + rotationBias;
         key.y = float(points[i++]) / float (32767) * rotationMultiplier + rotationBias;
         key.z = float(points[i++]) / float (32767) * rotationMultiplier + rotationBias;
         value.push_back(key);
      }
   }
   return value;
}

vector< Vector3 > NiBSplineCompTransformInterpolator::GetTranslateControlData() const
{
   vector< Vector3 > value;
   if ((translateOffset != USHRT_MAX) && splineData && basisData) { // has translation data
      int nctrl = basisData->GetNumControlPt();
      int npts = nctrl * SizeofTrans;
      vector<short> points = splineData->GetControlPointRange(translateOffset, npts);
      value.reserve(nctrl);
      for (int i=0; i<npts; ) {
         Vector3 key;
         key.x = float(points[i++]) / float (32767) * translateMultiplier + translateBias;
         key.y = float(points[i++]) / float (32767) * translateMultiplier + translateBias;
         key.z = float(points[i++]) / float (32767) * translateMultiplier + translateBias;
         value.push_back(key);
      }
   }
   return value;
}

vector< float > NiBSplineCompTransformInterpolator::GetScaleControlData() const
{
   vector< float > value;
   if ((scaleOffset != USHRT_MAX) && splineData && basisData) { // has translation data
      int nctrl = basisData->GetNumControlPt();
      int npts = nctrl * SizeofScale;
      vector<short> points = splineData->GetControlPointRange(scaleOffset, npts);
      value.reserve(nctrl);
      for (int i=0; i<npts; ) {
         float data = float(points[i++]) / float (32767) * scaleMultiplier + scaleBias;
         value.push_back(data);
      }
   }
   return value;
}

vector< Key<Quaternion> > NiBSplineCompTransformInterpolator::SampleQuatRotateKeys(int npoints, int degree) const
{
   vector< Key<Quaternion> > value;
   if ((rotateOffset != USHRT_MAX) && splineData && basisData) { // has rotation data
      int nctrl = basisData->GetNumControlPt();
      int npts = nctrl * SizeofQuat;
      vector<short> points = splineData->GetControlPointRange(rotateOffset, npts);
      vector<float> control(npts);
      vector<float> output(npoints*SizeofQuat);
      for (int i=0, j=0; i<nctrl; ++i) {
         for (int k=0; k<SizeofQuat; ++k)
            control[i*SizeofQuat + k] = float(points[j++]) / float (32767);
      }
      if (degree>=nctrl)
         degree = nctrl - 1;
      // fit data
      bspline(nctrl-1, degree+1, SizeofQuat, &control[0], &output[0], npoints);

      // copy to key
      float time = GetStartTime();
      float incr = (GetStopTime() - GetStartTime()) / float(npoints) ;
      value.reserve(npoints);
      for (int i=0, j=0; i<npoints; i++) {
         Key<Quaternion> key;
         key.time = time;
         key.backward_tangent.Set(1.0f,0.0f,0.0f,0.0f);
         key.forward_tangent.Set(1.0f,0.0f,0.0f,0.0f); 
         key.data.w = output[j++] * rotationMultiplier + rotationBias;
         key.data.x = output[j++] * rotationMultiplier + rotationBias;
         key.data.y = output[j++] * rotationMultiplier + rotationBias;
         key.data.z = output[j++] * rotationMultiplier + rotationBias;
         value.push_back(key);
         time += incr;
      }
   }
   return value;
}

vector< Key<Vector3> > NiBSplineCompTransformInterpolator::SampleTranslateKeys(int npoints, int degree) const
{
   vector< Key<Vector3> > value;
   if ((translateOffset != USHRT_MAX) && splineData && basisData) { // has rotation data
      int nctrl = basisData->GetNumControlPt();
      int npts = nctrl * SizeofTrans;
      vector<short> points = splineData->GetControlPointRange(translateOffset, npts);
      vector<float> control(npts);
      vector<float> output(npoints*SizeofTrans);
      for (int i=0, j=0; i<nctrl; ++i) {
         for (int k=0; k<SizeofTrans; ++k)
            control[i*SizeofTrans + k] = float(points[j++]) / float (32767);
      }
      // fit data
      bspline(nctrl-1, degree+1, SizeofTrans, &control[0], &output[0], npoints);

      // copy to key
      float time = GetStartTime();
      float incr = (GetStopTime() - GetStartTime()) / float(npoints) ;
      value.reserve(npoints);
      for (int i=0, j=0; i<npoints; i++) {
         Key<Vector3> key;
         key.time = time;
         key.backward_tangent.Set(0.0f,0.0f,0.0f);
         key.forward_tangent.Set(0.0f,0.0f,0.0f); 
         key.data.x = output[j++] * translateMultiplier + translateBias;
         key.data.y = output[j++] * translateMultiplier + translateBias;
         key.data.z = output[j++] * translateMultiplier + translateBias;
         value.push_back(key);
         time += incr;
      }
   }
   return value;
}

vector< Key<float> > NiBSplineCompTransformInterpolator::SampleScaleKeys(int npoints, int degree) const
{
   vector< Key<float> > value;
   if ((scaleOffset != USHRT_MAX) && splineData && basisData) // has rotation data
   {
      int nctrl = basisData->GetNumControlPt();
      int npts = nctrl * SizeofScale;
      vector<short> points = splineData->GetControlPointRange(scaleOffset, npts);
      vector<float> control(npts);
      vector<float> output(npoints*SizeofScale);
      for (int i=0, j=0; i<nctrl; ++i) {
         control[i] = float(points[j++]) / float (32767);
      }
      // fit data
      bspline(nctrl-1, degree+1, SizeofScale, &control[0], &output[0], npoints);

      // copy to key
      float time = GetStartTime();
      float incr = (GetStopTime() - GetStartTime()) / float(npoints) ;
      value.reserve(npoints);
      for (int i=0, j=0; i<npoints; i++) {
         Key<float> key;
         key.time = time;
         key.backward_tangent = 0.0f;
         key.forward_tangent = 0.0f; 
         key.data = output[j++] * scaleMultiplier + scaleBias;
         value.push_back(key);
         time += incr;
      }
   }
   return value;
}

int NiBSplineCompTransformInterpolator::GetNumControlPt() const
{
   if (basisData)
   {
      return basisData->GetNumControlPt();
   }
   return 0;
}

//--END CUSTOM CODE--//
