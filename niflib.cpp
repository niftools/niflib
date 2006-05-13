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
#include "kfm.h"
#include "NIF_IO.h"
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
void EnumerateNifTree( NiObjectRef const & root, map<Type,uint> & type_map, map<NiObjectRef, uint> link_map );
void BuildUpBindPositions( blk_ref const & block );
blk_ref FindRoot( vector<blk_ref> const & blocks );
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
		return NULL; //Return null block_ref
		//block = new UnknownBlock( block_type );
	}
	
	return blk_ref(block);
}

//Reads the given file by file name and returns a reference to the root block
blk_ref ReadNifTree( string const & file_name ) {
	//Read block list
	vector<blk_ref> blocks = ReadNifList( file_name );
	return FindRoot( blocks );
}

//Reads the given input stream and returns a reference to the root block
blk_ref ReadNifTree( istream & in ) {
	//Read block list
	vector<blk_ref> blocks = ReadNifList( in );
	return FindRoot( blocks );
}

NiObjectRef FindRoot( vector<blk_ref> const & blocks ) {
	//--Look for a NiNode that has no parents--//

	//Find the first NiObjectNET derived object
	NiObjectNETRef root;
	for (uint i = 0; i < blocks.size(); ++i) {
		root = DynamicCast<NiObjectNET>(blocks[i]);
		if ( root != NULL ) {
			break;
		}
	}

	//Make sure a node was found, if not return first node
	if ( root == NULL )
		return blocks[0];

	//Move up the chain to the root node
	while ( root->GetParent() != NULL ) {
		root = root->GetParent();
	}

	return StaticCast<NiObject>(root);
}

unsigned int CheckNifHeader( string const & file_name ) {
	//--Open File--//
	ifstream in( file_name.c_str(), ifstream::binary );

	//--Read Header--//
	char header_string[64];
	in.getline( header_string, 64 );
	string headerstr(header_string);

	// make sure this is a NIF file
	if ( ( headerstr.substr(0, 22) != "NetImmerse File Format" )
	&& ( headerstr.substr(0, 20) != "Gamebryo File Format" ) )
		return VER_INVALID;

	// supported versions
	if ( headerstr == "NetImmerse File Format, Version 4.0.0.2" ) return VER_4_0_0_2;
	if ( headerstr == "NetImmerse File Format, Version 4.1.0.12" ) return VER_4_1_0_12;
	if ( headerstr == "NetImmerse File Format, Version 4.2.0.2" ) return VER_4_2_0_2;
	if ( headerstr == "NetImmerse File Format, Version 4.2.1.0" ) return VER_4_2_1_0;
	if ( headerstr == "NetImmerse File Format, Version 4.2.2.0" ) return VER_4_2_2_0;
	if ( headerstr == "NetImmerse File Format, Version 10.0.1.0" ) return VER_10_0_1_0;
	if ( headerstr == "Gamebryo File Format, Version 10.1.0.0" ) return VER_10_1_0_0;
	if ( headerstr == "Gamebryo File Format, Version 10.2.0.0" ) return VER_10_2_0_0;
	if ( headerstr == "Gamebryo File Format, Version 20.0.0.4" ) return VER_20_0_0_4;
	if ( headerstr == "Gamebryo File Format, Version 20.0.0.5" ) return VER_20_0_0_5;

	// anything else: unsupported
	return VER_UNSUPPORTED;
}

//Reads the given file by file name and returns a vector of block references
vector<blk_ref> ReadNifList( string const & file_name ) {

	//--Open File--//
	ifstream in( file_name.c_str(), ifstream::binary );

	return ReadNifList( in );
}

