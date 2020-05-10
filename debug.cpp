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
// Number of pixels used to describe color for a single pixel (8, 8, 8)
#define BIT_DEPTH 24
// Horizontal angle of view, in radians
#define AOV_H (M_PI / 2)


int main(int argc, char **argv) {

  std::cout << "Starting debug program.\n";

  // ------------------------------------------------------------

  // Generate scene

  std::cout << "Generating scene...";

  // Scene to raytrace on
  RT_Scene scene();

  // Cube made of 12 triangles
  // Floor
  RT_Triangle tri_0(1, 1, 1, 2, 1, 1, 1, 2, 1);
  scene.addElement(tri_0);
  RT_Triangle tri_1(2, 2, 1, 2, 1, 1, 1, 2, 1);
  scene.addElement(tri_1);
  // Roof
  RT_Triangle tri_2(1, 1, 2, 2, 1, 2, 1, 2, 2);
  scene.addElement(tri_2);
  RT_Triangle tri_3(2, 2, 2, 2, 1, 2, 1, 2, 2);
  scene.addElement(tri_3);
  // Front
  RT_Triangle tri_4(1, 1, 1, 2, 1, 1, 1, 1, 2);
  scene.addElement(tri_4);
  RT_Triangle tri_5(2, 1, 2, 2, 1, 1, 1, 1, 2);
  scene.addElement(tri_5);
  // Back
  RT_Triangle tri_6(1, 2, 1, 2, 2, 1, 1, 2, 2);
  scene.addElement(tri_6);
  RT_Triangle tri_7(2, 2, 2, 2, 2, 1, 1, 2, 2);
  scene.addElement(tri_7);
  // Left
  RT_Triangle tri_8(1, 2, 1, 1, 1, 1, 1, 2, 2);
  scene.addElement(tri_8);
  RT_Triangle tri_9(1, 1, 2, 1, 1, 1, 1, 2, 2);
  scene.addElement(tri_9);
  // Right
  RT_Triangle tri_10(2, 2, 1, 2, 1, 1, 2, 2, 2);
  scene.addElement(tri_10);
  RT_Triangle tri_11(2, 1, 2, 2, 1, 1, 2, 2, 2);
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
  RT_Camera camera;
  camera.origin_x = 0;
  camera.origin_y = -4;
  camera.origin_z = 0;
  camera.dir_x = 0;
  camera.dir_y = 1;
  camera.dir_z = 0;
  camera.up_x = 0;
  camera.up_y = 0;
  camera.up_z = 1;
  camera.px_width = PX_WIDTH;
  camera.px_height = PX_HEIGHT;
  camera.px_angle_h = AOV_H;
  camera.px_angle_v = proportional_aov(AOV_H, PX_WIDTH, PX_HEIGHT);

  std::cout << " Complete.\n";

  // ------------------------------------------------------------

  // Run raytracer algorithm on scene to generate array of RGB tuples for pixels

  std::cout << "Running raytracer algorithm on scene...";

  RT_RGB background;
  background.red = 0;
  background.green = 0;
  background.blue = 0;

  std::vector<RT_RGB> render = raytrace(scene, camera, background);

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
