#include "revolution_object.h"

RevolutionObject::RevolutionObject(){
  top_under = false;
  top_above = false;
  profiles = 0;
  n_tops = 0;
  points_profile = 0;
}

// Constructor para almacenar un perfil
RevolutionObject::RevolutionObject(vector<_vertex3f> &perfil): Object3d(perfil){
  check_top(perfil);
  points_profile = perfil.size() - n_tops;
  create_profiles(50);
  create_exterior();
}

// Función para comprobar si tenemos tapas, y cuáles.
void RevolutionObject::check_top(vector<_vertex3f> &perfil){
  // Solo comprobaremos las dos primeras posiciones del vector, ya que las tapas son las primeras en pasarse.
  // La tapa superior siempre irá la primera. Si no hay tapa superior siempre será una inferior, o no habrá tapas.

  if(perfil[0].x == 0.0 ){
    // Tenemos al menos una tapa.
    n_tops = 1;
    if(perfil[0].y >= 0.0 ){
      // Tenemos una tapa superior.
      top_above = true;

      // Comprobamos si tenemos tapa inferior.
      if(perfil[1].x == 0.0 ){
        top_under = true;
        n_tops = 2;
      }

    }
    else{
      // Tenemos una tapa inferior.
      top_under = true;
      n_tops = 1;
    }

  }else{
    // No tenemos tapas.
    top_under = false;
    top_above = false;
    n_tops = 0;
  }

}

// Función que devuelve el número de puntos en el perfil.
unsigned int RevolutionObject::getPointsProfile(){
  return points_profile;
}


// Función para calcular los demás puntos del objeto de revolución.
void RevolutionObject::create_profiles(unsigned int n_profiles){
  float angle = (2*M_PI)/n_profiles;
  float _x, _z;
  unsigned int tam = vertex.size();

  profiles = n_profiles;

  for(unsigned int i=1; i < n_profiles ; i++){
    for(unsigned int j=0; j < tam ; j++){
      if(vertex[j].x != 0.0){
        _x = vertex[j].x * cos(angle*i);
        _z = vertex[j].x * sin(angle*i);

        vertex.push_back( _vertex3f(_x, vertex[j].y, _z) );
      }
    }
  }

}

// Función que devuelve el número de tapas.
unsigned int RevolutionObject::getNTapas(){
  return n_tops;
}

// Función para crear los triángulos de la parte exterior del objeto.
void RevolutionObject::create_exterior(){
  unsigned int max = vertex.size() - getNTapas();

  // calculamos en que indice tenemos que empezar.
  unsigned int ini = getPointsProfile() +getNTapas() -1;

  unsigned int aux = ini -1;
  unsigned int sum = getPointsProfile();
  unsigned int aux_2;

  _vertex3ui t1, t2;

  if(getPointsProfile() > 1){

    for(unsigned int i=0; i < profiles ; i++){
      aux_2 = ini;
      for(unsigned int j=0; j < (getPointsProfile()-1); j++){
        if(i == (profiles-1) ){
          t1._0 = ini; t1._1 = ((ini+sum) % max); t1._2 = aux;
          t2._0 = ((ini+sum) % max); t2._1 = ((ini+sum-1) % max); t2._2 = aux;
        }
        else{
          t1._0 = ini; t1._1 = ini+sum ; t1._2 = aux;
          t2._0 = ini+sum; t2._1 = ini+sum-1 ; t2._2 = aux;
        }

        triangles.push_back(t1);
        triangles.push_back(t2);

        ini = aux;
        aux --;
      }

      ini = aux_2 + sum;
      aux = ini-1;
    }

  }

  // Si tenemos tapas, se crean.
  if(top_above and top_under){
    create_top_above();
    create_top_under();
  }
  else if( top_under )
    create_top_under();
  else if( top_above )
    create_top_above();

}

// Función para crear los triángulos de la tapa de arriba.
void RevolutionObject::create_top_above(){
  unsigned int ini = getPointsProfile()+getNTapas()-1;
  unsigned int _0, _2;
  unsigned int sum = getPointsProfile();

  for(unsigned int i=0; i < profiles; i++){
    _0 = ini;
    _2 = (ini+sum)%vertex.size();

    if(i == (profiles-1))
      _2 = getPointsProfile()+getNTapas()-1;

    triangles.push_back(_vertex3ui(_0,0,_2));

    ini += sum;
  }

}

// Función para crear los triángulos de la tapa de abajo.
void RevolutionObject::create_top_under(){
  unsigned int pos_tapa;
  unsigned int sum = getPointsProfile();

  ( ( getNTapas() > 1 ) ? pos_tapa=1 : pos_tapa=0 );

  unsigned int ini = getNTapas();
  unsigned int _0, _2;

  for(unsigned int i=0; i < profiles; i++){
    _0 = ini;
    _2 = (ini+sum)%vertex.size();

    if(i == (profiles-1))
      _2 = getNTapas();

    triangles.push_back(_vertex3ui(_0,pos_tapa,_2));

    ini += sum;
  }
}
