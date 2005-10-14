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

#include "nif_math.h"

void PrintMatrix( float m[9], ostream & out ) {
	out << endl
		<< "      |" << setw(8) << m[0] << "," << setw(8) << m[1] << "," << setw(8) << m[2] << " |" << endl
		<< "      |" << setw(8) << m[3] << "," << setw(8) << m[4] << "," << setw(8) << m[5] << " |" << endl
		<< "      |" << setw(8) << m[6] << "," << setw(8) << m[7] << "," << setw(8) << m[8] << " |" <<endl;
}

void MultVect3( fVector3 u, fVector3 v, fVector3 answer ) {
	answer[0] = u[1] * v[2] - u[2] * v[1];
	answer[1] = u[2] * v[0] - u[0] * v[2];
	answer[2] = u[0] * v[1] - u[1] * v[0];
}

void SetIdentity33( float m[3][3] ) {
	m[0][0] = 1.0f;	m[0][1] = 0.0f;	m[0][2] = 0.0f;
	m[1][0] = 0.0f;	m[1][1] = 1.0f;	m[1][2] = 0.0f;
	m[2][0] = 0.0f;	m[2][1] = 0.0f;	m[2][2] = 1.0f;
}

void SetIdentity44( float m[4][4] ) {
	m[0][0] = 1.0f;	m[0][1] = 0.0f;	m[0][2] = 0.0f;	m[0][3] = 0.0f;
	m[1][0] = 0.0f;	m[1][1] = 1.0f;	m[1][2] = 0.0f;	m[1][3] = 0.0f;
	m[2][0] = 0.0f;	m[2][1] = 0.0f;	m[2][2] = 1.0f;	m[2][3] = 0.0f;
	m[3][0] = 0.0f;	m[3][1] = 0.0f;	m[3][2] = 0.0f;	m[3][3] = 1.0f;
}

void MatrixToEuler( float m[9], fVector3 answer ) {




}

Quat MatrixToQuat( matrix m ) {
	Quat quat;
	float tr, s, q[4];
	int i, j, k;

	int nxt[3] = {1, 2, 0};

	// compute the trace of the matrix
	tr = m[0][0] + m[1][1] + m[2][2];

	// check if the trace is positive or negative
	if (tr > 0.0) {
		s = sqrt (tr + 1.0f);
		quat.w = s / 2.0f;
		s = 0.5f / s;
		quat.x = (m[1][2] - m[2][1]) * s;
		quat.y = (m[2][0] - m[0][2]) * s;
		quat.z = (m[0][1] - m[1][0]) * s;
	}
	else {
		// trace is negative
		i = 0;
		if ( m[1][1] > m[0][0])
			i = 1;
		if ( m[2][2] > m[i][i] )
			i = 2;
		j = nxt[i];
		k = nxt[j];

		s = sqrt( ( m[i][i] - (m[j][j] + m[k][k]) ) + 1.0f );
		q[i] = s * 0.5f;
		if (s != 0.0f) s = 0.5f / s;
		q[3] = (m[j][k] - m[k][j]) * s;
		q[j] = (m[i][j] + m[j][i]) * s;
		q[k] = (m[i][k] + m[k][i]) * s;
		quat.x = q[0];
		quat.y= q[1];
		quat.z = q[2];
		quat.w = q[3];
	}

	return quat;
}

void MultMatrix33( float a[9], float b[9], float answer[9] ) {
	for (int c = 0; c < 3; ++c) {
		for (int r = 0; r < 3; ++r) {
			float t = 0.0f;
			for (int i = 0; i < 3; ++i) {
				t += a[c * 3 + i] * b[i * 3 + r];
			}
			answer[c * 3 + r] = t;
		}
	}
}

void MultMatrix44( float a[4][4], float b[4][4], float result[4][4] ) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			//result[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j];
			float t = 0.0f;
			for (int k = 0; k < 4; k++) {
				t += a[i][k] * b[k][j];
			}
			result[i][j] = t;
		}
	}
}

float DetMatrix33( float a[3][3] ) {
	return  a[0][0]*(a[1][1]*a[2][2]-a[1][2]*a[2][1])
		  - a[0][1]*(a[1][0]*a[2][2]-a[1][2]*a[2][0])
		  + a[0][2]*(a[1][0]*a[2][1]-a[1][1]*a[2][0]);
}

