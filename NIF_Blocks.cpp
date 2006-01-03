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

void ABlock::AddAttr( AttrType type, string const & name, unsigned int first_ver, unsigned int last_ver ) {
	IAttr * attr;
	if ( type == attr_int ) {
		attr = new IntAttr( name, this, first_ver, last_ver );
	} else if ( type == attr_short ) {
		attr = new ShortAttr( name, this, first_ver, last_ver );
	} else if ( type == attr_byte ) {
		attr = new ByteAttr( name, this, first_ver, last_ver );
	} else if ( type == attr_float ) {
		attr = new FloatAttr( name, this, first_ver, last_ver );
	} else if ( type == attr_float3 ) {
		attr = new Float3Attr( name, this, first_ver, last_ver );
	} else if ( type == attr_string ) {
		attr = new StringAttr( name, this, first_ver, last_ver );
	} else if ( type == attr_link ) {
		attr = new LinkAttr( name, this, first_ver, last_ver );
	} else if ( type == attr_flags ) {
		attr = new FlagsAttr( name, this, first_ver, last_ver );
	} else if ( type == attr_matrix33 ) {
		attr = new MatrixAttr( name, this, first_ver, last_ver );
	} else if ( type == attr_linkgroup ) {
		attr = new LinkGroupAttr( name, this, first_ver, last_ver );
	} else if ( type == attr_bones ) {
		attr = new BoneAttr( name, this, first_ver, last_ver );
	} else if ( type == attr_bbox ) {
		attr = new BBoxAttr( name, this, first_ver, last_ver );
	} else if ( type == attr_condint ) {
		attr = new CIntAttr( name, this, first_ver, last_ver );
	} else if ( type == attr_vertmode ) {
		attr = new VertModeAttr( name, this, first_ver, last_ver );
	} else if ( type == attr_lightmode ) {
		attr = new LightModeAttr( name, this, first_ver, last_ver );
	} else if ( type == attr_texture ) {
		attr = new TexDescAttr( name, this, first_ver, last_ver );
	} else if ( type == attr_bumpmap ) {
		attr = new BumpMapAttr( name, this, first_ver, last_ver );
	} else if ( type == attr_applymode ) {
		attr = new ApplyModeAttr( name, this, first_ver, last_ver );
	} else if ( type == attr_texsource ) {
		attr = new TexSourceAttr( name, this, first_ver, last_ver );
	} else if ( type == attr_pixellayout ) {
		attr = new PixelLayoutAttr( name, this, first_ver, last_ver );
	} else if ( type == attr_mipmapformat ) {
		attr = new MipMapFormatAttr( name, this, first_ver, last_ver );
	} else if ( type == attr_alphaformat ) {
		attr = new AlphaFormatAttr( name, this, first_ver, last_ver );
	} else if ( type == attr_controllertarget ) {
		attr = new ControllerTargetAttr( name, this, first_ver, last_ver );
	} else if ( type == attr_skeletonroot ) {
		attr = new SkeletonRootAttr( name, this, first_ver, last_ver );
	} else if ( type == attr_particlegroup ) {
		attr = new ParticleGroupAttr( name, this, first_ver, last_ver );
	} else if ( type == attr_lodrangegroup ) {
		attr = new LODRangeGroupAttr( name, this, first_ver, last_ver );
	} else if ( type == attr_vector3 ) {
		attr = new Vector3Attr( name, this, first_ver, last_ver );
	} else if ( type == attr_color3 ) {
		attr = new Color3Attr( name, this, first_ver, last_ver );
	} else if ( type == attr_parent ) {
		attr = new ParentAttr( name, this, first_ver, last_ver );
	} else {
		cout << type << endl;
		throw runtime_error("Unknown attribute type requested.");
	}

	_attr_map[name] = attr_ref(attr);
	_attr_vect.push_back(attr_ref(attr));
}

attr_ref ABlock::GetAttr(string const & attr_name) const {
	map<string, attr_ref>::const_iterator it;
	it = _attr_map.find(attr_name);
	if (it == _attr_map.end()) {
		//cout << "Requested Attribute does not exist:  " << attr_name << endl;
		return attr_ref(NULL);
	} else {
		return attr_ref((*it).second);
	}
	//return _attr_map[attr_name]; 
}


vector<attr_ref> ABlock::GetAttrs() const {
	return _attr_vect;
}

blk_ref ABlock::GetParent() const {
	if (_parents.size() > 0 )
		return blk_ref(_parents[0]);
	else
		return blk_ref(-1);
}

void ABlock::Read( ifstream& in, unsigned int version ) {

	//Read Attributes
	for (unsigned int i = 0; i < _attr_vect.size(); ++i ) {
		_attr_vect[i]->Read( in, version );
		//if ( _attr_vect[i]->GetType() != "bones" ) {
		//	cout << "   " << _attr_vect[i]->GetName() << ":  " << _attr_vect[i]->asString() << endl;
		//}
	}
	//map<string, attr_ref>::iterator it;
	//it = _attr_map.find("Scale");
	//if (it != _attr_map.end()) {
	//	if ( _attr_map["Scale"]->asFloat() != 1.0f ) {
	//		cout << "\a Non-1.0 Scale found!!!" << endl;
	//		cin.get();
	//	}
	//}
}

void ABlock::Write( ofstream& out, unsigned int version ) const {

	//Write Attributes
	for (unsigned int i = 0; i < _attr_vect.size(); ++i ) {
		//cout << "Writing " << blk_ref(this) << " " << _attr_vect[i]->GetName() << endl;
		_attr_vect[i]->Write( out, version );
	}
}

