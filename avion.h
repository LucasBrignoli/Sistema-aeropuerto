#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED
#include "lista.h"
#include "pasajero.h"
#include "destino.h"

struct avionE;

typedef struct avionE * AvionPtr;

// Pre: t no debe ser NULL, m debe ser un n�mero positivo, c debe ser mayor que 0.
// Post: Devuelve un puntero a un avi�n creado con los valores especificados.
AvionPtr crearAvion(char* t, int m, int c);

// Pre: a no debe ser NULL, pos debe ser un �ndice v�lido en la lista de pasajeros del avi�n.
// Post: Elimina el pasajero en la posici�n `pos` de la lista de pasajeros del avi�n.
void eliminarPasajero(AvionPtr a, int pos);

void eliminarDestino(AvionPtr a, int pos);

// Pre: a y p no deben ser NULL. p debe ser un pasajero v�lido.
// Post: Inserta al pasajero p en la lista de pasajeros del avi�n a.
void insertarPasajero(AvionPtr a, PasajeroPtr p);

// Pre: a y d no deben ser NULL. d debe ser un destino v�lido.
// Post: Inserta el destino d en la lista de destinos del avi�n a.
void insertarDestino(AvionPtr a, DestinoPtr d);

// Pre: a y b no deben ser NULL. Ambos deben ser punteros a pasajeros v�lidos.
// Post: Compara dos pasajeros por alg�n criterio (apellido, dni, etc.), devolviendo el resultado de la comparaci�n.
int compararPasajeros(void* a, void* b);

// Pre: d1 y d2 no deben ser NULL, ambos deben apuntar a punteros de avi�n v�lidos.
// Post: Devuelve un n�mero negativo si d1 < d2, 0 si son iguales, o un n�mero positivo si d1 > d2 seg�n un criterio de comparaci�n (matr�cula, tipo, etc.).
int compararAvionPtr(void * d1, void * d2);

// Pre: a no debe ser NULL, y la lista de pasajeros dentro del avi�n debe existir y contener al menos un pasajero.
// Post: Ordena la lista de pasajeros del avi�n a alfab�ticamente por apellido.
void ordenarPasajerosPorApellido(AvionPtr a);

// Pre: a no debe ser NULL, y la lista de destinos dentro del avi�n debe existir y contener al menos un destino.
// Post: Ordena la lista de destinos del avi�n a alfab�ticamente por ciudad.
void ordenarDestinoPtr(AvionPtr a);

// Pre: a no debe ser NULL.
// Post: Muestra la informaci�n del avi�n y sus listas de pasajeros y destinos.
void mostrarAvion(AvionPtr a);

// Pre: d no debe ser NULL.
// Post: Muestra los datos de un avi�n dado como puntero gen�rico (void*).
void mostrarAvionDatoPtr(void * d);

// Pre: a no debe ser NULL.
// Post: Libera la memoria utilizada por el avi�n, incluyendo las listas de pasajeros y destinos.
void liberarAvion(AvionPtr a);

// GETTERS Y SETTERS

// Pre: a no debe ser NULL.
// Post: Devuelve el tipo del avi�n a.
char* getTipo(AvionPtr a);

// Pre: a no debe ser NULL.
// Post: Devuelve la matr�cula del avi�n a.
int getMatricula(AvionPtr a);

// Pre: a no debe ser NULL.
// Post: Devuelve la capacidad del avi�n a.
int getCapacidad(AvionPtr a);

// Pre: a no debe ser NULL.
// Post: Devuelve la lista de pasajeros del avi�n a.
ListaPtr getListaPasajeros(AvionPtr a);

// Pre: a no debe ser NULL.
// Post: Devuelve la lista de destinos del avi�n a.
ListaPtr getDestinos(AvionPtr a);

// Pre: a y nuevoTipo no deben ser NULL.
// Post: Asigna nuevoTipo al avi�n a.
void setTipo(AvionPtr a, char* nuevoTipo);

// Pre: a no debe ser NULL, nuevoMatricula debe ser un n�mero positivo.
// Post: Asigna nuevoMatricula al avi�n a.
void setMatricula(AvionPtr a, int nuevoMatricula);

// Pre: a no debe ser NULL, nuevoCapacidad debe ser mayor que 0.
// Post: Asigna nuevoCapacidad al avi�n a.
void setCapacidad(AvionPtr a, int nuevoCapacidad);

// Pre: a y nuevoListaPasajeros no deben ser NULL.
// Post: Asigna nuevoListaPasajeros a la lista de pasajeros del avi�n a.
void setListaPasajeros(AvionPtr a, ListaPtr nuevoListaPasajeros);

// Pre: a y nuevoDestinos no deben ser NULL.
// Post: Asigna nuevoDestinos a la lista de destinos del avi�n a.
void setDestinos(AvionPtr a, ListaPtr nuevoDestinos);

#endif // AVION_H_INCLUDED
