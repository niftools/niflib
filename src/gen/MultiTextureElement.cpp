/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#include "../../include/gen/MultiTextureElement.h"
#include "../../include/obj/NiImage.h"
using namespace Niflib;

//Constructor
MultiTextureElement::MultiTextureElement() : hasImage(false), image(NULL), clamp_((TexClampMode)3), filter_((TexFilterMode)2), uvSet_((unsigned int)1), ps2L((unsigned short)0), ps2K((unsigned short)0xFFB5), unknownShort3((short)0) {};

//Copy Constructor
MultiTextureElement::MultiTextureElement( const MultiTextureElement & src ) {
	*this = src;
};

//Copy Operator
MultiTextureElement & MultiTextureElement::operator=( const MultiTextureElement & src ) {
	this->hasImage = src.hasImage;
	this->image = src.image;
	this->clamp_ = src.clamp_;
	this->filter_ = src.filter_;
	this->uvSet_ = src.uvSet_;
	this->ps2L = src.ps2L;
	this->ps2K = src.ps2K;
	this->unknownShort3 = src.unknownShort3;
	return *this;
};

//Destructor
MultiTextureElement::~MultiTextureElement() {};
