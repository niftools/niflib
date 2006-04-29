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

//#define IM_DEBUG

#include "NIF_Blocks.h"
#include "nif_attrs.h"
#include "nif_math.h"
#include <cmath>
#include <sstream>
#ifdef IM_DEBUG
#include <imdebug.h>
#endif
extern bool verbose;
extern unsigned int blocks_in_memory;

#define endl "\r\n"

extern string current_file;

/***********************************************************
 * ABlock methods
 **********************************************************/

ABlock::ABlock() : _block_num(-1), _ref_count(0) {
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

	//cout << endl << "Removing cross reference to " << this << " from " << uint(_cross_refs.size()) << " blocks";
	// Inform all cross-linked blocks that have added their references that this block is dying
	list<IBlock*>::iterator it;
	for (it = _cross_refs.begin(); it != _cross_refs.end(); ++it) {
		//IBlockInternal * blk_int = (IBlockInternal*)(*it)->QueryInterface(BlockInternal);
		//if ( blk_int != NULL ) {
			((ABlock*)(*it))->RemoveCrossLink(this);
		//}
	}
}

void ABlock::AddAttr( AttrType type, string const & name, unsigned int first_ver, unsigned int last_ver ) {
	IAttr * attr;

	switch( type ) {
		case attr_int:
			attr = new IntAttr( name, this, first_ver, last_ver );
			break;
		case attr_short:
			attr = new ShortAttr( name, this, first_ver, last_ver );
			break;
		case attr_byte:
			attr = new ByteAttr( name, this, first_ver, last_ver );
			break;
		case attr_float:
			attr = new FloatAttr( name, this, first_ver, last_ver );
			break;
		case attr_float3:
			attr = new Float3Attr( name, this, first_ver, last_ver );
			break;
		case attr_string:
			attr = new StringAttr( name, this, first_ver, last_ver );
			break;
		case attr_link:
			attr = new LinkAttr( name, this, first_ver, last_ver );
			break;
		case attr_flags:
			attr = new FlagsAttr( name, this, first_ver, last_ver );
			break;
		case attr_matrix33:
			attr = new MatrixAttr( name, this, first_ver, last_ver );
			break;
		case attr_linkgroup:
			attr = new LinkGroupAttr( name, this, first_ver, last_ver );
			break;
		case attr_bones:
			attr = new BoneAttr( name, this, first_ver, last_ver );
			break;
		case attr_bbox:
			attr = new BBoxAttr( name, this, first_ver, last_ver );
			break;
		case attr_condint:
			attr = new CIntAttr( name, this, first_ver, last_ver );
			break;
		case attr_vertmode:
			attr = new VertModeAttr( name, this, first_ver, last_ver );
			break;
		case attr_lightmode:
			attr = new LightModeAttr( name, this, first_ver, last_ver );
			break;
		case attr_texsource:
			attr = new TexSourceAttr( name, this, first_ver, last_ver );
			break;
		case attr_pixellayout:
			attr = new PixelLayoutAttr( name, this, first_ver, last_ver );
			break;
		case attr_mipmapformat:
			attr = new MipMapFormatAttr( name, this, first_ver, last_ver );
			break;
		case attr_alphaformat:
			attr = new AlphaFormatAttr( name, this, first_ver, last_ver );
			break;
		case attr_controllertarget:
			attr = new ControllerTargetAttr( name, this, first_ver, last_ver );
			break;
		case attr_skeletonroot:
			attr = new SkeletonRootAttr( name, this, first_ver, last_ver );
			break;
		case attr_particlegroup:
			attr = new ParticleGroupAttr( name, this, first_ver, last_ver );
			break;
		case attr_lodinfo:
			attr = new LODInfoAttr( name, this, first_ver, last_ver );
			break;
		case attr_vector3:
			attr = new Vector3Attr( name, this, first_ver, last_ver );
			break;
		case attr_color3:
			attr = new Color3Attr( name, this, first_ver, last_ver );
			break;
		case attr_parent:
			attr = new ParentAttr( name, this, first_ver, last_ver );
			break;
		case attr_unk292bytes:
			attr = new Unk292BytesAttr( name, this, first_ver, last_ver );
			break;
		case attr_bool:
			attr = new BoolAttr( name, this, first_ver, last_ver );
			break;
		case attr_targetgroup:
			attr = new TargetGroupAttr( name, this, first_ver, last_ver );
			break;
		case attr_shader:
			attr = new ShaderAttr( name, this, first_ver, last_ver );
			break;
		case attr_modifiergroup:
			attr = new ModifierGroupAttr( name, this, first_ver, last_ver );
			break;
		case attr_color4:	
			attr = new Color4Attr( name, this, first_ver, last_ver );	
			break;
		case attr_quaternion:
			attr = new QuaternionAttr( name, this, first_ver, last_ver );	
			break;
		case attr_emitterobject:
			attr = new EmitterObjectAttr( name, this, first_ver, last_ver );	
			break;
		case attr_selflink:
			attr = new SelfLinkAttr( name, this, first_ver, last_ver );	
			break;
		case attr_crossref:
			attr = new CrossRefAttr( name, this, first_ver, last_ver );	
			break;
		default:
			cout << type << endl;
			throw runtime_error("Unknown attribute type requested.");
	};

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
	if (_parents.size() > 0 ) {
		//Give preferential treatment to the first node parent
		for ( uint i = 0; i < _parents.size(); ++i ) {
			if ( _parents[i]->QueryInterface( ID_NODE ) ) {
				return _parents[i];
			}
		}
		return blk_ref(_parents[0]);
	} else {
		return blk_ref(-1);
	}
}

void ABlock::Read( istream& in, unsigned int version ) {

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

void ABlock::Write( ostream& out, unsigned int version ) const {

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
		//cout << "Block #" << this->GetBlockNum() << " - " << this->GetBlockType() << ":  Deleting block now." << endl;
		delete this;
	}
}

void ABlock::IncCrossRef( IBlock * block ) {
	_cross_refs.push_back(block);
}

void ABlock::DecCrossRef( IBlock * block ) {
	_cross_refs.remove(block);
}

