######
## Build boost::python wrapper file
######

import os, re
from pyplusplus import module_builder
from pygccxml import declarations

import wrapper_config

# The Niflib license
niflib_license = \
"""/*
Copyright (c) 2005, NIF File Format Library and Tools
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
POSSIBILITY OF SUCH DAMAGE.
*/
"""

####

# Function to get the type name of a template function
def TypeName( decl_string ):
    return declarations.templates.args(decl_string)[0].rsplit('::', 2)[-1]

# Function to rename the Cast<T> functions
def rename_casts( cast ):
    cast.rename( cast.name + 'To' +  TypeName(cast.decl_string) )
    cast.name = cast.demangled_name

# Function to rename the Ref<T> functions
def rename_refs( ref ):
    ref.rename( TypeName(ref.decl_string) + "Ref" )

####

# Creating an instance of class that will help you to expose your declarations
mb = module_builder.module_builder_t( [r"pyNiflib.h"], include_paths = [wrapper_config.niflib_path + '/include', wrapper_config.niflib_path + '/include/gen', wrapper_config.niflib_path + '/include/obj'], indexing_suite_version = 2 )

# Set the max. number of template arguments
mb.BOOST_PYTHON_MAX_ARITY = 20

# Rename the Ref<T> templates
refs = mb.classes ( lambda decl: ( decl.name.startswith('Ref<') ) )
map( rename_refs, refs )

# Rename the DynamicCast<T> and StaticCast<T> templates
casts = mb.free_functions ( lambda decl: ( decl.name == 'DynamicCast' or decl.name == 'StaticCast' ) )
map( rename_casts, casts )

# Get all operators
mb.member_operators().exclude()

# Optimize the queries
mb.run_query_optimizer()

# Exclude everything
mb.global_ns.exclude()

# Include the main Niflib namespace
mb.namespace('Niflib').include()

# Create code creator. After this step you should not modify/customize declarations.
mb.build_code_creator( module_name='pyNiflib' )

# Set the Niflib license for the output
mb.code_creator.license = niflib_license

# Well, don't you want to see what is going on?
mb.print_declarations(mb.namespace('Niflib'))

# Writing code to file.
mb.write_module( './pyNiflib.cpp' )
