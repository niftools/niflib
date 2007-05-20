/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _NIVERTEXCOLORPROPERTY_H_
#define _NIVERTEXCOLORPROPERTY_H_

#include "NiProperty.h"
namespace Niflib {


//#include "../gen/obj_defines.h"

class NiVertexColorProperty;
typedef Ref<NiVertexColorProperty> NiVertexColorPropertyRef;

/*!
 * NiVertexColorProperty - Property of vertex colors. This object is
 * referred to by the root object of the NIF file whenever some
 * NiTriShapeData object has vertex colors with non-default settings; if
 * not present, vertex colors have vertex_mode=2 and lighting_mode=1.
 */

class NiVertexColorProperty : public NI_VERTEX_COLOR_PROPERTY_PARENT {
public:
	NIFLIB_API NiVertexColorProperty();
	NIFLIB_API ~NiVertexColorProperty();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	//--BEGIN MISC CUSTOM CODE--//

	/*!
	 * Can be used to get the data stored in the flags field for this object.  It is usually better to call more specific flag-toggle functions if they are availiable.
	 * \return The flag data.
	 */
	NIFLIB_API unsigned short GetFlags() const;

	/*!
	 * Can be used to set the data stored in the flags field for this object.  It is usually better to call more specific flag-toggle functions if they are availiable.
	 * \param[in] value The new flag data.  Will overwrite any existing flag data.
	 */
	NIFLIB_API void SetFlags(unsigned short value);

	/*!
	 * Gets the current vertex mode.  This seems to specify how to apply vertex colors.
	 * \return The current vertex mode.
	 */
	NIFLIB_API VertMode GetVertexMode() const;

	/*!
	 * Sets the vertex mode.  This seems to specify how to apply vertex colors.
	 * \param[in] value The new vertex mode.
	 */
	NIFLIB_API void SetVertexMode(VertMode value);

	/*!
	 * Gets the current lighting mode.  This seems to specify how vertex colors influence lighting.
	 * \return The current lighting mode.
	 */
	NIFLIB_API LightMode GetLightingMode() const;

	/*!
	 * Sets the lighting mode.  This seems to specify how vertex colors influence lighting.
	 * \param[in] value The new lighting mode.
	 */
	NIFLIB_API void SetLightingMode(LightMode value);

	//--END CUSTOM CODE--//

protected:
	NI_VERTEX_COLOR_PROPERTY_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