blk_ref ABlock::Clone( unsigned int version ) {
	//Create a string stream to temporarily hold the state-save of this block
	stringstream tmp;

	cout << "Getting a list of all the links in this block" << endl;

	//Get a list of all the links in this block
	list<blk_ref> link_list = this->GetLinks();

	cout << "Putting the links into a vector & resetting block numbers" << endl;

	//Put the link into a vector and reset the block number of each of these blocks to correspond to its position in the vector
	int i = 0;
	vector<blk_ref> link_vec( link_list.size() );
	list<blk_ref>::iterator it;
	for ( it = link_list.begin(); it != link_list.end(); ++it ) {
		((ABlock*)it->get_block())->SetBlockNum(i);
		link_vec[i] = *it;
		++i;
	}

	cout << "Creating new block of same type" << endl;

	//Create a new block of the same type
	blk_ref clone = CreateBlock( GetBlockType() );

	cout << "Writing this block's data to the stream" << endl;

	//Write this block's data to the stream
	Write( tmp, version );

	cout << "Reading the data back from the stream" << endl;

	//Read the data back from the stream
	ABlock * clone_ab = (ABlock*)clone.get_block();
	clone_ab->Read( tmp, version );

	cout << "Fixing links of clone" << endl;

	//Fix the links of the clone using the original link list
	clone_ab->FixLinks( link_vec );	

	cout << "Done Cloning" << endl;

	//return new block
	return clone;
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

void ABlock::FixLinks( const vector<blk_ref> & blocks ) {
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

void ABlock::AddChild( IBlock * new_child ) {
	//If the poiner is null, do nothing
	if ( new_child == NULL )
		return;

	//Register this block as a parent of new_child
	((ABlock*)new_child)->AddParent( this );
	//IBlockInternal * bk_intl = (IBlockInternal*)new_child->QueryInterface( BlockInternal );
	//if ( bk_intl != NULL ) {
	//	bk_intl->AddParent( this );
	//}
}
void ABlock::RemoveChild( IBlock * old_child ) {
	//If the poiner is null, do nothing
	if ( old_child == NULL )
		return;

	//Add this block to first child as a parent
	((ABlock*)old_child)->RemoveParent( this );
	//IBlockInternal * bk_intl = (IBlockInternal*)old_child->QueryInterface( BlockInternal );
	//if ( bk_intl != NULL ) {
	//	bk_intl->RemoveParent( this );
	//}
}

void ABlock::RemoveCrossLink( IBlock * block_to_remove ) {
	//Ask all attributes to remove any cross links they might have to the specified block
	//cout << endl << "ABlock::RemoveCrossLink()";
	vector<attr_ref>::iterator it;
	for ( it = _attr_vect.begin(); it != _attr_vect.end(); ++it ) {
		((AAttr*)it->ptr())->RemoveCrossLinks( block_to_remove );
	}
}


void ABlock::AddParent( IBlock * new_parent) { 
	//Don't add null parents
	if ( new_parent != NULL )
		_parents.push_back( new_parent );
}

void ABlock::RemoveParent( IBlock * match ) {
	//Remove just one copy of the parent if there is one, incase a temporary reference is floating around
	vector<IBlock*>::iterator it = find< vector<IBlock*>::iterator, IBlock*>( _parents.begin(), _parents.end(), match);
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
	} else {
		return ABlock::QueryInterface( id );
	}
}

void const * ANode::QueryInterface( int id ) const {
	// Contains INode Interface
	if ( id == ID_NODE ) {
		return (void const *)static_cast<INode const *>(this);
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
	return MultMatrix44(s, rt);
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

void ANode::IncCrossRef( IBlock * block ) {
	//Add block to list
	ABlock::IncCrossRef( block );

	ResetSkinnedFlag();
}

void ANode::DecCrossRef( IBlock * block ) {
	ABlock::DecCrossRef( block );

	ResetSkinnedFlag();
}

void ANode::ResetSkinnedFlag() {
	//Count the number of cross references that are NiSkinData
	int count = 0;
	list<IBlock*>::iterator it;
	for (it = _cross_refs.begin(); it != _cross_refs.end(); ++it) {
		if ( (*it)->QueryInterface( ID_SKIN_DATA ) != NULL ) {
			++count;
		}
	}

	//Get Flags attribute
	attr_ref flag_attr = GetAttr("Flags");
	int flags = flag_attr->asInt();

	//If count == 0, then flag SHOULD be set
	if ( count == 0 && ((flags & 8) == 0) ) {
		//Flag is not set, flip the bit
		flags ^= 8;
	}

	//If count > 0, then flag should NOT be set
	if ( count >> 0 && ((flags & 8) != 0) ) {
		//Flag is set, flip the bit
		flags ^= 8;
	}

	//Store result
	flag_attr->Set(flags);
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

	//Create list of influenced skins
	list<IBlock*> skin_refs;

	list<IBlock*>::const_iterator it;
	for (it = _cross_refs.begin(); it != _cross_refs.end(); ++it ) {
		if ( (*it)->QueryInterface( ID_SKIN_DATA ) != NULL ) {
			skin_refs.push_back(*it);
		}
	}

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
 * NiTexturingProperty methods
 **********************************************************/

void NiTexturingProperty::Read( istream& file, unsigned int version ){

	AProperty::Read( file, version );

	appl_mode = ApplyMode( ReadUInt(file) );

	uint tex_count = ReadUInt( file );

	textures.resize( tex_count );

	for ( uint i = 0; i < textures.size(); ++i ) {
		NifStream( textures[i], file, version );

		if ( i == BUMP_MAP && textures[i].isUsed == true ) {
			NifStream( bmLumaScale, file );
			NifStream( bmLumaOffset, file );
			NifStream( bmMatrix[0][0], file );
			NifStream( bmMatrix[1][0], file );
			NifStream( bmMatrix[0][1], file );
			NifStream( bmMatrix[1][1], file );
		}
	}

	//Extra Texture group exists from version 10.0.1.0 on
	if ( version >= VER_10_0_1_0 ) {
		uint extra_tex_count = ReadUInt( file );

		extra_textures.resize( extra_tex_count );

		for ( uint i = 0; i < extra_textures.size(); ++i ) {
			NifStream( extra_textures[i].first, file, version );
			if ( extra_textures[i].first.isUsed ) {
				NifStream( extra_textures[i].second, file );
			}
		}
	}
}

void NiTexturingProperty::Write( ostream& file, unsigned int version ) const {

	AProperty::Write( file, version );

	WriteUInt( uint(appl_mode), file );

	WriteUInt( uint(textures.size()), file );

	for ( uint i = 0; i < textures.size(); ++i ) {
		NifStream( textures[i], file, version );

		if ( i == BUMP_MAP && textures[i].isUsed == true ) {
			NifStream( bmLumaScale, file );
			NifStream( bmLumaOffset, file );
			NifStream( bmMatrix[0][0], file );
			NifStream( bmMatrix[1][0], file );
			NifStream( bmMatrix[0][1], file );
			NifStream( bmMatrix[1][1], file );
		}
	}

	//Extra Texture group exists from version 10.0.1.0 on
	if ( version >= VER_10_0_1_0 ) {
		WriteUInt( uint(extra_textures.size()), file );

		for ( uint i = 0; i < extra_textures.size(); ++i ) {
			NifStream( extra_textures[i].first, file, version );
			if ( extra_textures[i].first.isUsed ) {
				NifStream( extra_textures[i].second, file );
			}
		}
	}
}

string NiTexturingProperty::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << "Apply Mode:  " << appl_mode << endl
		<< "Main Textures:  " << uint(textures.size()) << endl;

	for ( uint i = 0; i < textures.size(); ++i ) {
		out << "   Texture " << i + 1 << ":  ";
		switch (i) {
			case BASE_MAP:
				out << "Base Map";
				break;
			case DARK_MAP:
				out << "Dark Map";
				break;
			case DETAIL_MAP:
				out << "Detail Map";
				break;
			case GLOSS_MAP:
				out << "Gloss Map";
				break;
			case GLOW_MAP:
				out << "Glow Map";
				break;
			case BUMP_MAP:
				out << "Bump Map";
				break;
			case DECAL_0_MAP:
				out << "Decal 0 Map";
				break;
		};
		out << endl;

		out << textures[i].asString();
	}

	if ( textures.size() >= BUMP_MAP && textures[BUMP_MAP].isUsed == true ) {
		out << "BumpMap Info:" << endl
			<< "   Luma Offset:  " << bmLumaOffset << endl
			<< "   Luma Scale:  " << bmLumaScale << endl
			<< "   Matrix:" << endl
			<< "      |" << setw(6) << bmMatrix[0][0] << "," << setw(6) << bmMatrix[0][1] << " |" << endl
			<< "      |" << setw(6) << bmMatrix[1][0] << "," << setw(6) << bmMatrix[1][1] << " |" << endl;
	}

	for ( uint i = 0; i < extra_textures.size(); ++i ) {
		out << "   Extra Texture " << i + 1 << ":  " << endl;
		
		out << extra_textures[i].first.asString()
			<< "      Unknown Extra Int:  " << extra_textures[i].second << endl;
	}

	return out.str();
}

void NiTexturingProperty::FixLinks( const vector<blk_ref> & blocks ) {
	ABlock::FixLinks( blocks );

	//Main Textures
	for (uint i = 0; i < textures.size(); ++i ) {
		if ( textures[i].isUsed == true ) {
			//Fix link for this child
			textures[i].source = blocks[ textures[i].source.get_index() ];

			//Add this block to child as a parent
			AddChild( textures[i].source.get_block() );
		}
	}

	//Extra Textures
	for (uint i = 0; i < extra_textures.size(); ++i ) {
		if ( extra_textures[i].first.isUsed == true ) {
			//Fix link for this child
			extra_textures[i].first.source = blocks[ extra_textures[i].first.source.get_index() ];

			//Add this block to child as a parent
			AddChild( extra_textures[i].first.source.get_block() );
		}
	}
}

list<blk_ref> NiTexturingProperty::GetLinks() const {
	list<blk_ref> links = ABlock::GetLinks();

	//--Add Internal Links--//

	//Main Textures
	for (uint i = 0; i < textures.size(); ++i ) {
		if ( textures[i].isUsed == true ) {
			links.push_back( textures[i].source );
		}
	}

	//Extra Textures
	for (uint i = 0; i < extra_textures.size(); ++i ) {
		if ( extra_textures[i].first.isUsed == true ) {
			links.push_back( extra_textures[i].first.source );
		}
	}

	//Remove NULL links
	links.remove( blk_ref(-1) );

	return links;
}

NiTexturingProperty::~NiTexturingProperty() {
	//Remove all parents that were set as this block is dying.

	//Main Textures
	for (uint i = 0; i < textures.size(); ++i ) {
		if ( textures[i].isUsed == true ) {
			RemoveChild( textures[i].source.get_block() );
		}
	}

	//Extra Textures
	for (uint i = 0; i < extra_textures.size(); ++i ) {
		if ( extra_textures[i].first.isUsed == true ) {
			RemoveChild( extra_textures[i].first.source.get_block() );
		}
	}
}

void NiTexturingProperty::SetTextureCount( int new_count ) {

	if ( new_count < int(textures.size()) ) {
		//Remove active texture links that are about to be destroyed as children
		for ( uint i = new_count; i < textures.size(); ++i ) {
			RemoveChild( textures[i].source.get_block() );
		}
	}

	//Resize array
	textures.resize( new_count );
}

void NiTexturingProperty::SetExtraTextureCount( int new_count ) {
	if ( new_count < int(extra_textures.size()) ) {
		//Remove active texture links that are about to be destroyed as children
		for ( uint i = new_count; i < extra_textures.size(); ++i ) {
			RemoveChild( extra_textures[i].first.source.get_block() );
		}
	}

	//Resize array
	extra_textures.resize( new_count );
}

void NiTexturingProperty::SetTexture( int n, TexDesc & new_val ) {
	//Make sure index is not out of range
	if ( n < 0 || n > int(textures.size()) ) {
		throw runtime_error("SetTexture - Index out of range.  Call SetTextureCount first.");
	}

	//If new texture isUsed is false, then nullify any links
	if ( new_val.isUsed == false ) {
		new_val.source = blk_ref(-1);
	}

	//If blk_ref is different, children need to be changed
	if ( new_val.source != textures[n].source ) {
		//the new reference is different, discard the old child...
		if ( textures[n].source.is_null() == false ) {
			RemoveChild( textures[n].source.get_block() );
		}
		
		//and add the new one
		if ( new_val.source.is_null() == false ) {
			AddChild( new_val.source.get_block() );
		}
	}

	//Finally copy the values
	textures[n] = new_val;
}

void NiTexturingProperty::SetExtraTexture( int n, TexDesc & new_val ) {
	//Make sure index is not out of range
	if ( n < 0 || n > int(extra_textures.size()) ) {
		throw runtime_error("SetTexture - Index out of range.  Call SetTextureCount first.");
	}

	//If new texture isUsed is false, then nullify any links
	if ( new_val.isUsed == false ) {
		new_val.source = blk_ref(-1);
	}

	//If blk_ref is different, children need to be changed
	if ( new_val.source != extra_textures[n].first.source ) {
		//the new reference is different, discard the old child...
		if ( extra_textures[n].first.source.is_null() == false ) {
			RemoveChild( extra_textures[n].first.source.get_block() );
		}
		
		//and add the new one
		if ( new_val.source.is_null() == false ) {
			AddChild( new_val.source.get_block() );
		}
	}

	//Finally copy the values
	extra_textures[n].first = new_val;
}

/***********************************************************
 * NiBoneLODController methods
 **********************************************************/

void NiBoneLODController::Read( istream& file, unsigned int version ){

	AController::Read( file, version );

	unkInt1 = ReadUInt( file );
	
	uint numNodeGroups = ReadUInt( file );

	unkInt2 = ReadUInt( file );
	
	// Read Node Groups
	_node_groups.resize( numNodeGroups );
	for (uint i = 0; i < _node_groups.size(); ++i ) {
		uint groupSize = ReadUInt( file );
		_node_groups[i].resize(groupSize);
		for (uint j = 0; j < _node_groups[i].size(); ++j ) {
			_node_groups[i][j].set_index( ReadUInt(file) );
		}
	}

	// Read Shape Groups
	uint numShapeGroups = ReadUInt( file );
	_shape_groups.resize( numShapeGroups );
	for ( uint i = 0; i < _shape_groups.size(); ++i ) {
		uint groupSize = ReadUInt( file );
		_shape_groups[i].resize( groupSize );
		for ( uint j = 0; j < _shape_groups[i].size(); ++j ) {
			_shape_groups[i][j].first.set_index( ReadUInt(file) );
			_shape_groups[i][j].second.set_index( ReadUInt(file) );
		}
	}

	//Read Shape Group 2
	uint numShapeGroup2 = ReadUInt( file );
	_shape_group2.resize( numShapeGroup2 );

	for ( uint i = 0; i < _shape_group2.size(); ++i ) {
		_shape_group2[i].set_index( ReadUInt(file) );
	}
	
}

void NiBoneLODController::Write( ostream& file, unsigned int version ) const {
	AController::Write( file, version );

	WriteUInt( unkInt1, file );
	
	WriteUInt( uint(_node_groups.size()), file );

	WriteUInt( unkInt2, file );
	
	//Node Groups
	for (uint i = 0; i < _node_groups.size(); ++i ) {
		WriteUInt( uint(_node_groups[i].size()), file );
		for (uint j = 0; j < _node_groups[i].size(); ++j ) {
			WriteUInt( _node_groups[i][j]->GetBlockNum(), file );
		}
	}

	//Shape Groups
	WriteUInt( uint(_shape_groups.size()), file );
	for ( uint i = 0; i < _shape_groups.size(); ++i ) {
		WriteUInt( (uint)_shape_groups[i].size(), file );
		for ( uint j = 0; j < _shape_groups[i].size(); ++j ) {
			WriteUInt( _shape_groups[i][j].first->GetBlockNum(), file );
			WriteUInt( _shape_groups[i][j].second->GetBlockNum(), file );
		}
	}

	//Shape Group 2
	WriteUInt( (uint)_shape_group2.size(), file );
	for ( uint i = 0; i < _shape_group2.size(); ++i ) {
		WriteUInt( _shape_group2[i]->GetBlockNum(), file );
	}
}

string NiBoneLODController::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << "Unknown Int 1:  " << unkInt1 << endl
		<< "Num Node Groups:  " << uint(_node_groups.size()) << endl
		<< "Unknown Int 2:  " << unkInt2 << endl;

	//Node Groups
	for (uint i = 0; i < _node_groups.size(); ++i ) {
		out << "   " << i + 1 << ":  " << " Group Size:  " << uint(_node_groups[i].size()) << endl;

		for (uint j = 0; j < _node_groups[i].size(); ++j ) {
			out << "      " << j + 1 << ":  " << _node_groups[i][j] << endl;
		}
	}

	// Shape Groups
	out << "Num Shape Groups:  " << uint(_shape_groups.size()) << endl;
	for ( uint i = 0; i < _shape_groups.size(); ++i ) {
		out << "   " << i + 1 << ":  " << " Group Size:  " << uint(_shape_groups[i].size()) << endl;
		for ( uint j = 0; j < _shape_groups[i].size(); ++j ) {
			out << "      " << j + 1 << ":  " << _shape_groups[i][j].first << endl
				 << "      " << j + 1 << ":  " << _shape_groups[i][j].second << endl;
		}
	}

	//Shape Group 2
	out << "Num Shape Group 2:  " << uint(_shape_group2.size()) << endl;
	for ( uint i = 0; i < _shape_group2.size(); ++i ) {
		out << "   " << i + 1 << ":  " <<  _shape_group2[i] << endl;
	}

	return out.str();
}

void NiBoneLODController::FixLinks( const vector<blk_ref> & blocks ) {
	ABlock::FixLinks( blocks );

	//Node Groups
	for (uint i = 0; i < _node_groups.size(); ++i ) {
		for (uint j = 0; j < _node_groups[i].size(); ++j ) {
			//Fix link for this child
			_node_groups[i][j] = blocks[ _node_groups[i][j].get_index() ];

			//Add this block to child as a parent
			AddChild( _node_groups[i][j].get_block() );
		}
	}

	// Shape Groups
	for ( uint i = 0; i < _shape_groups.size(); ++i ) {
		for ( uint j = 0; j < _shape_groups[i].size(); ++j ) {
			//Fix links for this child
			_shape_groups[i][j].first = blocks[ _shape_groups[i][j].first.get_index() ];
			_shape_groups[i][j].second = blocks[ _shape_groups[i][j].second.get_index() ];

			//Add these blocks to child as a parent
			AddChild( _shape_groups[i][j].first.get_block() );
			AddChild( _shape_groups[i][j].second.get_block() );
		}
	}

	//Shape Group 2
	for ( uint i = 0; i < _shape_group2.size(); ++i ) {
		//Fix link for this child
		_shape_group2[i] = blocks[ _shape_group2[i].get_index() ];

		//Add this block to child as a parent
		AddChild( _shape_group2[i].get_block() );
	}
}

list<blk_ref> NiBoneLODController::GetLinks() const {
	list<blk_ref> links = ABlock::GetLinks();

	//--Add Internal Links--//

	//Node Groups
	for (uint i = 0; i < _node_groups.size(); ++i ) {
		for (uint j = 0; j < _node_groups[i].size(); ++j ) {
			links.push_back( _node_groups[i][j] );
		}
	}

	// Shape Groups
	for ( uint i = 0; i < _shape_groups.size(); ++i ) {
		for ( uint j = 0; j < _shape_groups[i].size(); ++j ) {
			links.push_back( _shape_groups[i][j].first );
			links.push_back( _shape_groups[i][j].second );
		}
	}

	//Shape Group 2
	for ( uint i = 0; i < _shape_group2.size(); ++i ) {
		links.push_back( _shape_group2[i] );
	}

	//Remove NULL links
	links.remove( blk_ref(-1) );

	return links;
}

NiBoneLODController::~NiBoneLODController() {
	//Remove all parents that were set as this block is dying.

	//Node Groups
	for (uint i = 0; i < _node_groups.size(); ++i ) {
		for (uint j = 0; j < _node_groups[i].size(); ++j ) {
			RemoveChild( _node_groups[i][j].get_block() );
		}
	}

	// Shape Groups
	for ( uint i = 0; i < _shape_groups.size(); ++i ) {
		for ( uint j = 0; j < _shape_groups[i].size(); ++j ) {
			//Add these blocks to child as a parent
			/*((ABlock*)_shape_groups[i][j].first.get)->RemoveParent( this );
			((ABlock*)_shape_groups[i][j].second)->RemoveParent( this );*/
			RemoveChild( _shape_groups[i][j].first.get_block() );
			RemoveChild( _shape_groups[i][j].second.get_block() );
		}
	}

	//Shape Group 2
	for ( uint i = 0; i < _shape_group2.size(); ++i ) {
		//Add this block to child as a parent
		RemoveChild( _shape_group2[i].get_block() );
	}
}

/***********************************************************
 * NiRangeLODData methods
 **********************************************************/

void NiRangeLODData::Read( istream& file, unsigned int version ){
	NifStream( _center, file );
	int numRanges = ReadUInt( file );
	ranges.resize( numRanges );
	NifStream( ranges, file );
}

void NiRangeLODData::Write( ostream& file, unsigned int version ) const {
	NifStream( _center, file );
	WriteUInt( uint(ranges.size()), file );
	NifStream( ranges, file );
}

string NiRangeLODData::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << "   LOD Center:  (" << _center.x << ", " << _center.y << ", " << _center.z << ")" << endl;

	out << uint(ranges.size()) << endl;

	for ( uint i = 0; i < ranges.size(); ++i ) {
		out << "   " << i + 1 << ")   Near:  " << ranges[i].near << "   Far:  " << ranges[i].far << endl;
	}

	return out.str();
}

/***********************************************************
 * NiScreenLODData methods
 **********************************************************/

void NiScreenLODData::Read( istream& file, unsigned int version ){
	//8 unknown floats
	for ( uint i = 0; i < 8; ++i ) {
		NifStream( unk_floats[i], file );
	}

	//float list
	uint unk_count = ReadUInt( file );
	unk_float_list.resize( unk_count );

	NifStream( unk_float_list, file );
}

void NiScreenLODData::Write( ostream& file, unsigned int version ) const {
	//8 unknown floats
	for ( uint i = 0; i < 8; ++i ) {
		NifStream( unk_floats[i], file );
	}

	//float list
	WriteUInt( uint( unk_float_list.size()), file );

	NifStream( unk_float_list, file );
}

string NiScreenLODData::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	//8 unknown floats
	out << "Unknown 8 Floats:  " << endl;
	for ( uint i = 0; i < 8; ++i ) {
		out << "   " << i + 1 << ":  " << unk_floats[i] << endl;
	}

	//float list
	out << "Unknown Float List:  " << uint(unk_float_list.size());
	for ( uint i = 0; i < unk_float_list.size(); ++i ) {
		out << "   " << i + 1 << ":  " << unk_float_list[i] << endl;
	}

	return out.str();
}

