// Implementación métodos base_sup.

#include "base_sup.h"

BaseSup::BaseSup(){
}

void BaseSup::draw(const _rendering_mode mode, float ang){
  // Primero dibujamos la base cilindrica.
  glPushMatrix();
  glTranslatef(0.0,1.0,0.0);
  glScalef(3.0, 2.0, 3.0);
  cilinder.draw(mode);
  glPopMatrix();

  // Ahora colocamos los brazos.
  glPushMatrix();
  glTranslatef(1.0,1.5,0);
  glRotatef(-135+ang*6,0,0,1);
  brazo.draw(mode);
  glPopMatrix();


  glPushMatrix();

  glRotatef(90,0,1,0);

  glTranslatef(1.0,1.5,0);
  glRotatef(-135+ang*6,0,0,1);
  brazo.draw(mode);
  glPopMatrix();


  glPushMatrix();

  glRotatef(180,0,1,0);

  glTranslatef(1.0,1.5,0);
  glRotatef(-135+ang*6,0,0,1);
  brazo.draw(mode);
  glPopMatrix();

  glPushMatrix();

  glRotatef(270,0,1,0);

  glTranslatef(1.0,1.5,0);
  glRotatef(-135+ang*6,0,0,1);
  brazo.draw(mode);
  glPopMatrix();



}
