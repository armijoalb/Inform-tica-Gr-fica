// Implementación métodos clase Brazos.
#include "brazos.h"

Brazos::Brazos(){
}

void Brazos::draw(const _rendering_mode mode, float ang, float mov){
  glPushMatrix();
  glTranslatef(0,7,0);
  base_sup.draw(mode,mov);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0.0,mov,0.0);
  base_inf.draw(mode, mov);
  glPopMatrix();
}