/***********************************************************
 * AShapeData methods
 **********************************************************/

/**
 * AShapeData::Read - Assumes block name has already been read from in
 */
void AShapeData::Read( istream& in, unsigned int version ){

	GetAttr("Name")->Read( in, version );
	
	ushort vert_count = ReadUShort( in );

	//There is an unknown short here from version 10.1.0.0 on
	if ( version >= VER_10_1_0_0 ) {
		ReadUShort( in );
	}

	bool hasVertices = ReadBool( in, version );
	if ( hasVertices != 0 ){
		vertices.resize( vert_count );
		for ( uint i = 0; i < vertices.size(); ++i ){
			NifStream( vertices[i], in );
		}
	}

	/// numTexSets up here up from version 10.0.1.0 on along with an unknown byte
	ushort numTexSets;
	bool hasUnknown;
	if ( version >= VER_10_0_1_0 ) {
		numTexSets = ReadByte( in );
		hasUnknown = ReadBool( in, version );
	}

	bool hasNormals = ReadBool( in, version );;
	if ( hasNormals != 0 ){
		normals.resize( vert_count );
		for ( uint i = 0; i < normals.size(); ++i ){
			NifStream( normals[i], in );
		}
	}

	//After version 10.1.0.0 there's several unknown vectors here
	if ( version >= VER_10_1_0_0 && hasUnknown == true ) {
		unk_vects.resize( vert_count * 2 );
		for ( uint i = 0; i < unk_vects.size(); ++i ){
			NifStream( unk_vects[i], in );
		}
	}

	//Read center and radius but throw the values away
	ReadFloat( in );
	ReadFloat( in );
	ReadFloat( in );
	ReadFloat( in );

	bool hasVertexColors = ReadBool( in, version );;
	if ( hasVertexColors != 0 ){
		colors.resize( vert_count );
		for ( uint i = 0; i < colors.size(); ++i ){
			NifStream( colors[i], in );
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
	
	out << "Unknown Vectors:  " << uint(unk_vects.size());
	if (verbose) {
		out << "   ";
		for ( uint i = 0; i < unk_vects.size(); ++i) {
			if (i % 3 == 0)
				out << endl << "   ";
			else
				out << "  ";

			out << "(" << setw(5) << unk_vects[i].x << ", " << setw(5) << unk_vects[i].y << ", " << setw(5) << unk_vects[i].z << " )";
		}
	} else {
		out << endl << "<<Data Not Shown>>";
	}
	out << endl;

	Vector3 center;
	float radius;
	CalcCentAndRad( center, radius );


	out << "Center:  (" << center.x << ", " << center.y << ", " << center.z << ")" << endl
		<< "Radius:  " << radius << endl
		<< "Vertex Colors:  " << uint(colors.size());
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

void AShapeData::CalcCentAndRad( Vector3 & center, float & radius ) const {
	//Check if there are no vertices
	if ( vertices.size() == 0 ) {
		center.Set(0.0f, 0.0f, 0.0f);
		radius = 0.0f;
		return;
	}
	
	//Set lows and highs to first vertex
	Vector3 lows = vertices[0];
	Vector3 highs = vertices[0];

	//Iterate through the rest of the vertices, adjusting the stored values
	//if a vertex with lower or higher values is found
	for (vector<Vector3>::const_iterator i = vertices.begin()+1; i != vertices.end(); ++i ) {
		if ( i->x > highs.x ) highs.x = i->x;
		else if ( i->x < lows.x ) lows.x = i->x;

		if ( i->y > highs.y ) highs.y = i->y;
		else if ( i->y < lows.y ) lows.y = i->y;

		if ( i->z > highs.z ) highs.z = i->z;
		else if ( i->z < lows.z ) lows.z = i->z;
	}

	//Now we know the extent of the shape, so the center will be the average of the lows and highs.
	center.x = (highs.x + lows.x) / 2.0f;
	center.y = (highs.y + lows.y) / 2.0f;
	center.z = (highs.z + lows.z) / 2.0f;

	//The radius will be the largest distance from the center
	Vector3 diff;
	float dist2(0.0f), maxdist2(0.0f);
	for (vector<Vector3>::const_iterator i = vertices.begin(); i != vertices.end(); ++i ) {
		diff = center;
		diff.x -= i->x;
		diff.y -= i->y;
		diff.z -= i->z;
		dist2 = diff.x * diff.x + diff.y * diff.y + diff.z * diff.z;
		if ( dist2 > maxdist2 ) maxdist2 = dist2;
	};
	radius = sqrt(maxdist2);
}

/**
 * AShapeData::Write
 */
void AShapeData::Write( ostream& out, unsigned int version ) const {

	GetAttr("Name")->Write( out, version );
	
	WriteUShort( ushort(vertices.size()), out );

	//There is an unknown short here from version 10.1.0.0 on
	if ( version >= VER_10_1_0_0 ) {
		WriteUShort( 0, out );
	}

	WriteBool( vertices.size() > 0, out, version );

	for ( uint i = 0; i < vertices.size(); ++i ){
		NifStream( vertices[i], out );
	}

	/// numTexSets up here up from version 10.0.1.0 on along with an unkown byte
	if ( version >= VER_10_0_1_0 ) {
		WriteByte( byte(uv_sets.size()), out );
		WriteBool( unk_vects.size() > 0, out, version );
	}

	WriteBool( normals.size() > 0, out, version );

	for ( uint i = 0; i < normals.size(); ++i ){
		NifStream( normals[i], out );
	}

	//Unkown vectors here from version 10.2.0.0 on
	if ( version >= VER_10_2_0_0 ) {
		for ( uint i = 0; i < unk_vects.size(); ++i ){
			NifStream( unk_vects[i], out );
		}
	}

	Vector3 center;
	float radius;
	CalcCentAndRad( center, radius );
	
	NifStream( center, out );
	NifStream( radius, out );

	if ( version <= VER_4_0_0_2 ) {
		// NifTexture bug workaround:
		if ( colors.size() > 0 )
			WriteUInt( 0xffffffff, out );
		else
			WriteUInt( 0, out );		
	} else
		WriteBool( colors.size() > 0, out, version );

	for ( uint i = 0; i < colors.size(); ++i ){
		NifStream( colors[i], out );
	}

	// numTexSets down here up to version 4.2.2.0
	if ( version <= VER_4_2_2_0 ) {
		WriteUShort( ushort(uv_sets.size()), out );
	}
	// hasUVs does not exist after version 4.0.0.2
	//bool hasUVs = true;
	if ( version <= VER_4_0_0_2 ) {
		//WriteBool( uv_sets.size() > 0, out, version );
		// NifTexture bug workaround:
		if (uv_sets.size() > 0)
			WriteUInt( 0xffffffff, out );
		else
			WriteUInt( 0, out );
	}

	for ( uint i = 0; i < uv_sets.size(); ++i ){
		for ( uint j = 0; j < uv_sets[i].size(); ++j){
			NifStream(uv_sets[i][j].u, out );
			NifStream(uv_sets[i][j].v, out );
		}
	}

	//Unknown Short here from version 10.0.1.0 on
	//Just write a zero
	if ( version >= VER_10_0_1_0) {
		WriteUShort( 0, out );
	}

	GetAttr("Unknown Link")->Write( out, version );
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

void AParticlesData::Read( istream& file, unsigned int version ) {
	AShapeData::Read( file, version );

	//numParticles exists up to version 4.0.0.2
	if ( version <= VER_4_0_0_2 ) {
		//This is just the number of vertices over again, so discard the data
		ReadUShort( file );
	}

	//Size exists up to version 10.0.1.0
	if ( version <= VER_10_0_1_0 ) {
		NifStream( size, file );
	}

	//numActive exists up to version 4.0.0.2
	if ( version <= VER_4_0_0_2 ) {
		NifStream( numActive, file );
	}

	//Unknown short exits from version 4.1.0.12 to 10.0.1.0
	if ( version >= VER_4_1_0_12 && version <= VER_10_0_1_0 ) {
		NifStream( unkShort, file );
	}

	hasSizes = ReadBool( file, version );

	if ( hasSizes ) {
		sizes.resize( vertices.size() );
		NifStream( sizes, file );
	}
}

void AParticlesData::Write( ostream& file, unsigned int version ) const {
	AShapeData::Write( file, version );

	//numParticles exists up to version 4.0.0.2
	if ( version <= VER_4_0_0_2 ) {
		//This is just the number of vertices over again
		NifStream( uint(vertices.size()), file );
	}

	//Size exists up to version 10.0.1.0
	if ( version <= VER_10_1_0_0 ) {
		NifStream( size, file );
	}

	//numActive exists up to version 4.0.0.2
	if ( version <= VER_4_0_0_2 ) {
		NifStream( numActive, file );
	}

	//Unknown short exits from version 4.1.0.12 to 10.0.1.0
	if ( version >= VER_4_1_0_12 && version <= VER_10_0_1_0 ) {
		NifStream( unkShort, file );
	}

	WriteBool( hasSizes, file, version );

	if ( hasSizes ) {
		NifStream( sizes, file );
	}
}

string AParticlesData::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << AShapeData::asString();

	out << "Num Particles:  " << uint(vertices.size()) << endl
		<< "Size:  " << size << endl
		<< "Num Active:  " << numActive << endl
		<< "Unknown Short:  " << unkShort << endl
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
 * APSysData methods
 **********************************************************/

void APSysData::Read( istream& file, unsigned int version ) {
	AShapeData::Read( file, version );

	bool hasUnkFlts = ReadBool( file, version );
	if ( hasUnkFlts ) {
		unkFloats1.resize( vertices.size() );
		for ( uint i = 0; i < unkFloats1.size(); ++i ) {
			NifStream( unkFloats1[i], file );
		}
	}

	NifStream( unkShort, file );

	hasUnkFlts = ReadBool( file, version );
	if ( hasUnkFlts ) {
		unkFloats2.resize( vertices.size() );
		for ( uint i = 0; i < unkFloats2.size(); ++i ) {
			NifStream( unkFloats2[i], file );
		}
	}

	NifStream( unkByte, file );
}

void APSysData::Write( ostream& file, unsigned int version ) const {
	AShapeData::Write( file, version );

	WriteBool( unkFloats1.size() > 0, file, version );
	for ( uint i = 0; i < unkFloats1.size(); ++i ) {
		NifStream( unkFloats1[i], file );
	}

	NifStream( unkShort, file );

	WriteBool( unkFloats2.size() > 0, file, version );
	for ( uint i = 0; i < unkFloats2.size(); ++i ) {
		NifStream( unkFloats2[i], file );
	}


	NifStream( unkByte, file );
}

string APSysData::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << AShapeData::asString();

	out << "Unknown Floats 1:  " << uint(unkFloats1.size()) << endl;
	if (verbose) {
		for ( uint i = 0; i < unkFloats1.size(); ++i ) {
			out << i + 1 << ":  " << unkFloats1[i] << endl;
		}
	} else {
		out << "<<Data Not Shown>>";
	}

	out << "Unknown Short:  " << unkShort << endl
		<< "Unknown Floats 2:  " << uint(unkFloats2.size()) << endl;
	if (verbose) {
		for ( uint i = 0; i < unkFloats2.size(); ++i ) {
			out << i + 1 << ":  " << unkFloats2[i] << endl;
		}
	} else {
		out << "<<Data Not Shown>>";
	}

	out << "Unknown Byte:  " << int(unkByte) << endl;

	return out.str();
}

/***********************************************************
 * NiMeshPSysData methods
 **********************************************************/

void NiMeshPSysData::Read( istream& file, unsigned int version ) {
	APSysData::Read( file, version );

	unkFloats.resize( vertices.size() * 14 );
	NifStream( unkFloats, file );

	NifStream( unkInt, file );

	GetAttr("Modifier")->Read( file, version );

	// From version 10.2.0.0 there are several new entries here
	if ( version >= VER_10_2_0_0 ) {
		NifStream( unkByte, file );

		GetAttr("Unknown Link Group")->Read( file, version );
		GetAttr("Unknown Link 2")->Read( file, version );
	}
}

void NiMeshPSysData::Write( ostream& file, unsigned int version ) const {
	APSysData::Write( file, version );

	NifStream( unkFloats, file );

	NifStream( unkInt, file );

	GetAttr("Modifier")->Write( file, version );

	// From version 10.2.0.0 there are several new entries here
	if ( version >= VER_10_2_0_0 ) {
		NifStream( unkByte, file );

		GetAttr("Unknown Link Group")->Write( file, version );
		GetAttr("Unknown Link 2")->Write( file, version );
	}
}

string NiMeshPSysData::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << AShapeData::asString();

	out << "Unknown Floats:  " << uint(unkFloats.size()) << endl;

	if (verbose) {
		for (uint i = 0; i < unkFloats.size(); ++i ) {
			out << "   " << i + 1 << unkFloats[i] << endl;
		}
	} else {
		out << "   <<<Data Not Shown>>>";
	}

	out << "Unknown Int:  " << unkInt << endl
		<< "Modifier:  " << GetAttr("Modifier")->asString() << endl
		<< "Unknown Byte:  " << unkByte << endl
		<< "Unknown Link Group:  " << GetAttr("Unknown Link Group")->asString() << endl
		<< "Unknown Link 2:  " << GetAttr("Unknown Link 2")->asString() << endl;

	return out.str();
}

/***********************************************************
 * NiPSysData methods
 **********************************************************/

void NiPSysData::Read( istream& file, unsigned int version ) {
	APSysData::Read( file, version );

	//before version 20.0.0.4 there are unknown floats here
	if ( version < VER_20_0_0_4	) {
		unkFloats.resize( vertices.size() * 10 );
		NifStream( unkFloats, file );
	} else {
		//From version 20.0.0.4 on there are a lot of unknown bytes
		unkBool1 = ReadBool( file, version );
		if ( unkBool1 ) {
			//32 bytes per vertex
			unkBytes1.resize( vertices.size() * 32 );
		} else {
			// 28 bytes per vertex
			unkBytes1.resize( vertices.size() * 28 );
		}
		NifStream( unkBytes1, file );

		NifStream( unkByte, file );

		unkBool2 = ReadBool( file, version );
		if ( unkBool2 ) {
			unkBytes2.resize( vertices.size() * 4 );
			NifStream( unkBytes2, file );
		}
	}

	NifStream( unkInt, file );
}

void NiPSysData::Write( ostream& file, unsigned int version ) const {
	APSysData::Write( file, version );

	//before version 20.0.0.4 there are unknown floats here
	if ( version < VER_20_0_0_4	) {
		NifStream( unkFloats, file );
	} else {
		//From version 20.0.0.4 on there are a lot of unknown bytes
		WriteBool( unkBool1, file, version );
		
		NifStream( unkBytes1, file );
		
		NifStream( unkByte, file );

		WriteBool( unkBool2, file, version);
		if ( unkBool2 ) {
			NifStream( unkBytes2, file );
		}
	}

	NifStream( unkInt, file );
}

string NiPSysData::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << AShapeData::asString();

	out << "Unknown Floats:  " << uint(unkFloats.size()) << endl;

	if (verbose) {
		for (uint i = 0; i < unkFloats.size(); ++i ) {
			out << "   " << i + 1 << unkFloats[i] << endl;
		}
	} else {
		out << "   <<<Data Not Shown>>>";
	}

	out << "Unknown Bool 1:  " << unkBool1 << endl
		<< "Unknown Bytes 1:  " << uint(unkBytes1.size()) << endl;

	if (verbose) {
		out << HexString( &unkBytes1[0], uint(unkBytes1.size()) );
	} else {
		out << "   <<<Data Not Shown>>>";
	}

	out << "Unknown Byte:  " << unkByte << endl
		<< "Unknown Bool 2:  " << unkBool2 << endl
		<< "Unknown Bytes 2:  " << uint(unkBytes2.size()) << endl;


	if (verbose) {
		out << HexString( &unkBytes2[0], uint(unkBytes2.size()) );
	} else {
		out << "   <<<Data Not Shown>>>";
	}

	out << "Unknown Int:  " << unkInt << endl;

	return out.str();
}

/***********************************************************
 * ARotatingParticlesData methods
 **********************************************************/

void ARotatingParticlesData::Read( istream& file, unsigned int version ) {
	AParticlesData::Read( file, version );

	//After version 10.1.0.0 there are several new entries
	if ( version >= VER_10_1_0_0 ) {
		NifStream( numActiveRot, file );

		bool hasUnkFloats = ReadBool( file, version );

		if ( hasUnkFloats ) {
			unkFloats.resize( vertices.size() );
			NifStream( unkFloats, file );
		}
	}

	bool hasRotations = ReadBool( file, version );

	if ( hasRotations ) {
		rotations.resize( vertices.size() );
		NifStream( rotations, file );
	}
}

void ARotatingParticlesData::Write( ostream& file, unsigned int version ) const {
	AParticlesData::Write( file, version );

	//After version 10.1.0.0 there are several new entries
	if ( version >= VER_10_1_0_0 ) {
		NifStream( numActiveRot, file );

		WriteBool( (unkFloats.size() > 0), file, version );

		NifStream( unkFloats, file );
	}

	WriteBool( (rotations.size() > 0), file, version );
	NifStream( rotations, file );
}

string ARotatingParticlesData::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << AParticlesData::asString() << endl
		<< "Num Active Rot:  " << numActiveRot << endl
		<< "Unknown Floats:  ";
	
	if ( unkFloats.size() > 0 ) {
		if (verbose) {
			out << endl;
			for ( uint i = 0; i < unkFloats.size(); ++i) {
				out << i << ":  " << unkFloats[i] << endl;
			}
		} else {
			out << endl << "<<Data Not Shown>>" << endl;
		}
	} else {
		out << "None" << endl;
	}

	out << "Rotations:  ";
	
	if ( rotations.size() > 0 ) {
		if (verbose) {
			out << endl;
			for ( uint i = 0; i < rotations.size(); ++i) {
				out << i << ":  [" << rotations[i].w << " (" << rotations[i].x << ", " << rotations[i].y << ", " << rotations[1].z << ")]" << endl;
			}
		} else {
			out << endl << "<<Data Not Shown>>" << endl;
		}
	} else {
		out << "None" << endl;
	}

	return out.str();
}

