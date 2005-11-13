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

#include "niflib.h"
#include "NIF_Blocks.h"
#include "nif_attrs.h"
#include <exception>
#include <stdexcept>
using namespace std;

bool verbose = false;

//Stores the mapping between block names and factory function pointers to create them
typedef IBlock * (*blk_factory_func)();
bool global_block_map_init = false;
map<string, blk_factory_func> global_block_map;

//Temporary Global to test reference counting
unsigned int blocks_in_memory = 0;

//Utility Functions
void ReorderNifTree( vector<blk_ref> & blk_list, blk_ref block );
void BuildUpBindPositions( blk_ref block );
blk_ref FindRoot( vector<blk_ref> & blocks );
void RegisterBlockFactories ();

//--Function Bodies--//
void SetVerboseMode( bool val ) { verbose = val; }

blk_ref CreateBlock( string block_type ) {
	
	//Initialize the global block list if it hasn't been done yet
	if ( global_block_map_init == false ) {
		RegisterBlockFactories();
		global_block_map_init = true;
	}

	IBlock * block = NULL;

	map<string, blk_factory_func>::iterator it;
	it = global_block_map.find(block_type);

	if ( it != global_block_map.end() ) {
		//Requested type has been registered
		block = it->second();
	} else {
		//An unknown type has been encountered
		return blk_ref(-1); //Return null block_ref
		//block = new UnknownBlock( block_type );
	}
	
	return blk_ref(block);
}

//Reads the given file by file name and returns a reference to the root block
blk_ref ReadNifTree( string file_name ) {
	//Read block list
	vector<blk_ref> blocks = ReadNifList( file_name );
	return FindRoot( blocks );
}

blk_ref FindRoot( vector<blk_ref> & blocks ) {
	//--Look for a NiNode that has no parents--//

	//Find the first Node
	blk_ref root;
	for (uint i = 0; i < blocks.size(); ++i) {
		if ( blocks[i]->QueryInterface(ID_NODE) || blocks[i]->GetBlockType() == "NiPixelData" ) {
			root = blocks[i];
			break;
		}
	}

	//Make sure a node was found, if not return first node
	if ( root.is_null() )
		return blocks[0];

	//Move up the chain to the root node
	while ( root->GetParent().is_null() != true ) {
		root = root->GetParent();
	}

	return root;
}

