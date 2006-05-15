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

#ifndef _NIFLIB_H_
#define _NIFLIB_H_

//--Includes--//
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <list>
#include <map>
#include "nif_math.h"
#include "NIF_IO.h"
#include "nif_objects.h"
#include "xml_extract.h"
#include "kfm.h"

using namespace std;

#ifndef NULL
#define NULL 0  /*!< Definition used to detect null pointers. */ 
#endif

//--Main Functions--//

/*!
 * Reads the header of the given file by file name and returns the NIF version. Call this
 * function prior to calling ReadNifList or ReadNifTree, if you need to make sure that the NIF file is supported.
 * \param file_name The name of the file to load, or the complete path if it is not in the working directory.
 * \return The NIF version of the file, in hexadecimal format. If the file is not a NIF file, it returns VER_INVALID. If it is a NIF file, but its version is not supported by the library, it returns VER_UNSUPPORTED.
 * 
 * <b>Example:</b> 
 * \code
 * unsigned int ver = CheckNifHeader("test_in.nif");
 * if ( ver == VER_UNSUPPORTED ) cout << "unsupported" << endl;
 * else if ( ver == VER_INVALID ) cout << "invalid" << endl;
 * else {
 *   vector<blk_ref> blocks = ReadNifList( "test_in.nif" );
 *   cout << blocks[0] << endl;
 * };
 *
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * ver = CheckNifHeader("test_in.nif")
 * if ( ver == VER_UNSUPPORTED ):
 *     print "unsupported"
 * elif ( ver == VER_INVALID ):
 *     print "invalid"
 * else:
 *      blocks = ReadNifList( "test_in.nif" )
 *      print blocks[0]
 * \endcode
 */
unsigned int CheckNifHeader( string const & file_name );

/*!
 * Reads the given file by file name and returns a vector of block references
 * \param file_name The name of the file to load, or the complete path if it is not in the working directory.
 * \return A vector of block references that point to all the blocks read from the Nif file.
 * 
 * <b>Example:</b> 
 * \code
 * blk_ref my_block = ReadNifList("test_in.nif");
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * my_block = ReadNifList("test_in.nif")
 * \endcode
 * 
 * \sa ReadNifTree, WriteNifTree
 */
vector<NiObjectRef> ReadNifList( string const & file_name );

/*!
 * Reads the given input stream and returns a vector of block references
 * \param stream The input stream to read NIF data from.
 * \return A vector of block references that point to all the blocks read from the stream.
 */
vector<blk_ref> ReadNifList( istream & in );

/*!
 * Reads the given file by file name and returns a reference to the root block.
 * \param file_name The name of the file to load, or the complete path if it is not in the working directory.
 * \return A block reference that points to the root of tree of data blocks contained in the NIF file.
 * 
 * <b>Example:</b> 
 * \code
 * blk_ref my_block = ReadNifTree("test_in.nif");
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * my_block = ReadNifTree("test_in.nif")
 * \endcode
 * 
 * \sa ReadNifList, WriteNifTree
 */
blk_ref ReadNifTree( string const & file_name );

/*!
 * Reads the given input stream and returns a reference to the root block.
 * \param stream The input stream to read NIF data from.
 * \return A block reference that points to the root of the tree of data blocks contained in the NIF file.
 */
blk_ref ReadNifTree( istream & in );

/*!
 * Creates a new NIF file of the given file name by crawling through the data tree starting with the root block given.
 * \param file_name The desired file name for the new NIF file.  The path is relative to the working directory unless a full path is specified.
 * \param root The root block to start from when writing out the NIF file.  All decedents of this block will be written to the file in tree-descending order.
 * \param version The version of the NIF format to use when writing a file.  Default is version 4.0.0.2.
 * 
 * <b>Example:</b> 
 * \code
 * blk_ref my_block = ReadNifTree("test_in.nif");
 * WriteNifTree( "test_out.nif", my_block );
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * my_block = ReadNifTree("test_in.nif")
 * WriteNifTree( "test_out.nif", my_block )
 * \endcode
 * 
 * \sa ReadNifList, WriteNifTree
 */
