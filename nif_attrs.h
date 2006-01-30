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
#include "niflib.h"
#include "NIF_Blocks.h"
#include "NIF_IO.h"

#define endl "\r\n"

const char ATTRERR[] = "Attribute type Missmatch.";

class AAttr : public IAttr {
public:
	AAttr( string const & name, IBlock * owner, unsigned int first_ver, unsigned int last_ver ) : _name(name), _owner(owner), _first_ver(first_ver), _last_ver(last_ver) {}
	~AAttr() {} //cout << "   Attribute \"" << _name << "\" deleted" << endl; }
	string GetName() const { return _name; }
	//Getters
	int asInt() const { throw runtime_error(ATTRERR); }
	float asFloat() const { throw runtime_error(ATTRERR); }
	Float3 asFloat3() const { throw runtime_error(ATTRERR); }
	Matrix33 asMatrix33() const { throw runtime_error(ATTRERR); }
	blk_ref asLink() const { throw runtime_error(ATTRERR); }
	TexSource asTexSource() const { throw runtime_error(ATTRERR); }
	BoundingBox asBoundingBox() const { throw runtime_error(ATTRERR); }
	ConditionalInt asConditionalInt() const { throw runtime_error(ATTRERR); }
	TexDesc asTexDesc() const { throw runtime_error(ATTRERR); }
	list<blk_ref> asLinkList() const { throw runtime_error(ATTRERR); }
	//Setters
	void Set(int) { throw runtime_error(ATTRERR); }
	void Set(float) { throw runtime_error(ATTRERR); }
	void Set(Float3 const &) { throw runtime_error(ATTRERR); }
	void Set(string const &) { throw runtime_error(ATTRERR); }
	void Set(Matrix33 const &) { throw runtime_error(ATTRERR); }
	void Set(blk_ref const &) { throw runtime_error(ATTRERR); }
	void Set(TexSource const &) { throw runtime_error(ATTRERR); }
	void Set(BoundingBox const &) { throw runtime_error(ATTRERR); }
	void Set(ConditionalInt const &) { throw runtime_error(ATTRERR); }
	void Set(TexDesc const &) { throw runtime_error(ATTRERR); }
	//Link functions
	bool HasLinks() const { return false; }
	void AddLink( blk_ref const & block ) { cout << "AddLink" << endl; throw runtime_error(ATTRERR); }
	void AddLinks( list<blk_ref> const & new_links ) { cout << "AddLinkS" << endl; throw runtime_error(ATTRERR); }
	void ClearLinks() { cout << "ClearLinks" << endl; throw runtime_error(ATTRERR); }
	void RemoveLinks( blk_ref const & block ) { cout << "RemoveLinks" << endl; throw runtime_error(ATTRERR); }
	blk_ref FindLink( string const & block_type ) const { cout << "FindLink" << endl; throw runtime_error(ATTRERR); }
	//Read/WriteFunctions
	void Read( ifstream& in, unsigned int version ) {
		if ( version >= _first_ver && version <= _last_ver ) {
			this->ReadAttr( in, version );
		}
	}
	void Write( ofstream& out, unsigned int version ) const {
		if ( version >= _first_ver && version <= _last_ver ) {
			this->WriteAttr( out, version );
		}
	}
protected:
	//Internal Read/Write Functions
	virtual void ReadAttr( ifstream& in, unsigned int version ) = 0;
	virtual void WriteAttr( ofstream& out, unsigned int version ) const = 0;

	string _name;
	IBlock * _owner;
	unsigned int _first_ver, _last_ver;
};

class lnk_ref : public blk_ref {
public:
	lnk_ref ( IBlock * owner) : _owner(owner) { /*cout << "Constructor " <<  endl;*/ InitLink(); }
	lnk_ref( IBlock * owner, int index ) : blk_ref(index), _owner(owner) { /*cout << "Constructor "  << endl;*/ InitLink(); }
	lnk_ref( IBlock * owner, blk_ref block ) : blk_ref(block), _owner(owner) { /*cout << "Constructor " << endl;*/ InitLink(); }

