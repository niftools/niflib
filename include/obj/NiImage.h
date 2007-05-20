/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _NIIMAGE_H_
#define _NIIMAGE_H_

#include "NiObject.h"
namespace Niflib {


//#include "../gen/obj_defines.h"

class NiImage;
class NiRawImageData;
typedef Ref<NiImage> NiImageRef;

/*!
 * NiImage -
 */

class NiImage : public NI_IMAGE_PARENT {
public:
	NIFLIB_API NiImage();
	NIFLIB_API ~NiImage();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	//--BEGIN MISC CUSTOM CODE--//

	/*!
	 * Sets a new external file texture.  Removes any existing texture references.
	 * \param[in] file_name The file name of the new external texture.  Often needs to follow game guidlines to be found.
	 */
	NIFLIB_API void SetTextureFileName( string file_name );

	/*!
	 * Returns the external texture file name.
	 * \return The name of the texture file.
	 */
	NIFLIB_API string GetTextureFileName() const;

	//--END CUSTOM CODE--//

protected:
	NI_IMAGE_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
