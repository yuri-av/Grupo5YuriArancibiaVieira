#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tp_colas.h"
#include "colas.h"
#include "tipo_elemento.h"


int contador(Cola c);
int cant_divisiones(Cola c, TipoElemento sig);


Cola c_ej5_divisortotal(Cola c){

    TipoElemento sig;

    Cola nueva = c_crear();
    Cola caux = c_crear();

    int cantidadElementos = contador(c);

    while(!c_es_vacia(c)){

        sig = c_desencolar(c);

        int divisiones = cant_divisiones(c, sig);

        bool *esTotal = malloc(sizeof(bool));

        if(divisiones == cantidadElementos - 1){

            *esTotal = true;

            TipoElemento nuevo =
                te_crear_con_valor(
                    sig->clave,
                    esTotal
                );

            c_encolar(nueva, nuevo);
        }
        else if(divisiones >= cantidadElementos / 2){

            *esTotal = false;

            TipoElemento nuevo =
                te_crear_con_valor(
                    sig->clave,
                    esTotal
                );

            c_encolar(nueva, nuevo);
        }

        c_encolar(caux, sig);
    }

    while(!c_es_vacia(caux)){

        sig = c_desencolar(caux);

        c_encolar(c, sig);
    }

    return nueva;
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


int main(){

    Cola c = c_crear();

    int cantidad;
    int numero;

    printf("====================================\n");
    printf("EJERCICIO 5 - DIVISORES TOTALES\n");
    printf("====================================\n\n");

    printf("Cantidad de elementos: ");
    scanf("%d",&cantidad);

    while(cantidad <= 0 || cantidad > TAMANIO_MAXIMO){

        printf("Cantidad invalida. Reingrese: ");
        scanf("%d",&cantidad);
    }

    for(int i=0;i<cantidad;i++){

        printf("Ingrese elemento %d (>=2): ",
               i+1);

        scanf("%d",&numero);

        while(numero < 2){

            printf("Valor invalido. Reingrese: ");
            scanf("%d",&numero);
        }

        c_encolar(
            c,
            te_crear(numero)
        );
    }

    printf("\nCola ingresada:\n");
    c_mostrar(c);

    Cola resultado =
        c_ej5_divisortotal(c);

    printf("\nResultado:\n");

    if(c_es_vacia(resultado)){

        printf("No existen divisores.\n");
    }
    else{

        TipoElemento x;

        while(!c_es_vacia(resultado)){

            x = c_desencolar(resultado);

            bool esTotal =
                *((bool*)x->valor);

            if(esTotal){

                printf(
                    "%d -> Divisor TOTAL\n",
                    x->clave
                );
            }
            else{

                printf(
                    "%d -> Divisor PARCIAL\n",
                    x->clave
                );
            }
        }
    }

    return 0;
}