string ABlock::asString() const {
	// Create a stringstream and set the floating point format
	// fixed notation with one decimal place
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	//Output the first parent of this block
	out << "Parent:  " << GetParent() << endl;

	//Output Attributes
	for (unsigned int i = 0; i < _attr_vect.size(); ++i ) {
		out << _attr_vect[i]->GetName() << ":  " << _attr_vect[i]->asString() << endl;
	}

	//Return result as a string
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

list<blk_ref> ABlock::GetLinks() const {
	list<blk_ref> links;

	//Search through all attributes for any links and add them to the list
	vector<attr_ref>::const_iterator it;
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

void const * ANode::QueryInterface( int id ) const {
	// Contains INode Interface
	if ( id == ID_NODE ) {
		return (void const *)static_cast<INode const *>(this);
	} else if (id == NodeInternal ) {
		return (void const *)static_cast<INodeInternal const *>(this);
	} else {
		return ABlock::QueryInterface( id );
	}
}

Matrix44 ANode::GetLocalTransform() const {
	//Get transform data from atributes
	Matrix33 f = GetAttr("Rotation")->asMatrix33();
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

Matrix44 ANode::GetWorldTransform() const {
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

Matrix44 ANode::GetWorldBindPos() const {
	return bindPosition;
	//for (int i = 0; i < 4; ++i) {
	//	for (int j = 0; j < 4; ++j) {
	//		out_matrix[i][j] = bindPosition[i][j];
	//	}
	//}
}

Matrix44 ANode::GetLocalBindPos() const {
	//Get Parent Transform if there is one
	blk_ref par = GetParent();
	INode * node;
	if ( par.is_null() == false && ( node = (INode*)par->QueryInterface(ID_NODE) ) != NULL) {
		//There is a node parent
		//multiply its inverse with this block's bind position to get the local bind position
		Matrix44 par_mat = node->GetWorldBindPos();
		Matrix44 par_inv = InverseMatrix44( par_mat);
		
		return MultMatrix44( bindPosition, par_inv);
	}
	else {
		//No parent transform, simply return local transform
		return GetWorldBindPos();
	}
}

void ANode::SetWorldBindPos( Matrix44 const & m ) {
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

string NiNode::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);
	
	out << ABlock::asString();

	//Matrix33 m;
	//GetAttr("Rotation")->asMatrix33( m );

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

		list<IBlock*>::const_iterator it;
		for (it = skin_refs.begin(); it != skin_refs.end(); ++it ) {
			out << "   " << blk_ref(*it) << endl;
		}
	}

	return out.str();
}

/***********************************************************
 * AShapeData methods
 **********************************************************/

/**
 * AShapeData::Read - Assumes block name has already been read from in
 */
void AShapeData::Read( ifstream& in, unsigned int version ){

	GetAttr("Name")->Read( in, version );
	
	short vert_count = ReadUShort( in );

	//There is an unknown short here from version 10.1.0.0 on
	if ( version >= VER_10_1_0_0 ) {
		ReadUShort( in );
	}

	bool hasVertices = ReadBool( in, version );
	if ( hasVertices != 0 ){
		vertices.resize( vert_count );
		for ( uint i = 0; i < vertices.size(); ++i ){
			vertices[i].x = ReadFloat( in );
			vertices[i].y = ReadFloat( in );
			vertices[i].z = ReadFloat( in );
		}
	}

	/// numTexSets up here up from version 10.0.1.0 on
	short numTexSets;
	
	if ( version >= VER_10_0_1_0 ) {
		numTexSets = ReadUShort( in );
	}

	//There is an unknown byte here after version 10.2.0.0
	byte unkByte;
	if ( version >= VER_10_2_0_0 ) {
		unkByte = ReadByte( in );
	}

	bool hasNormals = ReadBool( in, version );;
	if ( hasNormals != 0 ){
		normals.resize( vert_count );
		for ( uint i = 0; i < normals.size(); ++i ){
			normals[i].x = ReadFloat( in );
			normals[i].y = ReadFloat( in );
			normals[i].z = ReadFloat( in );
		}
	}

	//After version 10.2.0.0 there's several unknown vectors here
	if ( version >= VER_10_2_0_0 && unkByte != 0 ) {
		for ( uint i = 0; i < normals.size(); ++i ){
			ReadFloat( in );
			ReadFloat( in );
			ReadFloat( in );

			ReadFloat( in );
			ReadFloat( in );
			ReadFloat( in );
		}
	}

	GetAttr("Center")->Read( in, version );
	GetAttr("Radius")->Read( in, version );

	bool hasVertexColors = ReadBool( in, version );;
	if ( hasVertexColors != 0 ){
		colors.resize( vert_count );
		for ( uint i = 0; i < colors.size(); ++i ){
			colors[i].r = ReadFloat( in );
			colors[i].g = ReadFloat( in );
			colors[i].b = ReadFloat( in );
			colors[i].a = ReadFloat( in );
		}
	}
	// numTexSets down here up to version 4.2.2.0
	if ( version <= VER_4_2_2_0 ) {
		numTexSets = ReadUShort( in );
	}
	// hasUVs does not exist after version 4.0.0.2
	bool hasUVs = true;
	if ( version <= VER_4_0_0_2 ) {
		hasUVs = ReadBool( in, version );
	}
	if ( numTexSets > 0 && hasUVs == true ){
		uv_sets.resize( numTexSets );
		for ( uint i = 0; i < uv_sets.size(); ++i ){
			uv_sets[i].resize( vert_count );
			for ( uint j = 0; j < uv_sets[i].size(); ++j){
				uv_sets[i][j].u = ReadFloat( in );
				uv_sets[i][j].v = ReadFloat( in );
			}
		}
	}

	//Unknown Short here from version 10.0.1.0 on
	//Just read it and throw it away for now
	if ( version >= VER_10_0_1_0) {
		ReadUShort( in );
	}

	GetAttr("Unknown Link")->Read( in, version );
}

string AShapeData::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << "Name:  " << GetAttr("Name")->asString() << endl;

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

	out << "Unknown Link:  " << GetAttr("Unknown Link")->asString() << endl;

	return out.str();
}

/**
 * AShapeData::Write
 */
void AShapeData::Write( ofstream& out, unsigned int version ) const {

	WriteUShort( ushort(vertices.size()), out );

	if ( vertices.size() > 0 )
		WriteBool( true, out, version );
	else
		WriteBool( false, out, version );

	for ( uint i = 0; i < vertices.size(); ++i ){
		WriteFloat( vertices[i].x, out );
		WriteFloat( vertices[i].y, out );
		WriteFloat( vertices[i].z, out );
	}

	if ( normals.size() > 0 )
		WriteBool( true, out, version );
	else
		WriteBool( false, out, version );

	for ( uint i = 0; i < normals.size(); ++i) {
		WriteFloat( normals[i].x, out );
		WriteFloat( normals[i].y, out );
		WriteFloat( normals[i].z, out );
	}

	GetAttr("Center")->Write( out, version );
	GetAttr("Radius")->Write( out, version );

	if ( colors.size() > 0 )
		WriteBool( true, out, version );
	else
		WriteBool( false, out, version );

	for ( uint i = 0; i < colors.size(); ++i ){
		WriteFloat( colors[i].r, out );
		WriteFloat( colors[i].g, out );
		WriteFloat( colors[i].b, out );
		WriteFloat( colors[i].a, out );
	}

	WriteUShort( ushort(uv_sets.size()), out );
	if ( uv_sets.size() > 0 && uv_sets[0].size() > 0 ) // hasUVs
		WriteBool( true, out, version );
	else
		WriteBool( false, out, version );

	for ( uint i = 0; i < uv_sets.size(); ++i) {
		for ( uint j = 0; j < uv_sets[i].size(); ++j) {
			WriteFloat( uv_sets[i][j].u, out );
			WriteFloat( uv_sets[i][j].v, out );
		}
	}
}

void * AShapeData::QueryInterface( int id ) {
	// Contains ShapeData Interface
	if ( id == ID_SHAPE_DATA ) {
		return (void*)static_cast<IShapeData*>(this);
	} else {
		return AData::QueryInterface( id );
	}
}

void const * AShapeData::QueryInterface( int id ) const {
	// Contains ShapeData Interface
	if ( id == ID_SHAPE_DATA ) {
		return (void const *)static_cast<IShapeData const *>(this);
	} else {
		return AData::QueryInterface( id );
	}
}

void AShapeData::SetVertexCount(int n) {
	if ( n > 65535 || n < 0 )
		throw runtime_error("Invalid Vertex Count: must be between 0 and 65535.");

	if ( n == 0 ) {
		vertices.clear();
		normals.clear();
		colors.clear();
		for (uint i = 0; i < uv_sets.size(); ++i) {
			uv_sets[i].clear();
		}
		return;
	}
	
	//n != 0
	vertices.resize(n);

	if ( normals.size() != 0 ) { 
		normals.resize(n);
	}
	if ( colors.size() != 0 ) {
		colors.resize(n);
	}
	for (uint i = 0; i < uv_sets.size(); ++i) {	
		uv_sets[i].resize(n);
	}
}

void AShapeData::SetUVSetCount(int n) {
	uv_sets.resize(n);
}

//--Setters--//
void AShapeData::SetVertices( const vector<Vector3> & in ) {
	if (in.size() != vertices.size() && in.size() != 0 )
		throw runtime_error("Vector size must equal Vertex Count or zero.  Call SetVertexCount() to resize.");
	vertices = in;
}

void AShapeData::SetNormals( const vector<Vector3> & in ) {
	if (in.size() != vertices.size() && in.size() != 0 )
		throw runtime_error("Vector size must equal Vertex Count or zero.  Call SetVertexCount() to resize.");
	normals = in;
}

void AShapeData::SetColors( const vector<Color4> & in ) {
	if (in.size() != vertices.size() && in.size() != 0 )
		throw runtime_error("Vector size must equal Vertex Count or zero.  Call SetVertexCount() to resize.");
	colors = in;
}

void AShapeData::SetUVSet( int index, const vector<TexCoord> & in ) {
	if (in.size() != vertices.size())
		throw runtime_error("Vector size must equal Vertex Count.  Call SetVertexCount() to resize.");
	uv_sets[index] = in;
}

/***********************************************************
 * AParticlesData methods
 **********************************************************/

void AParticlesData::Read( ifstream& in, unsigned int version ) {
	AShapeData::Read( in, version );

	//numActive exists up to version 4.0.0.2
	if ( version <= VER_4_0_0_2 ) {
		numActive = ReadUShort( in );
	}

	GetAttr("Active Radius")->Read( in, version );

	//numValid exists up to version 4.0.0.2
	if ( version <= VER_4_0_0_2 ) {
		numValid = ReadUShort( in );
	}

	GetAttr("Unknown Short")->Read( in, version );

	hasSizes = ReadBool( in, version );

	if ( hasSizes ) {
		sizes.resize( vertices.size() );
		for ( uint i = 0; i < sizes.size(); ++i ) {
			sizes[i] = ReadFloat( in );
		}
	}
}

void AParticlesData::Write( ofstream& out, unsigned int version ) const {
	AShapeData::Write( out, version );

	//numActive exists up to version 4.0.0.2
	if ( version <= VER_4_0_0_2 ) {
		WriteUShort( numActive, out );
	}

	GetAttr("Active Radius")->Write( out, version );

	//numValid exists up to version 4.0.0.2
	if ( version <= VER_4_0_0_2 ) {
		WriteUShort( numValid, out );
	}

	
	GetAttr("Unknown Short")->Write( out, version );

	WriteBool( hasSizes, out, version );

	if ( hasSizes ) {
		for ( uint i = 0; i < sizes.size(); ++i ) {
			WriteFloat( sizes[i], out );
		}
	}
}

string AParticlesData::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << AShapeData::asString();

	out << "Num Active:  " << numActive << endl
		<< "Active Radius:  " << GetAttr("Active Radius")->asFloat() << endl
		<< "Num Valid:  " << numValid << endl
		<< "Unknown Short:  " << GetAttr("Unknown Short")->asInt() << endl
		<< "Sizes:  ";
	
	if ( hasSizes ) {
		if (verbose) {
			for ( uint i = 0; i < sizes.size(); ++i) {
				out << i << ":  " << sizes[i] << endl;
			}
		} else {
			out << endl << "<<Data Not Shown>>";
		}
	} else {
		out << "None" << endl;
	}

	return out.str();
}

