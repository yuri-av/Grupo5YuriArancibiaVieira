#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "tp_2_listas.h"
#include "listas.h"
#include "tipo_elemento.h"

int validacion_ingreso();
Lista rellenarLista(int elementos);
bool esSublista(Lista l1, Lista l2);

int main()
{
    srand(time(NULL));

    int cantidad1, cantidad2;

    printf("=== VERIFICAR SUBLISTAS ===\n");

    /* ================= CARGA DE LISTA 1 ================= */
    printf("\n--- Carga de la Lista 1 ---\n");
    printf("Ingrese la cantidad de elementos de la lista 1: ");
    cantidad1 = validacion_ingreso();

    while (cantidad1 <= 0)
    {
        printf("INGRESO INVALIDO. Ingrese un numero mayor a 0: ");
        cantidad1 = validacion_ingreso();
    }

    Lista l1 = rellenarLista(cantidad1);

    /* ================= CARGA DE LISTA 2 ================= */
    printf("\n--- Carga de la Lista 2 ---\n");
    printf("Ingrese la cantidad de elementos de la lista 2: ");
    cantidad2 = validacion_ingreso();

    while (cantidad2 <= 0)
    {
        printf("INGRESO INVALIDO. Ingrese un numero mayor a 0: ");
        cantidad2 = validacion_ingreso();
    }

    Lista l2 = rellenarLista(cantidad2);

    /* ================= MOSTRAR Y EVALUAR ================= */
    printf("\nLista 1:\n");
    l_mostrar(l1);

    printf("\nLista 2:\n");
    l_mostrar(l2);

    // VERIFICAR EN AMBOS SENTIDOS
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

int validacion_ingreso()
{
    int numero;
    char car = '\0';

    while (scanf("%d%c", &numero, &car) != 2 || car != '\n')
    {
        printf("Opcion invalida. Ingrese un numero entero: ");

        if (car != '\n')
        {
            while (getchar() != '\n')
                ;
        }
        car = '\0'; // Reseteamos para la próxima vuelta
    }

    return numero;
}

Lista rellenarLista(int elementos)
{
    Lista lista = l_crear();
    int opcion;

    printf("Desea cargar la lista con elementos aleatorios? (1 para aleatorio, 0 para manual):\n");

    do
    {
        opcion = validacion_ingreso();

        if (opcion != 0 && opcion != 1)
        {
            printf("Opcion invalida. Ingrese 1 para aleatorio o 0 para manual: ");
        }
    } while (opcion != 0 && opcion != 1);

    if (opcion == 1)
    {
        for (int i = 0; i < elementos; i++)
        {
            int clave = rand() % 100;
            TipoElemento te = te_crear(clave);
            l_agregar(lista, te);
        }
    }
    else if (opcion == 0)
    {
        for (int i = 0; i < elementos; i++)
        {
            printf("Ingrese la clave del elemento %d: ", i + 1);
            int clave = validacion_ingreso();
            TipoElemento te = te_crear(clave);
            l_agregar(lista, te);
        }
    }

    return lista;
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