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

#ifndef _NIF_ATTRS_H_
#define _NIF_ATTRS_H_

#include <sstream>
#include <list>
#include "niflib_internal.h"

#define endl "\r\n"


class IntAttr : public AAttr {
public:
	IntAttr( string const & name, IBlock * owner, int * data ) : AAttr( name, owner ), _data(data) {}
	~IntAttr() {}
	AttrType GetType() const { return attr_int; }
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << *_data;

		return out.str();
	}
	int asInt() const { return *_data; }
	void Set(int n ) { *_data = n; }
protected:
	int * _data;
};

class UIntAttr : public AAttr {
public:
	UIntAttr( string const & name, IBlock * owner, uint * data ) : AAttr( name, owner ), _data(data) {}
	~UIntAttr() {}
	AttrType GetType() const { return attr_int; }
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << *_data;

		return out.str();
	}
	int asInt() const { return int(*_data); }
	void Set(int n ) { *_data = uint(n); }
protected:
	uint * _data;
};

class ShortAttr : public AAttr {
public:
	ShortAttr( string const & name, IBlock * owner, short * data ) : AAttr( name, owner ), _data(data) {}
	~ShortAttr() {}
	AttrType GetType() const { return attr_short; }
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << *_data;

		return out.str();
	}
	int asInt() const { return int(*_data); }
	void Set(int n ) { *_data = short(n); }
protected:
	short * _data;
};

class UShortAttr : public AAttr {
public:
	UShortAttr( string const & name, IBlock * owner, ushort * data ) : AAttr( name, owner ), _data(data) {}
	~UShortAttr() {}
	AttrType GetType() const { return attr_short; }
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << *_data;

		return out.str();
	}
	int asInt() const { return int(*_data); }
	void Set(int n ) { *_data = ushort(n); }
protected:
	ushort * _data;
};

class ByteAttr : public AAttr {
public:
	ByteAttr( string const & name, IBlock * owner, byte * data ) : AAttr( name, owner ), _data(data) {}
	~ByteAttr() {}
	AttrType GetType() const { return attr_byte; }
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << int(*_data);

		return out.str();
	}
	int asInt() const { return int(*_data); }
	void Set(int n ) { *_data = byte(n); }
protected:
	byte * _data;
};

class FloatAttr : public AAttr {
public:
	FloatAttr( string const & name, IBlock * owner, float * data ) : AAttr( name, owner ), _data(data) {}
	~FloatAttr() {}
	AttrType GetType() const { return attr_float; }
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << *_data;

		return out.str();
	}
	float asFloat() const { return *_data; }
	void Set(float n ) { *_data = n; }
protected:
	float * _data;
};

class Float3Attr : public AAttr {
public:
	Float3Attr( string const & name, IBlock * owner, Float3 * data ) : AAttr( name, owner ), _data(data) {}
	~Float3Attr() {}
	AttrType GetType() const { return attr_float3; }
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << *_data;

		return out.str();
	}
	Float3 asFloat3() const { return *_data; }
	void Set(Float3 const & n ) { *_data = n; }
protected:
	Float3 * _data;
};

class Float4Attr : public AAttr {
public:
	Float4Attr( string const & name, IBlock * owner, Float4 * data ) : AAttr( name, owner ), _data(data) {}
	~Float4Attr() {}
	AttrType GetType() const { return attr_float4; }
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << *_data;

		return out.str();
	}
	Float4 asFloat4() const { return *_data; }
	void Set(Float4 const & n ) { *_data = n; }
protected:
	Float4 * _data;
};

class Vector3Attr : public AAttr {
public:
	Vector3Attr( string const & name, IBlock * owner, Vector3 * data ) : AAttr( name, owner ), _data(data) {}
	~Vector3Attr() {}
	AttrType GetType() const { return attr_vector3; }
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << *_data;

		return out.str();
	}
	Float3 asFloat3() const { return Float3(_data->x, _data->y, _data->z); }
	void Set(Float3 const & n ) { 
		_data->x = n.data[0];
		_data->y = n.data[1];
		_data->z = n.data[2];
	}
protected:
	Vector3 * _data;
};

//class Color3Attr : public AAttr {
//public:
//	Color3Attr( string const & name, IBlock * owner, Color3 * data ) : AAttr( name, owner ), _data(data) {}
//	~Color3Attr() {}
//	AttrType GetType() const { return attr_color3; }
//	string asString() const {
//		stringstream out;
//		out.setf(ios::fixed, ios::floatfield);
//		out << setprecision(1);
//
//		out << *data;
//
//		return out.str();
//	}
//	Float3 asFloat3() const { return Float3(_data->r, _data->g, _data->b); }
//	void Set(Float3 const & n ) { 
//		_data->r = n.data[0];
//		_data->g = n.data[1];
//		_data->b = n.data[2];
//	}
//protected:
//	Color3 * _data;
//};

