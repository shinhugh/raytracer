/*
 * Refer to rt_scene.h for details.
 */

#include "rt_scene.h"

// ------------------------------------------------------------

void RT_Scene::addElement(RT_Shape shape) {

  this->shapes.push_back(shape);

}

// ------------------------------------------------------------

void RT_Scene::addElement(RT_Light light) {

  this->lights.push_back(light);

}