/***********************************************************
 * ARotatingParticlesData methods
 **********************************************************/

void ARotatingParticlesData::Read( ifstream& in, unsigned int version ) {
	AParticlesData::Read( in, version );

	hasRotations = ReadBool( in, version );

	if ( hasRotations ) {
		rotations.resize( vertices.size() );
		for ( uint i = 0; i < rotations.size(); ++i ) {
			rotations[i].w = ReadFloat( in );
			rotations[i].x = ReadFloat( in );
			rotations[i].y = ReadFloat( in );
			rotations[i].z = ReadFloat( in );
		}
	}
}

void ARotatingParticlesData::Write( ofstream& out, unsigned int version ) const {
	AParticlesData::Write( out, version );

	WriteBool( hasRotations, out, version );

	if ( hasRotations ) {
		for ( uint i = 0; i < rotations.size(); ++i ) {
			WriteFloat( rotations[i].w, out );
			WriteFloat( rotations[i].x, out );
			WriteFloat( rotations[i].y, out );
			WriteFloat( rotations[i].z, out );
		}
	}
}

string ARotatingParticlesData::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << AParticlesData::asString()
		<< "Rotations:  ";
	
	if ( hasRotations ) {
		if (verbose) {
			for ( uint i = 0; i < rotations.size(); ++i) {
				out << i << ":  [" << rotations[i].w << " (" << rotations[i].x << ", " << rotations[i].y << ", " << rotations[1].z << ")]" << endl;
			}
		} else {
			out << endl << "<<Data Not Shown>>";
		}
	} else {
		out << "None" << endl;
	}

	return out.str();
}

/***********************************************************
 * NiParticleMeshesData methods
 **********************************************************/

void NiParticleMeshesData::Read( ifstream& in, unsigned int version ) {
	ARotatingParticlesData::Read( in, version );

	GetAttr("Unknown Link")->Read( in, version );
}

void NiParticleMeshesData::Write( ofstream& out, unsigned int version ) const {
	ARotatingParticlesData::Write( out, version );

	GetAttr("Unknown Link")->Write( out, version );
}

string NiParticleMeshesData::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << ARotatingParticlesData::asString()
		<< "Unknown Link:  " << GetAttr("Unknown Link")->asString() << endl;

	return out.str();
}

/***********************************************************
 * NiTriShapeData methods
 **********************************************************/

/**
 * NiTriShapeData::Read - Assumes block name has already been read from in
 */
void NiTriShapeData::Read( ifstream& in, unsigned int version ){
	AShapeData::Read( in, version );

	short numTriangles = ReadUShort( in );
	int numVertexIndices = ReadUInt( in );
	
	//From version 10.1.0.0 on there is a bool to check whether or not there are any triangles
	//We already know the answer to this from the numTriangles count, don't we?
	//Jus in case, set numTriangles to zero if this is false.
	if ( version >= VER_10_1_0_0 ) {
		if ( ReadBool( in, version ) == false ) {
			numTriangles = 0;
		}
	}

	triangles.resize( numTriangles );
	for ( uint i = 0; i < triangles.size(); ++i ){
		triangles[i].v1 = ReadUShort( in );
		triangles[i].v2 = ReadUShort( in );
		triangles[i].v3 = ReadUShort( in );
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

string NiTriShapeData::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << AShapeData::asString();

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
void NiTriShapeData::Write( ofstream& out, unsigned int version ) const {

	AShapeData::Write( out, version );

	WriteUShort( ushort(triangles.size()), out );
	WriteUInt( ushort(triangles.size()) * 3, out );
	
	//From version 10.1.0.0 on there is a bool to check whether or not there are any triangles
	if ( version >= VER_10_1_0_0 ) {
		WriteBool( triangles.size() > 0, out, version );
	}

	for ( uint i = 0; i < triangles.size(); ++i ){
		WriteUShort( triangles[i].v1, out );
		WriteUShort( triangles[i].v2, out );
		WriteUShort( triangles[i].v3, out );
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
		return AShapeData::QueryInterface( id );
	}
}

void const * NiTriShapeData::QueryInterface( int id ) const {
	// Contains TriShapeData Interface
	if ( id == ID_TRI_SHAPE_DATA ) {
		return (void const *)static_cast<ITriShapeData const *>(this);
	} else {
		return AShapeData::QueryInterface( id );
	}
}

void NiTriShapeData::SetTriangleCount(int n) {
	if ( n > 65535 || n < 0 )
		throw runtime_error("Invalid Triangle Count: must be between 0 and 65535.");

	if ( n == 0 )
		triangles.clear();
	else
		triangles.resize(n);
}

//--Setters--//

void NiTriShapeData::SetTriangles( const vector<Triangle> & in ) {
	if (in.size() != triangles.size())
		throw runtime_error("Vector size must equal Triangle Count.  Call SetTriangleCount() to resize.");
	triangles = in;
}

/***********************************************************
 * NiTriStripsData methods
 **********************************************************/

void NiTriStripsData::Read( ifstream& in, unsigned int version ){
	AShapeData::Read( in, version );

	//Read number of Triangles but discard it
	ReadUShort( in );

	//Initialize vectors to number and size of strips
	short numStrips = ReadUShort( in );
	strips.resize( numStrips );
	for ( uint i = 0; i < strips.size(); ++i ) {
		short stripSize = ReadUShort( in );
		strips[i].resize( stripSize );
	}

	//From version 10.1.0.0 on there is a bool to check whether or not there are any points
	//We already know the answer to this from the counts above, don't we?
	//Jus in case, clear all strips if this is false.
	if ( version >= VER_10_1_0_0 ) {
		if ( ReadBool( in, version ) == false ) {
			strips.clear();
		}
	}

	//Read points
	for ( uint i = 0; i < strips.size(); ++i ) {
		for ( uint j = 0; j < strips[i].size(); ++j ) {
			strips[i][j] = ReadUShort( in );
		}
	}
}

void NiTriStripsData::Write( ofstream& out, unsigned int version ) const {

	AShapeData::Write( out, version );

	//Write number of triangles and strips
	short numTriangles = GetTriangleCount();
	WriteUShort( numTriangles, out );
	WriteUShort( ushort(strips.size()), out );

	//Write Strip Sizes
	for ( uint i = 0; i < strips.size(); ++i ) {
		WriteUShort( ushort(strips[i].size()), out );
	}

	//From version 10.1.0.0 on there is a bool to check whether or not there are any points
	if ( version >= VER_10_1_0_0 ) {
		WriteBool( numTriangles > 0, out, version );
	}

	//Write points
	for ( uint i = 0; i < strips.size(); ++i ) {
		for ( uint j = 0; j < strips[i].size(); ++j ) {
			WriteUShort( strips[i][j], out );
		}
	}
}

string NiTriStripsData::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << AShapeData::asString();

	out << "Triangles:  " << GetTriangleCount() << endl
		<< "Strips:  " << ushort(strips.size()) << endl;

	if (verbose) {
		for ( uint i = 0; i < strips.size(); ++i ) {
			out << "   Strip " << i + 1 << endl;
			for ( uint j = 0; j < strips[i].size(); ++j ) {
				out << "      " << strips[i][j] << endl;
			}
		}
	} else {
		out << endl << "   <<Data Not Shown>>";
	}

	return out.str();
}

void * NiTriStripsData::QueryInterface( int id ) {
	// Contains TriShapeData Interface
	if ( id == ID_TRI_STRIPS_DATA ) {
		return (void*)static_cast<ITriStripsData*>(this);
	} else {
		return AShapeData::QueryInterface( id );
	}
}

void const * NiTriStripsData::QueryInterface( int id ) const {
	// Contains TriShapeData Interface
	if ( id == ID_TRI_STRIPS_DATA ) {
		return (void const *)static_cast<ITriStripsData const *>(this);
	} else {
		return AShapeData::QueryInterface( id );
	}
}

short NiTriStripsData::GetStripCount() const {
	return short(strips.size());
}

void NiTriStripsData::SetStripCount(int n) {
	strips.resize( n );
}

//Getters
vector<short> NiTriStripsData::GetStrip( int index ) const {
	return strips[index];
}

vector<Triangle> NiTriStripsData::GetTriangles() const {

	//Create a vector to hold the triangles
	vector<Triangle> triangles( GetTriangleCount() );
	int n = 0; // Current triangle

	//Cycle through all strips
	vector< vector<short> >::const_iterator it;
	for (it = strips.begin(); it != strips.end(); ++it ) {
		//The first three values in the strip are the first triangle
		triangles[n].Set( (*it)[0], (*it)[1], (*it)[2] );

		//Move to the next triangle
		++n;

		//The remaining triangles use the previous two indices as their first two indices.
		for( uint i = 3; i < it->size(); ++i ) {
			//Odd numbered triangles need to be reversed to keep the vertices in counter-clockwise order
			if ( i % 2 == 0 )
				triangles[n].Set( (*it)[i - 2], (*it)[i - 1], (*it)[i] );
			else
				triangles[n].Set( (*it)[i], (*it)[i - 1], (*it)[i - 2] );

			//Move to the next triangle
			++n;
		}
	}

	return triangles;
}

//Setter
void NiTriStripsData::SetStrip( int index, const vector<short> & in ) {
	strips[index] = in;
}

short NiTriStripsData::GetTriangleCount() const {

	//Calculate number of triangles
	//Sum of length of each strip - 2
	short numTriangles = 0;
	for ( uint i = 0; i < strips.size(); ++i ) {
		numTriangles += short(strips[i].size() - 2);
	}

	return numTriangles;
}

	

/***********************************************************
 * NiCollisionData methods
 **********************************************************/

void NiCollisionData::Read( ifstream& in, unsigned int version ){
	//Read parent node but don't store it
	ReadUInt( in );

	unknownInt1 = ReadUInt( in );
	unknownByte = ReadByte( in );
	collisionType = ReadUInt( in );

	if ( collisionType == 0 ) {
		unknownInt2 = ReadUInt( in );
		ReadFVector3( unknown3Floats, in );
	} 
	else if ( collisionType == 1 ) {
		for (int i = 0; i < 15; ++i ) {
			unknown15Floats[i] = ReadFloat( in );
		}
	} 
	else if ( collisionType == 2) {
		for ( int i = 0; i < 8; ++i ) {
			unknown8Floats[i] = ReadFloat( in );
		}
	} 
}

void NiCollisionData::Write( ofstream& out, unsigned int version ) const {

	//Write Parent node number
	WriteUInt( GetParent().get_index(), out );

	WriteUInt( unknownInt1, out );
	WriteByte( unknownByte, out );
	WriteUInt( collisionType, out );

	if ( collisionType == 0 ) {
		WriteUInt( unknownInt2, out );
		WriteFVector3( unknown3Floats, out );
	} 
	else if ( collisionType == 1 ) {
		for (int i = 0; i < 15; ++i ) {
			WriteFloat( unknown15Floats[i], out );
		}
	} 
	else if ( collisionType == 2) {
		for ( int i = 0; i < 8; ++i ) {
			WriteFloat( unknown8Floats[i], out );
		}
	} 
}

string NiCollisionData::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	//Parent is already written, so don't do anything with it

	out << "Unknown Int 1:  " << unknownInt1 << endl
		<< "Unknown Byte:  " << unknownByte << endl
		<< "Collision Type:  " << collisionType << endl
		<< "Collision Data:" << endl;

	if ( collisionType == 0 ) {
		out << "   Unknown Int 2:  " << unknownInt2 << endl
			<< "   Unknown 3 Floats:   " << unknown3Floats << endl;
	} 
	else if ( collisionType == 1 ) {
		out << "   Unknown 15 Floats:" << endl;
		for (int i = 0; i < 15; ++i ) {
			out << "      " << i + 1 << ":  " << unknown15Floats[i] << endl;
		}
	} 
	else if ( collisionType == 2) {
		out << "   Unknown 8 Floats:" << endl;
		for ( int i = 0; i < 8; ++i ) {
			out << "      " << i + 1 << ":  " << unknown8Floats[i] << endl;
		}
	} 

	return out.str();
}