/***********************************************************
 * NiParticleMeshesData methods
 **********************************************************/

void NiParticleMeshesData::Read( istream& in, unsigned int version ) {
	ARotatingParticlesData::Read( in, version );

	GetAttr("Unknown Link 2")->Read( in, version );
}

void NiParticleMeshesData::Write( ostream& out, unsigned int version ) const {
	ARotatingParticlesData::Write( out, version );

	GetAttr("Unknown Link 2")->Write( out, version );
}

string NiParticleMeshesData::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << ARotatingParticlesData::asString()
		<< "Unknown Link 2:  " << GetAttr("Unknown Link 2")->asString() << endl;

	return out.str();
}

/***********************************************************
 * NiTriShapeData methods
 **********************************************************/

/**
 * NiTriShapeData::Read - Assumes block name has already been read from in
 */
void NiTriShapeData::Read( istream& in, unsigned int version ){
	AShapeData::Read( in, version );

	ushort numTriangles = ReadUShort( in );
	ReadUInt( in ); // numTriangles * 3, we can throw this away
	
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

	ushort matchGroupCount = ReadUShort( in );
	match_group_mode = ( matchGroupCount != 0 );  // Only record whether or not file prefers to have match data generated

	ushort sub_count;
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
void NiTriShapeData::Write( ostream& out, unsigned int version ) const {

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

//--Setters--//

void NiTriShapeData::SetTriangles( const vector<Triangle> & in ) {
	if ( in.size() > 65535 || in.size() < 0 ) {
		throw runtime_error("Invalid Triangle Count: must be between 0 and 65535.");
	}

	triangles = in;
}

/***********************************************************
 * NiTriStripsData methods
 **********************************************************/

void NiTriStripsData::Read( istream& in, unsigned int version ){
	AShapeData::Read( in, version );

	//Read number of Triangles but discard it
	ReadUShort( in );

	//Initialize vectors to number and size of strips
	ushort numStrips = ReadUShort( in );
	strips.resize( numStrips );
	for ( uint i = 0; i < strips.size(); ++i ) {
		ushort stripSize = ReadUShort( in );
		strips[i].resize( stripSize );
	}

	//From version 10.1.0.0 on there is a bool to check whether or not there are any points
	//We already know the answer to this from the counts above, don't we?
	//Just in case, clear all strips if this is false.
	if ( version >= VER_10_1_0_0 ) {
		if ( ReadBool( in, version ) == false ) {
			strips.resize(0);
		}
	}

	//Read points
	for ( uint i = 0; i < strips.size(); ++i ) {
		for ( uint j = 0; j < strips[i].size(); ++j ) {
			strips[i][j] = ReadUShort( in );
		}
	}
}

void NiTriStripsData::Write( ostream& out, unsigned int version ) const {

	AShapeData::Write( out, version );

	//Write number of triangles and strips
	ushort numTriangles = GetTriangleCount();
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
			if ( i % 2 == 0 ) {
				//cout << (*it)[i - 2] << ", " << (*it)[i - 1] << ", " << (*it)[i] << endl;
				triangles[n].Set( (*it)[i - 2], (*it)[i - 1], (*it)[i] );
			} else {
				//cout << (*it)[i] << ", " << (*it)[i - 1] << ", " << (*it)[i - 2] << endl;
				triangles[n].Set( (*it)[i], (*it)[i - 1], (*it)[i - 2] );
			}

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
 * NiBSplineData methods
 **********************************************************/

void NiBSplineData::Read( istream& file, unsigned int version ){
	NifStream( unkInt, file );
	
	uint count = ReadUInt( file );
	unkShorts.resize( count );
	NifStream( unkShorts, file );
}

void NiBSplineData::Write( ostream& file, unsigned int version ) const {

	NifStream( unkInt, file );

	WriteUInt( uint(unkShorts.size()), file );

	NifStream( unkShorts, file );
}

string NiBSplineData::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << "Unknown Int:  " << unkInt << endl
		<< "Unknown Shorts?:  " << uint(unkShorts.size()) << endl;

	if (verbose) {
		for ( uint i = 0; i < unkShorts.size(); ++i ) {
			out << "   " << i + 1 << ":  " << unkShorts[i] << endl;
		}
	} else {
		out << "   <<<Data Not Shown>>>" << endl;
	}
	

	return out.str();
}

/***********************************************************
 * NiCollisionData methods
 **********************************************************/

void NiCollisionData::Read( istream& in, unsigned int version ){
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

void NiCollisionData::Write( ostream& out, unsigned int version ) const {

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
		<< "Unknown Byte:  " << int(unknownByte) << endl
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

void NiSkinData::Read( istream& in, unsigned int version ) {
	
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

void NiSkinData::Write( ostream& out, unsigned int version ) const {
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
	try {
		CalculateOverallOffset(rot, tr, sc);
	} catch ( runtime_error & e ) {
		out << e.what() << endl;
		return out.str();
	}

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

void NiSkinData::SetBones( const vector<blk_ref> & bone_blocks ) {
	//--Move bones from temproary vector to map, sorted by blk_ref--//
	for (uint i = 0; i < bones.size(); ++i) {
		//IBlockInternal * blk_int = (IBlockInternal*)bone_blocks[i]->QueryInterface(BlockInternal);

		//move the data
		bone_map.insert( pair<IBlock *, Bone>(bone_blocks[i].get_block(), bones[i]) );

		//Increment reference at bone node site
		((ABlock*)bone_blocks[i].get_block())->IncCrossRef(this);
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

void NiSkinData::RepositionTriShape( blk_ref & tri_shape ) {
	//Get block we're going to move
	//blk_ref tri_shape = GetParent()->GetParent();

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

void NiSkinData::FixLinks( const vector<blk_ref> & blocks ) {

	ABlock::FixLinks( blocks );

	//Fix indicies for bones as they are copied from NiSkinInstance block
	blk_ref inst_blk = GetParent();
	if ( inst_blk.is_null() == false ) {
		ISkinInstInternal * inst_data = (ISkinInstInternal*)inst_blk->QueryInterface( SkinInstInternal );
		if ( inst_data != NULL ) {
			vector<int> bone_list = inst_data->GetBoneList();
			vector<blk_ref> bone_blks( bone_list.size() );
			for ( uint i = 0; i < bone_list.size(); ++i ) {
				bone_blks[i] = blocks[ bone_list[i] ];
			}
			SetBones( bone_blks );
		}
	}

	//Straigten up the skeleton to match with the "bind pose" for any skin instances that exist
	StraightenSkeleton();
}

vector<blk_ref> NiSkinData::GetBones() const {
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

void NiSkinData::ReassignCrossRefs( const map<string,blk_ref> & name_map ) {
	//This branch has been moved as part of a merge, so the cross references need to be moved to
	//Point to the new blocks with the same names.  As far as I know, cross references always point
	//To ParentNode blocks.

	vector< map<IBlock *, Bone>::iterator > erase_list;

	map<IBlock *, Bone>::iterator it;
	int count = 0;
	for (it = bone_map.begin(); it != bone_map.end(); ++it ) {
		//Get the name of the current target if there is one
		attr_ref name_attr = it->first->GetAttr("Name");
		if ( name_attr.is_null() == true ) {
			//Somehow this crossref is pointing to a block with no name
			//do nothing
			continue;
		}

		string name = name_attr->asString();

		//Check if this name exists in the new group of nodes
		map<string,blk_ref>::const_iterator found_it = name_map.find( name );

		if ( found_it == name_map.end() ) {
			//There were no matches, so this cross reference will continue to
			//point to the same place
			continue;
		}

		//--Reassign this cross reference to the new node with the same name that was found--//

		//cout << "Found a cross reference to re-assign to new block with name:  " << name << endl;

		//Remove this cross reference from its current target
		((ABlock*)it->first)->DecCrossRef(this);

		//Assign to block with matching name
		bone_map[found_it->second.get_block()] = it->second;
		erase_list.push_back( it );

		//Add as a cross reference to new block
		((ABlock*)found_it->second.get_block())->IncCrossRef(this);
	}

	//Erase all old map entires
	for ( uint i = 0; i < erase_list.size(); ++i ) {
		bone_map.erase( erase_list[i] );
	}

	//cout << "Finished loop." << endl;
}

map<int, float> NiSkinData::GetWeights( blk_ref const & bone ) const {
	// since operator[] might insert a new element, it can't be const
	// so we need the find function
	return bone_map.find(bone.get_block())->second.weights;
}

void NiSkinData::AddBone( blk_ref const & bone, map<int, float> const & in ) {
		
	//Add bone to internal list
	bone_map[bone.get_block()].weights = in;
	
	//Increment reference at bone node site
	((ABlock*)bone.get_block())->IncCrossRef(this);
}

void NiSkinData::RemoveCrossLink( IBlock * block_to_remove ) {
	//Remove bone from internal list
	bone_map.erase( block_to_remove );

	//Do not decrement bone node location because it is already dead
}

void NiSkinData::RemoveBone( blk_ref const & bone ) {
	//Remove bone from internal list
	bone_map.erase( bone.get_block() );

	//Decrement reference at bone node site
	//IBlockInternal * blk_int = (IBlockInternal*)bone->QueryInterface(BlockInternal);
	((ABlock*)bone.get_block())->DecCrossRef(this);
}

NiSkinData::~NiSkinData() {
	//Inform all linked bone nodes that this NiSkinData block is dying
	map<IBlock *, Bone>::iterator it;
	for (it = bone_map.begin(); it != bone_map.end(); ++it) {
		//IBlockInternal * node_int = (IBlockInternal*)it->first->QueryInterface(BlockInternal);
		((ABlock*)it->first)->DecCrossRef(this);
	}
}

INode * NiSkinData::GetNodeParent() const {
	//--Get Node Parent Bind Pose--//


	blk_ref par_block = GetParent();
	if ( par_block.is_null() == true ) {
		//throw runtime_error("SkinData block does not have parent.");
		return NULL;
	}

	par_block = par_block->GetParent();
	
	if ( par_block.is_null() == true ) {
		//throw runtime_error("SkinData block does not have parent of parent.");
		return NULL;
	}

	INode * par_node = (INode*)par_block->QueryInterface(ID_NODE);	
	if ( par_node == NULL ) {
		//throw runtime_error("SkinData block's parent of parent is not a node.");
		return NULL;
	}

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
	if ( par == NULL ) {
		throw runtime_error("Cannot calculate overall offset because this NiSkinData does not seem to be connected to a NiTriShape through a NiSkinInstance.");
	}

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
 * AKeyframeData methods
 **********************************************************/

void AKeyframeData::Read( istream& file, unsigned int version ) {

	scaleType = rotationType = translationType = xyzTypes[0] = xyzTypes[1] = xyzTypes[2] = KeyType(0);

	//--Rotation--//
	uint numRotations = ReadUInt( file );

	if (numRotations > 0) {
		NifStream( rotationType, file );

		if ( rotationType != 4 ) {
			rotKeys.resize( numRotations );
			for ( unsigned int i = 0; i < rotKeys.size(); ++i ) {
				StreamQuatKey(rotKeys[i], file, rotationType );
			}
		}
		else {
			//Before version 10.2.0.0, read vestigial time and discard
			if ( version < VER_10_2_0_0 ) {
				ReadFloat( file );
			}

			for (int i = 0; i < 3; i++) {
				int subCount = ReadUInt( file );
				if ( subCount > 0 ) {
					NifStream( xyzTypes[i], file );

					xyzKeys[i].resize( subCount );
					for (uint j = 0; j < xyzKeys[i].size(); j++) {
						NifStream(xyzKeys[i][j], file, xyzTypes[i] );
					}
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

void AKeyframeData::Write( ostream& file, unsigned int version ) const {

	//--Rotation--//
	WriteUInt( uint(rotKeys.size()) , file );

	if ( rotKeys.size() > 0) {
		NifStream( rotationType, file );

		if ( rotationType != 4 ) {
			for ( unsigned int i = 0; i < rotKeys.size(); ++i ) {
				StreamQuatKey(rotKeys[i], file, rotationType );
			}
		}
		else {
			//Before version 10.2.0.0, write vestigial time
			if ( version < VER_10_2_0_0 ) {
				WriteFloat( 0.0, file );
			}

			for (int i = 0; i < 3; i++) {
				WriteUInt( uint(xyzKeys[i].size()) , file );
				if ( xyzKeys[i].size() > 0 ) {
					NifStream( xyzTypes[i], file );

					for (uint j = 0; j < xyzKeys[i].size(); j++) {
						NifStream(xyzKeys[i][j], file, xyzTypes[i] );
					}
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

string AKeyframeData::asString() const {
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
 * NiPSysEmitterCtlrData methods
 **********************************************************/

void NiPSysEmitterCtlrData::Read( istream& file, unsigned int version ) {

	//--Float Keys--//
	uint numKeys = ReadUInt( file );

	if (numKeys > 0) {
		NifStream( f_key_type, file );
		float_keys.resize( numKeys );
		for ( uint i = 0; i < float_keys.size(); ++i ) {
			NifStream( float_keys[i], file, f_key_type );
		}
	}

	//--Byte Keys--//
	numKeys = ReadUInt( file );

	byte_keys.resize( numKeys );
	for ( uint i = 0; i < byte_keys.size(); ++i ) {
		NifStream( byte_keys[i], file, LINEAR_KEY );
	}	
}

void NiPSysEmitterCtlrData::Write( ostream& file, unsigned int version ) const {

	//--Float Keys--//
	WriteUInt( uint(float_keys.size()), file );

	if (float_keys.size() > 0) {
		NifStream( f_key_type, file );
		for ( uint i = 0; i < float_keys.size(); ++i ) {
			NifStream( float_keys[i], file, f_key_type );
		}	
	}

	//--Byte Keys--//
	WriteUInt( uint(byte_keys.size()), file );

	for ( uint i = 0; i < byte_keys.size(); ++i ) {
		NifStream( byte_keys[i], file, LINEAR_KEY );
	}	
}

string NiPSysEmitterCtlrData::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << "Float Key Count:  " << uint(float_keys.size()) << endl
		<< "Float Key Type:  " << f_key_type << endl;

	if (verbose) {
		vector< Key<float> >::const_iterator it;
		for ( it = float_keys.begin(); it != float_keys.end(); ++it ) {
			out << "Key Time:  " <<  it->time << "  Float Value:  " << it->data << endl;
		}
	} else {
		out << "<<Data Not Shown>>" << endl;
	}

	out << "Byte Key Count:  " << uint(byte_keys.size()) << endl;

	if (verbose) {
		vector< Key<byte> >::const_iterator it;
		for ( it = byte_keys.begin(); it != byte_keys.end(); ++it ) {
			out << "Key Time:  " <<  it->time << "  Float Value:  " << it->data << endl;
		}
	} else {
		out << "<<Data Not Shown>>" << endl;
	}

	return out.str();
}

/***********************************************************
 * NiBoolData methods
 **********************************************************/

void NiBoolData::Read( istream& file, unsigned int version ) {
	uint keyCount = ReadUInt( file );
	NifStream( _type, file );

	_keys.resize( keyCount );
	for (uint i = 0; i < _keys.size(); i++) {
		NifStream( _keys[i], file, _type );
	}
}

void NiBoolData::Write( ostream& file, unsigned int version ) const {
	WriteUInt( uint(_keys.size()), file );
	NifStream( _type, file );

	for (uint i = 0; i < _keys.size(); i++) {
		NifStream( _keys[i], file, _type );
	}
}

string NiBoolData::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << "Key Count:  " << uint(_keys.size()) << endl
		<< "Key Type:  " << _type << endl;

	if (verbose) {
		vector< Key<byte> >::const_iterator it;
		for ( it = _keys.begin(); it != _keys.end(); ++it ) {
			out << "Key Time:  " <<  it->time << "  Is Visible:  ";
			if ( it->data != 0 ) {
				out << "True" << endl;
			} else {
				out << "False" << endl;
			}
		}
	} else {
		out << "<<Data Not Shown>>" << endl;
	}

	return out.str();
}

/***********************************************************
 * NiColorData methods
 **********************************************************/

void NiColorData::Read( istream& file, unsigned int version ) {
	uint keyCount = ReadUInt( file );
	NifStream( _type, file );

	_keys.resize( keyCount );
	for (uint i = 0; i < _keys.size(); i++) {
		NifStream( _keys[i], file, _type );
	}
}

void NiColorData::Write( ostream& file, unsigned int version ) const {
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
 * NiControllerSequence methods
 **********************************************************/

void NiControllerSequence::Read( istream& file, unsigned int version ) {
	GetAttr("Name")->Read( file, version );

	//Up to version 10.1.0.0 the text key block is up here and named
	if ( version <= VER_10_1_0_0 ) {
		NifStream( txt_key_name, file );
		txt_key_blk.set_index( ReadUInt( file ) );
	}

	//Read the ControllerLink array
	uint count = ReadUInt( file );
	children.resize( count );

	//After version 10.2.0.0 there is an unknown int here
	if ( version >=	VER_10_2_0_0 ) {
		NifStream( unk_int1, file );
	}

	for (uint i = 0; i < children.size(); ++i ) {
		//Up to version 10.1.0.0 the name is stored here in a string
		if ( version <= VER_10_1_0_0 ) {
			NifStream( children[i].name, file );
		}
		children[i].block.set_index( ReadUInt(file)  );
		//From version 10.2.0.0 there is a lot more stuff here
		if ( version >= VER_10_2_0_0 ) {
			children[i].unk_link.set_index( ReadUInt(file) );
			//Read and discard duplicate String Palette index
			ReadUInt(file);
			//Read offsets
			NifStream( children[i].name_offset, file );
			NifStream( children[i].unk_short1, file );
			NifStream( children[i].property_offset, file );
			NifStream( children[i].unk_short2, file );
			NifStream( children[i].controller_offset, file );
			NifStream( children[i].unk_short3, file );
			NifStream( children[i].var1_offset, file );
			NifStream( children[i].unk_short4, file );
			NifStream( children[i].var2_offset, file );
			NifStream( children[i].unk_short5, file );
		}
	}
	
	//And from version 10.2.0.0 there is a lot more stuff down here as well
	if (version >= VER_10_2_0_0 ) {
		NifStream( unk_float1, file );

		//Text key link is down here now and has no name
		txt_key_blk.set_index( ReadUInt( file ) ); 

		for (int i = 0; i < 4; ++i ) {
			NifStream( unk_4_floats[i], file );
		}
		//This does not exist after version 10.2.0.0
		if ( version < VER_20_0_0_4 ) {
			NifStream( unk_float2, file );
		}
		NifStream( unk_int2, file );
		NifStream( unk_string, file );
		GetAttr("String Palette")->Read( file, version );
	}
}

void NiControllerSequence::Write( ostream& file, unsigned int version ) const {
	GetAttr("Name")->Write( file, version );

	//Up to version 10.1.0.0 the text key block is up here and named
	if ( version <= VER_10_1_0_0 ) {
		NifStream( txt_key_name, file );
		WriteUInt( txt_key_blk.get_index(), file );
	}

	//Read the ControllerLink array
	WriteUInt( uint(children.size()), file );

	//After version 10.2.0.0 there is an unknown int here
	if ( version >=	VER_10_2_0_0 ) {
		NifStream( unk_int1, file );
	}

	for (uint i = 0; i < children.size(); ++i ) {
		//Up to version 10.1.0.0 the name is stored here in a string
		if ( version <= VER_10_1_0_0 ) {
			NifStream( children[i].name, file );
		}
		WriteUInt( children[i].block.get_index(), file );
		//From version 10.2.0.0 there is a lot more stuff here
		if ( version >= VER_10_2_0_0 ) {
			WriteUInt( children[i].unk_link.get_index(), file );
			//Write duplicate String Palette index
			GetAttr("String Palette")->Write( file, version );

			//Write offsets
			NifStream( children[i].name_offset, file );
			NifStream( children[i].unk_short1, file );
			NifStream( children[i].property_offset, file );
			NifStream( children[i].unk_short2, file );
			NifStream( children[i].controller_offset, file );
			NifStream( children[i].unk_short3, file );
			NifStream( children[i].var1_offset, file );
			NifStream( children[i].unk_short4, file );
			NifStream( children[i].var2_offset, file );
			NifStream( children[i].unk_short5, file );
		}
	}
	
	//And from version 10.2.0.0 there is a lot more stuff down here as well
	if (version >= VER_10_2_0_0 ) {
		NifStream( unk_float1, file );

		//Text key link is down here now and has no name
		WriteUInt( txt_key_blk.get_index(), file );

		for (int i = 0; i < 4; ++i ) {
			NifStream( unk_4_floats[i], file );
		}
		//This does not exist after version 10.2.0.0
		if ( version < VER_20_0_0_4 ) {
			NifStream( unk_float2, file );
		}
		NifStream( unk_int2, file );
		NifStream( unk_string, file );
		GetAttr("String Palette")->Write( file, version );
	}
}

string NiControllerSequence::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << "Name:  " << GetAttr("Name")->asString() << endl
		<< "Text Key Name:  " << txt_key_name << endl
		<< "Text Key Block:  " << txt_key_blk << endl
		<< "Unknown Int 1:  " << unk_int1 << endl
		<< "Kf Children:";

	if ( children.size() == 0 ) {
		out << "  None" << endl;
	} else {
		out << endl;
	}

	//Check for a string palette
	string pal;
	blk_ref str_pal = GetAttr("String Palette")->asLink();
	if ( str_pal.is_fixed() == true && str_pal.is_null() == false ) {
		pal = str_pal->GetAttr("Palette")->asString();
	}

	for (uint i = 0; i < children.size(); ++i ) {
		out << "   Kf Child " << i + 1 << ":" << endl
			<< "      Name:  "  << children[i].name << endl
			<< "      Block:  " << children[i].block << endl
			<< "      Unknown Link:  " << children[i].unk_link << endl
			<< "      Name Offset      :  " << children[i].name_offset <<" (" << GetSubStr( pal, children[i].name_offset) << ")" << endl
			<< "      Unknown Short 1  :  " << children[i].unk_short1 << endl
			<< "      Property Offset  :  " << children[i].property_offset << " (" << GetSubStr( pal, children[i].property_offset) << ")" << endl
			<< "      Unknown Short 2  :  " << children[i].unk_short2 << endl
			<< "      Controller Offset:  " << children[i].controller_offset << " (" << GetSubStr( pal, children[i].controller_offset) << ")" << endl
			<< "      Unknown Short 3  :  " << children[i].unk_short3 << endl
			<< "      Variable 1 Offset:  " << children[i].var1_offset << " (" << GetSubStr( pal, children[i].var1_offset) << ")" << endl
			<< "      Unknown Short 4  :  " << children[i].unk_short4 << endl
			<< "      Variable 2 Offset:  " << children[i].var2_offset << " (" << GetSubStr( pal, children[i].var2_offset) << ")" << endl
			<< "      Unknown Short 5  :  " << children[i].unk_short5 << endl;
	}

	out << "Unknown Float 1:  " << unk_float1 << endl
		<< "Unknown 4 Floats:  " << unk_4_floats[0] << ", " << unk_4_floats[1] << ", " << unk_4_floats[2] << ", " << unk_4_floats[3] << endl
		<< "Unknown Float 2:  " << unk_float2 << endl
		<< "Unknown String:  " << unk_string << endl
		<< "String Palette:  " << GetAttr("String Palette")->asString() << endl;

	return out.str();
}

string NiControllerSequence::GetSubStr( const string & pal, short offset ) const {
	string out;
	
	// -1 is a null offset
	if ( offset == -1 ) {
		return out;
	}

	for ( uint i = offset; i < pal.size(); ++i ) {
		if ( pal[i] == '\0' ) {
			break;
		}
		out.push_back( pal[i] );
	}

	return out;
}

void NiControllerSequence::FixLinks( const vector<blk_ref> & blocks ) {
	ABlock::FixLinks( blocks );
	
	//Fix text key lnk
	if ( txt_key_blk.is_null() == false ) {
		txt_key_blk = blocks[txt_key_blk.get_index()];
	
		//Add this block as a child
		AddChild( txt_key_blk.get_block() );
	}

	for (uint i = 0; i < children.size(); ++i ) {
		if ( children[i].block.is_null() == false ) {
			//Fix links for this child
			children[i].block = blocks[children[i].block.get_index()];

			//Add this block as a child
			AddChild( children[i].block.get_block() );
		}
		
		if ( children[i].unk_link.is_null() == false ) {
			children[i].unk_link = blocks[children[i].unk_link.get_index()];

			//Add this block as a child
			AddChild( children[i].unk_link.get_block() );
		}
	}
}

list<blk_ref> NiControllerSequence::GetLinks() const {
	list<blk_ref> links = ABlock::GetLinks();

	//add link for text key block
	if ( txt_key_blk.is_null() == false ) {
		links.push_back( txt_key_blk );
	}

	//Add child links
	for (uint i = 0; i < children.size(); ++i ) {
		if ( children[i].block.is_null() == false ) {
			links.push_back( children[i].block );
		}
		if ( children[i].unk_link.is_null() == false ) {
			links.push_back( children[i].unk_link );
		}
	}

	return links;
}

NiControllerSequence::~NiControllerSequence() {

	//Remove text key child
	RemoveChild( txt_key_blk.get_block() );

	for (uint i = 0; i < children.size(); ++i ) {
		//Remove child blocks
		RemoveChild( children[i].block.get_block() );
		RemoveChild( children[i].unk_link.get_block() );
	}
}

void NiControllerSequence::SetTextKey( string new_name, blk_ref new_link ) {
	//Set new name
	txt_key_name = new_name;
	
	//Check for identical block values
	if ( new_link == txt_key_blk )
		return;
	
	//Remove old child
	if ( txt_key_blk.is_null() == false ) {
		RemoveChild( txt_key_blk.get_block() );
	}

	//Set new value
	txt_key_blk = new_link;

	//Add new child
	if ( txt_key_blk.is_null() == false ) {
		AddChild( txt_key_blk.get_block() );
	}
}

void NiControllerSequence::AddKfChild( string new_name, blk_ref new_link, string controller_type = "" ) {
	//Make sure the link isn't null
	if ( new_link.is_null() == true ) {
		throw runtime_error("Attempted to add a null link to NiControllerSequence block.");
	}

	KfChild kc;

	kc.block = new_link;

	//Check for a string palette
	blk_ref str_pal = GetAttr("String Palette")->asLink();
	if ( str_pal.is_null() == true ) {
		//No string palette, store name internally
		kc.name = new_name;
	} else {
		//String palette exists - store name and controller type there

		//Make sure they didn't give us empty strings
		if ( new_name.size() == 0 || controller_type.size() == 0 ) {
			throw runtime_error( "You cannot use empty name or controller type strings when using a string palette.");
		}

		//Get palette
		string pal = str_pal->GetAttr("Palette")->asString();

		//--Search for copies of the text we want to add--//

		//Search for the name string
		int offset = (int)pal.find( new_name );
		if ( offset == -1 ) {
			//String not found, append it
			kc.name_offset = (uint)pal.size();
			pal.append( new_name + '\0' );
		} else {
			//String found, use existing offset
			kc.name_offset = offset;
		}

		//Search for the controller type string
		offset = (int)pal.find( controller_type );
		if ( offset == -1 ) {
			//String not found, append it
			kc.controller_offset = (uint)pal.size();
			pal.append( controller_type + '\0' );
		} else {
			//String found, use existing offset
			kc.controller_offset = offset;
		}

		//Store the palette back to the string pal block
		str_pal->GetAttr("Palette")->Set( pal );
	}
	
	children.push_back( kc );

	//Add new child
	AddChild( kc.block.get_block() );
	
	//This should be impossible now, but don't want to forget it later
	if ( kc.unk_link.is_null() != true ) {
		AddChild( kc.unk_link.get_block() );
	}
}

void NiControllerSequence::ClearKfChildren() {

	//Cycle through all Kf Children, removing them as parents from the blocks they refer to
	for (uint i = 0; i < children.size(); ++i ) {
		if ( children[i].block.is_null() != true ) {
			RemoveChild( children[i].block.get_block() );
		}
		if ( children[i].unk_link.is_null() != true ) {
			RemoveChild( children[i].unk_link.get_block() );
		}
	}

	//Clear list
	children.clear();

	//Check for a string palette
	blk_ref str_pal = GetAttr("String Palette")->asLink();
	if ( str_pal.is_null() == false ) {
		//There's a string palette, so clear it out
		str_pal->GetAttr("Palette")->Set( "" );
	}
}

/***********************************************************
 * NiFloatData methods
 **********************************************************/

void NiFloatData::Read( istream& file, unsigned int version ) {
	uint keyCount = ReadUInt( file );
	NifStream( _type, file );

	_keys.resize( keyCount );
	for (uint i = 0; i < _keys.size(); i++) {
		NifStream( _keys[i], file, _type );
	}
}

void NiFloatData::Write( ostream& file, unsigned int version ) const {
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

void NiStringExtraData::Read( istream& in, unsigned int version ) {
	AExtraData::Read( in, version );
	
	//GetAttr("Name")->Read( in, version );
	//GetAttr("Next Extra Data")->Read( in, version );
	

	//Up to version 4.2.2.0, read bytes remaining but don't bother to store it
	if ( version <= VER_4_2_2_0 ) {
		ReadUInt( in );
	}

	GetAttr("String Data")->Read( in, version );
}

void NiStringExtraData::Write( ostream& out, unsigned int version ) const {
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

void NiMorphData::Read( istream& file, unsigned int version ) {

	uint morphCount = ReadUInt( file );
	NifStream( vertCount, file );

	//GetAttr("Unknown Byte")->Read( file, version );
	byte unk_byte = ReadByte( file );

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

void NiMorphData::Write( ostream& file, unsigned int version ) const {
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

void NiPalette::Read( istream& file, unsigned int version ) {

	NifStream( unkByte, file );
	NifStream( numEntries, file );
	

	//Read Palette
	for (int i = 0; i < 256; ++i) {
		for (int j = 0; j < 4; ++j) {
			NifStream( palette[i][j], file );
		}
	}
}

void NiPalette::Write( ostream& file, unsigned int version ) const {

	NifStream( unkByte, file );
	NifStream( numEntries, file );

	//Write Palette
	for (int i = 0; i < 256; ++i) {
		for (int j = 0; j < 4; ++j) {
			NifStream( palette[i][j], file );
		}
	}
}


string NiPalette::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	out << "Unknown Byte:  " << int(unkByte) << endl;
	out << "Num Entries?:  " << numEntries << endl;

	//Print Palette

	vector<Color4>col_pal = GetPalette();

	out << "Palette: (256 colors)" << endl;
	if (verbose) {
		for (int i = 0; i < 256; ++i) {
			out << i + 1 << ":  " << setw(4) << int(palette[i][0]) << ", " << setw(4) << int(palette[i][1]) << ", " << setw(4) << int(palette[i][2]) << ", " << setw(4) << int(palette[i][3]) << "\t";
			out << i + 1 << ":  " << setw(4) << col_pal[i].r << ", " << setw(4) << col_pal[i].g << ", " << setw(4) << col_pal[i].b << ", " << setw(4) << col_pal[i].a << endl;
		}
	} else {
		out << "  <<Data Not Shown>>" << endl;
	}

	return out.str();
}


vector<Color4> NiPalette::GetPalette() const {
	vector<Color4> color_pal(256);

	for ( uint i = 0; i < 256; ++i ) {
		
		color_pal[i].r = float(palette[i][0]) / 255.0f;
		color_pal[i].g = float(palette[i][1]) / 255.0f;
		color_pal[i].b = float(palette[i][2]) / 255.0f;
		color_pal[i].a = float(palette[i][3]) / 255.0f;
	}

	return color_pal;
}

void NiPalette::SetPalette( const vector<Color4> & new_pal ) {
	if ( new_pal.size() != 256 ) {
		throw runtime_error( "Palette size must be 256" );
	}

	for ( uint i = 0; i < 256; ++i ) {
		palette[i][0] = int( new_pal[i].r * 255.0f );
		palette[i][1] = int( new_pal[i].g * 255.0f );
		palette[i][2] = int( new_pal[i].b * 255.0f );
		palette[i][3] = int( new_pal[i].a * 255.0f );
	}
}

/***********************************************************
 * NiSkinPartition methods
 **********************************************************/

void NiSkinPartition::Read( istream& file, unsigned int version ) {

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

void NiSkinPartition::Write( ostream& file, unsigned int version ) const {

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
 * NiStringPalette methods
 **********************************************************/

void NiStringPalette::Read( istream& file, unsigned int version ) {

	GetAttr("Palette")->Read( file, version );

	//Read extra length and throw it away
	ReadUInt( file );
}

void NiStringPalette::Write( ostream& file, unsigned int version ) const {

	attr_ref pal_attr = GetAttr("Palette");
	pal_attr->Write( file, version );
	string pal_str = pal_attr->asString();

	//Write length of string again
	WriteUInt( uint(pal_str.size()), file );
}


string NiStringPalette::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	string pal = GetAttr("Palette")->asString();

	////Replace 0's with newlines
	//replace( pal.begin(), pal.end(), 0x00, 0x0A );

	//out << "String Palette:  " << endl
	//	<< pal << endl;

	out << "String Palette:" << endl
		<< "   0:  ";

	if ( pal.size() > 0 ) for ( uint i = 0; i < pal.size() - 1; ++i ) {
		if ( pal[i] == '\0') {
			out << endl << "   " << i + 1 << ":  ";
		} else {
			out << pal[i];
		}
	}
	out << endl;

	return out.str();
}


/***********************************************************
 * NiPixelData methods
 **********************************************************/

void NiPixelData::Read( istream& file, unsigned int version ) {
	//ABlock::Read( in, version );

	pxFormat = PixelFormat( ReadUInt(file) );

	//This data only exists before version 20.0.0.4
	if ( version < VER_20_0_0_4 ) {
		NifStream( redMask, file );
		NifStream( greenMask, file );
		NifStream( blueMask, file );
		NifStream( alphaMask, file );

		NifStream( bpp, file );

		for ( int i = 0; i < 8; ++i ) {
			NifStream( unk8Bytes[i], file );
		}

		//There is an unknown int here from version 10.1.0.0 to 10.2.0.0
		if ( version >= VER_10_1_0_0 ) {
			NifStream( unkInt, file );
		}
	} else {
		//After version 20.0.0.4 there are 54 unknown bytes here
		file.read( (char*)unk54Bytes, 54 );
	}

	GetAttr("Palette")->Read( file, version );

	uint mipCount = ReadUInt( file );



	//Read Bytes per pixel and discard
	ReadUInt( file );

	mipmaps.resize( mipCount );
	for ( uint i = 0; i < mipCount; ++i ) {
		mipmaps[i].width = ReadUInt( file );
		mipmaps[i].height = ReadUInt( file );
		mipmaps[i].offset = ReadUInt( file );
	}

	dataSize = ReadUInt( file );
	data = new byte[dataSize];

	//After version 20.0.0.4 there is an unknown int here
	if ( version >= VER_20_0_0_4 ) {
		NifStream( unkInt2, file );
	}
	
	file.read( (char *)data, dataSize);
}

void NiPixelData::Write( ostream& file, unsigned int version ) const {
	//ABlock::Write( file, version );

	WriteUInt( uint(pxFormat), file );

	//This data only exists before version 20.0.0.4
	if ( version < VER_20_0_0_4 ) {
		NifStream( redMask, file );
		NifStream( greenMask, file );
		NifStream( blueMask, file );
		NifStream( alphaMask, file );

		NifStream( bpp, file );

		for ( int i = 0; i < 8; ++i ) {
			NifStream( unk8Bytes[i], file );
		}
		
		//There is an unknown int here from version 10.1.0.0 to version 10.2.0.0
		if ( version >= VER_10_1_0_0 ) {
			NifStream( unkInt, file );
		}
	}

	GetAttr("Palette")->Write( file, version );

	//If there is no data stored, then there are no mipmaps.
	if ( dataSize > 0 ) {
		WriteUInt( uint(mipmaps.size()), file );
	} else {
		WriteUInt( 0, file );
	}

	WriteUInt( bpp / 8, file );

	//If there is no data stored, then there are no mipmaps.
	if ( dataSize > 0 ) {
		for ( uint i = 0; i < mipmaps.size(); ++i ) {
			WriteUInt( mipmaps[i].width, file );
			WriteUInt( mipmaps[i].height, file );
			WriteUInt( mipmaps[i].offset, file );
		}
	}

	WriteUInt( dataSize, file );

	//After version 20.0.0.4 there is an unknown int here
	if ( version >= VER_20_0_0_4 ) {
		NifStream( unkInt2, file );
	}

	file.write( (char *)data, dataSize);
}

string NiPixelData::asString() const {
	stringstream out;
	out.setf(ios::fixed, ios::floatfield);
	out << setprecision(1);

	//out << ABlock::asString();

	out << "Pixel Format:  ";
	switch (pxFormat) {
		case PX_FMT_RGB8:
			out << "0 - PX_FMT_RGB8" << endl;
			break;
		case PX_FMT_RGBA8:
			out << "1 - PX_FMT_RGBA8" << endl;
			break;
		case PX_FMT_PAL8:
			out << "2 - PX_FMT_PAL8" << endl;
			break;
		default:
			out << uint(pxFormat) << " - ???" << endl;
	}
	
	out << "Red Mask:  " << redMask << endl
		<< "Green Mask:  " << greenMask << endl
		<< "Blue Mask:  " << blueMask << endl
		<< "Alpha Mask:  " << alphaMask << endl
		<< "Bits Per Pixel:  " << bpp << endl
		<< "Mipmap Count:  " << uint(mipmaps.size()) << endl
		<< "Bytes Per Pixel:  " << bpp / 8 << endl
		<< "Unknown 8 Bytes:" << endl;

	for ( int i = 0; i < 8; ++i ) {
		out << i + 1 << ":  " << int(unk8Bytes[i]) << endl;
	}

	out << "Unknown Int:  " << unkInt << endl
		<< "Unknown 54 Bytes:" << endl;

	if (verbose) {
		out << HexString( unk54Bytes, 54 );
	} else {
		out << "   <<<Data Not Shown>>>";
	}

    out << "Palette:  "  << GetAttr("Palette")->asLink() << endl;

	for ( uint i = 0; i < mipmaps.size(); ++i ) {
		out << "Mipmap " << i + 1 << ":" << endl
			<< "   Width:  "  << mipmaps[i].width << endl
			<< "   Height:  " << mipmaps[i].height << endl
			<< "   Offset into Image Data Block:  " << mipmaps[i].offset << endl;
	
#ifdef IM_DEBUG
		switch ( pxFormat ) {
			case PX_FMT_RGB8:
				imdebug("rgb w=%d h=%d %p", mipmaps[i].width, mipmaps[i].height, &data[mipmaps[i].offset] );
				break;
			case PX_FMT_RGBA8:
				imdebug("rgba w=%d h=%d %p", mipmaps[i].width, mipmaps[i].height, &data[mipmaps[i].offset] );
				break;
			//case 4:
			//	byte * img = new byte[ mipmaps[i].width * mipmaps[i].height ];
			//	for ( uint j = 0; j < mipmaps[i].width * mipmaps[i].height / 2; ++j ) {
			//		byte temp = data[mipmaps[i].offset + j];

			//		img[j*2] = (temp & 0x0F) * 0x11;
			//		img[j*2+1] = (temp & byte(0xF0) >> 4) * 0x11; 

			//		//cout << "Pixel " << j*2 << ":  " << setbase(16) << int(img[j*2]) << endl;
			//		//cout << "Pixel " << j*2+1 << ":  " << setbase(16) << int(img[j*2+1]) << endl;
			//	};
			//	imdebug("lum w=%d h=%d %p", mipmaps[i].width, mipmaps[i].height, img );

			//	delete [] img;
			//	break;
		}

		//cout << "Displaying NiPixelData Image.  Press Enter to continue." << endl;
		//cin.get();
#endif
	}

	out << "Unknown Int 2:  " << unkInt2 << endl
		<< "Mipmap Image Data:  "  << dataSize << " Bytes (Not Shown)" << endl;
	
	return out.str();
}

int NiPixelData::GetHeight() const {
	if ( mipmaps.size() == 0 ) {
		return 0;
	} else {
		return mipmaps[0].height;
	}
}

int NiPixelData::GetWidth() const {
	if (mipmaps.size() == 0 ) {
		return 0;
	} else {
		return mipmaps[0].width;
	}
}

PixelFormat NiPixelData::GetPixelFormat() const {
	return pxFormat;
}

void NiPixelData::Reset( int new_width, int new_height, PixelFormat px_fmt ) {
	//Ensure that texture dimentions are powers of two
	if ( (new_height & (new_height-1)) != 0 ) {
		throw runtime_error("Texture height must be a power of two.  1, 2, 4, 8, 16, 32, 64, 256, 512, etc.");
	}

	if ( (new_width & (new_width-1)) != 0 ) {
		throw runtime_error("Texture width must be a power of two.  1, 2, 4, 8, 16, 32, 64, 256, 512, etc.");
	}
	
	//Delete any data that was previously held
	if ( data != NULL ) {
		delete [] data;
		data = NULL;
		dataSize = 0;
	}

	dataSize = 0;
	mipmaps.resize(1);


	//Set up first mipmap
	mipmaps[0].width = new_width;
	mipmaps[0].height = new_height;
	mipmaps[0].offset = 0;

	//Set up pixel format fields
	pxFormat = px_fmt;
	switch(pxFormat) {
		case PX_FMT_RGB8:
			redMask    = 0x000000FF;
			greenMask  = 0x0000FF00;
			blueMask   = 0x00FF0000;
			alphaMask  = 0x00000000;
			bpp = 24;
			unk8Bytes[0] = 96;
			unk8Bytes[1] = 8;
			unk8Bytes[2] = 130;
			unk8Bytes[3] = 0;
			unk8Bytes[4] = 0;
			unk8Bytes[5] = 65;
			unk8Bytes[6] = 0;
			unk8Bytes[7] = 0;
			break;
		case PX_FMT_RGBA8 :
			redMask    = 0x000000FF;
			greenMask  = 0x0000FF00;
			blueMask   = 0x00FF0000;
			alphaMask  = 0xFF000000;
			bpp = 32;
			unk8Bytes[0] = 129;
			unk8Bytes[1] = 8;
			unk8Bytes[2] = 130;
			unk8Bytes[3] = 32;
			unk8Bytes[4] = 0;
			unk8Bytes[5] = 65;
			unk8Bytes[6] = 12;
			unk8Bytes[7] = 0;
			break;	
		case PX_FMT_PAL8 :
			redMask   = 0x00000000;
			blueMask  = 0x00000000;
			greenMask = 0x00000000;
			alphaMask = 0x00000000;
			bpp = 8;
			unk8Bytes[0] = 34;
			unk8Bytes[1] = 0;
			unk8Bytes[2] = 0;
			unk8Bytes[3] = 32;
			unk8Bytes[4] = 0;
			unk8Bytes[5] = 65;
			unk8Bytes[6] = 12;
			unk8Bytes[7] = 0;
			break;	
		//[4,0,0,0,0,0,0,0] if 0 (?) bits per pixel
		default:
			throw runtime_error("The pixel type you have requested is not currently supported.");
	}
}

vector<Color4> NiPixelData::GetColors() const {
	vector<Color4> pixels;

	if ( mipmaps.size() == 0 ) {
		//Return empty vector
		return pixels;
	}

	//Pack the pixel data from the first mipmap into a vector of
	//Color4 based on the pixel format.
	pixels.resize( mipmaps[0].width * mipmaps[0].height );
	switch(pxFormat) {
		case PX_FMT_RGB8:
			for ( uint i = 0; i < pixels.size(); ++i ) {
				pixels[i].r = float(data[i * 3]) / 255.0f;
				pixels[i].g = float(data[i * 3 + 1]) / 255.0f;
				pixels[i].b = float(data[i * 3 + 2]) / 255.0f;
				pixels[i].a = 1.0f;
			}
			break;
		case PX_FMT_RGBA8:
			for ( uint i = 0; i < pixels.size(); ++i ) {
				pixels[i].r = float(data[i * 4]) / 255.0f;
				pixels[i].g = float(data[i * 4 + 1]) / 255.0f;
				pixels[i].b = float(data[i * 4 + 2]) / 255.0f;
				pixels[i].a = float(data[i * 4 + 3]) / 255.0f;
			}
			break;
		default:
			throw runtime_error("The GetColors function only supports the PX_FMT_RGB8 and PX_FMT_RGBA8 pixel formats.");
	}

#ifdef IM_DEBUG

	imdebug("rgba b=32f rs=2 w=%d h=%d %p", mipmaps[0].width, mipmaps[0].height, &pixels[0] );
	//delete [] img;
	cout << "Showing image returned by GetColors function." << endl;
	cin.get();
#endif

	return pixels;
}

void NiPixelData::SetColors( const vector<Color4> & new_pixels, bool generate_mipmaps ) {
	//Ensure that compatible pixel format is being used
	if ( pxFormat != PX_FMT_RGB8 && pxFormat != PX_FMT_RGBA8 ) {
		throw runtime_error("The SetColors function only supports the PX_FMT_RGB8 and PX_FMT_RGBA8 pixel formats.");
	}

	//Ensure that there is size information in the mipmaps
	if ( mipmaps.size() == 0 ) {
		throw runtime_error("The size informatoin has not been set.  Call the IPixelData::Reset() function first.");
	}

	//Ensure that the right number of pixels for the dimentions set have been passed
	if ( new_pixels.size() != mipmaps[0].height * mipmaps[0].width ) {
		throw runtime_error("You must pass one color for every pixel in the image.  There should be height * width colors.");
	}

	uint size = 0;
	mipmaps.resize(1);
	size = (mipmaps[0].height * mipmaps[0].width * bpp) / 8;

	//Deal with multiple mipmaps
	if ( generate_mipmaps == true ) {
		MipMap m;
		m.height = mipmaps[0].height;
		m.width = mipmaps[0].width;

		size = (mipmaps[0].height * mipmaps[0].width * bpp) / 8;

		while ( m.width != 1 && m.height != 1 ) {
			////cout << "Width:  " << m.width << "  Height:  " << m.height << "  Offset:  " << m.offset << endl;
			m.width /= 2;
			m.height /= 2;
			m.offset = size;

			size += (m.height * m.width * bpp) / 8;

			mipmaps.push_back(m);
		}
	}

	//Allocate space to store mipmaps
	if ( data != NULL ) {
		delete [] data;
	}

	dataSize = size * bpp / 8;
	data = new byte[dataSize];

	//Copy pixels to Color4 C array
	Color4 * tmp_image = new Color4[new_pixels.size()];

	for (uint i = 0; i < new_pixels.size(); ++i ) {
		tmp_image[i] = new_pixels[i];
	}

	//Pack pixel data
	for (uint i = 0; i < mipmaps.size(); ++i ) {
		cout << "Width:  " << mipmaps[i].width << "  Height:  " << mipmaps[i].height << "  Offset:  " << mipmaps[i].offset << endl;

		if ( i > 0 ) {
			//Allocate space to store re-sized image.
			Color4 * resized = new Color4[ mipmaps[i].width * mipmaps[i].height ];

			//Visit every other pixel in each row and column of the previous image
			for ( uint w = 0; w < mipmaps[i-1].width; w+=2 ) {
				for ( uint h = 0; h < mipmaps[i-1].height; h+=2 ) {
					//cout << "w:  " << w << "  h:  " << h << endl;
					Color4 & av = resized[(h/2) * mipmaps[i].width + (w/2)];

					//Start with the value of the current pixel
					av = tmp_image[h * mipmaps[i-1].width + w];
					float num_colors = 1.0f;

					//Only process the pixel above if height is > 1
					if ( h > 1 ) {
						Color4 & px = tmp_image[(h+1) * mipmaps[i-1].width + w];
						av.r += px.r;
						av.g += px.g;
						av.b += px.b;
						av.a += px.a;
						num_colors += 1.0f;
					}

					//Only process the pixel to the right if width > 1
					if (w > 1 ) {
						Color4 & px = tmp_image[h * mipmaps[i-1].width + (w+1)];
						av.r += px.r;
						av.g += px.g;
						av.b += px.b;
						av.a += px.a;
						num_colors += 1.0f;
					}

					//Only process the pixel to the upper right if both width and height are > 1
					if ( w > 1 && h >> 1 ) {
						Color4 & px = tmp_image[(h+1) * mipmaps[i-1].width + (w+1)];
						av.r += px.r;
						av.g += px.g;
						av.b += px.b;
						av.a += px.a;
						num_colors += 1.0f;
					}

					//Calculate average
					av.r /= num_colors;
					av.g /= num_colors;
					av.b /= num_colors;
					av.a /= num_colors;
				}
			}
			//Resize is complete, set result to tmp_image

			//delete old tmp_image data
			delete [] tmp_image;

			//Adjust pointer values
			tmp_image = resized;
			resized = NULL;
		}

		//Data is ready to be packed into the byes of this mipmap

		#ifdef IM_DEBUG
			cout << "Showing mipmap size " << mipmaps[i].width << " x " << mipmaps[i].height << "." << endl;
			imdebug("rgba b=32f w=%d h=%d %p", mipmaps[i].width, mipmaps[i].height, &tmp_image[0] );
			cin.get();
		#endif

		//Start at offset
		byte * map = &data[mipmaps[i].offset];

		switch(pxFormat) {
		case PX_FMT_RGB8:
			for ( uint j = 0; j < mipmaps[i].width * mipmaps[i].height; ++j ) {
				map[j * 3] = int( tmp_image[j].r * 255.0f );
				map[j * 3 + 1] = int( tmp_image[j].g * 255.0f );
				map[j * 3 + 2] = int( tmp_image[j].b * 255.0f );
			}

			//#ifdef IM_DEBUG
			//	cout << "Showing mipmap after being packed  - size " << mipmaps[i].width << " x " << mipmaps[i].height << "." << endl;
			//	imdebug("rgb w=%d h=%d %p", mipmaps[i].width, mipmaps[i].height, &map[0] );
			//	cin.get();
			//#endif
			break;
		case PX_FMT_RGBA8:
			for ( uint j = 0; j < mipmaps[i].width * mipmaps[i].height; ++j ) {
				map[j * 4] = int( tmp_image[j].r * 255.0f );
				map[j * 4 + 1] = int( tmp_image[j].g * 255.0f );
				map[j * 4 + 2] = int( tmp_image[j].b * 255.0f );
				map[j * 4 + 3] = int( tmp_image[j].a * 255.0f );
			}

			//#ifdef IM_DEBUG
			//	cout << "Showing mipmap after being packed  - size " << mipmaps[i].width << " x " << mipmaps[i].height << "." << endl;
			//	imdebug("rgba w=%d h=%d %p", mipmaps[i].width, mipmaps[i].height, &map[0] );
			//	cin.get();
			//#endif
			break;
		case PX_FMT_PAL8:
			throw runtime_error("The SetColors function only supports the PX_FMT_RGB8 and PX_FMT_RGBA8 pixel formats.");
			break;
		}
	}
}

//enum PixelFormat {
//	PX_FMT_RGBA8 = 0, /*!< 32-bit color with alpha: uses 8 bits to store each red, blue, green, and alpha component. */
//	PX_FMT_RGB8 = 1, /*!< 24-bit color: uses 8 bit to store each red, blue, and green component. */
//	PX_FMT_PAL8 = 2 /*!< 8-bit palette index: uses 8 bits to store an index into the palette stored in a NiPallete block. */
//};

/***********************************************************
 * NiPosData methods
 **********************************************************/

void NiPosData::Read( istream& file, unsigned int version ) {
	uint keyCount = ReadUInt( file );
	if ( keyCount > 0 ) {
		NifStream( _type, file );

		_keys.resize( keyCount );
		for (uint i = 0; i < _keys.size(); i++) {
			NifStream( _keys[i], file, _type );
		}
	}
}

void NiPosData::Write( ostream& file, unsigned int version ) const {
	WriteUInt( uint(_keys.size()), file );
	if ( _keys.size() > 0 ) {
		NifStream( _type, file );

		for (uint i = 0; i < _keys.size(); i++) {
			NifStream( _keys[i], file, _type );
		}
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

void NiTextKeyExtraData::Read( istream& file, unsigned int version ) {
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

void NiTextKeyExtraData::Write( ostream& file, unsigned int version ) const {

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

void NiUVData::Read( istream& in, unsigned int version ) {	
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

void NiUVData::Write( ostream& out, unsigned int version ) const {
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
 
void NiVertWeightsExtraData::Read( istream& in, unsigned int version ) {
	AExtraData::Read( in, version );

	//Read byte count but throw it away
	ReadUInt( in );

	ushort verts = ReadUShort( in );

	weights.resize( verts );
	for (uint i = 0; i < weights.size(); ++i) {
		weights[i] = ReadFloat( in );
	}
}

void NiVertWeightsExtraData::Write( ostream& out, unsigned int version ) const {
	AExtraData::Write( out, version );

	uint bytes = 2 + 4 * uint(weights.size());
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

void NiVisData ::Read( istream& in, unsigned int version ) {
	uint keyCount = ReadUInt( in );

	keys.resize( keyCount );
	for (uint i = 0; i < keys.size(); ++i) {
		keys[i].time = ReadFloat( in );
		keys[i].data = ReadByte( in ); // Is Visible? True/False
	}
}

void NiVisData ::Write( ostream& out, unsigned int version ) const {
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
 * NiLookAtInterpolator methods
 **********************************************************/

//void NiLookAtInterpolator::Read( istream& file, unsigned int version ) {
//	
//	GetAttr("Unknown Short")->Read( file, version );
//	
//	//Float Array
//	uint numFloats = ReadUInt( file );
//	unkFloats.resize( numFloats );
//	NifStream( unkFloats, file );
//	
//	GetAttr("Unknown Link")->Read( file, version );
//
//	//Byte Array
//	for (uint i = 0; i < 8; ++i ) {
//		NifStream( unkBytes[i], file );
//	}
//}
//
//void NiLookAtInterpolator::Write( ostream& file, unsigned int version ) const {
//
//}
//
//string NiLookAtInterpolator::asString() const {
//	stringstream out;
//	out.setf(ios::fixed, ios::floatfield);
//	out << setprecision(1);
//
//	return out.str();
//}


/***********************************************************
 * UnknownMixIn methods
 **********************************************************/

void UnknownMixIn::Read( istream &in, unsigned int version ) {
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

void UnknownMixIn::Write( ostream& out, unsigned int version ) const {
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
