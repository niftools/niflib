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

#include "NIF_Blocks.h"
#include "nif_attrs.h"
#include "nif_math.h"
#include <cmath>
#include <sstream>

extern bool verbose;
extern unsigned int blocks_in_memory;

#define endl "\r\n"

extern string current_file;

/***********************************************************
 * ABlock methods
 **********************************************************/

ABlock::ABlock() : _ref_count(0), _block_num(-1) {
		//Temporary to test reference counting
		blocks_in_memory++;
	}

ABlock::~ABlock() {
	//Temporary to test reference counting
	//cout << "A block has commited suicide." << endl;
	blocks_in_memory--;

	// Delete all attributes
	for (unsigned int i = 0; i < _attr_vect.size(); ++i ) {
		delete _attr_vect[i].ptr();
	}
}

void ABlock::AddAttr( string type, string name ) {
	IAttr * attr;
	if ( type == "int" ) {
		attr = new IntAttr( name, this );
	} else if ( type == "short" ) {
		attr = new ShortAttr( name, this );
	} else if ( type == "byte" ) {
		attr = new ByteAttr( name, this );
	} else if ( type == "float" ) {
		attr = new FloatAttr( name, this );
	} else if ( type == "float3" ) {
		attr = new Float3Attr( name, this );
	} else if ( type == "string" ) {
		attr = new StringAttr( name, this );
	} else if ( type == "index" ) {
		attr = new IndexAttr( name, this );
	} else if ( type == "flags" ) {
		attr = new FlagsAttr( name, this );
	} else if ( type == "matrix" ) {
		attr = new MatrixAttr( name, this );
	} else if ( type == "linkgroup" ) {
		attr = new LinkGroupAttr( name, this );
	} else if ( type == "bones" ) {
		attr = new BoneAttr( name, this );
	} else if ( type == "bbox" ) {
		attr = new BBoxAttr( name, this );
	} else if ( type == "cint" ) {
		attr = new CIntAttr( name, this );
	} else if ( type == "vertmode" ) {
		attr = new VertModeAttr( name, this );
	} else if ( type == "lightmode" ) {
		attr = new LightModeAttr( name, this );
	} else if ( type == "texture" ) {
		attr = new TextureAttr( name, this );
	} else if ( type == "bumpmap" ) {
		attr = new TextureAttr( name, this, true );
	} else if ( type == "applymode" ) {
		attr = new ApplyModeAttr( name, this );
	} else if ( type == "texsource" ) {
		attr = new TexSourceAttr( name, this );
	} else if ( type == "pixellayout" ) {
		attr = new PixelLayoutAttr( name, this );
	} else if ( type == "mipmapformat" ) {
		attr = new MipMapFormatAttr( name, this );
	} else if ( type == "alphaformat" ) {
		attr = new AlphaFormatAttr( name, this );
	} else if ( type == "nodeancestor" ) {
		attr = new NodeAncestorAttr( name, this );
	} else if ( type == "root" ) {
		attr = new RootAttr( name, this );
	} else {
		cout << type << endl;
		throw runtime_error("Unknown attribute type requested.");
	}

	_attr_map[name] = attr_ref(attr);
	_attr_vect.push_back(attr_ref(attr));
}

attr_ref ABlock::GetAttr(string attr_name) {
	map<string, attr_ref>::iterator it;
	it = _attr_map.find(attr_name);
	if (it == _attr_map.end()) {
		return attr_ref(NULL);
	} else {
		return attr_ref((*it).second);
	}
	//return _attr_map[attr_name]; 
}


vector<attr_ref> ABlock::GetAttrs() {
	return _attr_vect;
}

blk_ref ABlock::GetParent() {
	if (_parents.size() > 0 )
		return blk_ref(_parents[0]);
	else
		return blk_ref(-1);
}

void ABlock::Read( ifstream& in ) {
	for (unsigned int i = 0; i < _attr_vect.size(); ++i ) {
		_attr_vect[i]->Read( in );
		//cout << "   " << _attr_vect[i]->GetName() << endl;
	}
}

void ABlock::Write( ofstream& out ) {
	//Write Block Type
	WriteString( this->GetBlockType() , out );

	//Write Attributes
	for (unsigned int i = 0; i < _attr_vect.size(); ++i ) {
		//cout << "Writing " << blk_ref(this) << " " << _attr_vect[i]->GetName() << endl;
		_attr_vect[i]->Write( out );
	}
}

string ABlock::asString() {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << "Parent:  " << GetParent() << endl;
	for (unsigned int i = 0; i < _attr_vect.size(); ++i ) {
		out << _attr_vect[i]->GetName() << ":  " << _attr_vect[i]->asString() << endl;
	}

	//if ( _parents.size() > 1 ) {
	//	cout << endl  << "Parents:";
	//	for (unsigned int i = 0; i < _parents.size(); ++i ) {
	//		cout << "   " << _parents[i]->GetBlockType();
	//	}
	//	cout << endl << "Node:  " << GetBlockType() << "\a";
	//	cin.get();
	//}

	return out.str();
}

void ABlock::AddRef() {
	++_ref_count;
	//cout << GetBlockType() << " Reference increased to: " << _ref_count << endl;
}

void ABlock::SubtractRef() {
	--_ref_count;
	//cout << GetBlockType() << " Reference decreased to: " << _ref_count << endl;

	if ( _ref_count < 1 ) {
		delete this;
	}
}

list<blk_ref> ABlock::GetLinks() {
	list<blk_ref> links;

	//Search through all attributes for any links and add them to the list
	vector<attr_ref>::iterator it;
	for ( it = _attr_vect.begin(); it != _attr_vect.end(); ++it ) {
		if ( (*it)->HasLinks() == true ) {
			list<blk_ref> link_list = (*it)->asLinkList();
			links.merge( link_list );
		}
	}

	//Remove NULL links
	links.remove( blk_ref(-1) );

	return links;
}

void ABlock::FixUpLinks( const vector<blk_ref> & blocks ) {
	//Search through all attributes for any links and fix their references based on the list
	vector<attr_ref>::iterator it;
	for ( it = _attr_vect.begin(); it != _attr_vect.end(); ++it ) {
		if ( (*it)->HasLinks() == true ) {
			//Get the links out of this attribute and fix each one
			list<blk_ref> links = *it;
			list<blk_ref>::iterator it2;
			for (it2 = links.begin(); it2 != links.end(); ++it2) {
				int index = it2->get_index();
				if (index < int(blocks.size()) && index >= 0 ) {
					*it2 = blocks[index];
				}
			}
			//Now clear the old links and send in the new ones
			(*it)->ClearLinks();
			(*it)->AddLinks(links);
		}
	}
}

//-- Internal Functions --//

void ABlock::AddParent( blk_ref parent) { 
	//Don't add null parents
	if (parent.get_block() != NULL)
		_parents.push_back( parent.get_block() );
}

void ABlock::RemoveParent( IBlock * match ) {
	//Remove just one copy of the parent if there is one, incase a temporary reference is floating around
	vector<IBlock*>::iterator it = find<vector<IBlock*>::iterator, IBlock*>( _parents.begin(), _parents.end(), match);
	if (it != _parents.end() ) {
		_parents.erase( it );
	}

	/*cout << blk_ref(this) << " Parents Remaining:" << endl << "   ";
	for ( it = _parents.begin(); it != _parents.end(); ++it ) {
		cout << blk_ref(*it) << "  ";
	}
	cout << endl;*/

		
	//for (it = _parents.begin(); it != _parents.end(); ) {
	//	if ( *it == match )
	//		_parents.erase( it );
	//	else
	//		++it;
	//}
}

/***********************************************************
 * ANode methods
 **********************************************************/

void * ANode::QueryInterface( int id ) {
	// Contains INode Interface
	if ( id == ID_NODE ) {
		return (void*)static_cast<INode*>(this);
	} else if (id == NodeInternal ) {
		return (void*)static_cast<INodeInternal*>(this);
	} else {
		return ABlock::QueryInterface( id );
	}
}

Matrix44 ANode::GetLocalTransform() {
	//Get transform data from atributes
	Matrix33 f = GetAttr("Rotation")->asMatrix();
	Float3 tran = GetAttr("Translation")->asFloat3();
	float scale = GetAttr("Scale")->asFloat();

	//Set up a matrix with rotate and translate information
	Matrix44 rt;
	rt[0][0] = f[0][0];	rt[0][1] = f[0][1];	rt[0][2] = f[0][2];	rt[0][3] = 0.0f;
	rt[1][0] = f[1][0];	rt[1][1] = f[1][1];	rt[1][2] = f[1][2];	rt[1][3] = 0.0f;
	rt[2][0] = f[2][0];	rt[2][1] = f[2][1];	rt[2][2] = f[2][2];	rt[2][3] = 0.0f;
	rt[3][0] = tran[0];	rt[3][1] = tran[1];	rt[3][2] = tran[2];	rt[3][3] = 1.0f;

	//Set up another matrix with the scale information
	Matrix44 s;
	s[0][0] = scale;	s[0][1] = 0.0f;		s[0][2] = 0.0f;		s[0][3] = 0.0f;
	s[1][0] = 0.0f;		s[1][1] = scale;	s[1][2] = 0.0f;		s[1][3] = 0.0f;
	s[2][0] = 0.0f;		s[2][1] = 0.0f;		s[2][2] = scale;	s[2][3] = 0.0f;
	s[3][0] = 0.0f;		s[3][1] = 0.0f;		s[3][2] = 0.0f;		s[3][3] = 1.0f;

	//Multiply the two for the resulting local transform
	return MultMatrix44(rt, s);
}

Matrix44 ANode::GetWorldTransform() {
	//Get Parent Transform if there is one
	blk_ref par = GetParent();
	INode * node;
	if ( par.is_null() == false && ( node = (INode*)par->QueryInterface(ID_NODE) ) != NULL) {
		//Get Local Transform
		Matrix44 local = GetLocalTransform();

		//Get Parent World Transform
		Matrix44 par_world = node->GetWorldTransform();

		//Multipy local matrix and parent world matrix for result
		return MultMatrix44( par_world, local);
	}
	else {
		//No parent transform, simply return local transform
		return GetLocalTransform();
	}
}

