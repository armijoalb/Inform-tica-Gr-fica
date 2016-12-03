/*
  Alberto Armijo Ruiz.
  3º A GII.
*/

#ifndef _REGULATOR_H
#define _REGULATOR_H

#include "cube.h"
#include "cuerpo.h"

class WattsRegulator{
private:
  Cube cube;
  Body body;
public:
  WattsRegulator();
  void draw(const _rendering_mode mode, float ang, float mov);
};

#endif
