#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tp_4_colas.h"
#include "../libs/colas/headers/colas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"

// Complejidad Algoritmica: O(n**2)
int contador(Cola c);
int cant_divisiones(Cola c, TipoElemento sig);


int c_ej5_divisortotal(Cola c, bool *fuetotal){

    TipoElemento sig;
    Cola caux = c_crear();
    int cantidadElementos = contador(c);
    int divisorEncontrado = 0;

    while(!c_es_vacia(c)){

        sig = c_desencolar(c);

        int divisiones = cant_divisiones(c, sig);

        // Si es divisor total
        if(divisiones == cantidadElementos - 1){
            *fuetotal = true;
            divisorEncontrado = sig->clave;
            c_encolar(caux, sig);
            
            // Devolver el resto a la cola original
            while(!c_es_vacia(c)){
                sig = c_desencolar(c);
                c_encolar(caux, sig);
            }
            break;
        }
        // Si es divisor parcial (al menos 50%)
        else if(divisiones >= cantidadElementos / 2){
            *fuetotal = false;
            divisorEncontrado = sig->clave;
            c_encolar(caux, sig);
            
            // Devolver el resto a la cola original
            while(!c_es_vacia(c)){
                sig = c_desencolar(c);
                c_encolar(caux, sig);
            }
            break;
        }

        c_encolar(caux, sig);
    }

    // Restaurar la cola original
    while(!c_es_vacia(caux)){
        sig = c_desencolar(caux);
        c_encolar(c, sig);
    }

    return divisorEncontrado;
}


int contador(Cola c){

    Cola aux = c_crear();

    TipoElemento x;

    int cont = 0;

    while(!c_es_vacia(c)){

        x = c_desencolar(c);

        cont++;

        c_encolar(aux, x);
    }

    while(!c_es_vacia(aux)){

        x = c_desencolar(aux);

        c_encolar(c, x);
    }

    return cont;
}


int cant_divisiones(Cola c, TipoElemento sig){

    Cola aux = c_crear();

    TipoElemento x;

    int cont = 0;

    while(!c_es_vacia(c)){

        x = c_desencolar(c);

        if(x->clave != sig->clave){

            if(x->clave % sig->clave == 0){

                cont++;
            }
        }

        c_encolar(aux, x);
    }

    while(!c_es_vacia(aux)){

        x = c_desencolar(aux);

        c_encolar(c, x);
    }

    return cont;
}
