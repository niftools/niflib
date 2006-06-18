/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIZBUFFERPROPERTY_H_
#define _NIZBUFFERPROPERTY_H_

#include "NiProperty.h"
namespace Niflib {


#include "../gen/obj_defines.h"

class NiZBufferProperty;
typedef Ref<NiZBufferProperty> NiZBufferPropertyRef;

/*!
 * NiZBufferProperty - This Property controlls the Z buffer (OpenGL:
 * depth buffer).
 */

class NIFLIB_API NiZBufferProperty : public NI_Z_BUFFER_PROPERTY_PARENT {
public:
	NiZBufferProperty();
	~NiZBufferProperty();
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

   uint GetFunction() const;
   void SetFunction(uint value);

protected:
	NI_Z_BUFFER_PROPERTY_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
