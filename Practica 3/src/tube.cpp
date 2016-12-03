// Implementación métodos clase Tube.

#include "tube.h"

// Constructor.
Tube::Tube()
  :tube(perfil_tubo){
}

// Método para dibujar el tubo.
void Tube::draw(const _rendering_mode mode){
  tube.draw(mode);
}
