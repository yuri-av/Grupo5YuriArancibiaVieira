#include "listas.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

void cargar_listas(Lista lista, int cantidad, int opcion);
void CompararListas(Lista l1, Lista L2);

int main()
{
    srand(time(NULL));
    Lista l1 = l_crear();
    Lista l2 = l_crear();
    // Contador de claves mayores
    int c_mayores1 = 0;
    int c_mayores2 = 0;

    // Tamaño de las listas
    int cantidad = 0;
    char car;
    int opcion;
    printf("Ingrese la cantidad de elementos a agregar a las listas: ");

    // Validacion de dato
    while (scanf("%d%c", &cantidad, &car) != 2 || car != '\n')
    {
        printf("ERROR: Ingrese una cantidad con numeros enteros: ");
        if (car != '\n')
        {
            while (getchar() != '\n')
                ;
        }
    }

    // Modalidad de carga de las listas
    printf("Desea cargar las listas con elementos aleatorios? (1 para aleatorio, 0 para manual): ");

    // Validacion de dato
    while (scanf("%d%c", &opcion, &car) != 2 || car != '\n' || (opcion != 0 && opcion != 1))
    {
        printf("Opcion invalida. Ingrese 1 para aleatorio o 0 para manual: ");
        if (car != '\n')
        {
            while (getchar() != '\n')
                ;
        }
    }

    // Llenamos las listas según la opción elegida
    cargar_listas(l1, cantidad, opcion);
    cargar_listas(l2, cantidad, opcion);
    /*Cargar listas 1 y 2 tienen una complejidad de O(N), quiere decir
    que crece su complejidad proporcionalmente al tamaño de la lista, o las listas*/

    // Mostramos las listas cargadas
    printf("Lista 1: ");
    l_mostrar(l1);
    printf("Lista 2: ");
    l_mostrar(l2);

    // Calculamos los totales
    comparacion(l1, l2, &c_mayores1, &c_mayores2);
    // La funcion comparación tiene una complejidad de O(N) que crece proporcionalmente al tamaño de las listas

    // Los comparamos para ver cual es más grande o si son iguales
    if (c_mayores1 > c_mayores2)
    {
        printf("L1 tiene mas claves mayores que L2\n");
    }
    else if (c_mayores1 < c_mayores2)
    {
        printf("L1 tiene menos claves mayores que L2\n");
    }
    else
    {
        printf("Ambas listas tienen la misma cantidad de claves mayores\n");
    }
    return 0;

    /*================================== NOTAS =====================================
    Como en todas las funciones empleadas, tanto de carga como de comparación
    de las listas siempre se utilizan bucles for o while, la complejidad pasa a ser
    de 3N, pero como no se tienen en cuenta las constantes, solo tenemos en cuenta
    que tienen una complejidad de O(N)
    ===============================================================================*/
}

void cargar_listas(Lista lista, int cantidad, int opcion)
{
    char car;
    // Opcion aleatoria
    if (opcion == 1)
    {
        for (int i = 0; i < cantidad; i++)
        {
            int clave = rand() % 100;
            TipoElemento te = te_crear(clave);
            l_agregar(lista, te);
        }
    }
    // Opcion manual
    else if (opcion == 0)
    {
        for (int i = 0; i < cantidad; i++)
        {
            int clave;
            printf("Ingrese la clave del elemento %d: ", i + 1);
            while (scanf("%d%c", &clave, &car) != 2 || car != '\n')
            {
                printf("ERROR: NUMERO INVALIDO\n");
                printf("Ingrese un numero entero: ");
                if (car != '\n')
                {
                    while (getchar() != '\n')
                        ;
                }
            }
            TipoElemento te = te_crear(clave);
            l_agregar(lista, te);
        }
    }
}

void comparacion(Lista l1, Lista l2, int *c_mayores1, int *c_mayores2)
{
    int clave_actual_l1 = 0;
    int clave_actual_l2 = 0;
    // Verificamos que no tengan longitudes distintas o que no estén vacías
    if (l_longitud(l1) != l_longitud(l2))
    {
        printf("Las longitudes de las listas no coinciden, no se pueden comparar\n");
        return;
    }
    else if (l_es_vacia(l1) || l_es_vacia(l2))
    {
        printf("Error: una o ambas listas estan vacias\n");
        return;
    }

    Iterador iter1 = iterador(l1);
    Iterador iter2 = iterador(l2);

    while (hay_siguiente(iter1))
    {
        TipoElemento te1 = siguiente(iter1);
        clave_actual_l1 = te1->clave;
        TipoElemento te2 = siguiente(iter2);
        clave_actual_l2 = te2->clave;
        // Comparamos cada clave
        if (clave_actual_l1 > clave_actual_l2)
        {
            // los paréntesis son para que sume 1 al valor CONTENIDO en la dirección de memoria y no a la dirección de memoria
            (*c_mayores1)++;
        }
        else if (clave_actual_l1 < clave_actual_l2)
        {
            (*c_mayores2)++;
        }
        // Si son iguales las claves no hacemos nada
    }
}