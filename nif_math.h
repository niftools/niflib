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

struct Quat {
	float w, x, y, z;
};

void QuatToMatrix( fVector4 quat, ostream & out );
void QuatToEuler( fVector4 quat, ostream & out );
void PrintMatrix( float m[3], ostream & out );
void MultVect3( fVector3 u, fVector3 v, fVector3 answer );
void MultMatrix33( float a[9], float b[9], float answer[9] );
void MultMatrix44( float a[4][4], float b[4][4], float result[4][4] );
float DetMatrix33( float a[3][3] );
float DetMatrix44( float a[4][4] );
float AdjMatrix44(float a[4][4], int m, int n);
void InverseMatrix44( float a[4][4], float result[4][4] );
void SetIdentity33( float m[3][3] );
void SetIdentity44( float m[4][4] );
void PrintMatrix( float m[9], ostream & out );
Quat MatrixToQuat( matrix m );

#endif