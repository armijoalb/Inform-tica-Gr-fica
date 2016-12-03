/*
  Alberto Armijo Ruiz
  3º A GII
  Clase cubo, crea un objeto cubo de tamaño unidad.
*/

#ifndef __CUBE_H
#define __CUBE_H

#include "obj3d.h"

class Cube{
private:
  vector<_vertex3f> v_cube = {_vertex3f(-0.5,0.5,0.5), _vertex3f(0.5,0.5,0.5), _vertex3f(0.5,-0.5,0.5), _vertex3f(-0.5,-0.5,0.5),
  											 _vertex3f(-0.5,0.5,-0.5), _vertex3f(0.5,0.5,-0.5), _vertex3f(0.5,-0.5,-0.5), _vertex3f(-0.5,-0.5,-0.5)};

  vector<_vertex3ui> t_cube ={ _vertex3ui(0,1,2), _vertex3ui(0,2,3),
      												_vertex3ui(1,5,6), _vertex3ui(1,6,2),
      												_vertex3ui(4,5,7), _vertex3ui(5,6,7),
      												_vertex3ui(4,0,3), _vertex3ui(4,3,7),
      												_vertex3ui(3,2,6), _vertex3ui(3,6,7),
      												_vertex3ui(4,5,1), _vertex3ui(4,1,0) };
  Object3d cube;
public:
  Cube();
  void draw(const _rendering_mode mode);
};

#endif
