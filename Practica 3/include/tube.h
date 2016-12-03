/*
  Alberto Armijo Ruiz
  3º A GII
  Clase tubo, crea un objeto tubo de tamaño unidad.
*/

#ifndef __TUBE_H
#define __TUBE_H

#include "revolution_object.h"

class Tube{
private:
  vector<_vertex3f> perfil_tubo = {_vertex3f(0.5,-0.5,0), _vertex3f(0.5,0.5,0)};
  RevolutionObject tube;
public:
  Tube();
  void draw(const _rendering_mode mode);

};

#endif
