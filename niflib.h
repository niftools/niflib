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

#ifndef _NIFLIB_H_
#define _NIFLIB_H_

//--Includes--//
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <list>
#include <map>
using namespace std;

//--Forward Declarations of Classes & Structs--//
class IAttr;
class IBlock;
class ITriShapeData;
class ISkinData;
class IKeyframeData;
class INode;
class blk_ref;
class attr_ref;
struct blk_link;
struct Texture;
struct TextureSource;
struct BoundingBox;
struct ConditionalInt;
struct SkinWeight;

//--Constants--//
const unsigned int HEADER_STRING_LEN = 39;

//Interface IDs
const int TriShapeData = 0;
const int SkinData = 1;
const int Node = 2;
const int KeyframeData = 3;

//--Main Functions--//

//Reads the given file by file name and returns a vector of block references
vector<blk_ref> ReadNifList( string file_name );

//Reads the given file by file name and returns a reference to the root block
blk_ref ReadNifTree( string file_name );

//Writes a valid Nif File given a file name, a pointer to the root block of a file tree
void WriteNifTree( string file_name, blk_ref & root_block );

////Returns the NIF spec version of a file, given a file name.
//string GetFileVersion(string file_name);

//Sets whether data/hex areas are shown by Print commands... yes it uses a global right now <sigh>
void SetVerboseMode( bool val );

//Creates a new block of the given type and returns a reference to it
blk_ref CreateBlock( string block_type );

//Retrns total number of blocks in memory
unsigned int BlocksInMemory();

//--Query Functions--//
// These are shorthands for using QueryInterface, and required for scripting languages
ITriShapeData * QueryTriShapeData( blk_ref block );
ISkinData * QuerySkinData( blk_ref block );
INode * QueryNode( blk_ref block );
IKeyframeData * QueryKeyframeData( blk_ref block );

//--TypeDefs--//

typedef float float3[3];
typedef float matrix[3][3];
typedef float transform[4][4];
//typedef pair<link_type, blk_ref> blk_pair;

//--Main Interfaces--//

/**
 * Interface for most Ni-blocks.
 */
class IBlock{
public:

	IBlock( ){}
	virtual ~IBlock() {}

	virtual int GetBlockNum() = 0;
	virtual blk_ref GetParent() = 0;
	virtual string asString() = 0;
	virtual string GetBlockType() = 0;

	//Attribute Functions
	virtual attr_ref GetAttr(string attr_name) = 0;
	virtual attr_ref GetAttr(int index) = 0;
	virtual int AttrCount() = 0;

	//Link Functions
	virtual list<blk_ref> GetLinks() = 0;

	//To check for specialized Interfaces
	virtual void * QueryInterface( int id ) = 0;
	
protected:
	friend class blk_ref;
	virtual void AddRef() = 0;
	virtual void SubtractRef() = 0;
};

class IAttr {
public:
	IAttr() {}
	virtual ~IAttr() {}
	virtual string GetType() const = 0;
	virtual string GetName() const = 0;
	virtual void Read( ifstream& in ) = 0;
	virtual void Write( ofstream& out ) = 0;
	//Getters
	virtual int asInt() const = 0;
	virtual float asFloat() const = 0;
	virtual void asFloat3( float3 &out ) const = 0;
	virtual string asString() const = 0;
	virtual void asMatrix( matrix &out ) const = 0;
	virtual blk_ref asLink() const = 0;
	virtual TextureSource asTextureSource() const = 0;
	virtual BoundingBox asBoundingBox() const = 0;
	virtual ConditionalInt asConditionalInt() const = 0;
	virtual Texture asTexture() const = 0;
	virtual vector<float> asFloatList() const = 0;
	virtual list<blk_ref> asLinkList() const = 0;
	//Setters
	virtual void Set(int) = 0;
	virtual void Set(float) = 0;
	virtual void Set(float, float, float) = 0;
	virtual void Set(string) = 0;
	virtual void Set(matrix) = 0;
	virtual void Set( blk_ref & n ) = 0;
	virtual void Set(TextureSource&) = 0;
	virtual void Set(BoundingBox&) = 0;
	virtual void Set(ConditionalInt&) = 0;
	virtual void Set(Texture&) = 0;
	virtual void Set(vector<float>) = 0;
	//Link functions
	virtual bool HasLinks() = 0;
	virtual void AddLink( blk_ref block ) = 0;
	virtual void AddLinks( list<blk_ref> new_links ) = 0;
	virtual void ClearLinks() = 0;
	virtual void RemoveLinks( blk_ref block ) = 0;
	virtual blk_ref FindLink( string block_type ) = 0;
};

