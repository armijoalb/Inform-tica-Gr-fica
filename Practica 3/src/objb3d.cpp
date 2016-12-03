// Implementación métodos clase Obj3d.

#include "objb3d.h"

// Constructor por defecto.
Basic3dObject::Basic3dObject(){};

// Constructor con parámetros.
Basic3dObject::Basic3dObject(vector<_vertex3f> &v) :vertex(v){}

// Método para hacer la translación.
void Basic3dObject::move_object(const float &x, const float &y, const float &z){

  // Recorremos el vector de vértices, y le vamos sumando a cada componente x, y y z.
  for(unsigned int i=0; i < vertex.size() ; i++){
    vertex[i].x += x;
    vertex[i].y += y;
    vertex[i].z += z;
   }

}


// Función para dibujar los puntos de un objeto.
void Basic3dObject::draw_points(){
  glPointSize(4);
  glBegin(GL_POINTS);


  glColor3f(0,0,0); // Negro.

  for(unsigned int i = 0 ; i < vertex.size(); i++){
    glVertex3f(vertex[i].x,vertex[i].y,vertex[i].z);
  }

  glEnd();
}

void Basic3dObject::setVertex(vector<float> &vert){
  vertex.resize(vert.size()/3);

  for(unsigned int i=0; i < vertex.size(); i++){
    vertex[i].x = vert[3*i];
    vertex[i].y = vert[3*i +1];
    vertex[i].z = vert[3*i +2];
  }
}
