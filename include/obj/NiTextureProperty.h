/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _NITEXTUREPROPERTY_H_
#define _NITEXTUREPROPERTY_H_

#include "NiProperty.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiImage;

//#include "../gen/obj_defines.h"

class NiTextureProperty;
typedef Ref<NiTextureProperty> NiTexturePropertyRef;

/*!
 * NiTextureProperty -
 */

class NiTextureProperty : public NI_TEXTURE_PROPERTY_PARENT {
public:
	NIFLIB_API NiTextureProperty();
	NIFLIB_API ~NiTextureProperty();
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
	 * Retrieves the image object used by this texture property, if any.
	 * \return The image used by this property, or NULL if there is none.
	 */
	NIFLIB_API Ref<NiImage> GetImage() const;

	/*!
	 * Sets the image object used by this texture property, if any.
	 * \return The new image to be used by this property, or NULL to clear the existing one.
	 */
	NIFLIB_API void SetImage( NiImage * n );

protected:
	NI_TEXTURE_PROPERTY_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