//class Color4Attr : public AAttr {
//public:
//	Color4Attr( string const & name, IBlock * owner, Color4 * data ) : AAttr( name, owner ), _data(data) {}
//	~Color4Attr() {}
//	AttrType GetType() const { return attr_color4; }
//	string asString() const {
//		stringstream out;
//		out.setf(ios::fixed, ios::floatfield);
//		out << setprecision(1);
//
//		out << *data;
//
//		return out.str();
//	}
//	Float3 asFloat4() const { return Float3(_data->r, _data->g, _data->b, _data->a); }
//	void Set(Float4 const & n ) { 
//		_data->r = n.data[0];
//		_data->g = n.data[1];
//		_data->b = n.data[2];
//		_data->a = n.data[2];
//	}
//protected:
//	Color4 * _data;
//};

class QuaternionAttr : public AAttr {
public:
	QuaternionAttr( string const & name, IBlock * owner, Quaternion * data ) : AAttr( name, owner ), _data(data) {}
	~QuaternionAttr() {}
	AttrType GetType() const { return attr_quaternion; }
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << *_data;

		return out.str();
	}
	Float4 asFloat4() const { return Float4(_data->w, _data->x, _data->y, _data->z); }
	void Set(Float4 const & n ) { 
		_data->w = n.data[0];
		_data->x = n.data[1];
		_data->y = n.data[2];
		_data->z = n.data[2];
	}
protected:
	Quaternion * _data;
};

class StringAttr : public AAttr {
public:
	StringAttr( string const & name, IBlock * owner, string * data ) : AAttr( name, owner ), _data(data) {}
	~StringAttr() {}
	AttrType GetType() const { return attr_string; }
	string asString() const { return *_data; }
	void Set(string const & n) { *_data = n; }
private:
	string * _data;
};

class LinkAttr : public AAttr {
public:
	LinkAttr( string const & name, IBlock * owner, Link * data ) : AAttr( name, owner ), _data(data) {}
	~LinkAttr() {}
	AttrType GetType() const { return attr_link; }
	
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << *_data;

		return out.str();
	}
	bool HasLinks() const { return true; }
	list<blk_ref> asLinkList() const { 
		list<blk_ref> out;

		out.push_back( _data->GetLink() );

		return out; 
	}
	void ClearLinks() { _data->Nullify(); }
	void AddLinks( list<blk_ref> const & new_links ) {
		//Just take the first one
		_data->SetLink( *(new_links.begin()) );
	}

	blk_ref asLink() const { return _data->GetLink(); }
	void Set( blk_ref const & n ) { _data->SetLink(n); }
private:
	Link * _data;
};

class CrossRefAttr : public AAttr {
public:
	CrossRefAttr( string const & name, IBlock * owner, CrossRef * data ) : AAttr( name, owner ), _data(data) {}
	~CrossRefAttr() {}
	AttrType GetType() const {
		return attr_link;
	}
	string asString() const {
		//cout << endl << "CrossRefAttr::asString()";
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << *_data;

		return out.str();
	}
	bool HasLinks() const { 
		//cout << endl << "CrossRefAttr::HasLinks()";
		return true;
	}
	list<blk_ref> asLinkList() const { 
		//cout << endl << "CrossRefAttr::asLinkList()";
		list<blk_ref> out;

		out.push_back( blk_ref(_data->GetCrossRef()) );

		return out; 
	}
	void ClearLinks() { 
		//cout << endl << "CrossRefAttr::ClearLinks()";
		_data->Nullify();
	}
	void AddLinks( list<blk_ref> const & new_links ) {
		//cout << endl << "CrossRefAttr::AddLinks()";
		//Just take the first one
		_data->SetCrossRef( new_links.begin()->get_block() );
	}

	blk_ref asLink() const { return blk_ref(_data->GetCrossRef()); }
	void Set( blk_ref const & n ) { 
		_data->SetCrossRef( n.get_block() );
	}
private:
	CrossRef * _data;
};


class FlagsAttr : public AAttr {
public:
	FlagsAttr( string const & name, IBlock * owner ) : AAttr( name, owner ), data(0) {}
	~FlagsAttr() {}
	AttrType GetType() const { return attr_flags; }
	void ReadAttr( istream& in, unsigned int version ) { data = ReadUShort( in ); }
	void WriteAttr( ostream& out, unsigned int version ) const { WriteUShort( data, out ); }
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << data;
		short t = data;
		for (uint i = 0; i < 16; ++i) {
			if((t & 1) !=0) {
				out << endl << "   Bit " << i + 1 << " set ";
			}
			t >>= 1;
		}

		return out.str();
	}
	int asInt() const { return int(data); }
	void Set(int n ) { data = short(n); }