	//Copy Constructors
	lnk_ref( const lnk_ref & rh ) {
		/*cout << "Copy constructor " << endl;*/
		//Kill previous link
		KillLink();
		_owner = rh._owner;
		blk_ref::operator=(rh);
		//Set New Link
		InitLink();
	}
	//Destructor
	~lnk_ref() { /*cout << "Destructor " << endl;*/ KillLink(); /*cin.get();*/}
	//Assignment Operator
	lnk_ref & operator=(const blk_ref & rh ) { 
		if ( blk_ref(*this)!= rh ) {
			//Kill previous link
			KillLink();
			blk_ref::operator=(rh);
			//Set New Link
			InitLink();
		}

		return *this;
	}
	void set_block( IBlock * block ) {
		/*cout << "set_block " << endl;*/
		//Use assignment operator code
		operator=( blk_ref(block) );
	}
	void set_index( int index ) { 
		/*cout << "set_index " << endl;*/
		//Use assigntment operator code
		operator=( blk_ref(index) );
	}
	IBlock * owner() const {
		if ( _owner == NULL ) {
			throw runtime_error("Link reference owner is NULL.");
		} else {
			return _owner;
		}
	}

private:
	IBlock * _owner;
	void InitLink() {
		//cout << "+ Reference " << this << endl;
		//Add parent at new link site
		if ( _block != NULL ) {
			//Get internal interface
			((ABlock*)_block)->AddParent( _owner );
			//IBlockInternal * bk_intl = (IBlockInternal*)_block->QueryInterface( BlockInternal );
			//if ( bk_intl != NULL ) {
			//	bk_intl->AddParent( _owner );
			//}
		}
	}
	void KillLink() {
		//cout << "- Reference " << this << endl;
		//Remove cross-reference at previous location
		if ( _block != NULL ) {
			((ABlock*)_block)->RemoveParent( _owner );
			//Get internal interface
			//IBlockInternal * bk_intl = (IBlockInternal*)_block->QueryInterface( BlockInternal );
			//if ( bk_intl != NULL ) {
			//	bk_intl->RemoveParent( _owner );
			//}
		}
	}
	lnk_ref( const blk_ref & rh ); // Intentionally Undefined
};

class IntAttr : public AAttr {
public:
	IntAttr( string const & name, IBlock * owner, unsigned int first_ver, unsigned int last_ver ) : AAttr( name, owner, first_ver, last_ver ), data(0) {}
	~IntAttr() {}
	AttrType GetType() const { return attr_int; }
	void ReadAttr( ifstream& in, unsigned int version ) { data = ReadUInt( in ); }
	void WriteAttr( ofstream& out, unsigned int version ) const { WriteUInt( data, out ); }
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << data;

		return out.str();
	}
	int asInt() const { return data; }
	void Set(int n ) { data = n; }
protected:
	int data;
};

class ShortAttr : public AAttr {
public:
	ShortAttr( string const & name, IBlock * owner, unsigned int first_ver, unsigned int last_ver ) : AAttr( name, owner, first_ver, last_ver ), data(0) {}
	~ShortAttr() {}
	AttrType GetType() const { return attr_short; }
	void ReadAttr( ifstream& in, unsigned int version ) { data = ReadUShort( in ); }
	void WriteAttr( ofstream& out, unsigned int version ) const { WriteUShort( data, out ); }
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << data;

		return out.str();
	}
	int asInt() const { return int(data); }
	void Set(int n ) { data = short(n); }
private:
	short data;
};

class ByteAttr : public AAttr {
public:
	ByteAttr( string const & name, IBlock * owner, unsigned int first_ver, unsigned int last_ver ) : AAttr( name, owner, first_ver, last_ver ), data(0) {}
	~ByteAttr() {}
	AttrType GetType() const { return attr_byte; }
	void ReadAttr( ifstream& in, unsigned int version ) { data = ReadByte( in ); }
	void WriteAttr( ofstream& out, unsigned int version ) const { WriteByte( data, out ); }
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << int(data);

		return out.str();
	}
	int asInt() const { return int(data); }
	void Set(int n ) { data = char(n); }
private:
	char data;
};

class BoolAttr : public AAttr {
public:
	BoolAttr( string const & name, IBlock * owner, unsigned int first_ver, unsigned int last_ver ) : AAttr( name, owner, first_ver, last_ver ), data(0) {}
	~BoolAttr() {}
	AttrType GetType() const { return attr_bool; }
	void ReadAttr( ifstream& in, unsigned int version ) { data = ReadBool( in, version ); }
	void WriteAttr( ofstream& out, unsigned int version ) const { WriteBool( data, out, version ); }
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << int(data);

		return out.str();
	}
	int asInt() const { return int(data); }
	void Set(int n ) { data = (n != 0); }
private:
	bool data;
};

