/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _MATERIAL_COLLECTION_H_
#define _MATERIAL_COLLECTION_H_

#include "Ref.h"
#include "gen/enums.h"
#include "dll_export.h"
#include "nif_versions.h"
#include <vector>
#include <string>

namespace Niflib {

using namespace std;

const unsigned int NO_MATERIAL = 0xFFFFFFFF;
const unsigned int NO_TEXTURE = 0xFFFFFFFF;

class MaterialWrapper;
class TextureWrapper;

class NiProperty;
class NiSpecularProperty;
class NiAlphaProperty;
class NiGeometry;
class NiAVObject;
class NiMaterialProperty;
class NiTexturingProperty;
class NiTextureProperty;
class NiMultiTextureProperty;
class NiSourceTexture;
class NiImage;

/*!
 * A helper class used to gather and create material and texturing information
 * in a NIF version independant way.
 */
class MatTexCollection {
public:

	/*
	 * Constructor which optionally allows you to specify the root of a scene
	 * to gather material information from.  This is equivalent to creating the
	 * object and then calling the GatherMaterials function as a separate step.
	 * \param[in] scene_root The root node of the scene to gather material
	 * information from.  If set to NULL (the default) no information will be
	 * gathered.
	 */
	NIFLIB_API MatTexCollection( NiAVObject * scene_root = NULL );

	/*! Destructor */
	NIFLIB_API ~MatTexCollection();

	/*
	 * This function gathers material data from the objects in the scene graph
	 * rooted by the given AV object.  This will create associations between
	 * the material and texturing properties and the objects that use them,
	 * which then can be browsed or searched using the collection's other functions.
	 * \param[in] scene_root The root node of the scene to gather material
	 * information from.
	 */
	NIFLIB_API void GatherMaterials( NiAVObject * scene_root );

	/*!
	 * Clears all materials and textures stored in this collection.
	 */
	NIFLIB_API void Clear();

	/*
	 * Reports the number of materials indexed by this collection.
	 * \return The number of materials for which data have been gathered in this
	 * collection.
	 */
	NIFLIB_API unsigned int GetNumMaterials();

	/*
	 * Retrieves a specific material wrapper by index.  This is a class which
	 * allows the attributes of the material and texturing properties to be
	 * manipulated.
	 * \param[in] index The index of the material wrapper to retrieve.  Must
	 * be less than the number reported by GetNumMaterials.
	 * \return The material wrapper stored at the specified index.
	 */
	NIFLIB_API MaterialWrapper GetMaterial( unsigned int index );

	/*
	 * Reports the number of textures indexed by this collection.
	 * \return The number of textures for which data have been gathered in this
	 * collection.
	 */
	NIFLIB_API unsigned int GetNumTextures();

	/*
	 * Retrieves a specific texture wrapper by index.  This is a class which
	 * allows the attributes of the texture to be manipulated.
	 * \param[in] index The index of the texture wrapper to retrieve.  Must
	 * be less than the number reported by GetNumTextures.
	 * \return The texture wrapper stored at the specified index.
	 */
	NIFLIB_API TextureWrapper GetTexture( unsigned int index );

	/*
	 * Retrieves the texture index of the texture wrapper that encloses the
	 * specified NiSouceTexture, if any.
	 * \param[in] src_tex The NiSourceTexture property to match in the search.
	 * \return The index of the matching texture, or NO_TEXTURE if a match is
	 * not found.
	 */
	NIFLIB_API unsigned int GetTextureIndex( NiSourceTexture * src_tex );

	/*
	 * Retrieves the texture index of the texture wrapper that encloses the
	 * specified NiImage, if any.
	 * \param[in] image The NiImage property to match in the search.
	 * \return The index of the matching texture, or NO_TEXTURE if a match is
	 * not found.
	 */
	NIFLIB_API unsigned int GetTextureIndex( NiImage * image );

	/*!
	 * Creates a new material and adds it to the end of the array of materials
	 * contained in this collection with an internal format matching the version
	 * number specified.
	 * \param[in] version The NIF version to target when creating the underlying NIF
	 * objects that store the texture data.
	 * \return The index of the newly created texture.
	 */
	NIFLIB_API unsigned int CreateTexture( unsigned int version = VER_4_0_0_2 );

