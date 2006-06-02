/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _QUATERNIONXYZW_H_
#define _QUATERNIONXYZW_H_

#include "NIF_IO.h"

/*!
 * A quaternion as it appears in the havok blocks.
 */
struct QuaternionXYZW {
  /*! Default Constructor */
  QuaternionXYZW();
  /*! Default Destructor */
  ~QuaternionXYZW();
  /*!
   * The x-coordinate.
   */
  float x;
  /*!
   * The y-coordinate.
   */
  float y;
  /*!
   * The z-coordinate.
   */
  float z;
  /*!
   * The w-coordinate.
   */
  float w;
};

#endif
