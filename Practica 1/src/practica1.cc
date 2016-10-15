#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include "obj3d.h"

// Enumerados:
typedef enum{CUBE, TETRAHEDRON} _object_type;
typedef enum{POINTS, LINES, SOLID, CHESS, ALL, TRANSLATION} _rendering_mode;

// tamaño de los ejes
const int AXIS_SIZE=5000;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Window_width,Window_height,Front_plane,Back_plane;

// variables que determninan la posicion y tamaño de la ventana X
int UI_window_pos_x=50,UI_window_pos_y=50,UI_window_width=500,UI_window_height=500;

// variable para dibujar un cubo o un tetraedro, según la tecla pulsada.
_object_type figura;

// variable para el tipo de dibujado del objeto.
// Por defecto se dibuja en modo puntos.
_rendering_mode modo;

// Vectores de los objetos.
vector<_vertex3f> v_cube = {_vertex3f(-0.5,0.5,0.5), _vertex3f(0.5,0.5,0.5), _vertex3f(0.5,-0.5,0.5), _vertex3f(-0.5,-0.5,0.5),
											 _vertex3f(-0.5,0.5,-0.5), _vertex3f(0.5,0.5,-0.5), _vertex3f(0.5,-0.5,-0.5), _vertex3f(-0.5,-0.5,-0.5)};

vector<_vertex3ui> t_cube ={ _vertex3ui(0,1,2), _vertex3ui(0,2,3),
 												_vertex3ui(1,5,6), _vertex3ui(1,6,2),
 												_vertex3ui(4,5,7), _vertex3ui(5,6,7),
 												_vertex3ui(4,0,3), _vertex3ui(4,3,7),
 												_vertex3ui(3,2,6), _vertex3ui(3,6,7),
 												_vertex3ui(4,5,1), _vertex3ui(4,1,0) };

vector<_vertex3f> v_tetrahedron = {_vertex3f(0,0.5,0), _vertex3f(0.5,-0.5,0), _vertex3f(-0.5,-0.5,0.5),_vertex3f(-0.5,-0.5,-0.5)};
vector<_vertex3ui> t_tetrahedron = {_vertex3ui(0,1,2), _vertex3ui(0,3,1), _vertex3ui(0,3,2),_vertex3ui(3,1,2)};

// Objectos para dibujar el cubo y el tetraedro.
Object3d un_cubo(v_cube, t_cube), un_tetraedro (v_tetrahedron, t_tetrahedron);
//**************************************************************************
//
//***************************************************************************