void WriteNifTree( string const & file_name, NiObjectRef const & root, unsigned int version = VER_4_0_0_2 );

/*!
 * Writes a nif tree to an ostream starting at the given root block.
 * \param stream The output stream to write the NIF data to.
 * \param root The root block to start from when writing out the NIF data.  All decedents of this block will be written to the stream in tree-descending order.
 * \param version The version of the NIF format to use when writing a file.  Default is version 4.0.0.2.
 */
void WriteNifTree( ostream & stream, NiObjectRef const & root, unsigned int version );

/*!
 * Writes a bunch of files given a base file name, and a pointer to the root block of the Nif file tree.
 * \param file_name The desired file name for the base NIF file. This name serves as the basis for the names of any Kf files and Kfm files as well.  The path is relative to the working directory unless a full path is specified.
 * \param root The root block to start from when writing out the NIF file.
 * \param version The version of the NIF format to use when writing a file.
 * \param export_files What files to write: NIF, NIF + KF + KFM, NIF + KF's + KFM, KF only, KF's only
 * \param kf_type The KF type (Morrowind style, DAoC style, CivIV style, ...)
 */
void WriteFileGroup( string const & file_name, blk_ref const & root, unsigned int version, unsigned int export_files, unsigned int kf_type );

/*!
 * Merges two Nif trees into one.  For standard Nif files, any blocks with the same name are merged.  For Kf files, blocks are attatched to those that match the name specified in the KF root block.  The data stored in a NIF file varies from version to version.  Usually you are safe with the default option (the highest availiable version) but you may need to use an earlier version if you need to clone an obsolete piece of information.
 * \param target The root block of the first Nif tree to merge.
 * \param right The root block of the second Nif tree to merge.
 * \param version The version of the nif format to use during the clone operation on the right-hand tree.  The default is the highest version availiable.
 */
void MergeNifTrees( blk_ref target, blk_ref right, unsigned int version = 0xFFFFFFFF );


//// Returns list of all blocks in the tree rooted by root block.
//list<blk_ref> GetNifTree( blk_ref const & root_block );

////Returns the NIF spec version of a file, given a file name.
//string GetFileVersion(string file_name);


/*!
 * Sets whether data/hex areas are shown by asString functions
 * \param val A boolean value that specifies whether verbose mode should be turned on.  True = Verbose, False = Brief.
 * 
 * <b>Example:</b> 
 * \code
 * SetVerboseMode(true);
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * SetVerboseMode(True)
 * \endcode
 * 
 * \sa IBlock::asString, IAttr::asString
 */
void SetVerboseMode( bool val );

/*!
 * Creates a new block of the given type and returns a reference to it
 * \param block_type – The type of block you want to create.  This value is case sensitive and spelling is important.  Ex. NiNode, NiTriShapeData, NiParticleSystemController, etc.
 * \return This function will return a newly created block of the requested type.  Beware, if the block type is unrecognized, this function will return a featureless block with whatever you sent it as the type.
 * 
 * <b>Example:</b> 
 * \code
 * blk_ref my_block = CreateBlock("NiNode");
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * my_block = CreateBlock("NiNode")
 * \endcode
 * 
 * sa BlocksInMemory
 */
blk_ref CreateBlock( string block_type );



