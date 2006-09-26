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
#include "nif_versions.h"
#include "Ref.h"
#include "gen/enums.h"

using namespace std;
namespace Niflib {

//Classes used
class NiObject;
class NiNode;
class NiAVObject;
class NiControllerSequence;

#ifndef NULL
#define NULL 0  /*!< Definition used to detect null pointers. */ 
#endif

//--Constants--//

/*! Keyframe trees are game dependent, so here we define a few games. */
enum NifGame {
	KF_MW = 0, /*!< keyframe files: NiSequenceStreamHelper header, .kf extension */
	KF_DAOC = 1, /*!< keyframe files: NiNode header, .kfa extension */
	KF_CIV4 = 2 /*!< keyframe files: NiControllerSequence header, .kf extension */
};

/*! Export options. */
enum ExportOptions { 
	EXPORT_NIF = 0, /*!< NIF */
	EXPORT_NIF_KF = 1, /*!< NIF + single KF + KFM */
	EXPORT_NIF_KF_MULTI = 2, /*!< NIF + multiple KF + KFM */
	EXPORT_KF = 3, /*!< single KF */
	EXPORT_KF_MULTI = 4 /*!< multiple KF */
};

//--Structures--//

struct NifInfo {
	NifInfo() : version(VER_4_0_0_2), userVersion(0), userVersion2(0), endian(INFO_LITTLE_ENDIAN) {}
	NifInfo( unsigned version, unsigned userVersion = 0, unsigned userVersion2 = 0) {
		this->version = version;
		this->userVersion = userVersion;
		this->userVersion2 = userVersion2;
		endian = INFO_LITTLE_ENDIAN;
	}
	//TODO: Implement endian support
	enum EndianType {
		INFO_BIG_ENDIAN = 0,
		INFO_LITTLE_ENDIAN = 1
	}; 
	unsigned version;
	unsigned userVersion;
	unsigned  userVersion2;
	/*! This is not yet supported. */
	EndianType endian;
	/*! This is only supported in Oblivion.  It contains the name of the person who created the NIF file. */
	string creator;
	/*! This is only supported in Oblivion.  It seems to contiain the type of script or program used to export the file. */
	string exportInfo1;
	/*! This is only supported in Oblivion.  It seems to contain the more specific script or options of the above. */
	string exportInfo2;
};

//--Main Functions--//

/*!
 * Reads the header of the given file by file name and returns the NIF version
 * if it is a valid NIF file. Call this function prior to calling ReadNifList
 * or ReadNifTree, if you want to make sure that its NIF version is supported
 * before trying to read it.
 * \param file_name The name of the file to load, or the complete path if it is not in the working directory.
 * \return The NIF version of the file, in hexadecimal format. If the file is not a NIF file, it returns VER_INVALID.
 * 
 * <b>Example:</b> 
 * \code
 * unsigned ver = GetNifVersion("test_in.nif");
 * if ( IsSupportedVersion(ver) == false ) {
 *    cout << "Unsupported.\n" << endl;
 * } else if ( ver == VER_INVALID ) {
 *    cout << "Not a NIF file.\n" << endl;
 * }
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * ver = CheckNifVersion("test_in.nif")
 * if ( IsSupportedVersion(ver) == false ):
 *     print "Unsupported."
 * elif ( ver == VER_INVALID ):
 *     print "Not a NIF file."
 * \endcode
 */
NIFLIB_API unsigned int GetNifVersion( string const & file_name );

/*!
 * Reads the given file by file name and returns a vector of block references
 * \param file_name The name of the file to load, or the complete path if it is not in the working directory.
 * \param info Optionally, a NifInfo structure pointer can be passed in, and it will be filled with information from the header of the NIF file.
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
NIFLIB_API vector< Ref<NiObject> > ReadNifList( string const & file_name, NifInfo * info = NULL );

/*!
 * Reads the given input stream and returns a vector of block references
 * \param in The input stream to read NIF data from.
 * \param info Optionally, a NifInfo structure pointer can be passed in, and it will be filled with information from the header of the NIF file.
 * \return A vector of block references that point to all the blocks read from the stream.
 */
NIFLIB_API vector< Ref<NiObject> > ReadNifList( istream & in, NifInfo * info = NULL );

/*!
 * Reads the given file by file name and returns a reference to the root block.
 * \param file_name The name of the file to load, or the complete path if it is not in the working directory.
 * \param info Optionally, a NifInfo structure pointer can be passed in, and it will be filled with information from the header of the NIF file.
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
NIFLIB_API Ref<NiObject> ReadNifTree( string const & file_name, NifInfo * info = NULL );

/*!
 * Reads the given input stream and returns a reference to the root block.
 * \param[in] in The input stream to read NIF data from.
 * \param[out] info Optionally, a NifInfo structure pointer can be passed in, and it will be filled with information from the header of the NIF file.
 * \return A block reference that points to the root of the tree of data blocks contained in the NIF file.
 */
NIFLIB_API Ref<NiObject> ReadNifTree( istream & in, NifInfo * info = NULL );

/*!
 * Creates a new NIF file of the given file name by crawling through the data tree starting with the root block given.
 * \param[in] file_name The desired file name for the new NIF file.  The path is relative to the working directory unless a full path is specified.
 * \param[in] root The root block to start from when writing out the NIF file.  All decedents of this block will be written to the file in tree-descending order.
 * \param[in] info A NifInfo structure that contains information such as the version of the NIF file to create.
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
NIFLIB_API void WriteNifTree( string const & file_name, Ref<NiObject> const & root, NifInfo & info );

/*!
 * Writes a nif tree to an ostream starting at the given root block.
 * \param[in] in The output stream to write the NIF data to.
 * \param[in] root The root block to start from when writing out the NIF data.  All decedents of this block will be written to the stream in tree-descending order.
 * \param[in] info A NifInfo structure that contains information such as the version of the NIF file to create.
 */
NIFLIB_API void WriteNifTree( ostream & in, Ref<NiObject> const & root, NifInfo & info );

/*!
 * Writes a bunch of files given a base file name, and a pointer to the root block of the Nif file tree.
 * \param[in] file_name The desired file name for the base NIF file. This name serves as the basis for the names of any Kf files and Kfm files as well.  The path is relative to the working directory unless a full path is specified.
 * \param[in] root The root block to start from when writing out the NIF file.
 * \param[in] info A NifInfo structure that contains information such as the version of the NIF file to create.
 * \param[in] export_files What files to write: NIF, NIF + KF + KFM, NIF + KF's + KFM, KF only, KF's only
 * \param[in] kf_type The KF type (Morrowind style, DAoC style, CivIV style, ...)
 */
NIFLIB_API void WriteFileGroup( string const & file_name, Ref<NiObject> const & root, NifInfo & info, ExportOptions export_files = EXPORT_NIF, NifGame kf_type = KF_MW);

/*!
 * Creates a clone of an entire tree of objects.
 * \param[in] root The root block to start from when cloning the NIF data.  All referenced objects will be included in the new tree.
 * \param[in] version The version of the NIF format to use when writing a file.  Default is version 4.0.0.2.
 * \param[in] user_version The user version of the NIF format to use when writing a file.  Default is user version 0.
 * \return The root of the new cloned tree.
 */
NIFLIB_API Ref<NiObject> CloneNifTree( Ref<NiObject> const & root, unsigned version = 0xFFFFFFFF, unsigned user_version = 0 );


//TODO:  Figure out how to fix this to work with the new system
/*!
 * Merges two Nif trees into one.  For standard Nif files, any blocks with the same name are merged.  For Kf files, blocks are attatched to those that match the name specified in the KF root block.  The data stored in a NIF file varies from version to version.  Usually you are safe with the default option (the highest availiable version) but you may need to use an earlier version if you need to clone an obsolete piece of information.
 * \param[in,out] target The root block of the first Nif tree to merge.
 * \param[in] right The root block of the second Nif tree to merge.
 * \param[in] version The version of the nif format to use during the clone operation on the right-hand tree.  The default is the highest version availiable.
 * \param[in] user_version The user version to use during the clone operation.
 */
//NIFLIB_API void MergeNifTrees( NiNodeRef target, NiAVObjectRef right, unsigned int version = 0xFFFFFFFF );
NIFLIB_API void MergeNifTrees( const Ref<NiNode> & target, const Ref<NiControllerSequence> & right, unsigned version = 0xFFFFFFFF, unsigned user_version = 0  );

/*! 
 * Traverses a tree of NIF objects, attempting to move each skeleton root
 * to the natural bind position where no meshes are distorted by skin
 * influences.  This is not always successful and only affects nodes that
 * are skin influences.
 * \param[in] root The root NiNode of the tree.
 */
NIFLIB_API void SendNifTreeToBindPos( const Ref<NiNode> & root );

//// Returns list of all blocks in the tree rooted by root block.
//list<NiObjectRef> GetNifTree( NiObjectRef const & root_block );

////Returns the NIF spec version of a file, given a file name.
//string GetFileVersion(string file_name);

/*!
 * Creates a new block of the given type and returns a reference to it.
 * In C++, it is not necessary to call this function as you can create
 * objects with the new keyword.  In Python, however, this is the only
 * way to create new objects for now.
 * This is 
 * \param block_type – The type of block you want to create.  This value is case sensitive and spelling is important.  Ex. NiNode, NiTriShapeData, NiParticleSystemController, etc.
 * \return This function will return a newly created block of the requested type.  Beware, if the block type is unrecognized, this function will return a featureless block with whatever you sent it as the type.
 *
 * sa NiObject::NumObjectsInMemory
 */
#ifdef SWIG
NIFLIB_API Ref<NiObject> CreateObject( string block_type );
#else
NIFLIB_HIDDEN Ref<NiObject> CreateObject( string block_type );
#endif

/*!
 * Returns whether the requested version is explicitly supported.  This does
 * not mean that the file will not open, rather it means that we have not
 * encountered files with this version in our tests yet.
 * \param[in] version The version of the NIF format to test for the support level of.
 * \return Whether the requested version is supported.
 */
NIFLIB_API bool IsSupportedVersion( unsigned int version );

/*!
 * Parses a version string and returns the equivalent version as a byte-packed integer.
 * \param[in] version The version number of the NIF format to parse in string format.
 * \return The version in integer format or VER_INVALID if the version string is not in the correct format.
 */
NIFLIB_API unsigned ParseVersionString( string version );

/*!
 * Takes a NIF version in byte-packed integer format and returns a formatted human-
 * readable string.  For example, 0x04000002 returns the string "4.0.0.2"
 * \param[in] version The NIF version in integer form.
 * \return The equivalent string representation of the version number.
 */
NIFLIB_API string FormatVersionString( unsigned version );

//--USER GUIDE DOCUMENTATION--//

/*! \mainpage Niflib Documentation
\section user_guide User Guide
- \ref intro_page
- \ref starting_out
*/

///////////////////////////////////////////////////////////////////////////////

/*! \page intro_page Introduction

\section compile Compiling the Library

Starting with version 0.5, Niflib creates a lib file that is too large to distribute directly, so to use it through C++ you must first compile it.  If you need help to do this, there is information about it on our main website here:  <a href="http://www.niftools.org/wiki/index.php/Niflib/Compile">Compiling Niflib</a>.

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

To check whether a file is really a NIF file, call the CheckNifVersion() function. You can then call the IsSupportedVersion() function to determine whether the data in the file may not be well understood.  There are two ways to read in a NIF file – as a list of objects in the order they appear in the file and as a single Ref pointing to the root of the scene graph tree from which all other objects can be found by following the links between objects.  Most of the time you will probably want to use the tree method, as this is the only one eligible for writing.  The list method is provided for uses such as Niflyze that need to retrieve all objects, regardless of whether we fully understand the links that keep them from destroying themselves.  Unsupported objects may not be included in the tree representation if no other objects reference them.  So most of the time, you’re going to want to call the ReadNifTree() function.

That’s all there is to reading in a NIF file.  If all goes well with the reading process (no exception was thrown), you will have at least one NIF object in memory – the root object of the tree.  You can pass this same object to the WriteNifTree() function to create a new NIF file from the representation in memory.

WARNING:  Some features of the NIF format are still unsupported by Niflib, therefore in some cases the exported NIF may either be different from the original, or completely unusable.  DO NOT OVERWRITE THE ORIGINAL NIF FILE.

\section work_blk Working with NIF Objects

New class objects don’t have to just come from loaded NIF files.  To create an object yourself, you can do so by using the C++ new keyword like so:

\code
RefNiNode node = new NiNode;
\endcode

It is recommended to always use smart pointers, rather than plain pointers, to ensure that your object is not destroyed before you realize it.  So do NOT do this:

\code
NiNode * node = new NiNode;
\endcode

All NIF objects inherit from NiObject so a good place to start would be understanding the methods of that class.

You can access the member functions of any class through a Ref smart pointer of the right type by using the -> operator.  In Python you will need to use the Ref::Ptr() function as an intermediary between a smart reference and the object that it holds, like so:

\code
//C++
niNode->GetChildren;

#Python
niNode.Ptr().GetChildren()
\endcode

If you have a Ref of one type, such as a generic NiObjectRef, and you want to know if the object it points to also inherits from the NiNode class, you use the DynamicCast() template function.  To cast from a NiObjectRef to a NiNodeRef, you would do the following:

\code
NiObjectRef root = ReadNifTree( “test.nif” );
NiNodeRef node = DynamicCast<NiNode>( root );
if ( node != NULL ) {
   ...
\endcode

Note the template syntax of the DynamicCast() function.  In Python these tempates are mapped to functions named DynamicCastTo[object type]().  For example, DynamicCastToNiNode().  To use them you must use the Ref::Ptr() function as they expect pointers rather than references.  For example:

\code
root = ReadNifTree( “test.nif” );
node = DynamicCastToNiNode( root.Ptr() );
if root != NULL:
   ...
\endcode

Notice also that you must always check the value returned by DynamicCast().  If the cast is not successful, i.e. the object is not a derived type of the one you’re trying to cast it to, the function will return NULL.

Casting down the inheritance tree should be automatic in C++, but you can also explicitly call the StaticCast() function.  You will need to use this function to cast a Ref to the type expected by some member functions which take Ref arguments.

One useful function of all NIF objects is the NiObject::asString() function.  You can use it to get an English summary of the contents of that object.  You can also call the NiObject::GetIDString() function to get a short readout that includes the memory address, type, and name, if any, of the object.

You will probably also want to know the type of a block at some point.  You can retrieve this with the NiObject::GetType() function.  This returns a reference to the Type value that uniquly identifies this class.  You can get its name by calling the Type::GetTypeName() function.

<center>\ref intro_page "<< Previous Section"</center>

*/

}
#endif
