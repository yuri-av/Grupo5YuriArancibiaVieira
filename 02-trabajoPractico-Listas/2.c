#include "../02-trabajoPractico-Listas/tp_2_listas.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int validacion_ingreso();
Lista rellenarLista(int elementos);
Lista en_l1_no_en_l2(Lista l1, Lista l2);
Lista coincidencias(Lista l1, Lista l2);
float promedio(Lista l1);
void obtener_minimo(Lista lista, int *min, int *pos_min);

int main()
{
    srand(time(NULL));
    int cantidad = 0;
    int min = 0;
    int pos_min = 0;
    char car;

    // Creamos las dos listas
    Lista l1, l2;

    // Tamaño de las listas
    printf("Ingrese la cantidad de elementos a agregar a las listas: ");
    while (scanf("%d%c", &cantidad, &car) != 2 || car != '\n')
    {
        printf("Opcion invalida. Ingrese una cantidad con numeros enteros: ");
        if (car != '\n')
        {
            while (getchar() != '\n')
                ;
        }
    }

    // Llenamos las listas según la opción elegida
    validacion_ingreso();
    l1 = rellenarLista(cantidad);
    validacion_ingreso();
    l2 = rellenarLista(cantidad);

    // Mostramos las listas cargadas
    printf("Lista 1: ");
    l_mostrar(l1);
    printf("Lista 2: ");
    l_mostrar(l2);

    // 2.a
    Lista l_solo_en_l1 = en_l1_no_en_l2(l1, l2);
    printf("Elementos en L1 que no estan en L2: ");
    l_mostrar(l_solo_en_l1);

    // 2.b
    Lista l_solo_en_l2 = en_l2_no_en_l1(l2, l1);
    printf("Elementos en L2 que no estan en L1: ");
    l_mostrar(l_solo_en_l2);

    // 2.c
    Lista l_coincidencias = coincidencias(l1, l2);
    printf("Elementos que coinciden en ambas listas: ");
    l_mostrar(l_coincidencias);

    // 2.d
    float promedio_l1 = promedio(l1, cantidad);
    float promedio_l2 = promedio(l2, cantidad);
    printf("Promedio de las claves en L1: %.2f\n", promedio_l1);
    printf("Promedio de las claves en L2: %.2f\n", promedio_l2);

    // 2.e
    obtener_minimo(l1, &min, &pos_min);
    printf("El minimo de l1 es: %i en la posicion: %i\n", min, pos_min);
    obtener_minimo(l2, &min, &pos_min);
    printf("El minimo de l2 es: %i en la posicion: %i\n", min, pos_min);

    return 0;
}

Lista rellenarLista(int elementos);
{
    Lista l1 = l_crear();

    int opcion = 0;
    char car;

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

// retorna una Lista con los elementos que están en L1 pero no en L2
Lista en_l1_no_en_l2(Lista l1, Lista l2)
{
    Lista l_resultado1 = l_crear(); // Creamos la lista a retornar
    Iterador iter = iterador(l1);   // Iterador para recorrer L1

    while (hay_siguiente(iter))
    {
        TipoElemento te = siguiente(iter);

        // Si no está en L2, lo agregamos a nuestra lista resultado
        if (l_buscar(l2, te->clave) == NULL)
        {
            // Creamos un nuevo TipoElemento para agregar a la lista resultado
            TipoElemento nuevo_te = te_crear(te->clave);
            l_agregar(l_resultado1, nuevo_te);
        }
    }
    return l_resultado1;
}

Lista en_l2_no_en_l1(Lista l2, Lista l1)
{
    Lista l_resultado2 = l_crear(); // Creamos la lista a retornar
    Iterador iter = iterador(l2);   // Iterador para recorrer L2

    while (hay_siguiente(iter))
    {
        TipoElemento te = siguiente(iter);

        // Si no está en L1, lo agregamos a nuestra lista resultado
        if (l_buscar(l1, te->clave) == NULL)
        {
            // Creamos un nuevo TipoElemento para agregar a la lista resultado
            TipoElemento nuevo_te = te_crear(te->clave);
            l_agregar(l_resultado2, nuevo_te);
        }
    }
    return l_resultado2;
}

Lista coincidencias(Lista l1, Lista l2)
{
    Lista coincidencias = l_crear(); // Creamos la lista a retornar
    Iterador iter = iterador(l1);    // Iterador para recorrer L1

    while (hay_siguiente(iter))
    {
        TipoElemento te = siguiente(iter);
        if (l_buscar(l2, te->clave) != NULL)
        {
            // Si encontramos una coincidencia, la agregamos a la lista resultado
            TipoElemento nuevo_te = te_crear(te->clave);
            l_agregar(coincidencias, nuevo_te);
        }
    }
    return coincidencias;
}

float promedio(Lista l1)
{
    float promedio = 0;
    int cantidad = 0;
    Iterador iter = iterador(l1); // Iterador para recorrer una lista
    while (hay_siguiente(iter))   // Verifica si hay siguiente
    {
        // Obtiene el siguiente elemento
        TipoElemento te = siguiente(iter);
        // Guarda el promedio sumando
        promedio += te->clave;
    }
    promedio = promedio / cantidad;
    return promedio;
}

void obtener_minimo(Lista lista, int *min, int *pos_min)
{
    // Caso de lista vacia
    if (l_es_vacia(lista))
    {
        *min = 0;
        *pos_min = 0;
        return; // Retorno agregado para que no intente seguir procesando la lista vacía
    }

    Iterador iter = iterador(lista);
    int pos_actual = 1;

    // Guardo el primer valor de la lista
    TipoElemento te = siguiente(iter);
    *min = te->clave;
    *pos_min = 1;

    while (hay_siguiente(iter)) // verifico que hay siguiente
    {
        // Aumento la posicion actual
        pos_actual++;
        te = siguiente(iter);
        // Verifico si es menor al minimo anterior
        if (te->clave < *min)
        {
            *min = te->clave;
            *pos_min = pos_actual;
        }
    }
}