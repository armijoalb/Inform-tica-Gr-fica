// Implementación métodos Brazo1.
#include "brazo1.h"

Brazo1::Brazo1()
{
}

void Brazo1::draw(const _rendering_mode mode){
  // Primero dibujamos el cilindro, y le damos tamaño.
  glPushMatrix();
  glTranslatef(0.0,5.0,0.0);
  glScalef(0.8,10.0,0.8);
  cilinder.draw(mode);
  glPopMatrix();

  // Ahora dibujamos la esfera.
  glPushMatrix();
  glTranslatef(0.0,11.5,0.0);
  glScalef(3.0,3.0,3.0);
  sphere.draw(mode);
  glPopMatrix();

  
}
