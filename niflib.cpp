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

//Temporary Global to test reference counting
unsigned int blocks_in_memory = 0;

//Utility Functions
void ReorderNifTree( vector<blk_ref> & blk_list, blk_ref block );
void BuildUpBindPositions( blk_ref block );
blk_ref FindRoot( vector<blk_ref> & blocks );

//--Function Bodies--//
void SetVerboseMode( bool val ) { verbose = val; }

blk_ref CreateBlock( string block_type ) {
	IBlock * block = NULL;

	if (block_type == "AvoidNode") {
		block = new AvoidNode;
	} else if (block_type == "NiAlphaController") {
		block = new NiAlphaController;
	} else if (block_type == "NiAlphaProperty") {
		block = new NiAlphaProperty;
	} else if (block_type == "NiAmbientLight") {
		block = new NiAmbientLight;
	} else if (block_type == "NiAutoNormalParticles") {
		block = new NiAutoNormalParticles;
	} else if (block_type == "NiBillboardNode") {
		block = new NiBillboardNode;
	} else if (block_type == "NiBSAnimationNode") {
		block = new NiBSAnimationNode;
	} else if (block_type == "NiBSParticleNode") {
		block = new NiBSParticleNode;
	} else if (block_type == "NiCamera") {
		block = new NiCamera;
	} else if (block_type == "NiColorData") {
		block = new NiColorData;
	} else if (block_type == "NiDirectionalLight") {
		block = new NiDirectionalLight;
	} else if (block_type == "NiDitherProperty") {
		block = new NiDitherProperty;
	} else if (block_type == "NiFloatData") {
		block = new NiFloatData;
	} else if (block_type == "NiGeomMorpherController") {
		block = new NiGeomMorpherController;
	} else if (block_type == "NiGravity") {
		block = new NiGravity;
	} else if (block_type == "NiKeyframeController") {
		block = new NiKeyframeController;
	} else if (block_type == "NiKeyframeData") {
		block = new NiKeyframeData;
	} else if (block_type == "NiMaterialColorController") {
		block = new NiMaterialColorController;
	} else if (block_type == "NiMaterialProperty") {
		block = new NiMaterialProperty;
	} else if (block_type == "NiMorphData") {
		block = new NiMorphData;
	} else if (block_type == "NiNode") {
		block = new NiNode;
	} else if (block_type == "NiParticleColorModifier") {
		block = new NiParticleColorModifier;
	} else if (block_type == "NiParticleGrowFade") {
		block = new NiParticleGrowFade;
	} else if (block_type == "NiParticleRotation") {
		block = new NiParticleRotation;
	//} else if (block_type == "NiParticleSystemController") {
	//	block = new NiParticleSystemController;
	} else if (block_type == "NiPathController") {
		block = new NiPathController;
	} else if (block_type == "NiPixelData") {
		block = new NiPixelData;
	} else if (block_type == "NiPlanarCollider") {
		block = new NiPlanarCollider;
	} else if (block_type == "NiPosData") {
		block = new NiPosData;
	} else if (block_type == "NiRotatingParticles") {
		block = new NiRotatingParticles;
	//} else if (block_type == "NiRotatingParticlesData") {
	//	block = new NiRotatingParticlesData;
	} else if ( block_type == "NiSequenceStreamHelper") {
		block = new NiSequenceStreamHelper;
	} else if (block_type == "NiShadeProperty") {
		block = new NiShadeProperty;
	} else if (block_type == "NiSkinData") {
		block = new NiSkinData;
	} else if (block_type == "NiSkinInstance") {
		block = new NiSkinInstance;
	} else if (block_type == "NiSourceTexture") {
		block = new NiSourceTexture;
	} else if (block_type == "NiSpecularProperty") {
		block = new NiSpecularProperty;
	} else if (block_type == "NiStringExtraData") {
		block = new NiStringExtraData;
	} else if (block_type == "NiTextKeyExtraData") {
		block = new NiTextKeyExtraData;
	} else if (block_type == "NiTextureEffect") {
		block = new NiTextureEffect;
	} else if (block_type == "NiTexturingProperty") {
		block = new NiTexturingProperty;
	} else if (block_type == "NiTriShape") {
		block = new NiTriShape;
	} else if (block_type == "NiTriShapeData") {
		block = new NiTriShapeData;
	} else if ( block_type == "NiUVController") {
		block = new NiUVController;
	} else if (block_type == "NiUVData") {
		block = new NiUVData;
	} else if ( block_type == "NiVertexColorProperty") {
		block = new NiVertexColorProperty;
	} else if (block_type == "NiVertWeightsExtraData") {
		block = new NiVertWeightsExtraData;
	} else if (block_type == "NiVisController") {
		block = new NiVisController;
	} else if (block_type == "NiVisData") {
		block = new NiVisData;
	} else if (block_type == "NiWireframeProperty") {
		block = new NiWireframeProperty;
	} else if (block_type == "NiZBufferProperty") {
		block = new NiZBufferProperty;
	} else if (block_type == "RootCollisionNode") {
		block = new RootCollisionNode;
	// Unknown Blocks
	} else if ( block_type == "NiRendererSpecificProperty" ) {
		block = new UnknownPropertyBlock( block_type );
	} else if ( block_type == "NiBSPArrayController" || block_type == "NiParticleSystemController" ) {
		block = new UnknownControllerBlock( block_type );
	} else {
		block = new UnknownBlock( block_type );
	}

	return blk_ref(block);
}

