/*
 * Sample program demonstrating straightforward usage of the raytracer API.
 */

#include <vector>
#include <string>
#include <iostream>
#include "rt.h"
#include "config_parse.h"
#include "FreeImagePlus.h"

// Render dimensions in pixels
#define PX_WIDTH 1920
#define PX_HEIGHT 1080
// Number of pixels used to describe color for a single pixel (8, 8, 8)
#define BIT_DEPTH 24


int main(int argc, char **argv) {

  std::cout << "Starting raytracer program.\n";

  // ------------------------------------------------------------

  // Parse scene configuration file and set parameters for raytracing

  std::cout << "Parsing configuration file...";

  // TODO

  RT_Scene scene();
  RT_Camera camera;

  std::cout << " Complete.\n";

  // ------------------------------------------------------------

  // Run raytracer algorithm on scene to generate array of RGB tuples for pixels

  std::cout << "Running raytracer algorithm on scene...";

  std::vector<RT_RGB> render = raytrace(scene, camera);

  std::cout << " Complete.\n";

  // ------------------------------------------------------------

  // Use FreeImage library to generate a .png file using the RGB array

  std::cout << "Generating image file...";

  unsigned char *rgb_array = new unsigned char[3 * render.size()];
  for(unsigned int i = 0; i < render.size(); i++) {
    // Little endian ordering (BGR)
    rgb_array[3 * i] = render.at(i).blue;
    rgb_array[3 * i + 1] = render.at(i).green;
    rgb_array[3 * i + 2] = render.at(i).red;
  }
  FreeImage_Initialise();
  FIBITMAP* bitmap = FreeImage_ConvertFromRawBits(rgb_array, PX_WIDTH,
  PX_HEIGHT, PX_WIDTH * 3, BIT_DEPTH, 0, 0, 0, true);
  std::string filename("render_sample.png");
  FreeImage_Save(FIF_PNG, bitmap, filename.c_str(), 0);
  FreeImage_Unload(bitmap);
  FreeImage_DeInitialise();
  delete[] rgb_array;

  std::cout << " Complete.\n";

  // ------------------------------------------------------------

  std::cout << "Raytracer program complete.\n";

  return 0;

}
