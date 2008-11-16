/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#include "../../include/gen/AdditionalDataInfo.h"
using namespace Niflib;

//Constructor
AdditionalDataInfo::AdditionalDataInfo() : dataType((int)0), blockSize((int)0), numBlocks((int)0), blockSize2((int)0), blockIndex((int)0), unknownInt1((int)0), unknownByte1((byte)0) {};

//Copy Constructor
AdditionalDataInfo::AdditionalDataInfo( const AdditionalDataInfo & src ) {
	*this = src;
};

//Copy Operator
AdditionalDataInfo & AdditionalDataInfo::operator=( const AdditionalDataInfo & src ) {
	this->dataType = src.dataType;
	this->blockSize = src.blockSize;
	this->numBlocks = src.numBlocks;
	this->blockSize2 = src.blockSize2;
	this->blockIndex = src.blockIndex;
	this->unknownInt1 = src.unknownInt1;
	this->unknownByte1 = src.unknownByte1;
	return *this;
};

//Destructor
AdditionalDataInfo::~AdditionalDataInfo() {};
