/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _NIALPHAPROPERTY_H_
#define _NIALPHAPROPERTY_H_

#include "NiProperty.h"
namespace Niflib {

//#include "../gen/obj_defines.h"

class NiAlphaProperty;
typedef Ref<NiAlphaProperty> NiAlphaPropertyRef;

/*!
 * NiAlphaProperty - Transparency. Flags 0x00ED.
 */

class NiAlphaProperty : public NI_ALPHA_PROPERTY_PARENT {
public:
	NIFLIB_API NiAlphaProperty();
	NIFLIB_API ~NiAlphaProperty();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*! Used to specify the source and destination blending functions.  The function of each value is equivalent to the OpenGL blending function of similar name. */
	enum BlendFunc {
		BF_ONE = 0x00, 
		BF_ZERO = 0x01,
		BF_SRC_COLOR = 0x02,
		BF_ONE_MINUS_SRC_COLOR = 0x03,
		BF_DST_COLOR = 0x04,
		BF_ONE_MINUS_DST_COLOR = 0x05,
		BF_SRC_ALPHA = 0x06,
		BF_ONE_MINUS_SRC_ALPHA = 0x07,
		BF_DST_ALPHA = 0x08,
		BF_ONE_MINUS_DST_ALPHA = 0x08,
		BF_SRC_ALPHA_SATURATE = 0x09,
	};

	/*! Used to set the alpha test function.  The function of each value is equivalent to the OpenGL test function of similar name. */
	enum TestFunc {
		TF_ALWAYS = 0x00,
		TF_LESS = 0x01,
		TF_EQUAL = 0x02,
		TF_LEQUAL = 0x03,
		TF_GREATER = 0x04,
		TF_NOTEQUAL = 0x05,
		TF_GEQUAL = 0x06,
		TF_NEVER = 0x07,
	};

	/*!
	 * Used to get the current alpha blending state.  If alpha blending is turned on, the blending functions will be used to mix the values based on the alpha component of each pixel in the texture.
	 * \return True if alpha blending is enabled, false otherwise.
	 */
	NIFLIB_API bool GetBlendState() const;

	/*!
	 * Used to set the alpha blending state.  If alpha blending is turned on, the blending functions will be used to mix the values based on the alpha component of each pixel in the texture.
	 * \param[in] value True to enable alpha blending, false to disable it.
	 */
	NIFLIB_API void SetBlendState(bool value);


	/*!
	 * Used to get the current source blend function which determines how alpha blending occurs if it is enabled.
	 * \return The current soucre blend function.
	 */
	NIFLIB_API BlendFunc GetSourceBlendFunc() const;

	/*!
	 * Used to set the source blend function which determines how alpha blending occurs if it is enabled.
	 * \param[in] value The new soucre blend function.
	 */
	NIFLIB_API void SetSourceBlendFunc(BlendFunc value);

	/*!
	 * Used to get the current destination blend function which determines how alpha blending occurs if it is enabled.
	 * \return The current destination blend function.
	 */
	NIFLIB_API BlendFunc GetDestBlendFunc() const;

	/*!
	 * Used to set the destination blend function which determines how alpha blending occurs if it is enabled.
	 * \param[in] value The new destination blend function.
	 */
	NIFLIB_API void SetDestBlendFunc(BlendFunc value);

	/*!
	 * Used to get the current alpha testing state.  If alpha testing is turned on, the alpha test function will be used to compare each pixel's alpha value to the threshold.  If the function is true, the pixel will be drawn, otherwise it will not.
	 * \return True if alpha testing is enabled, false otherwise.
	 */
	NIFLIB_API bool GetTestState() const;

	/*!
	 * Used to set the alpha testing state.  If alpha testing is turned on, the alpha test function will be used to compare each pixel's alpha value to the threshold.  If the function is true, the pixel will be drawn, otherwise it will not.
	 * \param[in] value True to enable alpha testing, false to disable it.
	 */
	NIFLIB_API void SetTestState(bool value);

	/*!
	 * Used to get the current alpha test function which determines the cut-off alpha value between fully transparent and fully opaque parts of a texture.
	 * \return The current alpha test function.
	 */
	NIFLIB_API TestFunc GetTestFunc() const;

	/*!
	 * Used to set the alpha test function which determines the cut-off alpha value between fully transparent and fully opaque parts of a texture.
	 * \param[in] value The new alpha test function.
	 */
	NIFLIB_API void SetTestFunc(TestFunc value);

	/*!
	 * Used to get the current threshold value that will be used with the alpha test function to determine whether a particular pixel will be drawn.
	 * \return The current alpha test threshold.
	 */
	NIFLIB_API byte GetTestThreshold() const;

	/*!
	 * Used to set the threshold value that will be used with the alpha test function to determine whether a particular pixel will be drawn.
	 * \param[in] n The new alpha test threshold.
	 */
	NIFLIB_API void SetTestThreshold( byte n );

	/*!
	 * Used to get the current triangle sort mode.  If triangle sorting is enabled, the triangles that make up an object will be sorted based on distance, and drawn from farthest away to closest.  This reduces errors when using alpha blending.
	 * \return True if triangles will be sorted, false otherwise.
	 */
	NIFLIB_API bool GetTriangleSortMode() const;

	/*!
	 * Used to set the triangle sort mode.  If triangle sorting is enabled, the triangles that make up an object will be sorted based on distance, and drawn from farthest away to closest.  This reduces errors when using alpha blending.
	 * \param[in] value True to enable triangle sorting, false to disable it.
	 */
	NIFLIB_API void SetTriangleSortMode(bool value);

	/*!
	 * Can be used to get the data stored in the flags field for this object.  It is usually better to call more specific flag-toggle functions if they are availiable.
	 * \return The flag data.
	 */
	NIFLIB_API unsigned short GetFlags() const;

	/*!
	 * Can be used to set the data stored in the flags field for this object.  It is usually better to call more specific flag-toggle functions if they are availiable.
	 * \param[in] n The new flag data.  Will overwrite any existing flag data.
	 */
	NIFLIB_API void SetFlags( unsigned short n );

protected:
	NI_ALPHA_PROPERTY_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