//Reads the given file by file name and returns a vector of block references
vector<blk_ref> ReadNifList( string file_name ) {

	//--Open File--//
	ifstream in( file_name.c_str(), ifstream::binary );

	//--Read Header--//
	char header_string[256];
	in.getline( header_string, 256 );
	uint version = ReadUInt( in );

	//There is an unknownInt here from version 10.1.0.0 on
	uint unknownInt1;
	if ( version >= 0x0A010000 ) {
		unknownInt1 = ReadUInt( in );
	}

	uint numBlocks = ReadUInt( in );

	vector<string> blockTypes;
	vector<short> blockTypeIndex;
	//New header data exists from version 5.0.0.1 on
	if ( version >= 0x05000001 ) {
		short numBlockTypes = ReadUShort( in );
		blockTypes.resize(numBlockTypes);
		for ( uint i = 0; i < blockTypes.size(); ++i ) {
			blockTypes[i] = ReadString( in );
		}

		blockTypeIndex.resize(numBlocks);
		for ( uint i = 0; i < blockTypeIndex.size(); ++i ) {
			blockTypeIndex[i] = ReadUShort( in );
		}

		uint unknownInt2 = ReadUInt( in );
		//uint unknownInt3 = ReadUInt( in );

		////Output
		//cout << endl << endl 
		//	 << "====[ " << file_name << " | File Header ]====" << endl
		//	 << "Header:  " << header_string << endl
		//	 << "Version:  " << Hex(version) << endl
		//	 << "Unknown Int 1:  " << unknownInt1 << endl
		//	 << "Number of Blocks: " << int(numBlocks) << endl
		//	 << "Block Types:  " << uint(blockTypes.size()) << endl;

		//for ( uint i = 0; i < blockTypes.size(); ++i ) {
		//	cout << "   " << i + 1 << ":  " << blockTypes[i] << endl;
		//}

		//cout << "Block Type Indices:  " << numBlocks << endl;
		//for ( uint i = 0; i < blockTypeIndex.size(); ++i ) {
		//	cout << "   " << i + 1 << ":  " << blockTypeIndex[i] << endl;
		//}

		//cout << "Unknown Int 2:  " << unknownInt2 << endl;
	} else {
		////Output
		//cout << endl << endl 
		//	<< "====[ " << file_name << " | File Header ]====" << endl
		//	<< "Header:  " << header_string << endl
		//	<< "Version:  " << Hex(version) << endl
		//	<< "Number of Blocks: " << int(numBlocks) << endl;
	}


	//--Read Blocks--//
	vector<blk_ref> blocks( numBlocks );
	string blockName;
	for (uint i = 0; i < numBlocks; i++) {
	
		//There are two ways to read blocks, one before version 5.0.0.1 and one after that
		if ( version >= 0x05000001 ) {
			//From version 5.0.0.1 on there is a zero byte at the end of each block
			//Throw an exception if it's not zero
			uint checkValue = ReadUInt( in );
			if ( checkValue != 0 ) {
				cout << "ERROR!  Bad block position.  Invalid check value\a" << endl;
				cout << "====[ " << file_name << " | Block " << i - 1 << " | " << blocks[i - 1]->GetBlockType() << " ]====" << endl;
				cout << blocks[i - 1]->asString();
				throw runtime_error("Read failue - Bad block position");
			}

			// Find which block type this is by using the header arrays
			blockName = blockTypes[ blockTypeIndex[i] ];
		} else {
			// Find which block type this is by reading the string at this location
			uint blockNameLength = ReadUInt( in );
			if (blockNameLength > 30 || blockNameLength < 6) {
				cout << "ERROR!  Bad block position.  Invalid Name Length:  " << blockNameLength << "\a" << endl;
				cout << "====[ " << file_name << " | Block " << i - 1 << " | " << blocks[i - 1]->GetBlockType() << " ]====" << endl;
				cout << blocks[i - 1]->asString();
				throw runtime_error("Read failue - Bad block position");
			}
			char* charBlockName = new char[blockNameLength + 1];
			in.read( charBlockName, blockNameLength );
			charBlockName[blockNameLength] = 0;
			blockName = string(charBlockName);
			delete [] charBlockName;
			if ( (blockName[0] != 'N' || blockName[1] != 'i') && (blockName[0] != 'R' || blockName[1] != 'o') && (blockName[0] != 'A' || blockName[1] != 'v')) {
				cout << "ERROR!  Bad block position.  Invalid Name:  " << blockName << "\a" << endl;
				cout << "====[ " << file_name << " | Block " << i - 1 << " | " << blocks[i - 1]->GetBlockType() << " ]====" << endl;
				cout << blocks[i - 1]->asString();
				throw runtime_error("Read failue - Bad block position");
			}
		}

		//cout << endl << i << ":  " << blockName;

		//Create Block of the type that was found
		blocks[i] = CreateBlock(blockName);

		//Check for an unknown block type
		if ( blocks[i].is_null() == true ) {
			//For version 5.0.0.1 and up, throw an exception - there's nothing we can do
			if ( version >= 0x05000001 ) {
				stringstream str;
				str << "Unknown block type encountered during file read:  " << blockName;
				throw runtime_error( str.str() );
			} else {
				//We can skip over this block in older versions
				blocks[i] = new UnknownBlock(blockName);
			}
		}

		//Get internal interface
		IBlockInternal * bk_intl = (IBlockInternal*)blocks[i]->QueryInterface( BlockInternal );

		if (bk_intl != NULL) {
			//Set the Block number
			bk_intl->SetBlockNum(i);

			//Read the block from the file
			bk_intl->Read( in, version );

			//cout << blocks[i]->asString() << endl;
		}
		else {
			throw runtime_error("Failed to create block.");
		}
	}

	//cout << endl;

	//--Read Footer--//
	uint unknownInt = ReadUInt( in );
	uint unknownInt2 = ReadUInt( in );

	//Output
	//cout << "====[ NiFooter ]====" << endl <<
	//		"Unknown Int 1:  " << Hex(unknownInt) << endl <<
	//		"Unknown Int 2: " << Hex(unknownInt2) << endl;


	//--Close File--//
	in.close();

	//--Now that all blocks are read, go back and fix the indices--//
	for (uint i = 0; i < blocks.size(); ++i) {
		//Get internal interface
		IBlockInternal * bk_intl = (IBlockInternal*)blocks[i]->QueryInterface( BlockInternal );

		//Fix links
		bk_intl->FixUpLinks( blocks );
		
		//--Skin Processing--//

		ISkinDataInternal * skin_data;
		skin_data = (ISkinDataInternal *)blocks[i]->QueryInterface( SkinDataInternal );
		if ( skin_data != NULL ) {
			//Fix indicies for bones as they are copied from NiSkinInstance blocks to  NiSkinData blocks
			blk_ref inst_blk = blocks[i]->GetParent();
			if ( inst_blk.is_null() == false ) {
				ISkinInstInternal * inst_data = (ISkinInstInternal*)inst_blk->QueryInterface( SkinInstInternal );
				if ( inst_data != NULL ) {
					vector<int> bone_list = inst_data->GetBoneList();
					vector<blk_ref> bone_blks( bone_list.size() );
					for ( uint i = 0; i < bone_list.size(); ++i ) {
						bone_blks[i] = blocks[ bone_list[i] ];
					}
					skin_data->SetBones( bone_blks );
				}
			}
		
			//Straigten up the skeleton to match with the "bind pose" for any skin instances that exist
			skin_data->StraightenSkeleton();
		}
	}

	//Build up the bind pose matricies into their world-space equivalents
	BuildUpBindPositions( FindRoot(blocks) );

	// Re-position any TriShapes with a SkinInstance
	for (uint i = 0; i < blocks.size(); ++i) {
		ISkinDataInternal * skin_data;
		skin_data = (ISkinDataInternal *)blocks[i]->QueryInterface( SkinDataInternal );
		if ( skin_data != NULL ) {
			skin_data->RepositionTriShape();
		}	
	}

	//Return completed block list
	return blocks;
}

