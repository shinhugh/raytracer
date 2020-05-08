/*
 * A generic shape in a raytracer scene.
 *
 * This file holds definitions for the following types:
 * - abstract class RT_Shape
 *
 * Instead of this file, the user should #include rt.h.
 */

#ifndef RT_SHAPE_H
#define RT_SHAPE_H

// ------------------------------------------------------------

/*
 * A generic shape in 3-dimensional space.
 * This is an abstract class; only its subclasses can be instantiated.
 */
class RT_Shape {

protected:

  // TODO

public:

  /*
   *
   */
  virtual bool checkRayCollision() = 0; // TODO

  // TODO

};

// ------------------------------------------------------------

#endif
