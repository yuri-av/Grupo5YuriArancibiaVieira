#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tp_2_listas.h"
#include "listas.h"
#include "tipo_elemento.h"

bool esSublista(Lista l1, Lista l2);

int main(){
    int cantidad;
    int elemento;
    int control;    

    Lista l1 = l_crear();
    Lista l2 = l_crear();

    printf("=== VERIFICAR SUBLISTAS ===\n");
    printf("Cargue la primer lista."\n);
    printf("Ingrese la cantidad de elementos de la lista 1.\n");
    control = scanf("%d", &cantidad);

    while (cantidad <= 0 || control != 1){
        printf("INGRESO INVALIDO. Ingrese un número mayor a 0.\n");
        while (getchar() != '\n');
        scanf("%d",cantidad1);
    }
    for (int i= 0; i<cantidad; i++){
        printf("Ingrese el elemeto %d de la lista 1.",i+1);
        control = scanf("%d", &elemento);
        while (control != 1){
        printf("INGRESO INVALIDO. Ingrese un número.\n");
        while (getchar() != '\n');
        scanf("%d",&elemento);
        }
        l_agregar(l1, te_crear(elemento));
    }
    
    printf("Cargue la segunda lista."\n);
    printf("Ingrese la cantidad de elementos de la lista 1.\n");
    control = scanf("%d", &cantidad1);

    while (cantidad <= 0 || control != 1){
        printf("INGRESO INVALIDO. Ingrese un número mayor a 0.\n");
        while (getchar() != '\n');
        scanf("%d",&cantidad);
    }
    for (int i= 0; i<cantidad; i++){
        printf("Ingrese el elemeto %d de la lista 2.",i+1);
        control = scanf("%d", &elemento);
        while (control != 1){
        printf("INGRESO INVALIDO. Ingrese un número.\n");
        while (getchar() != '\n');
        scanf("%d",&elemento);
        }
        l_agregar(l2, te_crear(elemento));
    }

 
    printf("\nLista 1:\n");
    l_mostrar(l1);

    printf("\nLista 2:\n");
    l_mostrar(l2);

        /* VERIFICAR EN AMBOS SENTIDOS */

    if (esSublista(l1, l2))
    {
        printf("\nLa Lista 2 es sublista de la Lista 1.\n");
    }
    else
    {
        printf("\nLa Lista 2 NO es sublista de la Lista 1.\n");
    }

    if (esSublista(l2, l1))
    {
        printf("La Lista 1 es sublista de la Lista 2.\n");
    }
    else
    {
        printf("La Lista 1 NO es sublista de la Lista 2.\n");
    }


    return 0;
}

bool esSublista(Lista l1, Lista l2)
{
    Iterador it = iterador(l2);

    while (hay_siguiente(it))
    {
        TipoElemento elem = siguiente(it);

        if (l_buscar(l1, elem->clave) == NULL)
        {
            return false;
        }
    }

    return true;
}