//Writes a valid Nif File given a file name, a pointer to the root block of a file tree
void WriteNifTree( string file_name, blk_ref & root_block, unsigned int version ) {
	// Walk tree, resetting all block numbers
	//int block_count = ResetBlockNums( 0, root_block );
	
	//Reorder blocks into a list
	vector<blk_ref> blk_list;
	ReorderNifTree( blk_list, root_block );

	//Open output file
	ofstream out( file_name.c_str(), ofstream::binary );

	//--Write Header--//
	out.write( "NetImmerse File Format, Version 4.0.0.2 \n", HEADER_STRING_LEN );
	WriteByte( 10, out ); // Unknown Byte = 10
	char ver[] = {2,0,0,4}; // Version = 4.0.0.2 for Morrowind
	out.write( ver, 4 );
	WriteUInt( uint(blk_list.size()), out ); //Number of blocks

	//--WriteBlocks--//
	for (uint i = 0; i < blk_list.size(); ++i) {
		if (version < 0x05000001) {
			//Write Block Type
			WriteString( blk_list[i]->GetBlockType() , out );
		}

		//Get internal interface
		IBlockInternal * bk_intl = (IBlockInternal*)blk_list[i]->QueryInterface( BlockInternal );

		bk_intl->Write( out, version );

		if (version >= 0x05000001) {
			WriteUInt( 0, out );
		}
	}

	//--Write Footer--//
	WriteUInt( 1, out ); // Unknown Int = 1 (usually)
	WriteUInt( 0, out ); // Unknown Int = 0 (usually)

	//Close file
	out.close();
}
void ReorderNifTree( vector<blk_ref> & blk_list, blk_ref block ) {
	//Get internal interface
	IBlockInternal * bk_intl = (IBlockInternal*)block->QueryInterface( BlockInternal );

	bk_intl->SetBlockNum( int(blk_list.size()) );
	blk_list.push_back(block);

	list<blk_ref> links = block->GetLinks();
	list<blk_ref>::iterator it;
	for (it = links.begin(); it != links.end(); ++it) {
		if ( it->is_null() == false && (*it)->GetParent() == block ) {
			ReorderNifTree( blk_list, *it );
		}
	}
	//for (int i = 0; i < block->LinkCount(); ++i) {
	//	blk_link l = block->GetLink(i);
	//	if ( l.block.get_block() != NULL && l.block->GetParent() == block ) {
	//		ReorderNifTree( list, l.block );
	//	}
	//}
}

