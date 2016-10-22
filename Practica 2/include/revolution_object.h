/*
  Alberto Armijo Ruiz.
  3º GII A.
  Objeto creado por revolución.
  Aquí se define la clase RevolutionObject.
  Clase que crea un objeto por revolución, a partir de un perfil dado.
  Hereda de la clase Object3d para poder dibujar el objeto de diferentes formas.
*/


#ifndef _REVOLUTION_OBJECT_H
#define _REVOLUTION_OBJECT_H

#include "obj3d.h"
#include <cmath>

class RevolutionObject : public Object3d{
private:
  bool top_under, top_above;
  unsigned int profiles;
  unsigned int n_tops;
  unsigned int points_profile; // Guarda el número de puntos que hay en el perfil.
                               // sin contar con los puntos del eje  Y.
public:
  RevolutionObject();
  RevolutionObject(vector<_vertex3f> &perfil);

  void create_profiles(unsigned int n_profiles);
  void check_top(vector<_vertex3f> &perfil);
  void create_top_above();
  void create_top_under();
  void create_exterior();
  unsigned int getNTapas();
  unsigned int getPointsProfile();

};

#endif
