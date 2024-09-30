#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodo.h"
#include "lista.h"

struct Lista{
    NodoPtr primero;
};

ListaPtr crearLista(){
    ListaPtr lista = (ListaPtr)malloc(sizeof(struct Lista));

    lista->primero = NULL;

    return lista;
};

void insertarPrimero(ListaPtr lista, DatoPtr dato){

    NodoPtr nuevoNodo = crearNodo(dato, lista->primero);
    lista->primero = nuevoNodo;

};

void insertarUltimo(ListaPtr lista, DatoPtr dato){
    NodoPtr nuevoNodo = crearNodo(dato, NULL);
    NodoPtr actual = lista->primero;

    if(lista->primero == NULL){
        lista->primero = nuevoNodo;
    }else{
        while(getSiguiente(actual) != NULL){
            actual = getSiguiente(actual);
        }
        setSiguiente(actual,nuevoNodo);
    }
};

void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion){

    int tam = obtenerTamanio(lista);

    if(posicion > tam){
        printf("NO SE PUEDE AGREGAR EN POSICION QUE NO EXISTE \n\n");
    }else{
        if(posicion < 0){
            printf("NO SE PUEDE AGREGAR EN POSICION NEGATIVA\n\n");
        }else{
            if(posicion == 0){
                insertarPrimero(lista, dato);
            }else{
                if(posicion == tam){
                    insertarUltimo(lista, dato);
                }else{
                    if(posicion > 0 && posicion < tam){
                       NodoPtr actual = lista->primero;

                       for(int i=1; i<posicion-1;i++){
                        actual = getSiguiente(actual);
                       }
                    setSiguiente(actual, crearNodo(dato, getSiguiente(actual)));
                    }
                }
            }
        }
    }
};

DatoPtr obtenerPrimero(ListaPtr lista){
    if(lista->primero == NULL){
        printf("LISTA NULA\n");
        return NULL;
    }
    NodoPtr primero = lista->primero;
    return getDato(primero);
};
DatoPtr obtenerUltimo(ListaPtr lista){
    if(lista->primero == NULL){
        printf("LISTA NULA\n");
        return NULL;
    }

    NodoPtr ultimo = lista->primero;

    while(getSiguiente(ultimo) != NULL){
        ultimo = getSiguiente(ultimo);
    }
    return getDato(ultimo);
};

DatoPtr obtenerPosicion(ListaPtr lista, int posicion){
    if(lista->primero == NULL){
        printf("LISTA NULA\n");
        return NULL;
    }
    NodoPtr actual = lista->primero;
    for(int i=1; i<posicion;i++){
        actual = getSiguiente(actual);
    }
    return getDato(actual);
};

void eliminarPrimero(ListaPtr lista){
    if(lista->primero == NULL){
        printf("Lista vacia\n");
    }
    NodoPtr nodoABorrar = lista->primero;

    lista->primero = getSiguiente(nodoABorrar);
    liberarNodo(nodoABorrar);
};

void eliminarUltimo(ListaPtr lista){
    if(lista->primero == NULL){
        printf("Lista vacia\n");
    }
    NodoPtr actual = lista->primero;

    if (getSiguiente(actual) == NULL) {
        liberarNodo(actual);
        lista->primero = NULL;
        return;
    }
    while (getSiguiente(getSiguiente(actual)) != NULL) {
        actual = getSiguiente(actual);
    }
    liberarNodo(getSiguiente(actual));
    setSiguiente(actual, NULL);
};
void eliminarPosicion(ListaPtr lista, int pos){
    if (lista->primero == NULL) {
        printf("La lista está vacía.\n");
    }
    int tam = obtenerTamanio(lista);
    if (pos < 1 || pos > tam) {
        printf("La posicion es erronea\n");
    }
    if (pos == 1) {
        return eliminarPrimero(lista);
    }
    if (pos == tam) {
        return eliminarUltimo(lista);
    }

    NodoPtr actual = lista->primero;
    for (int i = 1; i < pos - 1; i++) {
        actual = getSiguiente(actual);
    }

    NodoPtr nodoAEliminar = getSiguiente(actual);
    setSiguiente(actual, getSiguiente(nodoAEliminar));

    free(nodoAEliminar);
};

NodoPtr obtenerPrimerNodo(ListaPtr lista){
    return lista->primero;
};
NodoPtr obtenerUltimoNodo(ListaPtr lista){
    NodoPtr actual = lista->primero;

    while(actual != NULL){
        actual = getSiguiente(actual);
    }
    return actual;
};
NodoPtr obtenerPosicionNodo(ListaPtr lista, int posicion){
    int tam = obtenerTamanio(lista);
    int cont = 0;
    NodoPtr actual = lista->primero;

    if(posicion > tam){
        printf("Posicion fuera de limite\n");
        return NULL;
    }

    while(actual != NULL && cont < posicion){
        actual = getSiguiente(actual);
        cont =+1;
    }
    return actual;
};

int obtenerTamanio(ListaPtr lista){
    int tamanio = 0;

    NodoPtr actual = lista->primero;

    if(actual == NULL){
        return 0;
    }else{
        while(actual != NULL){
            tamanio = tamanio + 1;
            actual = getSiguiente(actual);
        }
    }

    return tamanio;
};

