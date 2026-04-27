#include "listas.h"
#include <stdlib.h>
#include <stdio.h>
#include "./tipo_elemento.h"

struct NodoCursor
{
    TipoElemento datos;
    int siguiente; // indice del próximo nodo en MEMORIA, o -1 si es el último
};

// Memoria simulada

static struct NodoCursor MEMORIA[TAMANIO_MAXIMO];

// Variable auxiliar para saber qué casilleros de MEMORIA están libres

static int libre = 0;

// struct para la Lista
struct ListaRep
{
    int inicio; // Índice donde arranca esta lista
    int cantidad;
};

// struct para el Iterador
struct IteradorRep
{
    int posicionActual; // El índice por el que vamos iterando
};
