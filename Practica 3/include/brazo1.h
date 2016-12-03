/*
  Alberto Armijo Ruiz.
  3º A GII.
  Brazo que se une con la bola.
*/

#ifndef _BRAZO1_H
#define _BRAZO1_H

#include "cilinder.h"
#include "sphere.h"

class Brazo1{
private:
  Cilinder cilinder;
  Sphere sphere;
public:
  Brazo1();
  void draw(const _rendering_mode mode);
};

#endif
