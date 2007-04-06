/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

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
	NIFLIB_API static const Type & TypeConst();
private:	
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	enum BlendMode {
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

	enum TestMode {
	  TM_ALWAYS = 0x00,
	  TM_LESS = 0x01,
	  TM_EQUAL = 0x02,
	  TM_LEQUAL = 0x03,
	  TM_GREATER = 0x04,
	  TM_NOTEQUAL = 0x05,
	  TM_GEQUAL = 0x06,
	  TM_NEVER = 0x07,
	};

	NIFLIB_API BlendMode GetSourceBlendMode() const;
	NIFLIB_API void SetSourceBlendMode(BlendMode value);

	NIFLIB_API BlendMode GetDestBlendMode() const;
	NIFLIB_API void SetDestBlendMode(BlendMode value);

	NIFLIB_API TestMode GetTestMode() const;
	NIFLIB_API void SetTestMode(TestMode value);

	NIFLIB_API bool GetAlphaBlend() const;
	NIFLIB_API void SetAlphaBlend(bool value);

	NIFLIB_API bool GetAlphaTest() const;
	NIFLIB_API void SetAlphaTest(bool value);

	NIFLIB_API bool GetAlphaSort() const;
	NIFLIB_API void SetAlphaSort(bool value);

	NIFLIB_API unsigned short GetFlags() const;
	NIFLIB_API void SetFlags( unsigned short n );

	NIFLIB_API byte GetAlphaTestThreshold() const;
	NIFLIB_API void SetAlphaTestThreshold( byte n );
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