private:
	short data;
};

class Matrix33Attr : public AAttr {
public:
	Matrix33Attr( string const & name, IBlock * owner, Matrix33 * data ) : AAttr( name, owner ), _data(data) {}
	~Matrix33Attr() {}
	AttrType GetType() const { return attr_matrix33; }
	
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << *_data << endl;

		return out.str();
	}
	Matrix33 asMatrix33() const {
		return *_data;
	}
	void Set( Matrix33 const & n ) {
		*_data = n;
	}
private:
	Matrix33 * _data;
};
/*
class BoneAttr : public AAttr {
public:
	BoneAttr( string const & name, IBlock * owner ) : AAttr(name, owner, first_ver, last_ver) {}
	~BoneAttr() {}
	AttrType GetType() const { return attr_bones; }
	void ReadAttr( istream& in, unsigned int version ) {
		ISkinInstInternal * data = (ISkinInstInternal*)_owner->QueryInterface( SkinInstInternal );
		if ( data != NULL ) {
			data->ReadBoneList( in );
		} else {
			throw runtime_error ("Attempted to use a bone list attribute on a block that doesn't support it.");
		}
	}
	void WriteAttr( ostream& out, unsigned int version ) const {
		//ISkinInstInternal * data = (ISkinInstInternal*)_owner->QueryInterface( SkinInstInternal );
		blk_ref data_blk = _owner->GetAttr("Data")->asLink();
		if ( data_blk.is_null() == false )  {
			//Get Bone data from data block
			ISkinData * data = (ISkinData*)data_blk->QueryInterface( ID_SKIN_DATA );
			vector<blk_ref> bones = data->GetBones();

			//Write bone indices to file
			WriteUInt( uint(bones.size()), out );
			for (uint i = 0; i < bones.size(); ++i ) {
				WriteUInt( bones[i].get_index(), out );
			}
		}
		else {
			//No data, so write zero for no bones
			WriteUInt( 0, out );
		}
	}
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		//See if there is a data block
		blk_ref data_blk = _owner->GetAttr("Data")->asLink();
		if ( data_blk.is_null() == false && data_blk.is_fixed() == true )  {
			//Get Bone data from data block
			ISkinData * data = (ISkinData*)data_blk->QueryInterface( ID_SKIN_DATA );
			vector<blk_ref> bones = data->GetBones();

			//Print Bone List
			for (uint i = 0; i < bones.size(); ++i ) {
				out << endl << "   " << bones[i];
			}
			if ( bones.size() == 0 ) {
				out << "None";
			}
		}
		else {
			//No data, so write none
			out << "None";
		}

		return out.str();
	}
};
*/

class LinkGroupAttr : public AAttr {
public:
	LinkGroupAttr( string const & name, IBlock * owner, vector<Link> * data ) : AAttr( name, owner ), _data(data) {}
	~LinkGroupAttr() {}
	AttrType GetType() const { return attr_linkgroup; }
	
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);
		for (vector<Link>::const_iterator it = _data->begin(); it != _data->end(); ++it ) {
			out << endl << "   " << it->GetLink();
		}
		if (_data->size() == 0 ) {
			out << "None";
		}

		return out.str();
	}

	bool HasLinks() const { return true; }

	list<blk_ref> asLinkList() const { 
		list<blk_ref> out;

		for (vector<Link>::iterator it = _data->begin(); it != _data->end(); ++it ) {
			out.push_back( it->GetLink() );
		}

		return out; 
	}

	void AddLink( blk_ref const & block ) {
		Link new_link(_owner);
		new_link.SetLink( block );
		_data->push_back( new_link);
	}

	void AddLinks( list<blk_ref> const & new_links ) {
		//Add new list of links
		for (list<blk_ref>::const_iterator it = new_links.begin(); it != new_links.end(); ++it ) {
			Link new_link(_owner);
			new_link.SetLink( *it );
			try {
				_data->push_back( new_link );
			}
			catch( exception & e ) {
				cout << "Error:  " << e.what() << endl;
			}
		}
	}

	blk_ref FindLink( string const & block_type ) const {
		//Find the first link with the requested block type
		for (vector<Link>::const_iterator it = _data->begin(); it != _data->end(); ++it ) {
			if ( it->GetLink()->GetBlockType() == block_type )
				return it->GetLink();
		}

		//No block was found, so return a null one
		return blk_ref(-1);
	}

	void ClearLinks() { _data->clear(); }

	void RemoveLinks( blk_ref const & block ) {
		//Remove all links that match this block
		for (vector<Link>::iterator it = _data->begin(); it != _data->end(); ++it ) {
			if ( it->GetLink() == block ) {
				_data->erase( it );
				return;
			}
		}
	}