void clear_window()
{

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void change_projection()
{

glMatrixMode(GL_PROJECTION);
glLoadIdentity();

// formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
//  Front_plane>0  Back_plane>PlanoDelantero)
glFrustum(-Window_width,Window_width,-Window_height,Window_height,Front_plane,Back_plane);
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void change_observer()
{

// posicion del observador
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}

//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void draw_axis()
{
glBegin(GL_LINES);
// eje X, color rojo
glColor3f(1,0,0);
glVertex3f(-AXIS_SIZE,0,0);
glVertex3f(AXIS_SIZE,0,0);
// eje Y, color verde
glColor3f(0,1,0);
glVertex3f(0,-AXIS_SIZE,0);
glVertex3f(0,AXIS_SIZE,0);
// eje Z, color azul
glColor3f(0,0,1);
glVertex3f(0,0,-AXIS_SIZE);
glVertex3f(0,0,AXIS_SIZE);
glEnd();
}


//**************************************************************************
// Funcion que dibuja los objetos
//***************************************************************************

void draw_objects()
{
	// Método para dibujar las figuras. Dependiendo del valor
	// de la variable figura, se dibuja un cubo o un tetraedro.
	// Después, dependiendo del valor de la variable modo,
	// se dibuja la figura de una forma u otra( sólido, líneas,...)

	switch (figura) {
		// Cubo.
		case CUBE:
			switch (modo){
				case POINTS : un_cubo.draw_points(); break;
				case LINES : un_cubo.draw_edges(); break;
				case SOLID : un_cubo.draw_solid(); break;
				case CHESS : un_cubo.draw_solid_chess(); break;
				case ALL : un_cubo.draw_points_edges_solid(); break;
				case TRANSLATION : un_cubo.move_object(1,1,1);
			}
			break;
		// Tetraedro.

		case TETRAHEDRON:
			switch (modo){
				case POINTS : un_tetraedro.draw_points(); break;
				case LINES : un_tetraedro.draw_edges(); break;
				case SOLID : un_tetraedro.draw_solid(); break;
				case CHESS : un_tetraedro.draw_solid_chess(); break;
				case ALL : un_tetraedro.draw_points_edges_solid(); break;
				case TRANSLATION : un_tetraedro.move_object(1,1,1); break;
			}
			break;
	}


}


//**************************************************************************
//
//***************************************************************************

void draw_scene(void)
{

clear_window();
change_observer();
draw_axis();
draw_objects();
glutSwapBuffers();
}



//***************************************************************************
// Funcion llamada cuando se produce un cambio en el tamaño de la ventana
//
// el evento manda a la funcion:
// nuevo ancho
// nuevo alto
//***************************************************************************

void change_window_size(int Ancho1,int Alto1)
{
change_projection();
glViewport(0,0,Ancho1,Alto1);
glutPostRedisplay();
}


//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla normal
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton
//***************************************************************************

void normal_keys(unsigned char Tecla1,int x,int y)
{

// Dependiendo de la tecla que pulsemos, podemos cambiar el modo,
// en el que se visualiza la figura.
// Si pulsamos Q salimos del programa.
switch(toupper(Tecla1)){
	case 'Q' : exit(0); break;
	case 'P' : modo=POINTS ; break;
	case 'A' : modo=LINES ; break;
	case 'S' : modo=SOLID ; break;
	case 'C' : modo=CHESS ; break;
	case 'M' : modo=ALL ; break;
	case 'T' : modo=TRANSLATION ; break;
}
glutPostRedisplay();

}

//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla especial
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton

//***************************************************************************

void special_keys(int Tecla1,int x,int y)
{

// Dependiendo de la tecla que pulsemos, se dibujará una tecla
// u otra. F1--> dibujar cubo. F2-->dibujar tetraedro.

switch (Tecla1){
	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
	case GLUT_KEY_F1:figura=CUBE; modo=POINTS; break;
	case GLUT_KEY_F2:figura=TETRAHEDRON; modo=POINTS; break;
	}
glutPostRedisplay();
}


//***************************************************************************
// Funcion de incializacion
//***************************************************************************

void initialize(void)
{
// se inicalizan la ventana y los planos de corte
Window_width=5;
Window_height=5;
Front_plane=10;
Back_plane=1000;

// se inicia la posicion del observador, en el eje z
Observer_distance=2*Front_plane;
Observer_angle_x=0;
Observer_angle_y=0;

// se indica cual sera el color para limpiar la ventana	(r,v,a,al)
// blanco=(1,1,1,1) rojo=(1,0,0,1), ...
glClearColor(1,1,1,1);

// se habilita el z-bufer
glEnable(GL_DEPTH_TEST);
//
change_projection();
//
glViewport(0,0,UI_window_width,UI_window_height);
}


//***************************************************************************
// Programa principal
//
// Se encarga de iniciar la ventana, asignar las funciones e comenzar el
// bucle de eventos
//***************************************************************************

int main(int argc, char **argv)
{

// se llama a la inicialización de glut
glutInit(&argc, argv);

// se indica las caracteristicas que se desean para la visualización con OpenGL
// Las posibilidades son:
// GLUT_SIMPLE -> memoria de imagen simple
// GLUT_DOUBLE -> memoria de imagen doble
// GLUT_INDEX -> memoria de imagen con color indizado
// GLUT_RGB -> memoria de imagen con componentes rojo, verde y azul para cada pixel
// GLUT_RGBA -> memoria de imagen con componentes rojo, verde, azul y alfa para cada pixel
// GLUT_DEPTH -> memoria de profundidad o z-bufer
// GLUT_STENCIL -> memoria de estarcido
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

// posicion de la esquina inferior izquierdad de la ventana
glutInitWindowPosition(UI_window_pos_x,UI_window_pos_y);

// tamaño de la ventana (ancho y alto)
glutInitWindowSize(UI_window_width,UI_window_height);

// llamada para crear la ventana, indicando el titulo (no se visualiza hasta que se llama
// al bucle de eventos)
glutCreateWindow("Práctica 1");

// asignación de la funcion llamada "dibujar" al evento de dibujo
glutDisplayFunc(draw_scene);
// asignación de la funcion llamada "cambiar_tamanio_ventana" al evento correspondiente
glutReshapeFunc(change_window_size);
// asignación de la funcion llamada "tecla_normal" al evento correspondiente
glutKeyboardFunc(normal_keys);
// asignación de la funcion llamada "tecla_Especial" al evento correspondiente
glutSpecialFunc(special_keys);

// funcion de inicialización
initialize();

// inicio del bucle de eventos
glutMainLoop();
return 0;
}