Matrix44 ANode::GetBindPosition() {
	return bindPosition;
	//for (int i = 0; i < 4; ++i) {
	//	for (int j = 0; j < 4; ++j) {
	//		out_matrix[i][j] = bindPosition[i][j];
	//	}
	//}
}

Matrix44 ANode::GetLocalBindPos() {
	//Get Parent Transform if there is one
	blk_ref par = GetParent();
	INode * node;
	if ( par.is_null() == false && ( node = (INode*)par->QueryInterface(ID_NODE) ) != NULL) {
		//There is a node parent
		//multiply its inverse with this block's bind position to get the local bind position
		Matrix44 par_mat = node->GetBindPosition();
		Matrix44 par_inv = InverseMatrix44( par_mat);
		
		return MultMatrix44( bindPosition, par_inv);
	}
	else {
		//No parent transform, simply return local transform
		return GetBindPosition();
	}
}

void ANode::SetBindPosition( Matrix44 & m ) {
	bindPosition = m;
	//for (int i = 0; i < 4; ++i) {
	//	for (int j = 0; j < 4; ++j) {
	//		bindPosition[i][j] = in_matrix[i][j];
	//	}
	//}
}

void ANode::IncSkinRef( IBlock * skin_data ) {
	size_t prev_size = skin_refs.size();

	skin_refs.push_back(skin_data);

	// if the size of the reference list is now not zero, make sure the  'not skin influence flag' is not set
	if ( skin_refs.size() > 0 && prev_size == 0 ) {
		attr_ref flag_attr = GetAttr("Flags");
		int flags = flag_attr->asInt();

		//Make sure it's not already set
		if ((flags & 8) == 0) {
			//Already not set, return
			return;
		}
		
		//Currently set, flip the bit
		flags ^= 8;

		//Store result
		flag_attr->Set(flags);
	}
}

void ANode::DecSkinRef( IBlock * skin_data ) {
	size_t prev_size = skin_refs.size();

	skin_refs.remove(skin_data);

	//If the size of the reference list is now zero, set the 'not skin influence' flag
	if ( skin_refs.size() == 0 && prev_size != 0 ) {
		attr_ref flag_attr = GetAttr("Flags");
		int flags = flag_attr->asInt();

		//Make sure it's not already set
		if ((flags & 8) != 0) {
			//Already set, return
			return;
		}
		
		//Currently not set, flip the bit
		flags ^= 8;

		//Store result
		flag_attr->Set(flags);
	}
}

ANode::~ANode() {
	// Inform all NiSkinData blocks that have added their references that this block is dying
	list<IBlock*>::iterator it;
	for (it = skin_refs.begin(); it != skin_refs.end(); ++it) {
		ISkinDataInternal * data = (ISkinDataInternal*)(*it)->QueryInterface(SkinDataInternal);
		if ( data != NULL ) {
			data->RemoveBoneByPtr(this);
		}
	}
}

/***********************************************************
 * NiNode methods
 **********************************************************/

string NiNode::asString() {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);
	
	out << ABlock::asString();

	//Matrix33 m;
	//GetAttr("Rotation")->asMatrix( m );

	//Vector rows[3];

	//rows[0] = Vector(m[0][0], m[0][1], m[0][2]);
	//rows[1] = Vector(m[1][0], m[1][1], m[1][2]);
	//rows[2] = Vector(m[2][0], m[2][1], m[2][2]);


	////out << "Rotation Matrix Test:" << endl
	////	<< "   Dot Products of each row with each other row:" << endl;

	////for (int i = 0; i < 3; ++i) {
	////	for (int j = 0; j < 3; ++j) {
	////		out << "      Rows " << i << " & " << j << ":  " << rows[i].dot(rows[j]) << endl;
	////	}
	////}

	//float pi = 3.141592653589793f;
	//out << "Euler Angles:" << endl
	//	<< "   X:  " << atan2( m[1][2], m[2][2] ) / pi * 180.0 << endl
	//	<< "   Y:  " << asin( -m[0][2] ) / pi * 180.0 << endl
	//	<< "   Z:  " << atan2( m[0][1], m[0][0] ) / pi * 180.0 << endl;

	//Quat q = MatrixToQuat( m );
	//out << "Quaternion:  [" << setw(6) << q.w << " (" << setw(6) << q.x << "," << setw(6) << q.y << "," << setw(6) << q.z << ")]" << endl;

	//Matrix built_up = IdentityMatrix();
	//GetBuiltUpTransform(blk_ref(this), built_up);
	//out << "Built Up Transformations:" << endl
	//	<< "   |" << setw(6) << built_up(0,0) << "," << setw(6) << built_up(0,1) << "," << setw(6) << built_up(0,2) << "," << setw(6) << built_up(0,3) << " |" << endl
	//	<< "   |" << setw(6) << built_up(1,0) << "," << setw(6) << built_up(1,1) << "," << setw(6) << built_up(1,2) << "," << setw(6) << built_up(1,3) << " |" << endl
	//	<< "   |" << setw(6) << built_up(2,0) << "," << setw(6) << built_up(2,1) << "," << setw(6) << built_up(2,2) << "," << setw(6) << built_up(2,3) << " |" << endl
	//	<< "   |" << setw(6) << built_up(3,0) << "," << setw(6) << built_up(3,1) << "," << setw(6) << built_up(3,2) << "," << setw(6) << built_up(3,3) << " |" << endl;

	//for ( int r = 0; r < 3; ++r ) {
	//	for ( int c = 0; c < 3; ++c) {
	//		m[r][c] = built_up(r,c);
	//	}
	//}
	//q = MatrixToQuat( m );
	//out << "Quaternion:  [" << setw(6) << q.w << " (" << setw(6) << q.x << "," << setw(6) << q.y << "," << setw(6) << q.z << ")]" << endl;
	//out << "Euler Angles:" << endl
	//	<< "   X:  " << atan2( m[1][2], m[2][2] ) / pi * 180.0 << endl
	//	<< "   Y:  " << asin( -m[0][2] ) / pi * 180.0 << endl
	//	<< "   Z:  " << atan2( m[0][1], m[0][0] ) / pi * 180.0 << endl;

	//built_up = built_up.inverse();

	//out << "Inverse Built Up:" << endl
	//	<< "   |" << setw(6) << built_up(0,0) << "," << setw(6) << built_up(0,1) << "," << setw(6) << built_up(0,2) << "," << setw(6) << built_up(0,3) << " |" << endl
	//	<< "   |" << setw(6) << built_up(1,0) << "," << setw(6) << built_up(1,1) << "," << setw(6) << built_up(1,2) << "," << setw(6) << built_up(1,3) << " |" << endl
	//	<< "   |" << setw(6) << built_up(2,0) << "," << setw(6) << built_up(2,1) << "," << setw(6) << built_up(2,2) << "," << setw(6) << built_up(2,3) << " |" << endl
	//	<< "   |" << setw(6) << built_up(3,0) << "," << setw(6) << built_up(3,1) << "," << setw(6) << built_up(3,2) << "," << setw(6) << built_up(3,3) << " |" << endl;

	//for ( int r = 0; r < 3; ++r ) {
	//	for ( int c = 0; c < 3; ++c) {
	//		m[r][c] = built_up(r,c);
	//	}
	//}
	//q = MatrixToQuat( m );
	//out << "Quaternion:  [" << setw(6) << q.w << " (" << setw(6) << q.x << "," << setw(6) << q.y << "," << setw(6) << q.z << ")]" << endl;

	//out << "Euler Angles:" << endl
	//	<< "   X:  " << atan2( m[1][2], m[2][2] ) / pi * 180.0 << endl
	//	<< "   Y:  " << asin( -m[0][2] ) / pi * 180.0 << endl
	//	<< "   Z:  " << atan2( m[0][1], m[0][0] ) / pi * 180.0 << endl;

	out << "Flag Analysis:" << endl
		<< "   Hidden:  ";

	int flags = GetAttr("Flags")->asInt();

	if (flags & 1)
		out << "Yes" << endl;
	else
		out << "No" << endl;

	out << "   Collision Detection Mode:  ";

	
	if (flags & 2)
		out << "Use Triangles" << endl;
	else if (flags & 4)
		out << "Use Oriented Bounding Boxes" << endl;
	else
		out << "None" << endl;

	out << "   Is Skin Influence:  ";

	if (flags & 8)
		out << "No" << endl;
	else
		out << "Yes" << endl;

	if (skin_refs.size() > 0) {
		out << "Influenced Skins:" << endl;

		list<IBlock*>::iterator it;
		for (it = skin_refs.begin(); it != skin_refs.end(); ++it ) {
			out << "   " << blk_ref(*it) << endl;
		}
	}

	return out.str();
}

/***********************************************************
 * NiTriShapeData methods
 **********************************************************/

/**
 * NiTriShapeData::Read - Assumes block name has already been read from in
 */
