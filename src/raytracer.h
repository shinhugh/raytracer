/*
 * Raytracer algorithm that generates an array of RGB tuples, one for each pixel
 */

#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <vector>
#include "scene.h"

// ------------------------------------------------------------
// RGB tuple struct definition

typedef struct RGB {
  unsigned int red;
  unsigned int green;
  unsigned int blue;
} RGB;

// ------------------------------------------------------------
// Functions

/*
 * Raytrace on all pixels for a view.
 */
std::vector<RGB> raytrace_all(const Scene &config); // TODO

/*
 * Raytrace a single pixel.
 */
RGB raytrace_pixel(const Scene &config); // TODO

#endif
