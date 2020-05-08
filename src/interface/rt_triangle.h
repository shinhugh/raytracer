/*
 * A subclass of the class RT_Shape, providing triangles to a raytracer scene.
 *
 * This file holds definitions for the following types:
 * - class RT_Triangle
 *
 * Instead of this file, the user should #include rt.h.
 */

#ifndef RT_TRIANGLE_H
#define RT_TRIANGLE_H

#include "rt_shape.h"

// ------------------------------------------------------------

/*
 * A triangle in 3-dimensional space.
 */
class RT_Triangle : public RT_Shape {

private:

  // Point 1's location
  long double pt_1_x;
  long double pt_1_y;
  long double pt_1_z;
  // Point 2's location
  long double pt_2_x;
  long double pt_2_y;
  long double pt_2_z;
  // Point 3's location
  long double pt_3_x;
  long double pt_3_y;
  long double pt_3_z;

public:

  /*
   * Constructor
   * The triangle is specified by the x, y, and z-coordinates for all 3 of
   * its points.
   */
  RT_Triangle(long double pt_1_x, long double pt_1_y, long double pt_1_z,
  long double pt_2_x, long double pt_2_y, long double pt_2_z,
  long double pt_3_x, long double pt_3_y, long double pt_3_z);

  // TODO

};

// ------------------------------------------------------------

#endif