void NiTriShapeData::Read( ifstream& in ){

	short vert_count = ReadUShort( in );
	int hasVertices = ReadUInt( in );
	if ( hasVertices != 0 ){
		vertices.resize( vert_count );
		for ( uint i = 0; i < vertices.size(); ++i ){
			vertices[i].x = ReadFloat( in );
			vertices[i].y = ReadFloat( in );
			vertices[i].z = ReadFloat( in );
		}
	}

	int hasNormals = ReadUInt( in );
	if ( hasNormals != 0 ){
		normals.resize( vert_count );
		for ( uint i = 0; i < normals.size(); ++i ){
			normals[i].x = ReadFloat( in );
			normals[i].y = ReadFloat( in );
			normals[i].z = ReadFloat( in );
		}
	}

	GetAttr("Center")->Read( in );
	GetAttr("Radius")->Read( in );

	int hasVertexColors = ReadUInt( in );
	if ( hasVertexColors != 0 ){
		colors.resize( vert_count );
		for ( uint i = 0; i < colors.size(); ++i ){
			colors[i].r = ReadFloat( in );
			colors[i].g = ReadFloat( in );
			colors[i].b = ReadFloat( in );
			colors[i].a = ReadFloat( in );
		}
	}

	short numTexSets = ReadUShort( in );
	int hasUVs = ReadUInt( in );
	if ( numTexSets > 0 && hasUVs != 0 ){
		uv_sets.resize( numTexSets );
		//UVs = new fVector2[numVertices * numTexSets];
		for ( uint i = 0; i < uv_sets.size(); ++i ){
			uv_sets[i].resize( vert_count );
			for ( uint j = 0; j < uv_sets[i].size(); ++j){
				uv_sets[i][j].u = ReadFloat( in );
				uv_sets[i][j].v = ReadFloat( in );
			}
		}
	}

	short numTriangles = ReadUShort( in );
	if (numTriangles > 0) {
		int numVertexIndices = ReadUInt( in );
		triangles.resize( numTriangles );
		for ( int i = 0; i < numTriangles; ++i ){
			triangles[i].v1 = ReadUShort( in );
			triangles[i].v2 = ReadUShort( in );
			triangles[i].v3 = ReadUShort( in );
		}
	}

	short matchGroupCount = ReadUShort( in );
	match_group_mode = ( matchGroupCount != 0 );  // Only record whether or not file prefers to have match data generated

	short sub_count;
	for ( int i = 0; i < matchGroupCount; ++i ){
		sub_count = ReadUShort( in );
		for (ushort j = 0; j < sub_count; ++j) {
			ReadUShort( in );  // Read data, but don't care what it is
		}
	}
}

string NiTriShapeData::asString() {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << "Vertices:  " << uint(vertices.size());
	if (verbose) {
		out << "   ";
		for ( uint i = 0; i < vertices.size(); ++i) {
			if (i % 3 == 0)
				out << endl << "   ";
			else
				out << "  ";

			out << "(" << setw(5) << vertices[i].x << ", " << setw(5) << vertices[i].y << ", " << setw(5) << vertices[i].z << " )";
		}
	} else {
		out << endl << "<<Data Not Shown>>";
	}
	out << endl;

	out << "Normals:  " << uint(normals.size());
	if (verbose) {
		out << "   ";
		for ( uint i = 0; i < normals.size(); ++i) {
			if (i % 3 == 0)
				out << endl << "   ";
			else
				out << "  ";

			out << "(" << setw(5) << normals[i].x << ", " << setw(5) << normals[i].y << ", " << setw(5) << normals[i].z << " )";
		}
	} else {
		out << endl << "<<Data Not Shown>>";
	}
	out << endl;
	
	attr_ref attr = GetAttr("Center");
	out << attr->GetName() << ":  " << attr->asString() << endl;
	attr = GetAttr("Radius");
	out << attr->GetName() << ":  " << attr->asString() << endl;

	out << "Vertex Colors:  " << uint(colors.size());
	if (verbose) {
		out << "   ";
		for ( uint i = 0; i < colors.size(); ++i) {
			if (i % 3 == 0)
				out << endl << "   ";
			else
				out << "  ";
			
			out << "(" << setw(5) << colors[i].r << ", " << setw(5) << colors[i].g << ", " << setw(5) << colors[i].b << ", " << setw(5) << colors[i].a << " )";
		}
	} else {
		out << endl << "<<Data Not Shown>>";
	}
	out << endl;

	out << "Texture Coordinate Sets:  " << uint(uv_sets.size());
	if (verbose) {
		for ( uint i = 0; i < uv_sets.size(); ++i) {
			out << endl 
				<< "   UV Set " << i+1 << ":";

			for ( uint j = 0; j < uv_sets[i].size(); ++j) {
				if (j % 3 == 0)
					out << endl << "      ";
				else
					out << "  ";

				out << "(" << setw(5) << uv_sets[i][j].u << ", " << setw(5) << uv_sets[i][j].v << " )";
			}
		}
	} else {
		out << endl << "<<Data Not Shown>>";
	}
	out << endl;

	out << "Triangles:  " << uint(triangles.size());
	if (verbose) {
		for ( uint i = 0; i < triangles.size(); ++i) {
			if (i % 3 == 0)
				out << endl << "   ";
			else
				out << "  ";
			
			out << "(" << setw(5) << triangles[i].v1 << ", " << setw(5) << triangles[i].v2 << ", " << setw(5) << triangles[i].v3 << " )";
		}
	} else {
		out << endl << "<<Data Not Shown>>";
	}
	out << endl;

	out << "Match Detection:  ";
	if ( match_group_mode )
		out << "On" << endl;
	else
		out << "Off" << endl;	

	return out.str();
}

/**
 * NiTriShapeData::Write - Writes block name to out, in addition to data.
 */
void NiTriShapeData::Write( ofstream& out ){

	WriteString( "NiTriShapeData", out );

	WriteUShort( short(vertices.size()), out );

	if ( vertices.size() > 0 )
		WriteUInt( 1, out );
	else
		WriteUInt( 0, out );

	for ( uint i = 0; i < vertices.size(); ++i ){
		WriteFloat( vertices[i].x, out );
		WriteFloat( vertices[i].y, out );
		WriteFloat( vertices[i].z, out );
	}

	if ( normals.size() > 0 )
		WriteUInt( 1, out );
	else
		WriteUInt( 0, out );

	for ( uint i = 0; i < normals.size(); ++i) {
		WriteFloat( normals[i].x, out );
		WriteFloat( normals[i].y, out );
		WriteFloat( normals[i].z, out );
	}

	GetAttr("Center")->Write( out );
	GetAttr("Radius")->Write( out );

	if ( colors.size() > 0 )
		WriteUInt( 1, out );
	else
		WriteUInt( 0, out );

	for ( uint i = 0; i < colors.size(); ++i ){
		WriteFloat( colors[i].r, out );
		WriteFloat( colors[i].g, out );
		WriteFloat( colors[i].b, out );
		WriteFloat( colors[i].a, out );
	}

	WriteUShort( ushort(uv_sets.size()), out );
	if ( uv_sets.size() > 0 && uv_sets[0].size() > 0 ) // hasUVs
		WriteUInt( 1, out );
	else
		WriteUInt( 0, out );

	for ( uint i = 0; i < uv_sets.size(); ++i) {
		for ( uint j = 0; j < uv_sets[i].size(); ++j) {
			WriteFloat( uv_sets[i][j].u, out );
			WriteFloat( uv_sets[i][j].v, out );
		}
	}

	WriteUShort( ushort(triangles.size()), out );

	if ( triangles.size() > 0 ) {
		//Write number of shorts:  triCount * 3
		WriteUInt( ushort(triangles.size()) * 3, out );

		for ( uint i = 0; i < triangles.size(); ++i ){
			WriteUShort( triangles[i].v1, out );
			WriteUShort( triangles[i].v2, out );
			WriteUShort( triangles[i].v3, out );
		}
	}

	

	if ( match_group_mode ) {
		WriteUShort( ushort(vertices.size()), out ); //Match Group Count = Vertex Count

		vector<ushort> matches;
		for ( uint i = 0; i < vertices.size(); ++i ){
			// Find all vertices that match this one.
			matches.clear();
			for (ushort j = 0; j < vertices.size(); ++j) {
				if ( i != j && vertices[i].x == vertices[j].x && vertices[i].y == vertices[j].y && vertices[i].z == vertices[j].z ) {
					matches.push_back(j);
				}
			}
			//Match Count
			WriteUShort( ushort(matches.size()) , out );

			//Output Vertex indicies
			for (ushort j = 0; j < matches.size(); ++j) {
				WriteUShort( matches[j], out );
			}
		}	
	} else {
		WriteUShort( 0, out ); //Match Group Count = 0
	}
}

void * NiTriShapeData::QueryInterface( int id ) {
	// Contains TriShapeData Interface
	if ( id == ID_TRI_SHAPE_DATA ) {
		return (void*)static_cast<ITriShapeData*>(this);
	} else {
		return ABlock::QueryInterface( id );
	}
}

void NiTriShapeData::SetVertexCount(int n) {
	vertices.resize(n);
	normals.resize(n);
	colors.resize(n);
	for (uint i = 0; i < uv_sets.size(); ++i) {
		uv_sets[i].resize(n);
	}
}

void NiTriShapeData::SetUVSetCount(int n) {
	uv_sets.resize(n);
}

void NiTriShapeData::SetTriangleCount(int n) {
	triangles.resize(n);
}

//--Setters--//
void NiTriShapeData::SetVertices( const vector<Vector3> & in ) {
	if (in.size() != vertices.size())
		throw runtime_error("Input array size must equal Vertex Count.  Call SetVertexCount() to resize.");
	vertices = in;
}

void NiTriShapeData::SetNormals( const vector<Vector3> & in ) {
	if (in.size() != vertices.size())
		throw runtime_error("Input array size must equal Vertex Count.  Call SetVertexCount() to resize.");
	normals = in;
}

void NiTriShapeData::SetColors( const vector<Color> & in ) {
	if (in.size() != vertices.size())
		throw runtime_error("Vector size must equal Vertex Count.  Call SetVertexCount() to resize.");
	colors = in;
}

void NiTriShapeData::SetUVSet( int index, const vector<UVCoord> & in ) {
	if (in.size() != vertices.size())
		throw runtime_error("Vector size must equal Vertex Count.  Call SetVertexCount() to resize.");
	uv_sets[index] = in;
}

void NiTriShapeData::SetTriangles( const vector<Triangle> & in ) {
	if (in.size() != vertices.size())
		throw runtime_error("Vector size must equal Vertex Count.  Call SetVertexCount() to resize.");
	triangles = in;
}

/***********************************************************
 * NiSkinData methods
 **********************************************************/

