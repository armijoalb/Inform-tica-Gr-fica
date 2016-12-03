// Implementación métodos clase Cilinder.

#include "cilinder.h"

// Constructor.
Cilinder::Cilinder()
  :cilinder(perfil_cilindro){
}

// Método para dibujar el cilindro.
void Cilinder::draw(const _rendering_mode mode){
  cilinder.draw(mode);
}