struct UVCoord {
	float u, v;
};

struct Triangle {
	short v1, v2, v3;
};

struct Vector3D {
	float x, y, z;
};

struct Color {
	float r, g, b, a;
};

struct Quaternion {
	float w, x, y, z;
};

template <class T>
struct Key {
	float time;
	T data, forward_tangent, backward_tangent;
	float3 tbc;
};

enum KeyType { LINEAR_KEY = 1, QUADRATIC_KEY = 2, TBC_KEY = 3 };

class INode {
public:
	INode() {}
	virtual ~INode() {}
	virtual void GetLocalTransform( float out_matrix[4][4] ) = 0;
	virtual void GetWorldTransform( float out_matrix[4][4] ) = 0;
	virtual void GetBindPosition( float out_matrix[4][4] ) = 0;
	virtual void SetBindPosition( float in_matrix[4][4] ) = 0;
	virtual void GetLocalBindPos( float out_matrix[4][4] ) = 0;
};

class ITriShapeData {
public:
	ITriShapeData() {}
	virtual ~ITriShapeData () {}
	//Counts
	virtual short GetVertexCount() = 0;
	virtual short GetUVSetCount() = 0;
	virtual short GetTriangleCount() = 0;
	virtual void SetVertexCount(int n) = 0;
	virtual void SetUVSetCount(int n) = 0;
	virtual void SetTriangleCount(int n) = 0;
	//Match Detection
	virtual void SetMatchDetectionMode(bool choice) = 0;
	virtual bool GetMatchDetectionMode() = 0;
	//Getters
	virtual vector<Vector3D> GetVertices() = 0;
	virtual vector<Vector3D> GetNormals() = 0;
	virtual vector<Color> GetColors() = 0;
	virtual vector<UVCoord> GetUVSet( int index ) = 0;
	virtual vector<Triangle> GetTriangles() = 0;
	//Setters
	virtual void SetVertices( const vector<Vector3D> & in ) = 0;
	virtual void SetNormals( const vector<Vector3D> & in ) = 0;
	virtual void SetColors( const vector<Color> & in ) = 0;
	virtual void SetUVSet( int index, const vector<UVCoord> & in ) = 0;
	virtual void SetTriangles( const vector<Triangle> & in ) = 0;
};

class ISkinData {
public:
	ISkinData() {}
	virtual ~ISkinData () {}
	virtual vector<blk_ref> GetBones() = 0;
	virtual map<int, float> GetWeights( blk_ref bone ) = 0;
	virtual void AddBone( blk_ref bone, map<int, float> in ) = 0;
	virtual void RemoveBone( blk_ref bone ) = 0;
};

class IKeyframeData {
public:
	IKeyframeData() {}
	virtual ~IKeyframeData () {}
	//Rotate
	virtual KeyType GetRotateType() = 0;
	virtual void SetRotateType( KeyType t ) = 0;
	virtual vector< Key<Quaternion> > GetRotateKeys() = 0;
	virtual void SetRotateKeys( vector< Key<Quaternion> > & keys ) = 0;
	//Translate
	virtual KeyType GetTranslateType() = 0;
	virtual void SetTranslateType( KeyType t ) = 0;
	virtual vector< Key<float3> > GetTranslateKeys() = 0;
	virtual void SetTranslateKeys( vector< Key<float3> > & keys ) = 0;
	//Scale
	virtual KeyType GetScaleType() = 0;
	virtual void SetScaleType( KeyType t ) = 0;
	virtual vector< Key<float> > GetScaleKeys() = 0;
	virtual void SetScaleKeys( vector< Key<float> > & keys ) = 0;
};

