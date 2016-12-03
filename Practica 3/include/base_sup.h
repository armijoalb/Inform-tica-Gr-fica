/*
  Alberto Armijo Ruiz.
  3º A GII.
  Clase Base Superior para el regulador de WATTS.
*/

#ifndef _BASE_SUP_H
#define _BASE_SUP_H

#include "brazo1.h"

class BaseSup{
private:
  Brazo1 brazo;
  Cilinder cilinder;
public:
  BaseSup();
  void draw(const _rendering_mode mode, float ang);
};

#endif