//Reads the given input stream and returns a vector of block references
vector<blk_ref> ReadNifList( istream & in ) {

	//--Read Header--//
	char header_string[256];
	in.getline( header_string, 256 );
	string headerstr(header_string);

	// make sure this is a NIF file
	if ( ( headerstr.substr(0, 22) != "NetImmerse File Format" )
	&& ( headerstr.substr(0, 20) != "Gamebryo File Format" ) )
		throw runtime_error("Not a NIF file.");

	// detect old versions
	if ( ( headerstr == "NetImmerse File Format, Version 3.1" )
	|| ( headerstr == "NetImmerse File Format, Version 3.03" )
	|| ( headerstr == "NetImmerse File Format, Version 3.0" )
	|| ( headerstr == "NetImmerse File Format, Version 2.3" ) )
		throw runtime_error("Unsupported: " + headerstr);

	uint version = ReadUInt( in );

	//There is an unknown Byte here from version 20.0.0.4 on
	byte unknownByte;
	if ( version >= VER_20_0_0_4 ) {
		unknownByte = ReadByte( in );
	}

	//There is an Unknown Int here from version 10.1.0.0 on
	uint unknownInt1 = 0;
	if ( version >= VER_10_1_0_0 ) {
		unknownInt1 = ReadUInt( in );
	}

	uint numBlocks = ReadUInt( in );

	if ( unknownInt1 != 0 ) {
		uint len;
		ReadUInt( in );
		len = ReadByte( in );
		for (uint i = 0; i < len; i++) ReadByte( in );
		len = ReadByte( in );
		for (uint i = 0; i < len; i++) ReadByte( in );
		len = ReadByte( in );
		for (uint i = 0; i < len; i++) ReadByte( in );
	}
	
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

		//uint unknownInt2 =
		ReadUInt( in );

		////Output
		//cout << endl << endl 
		//	 << "====[ " << "File Header ]====" << endl
		//	 << "Header:  " << header_string << endl
		//	 << "Version:  " << Hex(version) << endl
		//	 << "Unknown Int 1:  " << unknownInt1 << endl
		//	 << "Number of Blocks: " << int(numBlocks) << endl
		//	 << "Block Types:  " << uint(blockTypes.size()) << endl;

		//for ( uint i = 0; i < blockTypes.size(); ++i ) {
		//	cout << "   " << i << ":  " << blockTypes[i] << endl;
		//}

		//cout << "Block Type Indices:  " << numBlocks << endl;
		//for ( uint i = 0; i < blockTypeIndex.size(); ++i ) {
		//	cout << "   " << i + 1 << ":  " << blockTypeIndex[i] << endl;
		//}

		//cout << "Unknown Int 2:  " << unknownInt2 << endl;
	} else {
		////Output
		//cout << endl << endl 
		//	<< "====[ " << "File Header ]====" << endl
		//	<< "Header:  " << header_string << endl
		//	<< "Version:  " << Hex(version) << endl
		//	<< "Number of Blocks: " << int(numBlocks) << endl;
	}


	//--Read Blocks--//
	vector<NiObjectRef> blocks( numBlocks ); //List to hold the blocks
	list<uint> link_stack; //List to add link values to as they're read in from the file
	string blockName;
	for (uint i = 0; i < numBlocks; i++) {

		//Check for EOF
		//if (in.eof() ) {
		//	throw runtime_error("End of file reached prematurely.  This NIF may be corrupt or improperly supported.");
		//}
	
		//There are two ways to read blocks, one before version 5.0.0.1 and one after that
		if ( version >= 0x05000001 ) {
			//From version 5.0.0.1 to version 10.0.1.0  there is a zero byte at the begining of each block
			
			if ( version <= VER_10_1_0_0 ) {
				uint checkValue = ReadUInt( in );
				if ( checkValue != 0 ) {
					//Throw an exception if it's not zero
					cout << "ERROR!  Bad block position.  Invalid check value\a" << endl;
					cout << "====[ " << "Block " << i << " | " << blocks[i - 1]->GetType().GetTypeName() << " ]====" << endl;
					cout << blocks[i - 1]->asString();
					throw runtime_error("Read failue - Bad block position");
				}
			}

			// Find which block type this is by using the header arrays
			blockName = blockTypes[ blockTypeIndex[i] ];
		} else {
			// Find which block type this is by reading the string at this location
			uint blockNameLength = ReadUInt( in );
			if (blockNameLength > 30 || blockNameLength < 6) {
				cout << "ERROR!  Bad block position.  Invalid Name Length:  " << blockNameLength << "\a" << endl;
				cout << "====[ " << "Block " << i - 1 << " | " << blocks[i - 1]->GetType().GetTypeName() << " ]====" << endl;
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
				cout << "====[ " << "Block " << i - 1 << " | " << blocks[i - 1]->GetType().GetTypeName() << " ]====" << endl;
				cout << blocks[i - 1]->asString();
				throw runtime_error("Read failue - Bad block position");
			}
		}

		//cout << endl << i << ":  " << blockName;

		//Create Block of the type that was found
		blocks[i] = CreateBlock(blockName);

		//Check for an unknown block type
		if ( blocks[i] == NULL ) {
			//For version 5.0.0.1 and up, throw an exception - there's nothing we can do
			//if ( version >= 0x05000001 ) {
				stringstream str;
				str << "Unknown block type encountered during file read:  " << blockName;
				throw runtime_error( str.str() );
			//} else {
				//We can skip over this block in older versions
				//blocks[i] = new UnknownBlock(blockName);
			//}
		}

		//blocks[i]->SetBlockNum(i);
		blocks[i]->Read( in, link_stack, version );

		//cout << endl << blocks[i]->asString() << endl;
	}

	//cout << endl;

	//--Read Footer--//
	uint unknownCount = ReadUInt( in );
	for (uint i=0; i < unknownCount; i++) ReadUInt( in ); // throw away
	//Output
	//cout << "====[ NiFooter ]====" << endl <<
	//	"Unknown Count:  " << Hex(unknownCount) << endl;

	ReadByte( in ); // this should fail, and trigger the in.eof() flag
	if ( ! in.eof() )
		throw runtime_error("End of file not reached.  This NIF may be corrupt or improperly supported.");
		
	//--Now that all blocks are read, go back and fix the links--//
	for (uint i = 0; i < blocks.size(); ++i) {

		//Fix links & other pre-processing
		blocks[i]->FixLinks( blocks, link_stack, version );
	}

	//Build up the bind pose matricies into their world-space equivalents
	BuildUpBindPositions( FindRoot(blocks) );

	//TODO: Evaluate this and see if it can be moved to NiTriBasedGeom::FixLinks()
	//// Re-position any TriShapes with a SkinInstance
	//for (uint i = 0; i < blocks.size(); ++i) {
	//	
	//	attr_ref si_attr = blocks[i]->GetAttr("Skin Instance");
	//	if ( si_attr.is_null() == true ) {
	//		continue;
	//	}

	//	blk_ref si_blk = si_attr->asLink();

	//	if ( si_blk.is_null() == true ) {
	//		continue;
	//	}

	//	blk_ref sd_blk = si_blk->GetAttr("Data")->asLink();

	//	if ( sd_blk.is_null() == true ) {
	//		continue;
	//	}

	//	ISkinDataInternal * skin_data;
	//	skin_data = (ISkinDataInternal *)sd_blk->QueryInterface( SkinDataInternal );
	//	if ( skin_data != NULL ) {
	//		skin_data->RepositionTriShape( blocks[i] );
	//	}	

	//	//cout << i + 1 << ":  " << blocks[i] << endl;
	//}

	//Return completed block list
	return blocks;
}

