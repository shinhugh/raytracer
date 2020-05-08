/*
 * Interface for the core raytracer API
 *
 * This file does not introduce new content. It simply provides an easy way
 * for the user to attain an interface to the entire core API.
 *
 * To see details on all types and functions, refer to the other header files.
 *
 * ------------------------------------------------------------
 *
 * rt_shape.h defines the following:
 * - abstract class RT_Shape
 *
 * ------------------------------------------------------------
 *
 * rt_triangle.h defines the following:
 * - class RT_Triangle
 *
 * ------------------------------------------------------------
 *
 * rt_sphere.h defines the following:
 * - class RT_Sphere
 *
 * ------------------------------------------------------------
 *
 * rt_scene.h defines the following:
 * - class RT_Scene
 *
 * ------------------------------------------------------------
 *
 * rt_raytracer.h defines the following:
 * - struct RT_RGB
 * - struct RT_Ray
 * - struct RT_Camera
 * - RT_RGB raytrace(RT_Scene, RT_Ray)
 * - vector<RT_RGB> raytrace(RT_Scene, RT_Camera)
 *
 * ------------------------------------------------------------
 *
 * To use the raytracer library, all of the following conditions must apply:
 * - The following line must be in the user's source code, before the library
 *   is used:
 *     #include "rt.h"
 * - The following files must exist in the user's project:
 *   - rt.h
 *   - rt_shape.h
 *   - rt_triangle.h
 *   - rt_sphere.h
 *   - rt_scene.h
 *   - rt_raytracer.h
 *   - librt.a
 * - The user must provide the C++ compiler the path of the header files'
 *   containing directory with the option "-I [path]".
 * - The user must provide the C++ linker the path of the static library file's
 *   containing directory with the option "-L [path]".
 * - The user must link the static library during linkage with the option
 *   "-l rt".
 */

#ifndef RT_H
#define RT_H

#include "rt_scene.h"
#include "rt_raytracer.h"

#endif
