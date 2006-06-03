/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _FURNITUREPOSITION_H_
#define _FURNITUREPOSITION_H_

#include "NIF_IO.h"


/*!
 * Describes a furniture position?
 */
struct FurniturePosition {
  /*! Default Constructor */
  FurniturePosition();
  /*! Default Destructor */
  ~FurniturePosition();
  /*!
   * Unknown. Position?
   */
  Vector3 unknownVector;
  /*!
   * Unknown.
   */
  ushort unknownShort;
  /*!
   * This might refer to a furnituremarkerxx.nif file.
   */
  byte positionRef1_;
  /*!
   * This might also refer to a furnituremarkerxx.nif file.
   */
  byte positionRef2_;
};

#endif
