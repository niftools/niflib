/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISTENCILPROPERTY_H_
#define _NISTENCILPROPERTY_H_

#include "NiProperty.h"

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
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

   ushort GetFlags() const;
   void SetFlags(ushort value);

   bool GetStencilEnabled() const;
   void SetStencilEnabled(bool value);

   uint GetStencilFunction() const;
   void SetStencilFunction(uint value);

   uint GetStencilRef() const;
   void SetStencilRef(uint value);

   uint GetStencilMask() const;
   void SetStencilMask(uint value);

   uint GetFailAction() const;
   void SetFailAction(uint value);

   uint GetZFailAction() const;
   void SetZFailAction(uint value);

   uint GetPassAction() const;
   void SetPassAction(uint value);

   uint GetDrawMode() const;
   void SetDrawMode(uint value);


protected:
	NI_STENCIL_PROPERTY_MEMBERS
};

#endif
