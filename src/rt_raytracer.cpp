/*
 * Refer to rt_raytracer.h for details.
 */

#include "rt_raytracer.h"
#include "la.h"

// ------------------------------------------------------------

RT_RGB raytrace(const RT_Scene &scene, const RT_Ray &ray) {

  // TODO

  // Mock code
  RT_RGB fake_val;
  fake_val.red = 0;
  fake_val.green = 0;
  fake_val.blue = 0;
  return fake_val;

}

// ------------------------------------------------------------

std::vector<RT_RGB> raytrace(const RT_Scene &scene, const RT_Camera &camera) {

  // TODO

  // Mock code
  RT_RGB fake_val;
  fake_val.red = 0;
  fake_val.green = 0;
  fake_val.blue = 0;
  std::vector<RT_RGB> fake_vec;
  fake_vec.push_back(fake_val);
  return fake_vec;

}
