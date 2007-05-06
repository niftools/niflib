/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiBSplineCompTransformInterpolator.h"
#include "../../include/obj/NiBSplineBasisData.h"
#include "../../include/obj/NiBSplineData.h"
using namespace Niflib;

static const int SizeofQuat = 4;
static const int SizeofTrans = 3;
static const int SizeofScale = 1;

//Definition of TYPE constant
const Type NiBSplineCompTransformInterpolator::TYPE("NiBSplineCompTransformInterpolator", &NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_PARENT::TYPE );

NiBSplineCompTransformInterpolator::NiBSplineCompTransformInterpolator() NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_CONSTRUCT {}

NiBSplineCompTransformInterpolator::~NiBSplineCompTransformInterpolator() {}

void NiBSplineCompTransformInterpolator::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiBSplineCompTransformInterpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiBSplineCompTransformInterpolator::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBSplineCompTransformInterpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiBSplineCompTransformInterpolator::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBSplineCompTransformInterpolator::GetType() const {
	return TYPE;
};

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

namespace Niflib { 
	typedef NiObject*(*obj_factory_func)();
	extern map<string, obj_factory_func> global_object_map;

	//Initialization function
	static bool Initialization();

	//A static bool to force the initialization to happen pre-main
	static bool obj_initialized = Initialization();

	static bool Initialization() {
		//Add the function to the global object map
		global_object_map["NiBSplineCompTransformInterpolator"] = NiBSplineCompTransformInterpolator::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiBSplineCompTransformInterpolator::Create() {
	return new NiBSplineCompTransformInterpolator;
}
