#ifndef PASAJERO_H_INCLUDED
#define PASAJERO_H_INCLUDED

struct pasajeroE;

typedef struct pasajeroE * PasajeroPtr;

PasajeroPtr crearPasajero(char* apellido,int dni,char ventanilla);

void mostrarPasajero(PasajeroPtr p);
void mostrarPasajeroDatoPtr(void * d1);

void liberarPasajero(PasajeroPtr p);

///GETTERS Y SETTERS
//getters
char* getApellido(PasajeroPtr p);
int getDni(PasajeroPtr p);
char getVentanilla(PasajeroPtr p);
//setters
void setApellido(PasajeroPtr p, char* nuevoApellido);
void setDni(PasajeroPtr p, int nuevoDni);
void setVentanilla(PasajeroPtr p, char nuevoVentanilla);

#endif // PASAJERO_H_INCLUDED
