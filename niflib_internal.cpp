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

#include "niflib_internal.h"

extern unsigned int blocks_in_memory;

/***********************************************************
 * ABlock methods
 **********************************************************/

ABlock::ABlock() : _block_num(-1), _ref_count(0) {
		blocks_in_memory++;
	}

ABlock::~ABlock() {
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

//void ABlock::AddAttr( AttrType type, string const & name, unsigned int first_ver, unsigned int last_ver ) {
//	IAttr * attr;
//
//	switch( type ) {
//		case attr_int:
//			attr = new IntAttr( name, this, first_ver, last_ver );
//			break;
//		case attr_short:
//			attr = new ShortAttr( name, this, first_ver, last_ver );
//			break;
//		case attr_byte:
//			attr = new ByteAttr( name, this, first_ver, last_ver );
//			break;
//		case attr_float:
//			attr = new FloatAttr( name, this, first_ver, last_ver );
//			break;
//		case attr_float3:
//			attr = new Float3Attr( name, this, first_ver, last_ver );
//			break;
//		case attr_string:
//			attr = new StringAttr( name, this, first_ver, last_ver );
//			break;
//		case attr_link:
//			attr = new LinkAttr( name, this, first_ver, last_ver );
//			break;
//		case attr_flags:
//			attr = new FlagsAttr( name, this, first_ver, last_ver );
//			break;
//		case attr_matrix33:
//			attr = new MatrixAttr( name, this, first_ver, last_ver );
//			break;
//		case attr_linkgroup:
//			attr = new LinkGroupAttr( name, this, first_ver, last_ver );
//			break;
//		case attr_bones:
//			attr = new BoneAttr( name, this, first_ver, last_ver );
//			break;
//		case attr_bbox:
//			attr = new BBoxAttr( name, this, first_ver, last_ver );
//			break;
//		case attr_condint:
//			attr = new CIntAttr( name, this, first_ver, last_ver );
//			break;
//		case attr_vertmode:
//			attr = new VertModeAttr( name, this, first_ver, last_ver );
//			break;
//		case attr_lightmode:
//			attr = new LightModeAttr( name, this, first_ver, last_ver );
//			break;
//		case attr_texsource:
//			attr = new TexSourceAttr( name, this, first_ver, last_ver );
//			break;
//		case attr_pixellayout:
//			attr = new PixelLayoutAttr( name, this, first_ver, last_ver );
//			break;
//		case attr_mipmapformat:
//			attr = new MipMapFormatAttr( name, this, first_ver, last_ver );
//			break;
//		case attr_alphaformat:
//			attr = new AlphaFormatAttr( name, this, first_ver, last_ver );
//			break;
//		case attr_controllertarget:
//			attr = new ControllerTargetAttr( name, this, first_ver, last_ver );
//			break;
//		case attr_skeletonroot:
//			attr = new SkeletonRootAttr( name, this, first_ver, last_ver );
//			break;
//		case attr_particlegroup:
//			attr = new ParticleGroupAttr( name, this, first_ver, last_ver );
//			break;
//		case attr_lodinfo:
//			attr = new LODInfoAttr( name, this, first_ver, last_ver );
//			break;
//		case attr_vector3:
//			attr = new Vector3Attr( name, this, first_ver, last_ver );
//			break;
//		case attr_color3:
//			attr = new Color3Attr( name, this, first_ver, last_ver );
//			break;
//		case attr_parent:
//			attr = new ParentAttr( name, this, first_ver, last_ver );
//			break;
//		case attr_unk292bytes:
//			attr = new Unk292BytesAttr( name, this, first_ver, last_ver );
//			break;
//		case attr_bool:
//			attr = new BoolAttr( name, this, first_ver, last_ver );
//			break;
//		case attr_targetgroup:
//			attr = new TargetGroupAttr( name, this, first_ver, last_ver );
//			break;
//		case attr_shader:
//			attr = new ShaderAttr( name, this, first_ver, last_ver );
//			break;
//		case attr_modifiergroup:
//			attr = new ModifierGroupAttr( name, this, first_ver, last_ver );
//			break;
//		case attr_color4:	
//			attr = new Color4Attr( name, this, first_ver, last_ver );	
//			break;
//		case attr_quaternion:
//			attr = new QuaternionAttr( name, this, first_ver, last_ver );	
//			break;
//		case attr_emitterobject:
//			attr = new EmitterObjectAttr( name, this, first_ver, last_ver );	
//			break;
//		case attr_selflink:
//			attr = new SelfLinkAttr( name, this, first_ver, last_ver );	
//			break;
//		case attr_crossref:
//			attr = new CrossRefAttr( name, this, first_ver, last_ver );	
//			break;
//		default:
//			cout << type << endl;
//			throw runtime_error("Unknown attribute type requested.");
//	};
//
//	_attr_map[name] = attr_ref(attr);
//	_attr_vect.push_back(attr_ref(attr));
//}

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
		//_attr_vect[i]->Read( in, version );
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
		//_attr_vect[i]->Write( out, version );
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
		//((AAttr*)it->ptr())->RemoveCrossLinks( block_to_remove );
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

//--Link Classes--//

//Constructor
//It is required for a LinkGroup to be aware of the block it is part of

void Link::SetIndex( const int new_index ) {
	//This function is for the initial file read.  It records the index of the block which
	//will later be resolved to a link once all the blocks have been read

	//If there is already a link, kill it
	if ( link.is_null() == false ) {
		KillLink();
		link.nullify();
	}

	index = new_index;
}

void Link::SetLink( const blk_ref & new_link ) {
	if ( link != new_link ) {
		//Kill previous link
		KillLink();
		
		//Set New Link
		link = new_link;
		InitLink();
	}
}

void Link::Fix( const vector<blk_ref> & blocks ) {
	//The purpouse of this function is to convert the block index to a link
	//to the corresponding block.

	//Ensure that there is an index to convert
	if (index == -1 ) {
		return;
	}
	
	if ( index < int(blocks.size()) && index >= 0 ) {
		link = blocks[index];
		InitLink();
	}
}

void Link::SetOwner( IBlock * owner ) {
	if ( owner != NULL ) {
		throw runtime_error("The owner for this Link is already set.");
	}
	_owner = owner;
}

void Link::InitLink() {
	//Ensure that the owner is set
	if ( _owner == NULL ) {
		throw runtime_error("You must specify an owner before you can store a blk_ref in a Link.");
	}
	//Add parent at new link site
	IBlock * target = link.get_block();
	if ( target != NULL ) {
		//Get internal interface
		((ABlock*)target)->AddParent( _owner );
	}
}
void Link::KillLink() {
	//Remove parent at previous location
	IBlock * target = link.get_block();
	if ( target != NULL ) {
		((ABlock*)target)->RemoveParent( _owner );
	}
}

//--CrossRef Classes--//

void CrossRef::SetIndex( const int new_index ) {
	//This function is for the initial file read.  It records the index of the block which
	//will later be resolved to a reference once all the blocks have been read

	//If there is already a reference, kill it
	if ( ref != NULL ) {
		KillRef();
		ref = NULL;
	}

	index = new_index;
}

void CrossRef::SetCrossRef( IBlock * new_ref ) {
	if ( ref != new_ref ) {
		//Kill previous link
		KillRef();
		
		//Set New Link
		ref = new_ref;
		InitRef();
	}
}

void CrossRef::LostRef(  IBlock * match ) {
	//This function's purpouse is to inform this CrossRef that the block it is referencing has died
	//It will be called on every CrossRef in this block, we must check to see if this is the one that
	//the message is meant for
	if ( ref == match ) {
		//Simply set it to NULL  do not call KillRef because the reference is already dead
		ref = NULL;
	}
}

void CrossRef::Fix( const vector<blk_ref> & blocks ) {
	//The purpouse of this function is to convert the block index to a reference
	//to the corresponding block.
	
	if (index < int(blocks.size()) && index >= 0 ) {
		ref = blocks[index].get_block();
		index = -1;
		InitRef();
	}
}

void CrossRef::SetOwner( IBlock * owner ) {
	if ( owner != NULL ) {
		throw runtime_error("The owner for this Link is already set.");
	}
	_owner = owner;
}

void CrossRef::InitRef() {
	//Inform target block that it is being cross referenced
	//Ensure that the owner is set
	if ( _owner == NULL ) {
		throw runtime_error("You must specify an owner before you can store an IBlock * in a CrossRef.");
	}
	if ( ref != NULL ) {
		//Get internal interface
		((ABlock*)ref)->IncCrossRef( _owner );
	}
}
void CrossRef::KillRef() {
	//Inform target block that it is no longer being cross referenced
	if ( ref != NULL ) {
		((ABlock*)ref)->IncCrossRef( _owner );
	}
}