// Writes a valid Nif File given a file name, a pointer to the root block of a file tree
void WriteNifTree( string const & file_name, blk_ref const & root_block, unsigned int version ) {
	//Open output file
	ofstream out( file_name.c_str(), ofstream::binary );

	WriteNifTree( out, root_block, version );

	//Close file
	out.close();
}

// Writes a valid Nif File given an ostream, a pointer to the root block of a file tree
void WriteNifTree( ostream & out, NiObjectRef const & root, unsigned int version ) {
	// Walk tree, resetting all block numbers
	//int block_count = ResetBlockNums( 0, root_block );
	
	//Enumerate all objects in tree
	map<Type,uint> type_map;
	map<NiObjectRef, uint> link_map;

	EnumerateNifTree( root, type_map, link_map );

	//Build vectors for reverse look-up
	vector<NiObjectRef> objects(link_map.size());
	for ( map<NiObjectRef, uint>::iterator it = link_map.begin(); it != link_map.end(); ++it ) {
		objects[it->second] = it->first;
	}

	vector<const Type*> types(type_map.size());
	for ( map<Type, uint>::iterator it = type_map.begin(); it != type_map.end(); ++it ) {
		types[it->second] = &(it->first);
	}

	//--Write Header--//
	//Version 10.0.1.0 is the last known to use the name NetImmerse
	stringstream header_string;
	if ( version <= VER_10_0_1_0 ) {
		header_string << "NetImmerse File Format, Version ";
	} else {
		header_string << "Gamebryo File Format, Version ";
	}
	char * byte_ver = (char*)&version;
	int int_ver[4] = { byte_ver[3], byte_ver[2], byte_ver[1], byte_ver[0] };


	header_string << int_ver[0] << "." << int_ver[1] << "." << int_ver[2] << "." << int_ver[3];

	out << header_string.str();
	WriteByte( 10, out ); // Unknown Byte = 10
	WriteUInt( version, out );

	//There is an unknown Byte here from version 20.0.0.4 on
	if ( version >= VER_20_0_0_4 ) {
		WriteByte( 1, out );
	}

	//There is an Unknown Int here from version 10.1.0.0 on
	if ( version >= VER_10_1_0_0 ) {
		WriteUInt( 0, out );
	}
	
	WriteUInt( uint(objects.size()), out ); //Number of objects

	//New header data exists from version 5.0.0.1 on
	if ( version >= 0x05000001 ) {
		WriteUShort( ushort(type_map.size()), out );
		
		//Write Type Names
		for ( uint i = 0; i < types.size(); ++i ) {
			WriteString( types[i]->GetTypeName(), out );

		}

		//Write type number of each block
		for ( uint i = 0; i < objects.size(); ++i ) {
			WriteUShort( type_map[objects[i]->GetType()], out );

		}

		//Unknown Int 2
		WriteUInt( 0, out );
	}

	//--Write Objects--//
	for (uint i = 0; i < objects.size(); ++i) {

		if (version < 0x05000001) {
			//cout << i << ":  " << blk_list[i]->GetBlockType() << endl;
			//Write Block Type
			WriteString( objects[i]->GetType().GetTypeName() , out );
		} else if (version >= 0x05000001 && version <= VER_10_1_0_0 ) {
			WriteUInt( 0, out );
		}

		objects[i]->Write( out, link_map, version );
	}

	//--Write Footer--//
	WriteUInt( 1, out ); // Unknown Int = 1 (usually)
	WriteUInt( 0, out ); // Unknown Int = 0 (usually)
}

