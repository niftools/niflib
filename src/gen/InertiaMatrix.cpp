/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#include "../../include/gen/InertiaMatrix.h"
using namespace Niflib;

//Constructor
InertiaMatrix::InertiaMatrix() : m11(0.0f), m12(0.0f), m13(0.0f), m14(0.0f), m21(0.0f), m22(0.0f), m23(0.0f), m24(0.0f), m31(0.0f), m32(0.0f), m33(0.0f), m34(0.0f) {};

//Copy Constructor
InertiaMatrix::InertiaMatrix( const InertiaMatrix & src ) {
	*this = src;
};

//Copy Operator
InertiaMatrix & InertiaMatrix::operator=( const InertiaMatrix & src ) {
	this->m11 = src.m11;
	this->m12 = src.m12;
	this->m13 = src.m13;
	this->m14 = src.m14;
	this->m21 = src.m21;
	this->m22 = src.m22;
	this->m23 = src.m23;
	this->m24 = src.m24;
	this->m31 = src.m31;
	this->m32 = src.m32;
	this->m33 = src.m33;
	this->m34 = src.m34;
	return *this;
};

//Destructor
InertiaMatrix::~InertiaMatrix() {};
