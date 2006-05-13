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
//#include "NIF_IO.h"
using namespace std;

#ifndef PI
#define PI 3.14159265358979323846f
#endif

//Forward declarations
struct TexCoord;
struct Triangle;
struct Vector3;
struct Color4;
struct Quaternion;
struct Float2;
struct Matrix22;
struct Float3;
struct Matrix33;
struct Float4;
struct Matrix44;

/*! Stores 2D texture coordinates – two floating point variables, u and v. */
struct TexCoord {
	float u; /*!< The U value in this coordinate pair. */ 
	float v; /*!< The V value in this coordinate pair. */ 

	/*! Default constructor	*/
	TexCoord() {}

	/*! This constructor can be used to set all values in this structure during initialization
	 * \param u The value to set U to.
	 * \param v The value to set V to.
	 */
	TexCoord(float u, float v) {
		this->u = u;
		this->v = v;
	}

	/*! This function can be used to set all values in the structure at the same time.
	 * \param u The value to set U to.
	 * \param v The value to set V to.
	 */
	void Set(float u, float v) {
		this->u = u;
		this->v = v;
	}
};

/*! Represents a triangle face formed between three vertices referenced by number */
struct Triangle {
	short v1; /*!< The index of the first vertex. */ 
	short v2; /*!< The index of the second vertex. */ 
	short v3; /*!< The index of the third vertex. */ 

	/*! Default constructor */
	Triangle() {}

	/*! This constructor can be used to set all values in this structure during initialization
	 * \param v1 The index of the first vertex.
	 * \param v2 The index of the second vertex.
	 * \param v3 The index of the third vertex.
	 */
	Triangle(short v1, short v2, short v3) {
		this->v1 = v1;
		this->v2 = v2;
		this->v3 = v3;
	}

	/*! This function can be used to set all values in the structure at the same time.
	 * \param v1 The index of the first vertex.
	 * \param v2 The index of the second vertex.
	 * \param v3 The index of the third vertex.
	 */
	void Set(short v1, short v2, short v3) {
		this->v1 = v1;
		this->v2 = v2;
		this->v3 = v3;
	}

	/*! The bracket operator makes it possible to use this structure like a C++ array.
	 * \param n The index into the data array.  Should be 0, 1, or 2.
	 * \return The value at the given array index by reference so it can be read or set via the bracket operator.
	 */
	short & operator[](int n) {
		switch (n) {
			case 0: return v1; break;
			case 1: return v2; break;
			case 2: return v3; break;
			default: throw std::out_of_range("Index out of range for Triangle");
		};
	}
	short operator[](int n) const {
		switch (n) {
			case 0: return v1; break;
			case 1: return v2; break;
			case 2: return v3; break;
			default: throw std::out_of_range("Index out of range for Triangle");
		};
	}
};

/*!Represents a position or direction in 3D space*/
struct Vector3 {
	float x; /*!< The X component of this vector. */ 
	float y; /*!< The Y component of this vector. */ 
	float z; /*!< The Z component of this vector. */ 

	/*!Default constructor.*/
	Vector3() { x = y = z = 0.0f; }

