/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIALPHAPROPERTY_H_
#define _NIALPHAPROPERTY_H_

#include "NiProperty.h"
namespace NifLib {

#include "../gen/obj_defines.h"

class NiAlphaProperty;
typedef Ref<NiAlphaProperty> NiAlphaPropertyRef;

/*!
 * NiAlphaProperty - Transparency. Flags 0x00ED.
 */

class NIFLIB_API NiAlphaProperty : public NI_ALPHA_PROPERTY_PARENT {
public:
	NiAlphaProperty();
	~NiAlphaProperty();
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

   enum BlendMode
   {
      BM_ONE = 0x00,
      BM_ZERO = 0x01,
      BM_SRC_COLOR = 0x02,
      BM_ONE_MINUS_SRC_COLOR = 0x03,
      BM_DST_COLOR = 0x04,
      BM_ONE_MINUS_DST_COLOR = 0x05,
      BM_SRC_ALPHA = 0x06,
      BM_ONE_MINUS_SRC_ALPHA = 0x07,
      BM_DST_ALPHA = 0x08,
      BM_ONE_MINUS_DST_ALPHA = 0x08,
      BM_SRC_ALPHA_SATURATE = 0x09,
   };

   enum TestMode
   {
      TM_ALWAYS = 0x00,
      TM_LESS = 0x01,
      TM_EQUAL = 0x02,
      TM_LEQUAL = 0x03,
      TM_GREATER = 0x04,
      TM_NOTEQUAL = 0x05,
      TM_GEQUAL = 0x06,
      TM_NEVER = 0x07,
   };

   BlendMode GetSourceBlendMode() const;
   void SetSourceBlendMode(BlendMode value);

   BlendMode GetDestBlendMode() const;
   void SetDestBlendMode(BlendMode value);

   TestMode GetTestMode() const;
   void SetTestMode(TestMode value);

   bool GetAlphaBlend() const;
   void SetAlphaBlend(bool value);

   bool GetAlphaTest() const;
   void SetAlphaTest(bool value);

   bool GetAlphaSort() const;
   void SetAlphaSort(bool value);

	ushort GetFlags() const;
	void SetFlags( ushort n );

	byte GetAlphaTestThreshold() const;
	void SetAlphaTestThreshold( byte n );
protected:
	NI_ALPHA_PROPERTY_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
