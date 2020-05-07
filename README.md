# Raytracer 3-D Modeling API

Model a scene in 3-dimensional space and render a view into an array of RGB
values. Supports point-source/directional lighting, reflections, diffusion,
etc. Written in C++.

A sample program demonstrating usage of the API is also provided.

**This project is currently being rebuilt from scratch.**

## Sample Output

![Sample output](img/sample_output_1.png)

![Sample output](img/sample_output_2.png)

## Get Started

*Coming soon!*

## API

The core C++ API provides:
- Configuration of a scene, stored in a single object
- Raytracing on a scene described by the configuration object
- Creation of an array of RGB tuples, 1 tuple per pixel

Note:
- The API itself does not generate an image file of any sort. It simply
populates an array of the RGB tuples that make up an image, which the user can
filter/render as desired. To see how to render this output into an image file,
refer to the source code for the provided sample program
(`sample_program.cpp`). It is very straightforward, and it contains plenty of
comments.
- Parsing of the scene configuration file is also not part of the core API, but
an implementation is provided to supplement the sample program. If the provided
syntax for the scene configuration file is not desirable, the user may design
their own parser. As long as the `Scene` interface is dealt with correctly,
there should be no issues for the raytracer.

## Sample Program

The provided program, implemented in `sample_program.cpp`, is fairly simple to
understand. It does the following:
1. Parse the sample scene configuration file using functions declared
in `config_parse.h`. This creates an instance of the class `Scene`, which
single-handedly holds all the configuration information that the raytracer
requires as input. `Scene`, as expected, is defined in `scene.h`.
2. Run the raytracer algorithm using the `Scene` object as input. This generates
an array of RGB tuples, where each pixel gets its own tuple. These functions
are declared in `raytracer.h`. This is the core part of the API and is by far
the most computation-heavy.
3. Utilize the FreeImage library to generate and write to disk a .jpg image
file from the RGB array. This is done directly in the main function. The image
should be saved in the same directory as the sample program executable.

## Scene Configuration File

*Coming soon!*

## Multi-threading Support

*Coming soon!*

## External Resources

- Wikipedia - Code for matrix LU decomposition
- FreeImage - Library for translating RGB data into image files
