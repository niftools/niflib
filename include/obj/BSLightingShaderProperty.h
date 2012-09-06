/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#ifndef _BSLIGHTINGSHADERPROPERTY_H_
#define _BSLIGHTINGSHADERPROPERTY_H_

//--BEGIN FILE HEAD CUSTOM CODE--//

//--END CUSTOM CODE--//

#include "NiProperty.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class BSShaderTextureSet;
class BSLightingShaderProperty;
typedef Ref<BSLightingShaderProperty> BSLightingShaderPropertyRef;

/*! Skyrim PP shader for assigning material/shader/texture. */
class BSLightingShaderProperty : public NiProperty {
public:
	/*! Constructor */
	NIFLIB_API BSLightingShaderProperty();

	/*! Destructor */
	NIFLIB_API virtual ~BSLightingShaderProperty();

	/*!
	 * A constant value which uniquly identifies objects of this type.
	 */
	NIFLIB_API static const Type TYPE;

	/*!
	 * A factory function used during file reading to create an instance of this type of object.
	 * \return A pointer to a newly allocated instance of this type of object.
	 */
	NIFLIB_API static NiObject * Create();

	/*!
	 * Summarizes the information contained in this object in English.
	 * \param[in] verbose Determines whether or not detailed information about large areas of data will be printed out.
	 * \return A string containing a summary of the information within the object in English.  This is the function that Niflyze calls to generate its analysis, so the output is the same.
	 */
	NIFLIB_API virtual string asString( bool verbose = false ) const;

	/*!
	 * Used to determine the type of a particular instance of this object.
	 * \return The type constant for the actual type of the object.
	 */
	NIFLIB_API virtual const Type & GetType() const;

	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
protected:
	/*! Skyrim Shader Flags for setting render/shader options. */
	SkyrimShaderPropertyFlags1 shaderFlags1;
	/*! Skyrim Shader Flags for setting render/shader options. */
	SkyrimShaderPropertyFlags2 shaderFlags2;
	/*! Offset UVs */
	TexCoord uvOffset;
	/*! Offset UV Scale to repeat tiling textures, see above. */
	TexCoord uvScale;
	/*! Texture Set, can have override in an esm/esp */
	Ref<BSShaderTextureSet > textureSet;
	/*! Glow color and alpha */
	Color3 emissiveColor;
	/*! Multiplied emissive colors */
	float emissiveMultiple;
	/*! How to handle texture borders. */
	TexClampMode textureClampMode;
	/*! The materials opacity (1=non-transparent). */
	float alpha;
	/*! Unknown */
	float unknownFloat2;
	/*! The material's glossiness. (0-999) */
	float specularPower_Glossiness;
	/*! Adds a colored highlight. */
	Color3 specularColor;
	/*! Brightness of specular highlight. (0=not visible) (0-999) */
	float specularStrength;
	/*! Controls strength for envmap/backlight/rim/softlight lighting effect? */
	float lightingEffect1;
	/*! Controls strength for envmap/backlight/rim/softlight lighting effect? */
	float lightingEffect2;
	/*! Scales the environment/cube map. (0-??) */
	float environmentMapScale;
	/*! Tints the base texture. Overridden by game settings. */
	Color3 skinTintColor;
	/*! Tints the base texture. Overridden by game settings. */
	Color3 hairTintColor;
	/*! Max Passes */
	float maxPasses;
	/*! Scale */
	float scale;
	/*! How far from the surface the inner layer appears to be. */
	float parallaxInnerLayerThickness;
	/*! Depth of inner parallax layer effect. */
	float parallaxRefractionScale;
	/*! Scales the inner parallax layer texture. */
	TexCoord parallaxInnerLayerTextureScale;
	/*! How strong the environment/cube map is. (0-??) */
	float parallaxEnvmapStrength;
	/*! Unknown/unused?  CK lists "snow material" when used. */
	Vector4 sparkleParamaters;
	/*! Eye cubemap scale */
	float eyeCubemapScale;
	/*! Offset to set center for left eye cubemap */
	Vector3 leftEyeReflectionCenter;
	/*! Offset to set center for right eye cubemap */
	Vector3 rightEyeReflectionCenter;
public:
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const;
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info );
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual list<NiObject *> GetPtrs() const;
};

//--BEGIN FILE FOOT CUSTOM CODE--//

//--END CUSTOM CODE--//

} //End Niflib namespace
#endif