//--Attribute Reference--//
class attr_ref {
public:
	attr_ref() : _attr(NULL) {}
	attr_ref( IAttr * ptr ) : _attr(ptr) {}
	IAttr * operator->() {
		if ( _attr == NULL ) {
			//pointer has not been fixed, throw exception
			throw runtime_error("Attempted to dereference a null Attribute reference.");
		} else {
			return _attr;
		}
	}
	bool is_null() {
		if (_attr == NULL )
			return true;
		else
			return false;
	}
	IAttr * ptr() {
		return _attr;
	}
	//Comparison operators
	bool operator==(attr_ref & rh) {
		if (_attr == rh._attr)
			return true;
		else
			return false;
	}
	bool operator!=(attr_ref & rh) {
		if (_attr != rh._attr)
			return true;
		else
			return false;
	}
	bool operator<(attr_ref & rh) {
		if (_attr < rh._attr)
			return true;
		else
			return false;
	}

	//Assignment operators
	attr_ref & operator=(int & n) {
		_attr->Set(n);
		return *this;
	}
	attr_ref & operator=(float & n) {
		_attr->Set(n);
		return *this;
	}
	attr_ref & operator=(float3 & n) {
		_attr->Set(n[0], n[1], n[2]);
		return *this;
	}
	attr_ref & operator=(string & n) {
		_attr->Set(n);
		return *this;
	}
	attr_ref & operator=(matrix & n) {
		_attr->Set(n);
		return *this;
	}
	//attr_ref & operator=(blk_ref & n) {
	//	_attr->Set(n);
	//	return *this;
	//}
	attr_ref & operator=(TextureSource & n) {
		_attr->Set(n);
		return *this;
	}
	attr_ref & operator=(BoundingBox & n) {
		_attr->Set(n);
		return *this;
	}
	attr_ref & operator=(ConditionalInt & n) {
		_attr->Set(n);
		return *this;
	}
	attr_ref & operator=(Texture & n) {
		_attr->Set(n);
		return *this;
	}

	//Conversion fuctions
	operator int() { return _attr->asInt(); }
	operator float() { return _attr->asFloat(); }
	//Float3
	operator string() { return _attr->asString(); }
	//operator matrix();
	operator blk_ref();
	operator TextureSource();
	operator BoundingBox();
	operator ConditionalInt();
	operator Texture();
	operator list<blk_ref>() { return _attr->asLinkList(); }

	//friend ostream & operator<<(ostream & lh, const attr_ref & rh) {
	//	if ( rh._attr == NULL )
	//		lh << "Null Attribute";
	//	else
	//		lh << rh->GetName() << ":  " << rh->asString();
	//	}
	//	return lh;
	//}

	private:
	IAttr * _attr;
};

//--Block Reference--//

