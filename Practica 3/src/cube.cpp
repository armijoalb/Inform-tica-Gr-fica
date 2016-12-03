// Implementación métodos del objeto cubo.

#include "cube.h"

// Constructor por defecto.
Cube::Cube()
:cube(v_cube, t_cube){}

// Método para dibujar el cubo.
void Cube::draw(const _rendering_mode mode){
  cube.draw(mode);
}
