/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _SKINDATA_H_
#define _SKINDATA_H_

#include "NIF_IO.h"
#include "gen/SkinWeight.h"

/*!
 * Skinning data component.
 */
struct SkinData {
  /*! Default Constructor */
  SkinData();
  /*! Default Destructor */
  ~SkinData();
  /*!
   * Rotation offset of the skin from this bone in bind position.
   */
  Matrix33 rotation;
  /*!
   * Translation offset of the skin from this bone in bind position.
   */
  Vector3 translation;
  /*!
   * Scale offset of the skin from this bone in bind position. (Assumption
   * - this is always 1.0 so far)
   */
  float scale;
  /*!
   * This has been verified not to be a normalized quaternion.  They may or
   * may not be related to each other so their specification as an array of
   * 4 floats may be misleading.
   */
  vector<float > unknown4Floats;
  /*!
   * Number of weighted vertices.
   */
  ushort numVertices;
  /*!
   * The vertex weights.
   */
  vector<SkinWeight > vertexWeights;
};

#endif