void NiSkinData::Read( ifstream& in ) {
	
	for (int c = 0; c < 3; ++c) {
		for (int r = 0; r < 3; ++r) {
			rotation[r][c] = ReadFloat( in );
		}
	}
	ReadFVector3( translation, in );
	scale = ReadFloat( in );
	int boneCount = ReadUInt( in );
	unknown = ReadUInt( in );
	bones.resize(boneCount);
	for( int i = 0; i < boneCount; i++ ) {
		for (int c = 0; c < 3; ++c) {
			for (int r = 0; r < 3; ++r) {
				bones[i].rotation[r][c] = ReadFloat( in );
			}
		}
		ReadFVector3( bones[i].translation, in );
		bones[i].scale = ReadFloat( in );
		ReadFVector4( bones[i].unknown4Floats, in );
		short numWeights = ReadUShort( in );
		bones[i].weights.clear();
		for ( int j = 0; j < numWeights; ++j ){
			short vertexNum = ReadUShort( in );
			float vertexWeight = ReadFloat( in );
			bones[i].weights[vertexNum] = vertexWeight;
		}
	}
}

void NiSkinData::Write( ofstream& out ) {
	//Calculate offset matrices prior to writing data
	CalculateBoneOffsets();

	WriteString( "NiSkinData", out );

	for (int c = 0; c < 3; ++c) {
		for (int r = 0; r < 3; ++r) {
			WriteFloat( rotation[r][c], out );
		}
	}
	WriteFVector3( translation, out );
	WriteFloat( scale, out );
	WriteUInt(short(bone_map.size()), out);
	WriteUInt(unknown, out);

	map<IBlock*, Bone>::iterator it;
	for( it = bone_map.begin(); it != bone_map.end(); ++it ) {		
		for (int c = 0; c < 3; ++c) {
			for (int r = 0; r < 3; ++r) {
				WriteFloat( it->second.rotation[r][c], out );
			}
		}
		WriteFVector3( it->second.translation, out );
		WriteFloat( it->second.scale, out );

		WriteFVector4( it->second.unknown4Floats, out );
		//WriteFloat( 0.0f, out );
		//WriteFloat( 0.0f, out );
		//WriteFloat( 0.0f, out );
		//WriteFloat( 0.0f, out );
		WriteUShort( short(it->second.weights.size() ), out );
		
		map<int, float>::iterator it2;
		for ( it2 = it->second.weights.begin(); it2 != it->second.weights.end(); ++it2 ){
			WriteUShort( it2->first, out );
			WriteFloat( it2->second, out );
		}
	}
}

//void GetBuiltUpTransform(blk_ref block, Matrix & m/*, blk_ref stop*/) {
//	Matrix33 temp;
//	float3 t2;
//
//	// Do multiplication
//	attr_ref rot_attr = block["Rotation"];
//	attr_ref trn_attr = block["Translation"];
//	attr_ref scl_attr = block["Scale"];
//
//	if ( rot_attr.is_null() == false && trn_attr.is_null() == false && scl_attr.is_null() == false ) {
//		rot_attr->asMatrix(temp);
//		trn_attr->asFloat3(t2);
//		float scale = scl_attr->asFloat();
//
//		Matrix tr = Matrix( temp[0][0], temp[0][1], temp[0][2], 0.0f,
//							temp[1][0], temp[1][1], temp[1][2], 0.0f,
//							temp[2][0], temp[2][1], temp[2][2], 0.0f,
//							t2[0], t2[1], t2[2], 1.0f);
//
//		Matrix s = Matrix( scale, 0.0f, 0.0f, 0.0f,
//							0.0f, scale, 0.0f, 0.0f,
//							0.0f, 0.0f, scale, 0.0f,
//							0.0f, 0.0f, 0.0f, 1.0f );
//
//		m = m * (tr * s);
//	}
//	else {
//		throw runtime_error("GetBuiltUpTranslations attempted to access a block without rotation, translation, and scale");
//	}
//
//	//Check if there are any parents
//	blk_ref par = block->GetParent();
//	if ( par.is_null() == false ) {
//		//There is a parent, re-call this function on it
//		GetBuiltUpTransform( par, m/*, stop*/ );
//	}
//}

string NiSkinData::asString() {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	//Calculate bone offsets pior to printing readout
	CalculateBoneOffsets();

	out << "Rotate:" << endl
		<< "   |" << setw(6) << rotation[0][0] << "," << setw(6) << rotation[0][1] << "," << setw(6) << rotation[0][2] << " |" << endl
		<< "   |" << setw(6) << rotation[1][0] << "," << setw(6) << rotation[1][1] << "," << setw(6) << rotation[1][2] << " |" << endl
		<< "   |" << setw(6) << rotation[2][0] << "," << setw(6) << rotation[2][1] << "," << setw(6) << rotation[2][2] << " |" << endl
		<< "Translate:  " << translation << endl
		<< "Scale:  " << scale << endl
		<< "Bone Count:  " << uint(bone_map.size()) << endl
		<< "Unknown Index:  " << unknown << endl
		<< "Bones:" << endl;

	map<IBlock*, Bone>::iterator it;
	//vector<Bone>::iterator it;
	int num = 0;
	for( it = bone_map.begin(); it != bone_map.end(); ++it ) {
		//Friendlier name
		Bone & bone = it->second;

		num++;
		out << "Bone " << num << ":" << endl
			<< "   Block:  " << blk_ref(it->first) << endl
			<< "   Bone Offset Transforms:" << endl
			<< "      Rotation:" << endl
			<< "         |" << setw(6) << bone.rotation[0][0] << "," << setw(6) << bone.rotation[0][1] << "," << setw(6) << bone.rotation[0][2] << " |" << endl
			<< "         |" << setw(6) << bone.rotation[1][0] << "," << setw(6) << bone.rotation[1][1] << "," << setw(6) << bone.rotation[1][2] << " |" << endl
			<< "         |" << setw(6) << bone.rotation[2][0] << "," << setw(6) << bone.rotation[2][1] << "," << setw(6) << bone.rotation[2][2] << " |" << endl
			<< "      Translate:  " << bone.translation << endl
			<< "      Scale:  " << bone.scale << endl;

		float q[4] = {  bone.unknown4Floats[0],
					    bone.unknown4Floats[1],
					    bone.unknown4Floats[2],
					    bone.unknown4Floats[3] };

		out << "Unknown 4 Floats:  " << setw(6) << q[0] << "," << setw(6) << q[1] << "," << setw(6) << q[2] << "," << setw(6) << q[3] << endl;

		out << "   Weights:  " << uint(bone.weights.size()) << endl;

		if (verbose) {
			map<int, float>::iterator it2;
			for ( it2 = bone.weights.begin(); it2 != bone.weights.end(); ++it2 ){
				out << "   Vertex: " << it2->first << "\tWeight: " << it2->second << endl;
			}
		} else {
			out << "      <<Data Not Shown>>" << endl;
		}
	}
	
	//out << setprecision(1);

	return out.str();
}

void * NiSkinData::QueryInterface( int id ) {
	// Contains ISkinData Interface
	if ( id == ID_SKIN_DATA ) {
		return (void*)static_cast<ISkinData*>(this);
	} else if ( id == SkinDataInternal ) {
		return (void*)static_cast<ISkinDataInternal*>(this);
	} else {
		return ABlock::QueryInterface( id );
	}
}

void NiSkinData::SetBones( vector<blk_ref> bone_blocks ) {
	//Move bones from temproary vector to map, sorted by blk_ref
	for (uint i = 0; i < bones.size(); ++i) {
			//Make sure bone is a node
			INodeInternal * node_int = (INodeInternal*)bone_blocks[i]->QueryInterface(NodeInternal);

			if (node_int == NULL)
				throw runtime_error("Attempted to add a block as a bone that is not a node.");

			//move the data
			bone_map.insert( pair<IBlock*, Bone>(bone_blocks[i].get_block(), bones[i]) );
			
			//Increment reference at bone node site
			node_int->IncSkinRef(this);
	}

	//Clear temporary vector data
	bones.clear();
}

void NiSkinData::StraightenSkeleton() {
	////Get bone blocks from parent SkinInstance
	//vector<blk_ref> bone_blks;
	//blk_ref par = GetParent();
	//blk_link l;
	//attr_ref bone_attr = par->GetAttr("Bones");

	//if ( bone_attr.is_null() == false ) {
	//	for (int i = 0; i < par->LinkCount(); ++i) {
	//		l = par->GetLink(i);
	//		if ( l.attr == bone_attr ) {
	//			bone_blks.push_back(l.block);
	//		}
	//	}
	//}

	//Loop through all bones
	map<IBlock*, Bone>::iterator it;
	for ( it = bone_map.begin(); it != bone_map.end(); ++it ) {
		//Friendlier name for current bone
		Bone & bone = it->second;

		//Get current offset Matrix33 for this bone

		Matrix44 parent_offset = {
			bone.rotation[0][0], bone.rotation[0][1], bone.rotation[0][2], 0.0f,
			bone.rotation[1][0], bone.rotation[1][1], bone.rotation[1][2], 0.0f,
			bone.rotation[2][0], bone.rotation[2][1], bone.rotation[2][2], 0.0f,
			bone.translation[0], bone.translation[1], bone.translation[2], 1.0f
		}; 
		//Loop through all bones again, checking for any that have this bone as a parent
		map<IBlock*, Bone>::iterator it2;
		for ( it2 = bone_map.begin(); it2 != bone_map.end(); ++it2 ) {
			if ( it2->first->GetParent() == it->first ) {
				//Block 2 has block 1 as a parent

				Bone & bone2 = it2->second;

				//Get child offset Matrix33
				Matrix44 child_offset = {
					bone2.rotation[0][0], bone2.rotation[0][1], bone2.rotation[0][2], 0.0f,
					bone2.rotation[1][0], bone2.rotation[1][1], bone2.rotation[1][2], 0.0f,
					bone2.rotation[2][0], bone2.rotation[2][1], bone2.rotation[2][2], 0.0f,
					bone2.translation[0], bone2.translation[1], bone2.translation[2], 1.0f
				};

				//Do calculation to get correct bone postion in relation to parent
				Matrix44 inverse_co = InverseMatrix44(child_offset);
				Matrix44 child_pos = MultMatrix44( inverse_co, parent_offset);

				//Store result in block's Bind Position Matrix
				INode * node = (INode*)it2->first->QueryInterface(ID_NODE);
				if (node != NULL) {
					node->SetBindPosition(child_pos);
				}

    //            //Store result in child block
				//Matrix33 rotate = { 
				//	child_pos[0][0], child_pos[0][1], child_pos[0][2],
				//	child_pos[1][0], child_pos[1][1], child_pos[1][2],
				//	child_pos[2][0], child_pos[2][1], child_pos[2][2]
				//};
				//it2->first->GetAttr("Rotation")->Set( rotate );
				//it2->first->GetAttr("Translation")->Set( child_pos[3][0], child_pos[3][1], child_pos[3][2] );
			}
		}
	}
}

