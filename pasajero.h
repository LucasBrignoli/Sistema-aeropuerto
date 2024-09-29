#ifndef PASAJERO_H_INCLUDED
#define PASAJERO_H_INCLUDED

struct pasajeroE;

typedef struct pasajeroE * PasajeroPtr;

// Pre: apellido no debe ser NULL, dni debe ser un número positivo.
// Post: Devuelve un puntero a un pasajero creado con los valores asignados.
PasajeroPtr crearPasajero(char* apellido, int dni, char ventanilla);

// Pre: p no debe ser NULL.
// Post: Muestra los datos del pasajero p.
void mostrarPasajero(PasajeroPtr p);

// Pre: d no debe ser NULL.
// Post: Muestra los datos de un pasajero dado como puntero genérico (void*).
void mostrarPasajeroDatoPtr(void * d);

// Pre: d1 y d2 no deben ser NULL. Ambos deben ser punteros a pasajeros válidos.
// Post: Compara dos pasajeros por algún criterio (apellido, dni, etc.), devolviendo el resultado de la comparación.
int compararPasajeroPtr(void * d1, void * d2);

// Pre: p no debe ser NULL.
// Post: Libera la memoria utilizada por el pasajero p.
void liberarPasajero(PasajeroPtr p);

// GETTERS Y SETTERS

// Pre: p no debe ser NULL.
// Post: Devuelve el apellido del pasajero p.
char* getApellido(PasajeroPtr p);

// Pre: p no debe ser NULL.
// Post: Devuelve el DNI del pasajero p.
int getDni(PasajeroPtr p);

// Pre: p no debe ser NULL.
// Post: Devuelve la preferencia de ventanilla del pasajero p ('S' o 'N').
char getVentanilla(PasajeroPtr p);

// Pre: p y nuevoApellido no deben ser NULL.
// Post: Asigna nuevoApellido al pasajero p.
void setApellido(PasajeroPtr p, char* nuevoApellido);

// Pre: p no debe ser NULL, nuevoDni debe ser un número positivo.
// Post: Asigna nuevoDni al pasajero p.
void setDni(PasajeroPtr p, int nuevoDni);

// Pre: p no debe ser NULL, nuevoVentanilla debe ser 'S' o 'N'.
// Post: Asigna nuevoVentanilla al pasajero p.
void setVentanilla(PasajeroPtr p, char nuevoVentanilla);

#endif // PASAJERO_H_INCLUDED
