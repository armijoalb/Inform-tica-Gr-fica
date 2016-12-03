// Métodos clase BaseInf.

#include "base_inf.h"

BaseInf::BaseInf(){
}

void BaseInf::draw(const _rendering_mode mode, float ang){
  // Primero dibujaremos la base.
  glPushMatrix();
  glTranslatef(0.0,1.0,0.0);
  glScalef(3.0, 2.0, 3.0);
  cilinder.draw(mode);
  glPopMatrix();

  // Ahora dibujamos los brazos.

  glPushMatrix();
  // Transformaciones conforme a la base.
  glTranslatef(0.75,0.5,0);
  glRotatef(-45-ang*6,0,0,1);
  brazo.draw(mode,0);
  glPopMatrix();


  glPushMatrix();
  glRotatef(90,0,1,0);

  // Transformaciones conforme a la base.
  glTranslatef(0.75,0.5,0);
  glRotatef(-45-ang*6,0,0,1);
  brazo.draw(mode,0);
  glPopMatrix();

  glPushMatrix();
  glRotatef(180,0,1,0);

  // Transformaciones conforme a la base.
  glTranslatef(0.75,0.5,0);
  glRotatef(-45-ang*6,0,0,1);
  brazo.draw(mode,0);
  glPopMatrix();

  glPushMatrix();
  glRotatef(270,0,1,0);

  // Transformaciones conforme a la base.
  glTranslatef(0.75,0.5,0);
  glRotatef(-45-ang*6,0,0,1);
  brazo.draw(mode,0);
  glPopMatrix();

  // Ahora dibujamos el cubo.
  glPushMatrix();
  // Transformaciones conforma a la base.
  glTranslatef(-0.9, -0.5, 0.0);
  // Transformaciones de forma.
  glTranslatef(0.0,-2.0,0.0);
  glScalef(0.3,6, 0.3);
  cube.draw(mode);
  glPopMatrix();

}