	/*
	 * Retrieves the material index of the material that affects a specified
	 * NiAVObject, if any.
	 * \param[in] obj The AV object to find the material index for.
	 * \return The index of the material that affects the specified object or
	 * NO_MATERIAL if no match is found.
	 */
	NIFLIB_API unsigned int GetMaterialIndex( NiAVObject * obj );

	/*
	 * Retrieves the material index of the material that matches the given list
	 * of properties, if any.
	 * \param[in] mat The NiMaterialProperty to match.
	 * \param[in] texing The NiTexturingProperty to match.
	 * \param[in] tex The NiTextureProperty to match.
	 * \param[in] multi The NiMultiTextureProperty to match.
	 * \return The index of the material that matches the specified properties,
	 * or NO_MATERIAL if no match is found.
	 */
	NIFLIB_API unsigned int GetMaterialIndex( NiMaterialProperty * mat, NiTexturingProperty * texing, NiTextureProperty * tex, NiMultiTextureProperty * multi, NiSpecularProperty * spec, NiAlphaProperty * alpha );

	/*
	 * Retrieves the material index of the material that matches the given list
	 * of properties, if any.
	 * \param[in] properties An unsorted list of properties that is thought to contain some related to materials.
	 * \return The index of the material that matches the given properties,
	 * or NO_MATERIAL if no match is found.
	 */
	NIFLIB_API unsigned int GetMaterialIndex( const vector< Ref<NiProperty> > & properties );

	/*
	 * Creates a new material and adds it to the end of the array of materials
	 * contained in this collection.  The type of material data that will
	 * appear in the new material must be specified, and a version number can be
	 * used to determine how the data will be stored in the eventual NIF file.
	 * Note that the multi_tex option is only a suggestion, as later NIF versions
	 * combine the texture and multi-texture data into one NIF object.
	 * \param[in] color Whether or not to include color data in the new
	 * material.
	 * \param[in] texture Whether or not to include base texture data in the
	 * new material.
	 * \param[in] multi_tex Whether or not to include multi-texture data in the
	 * new material.
	 * \param[in] multi_tex Whether or not to include multi-texture data in the
	 * new material.  This is only a suggestion as some NIF versions cannot
	 * separate this from base texture information.
	 * \param[in] specular Whether or not to include specular lighting data in
	 * the new material.
	 * \param[in] translucenty Whether or not to include alpha translucenty
	 * data in the new material.
	 * \param[in] version The NIF version to target when creating the underlying NIF
	 * objects that store the requested types of data.
	 * \return The index of the newly created material.
	 */
	NIFLIB_API unsigned int CreateMaterial( bool color, bool texture, bool multi_tex, bool specular, bool translucenty, unsigned int version = VER_4_0_0_2 );
private:
	/*! The vector of materials that this collection holds. */
	vector<MaterialWrapper> materials;
	/*! The vector of textures that this collection holds. */
	vector<TextureWrapper> textures;
};

class MaterialWrapper {
public:
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN MaterialWrapper( NiMaterialProperty * mat, NiTexturingProperty * texing, NiTextureProperty * tex, NiMultiTextureProperty * multi, NiSpecularProperty * spec, NiAlphaProperty * alpha, MatTexCollection * creator );
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_API ~MaterialWrapper();

	/*!
	 *	Applies the material and texture properties controlled by this wrapper
	 * to the specified AV object.  Note that properties affect any child
	 * objects in the scene graph as well.
	 * \param[in] target The AV object to apply the material and texture
	 * properties to.
	 */
	NIFLIB_API void ApplyToObject( NiAVObject * target );

	/*!
	 * Returns a list of all the properties stored in this material wrapper.
	 * \return All the properties controlled by this wrapper.
	 */
	NIFLIB_API vector< Ref<NiProperty> > GetProperties();

	//--Color Functions--//

	/*!
	 * This function simply returns a reference to the NiMaterialProperty that
	 * this wrapper uses to store color information, if any.  Since all
	 * supported NIF versions currently use the same material property object,
	 * these funtions are not wrapped.
	 * \return The material property that this wrapper uses to store color
	 * information, or NULL if there is no color information stored.
	 */
	NIFLIB_API Ref<NiMaterialProperty> GetColorInfo();

