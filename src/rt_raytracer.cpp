/*
 * Refer to rt_raytracer.h for details.
 */

#include <cmath>
#include "rt_raytracer.h"
#include "la.h"

// ------------------------------------------------------------

RT_RGB raytrace(const RT_Scene &scene, const RT_Ray &ray, RT_RGB background) {

  // TODO

  // Mock code
  RT_RGB fake_val;
  fake_val.red = 0;
  fake_val.green = 255;
  fake_val.blue = 0;
  return fake_val;

}

// ------------------------------------------------------------

std::vector<RT_RGB> raytrace(const RT_Scene &scene, const RT_Camera &camera,
RT_RGB background) {

  // Sequential implementation; no parallelism

  // Generate all rays to deploy for raytracing on scene
  std::vector<RT_Ray> rays;
  for(unsigned int row_idx = 0; row_idx < camera.px_height; row_idx++) {
    for(unsigned int col_idx = 0; col_idx < camera.px_width; col_idx++) {
      // For each pixel, generate a ray
      RT_Ray curr_ray;
      curr_ray.origin_x = camera.origin_x;
      curr_ray.origin_y = camera.origin_y;
      curr_ray.origin_z = camera.origin_z;
      curr_ray.dir_x = ;
      curr_ray.dir_y = ;
      curr_ray.dir_z = ;
      rays.push_back(curr_ray);
    }
  }

  // Rendered RGB tuples
  std::vector<RT_RGB> render;

  // Raytrace with all generated rays
  for(unsigned int ray_idx = 0; ray_idx < rays.size(); ray_idx++) {
    render.push_back(raytrace(scene, rays.at(ray_idx), background));
  }

  // Return render
  return render;

}

// ------------------------------------------------------------

long double proportional_aov(long double aov_a, long double length_a,
long double length_b) {

  return 2 * atan((length_b / length_a) * tan(aov_a / 2));

}
