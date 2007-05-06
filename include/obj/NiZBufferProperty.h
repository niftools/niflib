/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _NIZBUFFERPROPERTY_H_
#define _NIZBUFFERPROPERTY_H_

#include "NiProperty.h"
namespace Niflib {


//#include "../gen/obj_defines.h"

class NiZBufferProperty;
typedef Ref<NiZBufferProperty> NiZBufferPropertyRef;

/*!
 * NiZBufferProperty - This Property controlls the Z buffer (OpenGL:
 * depth buffer).
 */

class NiZBufferProperty : public NI_Z_BUFFER_PROPERTY_PARENT {
public:
	NIFLIB_API NiZBufferProperty();
	NIFLIB_API ~NiZBufferProperty();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Can be used to get the data stored in the flags field for this object.  It is usually better to call more specific flag-toggle functions if they are availiable.
	 * \return The flag data.
	 */
	NIFLIB_API unsigned short GetFlags() const;

	/*!
	 * Can be used to set the data stored in the flags field for this object.  It is usually better to call more specific flag-toggle functions if they are availiable.
	 * \param[in] value The new flag data.  Will overwrite any existing flag data.
	 */
	NIFLIB_API void SetFlags( unsigned short value );

	/*!
	 * Used to get the current depth buffer (Z-Buffer) test function, which determine whether a pixel is drawn based on the value of the depth buffer at the same location.
	 * \return The current depth buffer test function.
	 */
	NIFLIB_API CompareMode GetDepthFunction() const;

	/*!
	 * Used to set the depth buffer (Z-Buffer) test function, which determine whether a pixel is drawn based on the value of the depth buffer at the same location.
	 * \param[in] value The new depth buffer test function.
	 */
	NIFLIB_API void SetDepthFunction(CompareMode value);

protected:
	NI_Z_BUFFER_PROPERTY_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
