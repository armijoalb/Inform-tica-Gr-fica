/*
  Alberto Armijo Ruiz
  3º A GII
  Clase cilindro, crea un objeto cilindro de tamaño unidad.
*/

#ifndef __CILINDER_H
#define __CILINDER_H

#include "revolution_object.h"

class Cilinder{
private:
  vector<_vertex3f> perfil_cilindro = {_vertex3f(0,0.5,0),_vertex3f(0,-0.5,0), _vertex3f(0.5,-0.5,0), _vertex3f(0.5,0.5,0)};
  RevolutionObject cilinder;

public:
  Cilinder();
  void draw(const _rendering_mode mode);
};

#endif
