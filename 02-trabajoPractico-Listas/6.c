#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tp_2_listas.h"
#include "listas.h"
#include "tipo_elemento.h"

int validacion_ingreso();
Lista rellenarLista(int elementos);
bool esSublista(Lista l1, Lista l2);

int main()
{
    int cantidad;
    int elemento;
    int control;

    Lista l1 = l_crear();
    Lista l2 = l_crear();

    printf("=== VERIFICAR SUBLISTAS ===\n");
    printf("Cargue la primer lista."\n);
    printf("Ingrese la cantidad de elementos de la lista 1.\n");
    control = scanf("%d", &cantidad);

    while (cantidad <= 0 || control != 1)
    {
        printf("INGRESO INVALIDO. Ingrese un número mayor a 0.\n");
        while (getchar() != '\n')
            ;
        scanf("%d", cantidad1);
    }
    for (int i = 0; i < cantidad; i++)
    {
        printf("Ingrese el elemeto %d de la lista 1.", i + 1);
        control = scanf("%d", &elemento);
        while (control != 1)
        {
            printf("INGRESO INVALIDO. Ingrese un número.\n");
            while (getchar() != '\n')
                ;
            scanf("%d", &elemento);
        }
        l_agregar(l1, te_crear(elemento));
    }

    printf("Cargue la segunda lista."\n);
    printf("Ingrese la cantidad de elementos de la lista 1.\n");
    control = scanf("%d", &cantidad1);

    while (cantidad <= 0 || control != 1)
    {
        printf("INGRESO INVALIDO. Ingrese un número mayor a 0.\n");
        while (getchar() != '\n')
            ;
        scanf("%d", &cantidad);
    }
    for (int i = 0; i < cantidad; i++)
    {
        printf("Ingrese el elemeto %d de la lista 2.", i + 1);
        control = scanf("%d", &elemento);
        while (control != 1)
        {
            printf("INGRESO INVALIDO. Ingrese un número.\n");
            while (getchar() != '\n')
                ;
            scanf("%d", &elemento);
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

int validacion_ingreso()
{
    int numero;
    char car;

    while (scanf("%d%c", &numero, &car) != 2 || car != '\n')
    {
        // Mensaje genérico para cualquier número entero
        printf("Opcion invalida. Ingrese un numero entero: ");

        // Limpieza del buffer de entrada
        if (car != '\n')
        {
            while (getchar() != '\n')
                ;
        }
    }

    // Retornamos el valor ya validado
    return numero;
}
// Asumimos que validacion_ingreso() ya esta definida antes de esta funcion

Lista rellenarLista(int elementos)
{
    Lista lista = l_crear();
    int opcion;

    // Modalidad de carga de las listas
    printf("Desea cargar la lista con elementos aleatorios? (1 para aleatorio, 0 para manual):\n");

    // Validacion especifica para 0 o 1
    do
    {
        opcion = validacion_ingreso(); // Nos aseguramos de que ingrese un numero entero

        if (opcion != 0 && opcion != 1)
        {
            printf("Opcion invalida. Ingrese 1 para aleatorio o 0 para manual: ");
        }
    } while (opcion != 0 && opcion != 1);

    // Opcion aleatoria
    if (opcion == 1)
    {
        for (int i = 0; i < elementos; i++) // Usamos 'elementos' en lugar de 'cantidad'
        {
            int clave = rand() % 100;
            TipoElemento te = te_crear(clave);
            l_agregar(lista, te); // Usamos 'l1'
        }
    }
    // Opcion manual
    else if (opcion == 0)
    {
        for (int i = 0; i < elementos; i++) // Usamos 'elementos' en lugar de 'cantidad'
        {
            printf("Ingrese la clave del elemento %d: ", i + 1);

            // Reemplazamos todo el bucle de limpieza y scanf por tu funcion generica
            int clave = validacion_ingreso();

            TipoElemento te = te_crear(clave);
            l_agregar(lista, te); // Usamos 'l1'
        }
    }

    return lista; // Devolvemos la lista ya rellenada
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