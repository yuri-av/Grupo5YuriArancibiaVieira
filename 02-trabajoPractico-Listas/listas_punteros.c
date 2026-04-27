#include "listas.h"
#include <stdlib.h>
#include <stdio.h>
#include "..\Tipos\tipo_elemento.h"

struct nodo
{
    TipoElemento datos;     // el dato que guardamos
    struct Nodo *siguiente; // puntero al próximo nodo
};

struct ListaRep
{
    struct Nodo *inicio; // Puntero al primer nodo de la lista
    int cantidad;        // Cantidad de elementos que tiene la lista
};

struct IteratorRep
{
    struct Nodo *posicionActual; // Un puntero para ir saltando de nodo en nodo
};