class FloatAttr : public AAttr {
public:
	FloatAttr( string const & name, IBlock * owner, unsigned int first_ver, unsigned int last_ver ) : AAttr( name, owner, first_ver, last_ver ), data(0.0f) {}
	~FloatAttr() {}
	AttrType GetType() const { return attr_float; }
	void ReadAttr( ifstream& in, unsigned int version ) { data = ReadFloat( in ); }
	void WriteAttr( ofstream& out, unsigned int version ) const { WriteFloat( data, out ); }
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << data;

		return out.str();
	}
	float asFloat() const { return data; }
	void Set(float n ) { data = n; }
private:
	float data;
};

class Float3Attr : public AAttr {
public:
	Float3Attr( string const & name, IBlock * owner, unsigned int first_ver, unsigned int last_ver) : AAttr(name, owner, first_ver, last_ver) {
		data[0] = 0.0f;
		data[1] = 0.0f;
		data[2] = 0.0f;
	}
	~Float3Attr() {}
	AttrType GetType() const { return attr_float3; }
	void ReadAttr( ifstream& in, unsigned int version ) { 
		data[0] = ReadFloat( in );
		data[1] = ReadFloat( in );
		data[2] = ReadFloat( in );
	}
	void WriteAttr( ofstream& out, unsigned int version ) const {
		WriteFloat( data[0], out );
		WriteFloat( data[1], out );
		WriteFloat( data[2], out );
	}
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << "(" << setw(5) << data[0] << ", " << setw(5) << data[1] << ", " << setw(5) << data[2] << " )";
		
		return out.str();
	}
	Float3 asFloat3() const { return data; }
	void Set(Float3 const & n) { data = n; }
private:
	Float3 data;
};

class Vector3Attr : public Float3Attr {
public:
	Vector3Attr( string const & name, IBlock * owner, unsigned int first_ver, unsigned int last_ver) : Float3Attr(name, owner, first_ver, last_ver) {}
	~Vector3Attr() {}
	AttrType GetType() const { return attr_vector3; }
};

class Color3Attr : public Float3Attr {
public:
	Color3Attr( string const & name, IBlock * owner, unsigned int first_ver, unsigned int last_ver) : Float3Attr(name, owner, first_ver, last_ver) {}
	~Color3Attr() {}
	AttrType GetType() const { return attr_color3; }
};

class StringAttr : public AAttr {
public:
	StringAttr( string const & name, IBlock * owner, unsigned int first_ver, unsigned int last_ver ) : AAttr( name, owner, first_ver, last_ver ) {}
	~StringAttr() {}
	AttrType GetType() const { return attr_string; }
	void ReadAttr( ifstream& in, unsigned int version ) { data = ReadString( in ); }
	void WriteAttr( ofstream& out, unsigned int version ) const { WriteString( data, out ); }
	string asString() const { return data; }
	void Set(string const & n) { data = n; }
private:
	string data;
};

class LinkAttr : public AAttr {
public:
	LinkAttr( string const & name, IBlock * owner, unsigned int first_ver, unsigned int last_ver ) : AAttr( name, owner, first_ver, last_ver ), link( owner ) {}
	~LinkAttr() {}
	AttrType GetType() const { return attr_link; }
	void ReadAttr( ifstream& in, unsigned int version ) {
		////Remove all links beloning to this attribute
		//_owner->RemoveAttrLinks(this);

		////Add a new link with read in link
		//blk_link l;
		//l.attr = this;
		//l.block = ReadUInt( in );
		//_owner->AddLink(l);

		//Set block index only
		link.set_index( ReadUInt( in ) );
	}
	void WriteAttr( ofstream& out, unsigned int version ) const {
		WriteUInt( link.get_index(), out );
	}
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << link;

		return out.str();
	}
	bool HasLinks() const { return true; }
	list<blk_ref> asLinkList() const { 
		list<blk_ref> out;

		out.push_back( blk_ref(link) );

		return out; 
	}
	void ClearLinks() { link = blk_ref(-1); }
	void AddLinks( list<blk_ref> const & new_links ) {
		//Just take the first one
		link = *(new_links.begin());
	}

	blk_ref asLink() const { return blk_ref(link); }
	void Set( blk_ref const & n ) { link = n; }
private:
	lnk_ref link;
};

