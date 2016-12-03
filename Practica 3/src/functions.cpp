#include "functions.h"

// Función para crear el prefil de una esfera. Siempre añade tapas.
vector<_vertex3f> create_sphere_outline(const float radius, const unsigned int n_points){
	// radius: radio de la esfera
	// v: vector en el que se meteran los puntos.
	// n_points: número de puntos que tienen que crearse en el primer cuadrante.

  vector<_vertex3f> v;

	// Empieza a crear siempre desde el punto (radius, 0.0, 0.0);

	_vertex3f ini(radius, 0.0, 0.0);
	float _x, _y, _z = 0.0;
	float angle = M_PI/(n_points*2);


	// Añadimos el primer punto.
	v.push_back(ini);


	for(unsigned int i = 1; i < n_points ; i++){
	 	_x = radius*cos(angle*i);
		_y = radius*sin(angle*i);

		v.insert(v.begin(), _vertex3f(_x,-_y, _z) );
		v.push_back( _vertex3f(_x, _y, _z) );
	}



	// Añadimos las tapas.
	v.insert(v.begin(), _vertex3f(0.0, -radius, _z) ); // Tapa inferior.
  v.insert(v.begin(), _vertex3f(0.0, radius, _z) ); // Tapa superior.

  return v;

}
