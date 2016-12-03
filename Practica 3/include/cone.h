/*
  Alberto Armijo Ruiz
  3º A GII
  Clase Cone, crea un objeto cono de tamaño unidad.
*/

#ifndef __CONE_H
#define __CONE_H

#include "revolution_object.h"

class Cone{
private:
  vector<_vertex3f> perfil_cono = {_vertex3f(0,0.5,0), _vertex3f(0,-0.5,0), _vertex3f(0.5,-0.5,0)};
  RevolutionObject cone;
public:
  Cone();
  void draw(const _rendering_mode mode);

};

#endif