	/*! This constructor can be used to set all values in this structure during initialization
	 * \param x The value to set X to.
	 * \param y The value to set Y to.
	 * \param z The value to set Z to.
	 */
	Vector3(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	/*! This constructor can be used to initialize this Vector3 with another Vector3
	 * \param v The Vector3 to construct this one from
	 */
	Vector3( const Vector3 & v) { x = v.x; y = v.y; z = v.z; }
	
	/*! Destructor */
	~Vector3() {}

	/*! This function can be used to set all values in the structure at the same time.
	 * \param x The value to set X to.
	 * \param y The value to set Y to.
	 * \param z The value to set Z to.
	 */
	void Set(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	/* This function calculates the magnitude of this vector
	 * \return the magnitude of the vector; its length.
	 */
	float Magnitude() const;

	/* This function returns a normalization of this vector.  A vecctor pointing in the same
	 * direction but with a magnitude, or length, of 1.
	 */
	Vector3 Normalized() const;

	/* Allows the addition of vectors.  Each component, x, y, y, is added with
	 * the same component of the other vector.
	 * \return The result of the addition.
	 */
	Vector3 operator+( const Vector3 & rh ) const;

	/* Adds the two vectors and then sets the result to the left-hand vector.
	 * \return This vector is returned.
	 */
	Vector3 & operator+=( const Vector3 & rh );

	/* Allows the subtraction of vectors.  Each component, x, y, y, is subtracted from
	 * the same component of the other vector.
	 * \return The result of the subtraction.
	 */
	Vector3 operator-( const Vector3 & rh ) const;

	/* This operator subtracts the two vectors and then sets the result to the left-hand vector.
	 * \return This vector is returned.
	 */
	Vector3 & operator-=( const Vector3 & rh);

	/* Allows scaler multiplication, that is multipying all components of the
	 * vector, x, y and z, by the same number.
	 * \return The result of the multiplication.
	 */
	Vector3 operator*( const float & rh) const; //Scalar Multiply

	/* Multipies a vector by a scalar and then sets the result to the left-hand vector.
	 * \return This vector is returned.
	 */
	Vector3 & operator*=( const float & rh );

	/* Allows scaler division, that is dividing all components of the
	 * vector, x, y and z, by the same number.
	 * \return The result of the division.
	 */
	Vector3 operator/( const float & rh ) const;

	/* Divides a vector by a scalar and then sets the result to the left-hand vector.
	 * \return This vector is returned.
	 */
	Vector3 & operator/=( const float & rh );

	/* Sets the components of this Vector3 to those of another Vector3 
	 * \return This vector is returned.
	 */
	Vector3 & operator=( const Vector3 & v ) { x = v.x; y = v.y; z = v.z;  return *this; }

	/* Tests the equality of two Vector3 structures.  Vectors are considered equal if all
	 * three components are equal.
	 */
	bool operator==( const Vector3 & rh ) const;

	/* Computes the dot product of two vectors; the angle between two vectors.
	 * \param rh The vector to perform the dot product with
	 * \return The angle in radians between this vector and the one given
	 */
	float DotProduct( const Vector3 & rh ) const;

	/* Computes the cross product of two vectors; a vector perpendicular to both of them.
	 * \param The vector to perform the cross product with
	 * \return A vector perpendicular to this vector and the one given
	 */
	Vector3 CrossProduct( const Vector3 & rh) const; //Cross Product


	///* Multiplies this Vector with a 4x4 matrix
	// * \param The 4x4 matrix to multiply this vector with. 
	// * \return The new vector resulting from the multiplication.
	// */
	//Vector3 operator*( const Matrix44 & rh ) const;

	///* Multiplies this Vector with a 4x4 matrix and sets the result to itself
	// * \param The 4x4 matrix to multiply this vector with.
	// * \return This vector is returned.
	// */
	//Vector3 & operator*=( const Matrix44 & rh );

	friend ostream & operator<<( ostream & out, const Vector3 & rh );
};

/* Stores two floating point numbers.  Used as a row of a Matrix22 */
struct Float2 {
	float data[2]; /*!< The two floating point numbers stored as an array. */ 
	
	/*! The bracket operator makes it possible to use this structure like a C++ array.
	 * \param n The index into the data array.  Should be 0 or 1.
	 * \return The value at the given array index by reference so it can be read or set via the bracket operator.
	 */
	float & operator[](int n) {
		return data[n];
	}
	float operator[](int n) const {
		return data[n];
	}

	/*! Default constructor. */
	Float2() {}

	/*! This constructor can be used to set all values in this structure during initialization
	 * \param f1 The value to set the first floating point number to.
	 * \param f2 The value to set the second floating point number to.
	 */
	Float2( float f1, float f2 ) {
		data[0] = f1;
		data[1] = f2;
	}

	/*! This function can be used to set all values in the structure at the same time.
	 * \param f1 The value to set the first floating point number to.
	 * \param f2 The value to set the second floating point number to.
	 */
	void Set( float f1, float f2 ) {
		data[0] = f1;
		data[1] = f2;
	}

	//Python Operator Overloads
	float __getitem__(int n) {
		if (n > 1 || n < 0)
			throw std::out_of_range("Index out of range for MatrixRow3");
        return data[n];
    }
	void __setitem__(int n, float value) {
		if (n > 1 || n < 0)
			throw std::out_of_range("Index out of range for MatrixRow3");
		data[n] = value;
	}
};

/*! Stores a 2 by 2 matrix used for bump maps. */
struct Matrix22 {
	Float2 rows[2];  /*!< The two rows of Float2 structures which hold two floating point numbers each. */ 
	
	/*! The bracket operator makes it possible to use this structure like a 2x2 C++ array.
	 * \param n The index into the row array.  Should be 0 or 1.
	 * \return The Float2 structure for the given row index by reference so it can be read or set via the bracket operator.
	 */
	Float2 & operator[](int n) {
		return rows[n];
	}
	const Float2 & operator[](int n) const {
		return rows[n];
	}

	/*! Default Constructor */
	Matrix22() {}

	/*! This constructor can be used to set all values in this matrix during initialization
	 * \param m11 The value to set at row 1, column 1.
	 * \param m12 The value to set at row 1, column 2.
	 * \param m21 The value to set at row 2, column 1.
	 * \param m22 The value to set at row 2, column 2.
	 */
	Matrix22(
		float m11, float m12,
		float m21, float m22
	) {
		rows[0][0] = m11; rows[0][1] = m12;
		rows[1][0] = m21; rows[1][1] = m22;
	}

	/*! This function can be used to set all values in this matrix at the same time.
	 * \param m11 The value to set at row 1, column 1.
	 * \param m12 The value to set at row 1, column 2.
	 * \param m21 The value to set at row 2, column 1.
	 * \param m22 The value to set at row 2, column 2.
	 */
	void Set(
		float m11, float m12,
		float m21, float m22
	) {
		rows[0][0] = m11; rows[0][1] = m12;
		rows[1][0] = m21; rows[1][1] = m22;
	}

	Quaternion AsQuaternion();

	//Python Operator Overloads
	Float2 & __getitem__(int n) {
		if (n > 1 || n < 0)
			throw std::out_of_range("Index out of range for MatrixRow3");
        return rows[n];
    }
};

/* Stores three floating point numbers.  Used as a row of a Matrix33 and to store the data in attr_vector3 and attr_color3 type attributes. */
struct Float3 {
	float data[3]; /*!< The three floating point numbers stored as an array. */ 

	/*! The bracket operator makes it possible to use this structure like a C++ array.
	 * \param n The index into the data array.  Should be 0, 1, or 2.
	 * \return The value at the given array index by reference so it can be read or set via the bracket operator.
	 */
	float & operator[](int n) {
		return data[n];
	}
	float operator[](int n) const {
		return data[n];
	}

	/*!Default constructor.*/
	Float3() {}

	/*! This constructor can be used to set all values in this structure during initialization
	 * \param f1 The value to set the first floating point number to.
	 * \param f2 The value to set the second floating point number to.
	 * \param f3 The value to set the third floating point number to.
	 */
	Float3( float f1, float f2, float f3 ) {
		data[0] = f1;
		data[1] = f2;
		data[2] = f3;
	}

	/*! This function can be used to set all values in the structure at the same time.
	 * \param f1 The value to set the first floating point number to.
	 * \param f2 The value to set the second floating point number to.
	 * \param f3 The value to set the third floating point number to.
	 */
	void Set( float f1, float f2, float f3 ) {
		data[0] = f1;
		data[1] = f2;
		data[2] = f3;
	}

	//Python Operator Overloads
	float __getitem__(int n) {
		if (n > 2 || n < 0)
			throw std::out_of_range("Index out of range for Float3");
		return data[n];
	}
	void __setitem__(int n, float value) {
		if (n > 2 || n < 0)
			throw std::out_of_range("Index out of range for Float3");
		data[n] = value;
	}
};

/*! Stores a 3 by 3 matrix used for rotation. */
struct Matrix33 {
	Float3 rows[3]; /*!< The three rows of Float3 structures which hold three floating point numbers each. */ 
	
	/*! The bracket operator makes it possible to use this structure like a 3x3 C++ array.
	 * \param n The index into the row array.  Should be 0, 1, or 2.
	 * \return The Float3 structure for the given row index by reference so it can be read or set via the bracket operator.
	 */
	Float3 & operator[](int n) {
		return rows[n];
	}
	const Float3 & operator[](int n) const {
		return rows[n];
	}

	/*! Default constructor. */
	Matrix33() {}

	/*! This constructor can be used to set all values in this matrix during initialization
	 * \param m11 The value to set at row 1, column 1.
	 * \param m12 The value to set at row 1, column 2.
	 * \param m13 The value to set at row 1, column 3.
	 * \param m21 The value to set at row 2, column 1.
	 * \param m22 The value to set at row 2, column 2.
	 * \param m23 The value to set at row 2, column 3.
	 * \param m31 The value to set at row 3, column 1.
	 * \param m32 The value to set at row 3, column 2.
	 * \param m33 The value to set at row 3, column 3.
	 */
	Matrix33(
		float m11, float m12, float m13,
		float m21, float m22, float m23,
		float m31, float m32, float m33
	) {
		rows[0][0] = m11; rows[0][1] = m12; rows[0][2] = m13;
		rows[1][0] = m21; rows[1][1] = m22; rows[1][2] = m23;
		rows[2][0] = m31; rows[2][1] = m32; rows[2][2] = m33;
	}

	/*! This function can be used to set all values in this matrix at the same time.
	 * \param m11 The value to set at row 1, column 1.
	 * \param m12 The value to set at row 1, column 2.
	 * \param m13 The value to set at row 1, column 3.
	 * \param m21 The value to set at row 2, column 1.
	 * \param m22 The value to set at row 2, column 2.
	 * \param m23 The value to set at row 2, column 3.
	 * \param m31 The value to set at row 3, column 1.
	 * \param m32 The value to set at row 3, column 2.
	 * \param m33 The value to set at row 3, column 3.
	 */
	void Set(
		float m11, float m12, float m13,
		float m21, float m22, float m23,
		float m31, float m32, float m33
	) {
		rows[0][0] = m11; rows[0][1] = m12; rows[0][2] = m13;
		rows[1][0] = m21; rows[1][1] = m22; rows[1][2] = m23;
		rows[2][0] = m31; rows[2][1] = m32; rows[2][2] = m33;
	}

	Quaternion AsQuaternion();

	void AsFloatArr( float out[3][3] ) {
		out[0][0] = rows[0][0]; out[0][1] = rows[0][1]; out[0][2] = rows[0][2];
		out[1][0] = rows[1][0]; out[1][1] = rows[1][1]; out[1][2] = rows[1][2];
		out[2][0] = rows[2][0]; out[2][1] = rows[2][1]; out[2][2] = rows[2][2];
	}

	//Python Operator Overloads
	Float3 & __getitem__(int n) {
		if (n > 2 || n < 0)
			throw std::out_of_range("Index out of range for MatrixRow3");
        return rows[n];
    }
};

/* Stores four floating point numbers.  Used as a row of a Matrix44. */
struct Float4 {
	float data[4]; /*!< The four floating point numbers stored as an array. */ 

	/*! The bracket operator makes it possible to use this structure like a C++ array.
	 * \param n The index into the data array.  Should be 0, 1, 2, or 3.
	 * \return The value at the given array index by reference so it can be read or set via the bracket operator.
	 */
	float & operator[](int n) {
		return data[n];
	}
	float operator[](int n) const {
		return data[n];
	}

	/*! Default Constructor.*/
	Float4() {}

	/*! This constructor can be used to set all values in this structure during initialization
	 * \param f1 The value to set the first floating point number to.
	 * \param f2 The value to set the second floating point number to.
	 * \param f3 The value to set the third floating point number to.
	 * \param f4 The value to set the fourth floating point number to.
	 */
	Float4( float f1, float f2, float f3, float f4 ) {
		data[0] = f1;
		data[1] = f2;
		data[3] = f3;
		data[4] = f4;
	}

	/*! This function can be used to set all values in the structure at the same time.
	 * \param f1 The value to set the first floating point number to.
	 * \param f2 The value to set the second floating point number to.
	 * \param f3 The value to set the third floating point number to.
	 * \param f4 The value to set the fourth floating point number to.
	 */
	void Set( float f1, float f2, float f3, float f4 ) {
		data[0] = f1;
		data[1] = f2;
		data[3] = f3;
		data[4] = f4;
	}

	//Python Operator Overloads
	float __getitem__(int n) {
		if (n > 3 || n < 0)
			throw std::out_of_range("Index out of range for Float4");
        return data[n];
    }
	void __setitem__(int n, float value) {
		if (n > 3 || n < 0)
			throw std::out_of_range("Index out of range for Float4");
		data[n] = value;
	}
};

/*! Stores a 4 by 4 matrix used for combined transformations. */
struct Matrix44 {
	Float4 rows[4]; /*!< The three rows of Float3 structures which hold three floating point numbers each. */ 
	
	/*! The bracket operator makes it possible to use this structure like a 4x4 C++ array.
	 * \param n The index into the row array.  Should be 0, 1, 2, or 3.
	 * \return The Float4 structure for the given row index by reference so it can be read or set via the bracket operator.
	 */
	Float4 & operator[](int n) {
		return rows[n];
	}
	Float4 const & operator[](int n) const {
		return rows[n];
	}

	/*! Default constructor. Initializes Matrix to Identity. */
	Matrix44();

	/*! Copy constructor.  Initializes Matrix to another Matrix44.
	 * \param The matrix to initialize this one to. 
	 */
	Matrix44( const Matrix44 & m ) { memcpy(rows, m.rows, sizeof(Float4) * 4); }

	/*! This constructor can be used to set all values in this matrix during initialization
	 * \param m11 The value to set at row 1, column 1.
	 * \param m12 The value to set at row 1, column 2.
	 * \param m13 The value to set at row 1, column 3.
	 * \param m14 The value to set at row 1, column 4.
	 * \param m21 The value to set at row 2, column 1.
	 * \param m22 The value to set at row 2, column 2.
	 * \param m23 The value to set at row 2, column 3.
	 * \param m24 The value to set at row 2, column 4.
	 * \param m31 The value to set at row 3, column 1.
	 * \param m32 The value to set at row 3, column 2.
	 * \param m33 The value to set at row 3, column 3.
	 * \param m34 The value to set at row 3, column 4.
	 * \param m41 The value to set at row 4, column 1.
	 * \param m42 The value to set at row 4, column 2.
	 * \param m43 The value to set at row 4, column 3.
	 * \param m44 The value to set at row 4, column 4.
	 */
	Matrix44(
		float m11, float m12, float m13, float m14,
		float m21, float m22, float m23, float m24,
		float m31, float m32, float m33, float m34,
		float m41, float m42, float m43, float m44
	) {
		rows[0][0] = m11; rows[0][1] = m12; rows[0][2] = m13; rows[0][3] = m14;
		rows[1][0] = m21; rows[1][1] = m22; rows[1][2] = m23; rows[1][3] = m24;
		rows[2][0] = m31; rows[2][1] = m32; rows[2][2] = m33; rows[2][3] = m34;
		rows[3][0] = m41; rows[3][1] = m42; rows[3][2] = m43; rows[3][3] = m44;
	}

	/*! This function can be used to set all values in this matrix at the same time.
	 * \param m11 The value to set at row 1, column 1.
	 * \param m12 The value to set at row 1, column 2.
	 * \param m13 The value to set at row 1, column 3.
	 * \param m14 The value to set at row 1, column 4.
	 * \param m21 The value to set at row 2, column 1.
	 * \param m22 The value to set at row 2, column 2.
	 * \param m23 The value to set at row 2, column 3.
	 * \param m24 The value to set at row 2, column 4.
	 * \param m31 The value to set at row 3, column 1.
	 * \param m32 The value to set at row 3, column 2.
	 * \param m33 The value to set at row 3, column 3.
	 * \param m34 The value to set at row 3, column 4.
	 * \param m41 The value to set at row 4, column 1.
	 * \param m42 The value to set at row 4, column 2.
	 * \param m43 The value to set at row 4, column 3.
	 * \param m44 The value to set at row 4, column 4.
	 */
	void Set(
		float m11, float m12, float m13, float m14,
		float m21, float m22, float m23, float m24,
		float m31, float m32, float m33, float m34,
		float m41, float m42, float m43, float m44
	) {
		rows[0][0] = m11; rows[0][1] = m12; rows[0][2] = m13; rows[0][3] = m14;
		rows[1][0] = m21; rows[1][1] = m22; rows[1][2] = m23; rows[1][3] = m24;
		rows[2][0] = m31; rows[2][1] = m32; rows[2][2] = m33; rows[2][3] = m34;
		rows[3][0] = m41; rows[3][1] = m42; rows[3][2] = m43; rows[3][3] = m44;
	}

	//undocumented
	void AsFloatArr( float out[4][4] ) {
		out[0][0] = rows[0][0]; out[0][1] = rows[0][1]; out[0][2] = rows[0][2]; out[0][3] = rows[0][3];
		out[1][0] = rows[1][0]; out[1][1] = rows[1][1]; out[1][2] = rows[1][2]; out[1][3] = rows[1][3];
		out[2][0] = rows[2][0]; out[2][1] = rows[2][1]; out[2][2] = rows[2][2]; out[2][3] = rows[2][3];
		out[3][0] = rows[3][0]; out[3][1] = rows[3][1]; out[3][2] = rows[3][2]; out[3][3] = rows[3][3];
	}

	//Python Operator Overloads
	Float4 & __getitem__(int n) {
		if (n > 3 || n < 0)
			throw std::out_of_range("Index out of range for Matrix44");
        return rows[n];
    }
};

/*! The 4x4 identity matrix */
const Matrix44 IDENTITY44( 1.0f, 0.0f, 0.0f, 0.0f,
						   0.0f, 1.0f, 0.0f, 0.0f,
						   0.0f, 0.0f, 1.0f, 0.0f,
						   0.0f, 0.0f, 0.0f, 1.0f );

/*! Stores a color along with alpha translucency */
struct Color4 {
	float r; /*!< The red component of this color.  Should be between 0.0f and 1.0f. */ 
	float g; /*!< The green component of this color.  Should be between 0.0f and 1.0f. */ 
	float b; /*!< The blue component of this color.  Should be between 0.0f and 1.0f. */ 
	float a; /*!< The alpha translucency component of this color.  Should be between 0.0f and 1.0f. */ 

	/*! Default constructor */
	Color4() {}

	/*! This constructor can be used to set all values in this structure during initialization
	 * \param r The value to set the red component of this color to.  Should be between 0.0f and 1.0f.
	 * \param g The value to set the green component of this color to. Should be between 0.0f and 1.0f.
	 * \param b The value to set the blue component of this color to.  Should be between 0.0f and 1.0f.
	 * \param a The value to set the alpha translucency component of this color to.  Should be between 0.0f and 1.0f.
	 */
	Color4(float r, float g, float b, float a = 1.0f) {
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

	/*! This function can be used to set all values in the structure at the same time.
	 * \param r The value to set the red component of this color to.  Should be between 0.0f and 1.0f.
	 * \param g The value to set the green component of this color to. Should be between 0.0f and 1.0f.
	 * \param b The value to set the blue component of this color to.  Should be between 0.0f and 1.0f.
	 * \param a The value to set the alpha translucency component of this color to.  Should be between 0.0f and 1.0f.
	 */
	void Set(float r, float g, float b, float a = 1.0f) {
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}
};

/*! Represents a quaternion - a 4D extention of complex numbers used as an alternitive to matrices to represent rotation.*/
struct Quaternion {
	float w; /*!< The W scalar component of this Quaternion. */ 
	float x; /*!< The X vector component of this Quaternion. */ 
	float y; /*!< The Y vector component of this Quaternion. */ 
	float z; /*!< The Z vector component of this Quaternion. */ 

	/*! Default constructor. */
	Quaternion() {}

	/*! This constructor can be used to set all values in this structure during initialization
	 * \param w The value to set the W scalar component of this quaternion to.
	 * \param x The value to set the X vector component of this quaternion to.
	 * \param y The value to set the Y vector component of this quaternion to.
	 * \param z The value to set the Z vector component of this quaternion to.
	 */
	Quaternion(float w, float x, float y, float z) {
		this->w = w;
		this->x = x;
		this->y = y;
		this->z = z;
	}

	/*! This function can be used to set all values in the structure at the same time.
	 * \param w The value to set the W scalar component of this quaternion to.
	 * \param x The value to set the X vector component of this quaternion to.
	 * \param y The value to set the Y vector component of this quaternion to.
	 * \param z The value to set the Z vector component of this quaternion to.
	 */
	void Set(float w, float x, float y, float z) {
		this->w = w;
		this->x = x;
		this->y = y;
		this->z = z;
	}

	/*! This function returns a 3x3 matrix representation of the rotation stored in this quaternion.
	 * \return a Matrix33 structure with an equivalent rotation to this quaternion.
	 */
	Matrix33 AsMatrix();

	/*! This function returns a Euler Angle representation of the rotation stored in this quaternion.
	 * The angles returned correspond to yaw, pitch, and roll and are in radiens.
	 * \return a Float3 structure with the first value containing the yaw, the second the pitch,
	 * and the third the roll.  The values are in radians.
	 */
	Float3 AsEulerYawPitchRoll();
};

//--ostream functions for printing with cout--//

ostream & operator<<( ostream & out, TexCoord const & val );
ostream & operator<<( ostream & out, Triangle const & val );
ostream & operator<<( ostream & out, Float2 const & val );
ostream & operator<<( ostream & out, Matrix22 const & val );
ostream & operator<<( ostream & out, Float3 const & val );
ostream & operator<<( ostream & out, Matrix33 const & val );
ostream & operator<<( ostream & out, Float4 const & val );
ostream & operator<<( ostream & out, Matrix44 const & val );
ostream & operator<<( ostream & out, Color4 const & val );
ostream & operator<<( ostream & out, Quaternion const & val );



Matrix33 MultMatrix33( Matrix33 const & a, Matrix33 const & b );
Matrix44 MultMatrix44( Matrix44 const & a, Matrix44 const & b );
float DetMatrix33( Matrix33 const & m );
float DetMatrix44( Matrix44 const & m );
float AdjMatrix44( Matrix44 const & m, int r, int c );
Matrix44 InverseMatrix44( Matrix44 const & m );
void SetIdentity33( Matrix33 & m );
void SetIdentity44( Matrix44 & m );
void PrintMatrix33( Matrix33 const & m, ostream & out );
void PrintMatrix44( Matrix44 const & m, ostream & out );

#endif
