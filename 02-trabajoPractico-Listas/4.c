#include "listas.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

int validacion_ingreso();
Lista rellenarLista(int elementos);
void CompararListas(Lista l1, Lista l2);

int main()
{
    srand(time(NULL));
    Lista l1, l2;
    int cantidad = 0;

    printf("Ingrese la cantidad de elementos a agregar a las listas: ");
    cantidad = validacion_ingreso();

    // Llenamos las listas
    printf("\n--- Carga de la Lista 1 ---\n");
    l1 = rellenarLista(cantidad);

    printf("\n--- Carga de la Lista 2 ---\n");
    l2 = rellenarLista(cantidad);

    // Mostramos las listas cargadas
    printf("\nLista 1: ");
    l_mostrar(l1);
    printf("Lista 2: ");
    l_mostrar(l2);

    // Comparamos las listas
    CompararListas(l1, l2);

    /*================================== NOTAS =====================================
    Complejidad: O(N)
    Como en todas las funciones empleadas, tanto de carga como de comparación
    de las listas siempre se utilizan bucles for o while, la complejidad pasa a ser
    de 3N, pero como no se tienen en cuenta las constantes, solo tenemos en cuenta
    que tienen una complejidad de O(N).
    ===============================================================================*/

    return 0;
}

int validacion_ingreso()
{
    int numero;
    char car = '\0'; // Inicializamos limpia

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

void CompararListas(Lista l1, Lista l2)
{
    int c_mayores1 = 0;
    int c_mayores2 = 0;

    // Verificamos que no tengan longitudes distintas o que no estén vacías
    if (l_longitud(l1) != l_longitud(l2))
    {
        printf("\nLas longitudes de las listas no coinciden, no se pueden comparar\n");
        return;
    }
    if (l_es_vacia(l1) || l_es_vacia(l2))
    {
        printf("\nError: una o ambas listas estan vacias\n");
        return;
    }

    Iterador iter1 = iterador(l1);
    Iterador iter2 = iterador(l2);

    while (hay_siguiente(iter1))
    {
        TipoElemento te1 = siguiente(iter1);
        TipoElemento te2 = siguiente(iter2);

        // Comparamos directamente las claves sin variables temporales
        if (te1->clave > te2->clave)
        {
            c_mayores1++;
        }
        else if (te1->clave < te2->clave)
        {
            c_mayores2++;
        }
        // Si son iguales las claves no hacemos nada
    }

    // Imprimimos el resultado final dentro de la función
    if (c_mayores1 > c_mayores2)
    {
        printf("\nL1 tiene mas claves mayores que L2\n");
    }
    else if (c_mayores1 < c_mayores2)
    {
        printf("\nL1 tiene menos claves mayores que L2\n");
    }
    else
    {
        printf("\nAmbas listas tienen la misma cantidad de claves mayores\n");
    }
}