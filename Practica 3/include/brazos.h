/*
  Alberto Armijo Ruiz
  3º GII A.
  Clase que representa los brazos.
*/

#ifndef _BRAZOS_H
#define _BRAZOS_H

#include "base_inf.h"
#include "base_sup.h"

class Brazos{
private:
  BaseSup base_sup;
  BaseInf base_inf;
public:
  Brazos();
  void draw(const _rendering_mode mode, float ang, float mov);
};

#endif
