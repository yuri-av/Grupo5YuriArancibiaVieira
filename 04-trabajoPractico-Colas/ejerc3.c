#include "colas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "tipo_elemento.h"


/*Dadas dos colas, determinar si sus contenidos son iguales tanto en posición como en datos (solo comparar por la clave), sin destruirlas. Utilizar para la resolución
del problema una sola cola auxiliar. Determinar la complejidad algorítmica del problema. */

bool c_ej3_iguales(Cola c1, Cola c2) {
    Cola caux = c_crear();
    bool iguales = true;

    while (!c_es_vacia(c1) && !c_es_vacia(c2)) {
        TipoElemento x = c_desencolar(c1);
        TipoElemento y = c_desencolar(c2);

        if (x->clave != y->clave) {
            iguales = false;
        }

        c_encolar(caux, x);
        c_encolar(caux, y);
    }

    if (!c_es_vacia(c1) || !c_es_vacia(c2)) {
    iguales = false;
    }

    while (!c_es_vacia(caux)) {
        TipoElemento x = c_desencolar(caux);
        c_encolar(c1, x);
        
        TipoElemento y = c_desencolar(caux);
        c_encolar(c2, y);
    }

    return iguales;
}

#include <stdio.h>
#include <stdlib.h>
#include "colas.h"   // o el nombre que uses
#include "tipo_elemento.h"

bool c_ej3_iguales(Cola c1, Cola c2); // tu función

int main() {
    Cola c1 = c_crear();
    Cola c2 = c_crear();

    int n1, n2, valor;

    printf("Cantidad de elementos de la cola 1: ");
    scanf("%d", &n1);

    printf("Ingrese los elementos de la cola 1:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &valor);
        c_encolar(c1, te_crear(valor));
    }

    printf("\nCantidad de elementos de la cola 2: ");
    scanf("%d", &n2);

    printf("Ingrese los elementos de la cola 2:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &valor);
        c_encolar(c2, te_crear(valor));
    }


    if (c_ej3_iguales(c1, c2)) {
        printf("\nLas colas SON iguales\n");
    } else {
        printf("\nLas colas NO son iguales\n");
    }

    return 0;
}

/*Complejidad: O(n) */