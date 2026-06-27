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

bool c_ej4_transitividad(Conjunto A, Conjunto B, Conjunto C){
for (int i = 1; i< cto_cantidad_elementos(A);i++){
    TipoElemento sig = cto_recuperar(A,i);
    if (!cto_pertenece(B,sig->clave)){
        return false;
    }
}
for (int i = 1;i<cto_cantidad_elementos(B);i++){
    TipoElemento sig = cto_recuperar(B,i);
    if (!cto_pertenece(C,sig->clave)){
        return false;
    }
}
return true;
}