//int ResetBlockNums( int start_num, blk_ref block ) {
//	cout << "Setting " << block << " to " << start_num << endl;
//	block->SetBlockNum( start_num );
//	start_num++;
//	for (uint i = 0; i < block->LinkCount(); ++i) {
//		blk_link l = block->GetLink(i);
//		if ( l.block.get_block() != NULL && l.attr->LinkType() == child_link ) {
//			start_num = ResetBlockNums( start_num, l.block );
//		}
//	}
//	return start_num;
//	
//}

void BuildUpBindPositions( blk_ref block ) {

	//Return if this is not a node
	INode * blk_node = (INode*)block->QueryInterface(ID_NODE);
	if (blk_node == NULL)
		return;

	//Get parent if there is one
	blk_ref par = block->GetParent();
	if (par.is_null() == false) {
		INode * par_node = (INode*)par->QueryInterface(ID_NODE);
		if (par_node != NULL) {
			//There is a node parent
			//Post-multipy the block's bind matrix with the parent's bind matrix
			Matrix44 par_mat = par_node->GetBindPosition();
			Matrix44 blk_mat = blk_node->GetBindPosition();
			Matrix44 result = MultMatrix44( blk_mat, par_mat);

			//Store result back to block bind position
			blk_node->SetBindPosition( result );
		}
	}

	//Call this function for all child nodes if any
	attr_ref child_attr = block["Children"];
	if ( child_attr.is_null() == false ) {
		list<blk_ref> children = child_attr->asLinkList();
		list<blk_ref>::iterator it;
		for (it = children.begin(); it != children.end(); ++it) {
			BuildUpBindPositions( *it );
		}
	}
}

//Returns the total number of blocks in memory
unsigned int BlocksInMemory() {
	return blocks_in_memory;
}

//--Attribute Reference Functions--//

attr_ref::operator blk_ref() { return _attr->asLink(); }
attr_ref::operator TextureSource() { return _attr->asTextureSource(); }
attr_ref::operator BoundingBox() { return _attr->asBoundingBox(); }
attr_ref::operator ConditionalInt() { return _attr->asConditionalInt(); }
attr_ref::operator Texture() { return _attr->asTexture(); }

//--Query Functions--//

IShapeData * QueryShapeData( blk_ref & block ) {
	return (IShapeData*)block->QueryInterface( ID_SHAPE_DATA );
}

ITriShapeData * QueryTriShapeData( blk_ref & block ) {
	return (ITriShapeData*)block->QueryInterface( ID_TRI_SHAPE_DATA );
}

ISkinData * QuerySkinData( blk_ref & block ) {
	return (ISkinData*)block->QueryInterface( ID_SKIN_DATA );
}

INode * QueryNode( blk_ref & block ) {
	return (INode*)block->QueryInterface( ID_NODE );
}

IKeyframeData * QueryKeyframeData( blk_ref & block ) {
	return (IKeyframeData*)block->QueryInterface( ID_KEYFRAME_DATA );
}

ITextKeyExtraData * QueryTextKeyExtraData ( blk_ref & block ) {
	return (ITextKeyExtraData*)block->QueryInterface( ID_TEXT_KEY_EXTRA_DATA );
}

IMorphData * QueryMorphData ( blk_ref & block ) {
	return (IMorphData*)block->QueryInterface( ID_MORPH_DATA );
}
