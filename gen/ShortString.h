/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _SHORTSTRING_H_
#define _SHORTSTRING_H_

#include "NIF_IO.h"

/*!
 * Another string format, for short strings.  Specific to Bethesda-
 * specific header tags.
 */
struct ShortString {
  /*! Default Constructor */
  ShortString();
  /*! Default Destructor */
  ~ShortString();
  /*!
   * The string length.
   */
  byte length;
  /*!
   * The string itself, null terminated (the null terminator is taken into
   * account in the length byte).
   */
  vector<byte > value;
};

#endif
