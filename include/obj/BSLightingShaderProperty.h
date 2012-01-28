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

/*!
 * Bethesda-specific node, used in Skyrim to configure material/shader/texture
 * properties.
 */
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

	/*!
	 * Shader flags used by Skyrim
	 * \return The value of the shader flags
	 */
	NIFLIB_API unsigned int getShaderFlags1();

	/*!
	 * Sets the value of the shader flags used by Skyrim
	 * \param[in] The new value of the shader flags
	 */
	NIFLIB_API void setShaderFlags1(unsigned int value);

	/*!
	 * Gets the second set of shader flags used by Skyrim
	 * \return The value of the second set of flags
	 */
	NIFLIB_API unsigned int getShaderFlags2();

	/*!
	 * Sets the value of the second set of skyrim shader flags
	 * \param[in] the value of the second set of flags
	 */
	NIFLIB_API void setShaderFlags2(unsigned int value); 

	/*!
	 * Used to reposition the texture coordinates of the uv's
	 * \return The texture translation the the uv's
	 */
	NIFLIB_API TexCoord getTextureTranslation1();

	/*!
	 * Sets the value of the texture offset of the uv's
	 * \param[in] The new value of the uv offsets
	 */
	NIFLIB_API void setTextureTranslation1(TexCoord value);

	/*!
	 * Used to get the offset of the texture coordinates or uv's
	 * \return The second texture offsets for the uv
	 */
	NIFLIB_API TexCoord getTextureRepeat();

	/*!
	 * Used to set the second texture offsets
	 * \param[in] The second texture offsets
	 */
	NIFLIB_API void setTextureRepeat(TexCoord value);

	/*!
	 * Returns the current texture set used
	 * \return A reference to the texture set
	 */
	NIFLIB_API Ref<BSShaderTextureSet > getTextureSet();

	/*!
	 * Sets the texture set used by this material
	 * \param[in] A reference to the texture set
	 */
	NIFLIB_API void setTextureSet(BSShaderTextureSet * value);

	/*!
	 * Returns the emissive color of the material
	 * \return The emissive color value
	 */
	NIFLIB_API Color3 getEmissiveColor();

	/*!
	 * Sets the emissive color of this material
	 * \param[in] The new emissive color
	 */
	NIFLIB_API void setEmissiveColor(Color3 value);

	/*!
	 * Get the emissive saturation
	 * \return The emissive saturation
	 */
	NIFLIB_API float getEmissiveSaturation();

	/*!
	 * Sets the emissive saturation of the material
	 * \param[in] The new emissive saturation value
	 */
	NIFLIB_API void setEmissiveSaturation(float value);

	/*!
	 * Gets unknown unsigned int7
	 * \return The current value
	 */
	NIFLIB_API unsigned int  getUnkownInt7();

	/*!
	 * Sets the unknown int7 of this material
	 * \param[in] The new value
	 */
	NIFLIB_API void setUnknownInt7(unsigned int value);

	/*!
	 * Get the transparency or "alpha" of this material
	 * \return The current alpha value of the material
	 */
	NIFLIB_API float getAlpha();

	/*!
	 * Sets the transparency or alpha of this material
	 * \param[in] The new alpha value
	 */
	NIFLIB_API void setAlpha(float value);

	/*!
	 * Get the unknown float2 of the material
	 * \return The unknown float2 value
	 */
	NIFLIB_API float getUnknownFloat2();

	/*!
	 * Sets the unknown float2 of the material
	 * \param[in] The new unknown float2 value
	 */
	 NIFLIB_API void setUnknownFloat2(float value);

	/*!
	 * Gets the glossiness of the material
	 * \return The glossiness 
	 */
	NIFLIB_API float getGlossiness();

	/*!
	 * Sets the glossiness of the material
	 * \param[in] The new glossiness value
	 */
	NIFLIB_API void setGlossiness(float value);

	/*!
	 * Gets the specular color of the material
	 * \return The specular color
	 */
	NIFLIB_API Color3 getSpecularColor();

	/*!
	 * Sets the specular color of the material
	 * \param[in] The new specular color 
	 */
	NIFLIB_API void setSpecularColor(Color3 value);

	/*!
	 * Gets the specular strength of the material
	 * \return The specular strength value
	 */
	NIFLIB_API float getSpecularStrength();

	/*!
	 * Sets the specular strength of the material
	 * \param[in] The new specular strength value
	 */
	NIFLIB_API void setSpecularStrength(float value);

	/*!
	 * Gets the lightning effect1 of the material
	 * \return The lightning effect2 value 
	 */
	NIFLIB_API float getLightningEffect1();

	/*!
	 * Sets the lightning effect1 of the material
	 * \param[in] The new lighting effect1 value
	 */
	NIFLIB_API void setLightningEffect1(float value);

	/*!
	 * Gets the lightning effect2 of the material
	 * \return The lightning effect2 value
	 */
	NIFLIB_API float getLightningEffect2();

	/*!
	 * Sets the lightning effect2 of the material
	 * \param[in] The new lighting effect2 of the material
	 */
	NIFLIB_API void setLightningEffect2(float value);

	/*!
	 * Gets the environment map strength of the material
	 * \return The environment map strength
	 */
	NIFLIB_API float getEnvironmentMapStrength();

	/*!
	 * Sets the environment map strength of the material
	 * \param[in] The new environment map strength value
	 */
	NIFLIB_API void setEnvironmentMapStrength(float value);

	/*!
	 * Sets unknown float set3 of the material related to hair
	 * \return The unknown float set3 value
	 */
	NIFLIB_API array<2, float> getUnknownFloatSet3();

	/*!
	 * Sets the unknown float set3 of the material
	 * \param[in] The new unknown float set3 value 
	 */
	NIFLIB_API void setUnknownFloatSet3(array<2, float> value);

	/*!
	 * Gets the unknown float9 of the material
	 * \return The unknown float9 value
	 */
	NIFLIB_API float getUnknownFloat9();

	/*!
	 * Sets the unknown float9 of the material
	 * \param[in] The new unknown float9 value
	 */
	NIFLIB_API void setUnknownFloat9(float value);

	/*!
	 * Gets the unknown color2 of the material
	 * \return The unknown color2 value
	 */
	NIFLIB_API Color4 getUnknownColor2();

	/*!
	 * Sets the unknown color2 of the material
	 * \param[in] The new unknown color2 value
	 */
	NIFLIB_API void setUnknownColor2(Color4 value);

	/*!
	 * Gets the unknown float set5 of the material
	 * \return The unknown float set5 value
	 */
	NIFLIB_API Vector4 getUnknownFloatSet5();

	/*!
	 * Sets the unknown float set5 of the material
	 * \param[in] The new unknown float set5 value
	 */
	NIFLIB_API void setUnknownFloatSet5(Vector4 value);

	/*!
	 * Get the eye cubemap scale
	 * \return The eye cubemap scale value
	 */
	NIFLIB_API float getEyeCubemapScale();

	/*!
	 * Sets the eye cubemap scale
	 * \param[in] The new eye cubemap scale value
	 */
	NIFLIB_API void setEyeCubemapScale(float value);

	/*!
	 * Gets the left eye reflection center
	 * \return The left eye reflection center value
	 */
	NIFLIB_API Vector3 getLeftEyeReflectionCenter();

	/*!
	 * Sets the left eye reflection center
	 * \param[in] The new left eye reflection center value
	 */
	NIFLIB_API void setLeftEyeReflectionCenter(Vector3 value);

	/*!
	 * Get the right eye reflection center
	 * \return The right eye reflection center value
	 */
	NIFLIB_API Vector3 getRightEyeReflectionCenter();

	/*!
	 * Sets the right eye reflection center
	 * \param[in] The new right eye reflection center value
	 */
	NIFLIB_API void setRightEyeReflectionCenter(Vector3 value);

	//--END CUSTOM CODE--//