void EnumerateNifTree( NiObjectRef const & root, map<Type,uint> & type_map, map<NiObjectRef, uint> link_map ) {
	//Ensure that this object has not already been visited
	if ( link_map.find( root ) != link_map.end() ) {
		//This object has already been visited.  Return.
		return;
	}

	//Add object to link map
	link_map[root] = uint(link_map.size());

	//Add this object type to the map if it isn't there already
	if ( type_map.find( root->GetType() ) == type_map.end() ) {
		//The type has not yet been registered, so register it
		type_map[root->GetType()] = uint(type_map.size());
	}
	
	//Call this function on all links of this object
	
	list<NiObjectRef> links = root->GetLinks();
	for ( list<blk_ref>::iterator it = links.begin(); it != links.end(); ++it ) {
		EnumerateNifTree( *it, type_map, link_map );
	}
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

void BuildUpBindPositions( const NiAVObjectRef av ) {

	//Get parent if there is one
	NiAVObjectRef par = DynamicCast<NiAVObject>(av->GetParent());
	if ( par != NULL ) {
		//There is an AV Object parent

		//Post-multipy the block's bind matrix with the parent's bind matrix
		Matrix44 result = av->GetWorldBindPos() * par->GetWorldBindPos();

		//Store result back to block bind position
		av->SetWorldBindPos( result );
	}

	////Call this function for all child nodes if any
	//attr_ref child_attr = block["Children"];
	//if ( child_attr.is_null() == false ) {
	//	list<blk_ref> children = child_attr->asLinkList();
	//	list<blk_ref>::iterator it;
	//	for (it = children.begin(); it != children.end(); ++it) {
	//		BuildUpBindPositions( *it );
	//	}
	//}
}

// Searches for the first object in the hierarchy of type block_type.
NiObjectRef SearchNifTree( const NiObjectRef & root_block, const Type & block_type ) {
	if ( root_block->IsSameType( block_type ) ) {
		return root_block;
	}
	//list<blk_ref> links = root_block->GetLinks();
	//for (list <blk_ref>::iterator it = links.begin(); it != links.end(); ++it) {
	//	// if the link is not null, and if the child's first parent is root_block
	//	// (this makes sure we only check every child once, even if it is shared by multiple parents),
	//	// then look for a match in the tree starting from the child.
	//	if ( it->is_null() == false && (*it)->GetParent() == root_block ) {
	//		blk_ref result = SearchNifTree( *it, block_type );
	//		if ( result.is_null() == false ) return result;
	//	};
	//};
	return NULL; // return null reference
};

// Returns all blocks in the tree of type block_name.
list<blk_ref> SearchAllNifTree( blk_ref const & root_block, Type & block_type ) {
	list<blk_ref> result;
	if ( root_block->IsSameType(block_type) ) {
		//result.push_back( root_block );
	}
	/*list<blk_ref> links = root_block->GetLinks();
	for (list<blk_ref>::iterator it = links.begin(); it != links.end(); ++it ) {
		if ( it->is_null() == false && (*it)->GetParent() == root_block ) {
			list<blk_ref> childresult = SearchAllNifTree( *it, block_type );
			result.merge( childresult );
		};
	};*/
	return result;
};

//list<blk_ref> GetNifTree( blk_ref const & root_block ) {
//	list<blk_ref> result;
//	result.push_back( root_block );
//	list<blk_ref> links = root_block->GetLinks();
//	for (list<blk_ref>::iterator it = links.begin(); it != links.end(); ++it ) {
//		if ( it->is_null() == false && (*it)->GetParent() == root_block ) {
//			list<blk_ref> childresult = GetNifTree( *it );
//			result.merge( childresult );
//		};
//	};
//	return result;
//};

/*!
 * Helper function to split off animation from a nif tree. If no animation groups are defined, then both xnif_root and xkf_root will be null blocks.
 * \param root_block The root block of the full tree.
 * \param xnif_root The root block of the tree without animation.
 * \param xkf_root The root block of the animation tree.
 * \param kfm The KFM structure (if required by style).
 * \param kf_type What type of keyframe tree to write (Morrowind style, DAoC style, ...).
 */
//void SplitNifTree( blk_ref const & root_block, blk_ref & xnif_root, blk_ref & xkf_root, Kfm & kfm, int kf_type ) {
//	// Do we have animation groups (a NiTextKeyExtraData block)?
//	// If so, create XNif and XKf trees.
//	blk_ref txtkey_block = SearchNifTree( root_block, "NiTextKeyExtraData" );
//	if ( txtkey_block.is_null() == false ) {
//		if ( kf_type == KF_MW ) {
//			// Construct the XNif file...
//			// We are lazy. (TODO: clone & remove keyframe controllers & keyframe data)
//			xnif_root = root_block;
//			
//			// Now the XKf file...
//			// Create xkf root header.
//			xkf_root = CreateBlock("NiSequenceStreamHelper");
//			
//			// Add a copy of the NiTextKeyExtraData block to the XKf header.
//			blk_ref xkf_txtkey_block = CreateBlock("NiTextKeyExtraData");
//			xkf_root["Extra Data"] = xkf_txtkey_block;
//			
//			ITextKeyExtraData const *itxtkey_block = QueryTextKeyExtraData(txtkey_block);
//			ITextKeyExtraData *ixkf_txtkey_block = QueryTextKeyExtraData(xkf_txtkey_block);
//			ixkf_txtkey_block->SetKeys(itxtkey_block->GetKeys());
//			
//			// Append NiNodes with a NiKeyFrameController as NiStringExtraData blocks.
//			list<blk_ref> nodes = SearchAllNifTree( root_block, "NiNode" );
//			for ( list<blk_ref>::iterator it = nodes.begin(); it != nodes.end(); ) {
//				if ( (*it)->GetAttr("Controller")->asLink().is_null() || (*it)->GetAttr("Controller")->asLink()->GetBlockType() != "NiKeyframeController" )
//					it = nodes.erase( it );
//				else
//					it++;
//			};
//			
//			blk_ref last_block = xkf_txtkey_block;
//			for ( list<blk_ref>::const_iterator it = nodes.begin(); it != nodes.end(); ++it ) {
//				blk_ref nodextra = CreateBlock("NiStringExtraData");
//				nodextra["String Data"] = (*it)["Name"]->asString();
//				last_block["Next Extra Data"] = nodextra;
//				last_block = nodextra;
//			};
//			
//			// Add controllers & controller data.
//			last_block = xkf_root;
//			for ( list<blk_ref>::const_iterator it = nodes.begin(); it != nodes.end(); ++it ) {
//				blk_ref controller = (*it)->GetAttr("Controller")->asLink();
//				blk_ref xkf_controller = CreateBlock("NiKeyframeController");
//				xkf_controller["Flags"] = controller["Flags"]->asInt();
//				xkf_controller["Frequency"] = controller["Frequency"]->asFloat();
//				xkf_controller["Phase"] = controller["Phase"]->asFloat();
//				xkf_controller["Start Time"] = controller["Start Time"]->asFloat();
//				xkf_controller["Stop Time"] = controller["Stop Time"]->asFloat();
//				
//				blk_ref xkf_data = CreateBlock("NiKeyframeData");
//				xkf_controller["Data"] = xkf_data;
//				IKeyframeData const *ikfdata = QueryKeyframeData(controller["Data"]->asLink());
//				IKeyframeData *ixkfdata = QueryKeyframeData(xkf_data);
//				ixkfdata->SetRotateType(ikfdata->GetRotateType());
//				ixkfdata->SetTranslateType(ikfdata->GetTranslateType());
//				ixkfdata->SetScaleType(ikfdata->GetScaleType());
//				ixkfdata->SetRotateKeys(ikfdata->GetRotateKeys());
//				ixkfdata->SetTranslateKeys(ikfdata->GetTranslateKeys());
//				ixkfdata->SetScaleKeys(ikfdata->GetScaleKeys());
//	
//				if ( last_block == xkf_root ) {
//					if ( ! last_block["Controller"]->asLink().is_null() )
//						throw runtime_error("Cannot create .kf file for multicontrolled nodes."); // not sure 'bout this one...
//					last_block["Controller"] = xkf_controller;
//				} else {
//					if ( ! last_block["Next Controller"]->asLink().is_null() )
//						throw runtime_error("Cannot create .kf file for multicontrolled nodes."); // not sure 'bout this one...
//					last_block["Next Controller"] = xkf_controller;
//				};
//				last_block = xkf_controller;
//				// note: targets are automatically calculated, we don't need to reset them
//			};
//		} else // TODO other games
//			throw runtime_error("Not yet implemented.");
//	} else {
//		// no animation groups: nothing to do
//		xnif_root = blk_ref();
//		xkf_root = blk_ref();
//	};
//}

/*!
 * Helper function to split an animation tree into multiple animation trees (one per animation group) and a kfm block.
 * \param root_block The root block of the full tree.
 * \param kf Vector of root blocks of the new animation trees.
 */
void SplitKfTree( blk_ref const & root_block, vector<blk_ref> & kf ) {
	throw runtime_error("Not yet implemented.");
};

void WriteFileGroup( string const & file_name, blk_ref const & root_block, unsigned int version, unsigned int export_files, unsigned int kf_type ) {
	//// Get base filename.
	//uint file_name_slash = uint(file_name.rfind("\\") + 1);
	//string file_name_path = file_name.substr(0, file_name_slash);
	//string file_name_base = file_name.substr(file_name_slash, file_name.length());
	//uint file_name_dot = uint(file_name_base.rfind("."));
	//file_name_base = file_name_base.substr(0, file_name_dot);
	//
	//// Deal with the simple case first
	//if ( export_files == EXPORT_NIF )
	//	WriteNifTree( file_name_path + file_name_base + ".nif", root_block, version ); // simply export the NIF file!
	//// Now consider all other cases
	//else if ( kf_type == KF_MW ) {
	//	if ( export_files == EXPORT_NIF_KF ) {
	//		// for Morrowind we must also write the full NIF file
	//		WriteNifTree( file_name_path + file_name_base + ".nif", root_block, version ); // simply export the NIF file!
	//		blk_ref xnif_root;
	//		blk_ref xkf_root;
	//		Kfm kfm; // dummy
	//		SplitNifTree( root_block, xnif_root, xkf_root, kfm, KF_MW );
	//		if ( ! xnif_root.is_null() ) {
	//			WriteNifTree( file_name_path + "x" + file_name_base + ".nif", xnif_root, version );
	//			WriteNifTree( file_name_path + "x" + file_name_base + ".kf", xkf_root, version );
	//		};
	//	} else
	//		throw runtime_error("Invalid export option.");
	//} else
	//	throw runtime_error("Not yet implemented.");
};


//Returns the total number of blocks in memory
unsigned int BlocksInMemory() {
	return blocks_in_memory;
}

void MapParentNodeNames( map<string,blk_ref> & name_map, blk_ref par ) {
	////Check if this block is a scene graph node
	//if ( par->QueryInterface( ID_NODE ) == false ) {
	//	throw runtime_error( "Only trees that have a node as the root can be merged." );
	//}

	////Check if this is a parent node
	//attr_ref children = par->GetAttr("Children");
	//if ( children.is_null() == true ) {
	//	//We are only interested in parent nodes
	//	return;
	//}

	////Add the par node to the map, and then call this function for each of its children
	//name_map[par->GetAttr("Name")->asString()] = par;

	//list<blk_ref> links = par->GetAttr("Children")->asLinkList();;
	//for (list <blk_ref>::iterator it = links.begin(); it != links.end(); ++it) {
	//	if ( it->is_null() == false ) {
	//		MapParentNodeNames( name_map, *it );
	//	};
	//};
}

void ReassignTreeCrossRefs( map<string,blk_ref> & name_map, blk_ref par ) {
	////Reassign any cross references on this block
	//((ABlock*)par.get_block())->ReassignCrossRefs( name_map );

	//list<blk_ref> links = par->GetLinks();
	//for (list <blk_ref>::iterator it = links.begin(); it != links.end(); ++it) {
	//	// if the link is not null, and if the child's first parent is root_block
	//	// (this makes sure we only check every child once, even if it is shared by multiple parents),
	//	// then look for a match in the tree starting from the child.
	//	if ( it->is_null() == false && (*it)->GetParent() == par ) {
	//		ReassignTreeCrossRefs( name_map, *it );
	//	};
	//};
	
}

//This function will merge two scene graphs by attatching new objects to the correct position
//on the existing scene graph.  In other words, it deals only with adding new nodes, not altering
//existing nodes by changing their data or attatched properties
void MergeSceneGraph( map<string,blk_ref> & name_map, const blk_ref & root, blk_ref par ) {
	////Check if this block is a scene graph node
	//if ( par->QueryInterface( ID_NODE ) == false ) {
	//	throw runtime_error( "Only trees that have a node as the root can be merged." );
	//}
	//
	////Check if this block's name exists in the block map
	//string name = par->GetAttr("Name")->asString();

	//if ( name_map.find(name) != name_map.end() ) {
	//	//This block already exists in the original file, so continue on to its children

	//	list<blk_ref> links = par->GetAttr("Children")->asLinkList();;
	//	for (list <blk_ref>::iterator it = links.begin(); it != links.end(); ++it) {
	//		if ( it->is_null() == false ) {
	//			MergeSceneGraph( name_map, root, *it );
	//		};
	//	};
	//	return;
	//}

	////This block has a new name and either it has no parent or its parent has a name that is
	//// in the list.  Attatch it to the block with the same name as its parent
	////all child blocks will follow along.
	//blk_ref par_par = par->GetParent();

	//if ( par_par.is_null() == true ) {
	//	//This block has a new name and no parents.  That means it is the root block
	//	//of a disimilar Nif file.
	//	attr_ref par_children = par->GetAttr("Children");
	//	
	//	//Get the current root child list
	//	attr_ref root_children = root->GetAttr("Children");
	//		
	//	if ( par_children.is_null() == true ) {
	//		//This is not a ParentNode class, so simply add it as a new child of the
	//		//target root node
	//		root_children->AddLink( par );
	//		cout << "Added link to " << par << " in " << root << " block.";
	//	} else {
	//		//This is a ParentNode class, so merge its child list with that of the root
	//		root_children->AddLinks( par_children->asLinkList() );
	//	}
	//} else {
	//	//This block has a new name and has a parent with a name that already exists.
	//	//Attatch it to the block in the target tree that matches the name of its
	//	//parent

	//	//Remove this block from its old parent
	//	par_par->GetAttr("Children")->RemoveLinks( par );

	//	//Get the block to attatch to
	//	blk_ref attatch = name_map[par_par->GetAttr("Name")->asString()];

	//	//Add this block as new child
	//	attatch->GetAttr("Children")->AddLink( par );
	//	//cout << "Added link to " << par << " in " << attatch << " block.";
	//}
}

void MergeNifTrees( blk_ref target, blk_ref right, unsigned int version ) {
	////For now assume that both are normal Nif trees just to verify that it works

	////Make a clone of the tree to add
	//stringstream tmp;
	////WriteNifTree( tmp, right, version );
	//tmp.seekg( 0, ios_base::beg );
	//blk_ref new_tree = right;// ReadNifTree( tmp ); TODO: Figure out why this doesn't work

	////Create a list of names in the target
	//map<string,blk_ref> name_map;
	//MapParentNodeNames( name_map, target );

	////Reassign any cross references in the new tree to point to blocks in the
	////target tree with the same names
	//ReassignTreeCrossRefs( name_map, new_tree );

	////Use the name map to merge the Scene Graphs
	//MergeSceneGraph( name_map, target, new_tree );
}