protected:
	vector<Link> * _data;
};
/*
class TargetGroupAttr : public AAttr {
public:
	TargetGroupAttr( string const & name, IBlock * owner ) : AAttr( name, owner ) {
		//cout << endl << "TargetGroupAttr()";
	}
	~TargetGroupAttr() {
		//cout << endl << "~TargetGroupAttr()";
		ClearLinks();
	}

	AttrType GetType() const { 
		//cout << endl << "GetType()";
		return attr_targetgroup;
	}

	void ReadAttr( istream& in, unsigned int version ) {
		//cout << endl << "ReadAttr()";
		int len = ReadUShort( in );

		if ( len > 1000 ) {
			throw runtime_error("Unlikley number of links found. (>1000)");
		}

		for (int i = 0; i < len; ++i ) {
			CrossRefAttr * new_attr = new CrossRefAttr( "", _owner, 0, 0xFFFFFFFF );
			new_attr->Read( in, version );
			links.push_back( new_attr );
		}
	}
	void WriteAttr( ostream& out, unsigned int version ) const {
		//cout << endl << "WriteAttr()";
		//Write the number of links
		WriteUShort( ushort(links.size()), out );
		//cout << "Link Group Size:  " << uint(links.size()) << endl;

		if ( links.size() > 1000 ) {
			throw runtime_error("You probably shouldn't write more than 1000 links");
		}

		//Write the block indices
		for ( uint i = 0; i < links.size(); ++i ) {
			links[i]->Write( out, version );
		}
	}
	string asString() const {
		//cout << endl << "asString()";
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		for ( uint i = 0; i < links.size(); ++i ) {
			out << endl << "   " << links[i]->asString();
		}
		if (links.size() == 0 ) {
			out << "None";
		}

		return out.str();
	}

	bool HasLinks() const { 
		//cout << endl << "HasLinks()";
		return true;
	}

	list<blk_ref> asLinkList() const { 
		//cout << endl << "asLinkList()";
		list<blk_ref> out;

		//cout << endl << "Link List size:  " << uint(links.size());
		for ( uint i = 0; i < links.size(); ++i ) {
			//cout << endl << "Link:  " << links[i]->asLink();
			out.push_back( links[i]->asLink() );
		}

		//cout << endl << "Out List Size:  " << uint(out.size());

		return out; 
	}

	void AddLink( blk_ref const & block ) {
		//cout << endl << "AddLink()";
		CrossRefAttr * new_attr = new CrossRefAttr( "", _owner, 0, 0xFFFFFFFF );
		new_attr->Set( block );
		links.push_back( new_attr );
	}

	void AddLinks( list<blk_ref> const & new_links ) {
		//cout << endl << "AddLinks()";
		//Add new list of links
		list<blk_ref>::const_iterator it;
		for (it = new_links.begin(); it != new_links.end(); ++it ) {
			AddLink( *it );
		}
	}

	blk_ref FindLink( string const & block_type ) const {
		//cout << endl << "FindLink()";
		//Find the first link with the requested block type
		for ( uint i = 0; i < links.size(); ++i ) {
			blk_ref found_block = links[i]->asLink();
			if ( found_block->GetBlockType() == block_type ) {
				return found_block;
			}
		}

		//No block was found, so return a null one
		return blk_ref(-1);
	}

	void ClearLinks() { 
		//cout << endl << "ClearLinks()";

		vector<CrossRefAttr*>::iterator it;
		for ( it = links.begin(); it != links.end(); ++it ) {
			delete *it;
		}
		links.clear();
	}

	void RemoveLinks( blk_ref const & block ) {
		cout << endl << "RemoveLinks()";
		//Remove all links that match this block
		vector<CrossRefAttr*>::iterator it;
		for ( it = links.begin(); it != links.end(); ++it ) {
			if ( (*it)->asLink() == block ) {
				delete *it;
				links.erase( it );
			}
		}
	}
	void RemoveCrossLinks( IBlock * block_to_remove ) {
		//cout << endl << "RemoveCrossLinks()";
		vector<CrossRefAttr*>::iterator it;
		for ( it = links.begin(); it != links.end(); ++it ) {
			(*it)->RemoveCrossLinks( block_to_remove );
			if ( (*it)->asLink().is_null() == true ) {
				delete *it;
				links.erase( it );
			}
		}
	}
private:
	vector<CrossRefAttr*> links;
};

class ModifierGroupAttr : public LinkGroupAttr {
public:
	ModifierGroupAttr( string const & name, IBlock * owner ) : LinkGroupAttr( name, owner, first_ver, last_ver ) {}
	~ModifierGroupAttr() {}

	AttrType GetType() const { return attr_modifiergroup; }

	void ReadAttr( istream& in, unsigned int version ) {

		//The only difference is that there is a boolean before this link group
		//bool has_links =
		ReadBool( in, version );

		//if ( has_links || version >= VER_10_2_0_0 ) {
			LinkGroupAttr::ReadAttr( in, version );
		//}
	}
	void WriteAttr( ostream& out, unsigned int version ) const {
		//The only difference is that there is a boolean before this link group
		WriteBool( (links.size() > 0), out, version );

		//if ( links.size() > 0 || version >= VER_10_2_0_0) {
			LinkGroupAttr::WriteAttr( out, version );
		//}

	}
};
*/
class BoundingBoxAttr : public AAttr {
public:
	BoundingBoxAttr( string const & name, IBlock * owner, BoundingBox * data ) : AAttr( name, owner ), _data(data) {}
	~BoundingBoxAttr() {}
	AttrType GetType() const { return attr_bbox; }
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << *_data;

