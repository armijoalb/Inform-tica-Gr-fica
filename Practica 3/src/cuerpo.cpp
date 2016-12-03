// Implementación de la clase Body.

#include "cuerpo.h"

Body::Body(){

}

void Body::draw(const _rendering_mode mode, float ang, float mov){
  // Dibujamos el cilindro principal.
  glPushMatrix();
  glTranslatef(0.0,7.5,0.0);
  glScalef(1,15.0,1);
  cilinder.draw(mode);
  glPopMatrix();

  // Dibujamos los brazos.
  glPushMatrix();
  glTranslatef(0,7,0);
  glRotatef(ang, 0, 1,0);
  brazos.draw(mode, ang, mov);
  glPopMatrix();
}