/***********************************************************
 * NiSkinData methods
 **********************************************************/

void NiSkinData::Read( ifstream& in, unsigned int version ) {
	
	for (int c = 0; c < 3; ++c) {
		for (int r = 0; r < 3; ++r) {
			rotation[r][c] = ReadFloat( in );
		}
	}
	ReadFVector3( translation, in );
	scale = ReadFloat( in );
	int boneCount = ReadUInt( in );
	GetAttr("Skin Partition")->Read( in, version );
	//unknownByte exists from version 4.2.1.0 on
	if ( version >= VER_4_2_1_0 ) {
		unknownByte = ReadByte( in );
	}
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

void NiSkinData::Write( ofstream& out, unsigned int version ) const {
	//Calculate offset matrices prior to writing data

	Matrix33 rot;
	fVector3 tr;
	float sc;
	CalculateOverallOffset(rot, tr, sc);

	for (int c = 0; c < 3; ++c) {
		for (int r = 0; r < 3; ++r) {
			WriteFloat( rot[r][c], out );
		}
	}
	WriteFVector3( tr, out );
	WriteFloat( sc, out );
	WriteUInt(short(bone_map.size()), out);
	GetAttr("Skin Partition")->Write( out, version );
	//unknownByte exists from version 4.2.1.0 on
	if ( version >= VER_4_2_1_0) {
		WriteByte( unknownByte, out );
	}

	//Get parent node for bone calculations
	INode const * const par_node = this->GetNodeParent();
	Bone bone; // temporary value

	map<IBlock *, Bone >::const_iterator it;
	int num = 0;
	for( it = bone_map.begin(); it != bone_map.end(); ++it ) {
		//Calculae offset for this bone (data is not stored)
		CalculateBoneOffset( par_node, it->first, bone );	

		for (int c = 0; c < 3; ++c) {
			for (int r = 0; r < 3; ++r) {
				WriteFloat( bone.rotation[r][c], out );
			}
		}
		WriteFVector3( bone.translation, out );
		WriteFloat( bone.scale, out );

		//Write 4 zeros for unknown floats
		WriteFloat( 0.0f, out );
		WriteFloat( 0.0f, out );
		WriteFloat( 0.0f, out );
		WriteFloat( 0.0f, out );

		//WriteFVector4( bone.unknown4Floats, out );

		WriteUShort( short(it->second.weights.size() ), out );
		
		map<int, float>::const_iterator it2;
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
//		rot_attr->asMatrix33(temp);
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

string NiSkinData::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	//If there is no parent, do nothing
	if ( this->GetParent().is_null() == true ) {
		out << "No parent - data cannot be calculated." << endl
			<< ABlock::asString() << endl;
		return out.str();
	}
	
	Matrix33 rot;
	fVector3 tr;
	float sc;
	CalculateOverallOffset(rot, tr, sc);

	out << "Rotate:" << endl
		<< "   |" << setw(6) << rot[0][0] << "," << setw(6) << rot[0][1] << "," << setw(6) << rot[0][2] << " |" << endl
		<< "   |" << setw(6) << rot[1][0] << "," << setw(6) << rot[1][1] << "," << setw(6) << rot[1][2] << " |" << endl
		<< "   |" << setw(6) << rot[2][0] << "," << setw(6) << rot[2][1] << "," << setw(6) << rot[2][2] << " |" << endl
		<< "Translate:  " << tr << endl
		<< "Scale:  " << sc << endl
		<< "Bone Count:  " << uint(bone_map.size()) << endl
		<< "Skin Partition:  " << GetAttr("Skin Partition")->asLink() << endl
		<< "Unknown Byte:  " << int(unknownByte) << endl
		<< "Bones:" << endl;

	//Get parent node for bone calculations
	INode const * const par_node = this->GetNodeParent();
	Bone bone; // temporary value

	map<IBlock *, Bone >::const_iterator it;
	int num = 0;
	for( it = bone_map.begin(); it != bone_map.end(); ++it ) {
		//Calculae offset for this bone (data is not stored)
		CalculateBoneOffset( par_node, it->first, bone );

		num++;
		out << "Bone " << num << ":" << endl
			<< "   Block:  " << it->first->GetBlockNum() << endl //blk_ref(it->first) << endl
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

		out << "   Weights:  " << uint( it->second.weights.size()) << endl;

		if (verbose) {
			map<int, float>::const_iterator it2;
			for ( it2 = it->second.weights.begin(); it2 != it->second.weights.end(); ++it2 ){
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

void const * NiSkinData::QueryInterface( int id ) const {
	// Contains ISkinData Interface
	if ( id == ID_SKIN_DATA ) {
		return (void const *)static_cast<ISkinData const *>(this);
	} else if ( id == SkinDataInternal ) {
		return (void const *)static_cast<ISkinDataInternal const *>(this);
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

		//---------------Problem Area---------------//
		//move the data
		bone_map.insert( pair<IBlock *, Bone>(bone_blocks[i].get_block(), bones[i]) );

		//Increment reference at bone node site
		node_int->IncSkinRef(this);
		//------------------------------------------//
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
	map<IBlock *, Bone>::iterator it;
	for ( it = bone_map.begin(); it != bone_map.end(); ++it ) {
		//Friendlier name for current bone
		Bone & bone = it->second;

		//Get current offset Matrix33 for this bone

		Matrix44 parent_offset(
			bone.rotation[0][0], bone.rotation[0][1], bone.rotation[0][2], 0.0f,
			bone.rotation[1][0], bone.rotation[1][1], bone.rotation[1][2], 0.0f,
			bone.rotation[2][0], bone.rotation[2][1], bone.rotation[2][2], 0.0f,
			bone.translation[0], bone.translation[1], bone.translation[2], 1.0f
		); 
		//Loop through all bones again, checking for any that have this bone as a parent
		map<IBlock *, Bone>::iterator it2;
		for ( it2 = bone_map.begin(); it2 != bone_map.end(); ++it2 ) {
			if ( it2->first->GetParent() == it->first ) {
				//Block 2 has block 1 as a parent

				Bone & bone2 = it2->second;

				//Get child offset Matrix33
				Matrix44 child_offset(
					bone2.rotation[0][0], bone2.rotation[0][1], bone2.rotation[0][2], 0.0f,
					bone2.rotation[1][0], bone2.rotation[1][1], bone2.rotation[1][2], 0.0f,
					bone2.rotation[2][0], bone2.rotation[2][1], bone2.rotation[2][2], 0.0f,
					bone2.translation[0], bone2.translation[1], bone2.translation[2], 1.0f
				);

				//Do calculation to get correct bone postion in relation to parent
				Matrix44 inverse_co = InverseMatrix44(child_offset);
				Matrix44 child_pos = MultMatrix44( inverse_co, parent_offset);

				//Store result in block's Bind Position Matrix
				INode * node = (INode*)it2->first->QueryInterface(ID_NODE);
				if (node != NULL) {
					node->SetWorldBindPos(child_pos);
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
		IBlock * bone_blk = bone_map.begin()->first;
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

		Matrix44 offset_mat(
			bone.rotation[0][0], bone.rotation[0][1], bone.rotation[0][2], 0.0f,
			bone.rotation[1][0], bone.rotation[1][1], bone.rotation[1][2], 0.0f,
			bone.rotation[2][0], bone.rotation[2][1], bone.rotation[2][2], 0.0f,
			bone.translation[0], bone.translation[1], bone.translation[2], 1.0f
		);
			
		//Get built up rotations to the root of the skeleton from this bone
		INode * bone_node = (INode*)bone_blk->QueryInterface(ID_NODE);
		if (bone_node == NULL)
			throw runtime_error("Failed to get Node interface.");

		Matrix44 bone_mat = bone_node->GetWorldBindPos();

		Matrix44 result_mat = MultMatrix44( offset_mat, bone_mat);

		//GetBuiltUpTransform( bone_blk, end_mat );

		//--Set TriShape Bind Position to Result--//
		INode * shape_node = (INode*)tri_shape->QueryInterface(ID_NODE);
		if (shape_node == NULL)
			throw runtime_error("Failed to get Node interface.");

		shape_node->SetWorldBindPos( result_mat );

		

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

	map<IBlock *, Bone>::const_iterator it;
	int count = 0;
	for (it = bone_map.begin(); it != bone_map.end(); ++it ) {
		bone_blks[count] = it->first;
		count++;
	}

	return bone_blks;
}

map<int, float> NiSkinData::GetWeights( blk_ref const & bone ) const {
	// since operator[] might insert a new element, it can't be const
	// so we need the find function
	return bone_map.find(bone.get_block())->second.weights;
}

void NiSkinData::AddBone( blk_ref const & bone, map<int, float> const & in ) {
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

void NiSkinData::RemoveBone( blk_ref const & bone ) {
	//Remove bone from internal list
	bone_map.erase( bone.get_block() );

	//Decrement reference at bone node site
	INodeInternal * node_int = (INodeInternal*)bone->QueryInterface(NodeInternal);
	node_int->DecSkinRef(this);
}

NiSkinData::~NiSkinData() {
	//Inform all linked bone nodes that this NiSkinData block is dying
	map<IBlock *, Bone>::iterator it;
	for (it = bone_map.begin(); it != bone_map.end(); ++it) {
		INodeInternal * node_int = (INodeInternal*)it->first->QueryInterface(NodeInternal);
		node_int->DecSkinRef(this);
	}
}

INode * NiSkinData::GetNodeParent() const {
	//--Get Node Parent Bind Pose--//

	blk_ref par_block;
	try {
		par_block = GetParent()->GetParent();
	}
	catch (...) {
		throw runtime_error("SkinData block does not have parent of parent.");
	}

	INode * par_node = (INode*)par_block->QueryInterface(ID_NODE);	
	if ( par_node == NULL )
		throw runtime_error("SkinData block's parent of parent is not a node.");

	return par_node;
}

void NiSkinData::CalculateBoneOffset( INode const * const par_node, IBlock const * const bone_block, Bone & result ) const {

	//--Get Bone Bind Pose--//

	//Get Bone Node
	INode * const bone_node = (INode*)bone_block->QueryInterface(ID_NODE);

	//Get bind matricies
	Matrix44 par_mat, bone_mat, inv_mat, res_mat;
	par_mat = par_node->GetWorldBindPos();
	bone_mat = bone_node->GetWorldBindPos();

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

	//--Store Result--//

	//Store rotation matrix
	for (int c = 0; c < 3; ++c) {
		for (int r = 0; r < 3; ++r) {
			result.rotation[r][c] = res_mat[r][c];
		}
	}

	//Store translate vector
	result.translation[0] = res_mat[3][0];
	result.translation[1] = res_mat[3][1];
	result.translation[2] = res_mat[3][2];

	
	//Store average scale
	result.scale = (scale[0] + scale[1] + scale[2]) / 3.0f;
}

void NiSkinData::CalculateOverallOffset( Matrix33 & rot, fVector3 & tr, float & sc ) const {
	// Node parent world transform
	INode const * par = this->GetNodeParent();
	Matrix44 par_mat = par->GetWorldTransform();
	
	// Skeleton root world transform
	blk_ref skel = GetParent()->GetAttr("Skeleton Root")->asLink();
	INode const * iskel = (INode const *)skel->QueryInterface(ID_NODE);
	if ( iskel == NULL )
		throw runtime_error("SkinInfluence skeleton root is not a node.");
	Matrix44 skel_mat = iskel->GetWorldTransform();
	
	// Inverse parent node transform & multiply with skeleton matrix
	Matrix44 inv_mat = InverseMatrix44(par_mat);
	Matrix44 res_mat = MultMatrix44(inv_mat, skel_mat);

	//--Extract Scale from first 3 rows--//
	float scale[3];
	for (int r = 0; r < 3; ++r) {
		//Get scale for this row
		scale[r] = sqrt(res_mat[r][0] * res_mat[r][0] + res_mat[r][1] * res_mat[r][1] + res_mat[r][2] * res_mat[r][2]);

		//Normalize the row by dividing each factor by scale
		res_mat[r][0] /= scale[r];
		res_mat[r][1] /= scale[r];
		res_mat[r][2] /= scale[r];
	}

	//--Store Result--//

	//Store rotation matrix
	for (int c = 0; c < 3; ++c)
		for (int r = 0; r < 3; ++r)
			rot[r][c] = res_mat[r][c];

	//Store translate vector
	tr[0] = res_mat[3][0];
	tr[1] = res_mat[3][1];
	tr[2] = res_mat[3][2];

	//Store average scale
	sc = (scale[0] + scale[1] + scale[2]) / 3.0f;
}

/***********************************************************
 * NiGeomMorpherController methods
 **********************************************************/

string NiGeomMorpherController::asString() const {
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

void NiKeyframeData::Read( ifstream& file, unsigned int version ) {

	scaleType = rotationType = translationType = xyzTypes[0] = xyzTypes[1] = xyzTypes[2] = KeyType(0);

	//--Rotation--//
	uint numRotations = ReadUInt( file );

	if (numRotations > 0) {
		NifStream( rotationType, file );

		if ( rotationType != 4 ) {
			rotKeys.resize( numRotations );
			for ( unsigned int i = 0; i < rotKeys.size(); ++i ) {
				NifStream(rotKeys[i], file, rotationType );
			}
		}
		else {
			//Read vestigial time and discard
			ReadFloat( file );

			for (int i = 0; i < 3; i++) {
				int subCount = ReadUInt( file );
				NifStream( xyzTypes[i], file );

				xyzKeys[i].resize( subCount );
				for (uint j = 0; j < xyzKeys[i].size(); j++) {
					NifStream(xyzKeys[i][j], file, xyzTypes[i] );
				}
			}
		}
	}

	//--Translation--//
	uint numTranslations = ReadUInt( file );

	if (numTranslations > 0) {
		NifStream( translationType, file );

		transKeys.resize( numTranslations );
		for ( unsigned int i = 0; i < transKeys.size(); ++i ) {
			NifStream(transKeys[i], file, translationType );
		}
	}

	//--Scale--//
	uint numScalings = ReadUInt( file );

	if (numScalings > 0) {
		NifStream( scaleType, file );

		scaleKeys.resize( numScalings );
		for ( unsigned int i = 0; i < scaleKeys.size(); ++i ) {
			NifStream(scaleKeys[i], file, scaleType );
		}
	}
}

void NiKeyframeData::Write( ofstream& file, unsigned int version ) const {

	//--Rotation--//
	WriteUInt( uint(rotKeys.size()) , file );

	if ( rotKeys.size() > 0) {
		NifStream( rotationType, file );

		if ( rotationType != 4 ) {
			for ( unsigned int i = 0; i < rotKeys.size(); ++i ) {
				NifStream(rotKeys[i], file, rotationType );
			}
		}
		else {
			//Write vestigial time
			WriteFloat( 0.0, file );

			for (int i = 0; i < 3; i++) {
				WriteUInt( uint(xyzKeys[i].size()) , file );
				NifStream( xyzTypes[i], file );

				for (uint j = 0; j < xyzKeys[i].size(); j++) {
					NifStream(xyzKeys[i][j], file, xyzTypes[i] );
				}
			}
		}
	}

	//--Translation--//
	WriteUInt( uint(transKeys.size()) , file );

	if ( transKeys.size() > 0) {
		NifStream( translationType, file );

		for ( unsigned int i = 0; i < transKeys.size(); ++i ) {
			NifStream(transKeys[i], file, translationType );
		}
	}

	//--Scale--//
	WriteUInt( uint(scaleKeys.size()), file );

	if (scaleKeys.size() > 0) {
		NifStream( scaleType, file );

		for ( unsigned int i = 0; i < scaleKeys.size(); ++i ) {
			NifStream(scaleKeys[i], file, scaleType );
		}
	}
}

string NiKeyframeData::asString() const {
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

void NiColorData::Read( ifstream& file, unsigned int version ) {
	uint keyCount = ReadUInt( file );
	NifStream( _type, file );

	_keys.resize( keyCount );
	for (uint i = 0; i < _keys.size(); i++) {
		NifStream( _keys[i], file, _type );
	}
}

void NiColorData::Write( ofstream& file, unsigned int version ) const {
	WriteUInt( uint(_keys.size()), file );
	NifStream( _type, file );

	for (uint i = 0; i < _keys.size(); i++) {
		NifStream( _keys[i], file, _type );
	}
}

string NiColorData::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << "Key Count:  " << uint(_keys.size()) << endl
		<< "Key Type:  " << _type << endl;

	if (verbose) {
		vector< Key<Color4> >::const_iterator it;
		for ( it = _keys.begin(); it != _keys.end(); ++it ) {
			out << "Key Time:  " <<  it->time << "  Color:  " << it->data.r << ", " << it->data.g << ", " << it->data.b << ", " << it->data.a << endl;
		}
	} else {
		out << "<<Data Not Shown>>" << endl;
	}

	return out.str();
}

/***********************************************************
 * NiFloatData methods
 **********************************************************/

void NiFloatData::Read( ifstream& file, unsigned int version ) {
	uint keyCount = ReadUInt( file );
	NifStream( _type, file );

	_keys.resize( keyCount );
	for (uint i = 0; i < _keys.size(); i++) {
		NifStream( _keys[i], file, _type );
	}
}

void NiFloatData::Write( ofstream& file, unsigned int version ) const {
	WriteUInt( uint(_keys.size()), file );
	NifStream( _type, file );

	for (uint i = 0; i < _keys.size(); i++) {
		NifStream( _keys[i], file, _type );
	}
}

string NiFloatData::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << "Key Count:  " << uint(_keys.size()) << endl
		<< "Key Type:  " << _type << endl;

	if (verbose) {
		vector< Key<float> >::const_iterator it;
		for ( it = _keys.begin(); it != _keys.end(); ++it ) {
			out << "Key Time:  " <<  it->time << "  Float Value:  " << it->data << endl;
		}
	} else {
		out << "<<Data Not Shown>>" << endl;
	}

	return out.str();
}

/***********************************************************
 * NiStringExtraData methods
 **********************************************************/

void NiStringExtraData::Read( ifstream& in, unsigned int version ) {
	AExtraData::Read( in, version );
	
	//GetAttr("Name")->Read( in, version );
	//GetAttr("Next Extra Data")->Read( in, version );
	

	//Up to version 4.2.2.0, read bytes remaining but don't bother to store it
	if ( version <= VER_4_2_2_0 ) {
		ReadUInt( in );
	}

	GetAttr("String Data")->Read( in, version );
}

void NiStringExtraData::Write( ofstream& out, unsigned int version ) const {
	//GetAttr("Name")->Write( out, version );
	//GetAttr("Next Extra Data")->Write( out, version );
	AExtraData::Write( out, version );

	attr_ref string_data = GetAttr("String Data");

	//Up to version 4.2.2.0, Write Bytes Remaining; length of string + 4
	if ( version <= VER_4_2_2_0 ) {
		WriteUInt( uint(string_data->asString().length()) + 4, out );
	}

	string_data->Write( out, version );
}

string NiStringExtraData::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	attr_ref name_attr = GetAttr("Name");
	//attr_ref next_data = GetAttr("Next Extra Data");
	attr_ref string_data = GetAttr("String Data");

	out << "Name:  " << name_attr->asString() << endl
		//<< next_data->GetName() << ":  " << next_data->asLink() << endl
		<< "Bytes Remaining:  " << uint(string_data->asString().length()) + 4 << endl
		<< string_data->GetName() << ":  " << string_data->asString() << endl;
	
	return out.str();
}

/***********************************************************
 * NiMorphData methods
 **********************************************************/

void NiMorphData::Read( ifstream& file, unsigned int version ) {

	uint morphCount = ReadUInt( file );
	NifStream( vertCount, file );

	GetAttr("Unknown Byte")->Read( file, version );

	morphs.resize(morphCount);
	for ( uint i = 0; i < morphs.size() ; ++i ) {
		uint numKeys = ReadUInt( file );

		NifStream( morphs[i]._type, file );

		
		morphs[i].keys.resize( numKeys );
		
		for (uint j = 0; j < morphs[i].keys.size(); j++) {
			NifStream( morphs[i].keys[j], file, morphs[i]._type );
		}

		morphs[i].morph.resize( vertCount );
		//Stream whole array of Vector3
		NifStream( morphs[i].morph, file );
	}
}

void NiMorphData::Write( ofstream& file, unsigned int version ) const {
	WriteUInt( uint(morphs.size()), file );
	NifStream( vertCount, file );

	GetAttr("Unknown Byte")->Write( file, version );

	for ( uint i = 0; i < morphs.size() ; ++i ) {
		WriteUInt( uint(morphs[i].keys.size()), file );

		NifStream( morphs[i]._type, file );

		for (uint j = 0; j < morphs[i].keys.size(); j++) {
			NifStream( morphs[i].keys[j], file, morphs[i]._type );
		}
		
		//Stream whole array of Vector3
		NifStream( morphs[i].morph, file );
	}
}

string NiMorphData::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << "Morph Count:  " << uint(morphs.size()) << endl
		<< "Vert Count:  " << vertCount << endl
		<< "Unknown Byte:  " << GetAttr("Unknown Byte")->asString() << endl;

	for ( uint i = 0; i < morphs.size() ; ++i ) {
		out << "---Morph " << i + 1 << "---" << endl;

		out << "Time Count:  " << uint(morphs[i].keys.size()) << endl
			<< "Key Type:  " << morphs[i]._type << endl;
		
		if (verbose) {
			for (uint j = 0; j < morphs[i].keys.size(); ++j ) {
				//Always show time and data
				out << "Key Time:  " << morphs[i].keys[j].time << ", Influence?: " << morphs[i].keys[j].data;
				if ( morphs[i]._type == 2 ) {
					//Uses Quadratic interpolation
					out << ", FT(" << morphs[i].keys[j].forward_tangent << ") BT(" << morphs[i].keys[j].backward_tangent << ")";
				} else if ( morphs[i]._type == 3 ) {
					out << ", T " << morphs[i].keys[j].tension << ", B " << morphs[i].keys[j].bias << ", C " << morphs[i].keys[j].continuity;
				}
				out << endl;
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
 * NiPalette methods
 **********************************************************/

void NiPalette::Read( ifstream& in, unsigned int version ) {
	//Read 5 unknown bytes
	for (int i = 0; i < 5; ++i) {
		unknownBytes[i] = ReadByte( in );
	}

	//Read Palette
	for (int i = 0; i < 256; ++i) {
		for (int j = 0; j < 4; ++j) {
			palette[i][j] = ReadByte( in );
		}
	}
}

void NiPalette::Write( ofstream& out, unsigned int version ) const {
	//Write 5 unknown bytes
	for (int i = 0; i < 5; ++i) {
		WriteByte( unknownBytes[i], out );
	}

	//Read Palette
	for (int i = 0; i < 256; ++i) {
		for (int j = 0; j < 4; ++j) {
			WriteByte( palette[i][j], out );
		}
	}
}


string NiPalette::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	//Print 5 unknown bytes
	for (int i = 0; i < 5; ++i) {
		out << "Unknown Byte " << i + 1 << ":  " << unknownBytes[i] << endl;
	}

	//Print Palette
	out << "Palette:" << endl;
	if (verbose) {
		for (int i = 0; i < 256; ++i) {
			out << i + 1 << ":  " << int(palette[i][0]) << ", " << int(palette[i][1]) << ", " << int(palette[i][2]) << ", " << int(palette[i][3]) << endl;
		}
	} else {
		out << "  <<Data Not Shown>>" << endl;
	}

	return out.str();
}

/***********************************************************
 * NiSkinPartition methods
 **********************************************************/

void NiSkinPartition::Read( ifstream& file, unsigned int version ) {

	uint numPartitions = ReadUInt( file );
	partitions.resize( numPartitions );
	
	vector<SkinPartition>::iterator it;
	for (it = partitions.begin(); it != partitions.end(); ++it ) {

		//Read counts
		ushort numVertices = ReadUShort( file );
		ushort numTriangles = ReadUShort( file );
		ushort numBones = ReadUShort( file );
		ushort numStrips = ReadUShort( file );
		ushort numWeights = ReadUShort( file );

		//Read bones
		it->bones.resize( numBones );
		NifStream( it->bones, file );

		//Read vertex map
		//After version 10.1.0.0, the vertex map is conditioned on a bool
		bool hasVertexMap = true;
		if ( version >= VER_10_1_0_0 ) {
			hasVertexMap = ReadBool( file, version );
		}

		if ( hasVertexMap ) {
			it->vertexMap.resize( numVertices );
			NifStream( it->vertexMap, file );
		}

		//Read vertex weights
		//After version 10.1.0.0, the vertex weights are conditioned on a bool
		bool hasVertexWeights = true;
		if ( version >= VER_10_1_0_0 ) {
			hasVertexWeights = ReadBool( file, version );
		}

		if ( hasVertexWeights ) {
			//Resize vectors 2 deep
			it->vertexWeights.resize( numVertices );
			for ( uint i = 0; i < it->vertexWeights.size(); ++i ) {
				it->vertexWeights[i].resize( numWeights );
			}
			//Read it all
			NifStream( it->vertexWeights, file );
		}

		//Read strip lenghts, resize strip vectors as we go.
		it->strips.resize( numStrips );
		for ( uint i = 0; i < it->strips.size(); ++i ) {
			it->strips[i].resize( ReadUShort( file ) );
		}

		//Read triangle strip points
		//After version 10.1.0.0, the triangle strip points are conditioned on a bool
		bool hasStrips = true;
		if ( version >= VER_10_1_0_0 ) {
			hasStrips = ReadBool( file, version );
		}

		if ( hasStrips ) {
			//Read 2 deep
			NifStream( it->strips, file );
		}

		//Read triangles
		//Triangles only exist if numStrips == 0
		if ( it->strips.size() == 0 ) {
			it->triangles.resize( numTriangles );
			NifStream( it->triangles, file );
		}

		//This bool exists in all versions
		bool hasBoneIndices = ReadBool( file, version );

		if ( hasBoneIndices ) {
			//Resize vectors 2 deep
			it->boneIndices.resize( numVertices );
			for ( uint i = 0; i < it->vertexWeights.size(); ++i ) {
				it->boneIndices[i].resize( numWeights );
			}
			//Read it all
			NifStream( it->boneIndices, file );
		}
	}
}

void NiSkinPartition::Write( ofstream& file, unsigned int version ) const {

	WriteUInt( uint(partitions.size()), file );

	vector<SkinPartition>::const_iterator it;
	for (it = partitions.begin(); it != partitions.end(); ++it ) {
		//Write counts
		WriteUShort( ushort( it->vertexMap.size()), file );
		WriteUShort( ushort( it->triangles.size()), file );
		WriteUShort( ushort( it->bones.size()), file );
		WriteUShort( ushort( it->strips.size()), file );
		WriteUShort( ushort( it->vertexWeights.size()), file );

		//Write bones
		NifStream( it->bones, file );

		//Write vertex map
		//After version 10.1.0.0, the vertex map is conditioned on a bool
		if ( version >= VER_10_1_0_0 ) {
			WriteBool( it->vertexMap.size() > 0, file, version );
		}

		NifStream( it->vertexMap, file );

		//Write vertex weights
		//After version 10.1.0.0, the vertex weights are conditioned on a bool
		if ( version >= VER_10_1_0_0 ) {
			WriteBool( it->vertexWeights.size() > 0, file, version );
		}

		//Write vertex weights - 2 deep
		NifStream( it->vertexWeights, file );

		//Write strip lenghts
		for ( uint i = 0; i < it->strips.size(); ++i ) {
			WriteUShort( ushort(it->strips.size()), file );
		}

		//Write triangle strip points
		//After version 10.1.0.0, the triangle strip points are conditioned on a bool
		if ( version >= VER_10_1_0_0 ) {
			WriteBool( it->strips.size() > 0, file, version );
		}

		//Write strip points - 2 deep
		NifStream( it->strips, file );

		//Write triangles
		//Triangles only exist if numStrips == 0
		if ( it->strips.size() == 0 ) {
			NifStream( it->triangles, file );
		}

		//This bool exists in all versions
		WriteBool( it->boneIndices.size() > 0, file, version );

		//Write bone indices - 2 deep
		NifStream( it->boneIndices, file );
	}
}


string NiSkinPartition::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	int count = 0;
	vector<SkinPartition>::const_iterator it;
	for (it = partitions.begin(); it != partitions.end(); ++it ) {
		count++;
		//Write counts
		out << "Skin Partition " << count << ":" << endl
			<< "   Vertex Count:  " << ushort(it->vertexMap.size()) << endl
			<< "   Triangle Count:  " << ushort(it->triangles.size()) << endl
			<< "   Bone Count:  " << ushort(it->bones.size()) << endl
			<< "   Triangle Strip Count:  " << ushort(it->strips.size()) << endl
			<< "   Vertex Weight Count:  " << ushort(it->vertexWeights.size()) << endl;

		if (verbose) {
			out << "   Bones:" << endl;
			for ( uint i = 0; i < it->bones.size(); ++i ) {
				out << "      " << i + 1 << ":  " << it->bones[i] << endl;
			}

			out << "   Vertex Map:" << endl;
			for ( uint i = 0; i < it->vertexMap.size(); ++i ) {
				out << "      " << i + 1 << ":  " << it->vertexMap[i] << endl;
			}

			out << "   Vertex Weights:" << endl;
			for ( uint i = 0; i < it->vertexWeights.size(); ++i ) {
				out << "Group " << i + 1 << ":" << endl;
				for ( uint j = 0; j < it->vertexWeights[i].size(); ++j ) {
					out << "         " << j + 1 << ":  " << it->vertexWeights[i][j] << endl;
				}
			}

			out << "   Triangle Strips:" << endl;
			for ( uint i = 0; i < it->strips.size(); ++i ) {
				out << "Strip " << i + 1 << ":" << endl;
				for ( uint j = 0; j < it->strips[i].size(); ++j ) {
					out << "         " << j + 1 << ":  " << it->strips[i][j] << endl;
				}
			}

			out << "   Triangles:" << endl;
			for ( uint i = 0; i < it->triangles.size(); ++i ) {
				out << "      " << i + 1 << ":  " << setw(10) << it->triangles[i].v1 << "," << setw(10) << it->triangles[i].v2 << "," << setw(10) << it->triangles[i].v3 << endl;
			}

			out << "   Bone Indices:" << endl;
			for ( uint i = 0; i < it->boneIndices.size(); ++i ) {
				out << "Group " << i + 1 << ":" << endl;
				for ( uint j = 0; j < it->boneIndices[i].size(); ++j ) {
					out << "         " << j + 1 << ":  " << it->boneIndices[i][j] << endl;
				}
			}
		} else {
			out << "   <<Data Not Shown>>" << endl;
		}
	}

	return out.str();
}

/***********************************************************
 * NiPixelData methods
 **********************************************************/

void NiPixelData::Read( ifstream& in, unsigned int version ) {
	ABlock::Read( in, version );

	uint mipCount = ReadUInt( in );
	bytesPerPixel = ReadUInt( in );

	mipmaps.resize( mipCount );
	for ( uint i = 0; i < mipCount; ++i ) {
		mipmaps[i].width = ReadUInt( in );
		mipmaps[i].height = ReadUInt( in );
		mipmaps[i].offset = ReadUInt( in );
	}

	dataSize = ReadUInt( in );
	data = new byte[dataSize];
	in.read( (char *)data, dataSize);
}

void NiPixelData::Write( ofstream& out, unsigned int version ) const {
	ABlock::Write( out, version );

	WriteUInt( uint(mipmaps.size()), out );
	WriteUInt( bytesPerPixel, out );

	for ( uint i = 0; i < mipmaps.size(); ++i ) {
		WriteUInt( mipmaps[i].width, out );
		WriteUInt( mipmaps[i].height, out );
		WriteUInt( mipmaps[i].offset, out );
	}

	WriteUInt( dataSize, out );
	out.write( (char *)data, dataSize);
}

string NiPixelData::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << ABlock::asString();

	out << endl
		<< "Mipmap Count:  " << uint(mipmaps.size()) << endl
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

void NiPosData::Read( ifstream& file, unsigned int version ) {
	uint keyCount = ReadUInt( file );
	NifStream( _type, file );

	_keys.resize( keyCount );
	for (uint i = 0; i < _keys.size(); i++) {
		NifStream( _keys[i], file, _type );
	}
}

void NiPosData::Write( ofstream& file, unsigned int version ) const {
	WriteUInt( uint(_keys.size()), file );
	NifStream( _type, file );

	for (uint i = 0; i < _keys.size(); i++) {
		NifStream( _keys[i], file, _type );
	}
}

string NiPosData::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << "Key Count:  " << uint(_keys.size()) << endl
		<< "Key Type:  " << _type << endl;

	if (verbose) {
		vector< Key<Vector3> >::const_iterator it;
		for ( it = _keys.begin(); it != _keys.end(); ++it ) {
			out << "Key Time:  " <<  it->time << "  Position:  " << it->data.x << ", " << it->data.y << ", " << it->data.z << endl;
		}
	} else {
		out << "<<Data Not Shown>>" << endl;
	}

	return out.str();
}

/***********************************************************
 * NiTextKeyExtraData methods
 **********************************************************/

void NiTextKeyExtraData::Read( ifstream& file, unsigned int version ) {
	/*GetAttr("Name")->Read( file, version );
	GetAttr("Next Extra Data")->Read( file, version );
	*/
	AExtraData::Read( file, version );
	GetAttr("Unknown Int")->Read( file, version );

	uint keyCount = ReadUInt( file );

	_keys.resize( keyCount );
	for (uint i = 0; i < _keys.size(); i++) {
		NifStream( _keys[i], file, LINEAR_KEY );
	}
}

void NiTextKeyExtraData::Write( ofstream& file, unsigned int version ) const {

	/*GetAttr("Name")->Write( file, version );
	GetAttr("Next Extra Data")->Write( file, version );
	*/
	AExtraData::Write( file, version );
	GetAttr("Unknown Int")->Write( file, version );

	WriteUInt( uint(_keys.size()), file );

	for (uint i = 0; i < _keys.size(); i++) {
		NifStream( _keys[i], file, LINEAR_KEY );
	}
}

string NiTextKeyExtraData::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << "Name:  " << GetAttr("Name")->asString() << endl
		//<< "Next Extra Data:  " << GetAttr("Next Extra Data")->asString() << endl
		<< "Unknown Int:  " << GetAttr("Unknown Int")->asString() << endl
		<< "Key Count:  " << uint(_keys.size()) << endl;

	if (verbose) {
		vector< Key<string> >::const_iterator it;
		for ( it = _keys.begin(); it != _keys.end(); ++it ) {
			out << "Key Time:  " <<  it->time << "  Key Text:  " << it->data << endl;
		}
	} else {
		out << "<<Data Not Shown>>" << endl;
	}

	return out.str();
}

/***********************************************************
 * NiUVData methods
 **********************************************************/

void NiUVData::Read( ifstream& in, unsigned int version ) {	
	for (uint i = 0; i < 4; ++i) {
		uint count = ReadUInt( in );

		if ( count > 0 ) {
			groups[i].keyType = ReadUInt( in );

			groups[i].keys.resize(count);
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

void NiUVData::Write( ofstream& out, unsigned int version ) const {
	for (uint i = 0; i < 4; ++i) {
		WriteUInt( uint(groups[i].keys.size()), out );

		if ( groups[i].keys.size() > 0 ) {
			WriteUInt( groups[i].keyType, out );

			for (uint j = 0; j < groups[i].keys.size(); ++j) {
				WriteFloat( groups[i].keys[j].time, out );
				WriteFloat( groups[i].keys[j].data, out );

				if ( groups[i].keyType == 2) {
					WriteFloat( groups[i].keys[j].forward_tangent, out );
					WriteFloat( groups[i].keys[j].backward_tangent, out );
				}
			}
		}
	}
}

string NiUVData::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	for (uint i = 0; i < 4; ++i) {
		out << "UV Group " << i + 1 << ":" << endl
			<< "   Key Count:  " << uint(groups[i].keys.size()) << endl;

		if ( groups[i].keys.size() > 0 ) {
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
 
void NiVertWeightsExtraData::Read( ifstream& in, unsigned int version ) {
	AExtraData::Read( in, version );

	bytes = ReadUInt( in );
	ushort verts = ReadUShort( in );

	weights.resize( verts );
	for (uint i = 0; i < weights.size(); ++i) {
		weights[i] = ReadFloat( in );
	}
}

void NiVertWeightsExtraData::Write( ofstream& out, unsigned int version ) const {
	AExtraData::Write( out, version );

	WriteUInt( bytes, out );
	WriteUShort( ushort(weights.size()), out );

	for (uint i = 0; i < weights.size(); ++i) {
		 WriteFloat( weights[i], out );
	}
}

string NiVertWeightsExtraData::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << AExtraData::asString();

	out << "Bytes:  " << bytes << endl
		<< "Verts:  " << uint(weights.size()) << endl;

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

void NiVisData ::Read( ifstream& in, unsigned int version ) {
	uint keyCount = ReadUInt( in );

	keys.resize( keyCount );
	for (uint i = 0; i < keys.size(); ++i) {
		keys[i].time = ReadFloat( in );
		keys[i].data = ReadByte( in ); // Is Visible? True/False
	}
}

void NiVisData ::Write( ofstream& out, unsigned int version ) const {
	WriteUInt( uint(keys.size()), out );

	for (uint i = 0; i < keys.size(); ++i) {
		WriteFloat( keys[i].time, out );
		WriteByte( keys[i].data, out ); // Is Visible? True/False
	}
}

string NiVisData::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << "Key Count:  "  << uint(keys.size()) << endl;

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

void UnknownMixIn::Read( ifstream &in, unsigned int version ) {
	len = BlockSearch(in);

	//Create byte array and read in unknown block
	data = new byte [len];
	in.read((char*)data, len);
}

string UnknownMixIn::asString() const {
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

void UnknownMixIn::Write( ofstream& out, unsigned int version ) const {
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
