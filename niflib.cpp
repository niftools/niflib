/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

//#define DEBUG // this will produce lots of output
//#define PRINT_OBJECT_NAMES
//#define PRINT_OBJECT_CONTENTS
//#define DEBUG_LINK_PHASE
//#define DEBUG_HEADER_FOOTER

#include "niflib.h"
#include "NIF_IO.h"
#include "kfm.h"
#include "obj/NiObject.h"
#include "obj/NiNode.h"
#include "obj/NiAVObject.h"
#include "obj/NiTextKeyExtraData.h"
#include "obj/NiSequenceStreamHelper.h"
#include "obj/NiControllerSequence.h"
#include "obj/NiStringPalette.h"
#include "obj/NiSkinPartition.h"
#include "obj/NiTimeController.h"
#include "obj/NiSingleInterpolatorController.h"
#include "obj/NiInterpolator.h"
#include "obj/NiKeyframeController.h"
#include "obj/NiKeyframeData.h"
#include "obj/NiStringExtraData.h"
#include "obj/NiExtraData.h"
#include "obj/bhkRigidBody.h"
#include "gen/header.h"
#include "gen/footer.h"

namespace Niflib {

//Stores the mapping between block names and factory function pointers to create them
typedef NiObject * (*blk_factory_func)();
bool global_block_map_init = false;
map<string, blk_factory_func> global_block_map;

//Utility Functions
void EnumerateObjects( NiObjectRef const & root, map<Type*,uint> & type_map, map<NiObjectRef, uint> & link_map );
NiObjectRef FindRoot( vector<NiObjectRef> const & blocks );
void RegisterBlockFactories ();
NiObjectRef GetObjectByType( const NiObjectRef & root, const Type & block_type );


//--Function Bodies--//
NiObjectRef CreateObject( string block_type ) {
	
	//Initialize the global block list if it hasn't been done yet
	if ( global_block_map_init == false ) {
		RegisterBlockFactories();
		global_block_map_init = true;
	}

	NiObject * block = NULL;

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
	
	return NiObjectRef(block);
}

//Reads the given file by file name and returns a reference to the root block
NiObjectRef ReadNifTree( string const & file_name ) {
	//Read block list
	//cout << "File name:  " << file_name << endl;
	vector<NiObjectRef> blocks = ReadNifList( file_name );
	return FindRoot( blocks );
}

//Reads the given input stream and returns a reference to the root block
NiObjectRef ReadNifTree( istream & in ) {
	//Read block list
	vector<NiObjectRef> blocks = ReadNifList( in );
	return FindRoot( blocks );
}

NiObjectRef FindRoot( vector<NiObjectRef> const & blocks ) {
	//--Look for a NiNode that has no parents--//

	//Find the first NiObjectNET derived object
	NiAVObjectRef root;
	for (uint i = 0; i < blocks.size(); ++i) {
		root = DynamicCast<NiAVObject>(blocks[i]);
		if ( root != NULL ) {
			break;
		}
	}

	//Make sure a node was found, if not return first node
	if ( root == NULL )
		return blocks[0];

	//Move up the chain to the root node
	while ( root->GetParent() != NULL ) {
		root = StaticCast<NiAVObject>(root->GetParent());
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
vector<NiObjectRef> ReadNifList( string const & file_name ) {

	//--Open File--//
	ifstream in( file_name.c_str(), ifstream::binary );

	return ReadNifList( in );
}

//Reads the given input stream and returns a vector of block references
vector<NiObjectRef> ReadNifList( istream & in ) {

	//--Read Header--//
	Header header;

	//Read header.
	header.Read( in );

#ifdef DEBUG_HEADER_FOOTER
	//Print debug output for header
	cout << header.asString();
#endif

#ifdef PRINT_OBJECT_NAMES
	cout << endl << "Reading Objects:";
#endif

	//--Read Objects--//
	size_t numBlocks = header.numBlocks;
	vector<NiObjectRef> blocks( numBlocks ); //List to hold the blocks
	list<uint> link_stack; //List to add link values to as they're read in from the file
	string objectType;
	stringstream errStream;
	for (uint i = 0; i < numBlocks; i++) {

		//Check for EOF
		//if (in.eof() ) {
		//	throw runtime_error("End of file reached prematurely.  This NIF may be corrupt or improperly supported.");
		//}
	
		//There are two ways to read blocks, one before version 5.0.0.1 and one after that
		if ( header.version >= 0x05000001 ) {
			//From version 5.0.0.1 to version 10.0.1.0  there is a zero byte at the begining of each block
			
			if ( header.version <= VER_10_1_0_0 ) {
				uint checkValue = ReadUInt( in );
				if ( checkValue != 0 ) {
					//Throw an exception if it's not zero
					errStream << "Read failue - Bad object position.  Invalid check value" << endl;
					errStream << "====[ " << "Object " << i << " | " << blocks[i - 1]->GetType().GetTypeName() << " ]====" << endl;
					errStream << blocks[i - 1]->asString();
					throw runtime_error( errStream.str() );
				}
			}

			// Find which block type this is by using the header arrays
			objectType = header.blockTypes[ header.blockTypeIndex[i] ];
		} else {
			// Find which block type this is by reading the string at this location
			uint objectTypeLength = ReadUInt( in );
			if (objectTypeLength > 30 || objectTypeLength < 6) {
				errStream << "Read failue - Bad object position.  Invalid Type Name Length:  " << objectTypeLength  << endl;
				errStream << "====[ " << "Object " << i - 1 << " | " << blocks[i - 1]->GetType().GetTypeName() << " ]====" << endl;
				errStream << blocks[i - 1]->asString();
				throw runtime_error( errStream.str() );
			}
			char* charobjectType = new char[objectTypeLength + 1];
			in.read( charobjectType, objectTypeLength );
			charobjectType[objectTypeLength] = 0;
			objectType = string(charobjectType);
			delete [] charobjectType;
			if ( (objectType[0] != 'N' || objectType[1] != 'i') && (objectType[0] != 'R' || objectType[1] != 'o') && (objectType[0] != 'A' || objectType[1] != 'v')) {
				errStream << "Read failue - Bad object position.  Invalid Type Name:  " << objectType << endl;
				errStream << "====[ " << "Object " << i - 1 << " | " << blocks[i - 1]->GetType().GetTypeName() << " ]====" << endl;
				errStream << blocks[i - 1]->asString();
				throw runtime_error( errStream.str() );
			}
		}

#ifdef PRINT_OBJECT_NAMES
		cout << endl << i << ":  " << objectType;
#endif

		//Create Block of the type that was found
		blocks[i] = CreateObject(objectType);

		//Check for an unknown block type
		if ( blocks[i] == NULL ) {
			//For version 5.0.0.1 and up, throw an exception - there's nothing we can do
			//if ( version >= 0x05000001 ) {
				errStream << "Unknown object type encountered during file read:  " << objectType;
				throw runtime_error( errStream.str() );
			//} else {
				//We can skip over this block in older versions
				//blocks[i] = new UnknownBlock(objectType);
			//}
		}

		//blocks[i]->SetBlockNum(i);
		blocks[i]->Read( in, link_stack, header.version, header.userVersion );
#ifdef PRINT_OBJECT_CONTENTS
		cout << endl << blocks[i]->asString() << endl;
#endif
	}

	//cout << endl;

	//--Read Footer--//
	Footer footer;
	footer.Read( in, link_stack, header.version, header.userVersion );

#ifdef DEBUG_HEADER_FOOTER
	//Print footer debug output
	footer.asString();
#endif
	
	//This should fail, and trigger the in.eof() flag
	ReadByte( in ); 
	if ( ! in.eof() ) {
		throw runtime_error("End of file not reached.  This NIF may be corrupt or improperly supported.");
	}

#ifdef DEBUG_LINK_PHASE
	cout << "Link Stack:" << endl;
	list<uint>::iterator it;
	for ( it = link_stack.begin(); it != link_stack.end(); ++it ) {
		cout << *it << endl;
	}
#endif
	
#ifdef DEBUG_LINK_PHASE
	cout << "Fixing Links:"  << endl;
#endif
	//--Now that all blocks are read, go back and fix the links--//
	for (uint i = 0; i < blocks.size(); ++i) {
#ifdef DEBUG_LINK_PHASE
		cout << i << ":  " << blocks[i] << endl;
#endif
		//Fix links & other pre-processing
		blocks[i]->FixLinks( blocks, link_stack, header.version, header.userVersion );
	}

	//Return completed block list
	return blocks;
}

// Writes a valid Nif File given a file name, a pointer to the root block of a file tree
void WriteNifTree( string const & file_name, NiObjectRef const & root_block, unsigned int version, unsigned int user_version ) {
	//Open output file
	ofstream out( file_name.c_str(), ofstream::binary );

	WriteNifTree( out, root_block, version, user_version );

	//Close file
	out.close();
}

// Writes a valid Nif File given an ostream, a pointer to the root block of a file tree
void WriteNifTree( ostream & out, NiObjectRef const & root, unsigned int version, unsigned int user_version ) {
	// Walk tree, resetting all block numbers
	//int block_count = ResetBlockNums( 0, root_block );
	
	//Enumerate all objects in tree
	map<Type*,uint> type_map;
	map<NiObjectRef, uint> link_map;

	EnumerateObjects( root, type_map, link_map );

	//Build vectors for reverse look-up
	vector<NiObjectRef> objects(link_map.size());
	for ( map<NiObjectRef, uint>::iterator it = link_map.begin(); it != link_map.end(); ++it ) {
		objects[it->second] = it->first;
	}

	vector<const Type*> types(type_map.size());
	for ( map<Type*, uint>::iterator it = type_map.begin(); it != type_map.end(); ++it ) {
		types[it->second] = it->first;
	}

	//--Write Header--//
	Header header;
	header.version = version;
	header.userVersion = user_version;
   header.userVersion2 = user_version;
	
	//Set Type Names
	header.blockTypes.resize( types.size() );
	for ( uint i = 0; i < types.size(); ++i ) {
		header.blockTypes[i] = types[i]->GetTypeName();

	}

	//Set type number of each block
	header.blockTypeIndex.resize( objects.size() );
	for ( uint i = 0; i < objects.size(); ++i ) {
		header.blockTypeIndex[i] = type_map[(Type*)&(objects[i]->GetType())];
	}

	//Write header to file
	header.Write( out );

#ifdef PRINT_OBJECT_NAMES
	cout << endl << "Writing Objects:";
#endif

	//--Write Objects--//
	for (uint i = 0; i < objects.size(); ++i) {

#ifdef PRINT_OBJECT_NAMES
		cout << endl << i << ":  " << objects[i]->GetType().GetTypeName();
#endif

		if (version < 0x05000001) {
			//cout << i << ":  " << objects[i]->GetType().GetTypeName() << endl;
			//Write Block Type
			WriteString( objects[i]->GetType().GetTypeName() , out );
		} else if (version >= 0x05000001 && version <= VER_10_1_0_0 ) {
			WriteUInt( 0, out );
		}

		objects[i]->Write( out, link_map, version, user_version );
	}

	//--Write Footer--//
	Footer footer;
	footer.numRoots = 1;
	footer.roots.resize(1);
	footer.roots[0] = DynamicCast<NiAVObject>(root);

	footer.Write( out, link_map, version, user_version );
}

void EnumerateObjects( NiObjectRef const & root, map<Type*,uint> & type_map, map<NiObjectRef, uint> & link_map ) {
	//Ensure that this object has not already been visited
	if ( link_map.find( root ) != link_map.end() ) {
		//This object has already been visited.  Return.
		return;
	}

	//Add this object type to the map if it isn't there already
	if ( type_map.find( (Type*)&(root->GetType()) ) == type_map.end() ) {
		//The type has not yet been registered, so register it
		//cout << "Types[" << uint(type_map.size()) << "] = " << root->GetType().GetTypeName() << endl;
		type_map[ (Type*)&(root->GetType()) ] = uint(type_map.size());
	}

   // Oblivion has very rigid requirements about block ordering and the bhkRigidBody 
   //   must be after its children. Hopefully this can be removed and replaced with 
   //   a more generic mechanism in the future.
	Type *t = (Type*)&(root->GetType());
   if (t->IsDerivedType(bhkRigidBody::TypeConst()))
   {
      //Call this function on all links of this object
      list<NiObjectRef> links = root->GetRefs();
      for ( list<NiObjectRef>::iterator it = links.begin(); it != links.end(); ++it ) {
         if ( *it != NULL ) {
            EnumerateObjects( *it, type_map, link_map );
         }
      }
      //Add object to link map
      link_map[root] = uint(link_map.size());
   } 
   else
   {
      //Add object to link map
      link_map[root] = uint(link_map.size());

      //Call this function on all links of this object	
      list<NiObjectRef> links = root->GetRefs();
      for ( list<NiObjectRef>::iterator it = links.begin(); it != links.end(); ++it ) {
         if ( *it != NULL ) {
            EnumerateObjects( *it, type_map, link_map );
         }
      }
   }
}

//void BuildUpBindPositions( const NiAVObjectRef & root ) {
//
//	//Get parent if there is one
//	NiNodeRef par = root->GetParent();
//	if ( par != NULL ) {
//		//There is a node parent
//
//		//Post-multipy the block's bind matrix with the parent's bind matrix
//		Matrix44 result = root->GetWorldBindPos() * par->GetWorldBindPos();
//
//		//Store result back to block bind position
//		root->SetWorldBindPos( result );
//	}
//
//	//If this is a NiNode, call this function for all child AVObjects
//	NiNodeRef node = DynamicCast<NiNode>(root);
//	if ( node != NULL ) {
//		vector<NiAVObjectRef> children = node->GetChildren();
//		for (vector<NiAVObjectRef>::iterator it = children.begin(); it != children.end(); ++it) {
//			if ( *it != NULL ) {
//				BuildUpBindPositions( *it );
//			}
//		}
//	}
//}

//TODO: Should this be returning an object of a derived type too?
// Searches for the first object in the hierarchy of type.
NiObjectRef GetObjectByType( const NiObjectRef & root, const Type & type ) {
	if ( root->IsSameType( type ) ) {
		return root;
	}

	list<NiObjectRef> links = root->GetRefs();
	for (list <NiObjectRef>::iterator it = links.begin(); it != links.end(); ++it) {
		// Can no longer guarantee that some objects won't be visited twice.  Oh well.
		NiObjectRef result = GetObjectByType( *it, type );
		if ( result != NULL ) {
			return result;
		}
	};

	return NULL; // return null reference
};

//TODO: Should this be returning all objects of a derived type too?
// Returns all in the in the tree of type.
list<NiObjectRef> GetAllObjectsByType( NiObjectRef const & root, const Type & type ) {
	list<NiObjectRef> result;
	if ( root->IsSameType(type) ) {
		result.push_back( root );
	}
	list<NiObjectRef> links = root->GetRefs();
	for (list<NiObjectRef>::iterator it = links.begin(); it != links.end(); ++it ) {
		// Can no longer guarantee that some objects won't be visited twice.  Oh well.
		list<NiObjectRef> childresult = GetAllObjectsByType( *it, type );
		result.merge( childresult );
	};
	return result;
};

//TODO:  Is this function used anywhere?  Does it need to be re-done?
//list<NiObjectRef> GetNifTree( NiObjectRef const & root_block ) {
//	list<NiObjectRef> result;
//	result.push_back( root_block );
//	list<NiObjectRef> links = root_block->GetRefs();
//	for (list<NiObjectRef>::iterator it = links.begin(); it != links.end(); ++it ) {
//		if ( it->is_null() == false && (*it)->GetParent() == root_block ) {
//			list<NiObjectRef> childresult = GetNifTree( *it );
//			result.merge( childresult );
//		};
//	};
//	return result;
//};

//TODO:  This was written by Amorilia.  Figure out how to fix it.
/*!
 * Helper function to split off animation from a nif tree. If no animation groups are defined, then both xnif_root and xkf_root will be null blocks.
 * \param root_block The root block of the full tree.
 * \param xnif_root The root block of the tree without animation.
 * \param xkf_root The root block of the animation tree.
 * \param kfm The KFM structure (if required by style).
 * \param kf_type What type of keyframe tree to write (Morrowind style, DAoC style, ...).
 */
void SplitNifTree( NiObjectRef const & root_block, NiObjectRef & xnif_root, NiObjectRef & xkf_root, Kfm & kfm, int kf_type ) {
	// Do we have animation groups (a NiTextKeyExtraData block)?
	// If so, create XNif and XKf trees.
	NiObjectRef txtkey = GetObjectByType( root_block, NiTextKeyExtraData::TypeConst() );
	NiTextKeyExtraDataRef txtkey_block;
	if ( txtkey != NULL ) {
		txtkey_block = DynamicCast<NiTextKeyExtraData>(txtkey);
	}
	if ( txtkey_block != NULL ) {
		if ( kf_type == KF_MW ) {
			// Construct the XNif file...
			// We are lazy. (TODO: clone & remove keyframe controllers & keyframe data)
			xnif_root = root_block;
			
			// Now the XKf file...
			// Create xkf root header.
			NiSequenceStreamHelperRef xkf_stream_helper = new NiSequenceStreamHelper;
			xkf_root = xkf_stream_helper;
			
			// Add a copy of the NiTextKeyExtraData block to the XKf header.
			NiTextKeyExtraDataRef xkf_txtkey_block = new NiTextKeyExtraData;

			//TODO: Have Amorilia fix this
			xkf_stream_helper->AddExtraData( StaticCast<NiExtraData>(xkf_txtkey_block) );
			
			//ITextKeyExtraData const *itxtkey_block = QueryTextKeyExtraData(txtkey_block);
			//ITextKeyExtraData *ixkf_txtkey_block = QueryTextKeyExtraData(xkf_txtkey_block);
			
			xkf_txtkey_block->SetKeys( txtkey_block->GetKeys() );
			
			// Append NiNodes with a NiKeyFrameController as NiStringExtraData blocks.
			list< pair< NiNodeRef, NiKeyframeControllerRef> > node_controllers;

			list<NiObjectRef> nodes = GetAllObjectsByType( root_block, NiNode::TypeConst() );
			for ( list<NiObjectRef>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
				NiNodeRef node = DynamicCast<NiNode>(*it);
				if ( node == NULL ) {
					continue;
				}

				//Find the first NiKeyframeController in the controller list, if any
				list<NiTimeControllerRef> controllers = node->GetControllers();
				NiKeyframeControllerRef key_controller;
				for ( list<NiTimeControllerRef>::iterator controller = controllers.begin(); controller != controllers.end(); ++controller ) {
					key_controller = DynamicCast<NiKeyframeController>(*it);
					if ( key_controller != NULL ) {
						break;
					}
				}

				//If this node has no keyframe controller, put it in the list
				if ( key_controller != NULL ) {
					node_controllers.push_back( pair<NiNodeRef,NiKeyframeControllerRef>( node, key_controller ) );
				}
			};
			
			
			for ( list< pair< NiNodeRef, NiKeyframeControllerRef> >::iterator it = node_controllers.begin(); it != node_controllers.end(); ++it ) {
				//Add string data				
				NiStringExtraDataRef nodextra = new NiStringExtraData;
				nodextra->SetData( it->first->GetName() );
				xkf_stream_helper->AddExtraData( StaticCast<NiExtraData>(nodextra) );

				// Add controllers & controller data.
				NiKeyframeControllerRef controller = it->second;
				NiKeyframeControllerRef xkf_controller =  new NiKeyframeController;

				xkf_controller->SetFlags( controller->GetFlags() );
				xkf_controller->SetFrequency( controller->GetFrequency() );
				xkf_controller->SetPhase( controller->GetPhase() );
				xkf_controller->SetStartTime( controller->GetStartTime() );
				xkf_controller->SetStopTime( controller->GetStopTime() );
				
				NiKeyframeDataRef xkf_data = new NiKeyframeData;
				NiKeyframeDataRef kfdata = controller->GetData();
				xkf_controller->SetData( xkf_data );

				xkf_data->SetRotateType( kfdata->GetRotateType() );
				xkf_data->SetTranslateType( kfdata->GetTranslateType() );
				xkf_data->SetScaleType( kfdata->GetScaleType() );
				xkf_data->SetQuatRotateKeys( kfdata->GetQuatRotateKeys() );
				xkf_data->SetXRotateKeys( kfdata->GetXRotateKeys() );
				xkf_data->SetYRotateKeys( kfdata->GetYRotateKeys() );
				xkf_data->SetZRotateKeys( kfdata->GetZRotateKeys() );
				xkf_data->SetTranslateKeys( kfdata->GetTranslateKeys() );
				xkf_data->SetScaleKeys( kfdata->GetScaleKeys() );
	
				xkf_stream_helper->AddController( StaticCast<NiTimeController>(controller) );
			};
		} else // TODO other games
			throw runtime_error("KF splitting for the requested game is not yet implemented.");
	} else {
		// no animation groups: nothing to do
		xnif_root = NULL;
		xkf_root = NULL;
	};
}

//TODO:  This was written by Amorilia.  Figure out how to fix it.
///*!
// * Helper function to split an animation tree into multiple animation trees (one per animation group) and a kfm block.
// * \param root_block The root block of the full tree.
// * \param kf Vector of root blocks of the new animation trees.
// */
//void SplitKfTree( NiObjectRef const & root_block, vector<NiObjectRef> & kf ) {
//	throw runtime_error("Not yet implemented.");
//};

//TODO:  This was written by Amorilia.  Figure out how to fix it.
void WriteFileGroup( string const & file_name, NiObjectRef const & root_block, unsigned int version, ExportOptions export_files, NifGame kf_type ) {
	// Get base filename.
	uint file_name_slash = uint(file_name.rfind("\\") + 1);
	string file_name_path = file_name.substr(0, file_name_slash);
	string file_name_base = file_name.substr(file_name_slash, file_name.length());
	uint file_name_dot = uint(file_name_base.rfind("."));
	file_name_base = file_name_base.substr(0, file_name_dot);
	
	// Deal with the simple case first
	if ( export_files == EXPORT_NIF )
		WriteNifTree( file_name_path + file_name_base + ".nif", root_block, version ); // simply export the NIF file!
	// Now consider all other cases
	else if ( kf_type == KF_MW ) {
		if ( export_files == EXPORT_NIF_KF ) {
			// for Morrowind we must also write the full NIF file
			WriteNifTree( file_name_path + file_name_base + ".nif", root_block, version ); // simply export the NIF file!
			NiObjectRef xnif_root;
			NiObjectRef xkf_root;
			Kfm kfm; // dummy
			SplitNifTree( root_block, xnif_root, xkf_root, kfm, KF_MW );
			if ( xnif_root != NULL ) {
				WriteNifTree( file_name_path + "x" + file_name_base + ".nif", xnif_root, version );
				WriteNifTree( file_name_path + "x" + file_name_base + ".kf", xkf_root, version );
			};
		} else
			throw runtime_error("Invalid export option.");
	} else
		throw runtime_error("Not yet implemented.");
};

void MapNodeNames( map<string,NiNodeRef> & name_map, const Ref<NiNode> & par ) {
	//Add the par node to the map, and then call this function for each of its children
	name_map[par->GetName()] = par;

	
	vector<NiAVObjectRef> links = par->GetChildren();
	for (vector<NiAVObjectRef>::iterator it = links.begin(); it != links.end(); ++it) {
		NiNodeRef child_node = DynamicCast<NiNode>(*it);
		if ( child_node != NULL ) {
			MapNodeNames( name_map, child_node );
		};
	};
}

void ReassignTreeCrossRefs( map<string,NiNodeRef> & name_map, NiAVObjectRef par ) {
	//TODO: Decide how cross refs are going to work
	////Reassign any cross references on this block
	//((ABlock*)par.get_block())->ReassignCrossRefs( name_map );

	//list<NiObjectRef> links = par->GetRefs();
	//for (list <NiObjectRef>::iterator it = links.begin(); it != links.end(); ++it) {
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
void MergeSceneGraph( map<string,NiNodeRef> & name_map, const NiNodeRef & root, NiAVObjectRef par ) {
	//Check if this block's name exists in the block map
	string name = par->GetName();

	if ( name_map.find(name) != name_map.end() ) {
		//This block already exists in the original file, so continue on to its children, if it is a NiNode
		
		NiNodeRef par_node = DynamicCast<NiNode>(par);
		if ( par_node != NULL ) {
			vector<NiAVObjectRef> children = par_node->GetChildren();
			for ( vector<NiAVObjectRef>::iterator it = children.begin(); it != children.end(); ++it ) {
				if ( (*it) != NULL ) {
					MergeSceneGraph( name_map, root, *it );
				};
			};
		}
		return;
	}

	//This block has a new name and either it has no parent or its parent has a name that is
	// in the list.  Attatch it to the block with the same name as its parent
	//all child blocks will follow along.
	NiNodeRef par_par = par->GetParent();

	if ( par_par == NULL) {
		//This block has a new name and no parents.  That means it is the root block
		//of a disimilar Nif file.
			
		//Check whether we have a NiNode ( a node that might have children) or not.
		NiNodeRef par_node = DynamicCast<NiNode>(par);
		if ( par_node == NULL ) {
			//This is not a NiNode class, so simply add it as a new child of the
			//target root node
			root->AddChild( par );

			//cout << "Added link to " << par << " in " << root << " block.";
		} else {
			//This is a NiNode class, so merge its child list with that of the root
			vector<NiAVObjectRef> children = par_node->GetChildren();
			for ( uint i = 0; i < children.size(); ++i ) {
				root->AddChild( children[i] );
			}
		}
	} else {
		//This block has a new name and has a parent with a name that already exists.
		//Attatch it to the block in the target tree that matches the name of its
		//parent

		//TODO:  Implement children
		////Remove this block from its old parent
		//par_par->GetAttr("Children")->RemoveLinks( par );

		//Get the block to attatch to
		NiObjectRef attatch = DynamicCast<NiObject>(name_map[par_par->GetName()]);

		//TODO:  Implement children
		////Add this block as new child
		//attatch->GetAttr("Children")->AddLink( par );
		////cout << "Added link to " << par << " in " << attatch << " block.";
	}
}

void MergeNifTrees( NiNodeRef target, NiAVObjectRef right, unsigned int version ) {
	//For now assume that both are normal Nif trees just to verify that it works

	//Make a clone of the tree to add
	stringstream tmp;
	//WriteNifTree( tmp, right, version );
	tmp.seekg( 0, ios_base::beg );
	NiAVObjectRef new_tree = right;// ReadNifTree( tmp ); TODO: Figure out why this doesn't work

	//Create a list of names in the target
	map<string,NiNodeRef> name_map;
	MapNodeNames( name_map, target );

	//Reassign any cross references in the new tree to point to blocks in the
	//target tree with the same names
	ReassignTreeCrossRefs( name_map, new_tree );

	//Use the name map to merge the Scene Graphs
	MergeSceneGraph( name_map, target, new_tree );
}

//Version for merging KF Trees rooted by a NiControllerSequence
void MergeNifTrees( const Ref<NiNode> & target, const Ref<NiControllerSequence> & right, unsigned int version, unsigned int user_version ) {
	//Map the node names
	map<string,NiNodeRef> name_map;
	MapNodeNames( name_map, target );

	//TODO:  Allow this to merge a KF sequence into a file that already has
	//sequences in it by appending all the keyframe data to the end of
	//existing controllers

	//Get the NiTextKeyExtraData, clone it, and attach it to the target node
	NiTextKeyExtraDataRef txt_key = right->GetTextKeyExtraData();
	if ( txt_key != NULL ) {
		NiObjectRef tx_clone = txt_key->Clone( version, user_version );
		NiExtraDataRef ext_dat = DynamicCast<NiExtraData>(tx_clone);
		if ( ext_dat != NULL ) {
			target->AddExtraData( ext_dat );
		}
	}

	//Atach it to

	//Get the controller data
	vector<ControllerLink> data = right->GetControllerData();

	//Connect a clone of all the interpolators/controllers to the named node
	for ( uint i = 0; i < data.size(); ++i ) {
		//Get strings
		//TODO: Find out if other strings are needed
		string node_name, ctlr_type;
		NiStringPaletteRef str_pal = data[i].stringPalette;
		if ( str_pal == NULL ) {
			node_name = data[i].nodeName;
			ctlr_type = data[i].controllerType;
		} else {
			node_name = str_pal->GetSubStr( data[i].nodeNameOffset );
			ctlr_type = str_pal->GetSubStr( data[i].controllerTypeOffset );
		}
		//Make sure there is a node with this name in the target tree
		if ( name_map.find( node_name ) != name_map.end() ) {
			//See if we're dealing with an interpolator or a controller
			if ( data[i].controller != NULL ) {
				//Clone the controller and attached data and
				//add it to the named node
				NiObjectRef clone = CloneNifTree( StaticCast<NiObject>(data[i].controller), version, user_version );
				NiTimeControllerRef ctlr = DynamicCast<NiTimeController>(clone);
				if ( ctlr != NULL ) {
					name_map[node_name]->AddController( ctlr );
				}
			} else if ( data[i].interpolator != NULL ) {
				//Clone the interpolator and attached data and
				//attach it to the specific type of controller that's
				//connected to the named node
				NiNodeRef node = name_map[node_name];
				//cout << "Attaching interpolator to " << node << endl;
				list<NiTimeControllerRef> ctlrs = node->GetControllers();
				NiSingleInterpolatorControllerRef ctlr;
				for ( list<NiTimeControllerRef>::iterator it = ctlrs.begin(); it != ctlrs.end(); ++it ) {
					if ( *it != NULL && (*it)->GetType().GetTypeName() == ctlr_type ) {
						ctlr = DynamicCast<NiSingleInterpolatorController>(*it);
						if ( ctlr != NULL ) {
							break;
						}
					}
				}

				//If the controller wasn't found, create one of the right type and attach it
				if ( ctlr == NULL ) {
					NiObjectRef new_ctlr = CreateObject( ctlr_type );
					ctlr = DynamicCast<NiSingleInterpolatorController>( new_ctlr );
					if ( ctlr == NULL ) {
						throw runtime_error ("Non-NiSingleInterpolatorController controller found in KF file.");
					}
					node->AddController( StaticCast<NiTimeController>(ctlr) );
				}

				//cout << "Controller is " << ctlr << endl;

				//Clone the interpolator and attached data and
				//add it to controller of matching type that was
				//found
				NiObjectRef clone = CloneNifTree( StaticCast<NiObject>(data[i].interpolator), version, user_version );
				NiInterpolatorRef interp = DynamicCast<NiInterpolator>(clone);
				if ( interp != NULL ) {
					ctlr->SetInterpolator( interp );

					//Set the start/stop time and frequency of this controller
					ctlr->SetStartTime( right->GetStartTime() );
					ctlr->SetStopTime( right->GetStopTime() );
					ctlr->SetFrequency( right->GetFrequency() );
					ctlr->SetPhase( 0.0f ); //TODO:  Is phase somewhere in NiControllerSequence?

					//Set cycle type as well
					switch ( right->GetCycleType() ) {
						case NiControllerSequence::CYCLE_LOOP:
							ctlr->SetFlags( 8 ); //Active
							break;
						case NiControllerSequence::CYCLE_CLAMP:
							ctlr->SetFlags( 12 ); //Active+Clamp
							break;
						case NiControllerSequence::CYCLE_REVERSE:
							ctlr->SetFlags( 10 ); //Active+Reverse
							break;
					}
				}
			}
		}
	}
}

//Version for merging KF Trees rooted by a NiSequenceStreamHelper
void MergeNifTrees( const Ref<NiNode> & target, const Ref<NiSequenceStreamHelper> & right, unsigned int version, unsigned int user_version ) {
	//Map the node names
	map<string,NiNodeRef> name_map;
	MapNodeNames( name_map, target );

	//TODO: Implement this

}


bool IsVersionSupported(unsigned int ver) {
   switch (ver)
   {
   case VER_4_0_0_2:
   case VER_4_1_0_12:
   case VER_4_2_0_2:
   case VER_4_2_1_0:
   case VER_4_2_2_0:
   case VER_10_0_1_0:
   case VER_10_1_0_0:
   case VER_10_2_0_0:
   case VER_20_0_0_4:
   case VER_20_0_0_5:
      return true;
   }
   return false;
}

unsigned int GetVersion(string version){
   unsigned int outver = 0;
   string::size_type start = 0;
   for(int offset = 3; offset >= 0 && start < version.length(); --offset) {
      string::size_type end = version.find_first_of(".", start);
      string::size_type len = (end == string.npos) ? end : end-start;
      int num = 0;
      stringstream sstr(version.substr(start, len));
      sstr >> num;
      if (num > 0xFF) {
         outver = VER_INVALID;
         break;
      }
      outver |= (num << (offset * 8));
      if (len == string::npos) 
         break;
      start = start + len + 1;
   }
   if (outver == 0)
      outver = VER_INVALID;
   return outver;
}

Ref<NiObject> CloneNifTree( Ref<NiObject> const & root, unsigned int version, unsigned int user_version ) {
	//Create a string stream to temporarily hold the state-save of this tree
	stringstream tmp;

	//Write the existing tree into the stringstream
	WriteNifTree( tmp, root, version, user_version );

	//Read the data back out of the stringstream, returning the new tree
	return ReadNifTree( tmp );
}

void SendNifTreeToBindPos( const Ref<NiNode> & root ) {
	//If this node is a skeleton root, send its children to the bind
	//position

	if ( root == NULL ) {
		throw runtime_error( "Attempted to call SendNifTreeToBindPos on a null reference." );
	}

	if ( root->IsSkeletonRoot() ) {
		root->GoToSkeletonBindPosition();
	}

	//Call this function on any NiNode children
	vector<NiAVObjectRef> children = root->GetChildren();
	for ( uint i = 0; i < children.size(); ++i ) {
		NiNodeRef child = DynamicCast<NiNode>(children[i]);
		if ( child != NULL ) {
			SendNifTreeToBindPos( child );
		}
	}
}

} // namespace NifLib