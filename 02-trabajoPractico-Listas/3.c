#include "listas.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

int validacion_ingreso();
void cargar_listas(Lista lista, int cantidad, int opcion);
void es_multiplo(Lista l1, Lista l2);

int main()
{
    srand(time(NULL));
    Lista l1 = l_crear();
    Lista l2 = l_crear();
    char car;
    int cantidad, opcion;

    // Tamaño de las listas
    printf("Ingrese la cantidad de elementos a agregar a las listas: ");

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

    // Mostramos las listas cargadas
    printf("Lista 1: ");
    l_mostrar(l1);
    printf("Lista 2: ");
    l_mostrar(l2);

    // Verificamos multiplicidad
    es_multiplo(l1, l2);

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
void es_multiplo(Lista l1, Lista l2)
{
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

    bool flag = true;
    Iterador iter1 = iterador(l1);
    Iterador iter2 = iterador(l2);
    bool es_escalar = true;
    int primer_cociente = -1;

    while (hay_siguiente(iter1) && flag)
    {
        TipoElemento te1 = siguiente(iter1);
        TipoElemento te2 = siguiente(iter2);

        // No son multiplos uno de otro
        if (te2->clave % te1->clave != 0 || te1->clave == 0)
        {
            flag = false;
            es_escalar = false;
        }
        // En caso de que sea multiplo el numero actual
        else
        {
            int cociente_actual = te2->clave / te1->clave;
            printf("%i / %i = %i\n", te2->clave, te1->clave, cociente_actual);

            // Primera iteración asigna valor a primer cociente
            if (primer_cociente == -1)
            {
                primer_cociente = cociente_actual;
                printf("Primer cociente de la lista: %i\n", primer_cociente);
            }
            // Caso de que no sea igual al anterior cociente
            else if (cociente_actual != primer_cociente)
            {
                printf("Se encontró un valor que hace que no sea escalar\n");
                es_escalar = false;
            }
            // Else implicito, si no son distintos entonces es_escalar = true
        }
    }

    if (!flag)
    {
        printf("L2 no es multiplo de L1\n");
    }
    else
    {
        printf("L2 es multiplo de L1");
        if (!es_escalar)
        {
            printf(" y no es escalar uno de otro\n");
        }
        else
        {
            printf(" y es escalar por %i\n", primer_cociente);
        }
    }
}