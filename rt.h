/*
 * Interface for the core raytracer API.
 *
 * Refer to raytracer.h and scene.h for the available types and functions.
 *
 * To use the raytracer library, the user must #include this file in their
 * source code and statically link the rt library during linkage. The rt library
 * is attained by running make (no argument, default target); this creates the
 * file librt.a.
 *
 * In summary, to use this API in their code, the user needs these files in
 * their project:
 * - rt.h
 * - raytracer.h
 * - scene.h
 * - librt.a
 * As rt.h #includes raytracer.h and scene.h, only rt.h needs to be directly
 * #include'd.
 *
 * Alternatively, the user may discard rt.h altogether and directly #include
 * both raytracer.h and scene.h, as rt.h doesn't introduce any new content.
 */

#ifndef RT_H
#define RT_H

#include "raytracer.h"
#include "scene.h"

#endif