void NiSkinData::RepositionTriShape() {
	//Get block we're going to move
	blk_ref tri_shape = GetParent()->GetParent();

	//There must be at least one bone to do anything
	if ( bone_map.size() > 0 ) {
		//--Start Position--//
		//Matrix start_mat = IdentityMatrix();
		//GetBuiltUpTransform( tri_shape->GetParent(), start_mat );

		//--End Position--//

		//Get first bone
		blk_ref bone_blk = bone_map.begin()->first;
		Bone & bone = bone_map.begin()->second;


		//blk_ref skin_inst = GetParent();
		//blk_link l;
		//attr_ref bone_attr = skin_inst->GetAttr("Bones");
		//
		//blk_ref bone_blk;
		//if ( bone_attr.is_null() == false ) {
		//	for (int i = 0; i < skin_inst->LinkCount(); ++i) {
		//		l = skin_inst->GetLink(i);
		//		if ( l.attr == bone_attr ) {
		//			//Found the first bone, record it and break
		//			bone_blk = l.block;
		//			break;
		//		}
		//	}
		//}
		//else {
		//	//Couldn't get the bone attr
		//	cout << "Couldn't get the bone attr" << endl;
		//	return;
		//}

		Matrix44 offset_mat = {
			bone.rotation[0][0], bone.rotation[0][1], bone.rotation[0][2], 0.0f,
			bone.rotation[1][0], bone.rotation[1][1], bone.rotation[1][2], 0.0f,
			bone.rotation[2][0], bone.rotation[2][1], bone.rotation[2][2], 0.0f,
			bone.translation[0], bone.translation[1], bone.translation[2], 1.0f
		};
			
		//Get built up rotations to the root of the skeleton from this bone
		INode * bone_node = (INode*)bone_blk->QueryInterface(ID_NODE);
		if (bone_node == NULL)
			throw runtime_error("Failed to get Node interface.");

		Matrix44 bone_mat = bone_node->GetBindPosition();

		Matrix44 result_mat = MultMatrix44( offset_mat, bone_mat);

		//GetBuiltUpTransform( bone_blk, end_mat );

		//--Set TriShape Bind Position to Result--//
		INode * shape_node = (INode*)tri_shape->QueryInterface(ID_NODE);
		if (shape_node == NULL)
			throw runtime_error("Failed to get Node interface.");

		shape_node->SetBindPosition( result_mat );

		

		//Matrix res_mat = end_mat;// * start_mat.inverse();

		//tri_shape->GetAttr("Translation")->Set( res_mat(3,0), res_mat(3,1), res_mat(3,2) );

		//Matrix33 rotation = { res_mat(0,0), res_mat(0,1), res_mat(0,2),
		//					res_mat(1,0), res_mat(1,1), res_mat(1,2),
		//					res_mat(2,0), res_mat(2,1), res_mat(2,2) };
		//tri_shape->GetAttr("Rotation")->Set( rotation );
	}
	else {
		cout << "Reposition Failed for " << tri_shape << endl;
	}
}

vector<blk_ref> NiSkinData::GetBones() {
	//Put all the valid bones from the map into a vector to return
	vector<blk_ref> bone_blks( bone_map.size() );

	map<IBlock*, Bone>::iterator it;
	int count = 0;
	for (it = bone_map.begin(); it != bone_map.end(); ++it ) {
		bone_blks[count] = blk_ref(it->first);
		count++;
	}

	return bone_blks;
}

map<int, float> NiSkinData::GetWeights( blk_ref bone ) {
	return bone_map[bone.get_block()].weights;
}

void NiSkinData::AddBone( blk_ref bone, map<int, float> in ) {
	//Make sure bone is a node
	INodeInternal * node_int = (INodeInternal*)bone->QueryInterface(NodeInternal);

	if (node_int == NULL)
		throw runtime_error("Attempted to add a block as a bone that is not a node.");
	
	//Add bone to internal list
	bone_map[bone.get_block()].weights = in;
	
	//Increment reference at bone node site
	node_int->IncSkinRef(this);
}

void NiSkinData::RemoveBoneByPtr( IBlock * bone ) {
	//Remove bone from internal list
	bone_map.erase( bone );

	//Do not decrement bone node locatoin because it is already dead
}

void NiSkinData::RemoveBone( blk_ref bone ) {
	//Remove bone from internal list
	bone_map.erase( bone.get_block() );

	//Decrement reference at bone node site
	INodeInternal * node_int = (INodeInternal*)bone->QueryInterface(NodeInternal);
	node_int->DecSkinRef(this);
}

NiSkinData::~NiSkinData() {
	//Inform all linked bone nodes that this NiSkinData block is dying
	map<IBlock*, Bone>::iterator it;
	for (it = bone_map.begin(); it != bone_map.end(); ++it) {
		INodeInternal * node_int = (INodeInternal*)it->first->QueryInterface(NodeInternal);
		node_int->DecSkinRef(this);
	}
}

void NiSkinData::CalculateBoneOffsets() {

	//--Get Node Parent Bind Pose--//

	blk_ref par_block;
	try {
		par_block = GetParent()->GetParent();
	}
	catch (...) {
		throw runtime_error("SkinData block does not have parent of parent.");
	}

	INode * par_node = QueryNode(par_block);	
	if ( par_node == NULL )
		throw runtime_error("SkinData block's parent of parent is not a node.");


	//Cycle through all bones, calculating their offsets and storing the values
	map<IBlock*, Bone>::iterator it;
	for( it = bone_map.begin(); it != bone_map.end(); ++it ) {
		//--Get Bone Bind Pose--//

		//Get Bone Node
		INode * bone_node = (INode*)it->first->QueryInterface(ID_NODE);

		//Get bind matricies

		Matrix44 par_mat, bone_mat, inv_mat, res_mat;
		par_mat = par_node->GetBindPosition();
		bone_mat = bone_node->GetBindPosition();

		//Inverse bone matrix & multiply with parent node matrix
		inv_mat = InverseMatrix44(bone_mat);
		res_mat = MultMatrix44(par_mat, inv_mat);

		//--Extract Scale from first 3 rows--//
		float scale[3];
		for (int r = 0; r < 3; ++r) {
			//Get scale for this row
			scale[r] = sqrt(res_mat[r][0] * res_mat[r][0] + res_mat[r][1] * res_mat[r][1] + res_mat[r][2] * res_mat[r][2] + res_mat[r][3] * res_mat[r][3]);

			//Normalize the row by dividing each factor by scale
			res_mat[r][0] /= scale[r];
			res_mat[r][1] /= scale[r];
			res_mat[r][2] /= scale[r];
			res_mat[r][3] /= scale[r];
		}

		//--Store Results--//

		//Store rotation matrix
		for (int c = 0; c < 3; ++c) {
			for (int r = 0; r < 3; ++r) {
				it->second.rotation[r][c] = res_mat[r][c];
			}
		}

		//Store translate vector
		it->second.translation[0] = res_mat[3][0];
		it->second.translation[1] = res_mat[3][1];
		it->second.translation[2] = res_mat[3][2];

		
		//Store average scale
		it->second.scale = (scale[0] + scale[1] + scale[2]) / 3.0f;
	}
}

/***********************************************************
 * NiGeomMorpherController methods
 **********************************************************/

string NiGeomMorpherController::asString() {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << ABlock::asString();

	out << "Flag Analysis:" << endl
		<< "   Animation Type:  ";

	int flags = GetAttr("Flags")->asInt();
	
	if (flags & 1)
		out << "APP_INIT" << endl;
	else
		out << "APP_TIME" << endl;

	out << "   Cycle Type:  ";
	if (flags & 2)
		out << "REVERSE" << endl;
	else if (flags & 4)
		out << "CLAMP" << endl;
	else
		out << "LOOP" << endl;

	out << "   Animation Enabled:  ";
	if (flags & 8)
		out << "Yes" <<endl;
	else
		out << "No" <<endl;

	return out.str();
}

/***********************************************************
 * NiKeyframeData methods
 **********************************************************/

