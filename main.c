#include <stdio.h>
#include <stdlib.h>
#include "pasajero.h"
#include "destino.h"
#include "aeropuerto.h"
#include "avion.h"

int main()
{
    PasajeroPtr p1 = crearPasajero("Ramirez",1323232,'S');
    PasajeroPtr p2 = crearPasajero("Haarper",43541,'N');
    PasajeroPtr p3 = crearPasajero("Bones",16546,'N');
    PasajeroPtr p4 = crearPasajero("Freddie",645641,'S');

    AvionPtr a1 = crearAvion("Aerolineas",540,120);
    AvionPtr a2 = crearAvion("Airbus",420,160);
    AvionPtr a3 = crearAvion("JetSmart",280,200);

    DestinoPtr d1 = crearDestino("ITALIA",72.5,53.4);
    DestinoPtr d2 = crearDestino("JAPON",80.5,56.4);

    AeropuertoPtr ae1 = crearAeropuerto("Internacional","Riccheri","11302429");

    insertarPasajero(a1,p2);
    insertarPasajero(a3, p1);
    insertarPasajero(a2, p3);
    insertarPasajero(a2, p4);
    insertarDestino(a1,d1);
    insertarDestino(a2,d2);
    insertarDestino(a1,d2);
    insertarDestino(a3,d1);
    insertarAvion(ae1,a1);
    insertarAvion(ae1,a2);
    insertarAvion(ae1,a3);

    mostrarAeropuerto(ae1);

     ///Ordenar pasajes
    ///Eliminar pasajeros
    ///Buscar pasajeros... AVIONES...

    ///Destinos!!!!

    ///Calcular distancia de destinos
    ///Ordenar por distancia...

    return 0;
}
