/*
 * A subclass of the class RT_Light, providing directional lights without a
 * source location.
 *
 * This file holds definitions for the following types:
 * - class RT_Light_Dir
 *
 * Instead of this file, the user should #include rt.h.
 */

#ifndef RT_LIGHT_DIR_H
#define RT_LIGHT_DIR_H

#include "rt_light.h"

// ------------------------------------------------------------

/*
 * A scene-wide directional light source, shining light on the entire
 * 3-dimensional space from an unspecified source beyond the scene.
 */
class RT_Light_Dir : public RT_Light {

private:

  // TODO

public:

  /*
   * Constructor
   */
  RT_Light_Dir(); // TODO

  // TODO

};

// ------------------------------------------------------------

#endif