//Reads the given file by file name and returns a reference to the root block
blk_ref ReadNifTree( string file_name ) {
	//Read block list
	return FindRoot( ReadNifList( file_name ) );
}

blk_ref FindRoot( vector<blk_ref> & blocks ) {
	//--Look for a NiNode that has no parents--//

	//Find the first Node
	blk_ref root;
	for (uint i = 0; i < blocks.size(); ++i) {
		if ( blocks[i]->QueryInterface(Node) || blocks[i]->GetBlockType() == "NiPixelData" ) {
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
	char header_string[HEADER_STRING_LEN];
	in.read( header_string, HEADER_STRING_LEN );
	byte unknownByte = ReadByte( in );
	char ver[4];
	in.read(ver, 4);
	uint numBlocks = ReadUInt( in );

	////Output
	//cout << "====[ NiHeader ]====" << endl <<
	//		"Header:  " << Str(header_string, HEADER_STRING_LEN) << endl <<
	//		"Unknown Byte:  " << Hex(unknownByte) << endl <<
	//		"Version:  " << int(ver[3]) << "." << int(ver[2]) << "." << int(ver[1]) << "." << int(ver[0]) << endl <<
	//		"Number of blocks: " << int(numBlocks) << endl;

	//vector<blk_ref> v;
	//return v;

	//if ( unknownByte != 10 ) {
	//	cout << "Unknown Byte != 10\a" << endl;
	//	cin.get();
	//}
	//if ( version != 67108866 ) {
	//	cout << "Version != 67108866\a" << endl;
	//	cin.get();
	//}

	//--Read Blocks--//
	vector<blk_ref> blocks( numBlocks );
	for (uint i = 0; i < numBlocks; i++) {
		// Find which block type this is.
		uint blockNameLength = ReadUInt( in );
		if (blockNameLength > 30 || blockNameLength < 6) {
			cout << "ERROR!  Bad block position.  Invalid Name Length:  " << blockNameLength << "\a" << endl;
			cout << "====[ " << file_name << " | Block " << i - 1 << " | " << blocks[i - 1]->GetBlockType() << " ]====" << endl;
			cout << blocks[i - 1]->asString();
			cin.get();
		}
		char* blockName = new char[blockNameLength + 1];
		in.read( blockName, blockNameLength );
		blockName[blockNameLength] = 0;
		if ( (blockName[0] != 'N' || blockName[1] != 'i') && (blockName[0] != 'R' || blockName[1] != 'o') && (blockName[0] != 'A' || blockName[1] != 'v')) {
			cout << "ERROR!  Bad block position.  Invalid Name:  " << Str(blockName, blockNameLength) << "\a" << endl;
			cout << "====[ " << file_name << " | Block " << i - 1 << " | " << blocks[i - 1]->GetBlockType() << " ]====" << endl;
			cout << blocks[i - 1]->asString();
			cin.get();
		}

		cout << i << " " << blockName << endl;

		//Create Block of the type that was found
		blocks[i] = CreateBlock(blockName);

		//Get internal interface
		IBlockInternal * bk_intl = (IBlockInternal*)blocks[i]->QueryInterface( BlockInternal );

		if (bk_intl != NULL) {
			//Set the Block number
			bk_intl->SetBlockNum(i);

			//Read the block from the file
			bk_intl->Read( in );
		}
		else {
			throw runtime_error("Failed to create block.");
		}

		if (blockName != NULL)
			delete [] blockName;
	}

	//--Read Footer--//
	uint unknownInt = ReadUInt( in );
	uint unknownInt2 = ReadUInt( in );

	//Output
	//cout << "====[ NiFooter ]====" << endl <<
	//		"Unknown Int 1:  " << Hex(unknownInt) << endl <<
	//		"Unknown Int 2: " << Hex(unknownInt2) << endl;

	//if ( unknownInt != 1 ) {
	//	cout << "Unknown Int 1 != 1\a" << endl;
	//	cin.get();
	//}
	//if ( unknownInt2 != 0 ) {
	//	cout << "Unknown Int 2 != 0\a" << endl;
	//	cin.get();
	//}

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
void WriteNifTree( string file_name, blk_ref & root_block ) {
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
		//Get internal interface
		IBlockInternal * bk_intl = (IBlockInternal*)blk_list[i]->QueryInterface( BlockInternal );

		bk_intl->Write( out );
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
		if ( it->is_null() == false ) {
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
	INode * blk_node = (INode*)block->QueryInterface(Node);
	if (blk_node == NULL)
		return;

	//Get parent if there is one
	blk_ref par = block->GetParent();
	if (par.is_null() == false) {
		INode * par_node = (INode*)par->QueryInterface(Node);
		if (par_node != NULL) {
			//There is a node parent
			//Post-multipy the block's bind matrix with the parent's bind matrix
			float par_mat[4][4];
			par_node->GetBindPosition( par_mat );
			float blk_mat[4][4];
			blk_node->GetBindPosition( blk_mat );
			float result[4][4];
			MultMatrix44( blk_mat, par_mat, result );
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

ITriShapeData * QueryTriShapeData( blk_ref block ) {
	return (ITriShapeData*)block->QueryInterface( TriShapeData );
}

ISkinData * QuerySkinData( blk_ref block ) {
	return (ISkinData*)block->QueryInterface( SkinData );
}

INode * QueryNode( blk_ref block ) {
	return (INode*)block->QueryInterface( Node );
}
