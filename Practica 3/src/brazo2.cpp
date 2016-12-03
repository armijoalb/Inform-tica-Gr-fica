#include "brazo2.h"

// Constructor.
Brazo2::Brazo2()
  : objeto_ply("data/beethoven.ply"){
}


// Función para dibujar.
void Brazo2::draw(const _rendering_mode mode, const float ang){
  // Dibujamos primero el brazo.
  glPushMatrix();
  glTranslatef(0.0,2.5,0.0);
  glScalef(0.5,7.0,0.5);
  cilinder.draw(mode);
  glPopMatrix();

  // Ahora dibujamos a beethoven.
  glPushMatrix();
  glTranslatef(0.0,8,0.0);
  glScalef(0.3,0.3,0.3);
  glRotatef(90+ang, 0,1,0);
  objeto_ply.draw(mode);
  glPopMatrix();
}
