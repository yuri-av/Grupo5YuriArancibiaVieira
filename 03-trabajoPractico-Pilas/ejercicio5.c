#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilas.h"
#include "tipo_elemento.h"

/* Invertir el contenido de una pila sin destruir la pila original. Se debe retornar la nueva pila invertida y la original no se 
debe perder. Determinar la complejidad algorítmica de la solución. */

Pila  p_ej5_invertir(Pila p) {
    Pila Paux = p_crear();
    Pila nueva = p_crear();
    TipoElemento x;

    while (!p_es_vacia(p)) {
        x = p_desapilar(p);
        p_apilar(nueva, x);
        p_apilar(Paux, x);
    }

    while (!p_es_vacia(Paux)) { 
        x = p_desapilar(Paux);
        p_apilar(p,x);
    }

    return nueva; 
}

int main() {
    Pila p = p_crear();

    int n, valor;
    printf("Ingrese cantidad de elementos para P1: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Ingrese valor %d para P1: ", i + 1);
        scanf("%d", &valor);

        TipoElemento te = te_crear(valor);
        p_apilar(p, te);
    }

    printf("\nPila original: ");
    p_mostrar(p);

    Pila invertida = p_ej5_invertir(p);

    printf("\nPila invertida: ");
    p_mostrar(invertida);

    return 0;
}