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

Conjunto c_ej5_dif_simetrica(Conjunto A, Conjunto B){
    Conjunto ctoauxA = cto_crear();
    Conjunto ctoauxB = cto_crear();
    Conjunto ctoauxC = cto_crear();
    ctoauxA = cto_diferencia(A,B);
    ctoauxB = cto_diferencia(B,A);
    ctoauxC = cto_union(ctoauxA,ctoauxB);
    return ctoauxC;
}