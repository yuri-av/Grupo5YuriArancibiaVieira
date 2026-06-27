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


Conjunto c_ej2_union(Conjunto A, Conjunto B){
    return cto_union(A,B);
}

Conjunto c_ej2_interseccion(Conjunto A, Conjunto B){
    return cto_interseccion(A,B);
}

Conjunto c_ej2_diferencia(Conjunto A, Conjunto B){
    return cto_diferencia(A,B);
}