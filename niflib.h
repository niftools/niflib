/* Copyright (c) 2006, NIF File Format Library and Tools
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
#include "dll_export.h"
#include "nif_math.h"
#include "NIF_IO.h"
#include "obj/NiObject.h"
#include "obj/NiNode.h"
#include "obj/NiAVObject.h"
//#include "gen/obj_defines.h"
//#include "kfm.h"

using namespace std;
namespace Niflib {

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
 *   vector<NiObjectRef> blocks = ReadNifList( "test_in.nif" );
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
NIFLIB_API unsigned int CheckNifHeader( string const & file_name );

/*!
 * Reads the given file by file name and returns a vector of block references
 * \param file_name The name of the file to load, or the complete path if it is not in the working directory.
 * \return A vector of block references that point to all the blocks read from the Nif file.
 * 
 * <b>Example:</b> 
 * \code
 * NiObjectRef my_block = ReadNifList("test_in.nif");
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * my_block = ReadNifList("test_in.nif")
 * \endcode
 * 
 * \sa ReadNifTree, WriteNifTree
 */
NIFLIB_API vector<NiObjectRef> ReadNifList( string const & file_name );

/*!
 * Reads the given input stream and returns a vector of block references
 * \param stream The input stream to read NIF data from.
 * \return A vector of block references that point to all the blocks read from the stream.
 */
NIFLIB_API vector<NiObjectRef> ReadNifList( istream & in );

/*!
 * Reads the given file by file name and returns a reference to the root block.
 * \param file_name The name of the file to load, or the complete path if it is not in the working directory.
 * \return A block reference that points to the root of tree of data blocks contained in the NIF file.
 * 
 * <b>Example:</b> 
 * \code
 * NiObjectRef my_block = ReadNifTree("test_in.nif");
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * my_block = ReadNifTree("test_in.nif")
 * \endcode
 * 
 * \sa ReadNifList, WriteNifTree
 */
NIFLIB_API NiObjectRef ReadNifTree( string const & file_name );

/*!
 * Reads the given input stream and returns a reference to the root block.
 * \param stream The input stream to read NIF data from.
 * \return A block reference that points to the root of the tree of data blocks contained in the NIF file.
 */
NIFLIB_API NiObjectRef ReadNifTree( istream & in );

/*!
 * Creates a new NIF file of the given file name by crawling through the data tree starting with the root block given.
 * \param file_name The desired file name for the new NIF file.  The path is relative to the working directory unless a full path is specified.
 * \param root The root block to start from when writing out the NIF file.  All decedents of this block will be written to the file in tree-descending order.
 * \param version The version of the NIF format to use when writing a file.  Default is version 4.0.0.2.
 * \param user_version Some companies implement special extentions to the format which can be specified here.
 * 
 * <b>Example:</b> 
 * \code
 * NiObjectRef my_block = ReadNifTree("test_in.nif");
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
NIFLIB_API void WriteNifTree( string const & file_name, NiObjectRef const & root, unsigned int version = VER_4_0_0_2, unsigned int user_version = 0 );

/*!
 * Writes a nif tree to an ostream starting at the given root block.
 * \param stream The output stream to write the NIF data to.
 * \param root The root block to start from when writing out the NIF data.  All decedents of this block will be written to the stream in tree-descending order.
 * \param version The version of the NIF format to use when writing a file.  Default is version 4.0.0.2.
 */
NIFLIB_API void WriteNifTree( ostream & stream, NiObjectRef const & root, unsigned int version = VER_4_0_0_2, unsigned int user_version = 0 );

//TODO:  This was written by Amorilia.  Figure out how to fix it.
/*!
 * Writes a bunch of files given a base file name, and a pointer to the root block of the Nif file tree.
 * \param file_name The desired file name for the base NIF file. This name serves as the basis for the names of any Kf files and Kfm files as well.  The path is relative to the working directory unless a full path is specified.
 * \param root The root block to start from when writing out the NIF file.
 * \param version The version of the NIF format to use when writing a file.
 * \param export_files What files to write: NIF, NIF + KF + KFM, NIF + KF's + KFM, KF only, KF's only
 * \param kf_type The KF type (Morrowind style, DAoC style, CivIV style, ...)
 */
