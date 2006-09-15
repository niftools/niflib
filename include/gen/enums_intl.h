/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */
#ifndef _NIF_ENUMS_INTL_H_
#define _NIF_ENUMS_INTL_H_

#include <iostream>
using namespace std;

#include "nif_basic_types.h"

namespace Niflib {

/*!
 * The type of force?  May be more valid values.
 */
void NifStream( ForceType & val, istream& in, uint version = 0 );
void NifStream( ForceType const & val, ostream& out, uint version = 0  );

/*!
 * A material, used by havok shape objects.
 */
void NifStream( HavokMaterial & val, istream& in, uint version = 0 );
void NifStream( HavokMaterial const & val, ostream& out, uint version = 0  );

/*!
 * This enum contains the options for doing z buffer or stecil buffer
 * tests.
 */
void NifStream( CompareMode & val, istream& in, uint version = 0 );
void NifStream( CompareMode const & val, ostream& out, uint version = 0  );

/*!
 * Specifies the availiable texture filter modes.  That is, the way
 * pixels within a texture are blended together when textures are
 * displayed on the screen at a size other than their original
 * dimentions.
 */
void NifStream( TexFilterMode & val, istream& in, uint version = 0 );
void NifStream( TexFilterMode const & val, ostream& out, uint version = 0  );

/*!
 * An unsigned 32-bit integer, describing how vertex colors influence
 * lighting.
 */
void NifStream( LightMode & val, istream& in, uint version = 0 );
void NifStream( LightMode const & val, ostream& out, uint version = 0  );

/*!
 * An unsigned 32-bit integer, describing how mipmaps are handled in a
 * texture.
 */
void NifStream( MipMapFormat & val, istream& in, uint version = 0 );
void NifStream( MipMapFormat const & val, ostream& out, uint version = 0  );

/*!
 * This enum defines the various actions used in conjunction with the
 * stencil buffer.                 For a detailed description of the
 * individual options please refer to the OpenGL docs.
 */
void NifStream( StencilAction & val, istream& in, uint version = 0 );
void NifStream( StencilAction const & val, ostream& out, uint version = 0  );

/*!
 * Sets mesh color in Oblivion Construction Set.  Anything higher than 57
 * is also null.
 */
void NifStream( OblivionLayer & val, istream& in, uint version = 0 );
void NifStream( OblivionLayer const & val, ostream& out, uint version = 0  );

/*!
 * This enum lists the different face culling options.
 */
void NifStream( FaceDrawMode & val, istream& in, uint version = 0 );
void NifStream( FaceDrawMode const & val, ostream& out, uint version = 0  );

/*!
 * An unsigned 32-bit integer, describing how transparency is handled in
 * a texture.
 */
void NifStream( AlphaFormat & val, istream& in, uint version = 0 );
void NifStream( AlphaFormat const & val, ostream& out, uint version = 0  );

/*!
 * The type of animation interpolation (blending) that will be used on
 * the associated key frames.
 */
void NifStream( KeyType & val, istream& in, uint version = 0 );
void NifStream( KeyType const & val, ostream& out, uint version = 0  );

/*!
 * An unsigned 32-bit integer, which describes how to apply vertex
 * colors.
 */
void NifStream( VertMode & val, istream& in, uint version = 0 );
void NifStream( VertMode const & val, ostream& out, uint version = 0  );

/*!
 * An unsigned 32-bit integer, describing the apply mode of a texture.
 */
void NifStream( ApplyMode & val, istream& in, uint version = 0 );
void NifStream( ApplyMode const & val, ostream& out, uint version = 0  );

/*!
 * The motion system. 4 (Box) is used for everything movable. 7
 * (Keyframed) is used on statics and animated stuff.
 * Oblivion's ssg commando reveals even more values:         0: Keyframed
 * 1: Box         2: Sphere         3: Sphere         4: Box         5:
 * Box         6: Keyframed         7: Keyframed         8: Box
 * 9+: Keyframed?
 */
void NifStream( MotionSystem & val, istream& in, uint version = 0 );
void NifStream( MotionSystem const & val, ostream& out, uint version = 0  );

/*!
 * Determines the way the billboard will react to the camera.
 */
void NifStream( BillboardMode & val, istream& in, uint version = 0 );
void NifStream( BillboardMode const & val, ostream& out, uint version = 0  );

/*!
 * The type of texture.
 */
void NifStream( TexType & val, istream& in, uint version = 0 );
void NifStream( TexType const & val, ostream& out, uint version = 0  );

/*!
 * An unsigned 32-bit integer, describing the color depth of a texture.
 */
void NifStream( PixelLayout & val, istream& in, uint version = 0 );
void NifStream( PixelLayout const & val, ostream& out, uint version = 0  );

/*!
 * Specifies the availiable texture clamp modes.  That is, the behavior
 * of pixels outside the range of the texture.
 */
void NifStream( TexClampMode & val, istream& in, uint version = 0 );
void NifStream( TexClampMode const & val, ostream& out, uint version = 0  );

/*!
 * The motion type. Determines quality of motion?
 */
void NifStream( MotionQuality & val, istream& in, uint version = 0 );
void NifStream( MotionQuality const & val, ostream& out, uint version = 0  );

/*!
 * Specifies the pixel format used by the NiPixelData object to store a
 * texture.
 */
void NifStream( PixelFormat & val, istream& in, uint version = 0 );
void NifStream( PixelFormat const & val, ostream& out, uint version = 0  );

/*!
 * The animation cyle behavior.
 */
void NifStream( CycleType & val, istream& in, uint version = 0 );
void NifStream( CycleType const & val, ostream& out, uint version = 0  );

/*!
 * The force field's type.
 */
void NifStream( FieldType & val, istream& in, uint version = 0 );
void NifStream( FieldType const & val, ostream& out, uint version = 0  );

}
#endif
