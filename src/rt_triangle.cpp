/*
 * Refer to rt_triangle.h for details.
 */

#include "rt_triangle.h"

RT_Triangle::RT_Triangle(long double pt_1_x, long double pt_1_y,
long double pt_1_z, long double pt_2_x, long double pt_2_y, long double pt_2_z,
long double pt_3_x, long double pt_3_y, long double pt_3_z)
: pt_1_x(pt_1_x), pt_1_y(pt_1_y), pt_1_z(pt_1_z),
pt_1_x(pt_2_x), pt_1_y(pt_2_y), pt_1_z(pt_2_z),
pt_1_x(pt_3_x), pt_1_y(pt_3_y), pt_1_z(pt_3_z)
{}