//struct ComplexVertex {
//	ComplexVertex() : has_color(false), has_normal(false), vertex_index(0), normal_index(0), color_index(0) {}
//	~ComplexVertex();
//	bool has_color, has_normal;
//	int vertex_index, color_index, normal_index;
//	bool has_base_uv, has_glow_uv;
//	int base_uv_index, glow_uv_index;
//}
//
//struct ComplexFace {
//	vector<ComplexVertex> points;
//	int base_map_index;
//	int glow_map_index;
//};
//
//class ComplexShape {
//	void SetVertices( vector<Vector3> & vertices );
//	void SetUVs( vector<TexCoord> & uvs );
//	void SetColors( vector<Color4> & colors );
//	void SetNormals( vector<Vector3> & normals );
//	void SetBones( vector<blk_ref> & bones );
//	void SetFaces( list< vector< ComplexVertex > > & faces );
//
//	vector<Vector3> GetVertices();
//	vector<TexCoord> GetUVs();
//	vector<Color4> GetColors();
//	vector<Vector3> GetNormals();
//	vector<blk_ref> GetBones();
//	list< vector< ComplexVertex > > GetFaces();
//
//private:
//	vector<Vector3> _vertices;
//	vector<Color4> _colors;
//	vector<Vector3> _normals;
//	list<ComplexFace> _faces;
//	map<string, blk_ref> _materials;
//	map<string, vector<TexCoord> > _uvs;
//	map<blk_ref, map<int, float> > _bones;
//};
//
//void ComplexShape::CombineTriShapes( list<blk_ref> & tri_shapes ) {
//	//Clear all internal datea
//	_vertices.clear();
//	_colors.clear();
//	_normals.clear();
//	_materials.clear();
//	_uvs.clear();
//	_faces.clear();
//	_bones.clear();
//
//	//Create a temporary spot to hold the triangle lists from each TriShape
//	vector< vector<Triangle> > ts_faces;
//
//	//Create lists to hold the lookup tables
//	vector<int> tri_lookup, nor_lookup, col_lookup;
//	map<string, vector<int> > mat_lookup, uv_lookup;
//	
//	//--Cycle through all the TriShapes, adding their data to the lists--//
//	list<blk_ref>::iterator it;
//
//	for (it = tri_shapes.begin(); it != tri_shapes.end(); ++it) {
//		ITriShapeData * data = QueryTriShapeData(*it);
//
//		//Vertices
//		vector<Vector3> ts_verts = data->GetVertices();
//		_vertices.insert(_vertices.end(), ts_verts.begin(), ts_verts.end();
//
//		//Normals
//		vector<Vector3> ts_norms = data->GetNormals();
//		_normals.insert(_normals.end(), ts_norms.begin(), ts_norms.end();
//		
//		//Colors
//		vector<Colors> ts_cols = data->GetColors();
//		_colors.insert(_colors.end(), ts_colors.begin(), ts_colors.end();
//
//		//Triangles
//		ts_faces[i] = data->GetTriangles();
//
//		//UV Coords
//		vector< vector<TexCoords> > uvs(data->GetUVSetCount());
//		for (int i = 0; i < data->GetUVSetCount(); ++i) {
//			uvs[i] = data->GetUVSet(i);
//		}
//
//		//Associate UV Coord Data with proper map name
//		blk_ref tx_prop = par["Properties"]->FindLink( "NiTexturingProperty");
//		if ( tx_prop.is_null() == false ) {
//			int uv_set = 0;
//			for (int i = 0; i < 7; ++i) {
//				string attr_name, map;
//				switch(i) {
//					case 0:	attr_name = "Base Texture";     map = "map1";   break;
//					case 1:	attr_name = "Dark Texture";     map = "dark";   break;
//					case 2:	attr_name = "Detail Texture";   map = "detail"; break;
//					case 3:	attr_name = "Gloss Texture";    map = "gloss";  break;
//					case 4:	attr_name = "Glow Texture";     map = "glow";   break;
//					case 5:	attr_name = "Bump Map Texture"; map = "bump";   break;
//					case 6:	attr_name = "Decal 0 Texture";  map = "decal0";
//				}
//
//				if ( tx_prop[attr_name]->asTexDesc().isUsed == true ) {
//					//How to merge all UVs?
//				}
//
//		}
//
//
//		//blk_ref material = (*it)->GetAttr("Propreties")->FindLink("NiMaterialProperty");
//		//blk_ref skin_inst = (*it)->GetAttr("Skin Instance")->asLink();
//		//blk_ref skin_data;
//		//vector<blk_ref> bones;
//		//map<int, float> weights;
//		//if ( skin_inst.is_null() == false ) {
//		//	skin_block = skin_inst->GetAttr("Data");
//		//	if (skin_block.is_null() == false ) {
//		//		ISkinData * skin_data = QuerySkinData(skin_block);
//		//		weights = skin_data->GetWeights();
//		//		bones = skin_data->GetBones();
//		//	}
//		//}
//
//	}
//}