//NIFLIB_API void WriteFileGroup( string const & file_name, NiObjectRef const & root, unsigned int version, unsigned int export_files, unsigned int kf_type );

//TODO:  Figure out how to fix this to work with the new system
/*!
 * Merges two Nif trees into one.  For standard Nif files, any blocks with the same name are merged.  For Kf files, blocks are attatched to those that match the name specified in the KF root block.  The data stored in a NIF file varies from version to version.  Usually you are safe with the default option (the highest availiable version) but you may need to use an earlier version if you need to clone an obsolete piece of information.
 * \param target The root block of the first Nif tree to merge.
 * \param right The root block of the second Nif tree to merge.
 * \param version The version of the nif format to use during the clone operation on the right-hand tree.  The default is the highest version availiable.
 */
//NIFLIB_API void MergeNifTrees( NiNodeRef target, NiAVObjectRef right, unsigned int version = 0xffffffff );


//// Returns list of all blocks in the tree rooted by root block.
//list<NiObjectRef> GetNifTree( NiObjectRef const & root_block );

////Returns the NIF spec version of a file, given a file name.
//string GetFileVersion(string file_name);

/*!
 * Creates a new block of the given type and returns a reference to it
 * \param block_type – The type of block you want to create.  This value is case sensitive and spelling is important.  Ex. NiNode, NiTriShapeData, NiParticleSystemController, etc.
 * \return This function will return a newly created block of the requested type.  Beware, if the block type is unrecognized, this function will return a featureless block with whatever you sent it as the type.
 * 
 * <b>Example:</b> 
 * \code
 * NiObjectRef my_block = CreateBlock("NiNode");
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * my_block = CreateBlock("NiNode")
 * \endcode
 * 
 * sa BlocksInMemory
 */
NIFLIB_API NiObjectRef CreateBlock( string block_type );

/*!
 * Returns whether the requested version is supported.
 * \param version The version of the nif format to test for availablity.
 * \return Whether the requested version is supported.
 */
NIFLIB_API bool IsVersionSupported(unsigned int ver);

/*!
 * Parses the version string and returns in the equivalent version as integer
 * \param version The version of the nif format to parse.
 * \return The version in integer format. Returns VER_INVALID for invalid version strings.
 */
NIFLIB_API unsigned int GetVersion(string version);

//TODO:  This is planned functionality but is unfinished
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
*/

///////////////////////////////////////////////////////////////////////////////

