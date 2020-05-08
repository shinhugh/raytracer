/*
 * Program written for debugging the API.
 */

#include <vector>
#include <string>
#include <iostream>
#include "rt.h"
#include "FreeImagePlus.h"

// Render dimensions in pixels
#define PX_WIDTH 1920
#define PX_HEIGHT 1080
#define BIT_DEPTH 24


int main(int argc, char **argv) {

  std::cout << "Starting debug program.\n";

  // ------------------------------------------------------------

  // Generate scene

  std::cout << "Generating scene...";

  // Scene to raytrace on
  RT_Scene scene();

  // Cube
  RT_Triangle tri_0();
  scene.addElement(tri_0);
  RT_Triangle tri_1();
  scene.addElement(tri_1);
  RT_Triangle tri_2();
  scene.addElement(tri_2);
  RT_Triangle tri_3();
  scene.addElement(tri_3);
  RT_Triangle tri_4();
  scene.addElement(tri_4);
  RT_Triangle tri_5();
  scene.addElement(tri_5);
  RT_Triangle tri_6();
  scene.addElement(tri_6);
  RT_Triangle tri_7();
  scene.addElement(tri_7);
  RT_Triangle tri_8();
  scene.addElement(tri_8);
  RT_Triangle tri_9();
  scene.addElement(tri_9);
  RT_Triangle tri_10();
  scene.addElement(tri_10);
  RT_Triangle tri_11();
  scene.addElement(tri_11);
/*
  // Sphere
  RT_Sphere sph_0();
  scene.addElement(sph_0);

  // Ellipsoid
  RT_Sphere sph_1();
  scene.addElement(sph_1);
*/
  std::cout << " Complete.\n";

  // ------------------------------------------------------------

  // Configure camera

  std::cout << "Configuring camera...";

  // Camera to raytrace from
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

  /*
  // Custom pattern
  std::vector<RT_RGB> render;
  for(unsigned int i = 0; i < PX_HEIGHT; i++) {
    for(unsigned int j = 0; j < PX_WIDTH; j++) {
      RT_RGB pixel;
      pixel.red = 0;
      pixel.green = 0;
      pixel.blue = 0;
      if((i / 10) % 3 == 0) {
        pixel.red = j % 256;
      } else if((i / 10) % 3 == 1) {
        pixel.green = j % 256;
      } else {
        pixel.blue = j % 256;
      }
      render.push_back(pixel);
    }
  }
  */

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
  std::string filename("render_debug.png");
  FreeImage_Save(FIF_PNG, bitmap, filename.c_str(), 0);
  FreeImage_Unload(bitmap);
  FreeImage_DeInitialise();
  delete[] rgb_array;

  std::cout << " Complete.\n";

  // ------------------------------------------------------------

  std::cout << "Exiting debug program.\n";

  return 0;

}