class FlagsAttr : public AAttr {
public:
	FlagsAttr( string const & name, IBlock * owner, unsigned int first_ver, unsigned int last_ver ) : AAttr( name, owner, first_ver, last_ver ), data(0) {}
	~FlagsAttr() {}
	AttrType GetType() const { return attr_flags; }
	void ReadAttr( ifstream& in, unsigned int version ) { data = ReadUShort( in ); }
	void WriteAttr( ofstream& out, unsigned int version ) const { WriteUShort( data, out ); }
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

class MatrixAttr : public AAttr {
public:
	MatrixAttr( string const & name, IBlock * owner, unsigned int first_ver, unsigned int last_ver ) : AAttr( name, owner, first_ver, last_ver ) {
		data[0][0] = 1.0f;	data[0][1] = 0.0f;	data[0][2] = 0.0f;
		data[1][0] = 0.0f;	data[1][1] = 1.0f;	data[1][2] = 0.0f;
		data[2][0] = 0.0f;	data[2][1] = 0.0f;	data[2][2] = 1.0f;
	}
	~MatrixAttr() {}
	AttrType GetType() const { return attr_matrix33; }
	void ReadAttr( ifstream& in, unsigned int version ) { 
		for (int c = 0; c < 3; ++c) {
			for (int r = 0; r < 3; ++r) {
				data[r][c] = ReadFloat( in );
			}
		}
	}
	void WriteAttr( ofstream& out, unsigned int version ) const {
		for (int c = 0; c < 3; ++c) {
			for (int r = 0; r < 3; ++r) {
				WriteFloat( data[r][c], out );
			}
		}
	}
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << endl
			<< "   |" << setw(6) << data[0][0] << "," << setw(6) << data[0][1] << "," << setw(6) << data[0][2] << " |" << endl
			<< "   |" << setw(6) << data[1][0] << "," << setw(6) << data[1][1] << "," << setw(6) << data[1][2] << " |" << endl
			<< "   |" << setw(6) << data[2][0] << "," << setw(6) << data[2][1] << "," << setw(6) << data[2][2] << " |";
		
		return out.str();
	}
	Matrix33 asMatrix33() const {
		return data;
		//for (int c = 0; c < 3; ++c) {
		//	for (int r = 0; r < 3; ++r) {
		//		out[r][c] = data[r][c];
		//	}
		//}
	}
	void Set( Matrix33 const & n ) {
		for (int c = 0; c < 3; ++c) {
			for (int r = 0; r < 3; ++r) {
				data[r][c] = n[r][c];
			}
		}
	}

	//vector<float> asFloatList() const {
	//	vector<float> list(9);
	//	list[0] = data[0][0];	list[1] = data[0][1];	list[2] = data[0][2];
	//	list[0] = data[1][0];	list[1] = data[1][1];	list[2] = data[1][2];
	//	list[0] = data[2][0];	list[1] = data[2][1];	list[2] = data[2][2];
	//	return list;
	//}
	//void Set(vector<float> n ) {
	//	if ( n.size() != 9)
	//		throw runtime_error("List size must equal 9");

	//	data[0][0] = n[0];	data[0][1] = n[1];	data[0][2] = n[2];
	//	data[1][0] = n[0];	data[1][1] = n[1];	data[1][2] = n[2];
	//	data[2][0] = n[0];	data[2][1] = n[1];	data[2][2] = n[2];
	//}
private:
	Matrix33 data;
};

