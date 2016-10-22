/*
  Alberto Armijo Ruiz
  3º GII A.
  Objeto 3D.
  Contiene la clase Object3d, que contiene el modelo de triángulos del objeto 3d y
  los métodos necesarios para representarlos con líneas, sólido y ajedrez.
  Esta clase hereda de la clase Basic3dObject, para utilizar la estructura que contiene
  los puntos del objeto 3d.
*/


#ifndef _OBJ3D_H
#define _OBJ3D_H

#include "objb3d.h"
#include "file_ply_stl.h"

class Object3d : public Basic3dObject {
protected:
  vector<_vertex3ui> triangles;
public:
  Object3d();
  Object3d(vector<_vertex3f> &v, vector<_vertex3ui> &t);
  Object3d(char * file_name);
  Object3d(vector<_vertex3f> &v);

  void draw_edges();
  void draw_solid();
  void draw_solid_chess();
  void draw_points_edges_solid();
  void setTriangles(vector<int> &faces);

};


#endif
