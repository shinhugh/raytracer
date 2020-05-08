/*
 * Raytracer algorithm that generates an array of RGB tuples, one for each
 * pixel.
 *
 * This file holds definitions for the following types:
 * - struct RT_RGB
 * - struct RT_Ray
 * - struct RT_Camera
 *
 * This file declares the following functions:
 * - RT_RGB raytrace(RT_Scene, RT_Ray)
 * - vector<RT_RGB> raytrace(RT_Scene, RT_Camera)
 *
 * Instead of this file, the user should #include rt.h.
 */

#ifndef RT_RAYTRACER_H
#define RT_RAYTRACER_H

#include <vector>
#include "rt_scene.h"

// ------------------------------------------------------------

/*
 * Tuple holding color values (red, green, blue) for a pixel.
 */
typedef struct RT_RGB {

  // Strength of each hue
  unsigned int red;
  unsigned int green;
  unsigned int blue;

} RT_RGB;

// ------------------------------------------------------------

/*
 * A ray in 3-dimensional space, specified by a starting point and a direction.
 */
typedef struct RT_Ray {

  // Starting point location
  long double origin_x;
  long double origin_y;
  long double origin_z;

  // Direction
  long double dir_x;
  long double dir_y;
  long double dir_z;

} RT_Ray;

// ------------------------------------------------------------

/*
 * A camera with a location and direction in 3-dimensional space.
 * This contains all the information required by the raytracer that isn't
 * related to the scene itself.
 */
typedef struct RT_Camera {

  // Location and direction of camera
  RT_Ray center_ray;

  // Width of view in pixels
  unsigned int px_width;

  // Height of view in pixels
  unsigned int px_height;

  // Horizontal angle of view
  // Angle between segment from camera to leftmost pixel and segment from camera
  // to rightmost pixel
  // Cap at 120 degrees
  long double view_angle_h;

  // Vertical angle of view
  // Angle between segment from camera to uppermost pixel and segment from
  // camera to bottom pixel
  // Cap at 120 degrees
  long double view_angle_v;

} RT_Camera;

// ------------------------------------------------------------

/*
 * Perform raytracing with a single ray to get a single RGB tuple.
 */
RT_RGB raytrace(const RT_Scene &scene, const RT_Ray &ray);

// ------------------------------------------------------------

/*
 * Perform a full raytracing iteration with a configured camera to get an array
 * of RGB tuples.
 * The returned array is row-major, left-to-right; consecutive tuples represent
 * horizontally neighbor pixels (besides at the row edges).
 */
std::vector<RT_RGB> raytrace(const RT_Scene &scene, const RT_Camera &camera);

// ------------------------------------------------------------

#endif