protected:
	/*! Skyrim Shader Flag field 1 (will use SkyrimLightingShaderFlags1) */
	unsigned int shaderFlags1;
	/*! Skyrim Shader Flag field 2 (will use SkyrimLightingShaderFlags2) */
	unsigned int shaderFlags2;
	/*! Offset UVs */
	TexCoord textureTranslation1;
	/*! Offset UVs */
	TexCoord textureRepeat;
	/*! Texture Set */
	Ref<BSShaderTextureSet > textureSet;
	/*! Glow color and alpha */
	Color3 emissiveColor;
	/*! Unknown */
	float emissiveSaturation;
	/*! Unknown, always 3? */
	unsigned int unknownInt7;
	/*! The material transparency (1=non-transparent). */
	float alpha;
	/*! Unknown */
	float unknownFloat2;
	/*! The material's glossiness. (0-999) */
	float glossiness;
	/*! Adds a colored highlight. */
	Color3 specularColor;
	/*! Brightness of specular highlight. (0=not visible) (0-999) */
	float specularStrength;
	/*! Unknown, related to backlight/rim/softlight effect */
	float lightingEffect1;
	/*! Unknown, related to backlight/rim/softlight effect */
	float lightingEffect2;
	/*! How strong the environment/cube map is. (0-??) */
	float environmentMapStrength;
	/*! Unknown, related to skin */
	Vector3 unknownFloatSet1;
	/*! Unknown, related to hair */
	Color3 unknownColor1;
	/*! Unknown */
	array<2,float > unknownFloatSet3;
	/*! Unknown, related to ice or parallax */
	float unknownFloat9;
	/*! Unknown, related to ice parallax */
	Color4 unknownColor2;
	/*! Unknown, also related to ice? */
	Vector4 unknownFloatSet5;
	/*! Eye(Skyrim) */
	float eyeCubemapScale;
	/*! Eye(Skyrim)Left Unknown */
	Vector3 leftEyeReflectionCenter;
	/*! Eye(Skyrim)Right Unknown */
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