//--USER GUIDE DOCUMENTATION--//

/*! \mainpage Niflib Documentation
\section user_guide User Guide
- \ref intro_page
- \ref starting_out
- \ref attrs
- \ref link_blks
- \ref adv_interf
*/

///////////////////////////////////////////////////////////////////////////////

/*! \page intro_page Introduction

\section include Including the Library

You probably already know how to include a library, but here’s the basic gist if you don’t:

\subsection cpp C++

If you’re going to use the pre-compiled header file, make sure it is referenced in your project or make file.  Otherwise, make sure all the source code is included in your compile process. Also, make sure you add the location that you place niflib.h to your include directory paths.  With that out of the way, simply include this line at the top of your source code:

\code
#include "niflib.h"
\endcode

\subsection py Python

You should follow the instructions in the readme file that comes with the pre-compiled version of the Python SWIG wrapper for Windows.  Briefly, you will place the _niflib.dll and the niflib.py files in your Python folder.  If you want to compile them yourself you will need to get SWIG 1.3.25 or higher.  There is a make file provided for this purpose.  Once you have these files in the proper position in the Python directory, you can use the library in either of the two standard Python ways:

\code
from niflib import *
\endcode
or
\code
import niflib
\endcode

To save space I will assume in the examples that you have used the first method.  Of course if you use the second, you will have to preface all function calls with niflib.  For example, ReadNifTree() becomes niflib.ReadNifTree().

\section exept Exceptions

Niflib is a very much a C++ library, and therefore it uses exceptions rather than error return codes.  These are a lot more convenient in that you don’t have to use as many if statements, but not everyone understands what they are, so I thought I’d provide enough of an intro to get you along.  C++ exceptions should be mapped to Python exceptions transparently, so this only applies to people using the library via C++.

Very very basically, if you want to check if a Niflib function has failed, and why, wrap it in a try block like this:

\code
try {
    //Niflib Function Call
    blocks = ReadNifList( current_file );
}
catch( exception & e ) {
    cout << "Error: " << e.what() << endl;
    cout << "\a";
    return 0;
}
catch( ... ) {
    cout << "Unknown Exception." << endl;
    return 0;
}
\endcode

The really nice thing about exceptions is that you can place all of your Niflib calls within the try block, and if any one of them fails, execution will jump to the catch block.  If the exception is of the standard C++ type, which Niflib’s are, the first block will catch it, and an error message can be extracted and printed.  Otherwise, it will go to the second block, which is a catch-all statement that will end your program for any other reason.  There are ways to recover from exceptions, but this should be enough to allow you to at least exit gracefully if a function signals an error.

\section stl_temp STL & Templates

Niflib makes quite a bit of use of the standard template library, and also includes at least one template of its own.  You should be familiar with the template syntax for defining variables (ex: template<type>) You should also be familiar with at least the following STL built-in types:  string, vector, list, map.  These types map to Python types seamlessly (string, tuple, tuple, and dictionary respectively), so no understanding of C++ is required for Python users.
*/

///////////////////////////////////////////////////////////////////////////////