/*! \page intro_page Introduction

\section compile Compiling the Library

Starting with version 0.5, Niflib creates a lib file that is too large to distribute directly, so to use it through C++ you must first compile it.  If you need help to do this, there is information about it on our main website here:  <a href="http://niftools.sourceforge.net/wiki/index.php/Niflib/Compile">Compiling Niflib</a>.

A Python compile of the library will still be available for Windows, but for other platforms you will need to compile the library yourself.

\section include Including the Library

\subsection cpp C++

Once you have compiled Niflib, you will have a binary library file which you must reference from your project.  If you’re using Visual Studio, you can add it as an “Additional Dependancy” within your project options.  You can also include all the source code in your compile process if you do not want to use an intermediate library file. Finally, make sure the path to niflib.h is in your include search paths. 

\code
#include "niflib.h"
\endcode

There are now separate include files for each object type in a NIF file.  To include the NiNode object, for example, include the obj/NiNode.h file like so:

\code
#include "obj/NiNode.h"
\endcode

You will have one such line in your source code for each NIF object that your program needs access to.

Niflib also wraps all its functions in the "Niflib" namespace.  So, depending on your needs, you can either gain access to all Niflib symbols with a using directive like this:

\code
using namespace Niflib;
\endcode

Gain access to specific symbols but not others with specific using directives like this:

\code
using Niflib::NiNodeRef;
using Niflib::NiObjectRef;
using Niflib::ReadNifTree;
\endcode

Or simply prepend all of your Niflib symbols with "Niflib::" like this:

\code
Niflib::NiObjectRef niObj = Niflib::ReadNifTree( "test.nif" );
\endcode

\subsection py Python

If you are using the pre-compiled version of the Python SWIG wrapper for Windows, you should follow the instructions in the readme file that is included. Briefly, you will place the _niflib.dll and the niflib.py files in your Python 2.4 install location. If you want to compile them yourself you will need to get SWIG 1.3.25 or higher. There there are two build methods, Scons and a Visual Studio 2005 project, provided for this purpose.

Once you have these files in the proper position in the Python directory, you can use the library in either of the two standard Python ways:

\code
from niflib import *
\endcode
or
\code
import niflib
\endcode

To save space, the examples assume that you have used the first method. Of course if you use the second, you will have to preface all function calls with niflib. For example, ReadNifTree() becomes niflib.ReadNifTree().  Currently the Python module includes all NIF objects and is not split into separate modules for each object like the C++ version, so you will only need a single import statement to get everything.

\section exept Exceptions

Niflib uses C++ exceptions rather than error return codes. These are a lot more convenient in that you don’t have to wrap every single function in an if-test, but not everyone understands what they are, so I thought I’d provide enough of an intro to get you along. C++ exceptions should be mapped to Python exceptions transparently, so this only applies to people using the library via C++.

Very basically, if you want to check if Niflib function calls are failing, and why, wrap them in a try block like this:

\code
try {
    //Niflib Function Call
    vector<NiObject> objects = ReadNifList( current_file );
}
catch( exception & e ) {
    cout << "Error: " << e.what() << endl;
    return 0;
}
catch( ... ) {
    cout << "Unknown Exception." << endl;
    return 0;
}
\endcode

The really nice thing about exceptions is that you can place all of your Niflib calls within one try block, and if any one of them fails, execution will jump to the catch block. The first block will catch any exception thrown explicitly by Niflib, and an error message can be extracted and printed. Other exceptions, such as from bugs in the library or errors it never occurred to us to test for, will go to the second block which is a catch-all statement that will end your program for any other reason.

There are ways to recover from exceptions, but this should be enough to allow you to at least exit gracefully if a function signals an error.

\section stl_temp STL & Templates

Niflib makes quite a bit of use of the standard template library, and also includes some templates of its own. You should be familiar with the template syntax for defining variables (ex: template<type>) You should also be familiar with at least the following STL built-in types: string, vector, and list. These types map to Python types seamlessly (string, tuple, and tuple respectively), so no understanding of C++ is required for Python users.

//<center>\ref starting_out "Next Section >>>"</center>

*/

///////////////////////////////////////////////////////////////////////////////

