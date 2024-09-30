#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avion.h"
#include "destino.h"
#include "pasajero.h"
#include "lista.h"

struct avionE{
  char tipo[20];
  int matricula;
  int capacidad;

  ListaPtr listaPasajeros;

  ListaPtr destinos;
  };

AvionPtr crearAvion(char* t, int m, int c){
    AvionPtr a= (AvionPtr)malloc(sizeof(struct avionE));

    strcpy(a->tipo,t);
    a->matricula=m;
    a->capacidad=c;
    a->listaPasajeros = crearLista();
    a->destinos = crearLista();
    return a;
};

void mostrarAvion(AvionPtr a){
    printf("\n\n====================== AVION ======================\n\n");
    printf("TIPO: %s\n", a->tipo);
    printf("MATRICULA: %d\n",a->matricula);
    printf("CAPACIDAD: %d\n", a->capacidad);

    mostrarListaGenerico(a->listaPasajeros, &mostrarPasajeroDatoPtr);
    mostrarListaGenerico(a->destinos, &mostrarDestinoDatoPtr);
};

void insertarPasajero(AvionPtr a, PasajeroPtr p){
    if (a->capacidad == 0) {
        printf("\nNo hay mas asientos disponibles para agregar al pasajero %s\n", getApellido(p));
    } else {
        insertarUltimo(a->listaPasajeros, p);
        a->capacidad = a->capacidad - 1;
    }
}

int compararAvionPtr(void * d1, void * d2){
    AvionPtr a1 = (AvionPtr)d1;
    AvionPtr a2 = (AvionPtr)d2;

    return a1->matricula > a2->matricula;
}

void ordenarPasajerosPorApellido(AvionPtr a){
    ordenarLista(a->listaPasajeros, &compararPasajeroPtr);
};

void ordenarDestinoPtr(AvionPtr a){
    ordenarLista(a->destinos, &compararDestino);
}

void eliminarDestino(AvionPtr a, int pos){
    eliminarPosicion(a->destinos, pos);
}

void insertarDestino(AvionPtr a, DestinoPtr d){
    insertarPrimero(a->destinos,d);
}

void eliminarPasajero(AvionPtr a, int pos){
    eliminarPosicion(a->listaPasajeros, pos);
}

int compararPasajeros(void* a, void* b){
    PasajeroPtr p1 = (PasajeroPtr)a;
    PasajeroPtr p2 = (PasajeroPtr)b;
    return strcmp(getApellido(p1), getApellido(p2));
}

void mostrarAvionDatoPtr(void * d){
    DatoPtr a = (AvionPtr)d;
    mostrarAvion(a);
};

void liberarAvion(AvionPtr a){
    liberarLista(a->listaPasajeros);
    liberarLista(a->destinos);
    free(a);
};

///GETTERS Y SETTERS
//getters
char* getTipo(AvionPtr a){
    return a->tipo;
};
int getMatricula(AvionPtr a){
    return a->matricula;
};
int getCapacidad(AvionPtr a){
    return a->capacidad;
};
ListaPtr getListaPasajeros(AvionPtr a){
    return a->listaPasajeros;
};
ListaPtr getDestinos(AvionPtr a){
    return a->destinos;
};
//setters
void setTipo(AvionPtr a, char* nuevoTipo){
    strcpy(a->tipo, nuevoTipo);
};
void setMatricula(AvionPtr a, int nuevoMatricula){
    a->matricula = nuevoMatricula;
};
void setCapacidad(AvionPtr a, int nuevoCapacidad){
    a->capacidad = nuevoCapacidad;
};
void setListaPasajeros(AvionPtr a, ListaPtr nuevoListaPasajeros){
    a->listaPasajeros = nuevoListaPasajeros;
};
void setDestinos(AvionPtr a,ListaPtr nuevoDestinos){
    a->destinos = nuevoDestinos;
};
