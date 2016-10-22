// Implementación métodos clase Object3d.

#include "obj3d.h"

// Constructor.
Object3d::Object3d(){}

// Constructor con parametros.
Object3d::Object3d(vector<_vertex3f> &v , vector<_vertex3ui> &t)
  :Basic3dObject(v), triangles(t) {}

// Método para dibjar el objeto con líneas.
void Object3d::draw_edges(){
  // Establecemos las líneas como forma de dibujado.
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  // Inicializamos OpenGL con GL_TRIANGLES.
  glBegin(GL_TRIANGLES);

  glColor3f(0,0,0);

  // Dibujamos los tres vértices del triángulo.
  // vertice 1 : triangles[]._0, vertice 2 : triangles[]._1, vertice 3: triangles[]._2
  for(unsigned int i=0; i < triangles.size() ;i++){
    glVertex3f(vertex[triangles[i]._0].x, vertex[triangles[i]._0].y, vertex[triangles[i]._0].z);
    glVertex3f(vertex[triangles[i]._1].x, vertex[triangles[i]._1].y, vertex[triangles[i]._1].z);
    glVertex3f(vertex[triangles[i]._2].x, vertex[triangles[i]._2].y, vertex[triangles[i]._2].z);
  }

  glEnd();
}

// Método para dibujar el objeto sólido.
void Object3d::draw_solid(){
  // Establecemos el dibujado como sólido.
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

  // Inicializamos OpenGL con GL_TRIANGLES.
  glBegin(GL_TRIANGLES);

  glColor3f(1,0,1); // Rosa.

  // Dibujamos los tres vértices del triángulo.
  // vertice 1 : triangles[]._0, vertice 2 : triangles[]._1, vertice 3: triangles[]._2
  for(unsigned int i=0; i < triangles.size() ;i++){
    glVertex3f(vertex[triangles[i]._0].x, vertex[triangles[i]._0].y, vertex[triangles[i]._0].z);
    glVertex3f(vertex[triangles[i]._1].x, vertex[triangles[i]._1].y, vertex[triangles[i]._1].z);
    glVertex3f(vertex[triangles[i]._2].x, vertex[triangles[i]._2].y, vertex[triangles[i]._2].z);
  }

  glEnd();
}

// Método para dibujar el objeto como sólido ajedrez.
// Método para dibujar el objeto sólido.
void Object3d::draw_solid_chess(){
  // Establecemos el dibujado como sólido.
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

  // Inicializamos OpenGL con GL_TRIANGLES.
  glBegin(GL_TRIANGLES);

  // Dibujamos los tres vértices del triángulo.
  // vertice 1 : triangles[]._0, vertice 2 : triangles[]._1, vertice 3: triangles[]._2
  for(unsigned int i=0; i < triangles.size() ;i++){
    // Elegimos un color según las cara. Verde para las caras pares y rojo para
    // las caras impares.
    if(i%2 == 0)
      glColor3f(0,1,0); // Verde.
    else
      glColor3f(1,0,0); // Rojo.

    glVertex3f(vertex[triangles[i]._0].x, vertex[triangles[i]._0].y, vertex[triangles[i]._0].z);
    glVertex3f(vertex[triangles[i]._1].x, vertex[triangles[i]._1].y, vertex[triangles[i]._1].z);
    glVertex3f(vertex[triangles[i]._2].x, vertex[triangles[i]._2].y, vertex[triangles[i]._2].z);
  }

  glEnd();
}

// Función para dibujar los puntos, líneas y superficies del objeto 3D
void Object3d::draw_points_edges_solid(){
  draw_points();
  draw_edges();
  draw_solid();
}

//-------------------------------------------------------------------------------------
//
//  Práctica 2.
//
//-------------------------------------------------------------------------------------

// Función para asignar los valores de un vector de int al vector de triángulos.
void Object3d::setTriangles(vector<int> &faces){
  triangles.resize(faces.size()/3);

  for(unsigned int i=0; i < triangles.size() ; i++){
    triangles[i].x = (unsigned int) faces[3*i];
    triangles[i].y = (unsigned int) faces[3*i+1];
    triangles[i].z = (unsigned int) faces[3*i+2];
  }
}

// Constructor para la creación de Objetos 3D a partir de archivos PLY.
Object3d::Object3d(char * file_name){
  // Objectos auxiliares para conseguir los vértices.
  _file_ply arch_ply;
  vector<float> vert;
  vector<int> faces;

  // Primero abrimos el fichero.
  arch_ply.open(file_name);

  // Ahora, introducimos los datos en los vectores de float e int.
  arch_ply.read(vert, faces);

  // Introducimos el vector de triangulos.
  setTriangles(faces);
  // Introducimos el vector de vértices.
  setVertex(vert);
}

// Constructor para crear solo el modelo de puntos.
Object3d::Object3d(vector<_vertex3f> &v):Basic3dObject(v){
}
