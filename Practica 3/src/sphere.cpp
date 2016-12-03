// Implementación métodos clase Sphere.

#include "sphere.h"

// Constructor.

Sphere::Sphere()
:sphere( perfil_sphere ){
}


// Método para dibujar la esfera.
void Sphere::draw(const _rendering_mode mode){
  sphere.draw(mode);
}
