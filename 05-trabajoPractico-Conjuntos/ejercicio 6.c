#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tipo_elemento.h"
#include "listas.h"
#include "tipo_elemento.c"
#include "listas_arreglos.c"
#include "listas_cursores.c"
#include "listas_punteros.c"
#include "conjuntos_listas.c"
#include "conjuntos.h"

bool c_ej6_subconjuntopropio(Conjunto A, Conjunto B){

    if(cto_cantidad_elementos(A) >= cto_cantidad_elementos(B)){
        return false;
    }

    for(int i = 1; i <= cto_cantidad_elementos(A); i++){

        TipoElemento sig = cto_recuperar(A, i);

        if(!cto_pertenece(B, sig->clave)){
            return false;
        }
    }

    return true;
}

// Complejidad cuadratica porque se recorre un conjunto completo y, 
// para cada elemento, se realiza una búsqueda lineal en el otro conjunto.