/*
 * Sample program demonstrating straightforward usage of the raytracer API.
 */

#include <iostream>
#include "rt.h"
#include "config_parse.h"


int main(int argc, char **argv) {

  std::cout << "Starting raytracer program.\n";

  // ------------------------------------------------------------

  // Parse scene configuration file and set parameters for raytracing

  std::cout << "Parsing configuration file...";

  // TODO

  RT_Scene scene();
  RT_Camera camera();

  std::cout << " Complete.\n";

  // ------------------------------------------------------------

  // Run raytracer algorithm on scene to generate array of RGB tuples for pixels

  std::cout << "Running raytracer algorithm on scene...";

  std::vector<RT_RGB> render = raytrace(scene, camera);

  std::cout << " Complete.\n";

  // ------------------------------------------------------------

  // Use FreeImage library to generate a .png file using the RGB array

  std::cout << "Generating image file...";

  // TODO

  std::cout << " Complete.\n";

  // ------------------------------------------------------------

  std::cout << "Raytracer program complete.\n";

  return 0;

}