void NiKeyframeData::Read( ifstream& in ) {

	scaleType = rotationType = translationType = KeyType(0);

	//--Rotation--//
	uint numRotations = ReadUInt( in );

	if (numRotations > 0) {
		rotationType = KeyType(ReadUInt( in ));

		rotKeys.resize( numRotations );
		for ( unsigned int i = 0; i < numRotations; ++i ) {
			rotKeys[i].time = ReadFloat( in );

			if (rotationType != 4) {
				rotKeys[i].data.w = ReadFloat( in );
				rotKeys[i].data.x = ReadFloat( in );
				rotKeys[i].data.y = ReadFloat( in );
				rotKeys[i].data.z = ReadFloat( in );
			}

			if (rotationType == 3) {
				rotKeys[i].tension = ReadFloat( in );
				rotKeys[i].bias = ReadFloat( in );
				rotKeys[i].continuity = ReadFloat( in );
			} else if (rotationType == 4) {
				throw runtime_error("NiKeyframeData rotation type 4 currently unsupported");
				//cout << "Rotation Type 4 Unsupported - Data will not be read" << endl;

				////cout << endl;
				//for (int j = 0; j < 3; j++) {
				//	//cout << "--Rotation Group " << j + 1 << "--" << endl;
				//	int subCount = ReadUInt( in );
				//	//cout << "Sub Count:  " << subCount << endl;
				//	int subType = ReadUInt( in );
				//	//cout << "Sub Type:  " << subType << endl;

				//	for (int k = 0; k < subCount; k++) {
				//		float subTime = ReadFloat( in );
				//		//cout << "KeyTime:  " << subTime << "  ";
				//		float subUnk1 = ReadFloat( in );
				//		//cout << "Data:  " << subUnk1;
				//		if (subType == 2) {
				//			float subUnk2 = ReadFloat( in );
				//			float subUnk3 = ReadFloat( in );
				//			//cout << ", " << subUnk2 << ", " << subUnk3;
				//		}
				//		//cout << endl;
				//	}
				//}
			}
		}
	}

	//--Translation--//
	uint numTranslations = ReadUInt( in );

	if (numTranslations > 0) {
		translationType = KeyType(ReadUInt( in ));

		transKeys.resize( numTranslations );
		for ( unsigned int i = 0; i < numTranslations; ++i ) {
			transKeys[i].time = ReadFloat( in );
			
			transKeys[i].data.x = ReadFloat( in );
			transKeys[i].data.y = ReadFloat( in );
			transKeys[i].data.z = ReadFloat( in );

			if (translationType == 2) {
				transKeys[i].forward_tangent.x = ReadFloat( in );
				transKeys[i].forward_tangent.y = ReadFloat( in );
				transKeys[i].forward_tangent.y = ReadFloat( in );

				transKeys[i].backward_tangent.x = ReadFloat( in );
				transKeys[i].backward_tangent.y = ReadFloat( in );
				transKeys[i].backward_tangent.y = ReadFloat( in );
			}else if (translationType == 3) {
				transKeys[i].tension = ReadFloat( in );
				transKeys[i].bias = ReadFloat( in );
				transKeys[i].continuity = ReadFloat( in );
			}
		}
	}

	//--Scale--//
	uint numScalings = ReadUInt( in );

	if (numScalings > 0) {
		scaleType = KeyType(ReadUInt( in ));
		cout << "Scale Type:  " << scaleType << endl;

		scaleKeys.resize( numScalings );
		for ( unsigned int i = 0; i < numScalings; ++i ) {
			scaleKeys[i].time = ReadFloat( in );

			scaleKeys[i].data = ReadFloat( in );

			if (scaleType == 2) {
				scaleKeys[i].forward_tangent = ReadFloat( in );
				scaleKeys[i].backward_tangent = ReadFloat( in );
			} else if (scaleType == 3) {
				scaleKeys[i].tension = ReadFloat( in );
				scaleKeys[i].bias = ReadFloat( in );
				scaleKeys[i].continuity = ReadFloat( in );
			}
		}
	}
}

void NiKeyframeData::Write( ofstream& out ) {

	WriteString( "NiKeyframeData", out );

	//--Rotation--//
	WriteUInt( uint(rotKeys.size()), out );

	if (rotKeys.size() > 0) {
		WriteUInt( rotationType, out );

		for ( unsigned int i = 0; i < rotKeys.size(); ++i ) {
			WriteFloat( rotKeys[i].time, out );

			if (rotationType != 4) {
				WriteFloat( rotKeys[i].data.w, out );
				WriteFloat( rotKeys[i].data.x, out );
				WriteFloat( rotKeys[i].data.y, out );
				WriteFloat( rotKeys[i].data.z, out );
			}

			if (rotationType == 3) {
				WriteFloat( rotKeys[i].tension, out );
				WriteFloat( rotKeys[i].bias, out );
				WriteFloat( rotKeys[i].continuity, out );
			} else if (rotationType == 4) {
				throw runtime_error("NiKeyframeData rotation type 4 currently unsupported");
			}
		}
	}

	//--Translation--//

	WriteUInt( uint(transKeys.size()), out );

	if (transKeys.size() > 0) {
		WriteUInt( translationType, out );

		for ( unsigned int i = 0; i < transKeys.size(); ++i ) {
			WriteFloat( transKeys[i].time, out );

			WriteFloat( transKeys[i].data.x, out );
			WriteFloat( transKeys[i].data.y, out );
			WriteFloat( transKeys[i].data.z, out );

			if (translationType == 2) {
				WriteFloat( transKeys[i].forward_tangent.x, out );
				WriteFloat( transKeys[i].forward_tangent.y, out );
				WriteFloat( transKeys[i].forward_tangent.z, out );

				WriteFloat( transKeys[i].backward_tangent.x, out );
				WriteFloat( transKeys[i].backward_tangent.y, out );
				WriteFloat( transKeys[i].backward_tangent.z, out );
			}else if (translationType == 3) {
				WriteFloat( transKeys[i].tension, out );
				WriteFloat( transKeys[i].bias, out );
				WriteFloat( transKeys[i].continuity, out );
			}
		}
	}
                        
	//--Scale--//
	WriteUInt( uint(scaleKeys.size()), out );

	if ( scaleKeys.size() > 0) {
		WriteUInt( scaleType, out );

		for ( unsigned int i = 0; i < scaleKeys.size(); ++i ) {
			WriteFloat( scaleKeys[i].time, out );

			WriteFloat( scaleKeys[i].data, out );

			if (scaleType == 2) {
				WriteFloat( scaleKeys[i].forward_tangent, out );
				WriteFloat( scaleKeys[i].backward_tangent, out );
			} else if (scaleType == 3) {
				WriteFloat( scaleKeys[i].tension, out );
				WriteFloat( scaleKeys[i].bias, out );
				WriteFloat( scaleKeys[i].continuity, out );
			}
		}
	}
}

string NiKeyframeData::asString() {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	//--Rotation--//
	out << "Rotations:  " << uint(rotKeys.size()) << endl;

	if (rotKeys.size() > 0) {
		out << "Rotation Type:  " << rotationType << endl;

		if (verbose) {
			for (unsigned int i = 0; i < rotKeys.size(); i++) {
				out << "Key Time:  " << rotKeys[i].time << "  ";

				if (rotationType != 4) {
					out << "Rotation:  Q[" << rotKeys[i].data.w << " ( " << rotKeys[i].data.x << ", " << rotKeys[i].data.y << ", " << rotKeys[i].data.z << ")]" << endl;
					//	<< "   As Matrix:";
					//QuatToMatrix(rotKeys[i].data, out );
					//out << "   As Angles:";
					//QuatToEuler(rotKeys[i].data, out );

				}
				
				if (rotationType == 3) {
					out << ", T " << rotKeys[i].tension << ", B " << rotKeys[i].bias << ", C " << rotKeys[i].continuity;
				} else if (rotationType == 4) {
					out << "Rotation Type 4 Unsupported - Data was not read" << endl;
				}
				out << endl;
			}
		} else {
			out << "<<Data Not Shown>>" << endl;
		}	
	}

	//--Translation--//
	out << "Translations:  " << uint(transKeys.size()) << endl;

	if (transKeys.size() > 0) {
		out << "Translation Type:  " << translationType << endl;

		if (verbose) {
			for (unsigned int i = 0; i < transKeys.size(); i++) {
				out << "Key Time:  " << transKeys[i].time << "  ";
				
				out << "Data:  V(" << transKeys[i].data.x << ", " << transKeys[i].data.y << ", " << transKeys[i].data.z;

				if (translationType == 2) {
					out << "), F(" << transKeys[i].forward_tangent.x << ", " << transKeys[i].forward_tangent.y << ", " << transKeys[i].forward_tangent.z << "), B(" << transKeys[i].backward_tangent.x << ", " << transKeys[i].backward_tangent.y << ", " << transKeys[i].backward_tangent.z << ")";
				}else if (translationType == 3) {
					out << ", T " << transKeys[i].tension << ", B " << transKeys[i].bias << ", C " << transKeys[i].continuity;
				}
				out << endl;
			}
		} else {
			out << "<<Data Not Shown>>" << endl;
		}
		
	}
                        
	//--Scale--//
	out << "Scalings:  " << uint(scaleKeys.size()) << endl;

	if (verbose) {
		if (scaleKeys.size() > 0) {
			out << "Scale Type:  " << scaleType << endl;

			for (unsigned int i = 0; i < scaleKeys.size(); i++) {
				out << "Key Time:  " << scaleKeys[i].time  << "  ";

				out << "Data:  S(" << scaleKeys[i].data << ")";

				if (scaleType == 2) {
					out << ", FT(" << scaleKeys[i].forward_tangent << "), BT(" << scaleKeys[i].backward_tangent << ")";
				} else if (scaleType == 3) {
					out << ", T " << scaleKeys[i].tension << ", B " << scaleKeys[i].bias << ", C " << scaleKeys[i].continuity;
				}
				out << endl;
			}
		}
	} else {
		out << "<<Data Not Shown>>" << endl;
	}

	//out << setprecision(1);

	return out.str();
}

/***********************************************************
 * NiColorData methods
 **********************************************************/

void NiColorData::Read( ifstream& in ) {
	colorCount = ReadUInt( in );
	keyType = ReadUInt( in );

	if (keyType != 1) {
		cout << "NiColorData is thought to only support keyType of 1, but this NIF has a keyType of " << keyType << ".  Please report it to NIFLA.  Aborting" << endl;
		throw runtime_error("Abort");
	}

	Key<fVector4> tmp;
	for (uint i = 0; i < colorCount; i++) {
		tmp.time = ReadFloat( in );
		ReadFVector4( tmp.data, in );
		keys.push_back(tmp);
	}
}

string NiColorData::asString() {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << "Color Count:  " << colorCount << endl
		<< "Key Type:  " << keyType << endl;

	if (verbose) {
		vector<Key<fVector4> >::iterator it;
		for ( it = keys.begin(); it != keys.end(); ++it ) {
			out << "Key Time:  " << (*it).time << "  Color:  " << (*it).data << endl;
		}
	} else {
		out << "<<Data Not Shown>>" << endl;
	}

	return out.str();
}

/***********************************************************
 * NiFloatData methods
 **********************************************************/

void NiFloatData::Read( ifstream& in ) {	
	colorCount = ReadUInt( in );
	keyType = ReadUInt( in );

	if (keyType != 2) {
		cout << "NiFloatata is thought to only support keyType of 2, but this NIF has a keyType of " << keyType << ".  Please report it to NIFLA.  Aborting" << endl;
		throw runtime_error("Abort");
	}

	Key<float> tmp;
	for (uint i = 0; i < colorCount; i++) {
		tmp.time = ReadFloat( in );
		tmp.data = ReadFloat( in );
		tmp.forward_tangent = ReadFloat( in );
		tmp.backward_tangent = ReadFloat( in );
		keys.push_back(tmp);
	}
}

