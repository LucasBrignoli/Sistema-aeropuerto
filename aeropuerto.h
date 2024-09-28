#ifndef AEROPUERTO_H_INCLUDED
#define AEROPUERTO_H_INCLUDED
#include "lista.h"
#include "avion.h"

struct aeropuertoE;

typedef struct aeropuertoE * AeropuertoPtr;

AeropuertoPtr crearAeropuerto(char* nombre, char* direccion, char* telefono);

void insertarAvion(AeropuertoPtr a, AvionPtr av);

void liberarAeropuerto(AeropuertoPtr a);

void mostrarAeropuerto(AeropuertoPtr a);
void mostrarAeropuertoDatoPtr(void * d);

///GETTERS Y SETTERS
//getters
char* getNombre(AeropuertoPtr a);
char* getDireccion(AeropuertoPtr a);
char* getTelefono(AeropuertoPtr a);
ListaPtr getListaAviones(AeropuertoPtr a);
//setters
void setNombre(AeropuertoPtr a, char* nuevoNombre);
void setDireccion(AeropuertoPtr a, char* nuevoDireccion);
void setTelefono(AeropuertoPtr a, char* nuevoTelefono);

#endif // AEROPUERTO_H_INCLUDED
