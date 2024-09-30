#ifndef DESTINO_H_INCLUDED
#define DESTINO_H_INCLUDED

struct destinoE;

typedef struct destinoE * DestinoPtr;

// Pre: ciudad no debe ser NULL, latitud y longitud deben ser valores válidos.
// Post: Devuelve un puntero a un destino creado con los valores asignados.
DestinoPtr crearDestino(char* ciudad, float latitud, float longitud);

// Pre: d1 y d2 no deben ser NULL, ambos deben apuntar a punteros de destino válidos.
// Post: Devuelve un número negativo si d1 < d2, 0 si son iguales, o un número positivo si d1 > d2 según la ciudad del destino.
int compararDestino(void *d1, void *d2);

// Pre: d no debe ser NULL.
// Post: Muestra los datos del destino d.
void mostrarDestino(DestinoPtr d);

// Pre: d no debe ser NULL.
// Post: Muestra los datos de un destino dado como puntero genérico (void*).
void mostrarDestinoDatoPtr(void * d);

// Pre: d no debe ser NULL.
// Post: Libera la memoria utilizada por el destino d.
void liberarDestino(DestinoPtr d);

// GETTERS Y SETTERS

// Pre: d no debe ser NULL.
// Post: Devuelve la ciudad del destino d.
char* getCiudad(DestinoPtr d);

// Pre: d no debe ser NULL.
// Post: Devuelve la latitud del destino d.
float getLatitud(DestinoPtr d);

// Pre: d no debe ser NULL.
// Post: Devuelve la longitud del destino d.
float getLongitud(DestinoPtr d);

// Pre: d y nuevoCiudad no deben ser NULL.
// Post: Asigna nuevoCiudad al destino d.
void setCiudad(DestinoPtr d, char* nuevoCiudad);

// Pre: d no debe ser NULL, nuevoLatitud debe ser un valor válido.
// Post: Asigna nuevoLatitud al destino d.
void setLatitud(DestinoPtr d, float nuevoLatitud);

// Pre: d no debe ser NULL, nuevoLongitud debe ser un valor válido.
// Post: Asigna nuevoLongitud al destino d.
void setLongitud(DestinoPtr d, float nuevoLongitud);

#endif // DESTINO_H_INCLUDED