void ordenarLista(ListaPtr lista, int(*ordenarFuncion)(DatoPtr, DatoPtr)){
    int permutacion;
    NodoPtr nodo;
    NodoPtr ultimo = NULL;

    if(obtenerTamanio(lista)< 2)
    {
        //ya esta ordenada, no hago nada
    }
    else
    {
        do
        {
            permutacion = 0 ;
            nodo = lista->primero;

            while (getSiguiente(nodo) != ultimo)
            {
                if( ordenarFuncion(getDato(nodo),getDato(getSiguiente(nodo))) > 0)
                {
                    DatoPtr aux = getDato(nodo);
                    setDato(nodo, getDato(getSiguiente(nodo)));
                    setDato(getSiguiente(nodo), aux);
                    permutacion = 1;

                }
                nodo = getSiguiente(nodo);
            }
            ultimo = nodo; //opcional!!!
        }
        while (permutacion!=0);
    }
};

ListaPtr ordenarListaCopia(ListaPtr lista){
    if (lista == NULL) {
        return NULL;
    }
    ListaPtr listaCopia = duplicarLista(lista);
    ordenarLista(listaCopia, &compararInt);
    return listaCopia;
};

ListaPtr duplicarLista(ListaPtr lista){
    if (lista == NULL) {
        return NULL;
    }
    ListaPtr nuevaLista = crearLista();

    NodoPtr actual = lista->primero;
    NodoPtr ultimoNuevoNodo = NULL;

    while (actual != NULL) {
        NodoPtr nuevoNodo = crearNodo(getDato(actual),getSiguiente(actual));
        if (nuevaLista->primero == NULL) {
            nuevaLista->primero = nuevoNodo;
        } else {
            setSiguiente(ultimoNuevoNodo,nuevoNodo);
        }
        ultimoNuevoNodo = nuevoNodo;
        actual = getSiguiente(actual);
    }
    return nuevaLista;
};

int buscarDato(ListaPtr lista, void* datoBuscado, int (*compararFuncion)(void*, void*)) {
    if (lista == NULL || lista->primero == NULL) {
        return -1;  // Lista vacía o nula
    }

    NodoPtr actual = lista->primero;
    int posicion = 0;

    while (actual != NULL) {
        posicion= posicion +1;
        if (compararFuncion(getDato(actual), datoBuscado) == 0) {
            return posicion;  // Dato encontrado, devuelve la posición
        }
        actual = getSiguiente(actual);
    }

    return -1;  // Dato no encontrado
}

void insertarEnOrden(ListaPtr lista, DatoPtr dato, int (*compararFuncion)(DatoPtr, DatoPtr)){
    if (lista == NULL) {
        printf("Lista vacia\n");
        return;
    }
    NodoPtr nuevoNodo = crearNodo(dato, NULL);
    if (nuevoNodo == NULL){
        return;
    }
    if (lista->primero == NULL || compararFuncion(dato, getDato(lista->primero)) <= 0) {
        setSiguiente(nuevoNodo, lista->primero);
        lista->primero = nuevoNodo;
    } else {
        NodoPtr actual = lista->primero;
        while (getSiguiente(actual) != NULL && compararFuncion(getDato(getSiguiente(actual)), dato) < 0) {
            actual = getSiguiente(actual);
        }
        setSiguiente(nuevoNodo, getSiguiente(actual));
        setSiguiente(actual, nuevoNodo);
    }
}

int compararInt(void * d1, void * d2){
    int p1 = *(int*) d1;
    int p2 = *(int*) d2;

    return p1 > p2;
};

int compararFloat(void * d1, void * d2){
    float f1 = *(float*) d1;
    float f2 = *(float*) d2;

    return f1 > f2;
};

int compararChar(void * d1, void * d2) {
    char *p1 = (char *) d1;
    char *p2 = (char *) d2;

    return strcmp(p1, p2);
}

int compararDatoPtr(void * d1, void * d2){
    DatoPtr dato1 = *(DatoPtr *) d1;
    DatoPtr dato2 = *(DatoPtr *) d2;

    return getDato(dato1) > getDato(dato2);
}

void mostrarListaInt(ListaPtr lista){
    printf("LISTA\n");
    NodoPtr actual = lista->primero;

    while(actual != NULL){
        mostrarNodoInt(actual);
        actual = getSiguiente(actual);

        }
    printf("\n");
};

void mostrarListaFloat(ListaPtr lista){
    printf("LISTA\n");
    NodoPtr actual = lista->primero;

    while(actual != NULL){
        mostrarNodoFloat(actual);
        actual = getSiguiente(actual);

        }
    printf("\n");
};

void mostrarListaChar(ListaPtr lista){
    printf("LISTA\n");
    NodoPtr actual = lista->primero;

    while(actual != NULL){
        mostrarNodoChar(actual);
        actual = getSiguiente(actual);

        }
    printf("\n");
};

void liberarLista(ListaPtr lista){
    NodoPtr actual = lista->primero;

    while(actual != NULL){
        NodoPtr aux = actual;
        actual = getSiguiente(aux);
        free(aux);
        }
    free(lista);
};

void mostrarListaGenerico(ListaPtr lista, void(*mostrarFuncion)(DatoPtr)){
    printf("LISTA\n");
    NodoPtr actual = lista->primero;

    while(actual != NULL){
        (*mostrarFuncion)(getDato(actual));
        actual = getSiguiente(actual);

        }
    printf("\n");
};
