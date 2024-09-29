#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "pasajero.h"

struct pasajeroE{
    char apellido[20];
    int dni;
    char ventanilla;
};

PasajeroPtr crearPasajero(char* apellido,int dni,char ventanilla){
    PasajeroPtr p = (PasajeroPtr)malloc(sizeof(struct pasajeroE));

    strcpy(p->apellido, apellido);
    p->dni = dni;
    p->ventanilla = ventanilla;

    return p;
};

int compararPasajeroPtr(void * d1, void * d2){
    PasajeroPtr dato1 = (PasajeroPtr) d1;
    PasajeroPtr dato2 = (PasajeroPtr) d2;

    return dato1->dni > dato2->dni;
}

void mostrarPasajero(PasajeroPtr p){
    printf("-------- PASAJEROS --------\n");

    printf("APELLIDO: %s\n", p->apellido);
    printf("DNI: %d\n", p->dni);
    printf("VENTANILLA: %c\n", p->ventanilla);
};

void mostrarPasajeroDatoPtr(void * d1){
    PasajeroPtr p = (PasajeroPtr)d1;
    mostrarPasajero(p);
};

///GETTERS Y SETTERS
//getters
char* getApellido(PasajeroPtr p){
    return p->apellido;
};
int getDni(PasajeroPtr p){
    return p->dni;
};
char getVentanilla(PasajeroPtr p){
    return p->ventanilla;
};
//setters
void setApellido(PasajeroPtr p, char* nuevoApellido){
    strcpy(p->apellido, nuevoApellido);
};
void setDni(PasajeroPtr p, int nuevoDni){
    p->dni = nuevoDni;
};
void setVentanilla(PasajeroPtr p, char nuevoVentanilla){
    p->ventanilla = nuevoVentanilla;
};

void liberarPasajero(PasajeroPtr p){
    free(p);
};

