/*
  Alberto Armijo Ruiz.
  3º A GII.
  Clase cuerpo.
*/

#ifndef _BODY_H
#define _BODY_H

#include "cilinder.h"
#include "brazos.h"

class Body{
private:
  Cilinder cilinder;
  Brazos brazos;
public:
  Body();
  void draw( const _rendering_mode mode, float ang, float mov);
};

#endif
