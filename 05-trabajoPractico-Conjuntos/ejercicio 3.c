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

Conjunto c_ej3_uniones(Lista l_de_conjuntos){
    Conjunto ctoaux = cto_crear();
    Iterador it = iterador(l_de_conjuntos);
        while (hay_siguiente(it)){
            TipoElemento sig = siguiente(it);
            ctoaux = cto_union(ctoaux,sig->valor);
        }
        return ctoaux;
}

Conjunto c_ej3_intersecciones(Lista l_de_conjuntos){
    Conjunto ctoaux = cto_crear();
    if (l_es_vacia(l_de_conjuntos)){
        return ctoaux;
    }
    ctoaux = cto_union(ctoaux, sig->valor);
    Iterador it = iterador(l_de_conjuntos);
    TipoElemento sig = siguiente(it); 
    cto_agregar(sig->valor);
    while(hay_siguiente(it)){
        TipoElemento sig = siguiente(it);
        ctoaux = cto_interseccion(ctoaux,sig->valor);
    }
    return ctoaux;
}