		return out.str();
	}
	BoundingBox asBoundingBox() const { return *_data; }
	void Set(BoundingBox const & n ) { *_data = n; }

private:
	BoundingBox * _data;
};

/*
class ShaderAttr : public LinkAttr {
public:
	ShaderAttr( string const & name, IBlock * owner ) : LinkAttr(name, owner, first_ver, last_ver), isUsed(false) {}
	~ShaderAttr() {}
	AttrType GetType() const { return attr_shader; }
	void ReadAttr( istream& in, unsigned int version ) {
		isUsed = ReadBool( in, version );
		if ( isUsed ) {	
			//Read in shader name
			_shader_name = ReadString( in );

			//Read in unknown link
			LinkAttr::ReadAttr( in, version );
		}
	}
	void WriteAttr( ostream& out, unsigned int version ) const {
		WriteBool( isUsed, out, version );
		if ( isUsed ) {	
			//Write out shader name
			WriteString( _shader_name, out );

			//Write out unknown link
			LinkAttr::WriteAttr( out, version );
		}
	}
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << "Shader:  ";

		if ( isUsed ) {
			out << endl
				<< "   Shader Name:  " << _shader_name << endl
				<< "   Unknown Link:  " << LinkAttr::asLink() << endl;
		} else {
			out << "None" << endl;
		}

		return out.str();
	}

protected:
	bool isUsed;
	string _shader_name;
};
*/

/*class TexSourceAttr : public LinkAttr {
public:
	TexSourceAttr( string const & name, IBlock * owner ) : LinkAttr(name, owner ) {
		data.unknownByte = 0;
		data.useExternal = false;
	}
	~TexSourceAttr() {}
	AttrType GetType() const { return attr_texsource; }
	void ReadAttr( istream& in, unsigned int version ) {
		data.useExternal = ( ReadByte(in) != 0);

		//All data is always read after version 10.1.0.0
		if ( version >= VER_10_1_0_0 ) {
			data.fileName = ReadString( in );
			LinkAttr::ReadAttr( in, version );

		} else if ( data.useExternal ) {
			data.fileName = ReadString( in );
		} else {
			//Unknown byte exists up to version 10.0.1.0
			if ( version <= VER_10_0_1_0 ) {
				data.unknownByte = ReadByte ( in );
			}

			//Read link for Pixel Data
			LinkAttr::ReadAttr( in, version );
		}
	}
	void WriteAttr( ostream& out, unsigned int version ) const {
		WriteByte( byte(data.useExternal), out );

		//All data is always written after version 10.1.0.0
		if ( version >= VER_10_1_0_0 ) {
			WriteString( data.fileName, out );
			LinkAttr::WriteAttr( out, version );

		} else if ( data.useExternal ) {
			WriteString( data.fileName, out );
		} else {
			//Unknown byte exists up to version 10.0.1.0
			if ( version <= VER_10_0_1_0 ) {
				WriteByte ( data.unknownByte, out );
			}

			//Write link for Pixel Data
			LinkAttr::WriteAttr( out, version );
		}
	}
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << endl
			<< "   Location:  ";

		if ( data.useExternal ) {
			out << "External";
		} else {
			out << "Internal";
		}

        out << endl
			<< "   File Name:  " << data.fileName << endl
			<< "   Unknown Byte:  " << int(data.unknownByte) << endl
			<< "   Pixel Data:  " << asLink();

		return out.str();
	}
	TexSource asTexSource() const { return data; }
	void Set( TexSource const &n ) {
		data.useExternal = n.useExternal;
		data.unknownByte = n.unknownByte;
		data.fileName = n.fileName;
	}
private:
	TexSource data;
};*/

