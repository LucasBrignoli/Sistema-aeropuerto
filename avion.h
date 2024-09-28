#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED
#include "lista.h"
#include "pasajero.h"
#include "destino.h"

struct avionE;

typedef struct avionE * AvionPtr;

AvionPtr crearAvion(char* t, int m, int c);

int insertarPasajero(AvionPtr a, PasajeroPtr p);
void insertarDestino(AvionPtr a, DestinoPtr d);

void mostrarAvion(AvionPtr a);
void mostrarAvionDatoPtr(void * d);

void liberarAvion(AvionPtr a);

///GETTERS Y SETTERS
//getters
char* getTipo(AvionPtr a);
int getMatricula(AvionPtr a);
int getCapacidad(AvionPtr a);
ListaPtr getListaPasajeros(AvionPtr a);
ListaPtr getDestinos(AvionPtr a);
//setters
void setTipo(AvionPtr a, char* nuevoTipo);
void setMatricula(AvionPtr a, int nuevoMatricula);
void setCapacidad(AvionPtr a, int nuevoCapacidad);
void setListaPasajeros(AvionPtr a, ListaPtr nuevoListaPasajeros);
void setDestinos(AvionPtr a,ListaPtr nuevoDestinos);


#endif // AVION_H_INCLUDED