class BoneAttr : public AAttr {
public:
	BoneAttr( string const & name, IBlock * owner, unsigned int first_ver, unsigned int last_ver ) : AAttr(name, owner, first_ver, last_ver) {}
	~BoneAttr() {}
	AttrType GetType() const { return attr_bones; }
	void ReadAttr( ifstream& in, unsigned int version ) {
		ISkinInstInternal * data = (ISkinInstInternal*)_owner->QueryInterface( SkinInstInternal );
		if ( data != NULL ) {
			data->ReadBoneList( in );
		} else {
			throw runtime_error ("Attempted to use a bone list attribute on a block that doesn't support it.");
		}
	}
	void WriteAttr( ofstream& out, unsigned int version ) const {
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

typedef list<lnk_ref> LinkSetList;
typedef LinkSetList::iterator LinkSetIt;
typedef LinkSetList::const_iterator LinkSetConstIt;

class LinkGroupAttr : public AAttr {
public:
	LinkGroupAttr( string const & name, IBlock * owner, unsigned int first_ver, unsigned int last_ver ) : AAttr( name, owner, first_ver, last_ver ) {}
	~LinkGroupAttr() {}
	AttrType GetType() const { return attr_linkgroup; }
	void ReadAttr( ifstream& in, unsigned int version ) {
		int len = ReadUInt( in );
		//cout << "Link Group Size:  " << len << endl;

		if ( len > 1000 ) {
			throw runtime_error("Unlikley number of links found. (>1000)");
		}

		for (int i = 0; i < len; ++i ) {
			int index = ReadUInt( in );
			if (index != -1 )
				AddLink( blk_ref( index ) );
		}
	}
	void WriteAttr( ofstream& out, unsigned int version ) const {
		//Write the number of links
		WriteUInt( uint(links.size()), out );
		//cout << "Link Group Size:  " << uint(links.size()) << endl;

		if ( links.size() > 1000 ) {
			throw runtime_error("You probably shouldn't write more than 1000 links");
		}

		//Write the block indices
		for (LinkSetConstIt it = links.begin(); it != links.end(); ++it ) {
			WriteUInt( it->get_index(), out );
		}
	}
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		for (LinkSetList::const_iterator it = links.begin(); it != links.end(); ++it ) {
			out << endl << "   " << *it;
		}
		if (links.size() == 0 ) {
			out << "None";
		}

		return out.str();
	}

	bool HasLinks() const { return true; }

	list<blk_ref> asLinkList() const { 
		list<blk_ref> out;

		for (LinkSetList::const_iterator it = links.begin(); it != links.end(); ++it ) {
			out.push_back( blk_ref(*it) );
		}

		return out; 
	}

	void AddLink( blk_ref const & block ) {
		links.push_back( lnk_ref(_owner, block) );
	}

	void AddLinks( list<blk_ref> const & new_links ) {
		//Add new list of links
		list<blk_ref>::const_iterator it;
		for (it = new_links.begin(); it != new_links.end(); ++it ) {
			lnk_ref l(_owner, *it );
			try {
				links.push_back( l );
			}
			catch( exception & e ) {
				cout << "Error:  " << e.what() << endl;
			}
		}
	}

	blk_ref FindLink( string const & block_type ) const {
		//Find the first link with the requested block type
		for (LinkSetList::const_iterator it = links.begin(); it != links.end(); ++it ) {
			if ( (*it)->GetBlockType() == block_type )
				return blk_ref(*it);
		}

		//No block was found, so return a null one
		return blk_ref(-1);
	}

	void ClearLinks() { links.clear(); }

	void RemoveLinks( blk_ref const & block ) {
		//Remove all links that match this block
		links.remove( lnk_ref( _owner, block ) );
	}
protected:
	LinkSetList links;
};

class TargetGroupAttr : public LinkGroupAttr {
public:
	TargetGroupAttr( string const & name, IBlock * owner, unsigned int first_ver, unsigned int last_ver ) : LinkGroupAttr( name, owner, first_ver, last_ver ) {}
	~TargetGroupAttr() {}

	AttrType GetType() const { return attr_targetgroup; }

