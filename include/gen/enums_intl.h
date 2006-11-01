/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */
#ifndef _NIF_ENUMS_INTL_H_
#define _NIF_ENUMS_INTL_H_

#include <iostream>
using namespace std;

#include "../nif_basic_types.h"

namespace Niflib {


//---ForceType---//

void NifStream( ForceType & val, istream& in, uint version = 0 );
void NifStream( ForceType const & val, ostream& out, uint version = 0  );


//---HavokMaterial---//

void NifStream( HavokMaterial & val, istream& in, uint version = 0 );
void NifStream( HavokMaterial const & val, ostream& out, uint version = 0  );


//---CompareMode---//

void NifStream( CompareMode & val, istream& in, uint version = 0 );
void NifStream( CompareMode const & val, ostream& out, uint version = 0  );


//---TexFilterMode---//

void NifStream( TexFilterMode & val, istream& in, uint version = 0 );
void NifStream( TexFilterMode const & val, ostream& out, uint version = 0  );


//---LightMode---//

void NifStream( LightMode & val, istream& in, uint version = 0 );
void NifStream( LightMode const & val, ostream& out, uint version = 0  );


//---MipMapFormat---//

void NifStream( MipMapFormat & val, istream& in, uint version = 0 );
void NifStream( MipMapFormat const & val, ostream& out, uint version = 0  );


//---StencilAction---//

void NifStream( StencilAction & val, istream& in, uint version = 0 );
void NifStream( StencilAction const & val, ostream& out, uint version = 0  );


//---OblivionLayer---//

void NifStream( OblivionLayer & val, istream& in, uint version = 0 );
void NifStream( OblivionLayer const & val, ostream& out, uint version = 0  );


//---FaceDrawMode---//

void NifStream( FaceDrawMode & val, istream& in, uint version = 0 );
void NifStream( FaceDrawMode const & val, ostream& out, uint version = 0  );


//---AlphaFormat---//

void NifStream( AlphaFormat & val, istream& in, uint version = 0 );
void NifStream( AlphaFormat const & val, ostream& out, uint version = 0  );


//---KeyType---//

void NifStream( KeyType & val, istream& in, uint version = 0 );
void NifStream( KeyType const & val, ostream& out, uint version = 0  );


//---VertMode---//

void NifStream( VertMode & val, istream& in, uint version = 0 );
void NifStream( VertMode const & val, ostream& out, uint version = 0  );


//---ApplyMode---//

void NifStream( ApplyMode & val, istream& in, uint version = 0 );
void NifStream( ApplyMode const & val, ostream& out, uint version = 0  );


//---MotionSystem---//

void NifStream( MotionSystem & val, istream& in, uint version = 0 );
void NifStream( MotionSystem const & val, ostream& out, uint version = 0  );


//---BillboardMode---//

void NifStream( BillboardMode & val, istream& in, uint version = 0 );
void NifStream( BillboardMode const & val, ostream& out, uint version = 0  );


//---TexType---//

void NifStream( TexType & val, istream& in, uint version = 0 );
void NifStream( TexType const & val, ostream& out, uint version = 0  );


//---PixelLayout---//

void NifStream( PixelLayout & val, istream& in, uint version = 0 );
void NifStream( PixelLayout const & val, ostream& out, uint version = 0  );


//---TexClampMode---//

void NifStream( TexClampMode & val, istream& in, uint version = 0 );
void NifStream( TexClampMode const & val, ostream& out, uint version = 0  );


//---MotionQuality---//

void NifStream( MotionQuality & val, istream& in, uint version = 0 );
void NifStream( MotionQuality const & val, ostream& out, uint version = 0  );


//---PixelFormat---//

void NifStream( PixelFormat & val, istream& in, uint version = 0 );
void NifStream( PixelFormat const & val, ostream& out, uint version = 0  );


//---CycleType---//

void NifStream( CycleType & val, istream& in, uint version = 0 );
void NifStream( CycleType const & val, ostream& out, uint version = 0  );


//---FieldType---//

void NifStream( FieldType & val, istream& in, uint version = 0 );
void NifStream( FieldType const & val, ostream& out, uint version = 0  );

}
#endif
