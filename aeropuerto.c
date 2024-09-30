#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avion.h"
#include "aeropuerto.h"
#include "lista.h"

struct aeropuertoE{
    char nombre[20];
    char direccion[20];
    char telefono[10];

    ListaPtr listaAviones;
};

AeropuertoPtr crearAeropuerto(char* nombre, char* direccion, char* telefono){
    AeropuertoPtr a = (AeropuertoPtr)malloc(sizeof(struct aeropuertoE));

    strcpy(a->nombre, nombre);
    strcpy(a->direccion, direccion);
    strcpy(a->telefono, telefono);
    a->listaAviones = crearLista();

    return a;
};

void insertarAvion(AeropuertoPtr a, AvionPtr av){
    insertarPrimero(a->listaAviones, av);
}

void liberarAeropuerto(AeropuertoPtr a){
    free(a);
};

void mostrarAeropuerto(AeropuertoPtr a){
    printf("================= AEROPUERTO =================\n");
    printf("NOMBRE: %s\n",a->nombre);
    printf("DIRECCION: %s\n", a->direccion);
    printf("TELEFONO: %s\n",a->telefono);

    mostrarListaGenerico(a->listaAviones, &mostrarAvionDatoPtr);
};

void ordenarAviones(AeropuertoPtr a){
    ordenarLista(a->listaAviones, &compararAvionPtr);
}

void eliminarAvion(AeropuertoPtr a, int pos){
    eliminarPosicion(a->listaAviones, pos);
}

///GETTERS Y SETTERS
//getters
char* getNombre(AeropuertoPtr a){
    return a->nombre;
};
char* getDireccion(AeropuertoPtr a){
    return a->direccion;
};
char* getTelefono(AeropuertoPtr a){
    return a->telefono;
};
ListaPtr getListaAviones(AeropuertoPtr a){
    return a->listaAviones;
};
//setters
void setNombre(AeropuertoPtr a, char* nuevoNombre){
    strcpy(a->nombre, nuevoNombre);
};
void setDireccion(AeropuertoPtr a, char* nuevoDireccion){
    strcpy(a->direccion, nuevoDireccion);
};
void setTelefono(AeropuertoPtr a, char* nuevoTelefono){
    strcpy(a->telefono, nuevoTelefono);
};

