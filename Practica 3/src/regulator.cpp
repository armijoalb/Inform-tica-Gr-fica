// Implementación métodos clase WattsRegulator.

#include "regulator.h"

WattsRegulator::WattsRegulator(){}

void WattsRegulator::draw(const _rendering_mode mode, float ang, float mov){
  // Primero dibujamos la base.
  glPushMatrix();
  glTranslatef(0,0.75,0);
  glScalef(5.0,1.5,5.0);
  cube.draw(mode);
  glPopMatrix();

  // Ahora dibujamos el resto.
  glPushMatrix();
  glTranslatef(0,1.5,0);
  body.draw(mode,ang,mov);
  glPopMatrix();


}
