# fichero Makefile
#

# Variables.
BIN= bin
SRC= src
INC= include

# nombre del fichero ejecutable
#
TARGETS= $(BIN)/practica3

# banderas para el compilador (C y C++). Se indican los directorios donde se puenden
# encontrar ficheros para incluir mediante la opcion -I
# la opcion -g sirve para permitir la depuraci�n
#
CFLAGS=    -g -DXWINDOWS -DSHM -I/usr/include -I$(INC)
CXXFLAGS=  -g -DXWINDOWS -DSHM -I/usr/include -I$(INC) -Wall

# banderas pra el enlazador
# Se indica directorios donde encontrar las funciontecas con -L. Usando -l seguido del
# nombre se indica la funcionteca que se desea enlazar.
#
LDFLAGS=  -lGLU -lGL -lglut

# definicion del compilador
#
CC = g++

SOURCE = $(SRC)/practica3.cc $(SRC)/objb3d.cpp $(SRC)/obj3d.cpp $(SRC)/file_ply_stl.cc $(SRC)/revolution_object.cpp $(SRC)/functions.cpp
SOURCE2 = $(SRC)/cube.cpp $(SRC)/cilinder.cpp $(SRC)/tube.cpp $(SRC)/cone.cpp $(SRC)/sphere.cpp $(SRC)/brazo1.cpp $(SRC)/base_sup.cpp
SOURCE3 = $(SRC)/base_inf.cpp $(SRC)/brazos.cpp $(SRC)/cuerpo.cpp $(SRC)/regulator.cpp $(SRC)/brazo2.cpp
# orden que sera ejecutada por defecto
#
default : $(TARGETS)

# regla de ejecucion
#
$(TARGETS) :
	$(CC) -o $@ $(CXXFLAGS) $(SOURCE) $(SOURCE2) $(SOURCE3) $(LDFLAGS)


#
#
clean:
	rm -f *.o
	rm -f $(TARGETS)

#
#
redo:
	touch src/*.cc
	make

#
#
superclean:
	rm -f obj/*.o
	rm *~
	rm -f $(TARGETS)

#
#
tgz:
	rm -f *.o
	rm *~
	rm -f $(TARGETS)
	tar -zcvf $(TARGETS).tgz *