string NiFloatData::asString() {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << "Vector Count:  " << colorCount << endl
		<< "Key Type:  " << keyType << endl;

	if (verbose) {
		vector<Key<float> >::iterator it;
		for ( it = keys.begin(); it != keys.end(); ++it ) {
			out << "Key Time:  " << it->time << "  Data: " << it->data << "  Forward: " << it->forward_tangent << "  Back: " << it->backward_tangent << endl;
		}
	} else {
		out << "<<Data Not Shown>>" << endl;
	}
	
	return out.str();
}

/***********************************************************
 * NiStringExtraData methods
 **********************************************************/

void NiStringExtraData::Read( ifstream& in ) {
	GetAttr("Next Extra Data")->Read( in );

	//Read Bytes Remaining but don't bother to store it
	ReadUInt( in );

	GetAttr("String Data")->Read( in );
}

void NiStringExtraData::Write( ofstream& out ) {
	WriteString( "NiStringExtraData", out );

	GetAttr("Next Extra Data")->Write( out );

	//Write Bytes Remaining - length of string + 4
	attr_ref string_data = GetAttr("String Data");
	
	WriteUInt( uint(string_data->asString().length()) + 4, out );

	string_data->Write( out );
}

string NiStringExtraData::asString() {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	attr_ref next_data = GetAttr("Next Extra Data");
	attr_ref string_data = GetAttr("String Data");

	out << next_data->GetName() << ":  " << next_data->asLink() << endl
		<< "Bytes Remaining:  " << uint(strData.length()) + 4 << endl
		<< string_data->GetName() << ":  " << string_data->asString() << endl;
	
	return out.str();
}

/***********************************************************
 * NiMorphData methods
 **********************************************************/

void NiMorphData::Read( ifstream& in ) {
	uint morphCount = ReadUInt( in );
	vertCount = ReadUInt( in );

	GetAttr("Unknown Byte")->Read( in );

	morphs.resize(morphCount);
	for ( uint i = 0; i < morphs.size() ; ++i ) {
		uint timeCount = ReadUInt( in );
		morphs[i].keyType = KeyType(ReadUInt( in ));

		if (timeCount > 0 && morphs[i].keyType != 2) {
			cout << "NiMorphData is thought to only support keyType of 2, but this NIF has a keyType of " << morphs[i].keyType << ".  Please report it to NifTools.  Aborting." << endl;
			throw runtime_error("Abort");
		}

		morphs[i].keys.resize( timeCount );
		for (uint j = 0; j < morphs[i].keys.size(); ++j ) {
			morphs[i].keys[j].time = ReadFloat( in );
			morphs[i].keys[j].data = ReadFloat( in );
			morphs[i].keys[j].forward_tangent = ReadFloat( in );
			morphs[i].keys[j].backward_tangent = ReadFloat( in );
		}
		
		morphs[i].morph.resize( vertCount );
		for (uint j = 0; j < vertCount ; ++j ) {
			morphs[i].morph[j].x = ReadFloat( in );
			morphs[i].morph[j].y = ReadFloat( in );
			morphs[i].morph[j].z = ReadFloat( in );
		}
	}
}

void NiMorphData::Write( ofstream& out ) {
	WriteString( "NiMorphData", out );

	WriteUInt( uint(morphs.size()), out );
	WriteUInt( vertCount, out );

	GetAttr("Unknown Byte")->Write( out );

	for ( uint i = 0; i < morphs.size() ; ++i ) {
		WriteUInt( uint(morphs[i].keys.size()), out );
		WriteUInt( KeyType(morphs[i].keyType), out );

		if (morphs[i].keys.size() > 0 && morphs[i].keyType != 2) {
			cout << "NiMorphData is thought to only support keyType of 2, but this NIF has a keyType of " << morphs[i].keyType << ".  Please report it to NifTools.  Aborting." << endl;
			throw runtime_error("Abort");
		}

		for (uint j = 0; j < morphs[i].keys.size(); ++j ) {
			WriteFloat( morphs[i].keys[j].time, out );
			WriteFloat( morphs[i].keys[j].data, out );
			WriteFloat( morphs[i].keys[j].forward_tangent, out );
			WriteFloat( morphs[i].keys[j].backward_tangent, out );
		}
		
		for (uint j = 0; j < vertCount ; ++j ) {
			WriteFloat( morphs[i].morph[j].x, out );
			WriteFloat( morphs[i].morph[j].y, out );
			WriteFloat( morphs[i].morph[j].z, out );
		}
	}
}

string NiMorphData::asString() {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << "Morph Count:  " << uint(morphs.size()) << endl
		<< "Vert Count:  " << vertCount << endl
		<< "Unknown Byte:  " << GetAttr("Unknown Byte")->asString() << endl;

	for ( uint i = 0; i < morphs.size() ; ++i ) {
		out << "---Morph " << i + 1 << "---" << endl;

		out << "Time Count:  " << uint(morphs[i].keys.size()) << endl
			<< "Key Type:  " << morphs[i].keyType << endl;
		
		if (verbose) {
			for (uint j = 0; j < morphs[i].keys.size(); ++j ) {
				out << "Key Time:  " << morphs[i].keys[j].time << " Influence?: " << morphs[i].keys[j].data << " F: " << morphs[i].keys[j].forward_tangent << " B: " << morphs[i].keys[j].backward_tangent << endl;
			}
			
			for (uint j = 0; j < vertCount ; ++j ) {
				out << "Morph " << j + 1 << ":  (" << morphs[i].morph[j].x << ", " << morphs[i].morph[j].y << ", " << morphs[i].morph[j].z << ")" << endl;
			}
		} else {
			out << "<<Data Not Shown>>" << endl;
		}
	}

	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);
	return out.str();
}

void NiMorphData::SetVertexCount( int n ) {
	vertCount = n;
	for ( uint i = 0; i < morphs.size(); ++i ) {
		morphs[i].morph.resize( n );
	}
}

void NiMorphData::SetMorphVerts( int n, const vector<Vector3> & in ) {
	// Make sure the size of the incoming vector equal vertCount
	if ( in.size() != vertCount )
		throw runtime_error("Input array size must equal Vertex Count.  Call SetVertexCount() to resize.");

	//It's the right size, so go ahead and set it
	morphs[n].morph = in;
}

/***********************************************************
 * NiPixelData methods
 **********************************************************/

void NiPixelData::Read( ifstream& in ) {
	unknownInt = ReadUInt( in );
	rMask = ReadUInt( in );
	gMask = ReadUInt( in );
	bMask = ReadUInt( in );
	aMask = ReadUInt( in );
	bpp = ReadUInt( in );
		
	for (int i = 0; i < 8; ++i) {
		unknown8Bytes[i] = ReadByte( in );
	}

	GetAttr("Unknown Index")->Read( in );

	mipCount = ReadUInt( in );
	bytesPerPixel = ReadUInt( in );

	MipMap temp;
	for ( uint i = 0; i < mipCount; ++i ) {
		temp.width = ReadUInt( in );
		temp.height = ReadUInt( in );
		temp.offset = ReadUInt( in );
		mipmaps.push_back(temp);
	}

	dataSize = ReadUInt( in );
	data = new byte[dataSize];
	in.read( (char *)data, dataSize);
}

string NiPixelData::asString() {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	Hex r_mask(rMask), b_mask(bMask), g_mask(gMask), a_mask(aMask);

	out << "Unknown Int:  " << unknownInt << endl
		<< "Red Mask:   " << r_mask << endl
		<< "Blue Mask:  " << b_mask << endl
		<< "Green Mask: " << g_mask << endl
		<< "Alpha Mask: " << a_mask << endl
		<< "Bits Per Pixel:  " << bpp << endl
		<< "Unknown 8 Bytes:" << endl;

	for (int i = 0; i < 8; ++i) {
		Hex unk8by(unknown8Bytes[i]);
		out << unk8by << "  ";
	}
	out << endl;

	out << "Unknown Index:  " <<  GetAttr("Next Extra Data")->asLink() << endl
		<< "Mipmap Count:  " << mipCount << endl
		<< "Bytes Per Pixel:  " << bytesPerPixel << endl;

	for ( uint i = 0; i < mipmaps.size(); ++i ) {
		out << "Mipmap " << i + 1 << ":" << endl
			<< "   Width:  "  << mipmaps[i].width << endl
			<< "   Height:  " << mipmaps[i].height << endl
			<< "   Offset into Image Data Block:  " << mipmaps[i].offset << endl;
	}

	out << "Mipmap Image Data:  "  << dataSize << " Bytes (Not Shown)" << endl;
	
	return out.str();
}

/***********************************************************
 * NiPosData methods
 **********************************************************/

void NiPosData::Read( ifstream& in ) {
	posCount = ReadUInt( in );
	keyType = ReadUInt( in );

	keys.resize(posCount);
	for (uint i = 0; i < keys.size(); i++) {
		keys[i].time = ReadFloat( in );
		ReadFVector3( keys[i].data, in );

		if (keyType == 2) {
			ReadFVector3( keys[i].forward_tangent, in );
			ReadFVector3( keys[i].backward_tangent, in );
		}

		if (keyType != 1 && keyType != 2) {
			cout << "NiPosData is thought to only support keyTypes of 1 and 2, but this NIF has a keyType of " << keyType << ".  Please report it to NIFLA.  Aborting" << endl;
			throw runtime_error("Abort");
		}
	}
}

string NiPosData::asString() {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << "Pos Count:  " << posCount << endl
		<< "Key Type:  " << keyType << endl;

	if (verbose) {
		for (uint i = 0; i < keys.size(); i++) {
			out << "Key Time:  " << keys[i].time << "   Position:  " << keys[i].data;

			if (keyType == 2) {
				out << " F: " << keys[i].forward_tangent << "  B: " << keys[i].backward_tangent;
			}
			out << endl;
		}
	} else {
		out << "<<Data Not Shown>>" << endl;
	}
	
	return out.str();
}

