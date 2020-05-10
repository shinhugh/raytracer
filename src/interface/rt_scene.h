/*
 * Configuration for a scene (shapes and lights), which the raytracer routine
 * will use to capture an image.
 *
 * This file holds definitions for the following types:
 * - class RT_Scene
 *
 * Instead of this file, the user should #include rt.h.
 */

#ifndef RT_SCENE_H
#define RT_SCENE_H

#include <vector>
#include "rt_shape.h"

// ------------------------------------------------------------

/*
 * A set of shapes and lights in 3-dimensional space.
 * Feed into the raytracer with a camera configuration to get an RGB grid
 * rendering.
 */
class RT_Scene {

private:

  // Shapes
  std::vector<RT_Shape> shapes;

  // Light sources
  std::vector<RT_Light> lights;

public:

  /*
   * Add a shape to the scene.
   */
  void addElement(RT_Shape shape);

  /*
   * Add a light to the scene.
   */
  void addElement(RT_Light light);

};

// ------------------------------------------------------------

#endif
