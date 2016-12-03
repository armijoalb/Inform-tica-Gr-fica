/*
  Alberto Armijo Ruiz.
  3º A GII.
  Brazo pequeño.
*/

#ifndef _BRAZO2_H
#define _BRAZO2_H

#include "cilinder.h"

class Brazo2{
private:
  Cilinder cilinder;
  Object3d objeto_ply;
public:
  Brazo2();
  void draw(const _rendering_mode mode, const float ang);
};

#endif