/*! \page starting_out Starting Out with Niflib

\section blk_basics NIF Block Basics

NIF files consist of several types of data blocks that store various things and are linked together.  These blocks are stored using blk_ref variables.  blk_ref is short for “Block Reference” and the blk_ref class is a kind of auto pointer similar to a C++ reference in that it does not need to be deleted, but more like a pointer in that it can be changed to point to a new block at any time.

The member functions of the blk_ref class will be covered in detail as they are needed.  There are also overloaded operators that make most of them unnecessary when working through C++.

As long as there is a blk_ref somewhere pointing to a particular block, it will remain in memory.  Therefore, you do not have to worry about freeing the blocks yourself.  You may be curious how many blocks are loaded into memory by the library at any particular time.  You can check with the \ref BlocksInMemory function.

\section rw_files Reading and Writing NIF Files

To check whether NIF file has a valid header, and to make sure that its version is supported, call the \ref CheckNifHeader function. There are two ways to read in a NIF file – as a list of blocks in the order they appear in the file and as the root block of a tree arranged correctly.  Most of the time you will probably want to use the tree method, as this is the only one eligible for writing.  The list method is provided for uses such as Niflyze that need to retrieve all blocks.  Un-supported blocks may not be included in the tree representation if no other blocks reference them.  So you’re going to want to call the \ref ReadNifTree function.

That’s all there is to reading in a NIF file.  If all goes well with the reading process (no exception was thrown), you will have at least one block in memory – the root block of the tree.  You can pass this same block to the \ref WriteNifTree function to create a new NIF file from the representation in memory.  WARNING:  Some features of the NIF format are still un-supported by Niflib, therefore in some cases the exported NIF may either be different from the original, or completely unusable.  DO NOT OVERWRITE THE ORIGINAL NIF FILE.

\section work_blk Working with Blocks

New blocks don’t have to just come from loaded NIF files.  To create a block yourself, you need to know the type of the block you want to create, for example a NiNode, and call the \ref CreateBlock function.

To actually do anything with these blocks, you need to know about the \ref IBlock interface that the block references (blk_ref variables) provide access to.  An interface is a class that consists completely of virtual functions, but all you have to know are the public functions it provides.

\ref IBlock has a lot of functions and I’ll cover each one as they come up.  You can access these functions through a blk_ref variable as if using a pointer by using the -> operator.  In Python you can simply use the dot (.) operator.

You might want a quick summary of what one of the blocks you have read in contains; in this case you can use the \ref IBlock::asString function to get the contents as an English summary.

You will probably also want to know the type of a block at some point.  You can retrieve this with the \ref IBlock::GetBlockType function.

<center>\ref attrs "Next Section >>>"</center>
*/

///////////////////////////////////////////////////////////////////////////////

