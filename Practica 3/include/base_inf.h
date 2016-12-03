/*
  Alberto Armijo Ruiz.
  3º GII A.
  Clase Base inferior.
*/

#ifndef _BASE_INF_H
#define _BASE_INF_H

#include "cilinder.h"
#include "cube.h"
#include "brazo2.h"

class BaseInf{
private:
  Cilinder cilinder;
  Cube cube;
  Brazo2 brazo;
public:
  BaseInf();
  void draw(const _rendering_mode mode, float ang);
};

#endif
