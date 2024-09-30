#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED
#include "lista.h"
#include "pasajero.h"
#include "destino.h"

struct avionE;

typedef struct avionE * AvionPtr;

// Pre: t no debe ser NULL, m debe ser un número positivo, c debe ser mayor que 0.
// Post: Devuelve un puntero a un avión creado con los valores especificados.
AvionPtr crearAvion(char* t, int m, int c);

// Pre: a no debe ser NULL, pos debe ser un índice válido en la lista de pasajeros del avión.
// Post: Elimina el pasajero en la posición `pos` de la lista de pasajeros del avión.
void eliminarPasajero(AvionPtr a, int pos);

void eliminarDestino(AvionPtr a, int pos);

// Pre: a y p no deben ser NULL. p debe ser un pasajero válido.
// Post: Inserta al pasajero p en la lista de pasajeros del avión a.
void insertarPasajero(AvionPtr a, PasajeroPtr p);

// Pre: a y d no deben ser NULL. d debe ser un destino válido.
// Post: Inserta el destino d en la lista de destinos del avión a.
void insertarDestino(AvionPtr a, DestinoPtr d);

// Pre: a y b no deben ser NULL. Ambos deben ser punteros a pasajeros válidos.
// Post: Compara dos pasajeros por algún criterio (apellido, dni, etc.), devolviendo el resultado de la comparación.
int compararPasajeros(void* a, void* b);

// Pre: d1 y d2 no deben ser NULL, ambos deben apuntar a punteros de avión válidos.
// Post: Devuelve un número negativo si d1 < d2, 0 si son iguales, o un número positivo si d1 > d2 según un criterio de comparación (matrícula, tipo, etc.).
int compararAvionPtr(void * d1, void * d2);

// Pre: a no debe ser NULL, y la lista de pasajeros dentro del avión debe existir y contener al menos un pasajero.
// Post: Ordena la lista de pasajeros del avión a alfabéticamente por apellido.
void ordenarPasajerosPorApellido(AvionPtr a);

// Pre: a no debe ser NULL, y la lista de destinos dentro del avión debe existir y contener al menos un destino.
// Post: Ordena la lista de destinos del avión a alfabéticamente por ciudad.
void ordenarDestinoPtr(AvionPtr a);

// Pre: a no debe ser NULL.
// Post: Muestra la información del avión y sus listas de pasajeros y destinos.
void mostrarAvion(AvionPtr a);

// Pre: d no debe ser NULL.
// Post: Muestra los datos de un avión dado como puntero genérico (void*).
void mostrarAvionDatoPtr(void * d);

// Pre: a no debe ser NULL.
// Post: Libera la memoria utilizada por el avión, incluyendo las listas de pasajeros y destinos.
void liberarAvion(AvionPtr a);

// GETTERS Y SETTERS

// Pre: a no debe ser NULL.
// Post: Devuelve el tipo del avión a.
char* getTipo(AvionPtr a);

// Pre: a no debe ser NULL.
// Post: Devuelve la matrícula del avión a.
int getMatricula(AvionPtr a);

// Pre: a no debe ser NULL.
// Post: Devuelve la capacidad del avión a.
int getCapacidad(AvionPtr a);

// Pre: a no debe ser NULL.
// Post: Devuelve la lista de pasajeros del avión a.
ListaPtr getListaPasajeros(AvionPtr a);

// Pre: a no debe ser NULL.
// Post: Devuelve la lista de destinos del avión a.
ListaPtr getDestinos(AvionPtr a);

// Pre: a y nuevoTipo no deben ser NULL.
// Post: Asigna nuevoTipo al avión a.
void setTipo(AvionPtr a, char* nuevoTipo);

// Pre: a no debe ser NULL, nuevoMatricula debe ser un número positivo.
// Post: Asigna nuevoMatricula al avión a.
void setMatricula(AvionPtr a, int nuevoMatricula);

// Pre: a no debe ser NULL, nuevoCapacidad debe ser mayor que 0.
// Post: Asigna nuevoCapacidad al avión a.
void setCapacidad(AvionPtr a, int nuevoCapacidad);

// Pre: a y nuevoListaPasajeros no deben ser NULL.
// Post: Asigna nuevoListaPasajeros a la lista de pasajeros del avión a.
void setListaPasajeros(AvionPtr a, ListaPtr nuevoListaPasajeros);

// Pre: a y nuevoDestinos no deben ser NULL.
// Post: Asigna nuevoDestinos a la lista de destinos del avión a.
void setDestinos(AvionPtr a, ListaPtr nuevoDestinos);

#endif // AVION_H_INCLUDED