/*! \page attrs Attributes

Of course, the interesting thing about blocks is the data they contain.  For all the basic block types, this data is stored in attributes.  Each block contains a list of attributes that you can iterate through, examine, and change.  Attributes are passed around in the library via the attr_ref.  Similar to blk_ref, attr_ref contains a reference to a particular attribute and gives you several overloaded operators to make them seem almost like normal variables of all sorts of different types.

You do not create attributes; they are added to NIF blocks automatically when they are created either by reading a NIF file or by the \ref CreateBlock function.  The attributes that a particular block will have depend on its type.  The names of these attributes are analogous to those found in our <a href = "http://niftools.sourceforge.net/docsys/">NIF File Format Browser</a>.  To get an attribute from a block, you generally ask for it by name using the \ref IBlock::GetAttr function.

As you may have noticed from the example if you clicked the link to that function, the attr_ref class has a handy overloaded bracket operator that allows you to get attributes by using bracket notation instead of actually typing out the name of the \ref IBlock::GetAttr function.

You may also have noticed that this function will return a null reference if the attribute you requested does not exist in a particular block.  A null reference is one that points to nothing, and no functions can be called on it.  You can determine whether a particular attr_ref is null by calling the \ref attr_ref::is_null function.

The reason that the GetAttr function does not simply throw an exception if the attribute doesn’t exist is that it can be useful to ask a block whether it has an attribute without ever knowing what it is.  For example, many blocks have identical attributes because they inherit them from abstract blocks in the format documentation.  It might be useful to loop through all blocks in a file and call the \ref IBlock::GetAttr function on each one requesting the “Translate” attribute.  You would then do whatever it was you were trying to do only if the function did not return a null attribute.

You can also get a list of all attributes in a block in the form of an STL vector of attr_ref variables by calling the \ref IBlock::GetAttrs function.

So what are attributes good for?  Basically, they serve as a generic container for different types of data.  An attribute could be a string, or an integer number, or even a whole structure.  I will list the different types of data an attribute can store.


<table><tr><th>Basic C++ Types</th><th>Niflib Basic Types</th><th>Niflib Structures</th></tr>
<tr><td>int<br>
float<br>
string<br>
</td><td>
blk_ref<br>
list<blk_ref><br>
</td><td>
Float3<br>
Matrix33<br>
TexSource<br>
BoundingBox<br>
TexDesc<br>
</td></tr></table>

Most of the time, attributes will hold simple data types like C++ types, blk_ref references, or a list of references.  However, sometimes they hold structures.  You may want to take a moment to familiarize yourself with these structures by clicking on their names in the table above.

So how is data stored in Attributes manipulated?  For that we must understand the IAttr interface to which atter_ref variables contain a reference to.

Did you click the link?  Wow, that’s a lot of functions!  But don’t worry, as you may have noticed most of them just do exactly the same thing but for different data types – They get and set data stored within the attribute.  Each data type that I listed above has an asType function and a matching Set function.  Once you understand one, you understand them all.

For example, check out the IAttr::Set(float) function and the IAttr::asFloat function.

From the C++ side, most of this is almost automatic because you can use the overloaded = operator to set attributes, and every type has an overloaded operator for that type so you can omit the function call and everything will usually work out fine.  If you have any trouble, though, you may want to try spelling it out explicitly.  Python has similar shortcuts, but they only work if you access the attribute using a block's bracket operator.  Otherwise, you will have to type out the whole function name.

There are several types of attributes, more than the list above, and each type stores a different type (or types) of values.  Following is a list of attribute types and the type of values they hold:

<table><tr><th>Attribute Type</th><th>Value Types held</th></tr>
<tr><td>attr_alphaformat</td><td>int</td></tr>
<tr><td>attr_applymode</td><td>int</td></tr>
<tr><td>attr_bbox</td><td>BoundingBox</td></tr>
<tr><td>attr_bones</td><td>Automatic.</td></tr>
<tr><td>attr_bumpmap</td><td>TexDesc & blk_ref</td></tr>
<tr><td>attr_byte</td><td>int</td></tr>
<tr><td>attr_color3</td><td>Float3</td></tr>
<tr><td>attr_controllertarget</td><td>Automatic.</td></tr>
<tr><td>attr_flags</td><td>int</td></tr>
<tr><td>attr_float</td><td>float</td></tr>
<tr><td>attr_float3</td><td>Float3</td></tr>
<tr><td>attr_int</td><td>int</td></tr>
<tr><td>attr_lightmode</td><td>int</td></tr>
<tr><td>attr_link</td><td>blk_ref</td></tr>
<tr><td>attr_linkgroup</td><td>vector<blk_ref></td></tr>
<tr><td>attr_lodinfo</td><td>Coming Soon.</td></tr>
<tr><td>attr_matrix33</td><td>Matrix33</td></tr>
<tr><td>attr_mipmapformat</td><td>int</td></tr>
<tr><td>attr_parent</td><td>Automatic.</td></tr>
<tr><td>attr_particlegroup</td><td>Coming Soon.</td></tr>
<tr><td>attr_pixellayout</td><td>int</td></tr>
<tr><td>attr_short</td><td>int</td></tr>
<tr><td>attr_skeletonroot</td><td>Automatic.</td></tr>
<tr><td>attr_string</td><td>string</td></tr>
<tr><td>attr_texsource</td><td>TexSource</td></tr>
<tr><td>attr_texture</td><td>TexDesc & blk_ref</td></tr>
<tr><td>attr_vector3</td><td>Float3</td></tr>
<tr><td>attr_vertmode</td><td>int</td></tr>
</table>

To determine the type of an attribute, you can call the IAttr::GetType function.

You may also want to get the name of an attribute at runtime, say if you’re iterating through a list of all the attributes in a block to print out something about each one and you’d like to know the name.  For this you can call the IAttr::GetName function.

One other function that all attributes have in common is the IAttr::asString function.  Similarly to the function by the same name of the IBlock interface, this function returns a string that contains a formatted printout of the information held by a specific attribute.  The IBlock::asString function actually loops through its own attributes calling the IAttr::GetName and the IAttr::asString function for each one to create its output.

<center>\ref starting_out "<< Previous Section"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\ref link_blks "Next Section >>>"</center>
*/

