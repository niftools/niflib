/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIFOGPROPERTY_H_
#define _NIFOGPROPERTY_H_

#include "NiProperty.h"
namespace NifLib {


#include "../gen/obj_defines.h"

class NiFogProperty;
typedef Ref<NiFogProperty> NiFogPropertyRef;

/*!
 * NiFogProperty - Describes... fog?
 */

class NIFLIB_API NiFogProperty : public NI_FOG_PROPERTY_PARENT {
public:
	NiFogProperty();
	~NiFogProperty();
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
   void SetFlags( ushort n );
   
   float GetFogDepth() const;
   void SetFogDepth(float value);

   Color3 GetFogColor() const;
   void SetFogColor(Color3 value);

protected:
	NI_FOG_PROPERTY_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