/*class ControllerTargetAttr : public AAttr {
public:
	ControllerTargetAttr( string const & name, IBlock * owner ) : AAttr(name, owner, first_ver, last_ver) {}
	~ControllerTargetAttr() {}
	AttrType GetType() const { return attr_controllertarget; }
	void ReadAttr( istream& in, unsigned int version ) {
		ReadUInt(in);
	}
	void WriteAttr( ostream& out, unsigned int version ) const {
		//WriteUInt( FindTarget()->GetBlockNum(), out );
		WriteUInt( FindTarget().get_index(), out ); // we need get_index(), GetBlockNum() chokes on null block references
	}
	blk_ref FindTarget() const {
		//Find first ancestor that is controllable
		blk_ref block(_owner);
		blk_ref par;
		while ( true ) {
			//Get parent
			par = block->GetParent();

			//If parent is null, we're done - there are no node ancestors so return a null reference
			if (par.is_null() == true)
				return blk_ref(-1);

			// If parent is NiSequenceStreamHelper, return null reference (this is necessary to create consistent XKf files)
			if ( par->GetBlockType() == "NiSequenceStreamHelper" )
				return blk_ref(-1);

			//If parent is controllable, return it
			if ( par->IsControllable() == true )
				return par;

			//We didn't find a controllable object this time, set block to par and try again
			block = par;
		}
	}
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << FindTarget();

		return out.str();
	}
	blk_ref asLink() const { return FindTarget(); }
	void Set(blk_ref const &) { throw runtime_error("The attribute you tried to set is calculated automatically.  You cannot change it directly."); }

};*/

/*class EmitterObjectAttr : public AAttr {
public:
	EmitterObjectAttr( string const & name, IBlock * owner ) : AAttr(name, owner, first_ver, last_ver) {}
	~EmitterObjectAttr() {}
	AttrType GetType() const { return attr_emitterobject; }
	void ReadAttr( istream& in, unsigned int version ) {
		ReadUInt(in);
	}
	void WriteAttr( ostream& out, unsigned int version ) const {
		//WriteUInt( FindTarget()->GetBlockNum(), out );
		WriteUInt( FindTarget().get_index(), out ); // we need get_index(), GetBlockNum() chokes on null block references
	}
	blk_ref FindTarget() const {
		//Find first ancestor that is a node
		blk_ref block(_owner);
		blk_ref par;
		while ( true ) {
			//Get parent
			par = block->GetParent();

			//If parent is null, we're done - there are no node ancestors so return a null reference
			if (par.is_null() == true)
				return blk_ref(-1);

			// If parent is NiSequenceStreamHelper, return null reference (this is necessary to create consistent XKf files)
			if ( par->GetBlockType() == "NiSequenceStreamHelper" )
				return blk_ref(-1);

			//If parent is a node, return it
			if ( QueryNode( par ) != NULL )
				return par;

			//We didn't find a node this time, set block to par and try again
			block = par;
		}
	}
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << FindTarget();

		return out.str();
	}
	blk_ref asLink() const { return FindTarget(); }
	void Set(blk_ref const &) { throw runtime_error("The attribute you tried to set is calculated automatically.  You cannot change it directly."); }

};*/

