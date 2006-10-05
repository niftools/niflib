/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISTENCILPROPERTY_H_
#define _NISTENCILPROPERTY_H_

#include "NiProperty.h"
namespace Niflib {


#include "../gen/obj_defines.h"

class NiStencilProperty;
typedef Ref<NiStencilProperty> NiStencilPropertyRef;

/*!
 * NiStencilProperty - Allows control of stencil testing.
 */

class NIFLIB_API NiStencilProperty : public NI_STENCIL_PROPERTY_PARENT {
public:
	NiStencilProperty();
	~NiStencilProperty();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	/*!
	 * Property flags.
	 */
   ushort GetFlags() const;
   void SetFlags(ushort value);

	/*!
	 * Enables or disables the stencil test.
	 */
   bool GetStencilEnabled() const;
   void SetStencilEnabled(bool value);

	/*!
	 * Selects the compare mode function.
	 */
	CompareMode GetStencilFunction() const;
	void SetStencilFunction( CompareMode value );

	/*!
	 * Unknown.  Default is 0.
	 */
   uint GetStencilRef() const;
   void SetStencilRef(uint value);

	/*!
	 * A bit mask. The default is 0xffffffff.
	 */
   uint GetStencilMask() const;
   void SetStencilMask(uint value);

	/*!
	 * Unknown.
	 */
	StencilAction GetFailAction() const;
	void SetFailAction( StencilAction value );

	/*!
	 * Unknown.
	 */
	StencilAction GetZFailAction() const;
	void SetZFailAction( StencilAction  value );

	/*!
	 * Unknown.
	 */
	StencilAction GetPassAction() const;
	void SetPassAction( StencilAction value );

	/*!
	 * Used to enabled double sided faces.
	 */
	FaceDrawMode GetDrawMode() const;
	void SetDrawMode( FaceDrawMode value );

protected:
	NI_STENCIL_PROPERTY_MEMBERS
private:
	void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