///////////////////////////////////////////////////////////////////////////////

/*! \page link_blks Linking Blocks

Niflib views the NIF file as a group of interconnected blocks.  Technically a NIF file is a directed acyclic graph, and not a pure tree.  Basically this means that some nodes in the graph can have multiple parents, but loops cannot be formed.  There are two main categories of blocks in a nif file, Nodes and Non-Nodes.  Both types may have simple connect points for other nodes.  These are attributes which store a single block reference (blk_ref).  In order to link blocks together, you use these attributes in much the same way as other attributes that store data, but you call the IAttr::asLink and IAttr::Set(blk_ref const &) functions.  These functions will not only change the data inside the attribute, but they will have the affect of linking the two blocks together.  Niflib is aware of these connections and will not destroy a block that is connected to another, even if the variable expires in your code.  The WriteNifTree function uses these connections to determine the proper order and indexing to use when writing out a NIF file.

Once the blocks are linked, the child will now be aware of its new parent.  You can query the child block for the first parent it receives by calling the IBlock::GetParent function on that block.  Niflib keeps track of all parents, but usually the first one is the only one that’s important so this is what the IBlock::GetParent function returns.

Node blocks are always arranged in a tree fashion via the “Children” attribute and will always have one parent.  The “Children” attribute is an attr_linkgroup type attribute which stores a vector of block references (vector<blk_ref>) .  “Properties” is another common example of an attr_linkgroup type attribute.  These linkgroup attributes have a few more functions specific to them.  First of all, instead of having just one link, these blocks can have several or none.  So you need to use the IAttr::asLinkList function to get all the links contained within the attribute.

What if you wanted to follow all the links of a block? Say if you were trying to descend the entire graph easily.  In that case, you can use the IBlock::GetLinks function.  This will return a list of all blocks linked through any attribute within that block.

Instead of setting a linkgroup attribute all at once, you add or subtract links as necessary.  You can add links one at a time with the IAttr::AddLink function, or in a group with the IAttr::AddLinks function.  You can remove all links to a specific block by calling the IAttr::RemoveLinks function.  The IAttr::ClearLinks function will remove all the links.  Finally, it can sometimes be handy to find a link based on its block type (NiNode, for instance).  For that you can use the IAttr::FindLink function.

<center>\ref attrs "<< Previous Section"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\ref adv_interf "Next Section >>>"</center>
*/

///////////////////////////////////////////////////////////////////////////////

/*! \page adv_interf Advanced Block Interfaces

You now know how to access and change the information in most of the NIF blocks.  You know how to link blocks and unlink them, and you know how to read and write NIF files.  But if you take a close look at the types of attributes available, you will notice some apparent omissions.  Where are the lists of vertices?  How do you set up animation keys?  What about skin weights?  All these features are available through advanced block interfaces which you can query from simple block references.

Because calling the IBlock::QueryInterface function yourself can get a little messy (and is impossible from Python), several query functions are provided, one for each type of advanced block interface.  All of these functions work the same way, so I’ll just use one example to illustrate the rest.

The INode interface is an advanced interface that is present in all blocks that are nodes.  Blocks can have more than one advanced interface; you can use the QueryNode function to determine if INode is one of them.  Bear in mind that interfaces must be stored in pointers, so the return value of QueryNode is a pointer to an INode interface.  That is, it’s type is INode*.  This is not important for Python users to know, but C++ users must be able to declare a variable to hold their newly queried advanced interface.

Node data blocks in NIF files are arranged in a pure tree.  This tree defines a transform hierarchy… in other words, if a block’s parent is moved to a position in 3D space, its children will move to the same position.  Therefore, any 3D transform on the child is relative to its parent… and its parent, all the way back to the root node.  This can be a lot to keep track of, so Niflib does it for you.  Using the functions of the INode interface, you can get a full 4x4 transform matrix for both local (relative to the parent) and world (relative to the origin) coordinates.  To do this, you call the INode::GetLocalTransform and INode::GetWorldTransform functions respectively.  

<center>\ref link_blks "<< Previous Section"</center>

*/

#endif