	void ReadAttr( ifstream& in, unsigned int version ) {
		int len = ReadUShort( in );

		if ( len > 1000 ) {
			throw runtime_error("Unlikley number of links found. (>1000)");
		}

		for (int i = 0; i < len; ++i ) {
			int index = ReadUInt( in );
			if (index != -1 )
				AddLink( blk_ref( index ) );
		}
	}
	void WriteAttr( ofstream& out, unsigned int version ) const {
		//Write the number of links
		WriteUShort( ushort(links.size()), out );
		//cout << "Link Group Size:  " << uint(links.size()) << endl;

		if ( links.size() > 1000 ) {
			throw runtime_error("You probably shouldn't write more than 1000 links");
		}

		//Write the block indices
		for (LinkSetConstIt it = links.begin(); it != links.end(); ++it ) {
			WriteUInt( it->get_index(), out );
		}
	}
};

class BBoxAttr : public AAttr {
public:
	BBoxAttr( string const & name, IBlock * owner, unsigned int first_ver, unsigned int last_ver ) : AAttr( name, owner, first_ver, last_ver ) {
		data.isUsed = false;
		
		data.unknownInt = 0;

		data.translation.x = 0.0f;	data.translation.y = 0.0f;	data.translation.z = 0.0f;

		data.rotation[0][0] = 1.0f;	data.rotation[0][1] = 0.0f;	data.rotation[0][2] = 0.0f;
		data.rotation[1][0] = 0.0f;	data.rotation[1][1] = 1.0f;	data.rotation[1][2] = 0.0f;
		data.rotation[2][0] = 0.0f;	data.rotation[2][1] = 0.0f;	data.rotation[2][2] = 1.0f;

		data.radius.x = 0.0f;
		data.radius.y = 0.0f;
		data.radius.z = 0.0f;
	}
	~BBoxAttr() {}
	AttrType GetType() const { return attr_bbox; }
	void ReadAttr( ifstream& in, unsigned int version ) { 
		data.isUsed = ReadBool( in, version );
		if ( data.isUsed ){
			data.unknownInt = ReadUInt( in );
			data.translation.x = ReadFloat( in );
			data.translation.y = ReadFloat( in );
			data.translation.z = ReadFloat( in );
			for (int c = 0; c < 3; ++c) {
				for (int r = 0; r < 3; ++r) {
					data.rotation[r][c] = ReadFloat( in );
				}
			}
			data.radius.x = ReadFloat( in );
			data.radius.y = ReadFloat( in );
			data.radius.z = ReadFloat( in );
		}
	}
	void WriteAttr( ofstream& out, unsigned int version ) const {
		WriteBool( data.isUsed, out, version );
		if ( data.isUsed ){
			WriteUInt( data.unknownInt, out );
			WriteFloat( data.translation.x, out );
			WriteFloat( data.translation.y, out );
			WriteFloat( data.translation.z, out );
			for (int c = 0; c < 3; ++c) {
				for (int r = 0; r < 3; ++r) {
					WriteFloat(data.rotation[r][c], out );
				}
			}
			WriteFloat( data.radius.x, out );
			WriteFloat( data.radius.y, out );
			WriteFloat( data.radius.z, out );
		}
	}
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		if ( data.isUsed ) {
			out << endl
				<< "   Position:  " << "(" << setw(5) << data.translation.x << ", " << setw(5) << data.translation.y << ", " << setw(5) << data.translation.z << " )" << endl
				<< "   Rotation:"  << endl
				<< "      |" << setw(5) << data.rotation[0][0] << ", " << setw(5) << data.rotation[0][1] << ", " << setw(5) << data.rotation[0][2] << " |" << endl
				<< "      |" << setw(5) << data.rotation[1][0] << ", " << setw(5) << data.rotation[1][1] << ", " << setw(5) << data.rotation[1][2] << " |" << endl
				<< "      |" << setw(5) << data.rotation[2][0] << ", " << setw(5) << data.rotation[2][1] << ", " << setw(5) << data.rotation[2][2] << " |" << endl
				<< "   X Radius:  " << data.radius.x << endl
				<< "   Y Radius:  " << data.radius.y << endl
				<< "   Z Radius:  " << data.radius.z;
		} 
		else {
			out << "None";
		}

		return out.str();
	}
	BoundingBox asBoundingBox() const { return data; }
	void Set(BoundingBox const & n ) { data = n; }

private:
	BoundingBox data;
};

class CIntAttr : public AAttr {
public:
	CIntAttr( string const & name, IBlock * owner, unsigned int first_ver, unsigned int last_ver ) : AAttr( name, owner, first_ver, last_ver ) {
		data.isUsed = false;
		data.unknownInt = 0;
	}
	~CIntAttr() {}
	AttrType GetType() const { return attr_condint; }
	void ReadAttr( ifstream& in, unsigned int version ) {
		data.isUsed = ReadBool( in, version );
		if (data.isUsed) {
			data.unknownInt = ReadUInt( in );
		}
	}
	void WriteAttr( ofstream& out, unsigned int version ) const {
		WriteBool( data.isUsed, out, version );
		if (data.isUsed) {
			WriteUInt( data.unknownInt, out );
		}
	}
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		if (data.isUsed) {
			out << data.unknownInt;
		}
		else {
			out << "None";
		}

		return out.str();
	}
	ConditionalInt asConditionalInt() const { return data; }
	void Set(ConditionalInt const & n ) {
		data.isUsed = n.isUsed;
		data.unknownInt = n.unknownInt;
	}
private:
	ConditionalInt data;
};

class VertModeAttr : public IntAttr {
public:
	VertModeAttr( string const & name, IBlock * owner, unsigned int first_ver, unsigned int last_ver ) : IntAttr( name, owner, first_ver, last_ver ) {}
	~VertModeAttr() {}
	AttrType GetType() const { return attr_vertmode; }

	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		switch ( data ) {
			case 0:
				out << "Source Ingore";
				break;
			case 1:
				out << "Source Emmisive";
				break;
			case 2:
				out << "Source Amb Diff";
				break;
			default:
				out << "!Invalid Value! - " << data;
				break;
		}