/*class SelfLinkAttr : public AAttr {
public:
	SelfLinkAttr( string const & name, IBlock * owner ) : AAttr(name, owner, first_ver, last_ver) {}
	~SelfLinkAttr() {}
	AttrType GetType() const { return attr_emitterobject; }
	void ReadAttr( istream& in, unsigned int version ) {
		ReadUInt(in);
	}
	void WriteAttr( ostream& out, unsigned int version ) const {
		//WriteUInt( FindTarget()->GetBlockNum(), out );
		WriteUInt( _owner->GetBlockNum(), out );
	}
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << blk_ref(_owner) << endl;

		return out.str();
	}
	blk_ref asLink() const { return blk_ref(_owner); }
	void Set(blk_ref const &) { throw runtime_error("The attribute you tried to set is calculated automatically.  You cannot change it directly."); }

};

class SkeletonRootAttr : public AAttr {
public:
	SkeletonRootAttr( string const & name, IBlock * owner ) : AAttr(name, owner, first_ver, last_ver) {}
	~SkeletonRootAttr() {}
	AttrType GetType() const { return attr_skeletonroot; }
	void ReadAttr( istream& in, unsigned int version ) {
		original_root = ReadUInt( in );  //Read data but do nothing with it
	}
	void WriteAttr( ostream& out, unsigned int version ) const {
		WriteUInt( FindRoot().get_index(), out );
	}
	blk_ref FindRoot() const {
		//Find Skeleton Root - first node in ancestry of any bone that has 'not a skin influence' flag set
		
		//Get skin data to find a bone
		blk_ref skin_dat_blk = _owner->GetAttr("Data");

		//If there is no skin data, return a null block
		if ( skin_dat_blk.is_null() == true || skin_dat_blk.is_fixed() == false ) {
			return blk_ref(-1);
		}

		//Get bones from skin data
		ISkinData * skin_dat_int = QuerySkinData(skin_dat_blk);
		vector<blk_ref> bones = skin_dat_int->GetBones();

		//If size of bones is zero, return a null block
		if ( bones.size() == 0 ) {
			return blk_ref(-1);
		}

		//Arbitrarily start at the first bone in the list, and get it's ancestors
		// We want to get the closest common ancestor between the _owner and the bones
		// So start with a list of ancestors of the first bone (this is just a random choice)
		blk_ref block = bones[0];
		blk_ref par = block->GetParent();
		list<blk_ref> bone_pars;
		while ( par.is_null() == false ) {
			bone_pars.push_front(par);
			par = par->GetParent();
		};
		
		// There is something odd going on with some of the DAoC files:
		// all bones would refer to the scene root (see Atlantis/figures/fig03/lbody08_hig_m.nif).
		// In this case the skeleton root also refers to the scene root; let's cover this case here.
		if (bone_pars.empty()) return blk_ref(bones[0]);
		
		// Now do the same with the owner.
		block = _owner;
		par = block->GetParent();
		list<blk_ref> owner_pars;
		while ( par.is_null() == false ) {
			owner_pars.push_front(par);
			par = par->GetParent();
		};
		// Now find closest common ancestor.
		if ( owner_pars.empty() )
			throw runtime_error("Owner has no parents (invalid NIF file?). Cannot set skeleton root.");
		blk_ref skelroot;
		list<blk_ref>::const_iterator bone_par_it = bone_pars.begin();
		list<blk_ref>::const_iterator owner_par_it = owner_pars.begin();
		while ( *bone_par_it == *owner_par_it ) {
			skelroot = *bone_par_it;
			bone_par_it++;
			owner_par_it++;
		};
		if ( skelroot.is_null() )
			throw runtime_error("Skinning instance has no common parent with the bones it refers to (invalid NIF file?). Cannot set skeleton root.");
		return skelroot;
		/*NEW CODE END*/
		/*OLD CODE BEGIN
		blk_ref block = bones[0];
		blk_ref par;
		int flags;
		while ( true ) {
			//Get parent
			par = block->GetParent();

			//If parent is null, we're done - every node is an influence or there are no nodes
			//Probably shouldn't happen
			if (par.is_null() == true) {
				return block;

			}

			//If parent is a node and its 'not a skin influence' flag is set, it is the root for this skeleton
			if ( par->QueryInterface(ID_NODE) != NULL ) {
				flags = par->GetAttr("Flags")->asInt();

				if ( (flags & 8) != 0 ) {
					// extra check: skeleton root cannot be a bone (this fixes the BabelFish.nif problem)
					int par_is_bone = false;
					for ( vector<blk_ref>::const_iterator it = bones.begin(); it != bones.end(); ++it) {
						if ( *it == par ) {
							par_is_bone = true;
							break;
						};
					}
					if ( ! par_is_bone ) return par;
				}
			}

			//We didn't find the root this time, set block to par and try again
			block = par;
		}
		//OLD CODE END
	}
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		blk_ref root;
		root = FindRoot();
		out << root;

		return out.str();
	}
	blk_ref asLink() const { return FindRoot(); }
	void Set(blk_ref const &) { throw runtime_error("The attribute you tried to set is calculated automatically.  You cannot change it directly."); }

private:
	int original_root;
};

class ParentAttr : public AAttr {
public:
	ParentAttr( string const & name, IBlock * owner ) : AAttr(name, owner, first_ver, last_ver) {}
	~ParentAttr() {}
	AttrType GetType() const { return attr_parent; }
	void ReadAttr( istream& in, unsigned int version ) {
		ReadUInt(in);
	}
	void WriteAttr( ostream& out, unsigned int version ) const {
		WriteUInt( _owner->GetParent()->GetBlockNum(), out );
	}
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << _owner->GetParent();

		return out.str();
	}
	blk_ref asLink() const { return _owner->GetParent(); }
	void Set(blk_ref const &) { throw runtime_error("The attribute you tried to set is calculated automatically.  You cannot change it directly."); }
};

class ParticleGroupAttr : public AAttr {
public:
	ParticleGroupAttr( string const & name, IBlock * owner ) : AAttr(name, owner, first_ver, last_ver) {}
	~ParticleGroupAttr() {}
	AttrType GetType() const { return attr_particlegroup; }

	void ReadAttr( istream& in, unsigned int version ) {
		num_particles = ReadUShort( in );
		num_valid = ReadUShort( in );

		particles.resize(num_particles);
		for ( int i = 0; i < num_particles; ++i ) {
			for (int c = 0; c < 3; ++c) {
				for (int r = 0; r < 3; ++r) {
					particles[i].unk_matrix[r][c] = ReadFloat( in );
				}
			}
			particles[i].unk_short = ReadUShort( in );
			particles[i].vert_id = ReadUShort( in );
		}
	}

	void WriteAttr( ostream& out, unsigned int version ) const {
		WriteUShort( num_particles, out );
		WriteUShort( num_valid, out );

		for ( int i = 0; i < num_particles; ++i ) {
			for (int c = 0; c < 3; ++c) {
				for (int r = 0; r < 3; ++r) {
					WriteFloat( particles[i].unk_matrix[r][c], out );
				}
			}

			WriteUShort( particles[i].unk_short, out );
			WriteUShort( particles[i].vert_id, out );
		}
	}

	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << "Num Particles:  " << num_particles << endl
			<< "Num Valid:  " << num_valid << endl
			<< "Particles:" << endl;

		for ( int i = 0; i < num_particles; ++i ) {
			out << "   Particle " << i << ":" << endl;
			const Matrix33 & m = particles[i].unk_matrix;
			out << "      |" << setw(6) << m[0][0] << "," << setw(6) << m[0][1] << "," << setw(6) << m[0][2] << " |" << endl
				<< "      |" << setw(6) << m[1][0] << "," << setw(6) << m[1][1] << "," << setw(6) << m[1][2] << " |" << endl
				<< "      |" << setw(6) << m[2][0] << "," << setw(6) << m[2][1] << "," << setw(6) << m[2][2] << " |" << endl;

			out << "      Unknown Short:  " << particles[i].unk_short << endl
				<< "      Vertex ID:  " << particles[i].vert_id << endl;
		}
		return out.str();
	}
	
private:
	struct Particle {
		Matrix33 unk_matrix;
		short unk_short;
		short vert_id;
	};
	short num_particles;
	short num_valid;
	vector<Particle> particles;
};



class LODInfoAttr : public LinkAttr {
public:
	LODInfoAttr( string const & name, IBlock * owner ) : LinkAttr(name, owner, first_ver, last_ver) {}
	~LODInfoAttr() {}
	AttrType GetType() const { return attr_lodinfo; }

	void ReadAttr( istream& file, unsigned int version ) {
		NifStream( _type, file );
		if ( _type == 0 ) {
			NifStream( _center, file );
			int numRanges = ReadUInt( file );
			ranges.resize( numRanges );
			NifStream( ranges, file );
		} else {
			NifStream( _unk_short, file );
			LinkAttr::ReadAttr( file, version );
		}
	}

	void WriteAttr( ostream& file, unsigned int version ) const {
		NifStream( _type, file );
		if ( _type == 0 ) {
			NifStream( _center, file );
			WriteUInt( uint(ranges.size()), file );
			NifStream( ranges, file );
		} else {
			NifStream( _unk_short, file );
			LinkAttr::WriteAttr( file, version );
		}
	}

	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << "   LOD Info Type:  " << _type << endl;

		if ( _type == 0 ) {
			out << "   LOD Center:  (" << _center.x << ", " << _center.y << ", " << _center.z << ")" << endl;

			out << uint(ranges.size()) << endl;

			for ( uint i = 0; i < ranges.size(); ++i ) {
				out << "   " << i + 1 << ")   Near:  " << ranges[i].near << "   Far:  " << ranges[i].far << endl;
			}
		} else {
			out << "Unknown Short:  " << _unk_short << endl
				<< "Range Group Link:  " << LinkAttr::asString() << endl;
		}

		return out.str();
	}
	
private:
	uint _type;
	Vector3 _center;
	vector<LODRange> ranges;
	ushort _unk_short;
};


class Unk292BytesAttr : public AAttr {
public:
	Unk292BytesAttr( string const & name, IBlock * owner ) : AAttr( name, owner ) {
		for ( int i = 0; i < 256; ++i ) {
			data[i] = 0;
		}
		//memset( data, 0, 256 );
	}
	~Unk292BytesAttr() {}
	AttrType GetType() const { return attr_unk292bytes; }
	void ReadAttr( istream& in, unsigned int version ) {
		in.read( (char*)data, 256 );
	}
	void WriteAttr( ostream& out, unsigned int version ) const {
		out.write( (char*)data, 265 );
	}
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << "Unknown Data (256 bytes):" << endl;
	
		//Display Data in Hex form
		out << hex << setfill('0');
		for (int j = 0; j < 256; j++) {
			out << uppercase << setw(2) << uint(data[j]);
			if (j % 16 == 15 || j == 256 - 1)
				out << endl;
			else if (j % 16 == 7)
				out << "   ";
			else if (j % 8 == 3)
				out << "  ";
			else
				out << " ";
		}
		out << dec << setfill(' ');

		//Display data as a string
		out << "As String:  ";
		for (int j = 0; j < 256; j++ ) {
			if ( data[j] == 0 ) {
				out << endl;
			} else if ( data[j] == 0xCD ) {
				break;
			} else {
				out << data[j];
			}
		}

		return out.str();
	}
protected:
	byte data[256];
};*/


#endif
