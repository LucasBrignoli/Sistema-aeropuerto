#ifndef AEROPUERTO_H_INCLUDED
#define AEROPUERTO_H_INCLUDED
#include "lista.h"
#include "avion.h"

struct aeropuertoE;

typedef struct aeropuertoE * AeropuertoPtr;

// Aeropuerto.h

// Pre: nombre, direcci�n y tel�fono no deben ser NULL.
// Post: Devuelve un puntero a un aeropuerto creado con los valores asignados.
AeropuertoPtr crearAeropuerto(char* nombre, char* direccion, char* telefono);

// Pre: a y av no deben ser NULL.
// Post: Inserta el avi�n av en la lista de aviones del aeropuerto a.
void insertarAvion(AeropuertoPtr a, AvionPtr av);

// Pre: a no debe ser NULL.
// Post: Libera la memoria utilizada por el aeropuerto, incluyendo su lista de aviones.
void liberarAeropuerto(AeropuertoPtr a);

// Pre: a no debe ser NULL.
// Post: Muestra la informaci�n del aeropuerto y sus aviones.
void mostrarAeropuerto(AeropuertoPtr a);

// Pre: a no debe ser NULL, y la lista de aviones dentro del aeropuerto debe existir y contener al menos un avi�n.
// Post: Ordena la lista de aviones del aeropuerto a seg�n un criterio de comparaci�n (como la matr�cula o el tipo).
void ordenarAviones(AeropuertoPtr a);

// Pre: a no debe ser NULL, pos debe ser un �ndice v�lido dentro de la lista de aviones del aeropuerto.
// Post: Elimina el avi�n en la posici�n `pos` de la lista de aviones del aeropuerto a.
void eliminarAvion(AeropuertoPtr a, int pos);

// GETTERS

// Pre: a no debe ser NULL.
// Post: Devuelve el nombre del aeropuerto a.
char* getNombre(AeropuertoPtr a);

// Pre: a no debe ser NULL.
// Post: Devuelve la direcci�n del aeropuerto a.
char* getDireccion(AeropuertoPtr a);

// Pre: a no debe ser NULL.
// Post: Devuelve el tel�fono del aeropuerto a.
char* getTelefono(AeropuertoPtr a);

// Pre: a no debe ser NULL.
// Post: Devuelve la lista de aviones del aeropuerto a.
ListaPtr getListaAviones(AeropuertoPtr a);

// SETTERS

// Pre: a y nuevoNombre no deben ser NULL.
// Post: Asigna nuevoNombre al aeropuerto a.
void setNombre(AeropuertoPtr a, char* nuevoNombre);

// Pre: a y nuevoDireccion no deben ser NULL.
// Post: Asigna nuevoDireccion al aeropuerto a.
void setDireccion(AeropuertoPtr a, char* nuevoDireccion);

// Pre: a y nuevoTelefono no deben ser NULL.
// Post: Asigna nuevoTelefono al aeropuerto a.
void setTelefono(AeropuertoPtr a, char* nuevoTelefono);


#endif // AEROPUERTO_H_INCLUDED
