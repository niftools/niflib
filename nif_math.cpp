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

void PrintMatrix( Matrix33 const & m, ostream & out ) {
	out << endl
		<< "      |" << setw(8) << m[0][0] << "," << setw(8) << m[0][1] << "," << setw(8) << m[0][2] << " |" << endl
		<< "      |" << setw(8) << m[1][0] << "," << setw(8) << m[1][1] << "," << setw(8) << m[1][2] << " |" << endl
		<< "      |" << setw(8) << m[2][0] << "," << setw(8) << m[2][1] << "," << setw(8) << m[2][2] << " |" <<endl;
}

Vector3 MultVector3( Vector3 const & a, Vector3 const & b ) {
	Vector3 answer;
	answer.x = a.y * b.z - a.z * b.y;
	answer.y = a.z * b.x - a.x * b.z;
	answer.z = a.x * b.y - a.y * b.x;

	return answer;
}

void SetIdentity33( Matrix33 & m ) {
	m[0][0] = 1.0f;	m[0][1] = 0.0f;	m[0][2] = 0.0f;
	m[1][0] = 0.0f;	m[1][1] = 1.0f;	m[1][2] = 0.0f;
	m[2][0] = 0.0f;	m[2][1] = 0.0f;	m[2][2] = 1.0f;
}

void SetIdentity44( Matrix44 & m ) {
	m[0][0] = 1.0f;	m[0][1] = 0.0f;	m[0][2] = 0.0f;	m[0][3] = 0.0f;
	m[1][0] = 0.0f;	m[1][1] = 1.0f;	m[1][2] = 0.0f;	m[1][3] = 0.0f;
	m[2][0] = 0.0f;	m[2][1] = 0.0f;	m[2][2] = 1.0f;	m[2][3] = 0.0f;
	m[3][0] = 0.0f;	m[3][1] = 0.0f;	m[3][2] = 0.0f;	m[3][3] = 1.0f;
}

//Vector3 MatrixToEuler( Matrix33 & m ) {}

Quaternion MatrixToQuat( Matrix33 const & m ) {
	Quaternion quat;
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

Matrix33 MultMatrix33( Matrix33 const & a, Matrix33 const & b ) {
	Matrix33 result;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			float t = 0.0f;
			for (int k = 0; k < 4; k++) {
				t += a[i][k] * b[k][j];
			}
			result[i][j] = t;
		}
	}
	return result;
}

Matrix44 MultMatrix44( Matrix44 const & a, Matrix44 const & b ) {
	Matrix44 result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			float t = 0.0f;
			for (int k = 0; k < 4; k++) {
				t += a[i][k] * b[k][j];
			}
			result[i][j] = t;
		}
	}
	return result;
}

float DetMatrix33( Matrix33 const & m ) {
	return  m[0][0]*(m[1][1]*m[2][2]-m[1][2]*m[2][1])
		  - m[0][1]*(m[1][0]*m[2][2]-m[1][2]*m[2][0])
		  + m[0][2]*(m[1][0]*m[2][1]-m[1][1]*m[2][0]);
}

float DetMatrix44( Matrix44 const & m ) {
	Matrix33 sub1(
		m[1][1], m[1][2], m[1][3],
		m[2][1], m[2][2], m[2][3],
		m[3][1], m[3][2], m[3][3]
	);

	Matrix33 sub2(
		m[1][0], m[1][2], m[1][3],
		m[2][0], m[2][2], m[2][3],
		m[3][0], m[3][2], m[3][3]
	);

	Matrix33 sub3(
		m[1][0], m[1][1], m[1][3],
		m[2][0], m[2][1], m[2][3],
		m[3][0], m[3][1], m[3][3] 
	);

	Matrix33 sub4(
		m[1][0], m[1][1], m[1][2],
		m[2][0], m[2][1], m[2][2],
		m[3][0], m[3][1], m[3][2]
	);

	return  m[0][0] * DetMatrix33( sub1 )
	      - m[0][1] * DetMatrix33( sub2 )
	      + m[0][2] * DetMatrix33( sub3 )
	      - m[0][3] * DetMatrix33( sub4 );
}

float AdjMatrix44(Matrix44 const & m, int skip_r, int skip_c) {
	Matrix33 sub;
	int i = 0, j = 0;
	for (int r = 0; r < 4; r++) {
		if (r == skip_c)
			continue;
		for (int c = 0; c < 4; c++) {
			if (c == skip_r)
				continue;
			sub[i][j] = m[r][c];
			j++;
		}
		i++;
		j = 0;
	}

	return pow(-1.0f, float(skip_r + skip_c)) * DetMatrix33( sub );
}

Matrix44 InverseMatrix44( Matrix44 const & m ) {
	Matrix44 result;
	float det = DetMatrix44(m);
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			result[r][c] = AdjMatrix44(m, r, c) / det;
		}
	}
	return result;
}

void QuatToMatrix( Quaternion const & quat, ostream & out ) {
	Matrix33 m;

	float w = quat.w;
	float x = quat.x;
	float y = quat.y;
	float z = quat.z;

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

void QuatToEuler( Quaternion const & quat, ostream & out ) {
	float w = quat.w;
	float x = quat.x;
	float y = quat.y;
	float z = quat.z;

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