class blk_ref {
public:
	blk_ref() : _index(-1), _block(NULL) {}
	blk_ref( int index ) : _index(index), _block(NULL) {}
	//Copy Constructor
	blk_ref(const blk_ref & rh ) {
		_block = rh._block;
		_index = rh._index;

		if ( _block != NULL ) {
			//cout << "Copying from another reference - ";
			//Increment reference count
			_block->AddRef();
		}
	}
	//Asignment Operator
	blk_ref & operator=(const blk_ref & rh ) {
		//Make sure it's not already equal
		if (_block == rh._block && get_index() == rh.get_index() ) {
			// already equal
			return *this;
		}

		// the incoming reference is different
		if ( _block != NULL ) {
			//Decrement reference count
			//cout << "This reference was overwritten by another - ";
			_block->SubtractRef();
		}
		_block = rh._block;
		_index = rh._index;
		if (_block != NULL ) {
			//rhcrement reference count
			//cout << "Copied from another reference using = - ";
			_block->AddRef();
		}

		return *this;
	}
	// Equality Operator
	bool operator==(const blk_ref & rh) {
		if ( _block == rh._block && _index == rh._index )
			return true;
		else
			return false;
	}
	// Less-Than Operator
	bool operator<( const blk_ref & rh ) const {
		if ( get_index() < rh.get_index() )
			return true;
		else
			return false;
	}
	// Non-Equality Operator
	bool operator!=(const blk_ref & rh) {
		return !(*this == rh);
	}
	bool is_null() {
		if (_block == NULL && _index == -1)
			return true;
		else
			return false;
	}
	blk_ref( IBlock * block ) : _index(-1), _block(block) {

		//Increment reference count
		//cout << "Creating from block - ";
		_block->AddRef();
	}
	~blk_ref() {
		//If pointer has been fixed
		if ( _block != NULL ) {
			//Decrement reference count
			//cout << "Reference deleted - ";
			_block->SubtractRef();
		}
	}
	void set_block( IBlock * block ) {
		//Use assignment operator code
		*this = blk_ref( block );
	}
	IBlock * operator->() const {
		if ( _block == NULL ) {
			//pointer has not been fixed, throw exception
			cout << *this << endl;
			throw runtime_error("Attempted to dereference a block reference that has not been fixed.");
		} else {
			return _block;
		}
	}
	attr_ref operator[] ( string index ) {
		return _block->GetAttr(index);
	}
	attr_ref operator[] ( int index ) {
		return _block->GetAttr(index);
	}
	int get_index() const {

		if (_block != NULL)
			return _block->GetBlockNum();
		else
			return _index; 
	}
	IBlock * get_block() const {
		return _block;
	}
	void set_index( int index ) { 
		//Use assigntment operator code
		*this = blk_ref( index );
	}
	bool is_fixed() const {
		if ( _block == NULL )
			return false;
		else
			return true;
	}
	friend ostream & operator<<(ostream & lh, const blk_ref & rh) {
		if (rh._block != NULL) {
			lh << rh._block->GetBlockType() << "(Block " << rh._block->GetBlockNum() << ")";
			attr_ref attr = rh._block->GetAttr("Name");
			if (attr.is_null() == false ) {
				lh << " [" << attr->asString() << "]";
			}
		} else {
			if (rh._index == -1)
				lh << "Null (-1)";
			else
				lh << "Block " << rh._index;
		}
		return lh;
	}
protected:
	int _index;
	IBlock * _block;
};

enum TexClampMode {
	CLAMP_S_CLAMP_T = 0,
	CLAMP_S_WRAP_T = 1,
	WRAP_S_CLAMP_T = 2,
	WRAP_S_WRAP_T = 3
};

enum TexFilterMode {
	FILTER_NEAREST = 0,
	FILTER_BILERP = 1,
	FILTER_TRILERP = 2,
	FILTER_NEAREST_MIPNEAREST = 3,
	FILTER_NEAREST_MIPLERP = 4,
	FILTER_BILERP_MIPNEAREST = 5,
};

//--Structures--//

struct blk_link {
	blk_ref block;
	attr_ref attr;
};

struct BoundingBox {
	bool isUsed;
	int unknownInt;
	float translation[3];
	float rotation[3][3];
	float radius_x, radius_y, radius_z;
};

struct ConditionalInt {
	bool isUsed;
	int unknownInt;
};

struct Texture {
	bool isUsed;
	TexClampMode clampMode;
	TexFilterMode filterMode;
	int textureSet;
	short PS2_L;
	short PS2_K;
	short unknownShort;
	float bmLumaOffset;
	float bmLumaScale;
	float bmMatrix[2][2];
};

struct TextureSource {
	bool useExternal;
	unsigned char unknownByte;
	string fileName;
};

struct SkinWeight {
	unsigned short vertexNum;
	float vertexWeight;
};

#endif
