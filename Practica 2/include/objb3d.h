/*
  Alberto Armijo Ruiz
  3º A GII
  Objeto básico 3D.
  Contiene una clase que el modelo de puntos y la función para dibujar el
  modelo de puntos.
*/

#ifndef _OBJB3D_H
#define _OBJB3D_H

#include "vertex.h"
#include <GL/glut.h>
#include <vector>

class Basic3dObject{
protected:
  vector<_vertex3f> vertex;
public:
  Basic3dObject();
  Basic3dObject(vector<_vertex3f> &v);
  
  void draw_points();
  void move_object(const float &x, const float &y, const float &z);
  void setVertex(vector<float> &vert);

};

#endif
