// Implemetación métodos clase Cone.

#include "cone.h"

// Constructor.
Cone::Cone()
  :cone(perfil_cono){
}

// Método para dibujar el cono.
void Cone::draw(const _rendering_mode mode){
  cone.draw(mode);
}
