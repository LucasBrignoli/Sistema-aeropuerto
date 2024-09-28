#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "destino.h"

struct destinoE{
    char ciudad[20];
    float latitud;
    float longitud;
};

DestinoPtr crearDestino(char* ciudad, float latitud, float longitud){
    DestinoPtr d = (DestinoPtr)malloc(sizeof(struct destinoE));

    strcpy(d->ciudad, ciudad);
    d->latitud = latitud;
    d->longitud = longitud;

    return d;
};

void mostrarDestino(DestinoPtr d){
    printf("--------- DESTINO ---------\n");

    printf("CIUDAD: %s\n", d->ciudad);
    printf("LATITUD: %.2f \n",d->latitud);
    printf("LONGITUD: %.2f \n",d->longitud);

};

void mostrarDestinoDatoPtr(void * d){
    DestinoPtr des = (DestinoPtr)d;

    mostrarDestino(des);
};

void liberarDestino(DestinoPtr d){
    free(d);
};

///GETTERS Y SETTERS
//GETTERS
char* getCiudad(DestinoPtr d){
    return d->ciudad;
};
float getLatitud(DestinoPtr d){
    return d->latitud;
};
float getLongitud(DestinoPtr d){
    return d->longitud;
};
//SETTERS
void setCiudad(DestinoPtr d, char* nuevoCiudad){
    strcpy(d->ciudad, nuevoCiudad);
};
void setLatitud(DestinoPtr d, float nuevoLatitud){
    d->latitud = nuevoLatitud;
};
void setLongitud(DestinoPtr d, float nuevoLongitud){
    d->longitud = nuevoLongitud;
};