		return out.str();
	}
};

class LightModeAttr : public IntAttr {
public:
	LightModeAttr( string const & name, IBlock * owner, unsigned int first_ver, unsigned int last_ver ) : IntAttr( name, owner, first_ver, last_ver ) {}
	~LightModeAttr() {}
	AttrType GetType() const { return attr_lightmode; }
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		switch ( data ) {
			case 0:
				out << "Emmisive";
				break;
			case 1:
				out << "Emmisive Amb Diff";
				break;
			default:
				out << "!Invalid Value! - " << data;
				break;
		}

		return out.str();
	}
};



    //int vertex     - vertex mode:
    //                 0 - source ignore
    //                 1 - source emmisive
    //                 2 - source amb diff

    //int light      - lighting mode:
    //                 0 - lighting emmisive
    //  1 - lighting emmisive amb diff

class ShaderAttr : public LinkAttr {
public:
	ShaderAttr( string const & name, IBlock * owner, unsigned int first_ver, unsigned int last_ver ) : LinkAttr(name, owner, first_ver, last_ver), isUsed(false) {}
	~ShaderAttr() {}
	AttrType GetType() const { return attr_shader; }
	void ReadAttr( ifstream& in, unsigned int version ) {
		isUsed = ReadBool( in, version );
		if ( isUsed ) {	
			//Read in shader name
			_shader_name = ReadString( in );

			//Read in unknown link
			LinkAttr::ReadAttr( in, version );
		}
	}
	void WriteAttr( ofstream& out, unsigned int version ) const {
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

class TexSourceAttr : public LinkAttr {
public:
	TexSourceAttr( string const & name, IBlock * owner, unsigned int first_ver, unsigned int last_ver ) : LinkAttr(name, owner, first_ver, last_ver) {
		data.unknownByte = 0;
		data.useExternal = false;
	}
	~TexSourceAttr() {}
	AttrType GetType() const { return attr_texsource; }
	void ReadAttr( ifstream& in, unsigned int version ) {
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
	void WriteAttr( ofstream& out, unsigned int version ) const {
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
};

class PixelLayoutAttr : public IntAttr {
public:
	PixelLayoutAttr( string const & name, IBlock * owner, unsigned int first_ver, unsigned int last_ver ) : IntAttr( name, owner, first_ver, last_ver ) {}
	~PixelLayoutAttr() {}
	AttrType GetType() const { return attr_pixellayout; }

	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		switch ( data ) {
			case 0:
				out << "Palettised";
				break;
			case 1:
				out << "16-bit High Color";
				break;
			case 2:
				out << "32-bit True Color";
				break;
			case 3:
				out << "Compressed";
				break;
			case 4:
				out << "Bump Map";
				break;
			case 5:
				out << "Default";
				break;
			default:
				out << "!Invalid Value! - " << data;
				break;
		}

		return out.str();
	}
};

//typedef enum {
//   PALETTISED = 0,
//   HIGH_COLOR_16 = 1,
//   TRUE_COLOR_32 = 2,
//   COMPRESSED = 3,
//   BUMPMAP = 4,
//   PIX_DEFAULT = 5
//} SMB_PixelLayout;

class MipMapFormatAttr : public IntAttr {
public:
	MipMapFormatAttr( string const & name, IBlock * owner, unsigned int first_ver, unsigned int last_ver ) : IntAttr( name, owner, first_ver, last_ver ) {}
	~MipMapFormatAttr() {}
	AttrType GetType() const { return attr_mipmapformat; }

	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		switch ( data ) {
			case 0:
				out << "No";
				break;
			case 1:
				out << "Yes";
				break;
			case 2:
				out << "Default";
				break;
			default:
				out << "!Invalid Value! - " << data;
				break;
		}

		return out.str();
	}
};

//typedef enum {
//   MIPMAP_NO = 0,
//   MIPMAP_YES = 1,
//   MIPMAP_MIP_DEFAULT = 2,
//} SMB_MipMapFormat;

class AlphaFormatAttr : public IntAttr {
public:
	AlphaFormatAttr( string const & name, IBlock * owner, unsigned int first_ver, unsigned int last_ver ) : IntAttr( name, owner, first_ver, last_ver ) {}
	~AlphaFormatAttr() {}
	AttrType GetType() const { return attr_alphaformat; }

	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		switch ( data ) {
			case 0:
				out << "None";
				break;
			case 1:
				out << "Binary";
				break;
			case 2:
				out << "Smooth";
				break;
			case 3:
				out << "Default";
				break;
			default:
				out << "!Invalid Value! - " << data;
				break;
		}

		return out.str();
	}
};

class ControllerTargetAttr : public AAttr {
public:
	ControllerTargetAttr( string const & name, IBlock * owner, unsigned int first_ver, unsigned int last_ver ) : AAttr(name, owner, first_ver, last_ver) {}
	~ControllerTargetAttr() {}
	AttrType GetType() const { return attr_controllertarget; }
	void ReadAttr( ifstream& in, unsigned int version ) {
		ReadUInt(in);
	}
	void WriteAttr( ofstream& out, unsigned int version ) const {
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

};

class SkeletonRootAttr : public AAttr {
public:
	SkeletonRootAttr( string const & name, IBlock * owner, unsigned int first_ver, unsigned int last_ver ) : AAttr(name, owner, first_ver, last_ver) {}
	~SkeletonRootAttr() {}
	AttrType GetType() const { return attr_skeletonroot; }
	void ReadAttr( ifstream& in, unsigned int version ) {
		original_root = ReadUInt( in );  //Read data but do nothing with it
	}
	void WriteAttr( ofstream& out, unsigned int version ) const {
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

		//Arbitrarily start at the first bone in the list
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
	ParentAttr( string const & name, IBlock * owner, unsigned int first_ver, unsigned int last_ver ) : AAttr(name, owner, first_ver, last_ver) {}
	~ParentAttr() {}
	AttrType GetType() const { return attr_parent; }
	void ReadAttr( ifstream& in, unsigned int version ) {
		ReadUInt(in);
	}
	void WriteAttr( ofstream& out, unsigned int version ) const {
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
	ParticleGroupAttr( string const & name, IBlock * owner, unsigned int first_ver, unsigned int last_ver ) : AAttr(name, owner, first_ver, last_ver) {}
	~ParticleGroupAttr() {}
	AttrType GetType() const { return attr_particlegroup; }

	void ReadAttr( ifstream& in, unsigned int version ) {
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

	void WriteAttr( ofstream& out, unsigned int version ) const {
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



class LODRangeGroupAttr : public AAttr {
public:
	LODRangeGroupAttr( string const & name, IBlock * owner, unsigned int first_ver, unsigned int last_ver ) : AAttr(name, owner, first_ver, last_ver) {}
	~LODRangeGroupAttr() {}
	AttrType GetType() const { return attr_lodrangegroup; }

	void ReadAttr( ifstream& in, unsigned int version ) {
		int numRanges = ReadUInt( in );
		ranges.resize( numRanges );
		for ( uint i = 0; i < ranges.size(); ++i ) {
			ranges[i].near = ReadFloat( in );
			ranges[i].far = ReadFloat( in );		
		}
	}

	void WriteAttr( ofstream& out, unsigned int version ) const {
		WriteUInt( uint(ranges.size()), out );

		for ( uint i = 0; i < ranges.size(); ++i ) {
			WriteFloat( ranges[i].near, out );
			WriteFloat( ranges[i].far, out );		
		}
	}

	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << uint(ranges.size()) << endl;

		for ( uint i = 0; i < ranges.size(); ++i ) {
			out << "   " << i + 1 << ")   Near:  " << ranges[i].near << "   Far:  " << ranges[i].far << endl;
		}

		return out.str();
	}
	
private:
	struct LODRange {
		float near;
		float far;
	};
	vector<LODRange> ranges;
};


class Unk292BytesAttr : public AAttr {
public:
	Unk292BytesAttr( string const & name, IBlock * owner, unsigned int first_ver, unsigned int last_ver ) : AAttr( name, owner, first_ver, last_ver ) {
		for ( int i = 0; i < 256; ++i ) {
			data[i] = 0;
		}
		//memset( data, 0, 256 );
	}
	~Unk292BytesAttr() {}
	AttrType GetType() const { return attr_unk292bytes; }
	void ReadAttr( ifstream& in, unsigned int version ) {
		in.read( (char*)data, 256 );
	}
	void WriteAttr( ofstream& out, unsigned int version ) const {
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
};


#endif
