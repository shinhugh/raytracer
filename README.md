# Raytracer 3-D Modeling API

Model a scene in 3-dimensional space and render a view into an array of RGB
values.

A sample program demonstrating usage of the API is also provided.

## Get Started

TODO

## API

The core API provides:
- Parsing the scene configuration file
- Raytracing on a scene initialized by the configuration file
- Generating an array of RGB tuples, 1 tuple per pixel

Note that the API itself does not generate an image file of any sort. It simply
populates an array of the RGB tuples that make up an image, which the developer
can filter/render as desired. To see how to render the API's RGB output into an
image file, refer to the provided sample program.

## Sample Program

The provided program simply utilizes the API to:
1. Parse the sample scene configuration file.
2. Run the raytracer algorithm on the scene from the specified viewpoint,
generating an array of RGB tuples. A reflection depth of 2 is used.
3. Utilize the FreeImage library to generate a .jpg image file from the RGB
array.

## Scene Configuration File

TODO
