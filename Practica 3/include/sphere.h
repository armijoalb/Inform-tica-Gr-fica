/*
  Alberto Armijo Ruiz
  3º A GII
  Clase Sphere, crea un objeto esfera de tamaño unidad.
*/

#ifndef __SPHERE_H
#define __SPHERE_H

#include "functions.h"
#include "revolution_object.h"

class Sphere{
private:
  const float radius = 0.5;
  const unsigned int n = 20;
  vector<_vertex3f> perfil_sphere = create_sphere_outline(radius, n);
  RevolutionObject sphere;

public:
  Sphere();
  void draw(const _rendering_mode mode);
};

#endif
