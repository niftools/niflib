/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISTENCILPROPERTY_H_
#define _NISTENCILPROPERTY_H_

#include "NiProperty.h"
namespace Niflib {


//#include "../gen/obj_defines.h"

class NiStencilProperty;
typedef Ref<NiStencilProperty> NiStencilPropertyRef;

/*!
 * NiStencilProperty - Allows control of stencil testing.
 */

class NiStencilProperty : public NI_STENCIL_PROPERTY_PARENT {
public:
	NIFLIB_API NiStencilProperty();
	NIFLIB_API ~NiStencilProperty();
	//Run-Time Type Information
	NIFLIB_API static const Type & TypeConst();
private:
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Property flags.
	 */
	NIFLIB_API unsigned short GetFlags() const;
	NIFLIB_API void SetFlags(unsigned short value);

	/*!
	 * Enables or disables the stencil test.
	 */
	NIFLIB_API bool GetStencilEnabled() const;
	NIFLIB_API void SetStencilEnabled(bool value);

	/*!
	 * Selects the compare mode function.
	 */
	NIFLIB_API CompareMode GetStencilFunction() const;
	NIFLIB_API void SetStencilFunction( CompareMode value );

	/*!
	 * Unknown.  Default is 0.
	 */
	NIFLIB_API unsigned int GetStencilRef() const;
	NIFLIB_API void SetStencilRef(unsigned int value);

	/*!
	 * A bit mask. The default is 0xffffffff.
	 */
	NIFLIB_API unsigned int GetStencilMask() const;
	NIFLIB_API void SetStencilMask(unsigned int value);

	/*!
	 * Unknown.
	 */
	NIFLIB_API StencilAction GetFailAction() const;
	NIFLIB_API void SetFailAction( StencilAction value );

	/*!
	 * Unknown.
	 */
	NIFLIB_API StencilAction GetZFailAction() const;
	NIFLIB_API void SetZFailAction( StencilAction  value );

	/*!
	 * Unknown.
	 */
	NIFLIB_API StencilAction GetPassAction() const;
	NIFLIB_API void SetPassAction( StencilAction value );

	/*!
	 * Used to enabled double sided faces.
	 */
	NIFLIB_API FaceDrawMode GetDrawMode() const;
	NIFLIB_API void SetDrawMode( FaceDrawMode value );

protected:
	NI_STENCIL_PROPERTY_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