/*! \page starting_out Starting Out with Niflib

\section file_basics NIF File Basics

NIF files are the result of the NetImmmerse/Gamebryo engine saving the current state of a scene graph.  A scene graph is a tree of 3D transforms that has meshes and rendering instructions attached.  Each object is a class which, when the file is saved, writes its contents to disk.  So the NIF file is a listing of all the NIF classes, or objects, that are required to recreate a particular scene.

The objects in a NIF file all inherit from the NiObject class and reference eachother in various ways.  These relationships are reconstructed when the file is loaded from disk and can then be broken or redirected.  The most important structure is formed by the scene graph objects.  These objects inherit from the NiAVObject class and form the spacial structure of the scene represented by the NIF file.  Each has a 3D transform that is relative to its parent.

Attatched to the NiAVObject classes are various other sorts of objects that either contain the raw data used to render the scene, such as the verticies in NiTriBasedGeomData and the animation keyframes in NiKeyFrameData, or modify the way the scene is drawn in some other way such as objects inheriting from NiProperty and NiExtraData.

Each object type has member functions which allow you to get and set data, adjust linkage to other objects, and some also include functions to perform useful calculations on the data.

You do not access the classes directly, however.  Niflib uses reference counting to determine when objects are destroyed, so you always access a class through a Ref smart pointer.  This is a template which takes the class as its template argumetn, such as Ref<NiNode>.  For each type of Ref a typedef has been provided in the form of [class name]Ref, so Ref<NiNode> has the typedef NiNodeRef, and this name can be used instead of the more unusual template syntax.  When the last Ref smart pointer that points to a particular object is reassigned or goes out of scope, that object will take care of cleaning itself up automatically.

Objects use Ref smart pointers internally as well, so you don’t have to worry about objects that are referenced by other objects destroying themselves unexpectedly.


\section rw_files Reading and Writing NIF Files

To check whether a NIF file has a valid header, and to make sure that its version is supported, call the \ref CheckNifHeader function. There are two ways to read in a NIF file – as a list of objects in the order they appear in the file and as a single Ref pointing to the root of the scene graph tree from which all other objects can be found by following the links between objects.  Most of the time you will probably want to use the tree method, as this is the only one eligible for writing.  The list method is provided for uses such as Niflyze that need to retrieve all objects, regardless of whether we fully understand the links that keep them from destroying themselves.  Un-supported blocks may not be included in the tree representation if no other blocks reference them.  So most of the time, you’re going to want to call the \ref ReadNifTree function.

That’s all there is to reading in a NIF file.  If all goes well with the reading process (no exception was thrown), you will have at least one NIF object in memory – the root block of the tree.  You can pass this same block to the \ref WriteNifTree function to create a new NIF file from the representation in memory.

WARNING:  Some features of the NIF format are still unsupported by Niflib, therefore in some cases the exported NIF may either be different from the original, or completely unusable.  DO NOT OVERWRITE THE ORIGINAL NIF FILE.

\section work_blk Working with NIF Objects

New class objects don’t have to just come from loaded NIF files.  To create an object block yourself, you can do so by using the C++ new keyword like so:

\code
RefNiNode node = new NiNode;
\endcode

It is recommended to always use smart pointers, rather than plain pointers, to ensure that your object is not destroyed before you realize it.  So do NOT do this:

\code
NiNode * node = new NiNode;
\endcode

All NIF objects inherit from \ref NiObject so a good place to start would be understanding the methods of that class.

You can access the member functions of any class through a Ref smart pointer of the right type by using the -> operator.  In Python you can simply use the dot (.) operator.

If you have a Ref of one type, such as a generic NiObjectRef, and you want to know if the object it points to also inherits from the NiNode class, you use the \ref DynamicCast template function.  To cast from a NiObjectRef to a NiNodeRef, you would do the following:

\code
NiObjectRef root = ReadNifTree( “test.nif” );
NiNodeRef node = DynamicCast<NiNode>( root );
if ( node != NULL ) {
   ...
\endcode

Note the template syntax of the \ref DynamicCast function.  In Python these tempates are mapped to functions named DynamicCastTo[object type].  For example, DynamicCastToNiNode.  To use them you must use the \ref Ref::Ptr() function as they expect pointers rather than references.  For example:

\code
root = ReadNifTree( “test.nif” );
node = DynamicCastToNiNode( root.Ptr() );
if root != NULL:
   ...
\endcode

Notice also that you must always check the value returned by \ref DynamicCast.  If the cast is not successful, i.e. the object is not a derived type of the one you’re trying to cast it to, the function will return NULL.

Casting down the inheritance tree should be automatic in C++, but you can also explicitly call the \ref StaticCast function.  You will need to use this function in Python to cast a Ref to the type expected by some member functions which take Ref arguments.

One useful function of all NIF objects is the \ref NiObject::asString function.  You can use it to get an English summary of the contents of that object.  You can also call the \ref NiObject::GetIDString function to get a short read out that includes the memory address, type, and name, if any, of the object.

You will probably also want to know the type of a block at some point.  You can retrieve this with the \ref NiObject::GetType function.  This returns a reference to the Type value that uniquly identifies this class.  You can get its name by calling the \ref Type::GetTypeName function.

<center>\ref intro_page "<< Previous Section"</center>

*/

}
#endif
