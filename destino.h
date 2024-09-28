#ifndef DESTINO_H_INCLUDED
#define DESTINO_H_INCLUDED

struct destinoE;

typedef struct destinoE * DestinoPtr;

DestinoPtr crearDestino(char* ciudad, float latitud, float longitud);

void mostrarDestino(DestinoPtr d);
void mostrarDestinoDatoPtr(void * d);

void liberarDestino(DestinoPtr d);

///GETTERS Y SETTERS
//GETTERS
char* getCiudad(DestinoPtr d);
float getLatitud(DestinoPtr d);
float getLongitud(DestinoPtr d);
//SETTERS
void setCiudad(DestinoPtr d, char* nuevoCiudad);
void setLatitud(DestinoPtr d, float nuevoLatitud);
void setLongitud(DestinoPtr d,float nuevoLongitud);

#endif // DESTINO_H_INCLUDED
