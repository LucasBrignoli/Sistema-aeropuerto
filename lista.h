#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "nodo.h"

struct Lista;
typedef struct Lista * ListaPtr;

/**
 * @brief Crea una nueva lista vac�a
 * @pre Ninguna
 * @post Retorna un puntero a una nueva lista vac�a
 */
ListaPtr crearLista();

/**
 * @brief Inserta un dato al principio de la lista
 * @pre lista no es NULL
 * @post El nuevo dato se inserta al principio de la lista
 */
void insertarPrimero(ListaPtr lista, DatoPtr dato);

/**
 * @brief Inserta un dato al final de la lista
 * @pre lista no es NULL
 * @post El nuevo dato se inserta al final de la lista
 */
void insertarUltimo(ListaPtr lista, DatoPtr dato);

/**
 * @brief Inserta un dato en una posici�n espec�fica de la lista
 * @pre lista no es NULL, 0 <= posicion <= tama�o de la lista
 * @post El nuevo dato se inserta en la posici�n especificada
 */
void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion);

/**
 * @brief Obtiene el primer dato de la lista
 * @pre lista no es NULL y no est� vac�a
 * @post Retorna el primer dato de la lista
 */
DatoPtr obtenerPrimero(ListaPtr lista);

/**
 * @brief Obtiene el �ltimo dato de la lista
 * @pre lista no es NULL y no est� vac�a
 * @post Retorna el �ltimo dato de la lista
 */
DatoPtr obtenerUltimo(ListaPtr lista);

/**
 * @brief Obtiene el dato en una posici�n espec�fica de la lista
 * @pre lista no es NULL, 0 <= posicion < tama�o de la lista
 * @post Retorna el dato en la posici�n especificada
 */
DatoPtr obtenerPosicion(ListaPtr lista, int posicion);

/**
 * @brief Elimina el primer elemento de la lista
 * @pre lista no es NULL y no est� vac�a
 * @post El primer elemento de la lista es eliminado
 */
void eliminarPrimero(ListaPtr lista);

/**
 * @brief Elimina el �ltimo elemento de la lista
 * @pre lista no es NULL y no est� vac�a
 * @post El �ltimo elemento de la lista es eliminado
 */
void eliminarUltimo(ListaPtr lista);

/**
 * @brief Elimina el elemento en una posici�n espec�fica de la lista
 * @pre lista no es NULL, 0 <= posicion < tama�o de la lista
 * @post El elemento en la posici�n especificada es eliminado
 */
void eliminarPosicion(ListaPtr lista, int posicion);

/**
 * @brief Obtiene el primer nodo de la lista
 * @pre lista no es NULL
 * @post Retorna un puntero al primer nodo de la lista
 */
NodoPtr obtenerPrimerNodo(ListaPtr lista);

/**
 * @brief Obtiene el �ltimo nodo de la lista
 * @pre lista no es NULL
 * @post Retorna un puntero al �ltimo nodo de la lista
 */
NodoPtr obtenerUltimoNodo(ListaPtr lista);

/**
 * @brief Obtiene el nodo en una posici�n espec�fica de la lista
 * @pre lista no es NULL, 0 <= posicion < tama�o de la lista
 * @post Retorna un puntero al nodo en la posici�n especificada
 */
NodoPtr obtenerPosicionNodo(ListaPtr lista, int posicion);

/**
 * @brief Obtiene el tama�o de la lista
 * @pre lista no es NULL
 * @post Retorna el n�mero de elementos en la lista
 */
int obtenerTamanio(ListaPtr lista);

/**
 * @brief Ordena la lista in situ
 * @pre lista no es NULL
 * @post Los elementos de la lista est�n ordenados de menor a mayor
 */
void ordenarLista(ListaPtr lista, int(*ordenarFuncion)(DatoPtr, DatoPtr));

/**
 * @brief Crea una nueva lista ordenada a partir de la lista dada
 * @pre lista no es NULL
 * @post Retorna un puntero a una nueva lista con los mismos elementos ordenados
 */
ListaPtr ordenarListaCopia(ListaPtr lista);

/**
 * @brief Crea una copia de la lista
 * @pre lista no es NULL
 * @post Retorna un puntero a una nueva lista con los mismos elementos
 */
ListaPtr duplicarLista(ListaPtr lista);

/**
 * @brief Busca un dato en la lista
 * @pre lista no es NULL
 * @post Retorna la posici�n del dato si se encuentra, -1 si no
 */
int buscarDato(ListaPtr lista, DatoPtr datoBuscado, int (*compararFuncion)(DatoPtr, DatoPtr));

/**
 * @brief Compara dos enteros.
 * @pre d1 y d2 apuntan a enteros v�lidos.
 * @post Devuelve un entero menor que, igual a, o mayor que cero si el primer entero es menor, igual o mayor que el segundo, respectivamente.
 */
int compararInt(void * d1, void * d2);

/**
 * @brief Compara dos n�meros de punto flotante.
 * @pre d1 y d2 apuntan a floats v�lidos.
 * @post Devuelve un entero menor que, igual a, o mayor que cero si el primer float es menor, igual o mayor que el segundo, respectivamente.
 */
int compararFloat(void * d1, void * d2);

/**
 * @brief Compara dos caracteres.
 * @pre d1 y d2 apuntan a caracteres v�lidos.
 * @post Devuelve un entero menor que, igual a, o mayor que cero si el primer car�cter es menor, igual o mayor que el segundo, respectivamente.
 */
int compararChar(void * d1, void * d2);

/**
 * @brief Compara dos punteros de datos gen�ricos.
 * @pre d1 y d2 son punteros v�lidos.
 * @post Devuelve un entero menor que, igual a, o mayor que cero seg�n el resultado de la comparaci�n definida.
 */
int compararDatoPtr(void * d1, void * d2);

/**
 * @brief Inserta un dato en la lista manteniendo el orden
 * @pre lista no es NULL y est� ordenada
 * @post El nuevo dato se inserta manteniendo el orden de la lista
 */
void insertarEnOrden(ListaPtr lista, DatoPtr dato, int (*compararFuncion)(DatoPtr, DatoPtr));

/**
 * @brief Muestra el contenido de la lista int
 * @pre lista no es NULL
 * @post Imprime el contenido de la lista en la salida est�ndar
 */
void mostrarListaInt(ListaPtr lista);

/**
 * @brief Muestra el contenido de la lista float
 * @pre lista no es NULL
 * @post Imprime el contenido de la lista en la salida est�ndar
 */
void mostrarListaFloat(ListaPtr lista);

/**
 * @brief Muestra el contenido de la lista char
 * @pre lista no es NULL
 * @post Imprime el contenido de la lista en la salida est�ndar
 */
void mostrarListaChar(ListaPtr lista);

/**
 * @brief Muestra el contenido de la lista
 * @pre lista no es NULL
 * @post Imprime el contenido de la lista en la salida est�ndar
 */
void mostrarListaGenerico(ListaPtr lista, void(*mostrarFuncion)(DatoPtr));

/**
 * @brief Libera la memoria ocupada por la lista
 * @pre lista no es NULL
 * @post La memoria ocupada por la lista y sus nodos es liberada
 */
void liberarLista(ListaPtr lista);

#endif // LISTA_H_INCLUDED
