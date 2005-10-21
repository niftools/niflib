/* Copyright (c) 2005, NIF File Format Library and Tools
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above
     copyright notice, this list of conditions and the following
     disclaimer in the documentation and/or other materials provided
     with the distribution.

   * Neither the name of the NIF File Format Library and Tools
     project nor the names of its contributors may be used to endorse
     or promote products derived from this software without specific
     prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE. */

#ifndef NIF_MATH_H
#define NIF_MATH_H

#include <cmath>
#include <iostream>
#include "niflib.h"
#include "NIF_IO.h"
using namespace std;

//struct Quat {
//	float w, x, y, z;
//};

void QuatToMatrix( Quaternion & quat, ostream & out );
void QuatToEuler( Quaternion & quat, ostream & out );
Vector3 MultVector3( Vector3 & a, Vector3 & b);
Matrix33 MultMatrix33( Matrix33 & a, Matrix33 & b );
Matrix44 MultMatrix44( Matrix44 & a, Matrix44 & b );
float DetMatrix33( Matrix33 & m );
float DetMatrix44( Matrix44 & m );
float AdjMatrix44( Matrix44 & m, int r, int c );
Matrix44 InverseMatrix44( Matrix44 & m );
void SetIdentity33( Matrix33 & m );
void SetIdentity44( Matrix44 & m );
void PrintMatrix33( Matrix33 & m, ostream & out );
Quaternion MatrixToQuat( Matrix33 & m );

#endif