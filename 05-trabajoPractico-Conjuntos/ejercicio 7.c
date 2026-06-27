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

void c_ej7_subconjtotalparcial(Conjunto A, Conjunto B, Conjunto C){
comparar(A,B);
comparar(B,A);

comparar(A,C);
comparar(C,A);

comparar(B,C);
comparar(C,B);
} 

int Contar_Coincidencias(Conjunto A,Cojunto B){
    int contador = 0;
    for (int i = 1; i <= cto_cantidad_elementos(A);i++){
    TipoElemento sig = cto_recuperar(A,i);
    if (cto_pertenece(B,sig->clave)){
        contador ++;
    }
}
    return contador;
}

void comparar(Conjunto A,Conjunto B){
    int cant = Contar_Coincidencias(A,B);
    if (cant == cto_cantidad_elementos(A)){
        printf("El primero es subconjunto total del segundo.");
    }
    else if (cant >= (cto_cantidad_elementos(A) / 2)){
                printf("El primero es subconjunto parcial del segundo.");
    }
    else{
        printf("El primero no es subconjunto del segundo.");
    }
}

// Complejidad cuadrática.