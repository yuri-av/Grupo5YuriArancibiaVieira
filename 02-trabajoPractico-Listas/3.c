#include "listas.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "listas.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

typedef struct
{
    bool esMultiplo;
    bool escalar;
    int numEscalar;
} ResultadosMul;

int validacion_ingreso();
Lista rellenarLista(int elementos);
ResultadosMul multiplo(Lista l1, Lista l2);

int main()
{
    srand(time(NULL));
    int cantidad = 0;
    Lista l1, l2;

    printf("Ingrese la cantidad de elementos a agregar a las listas: ");
    cantidad = validacion_ingreso();

    // Llenamos las listas.
    printf("\n--- Carga de la Lista 1 ---\n");
    l1 = rellenarLista(cantidad);

    printf("\n--- Carga de la Lista 2 ---\n");
    l2 = rellenarLista(cantidad);

    // Mostramos las listas cargadas
    printf("\nLista 1: ");
    l_mostrar(l1);
    printf("Lista 2: ");
    l_mostrar(l2);

    // Verificamos multiplicidad
    ResultadosMul resultado = multiplo(l1, l2);

    // Mostramos los mensajes en el main, leyendo los datos del struct
    if (!resultado.esMultiplo)
    {
        printf("\nL2 no es multiplo de L1\n");
    }
    else
    {
        printf("\nL2 es multiplo de L1");
        if (!resultado.escalar)
        {
            printf(" y no es escalar uno de otro\n");
        }
        else
        {
            printf(" y es escalar por %i\n", resultado.numEscalar);
        }
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

ResultadosMul multiplo(Lista l1, Lista l2)
{
    ResultadosMul res;
    // Inicializamos el struct por defecto asumiendo que no es múltiplo
    res.esMultiplo = false;
    res.escalar = false;
    res.numEscalar = 0;

    // Verificamos que no tengan longitudes distintas o que no estén vacías
    if (l_longitud(l1) != l_longitud(l2))
    {
        printf("\nError: Las longitudes de las listas no coinciden.\n");
        return res; // Retornamos el struct en false
    }
    if (l_es_vacia(l1) || l_es_vacia(l2))
    {
        printf("\nError: Una o ambas listas estan vacias.\n");
        return res; // Retornamos el struct en false
    }

    bool flag = true;
    bool es_escalar = true;
    int primer_cociente = -1;

    Iterador iter1 = iterador(l1);
    Iterador iter2 = iterador(l2);

    while (hay_siguiente(iter1) && flag)
    {
        TipoElemento te1 = siguiente(iter1);
        TipoElemento te2 = siguiente(iter2);

        // Evitamos división por cero y verificamos si NO es múltiplo
        if (te1->clave == 0 || te2->clave % te1->clave != 0)
        {
            flag = false;
            es_escalar = false;
        }
        else
        {
            int cociente_actual = te2->clave / te1->clave;

            // Primera iteración: asigna el valor al primer cociente
            if (primer_cociente == -1)
            {
                primer_cociente = cociente_actual;
            }
            // Siguientes iteraciones: verificamos si se rompe la propiedad de escalar
            else if (cociente_actual != primer_cociente)
            {
                es_escalar = false;
            }
        }
    }

    // Cargamos los resultados finales en el struct
    res.esMultiplo = flag;

    // Solo puede ser escalar si la bandera principal de múltiplo se mantuvo verdadera
    res.escalar = (flag && es_escalar);

    // Si resultó ser escalar, guardamos el número; si no, dejamos un 0
    if (res.escalar)
    {
        res.numEscalar = primer_cociente;
    }

    return res;
}