/***********************************************************
 * NiRotatingParticlesData methods
 **********************************************************/

void NiRotatingParticlesData::Read( ifstream& in ) {

 //   short count1

 //   int b1
 //   if(b1 != 0)
 //       foreach count1
 //           float[3] unknown

 //   int or float = 0
 //   float[4] unknown

 //   int b2
 //   if(b2 != 0)
 //       foreach count1
 //           float[4] unknown

 //   int = 0
 //   short unknown
 //   short count2             - always equal to count1 ?
 //   float unknown
 //   short unknown

 //   int b3
 //   if(b3 != 0)
 //       foreach count2 (or count1)
 //           float unknown

 //   int b4
 //   if(b4 != 0)
 //       foreach count2 (or count1)
 //           float[4] unknown

	ushort count1 = ReadUShort( in );
	uint b1 = ReadUInt( in );

	cout << "Count 1:  " << count1 << endl
		 << "Bool 1:  " << b1 << endl;

	if (b1) {
		fVector3 vect;
		for (uint i = 0; i < count1; ++i) {
			ReadFVector3( vect, in );
			cout << "Unknown 3 Floats:  " << vect << endl;
		}
	}

	uint unknownInt = ReadUInt( in );

	fVector4 unknown4Floats;
	ReadFVector4( unknown4Floats, in );
	uint b2 = ReadUInt( in );

	cout << "Unknown Int:  " << unknownInt << endl
		 << "Unknown 4 Floats:  " << unknown4Floats << endl
		 << "Bool 2:  " << b2 << endl;

	if (b2) {
		fVector4 unknown4Floats2;
		for (uint i = 0; i < count1; ++i) {
			ReadFVector4( unknown4Floats2, in );
			cout << "Unkown 4 Floats:  " << unknown4Floats2 << endl;
		}
	}

	uint unknownInt2 = ReadUInt( in );
	ushort unknownShort = ReadUShort( in );
	ushort count2 = ReadUShort( in );
	float unknownFloat = ReadFloat( in );
	ushort unknownShort2 = ReadUShort( in );
	uint b3 = ReadUInt( in );

	cout << "Unknown Int 2:  " << unknownInt2 << endl
		 << "Unknown Short:  " << unknownShort << endl
		 << "Count 2:  " << count2 << endl
		 << "Unknown Float:  " << unknownFloat << endl
		 << "Unknown Short 2:  " << unknownShort2 << endl
		 << "Bool 3:  " << b3 << endl;

	if (b3) {
		float temp;
		for (uint i = 0; i < count1; ++i) {
			temp = ReadFloat( in );
			cout << "Unkown Float:  " << temp << endl;
		}
	}

	uint b4 = ReadUInt( in );

	cout << "Bool 4:  " << b4 << endl;

	if (b4) {
		fVector4 unknown4Floats3;
		for (uint i = 0; i < count1; ++i) {
			ReadFVector4( unknown4Floats3, in );
			cout << "Unkown 4 Floats:  " << unknown4Floats3 << endl;
		}
	}

	//int len = BlockSearch(in);

	////Create byte array and read in unknown block
	//byte * data = new byte [len];
	//in.read((char*)data, len);

	//Display Data in Hex form
	//cout << hex << setfill('0');
	//for (int j = 0; j < len; j++) {
	//	cout << uppercase << setw(2) << uint(data[j]);
	//	if (j % 16 == 15 || j == len - 1)
	//		cout << endl;
	//	else if (j % 16 == 7)
	//		cout << "   ";
	//	else if (j % 8 == 3)
	//		cout << "  ";
	//	else
	//		cout << " ";
	//}
	//cout << dec << setfill(' ');

	/*delete [] data;*/

	//if (count1 != count2) {
	//	cout << "\a";
	//	cin.get();
	//}
}

/***********************************************************
 * NiTextKeyExtraData methods
 **********************************************************/

void NiTextKeyExtraData::Read( ifstream& in ) {

	GetAttr("Next Extra Data")->Read( in );
	GetAttr("Unknown Int")->Read( in );

	uint keyCount = ReadUInt( in );

	_keys.resize(keyCount);
	for (uint i = 0; i < _keys.size(); ++i ) {
		_keys[i].time = ReadFloat( in );
		_keys[i].data = ReadString( in );
	}
}

void NiTextKeyExtraData::Write( ofstream& out ) {

	WriteString( "NiTextKeyExtraData", out );

	GetAttr("Next Extra Data")->Write( out );
	GetAttr("Unknown Int")->Write( out );

	WriteUInt( uint(_keys.size()), out );

	for (uint i = 0; i < _keys.size(); ++i ) {
		WriteFloat( _keys[i].time, out );
		WriteString( _keys[i].data, out );
	}
}

string NiTextKeyExtraData::asString() {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << "Next Extra Data:  " <<  GetAttr("Next Extra Data")->asLink() << endl
		<< "Unknown Int (Key Type?):  " << GetAttr("Unknown Int")->asInt() << endl
		<< "Key Count:  " << uint(_keys.size()) << endl;

	if (verbose) {
		for (uint i = 0; i < _keys.size(); ++i ) {
			out << "Key Time:  " << _keys[i].time << endl
				<< "Key Text:  " << _keys[i].data << endl;
		}
	} else {
		out << "<<Data Not Shown>>" << endl;
	}
	
	return out.str();
}

/***********************************************************
 * NiUVData methods
 **********************************************************/

void NiUVData::Read( ifstream& in ) {	
	for (uint i = 0; i < 4; ++i) {
		groups[i].count = ReadUInt( in );

		if ( groups[i].count > 0 ) {
			groups[i].keyType = ReadUInt( in );

			groups[i].keys.resize(groups[i].count);
			for (uint j = 0; j < groups[i].keys.size(); ++j) {
				groups[i].keys[j].time = ReadFloat( in );
				groups[i].keys[j].data = ReadFloat( in );

				if ( groups[i].keyType == 2) {
					groups[i].keys[j].forward_tangent = ReadFloat( in );
					groups[i].keys[j].backward_tangent = ReadFloat( in );
				}
			}
		}
	}
}

string NiUVData::asString() {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	for (uint i = 0; i < 4; ++i) {
		out << "UV Group " << i + 1 << ":" << endl
			<< "   Count:  " << groups[i].count << endl;

		if ( groups[i].count > 0 ) {
			out << "   Key Type:  " << groups[i].keyType << endl;

			if (verbose) {
				for (uint j = 0; j < groups[i].keys.size(); ++j) {
					out << "   Key Time:  " << groups[i].keys[j].time << " Data:  " << groups[i].keys[j].data;

					if ( groups[i].keyType == 2) {
						out << "  F: " << groups[i].keys[j].forward_tangent << "  B: " << groups[i].keys[j].backward_tangent;
					}
					out << endl;
				}
			} else {
				out << "<<Data Not Shown>>" << endl;
			}
		}
	}

	return out.str();
}

/***********************************************************
 * NiVertWeightsExtraData methods
 **********************************************************/
 
void NiVertWeightsExtraData ::Read( ifstream& in ) {
	GetAttr("Next Extra Data")->Read( in );
	bytes = ReadUInt( in );
	verts = ReadUShort( in );

	weights.resize( verts );
	for (uint i = 0; i < weights.size(); ++i) {
		weights[i] = ReadFloat( in );
	}
}

string NiVertWeightsExtraData::asString() {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << "Next Extra Data:  " <<  GetAttr("Next Extra Data")->asLink() << endl
		<< "Bytes:  " << bytes << endl
		<< "Verts:  " << verts << endl;

	if (verbose) {
		for (uint i = 0; i < weights.size(); ++i) {
			out << "Weight " << i + 1 << ":  " << weights[i] << endl;
		}		
	} else {
		out << "<<Data Not Shown>>" << endl;
	}

	return out.str();
}

/***********************************************************
 * NiVisData methods
 **********************************************************/

void NiVisData ::Read( ifstream& in ) {
	visCount = ReadUInt( in );

	keys.resize( visCount );
	for (uint i = 0; i < keys.size(); ++i) {
		keys[i].time = ReadFloat( in );
		keys[i].data = ReadByte( in ); // Is Visible? True/False
	}
}

string NiVisData::asString() {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << "Visibility Count:  "  << visCount << endl;

	if (verbose) {
		for (uint i = 0; i < keys.size(); ++i) {
			out << "Key Time:  " << keys[i].time << "  Visible:  " << int(keys[i].data) << endl;
		}		
	} else {
		out << "<<Data Not Shown>>" << endl;
	}

	return out.str();
}

/***********************************************************
 * UnknownMixIn methods
 **********************************************************/

void UnknownMixIn::Read( ifstream &in ) {
	len = BlockSearch(in);

	//Create byte array and read in unknown block
	data = new byte [len];
	in.read((char*)data, len);
}

string UnknownMixIn::asString() {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << "Unknown Data (" << len << " bytes):" << endl;
	
	if (verbose) {
		//Display Data in Hex form
		out << hex << setfill('0');
		for (int j = 0; j < len; j++) {
			out << uppercase << setw(2) << uint(data[j]);
			if (j % 16 == 15 || j == len - 1)
				out << endl;
			else if (j % 16 == 7)
				out << "   ";
			else if (j % 8 == 3)
				out << "  ";
			else
				out << " ";
		}
		out << dec << setfill(' ');
	} else {
		out << "<<Data Not Shown>>" << endl;
	}

	return out.str();
}

void UnknownMixIn::Write( ofstream& out ) {
	out.write( (const char*)data, len );
}

//int len = BlockSearch(in);

////Create byte array and read in unknown block
//byte * data = new byte [len];
//in.read((char*)data, len);

////Display Data in Hex form
//cout << hex << setfill('0');
//for (int j = 0; j < len; j++) {
//	cout << uppercase << setw(2) << uint(data[j]);
//	if (j % 16 == 15 || j == len - 1)
//		cout << endl;
//	else if (j % 16 == 7)
//		cout << "   ";
//	else if (j % 8 == 3)
//		cout << "  ";
//	else
//		cout << " ";
//}
//cout << dec << setfill(' ');

//delete [] data;
