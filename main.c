#include <stdio.h>
#include <stdlib.h>
#include "avion.h"
#include "pasajero.h"
#include "destino.h"
#include "aeropuerto.h"

int main()
{
    ///=================== CREAR =======================

    PasajeroPtr p1 = crearPasajero("Ramirez",1323232,'S');
    PasajeroPtr p2 = crearPasajero("Haarper",43541,'N');
    PasajeroPtr p3 = crearPasajero("Bones",16546,'N');
    PasajeroPtr p4 = crearPasajero("Freddie",645641,'S');

    AvionPtr a1 = crearAvion("Aerolineas",540,120);
    AvionPtr a2 = crearAvion("Airbus",420,160);
    AvionPtr a3 = crearAvion("JetSmart",280,200);

    DestinoPtr d1 = crearDestino("ITALIA",72.5,53.4);
    DestinoPtr d2 = crearDestino("JAPON",80.5,56.4);
    DestinoPtr d3 = crearDestino("ESTADOS UNIDOS",72.5,53.4);
    DestinoPtr d4 = crearDestino("ARGENTINA",80.5,56.4);
    DestinoPtr d5 = crearDestino("MEXICO",72.5,53.4);
    DestinoPtr d6 = crearDestino("URUGAY",80.5,56.4);

    AeropuertoPtr ae1 = crearAeropuerto("Internacional","Riccheri","11302429");

    ///=================== INSERTAR A LA LISTA =======================
    insertarPasajero(a1,p2);
    insertarPasajero(a3, p1);
    insertarPasajero(a2, p2);
    insertarPasajero(a2, p3);
    insertarPasajero(a2, p4);
    insertarDestino(a1,d1);
    insertarDestino(a2,d2);
    insertarDestino(a1,d2);
    insertarDestino(a3,d3);
    insertarDestino(a1,d4);
    insertarDestino(a2,d5);
    insertarDestino(a1,d6);
    insertarDestino(a3,d1);
    insertarAvion(ae1,a2);
    insertarAvion(ae1,a1);
    insertarAvion(ae1,a3);

    mostrarAeropuerto(ae1);
    ///Ordenar pasajes
    printf("================ SE ORDENAN LOS PASAJEROS ============\n");
    mostrarAvion(a2);
    printf("ORDENAR\n");
    ordenarPasajerosPorApellido(a2);
    mostrarAvion(a2);

    ///Eliminar pasajeros
    printf("================ SE ELIMINAN LOS PASAJEROS ============\n");
    printf("ELIMINAR\n");
    eliminarPasajero(a2,3);
    mostrarAvion(a2);
    insertarPasajero(a2, p4);
    ///Buscar pasajeros... AVIONES...
    printf("================ SE BUSCAN LOS PASAJEROS ============\n");
    PasajeroPtr pasajeroBuscado = crearPasajero("Freddie", 1323232, 'S');
    int posicion = buscarDato(getListaPasajeros(a2), pasajeroBuscado, compararPasajeros);
    printf("POSICION: %d\n", posicion);

    ///ORDENAR DESTINOS
    printf("================ SE ORDENAN LOS DESTINOS ============\n");
    ordenarDestinoPtr(a1);
    mostrarAvion(a1);
    ///ELIMINAR DESTINOS
    printf("================ SE ELIMINAN LOS DESTINOS ============\n");
    eliminarDestino(a1, 3);
    mostrarAvion(a1);
    insertarDestino(a1,d2);
    printf("================ SE BUSCAN LOS DESTINOS ============\n");
    DestinoPtr destinoBuscado = crearDestino("JAPON",80.5,56.4);
    int pos = buscarDato(getDestinos(a1) ,destinoBuscado ,&compararDestino);
    printf("EL DESTINO QUE BUSCA ESTA EN LA POSICION: %d", pos);

    ///ORDENAR AVIONES
    mostrarAeropuerto(ae1);
    printf("================ SE ORDENAN LOS AVIONES ============\n");
    ordenarAviones(ae1);
    mostrarAeropuerto(ae1);
    printf("================ SE ELIMINAN LOS AVIONES ============\n");
    eliminarAvion(ae1, 2);
    mostrarAeropuerto(ae1);
    insertarAvion(ae1, a2);
    return 0;
}
