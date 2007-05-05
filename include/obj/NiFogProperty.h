/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIFOGPROPERTY_H_
#define _NIFOGPROPERTY_H_

#include "NiProperty.h"
namespace Niflib {


//#include "../gen/obj_defines.h"

class NiFogProperty;
typedef Ref<NiFogProperty> NiFogPropertyRef;

/*!
 * NiFogProperty - Describes... fog?
 */

class NiFogProperty : public NI_FOG_PROPERTY_PARENT {
public:
	NIFLIB_API NiFogProperty();
	NIFLIB_API ~NiFogProperty();
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
	 * \param[in] n The new flag data.  Will overwrite any existing flag data.
	 */
	NIFLIB_API void SetFlags( unsigned short n );

	/*!
	 * Used to get the current distance when fog begins to appear, also known as fog density.
	 * \return The current fog depth.
	 */
	NIFLIB_API float GetFogDepth() const;

	/*!
	 * Used to set the distance when fog begins to appear, also known as fog density.
	 * \param[in] value The new fog depth.
	 */
	NIFLIB_API void SetFogDepth(float value);

	/*!
	 * Used to get the current color of the fog.
	 * \return The current fog color.
	 */
	NIFLIB_API Color3 GetFogColor() const;

	/*!
	 * Used to set the color of the fog.
	 * \param[in] value The new fog color.
	 */
	NIFLIB_API void SetFogColor(Color3 value);

protected:
	NI_FOG_PROPERTY_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
