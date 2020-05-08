/*
 * Parser for raytracer configuration file
 * Take in an open file stream and output an instance of the RT_Scene class,
 * which the raytracer routine will take in to capture an image.
 */

#ifndef CONFIG_PARSE_H
#define CONFIG_PARSE_H

#include "rt_scene.h"

// ------------------------------------------------------------
// Functions

/*
 * Parse an open file stream and initialize a scene's configuration
 */
RT_Scene parseScene(); // TODO

// ------------------------------------------------------------

#endif