float DetMatrix44( float a[4][4] ) {
	float sub1[3][3] = {
		a[1][1], a[1][2], a[1][3],
		a[2][1], a[2][2], a[2][3],
		a[3][1], a[3][2], a[3][3]
	};

	float sub2[3][3] = {
		a[1][0], a[1][2], a[1][3],
		a[2][0], a[2][2], a[2][3],
		a[3][0], a[3][2], a[3][3]
	};

	float sub3[3][3] = {
		a[1][0], a[1][1], a[1][3],
		a[2][0], a[2][1], a[2][3],
		a[3][0], a[3][1], a[3][3] 
	};

	float sub4[3][3] = {
		a[1][0], a[1][1], a[1][2],
		a[2][0], a[2][1], a[2][2],
		a[3][0], a[3][1], a[3][2]
	};

	return  a[0][0] * DetMatrix33( sub1 )
	      - a[0][1] * DetMatrix33( sub2 )
	      + a[0][2] * DetMatrix33( sub3 )
	      - a[0][3] * DetMatrix33( sub4 );
}

float AdjMatrix44(float a[4][4], int m, int n) {
	float sub[3][3];
	int i = 0, j = 0;
	for (int r = 0; r < 4; r++) {
		if (r == n)
			continue;
		for (int c = 0; c < 4; c++) {
			if (c == m)
				continue;
			sub[i][j] = a[r][c];
			j++;
		}
		i++;
		j = 0;
	}

	return pow(-1.0f, float(m + n)) * DetMatrix33( sub );
}

void InverseMatrix44( float a[4][4], float result[4][4] ) {
	float det = DetMatrix44(a);
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			result[r][c] = AdjMatrix44(a, r, c) / det;
		}
	}
}

void QuatToMatrix( fVector4 quat, ostream & out ) {
	float m[3][3]; // Matrix

	float w = quat[0];
	float x = quat[1];
	float y = quat[2];
	float z = quat[3];

	float w2 = w * w;
	float x2 = x * x;
	float y2 = y * y;
	float z2 = z * z;

	m[0][0] = w2 + x2- y2 - z2;
	m[0][1] = 2.0f*x*y - 2.0f*w*z;
	m[0][2] = 2.0f*x*z + 2.0f*w*y;
	
	m[1][0] = 2.0f*x*y + 2.0f*w*z;
	m[1][1] = w2 - x2 + y*y - z2;
	m[1][2] = 2.0f*y*z - 2.0f*w*x;
	
	m[2][0] = 2.0f*x*z - 2.0f*w*y;
	m[2][1] = 2.0f*y*z + 2.0f*w*x;
	m[2][2] = w2 - x2 - y2 + z2;

	out << endl
		<< "         |" << setw(8) << m[0][0] << "," << setw(8) << m[0][1] << "," << setw(8) << m[0][2] << " |" << endl
		<< "         |" << setw(8) << m[1][0] << "," << setw(8) << m[1][1] << "," << setw(8) << m[1][2] << " |" << endl
		<< "         |" << setw(8) << m[2][0] << "," << setw(8) << m[2][1] << "," << setw(8) << m[2][2] << " |" << endl;

	float pi = 3.141592653589793f;
	out << "      Euler Angles:" << endl
		<< "         X:  " << atan2( m[1][2], m[2][2] ) / pi * 180.0 << endl
		<< "         Y:  " << asin( -m[0][2] ) / pi * 180.0 << endl
		<< "         Z:  " << atan2( m[0][1], m[0][0] ) / pi * 180.0 << endl;
}

void QuatToEuler( fVector4 quat, ostream & out ) {
	float w = quat[0];
	float x = quat[1];
	float y = quat[2];
	float z = quat[3];

//heading = atan2(2*qy*qw-2*qx*qz , 1 - 2*qy2 - 2*qz2)
//attitude = asin(2*qx*qy + 2*qz*qw)
//bank = atan2(2*qx*qw-2*qy*qz , 1 - 2*qx2 - 2*qz2)
//
//except when qx*qy + qz*qw = 0.5 (north pole)
//which gives:
//heading = 2 * atan2(x,w)
//bank = 0
//and when qx*qy + qz*qw = -0.5 (south pole)
//which gives:
//heading = -2 * atan2(x,w)
//bank = 0 

	float h, a, b;
	float pi = 3.141592653589793f;

	if ( x*y + z*w == 0.5 ) {
		//North Pole
		h = 2 * atan2(x,w);
		a = asin(2*x*y + 2*z*w);
		b = 0.0f;
	}
	else if ( x*y + z*w == -0.5 ) {
		//South Pole
		h =  -2 * atan2(x,w);
		a = asin(2*x*y + 2*z*w);
		b = 0.0f;
	}
	else {
		h = atan2(2*y*w-2*x*z , 1 - 2*y*y - 2*z*z);
		a = asin(2*x*y + 2*z*w);
		b = atan2(2*x*w-2*y*z , 1 - 2*x*x - 2*z*z);
	}

	h = h / pi * 180;
	a = a / pi * 180;
	b = b / pi * 180;

	out << endl
		<< "         Heading:  " << h << endl
		<< "         Attitude:  " << a << endl
		<< "         Bank:  " << b << endl;
	
}