	/*!
	 * This function simply returns a reference to the NiSpecularProperty that
	 * this wrapper uses to store specular information, if any.  Since all
	 * supported NIF versions currently use the same specular property object,
	 * these funtions are not wrapped.
	 * \return The specular property that this wrapper uses to specular
	 * information, or NULL if there is no specular information stored.
	 */
	NIFLIB_API Ref<NiSpecularProperty> GetSpecularInfo();

	/*!
	 * This function simply returns a reference to the NiAlphaProperty that
	 * this wrapper uses to store translucency information, if any.  Since all
	 * supported NIF versions currently use the same alpha property object,
	 * these funtions are not wrapped.
	 * \return The alpha property that this wrapper uses to store translucency
	 * information, or NULL if there is no translucency information stored.
	 */
	NIFLIB_API Ref<NiAlphaProperty> GetTranslucencyInfo();


	//--Texturing Functions--//

	NIFLIB_API bool HasTexture( TexType tex );

	/*
	 * Retrieves the texture index of the texture that is used by the specified
	 * texture slot.
	 * \param[in] slot The type of texture slot to get the texture index of.
	 * \return The index of the texture used by the specified material at the
	 * given slot, or NO_TEXTURE if no match is found.
	 */
	NIFLIB_API unsigned int GetTextureIndex( TexType slot );

	NIFLIB_API void SetTextureIndex( TexType slot, unsigned int tex_index );

	NIFLIB_API unsigned int GetTexUVSetIndex( TexType tex );

	NIFLIB_API void SetTexUVSetIndex( TexType tex, unsigned int uv_set );

	NIFLIB_API TexClampMode GetTexClampMode( TexType tex );

	NIFLIB_API void SetTexClampMode( TexType tex, TexClampMode mode );

	NIFLIB_API TexFilterMode GetTexFilterMode( TexType tex );

	NIFLIB_API void SetTexFilterMode( TexType tex, TexFilterMode mode );

private:
	friend class MatTexCollection;

	/*! The NiMaterialProperty that this object wraps, if any. */
	Ref<NiMaterialProperty> mat_prop;
	/*! The NiTexturingProperty that this object wraps, if any. */
	Ref<NiTexturingProperty> texing_prop;
	/*! The NiTextureProperty that this object wraps, if any. */
	Ref<NiTextureProperty> tex_prop;
	/*! The NiMultiTextureProperty that this object wraps, if any. */
	Ref<NiMultiTextureProperty> multi_prop;
	/*! The NiSpecularProperty that this object wraps, if any. */
	Ref<NiSpecularProperty> spec_prop;
	/*! The NiAlphaProperty that this object wraps, if any. */
	Ref<NiAlphaProperty> alpha_prop;
	/*! A pointer back to the MatTexCollection that created this wrapper */
	MatTexCollection * _creator;
};

class TextureWrapper {
public:
	NIFLIB_HIDDEN TextureWrapper( NiSourceTexture * src );
	NIFLIB_HIDDEN TextureWrapper( NiImage * img );
	NIFLIB_API ~TextureWrapper();

	NIFLIB_API bool IsTextureExternal();

	NIFLIB_API string GetTextureFileName();

	NIFLIB_API void SetExternalTexture( const string & file_name );

	NIFLIB_API PixelLayout GetPixelLayout();

	NIFLIB_API void SetPixelLayout( PixelLayout layout );

	NIFLIB_API MipMapFormat GetMipMapFormat();

	NIFLIB_API void SetMipMapFormat( MipMapFormat format );

	NIFLIB_API AlphaFormat GetAlphaFormat();

	NIFLIB_API void SetAlphaFormat( AlphaFormat format );

	NIFLIB_API string GetObjectName();

	NIFLIB_API void SetObjectName( const string & name );

private:
	friend class MatTexCollection;
	friend class MaterialWrapper;

	/*! The NiSourceTexture that this object wraps, if any. */
	Ref<NiSourceTexture> src_tex;
	/*! The NiImage that this object wraps, if any. */
	Ref<NiImage> image;
};

} //End namspace Niflib

#endif