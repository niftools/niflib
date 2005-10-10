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
void PrintMatrix( float m[9], ostream & out );
void MultVect3( fVector3 u, fVector3 v, fVector3 answer );
void MultMatrix33( float a[9], float b[9], float answer[9] );
void MultMatrix44( float a[4][4], float b[4][4], float result[4][4] );
float DetMatrix33( float a[3][3] );
float DetMatrix44( float a[4][4] );
float AdjMatrix44(float a[4][4], int m, int n);
void InverseMatrix44( float a[4][4], float result[4][4] );
void SetIdentity33( float m[9] );
void SetIdentity44( float m[4][4] );
void PrintMatrix( float m[9], ostream & out );
Quat MatrixToQuat( matrix m );

#endif