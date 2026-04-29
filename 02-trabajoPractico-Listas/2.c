#include "../02-trabajoPractico-Listas/tp_2_listas.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct
{
    float resultado1;
    float resultado2;
} Resultados;

typedef struct resultadoStruct
{
    int pos;
    int lista;
    int valor;
} ResultadoValorMaximo;

int validacion_ingreso();
Lista rellenarLista(int elementos);
Lista verElementosRepetidos(Lista l1, Lista l2);
Lista verElementosQueNoSeRepiten(Lista l1, Lista l2);
float promedio(Lista l1);
Resultados promedioAmbasListas(Lista l1, Lista l2);
ResultadoValorMaximo valorMaximo(Lista l1, Lista l2);

int main()
{
    srand(time(NULL));
    int cantidad = 0;
    // Creamos las dos listas
    Lista l1, l2;

    // Tamaño de las listas
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

    // Elementos repetidos
    Lista l_repetidos = verElementosRepetidos(l1, l2);
    printf("\nElementos que se repiten en ambas listas: ");
    l_mostrar(l_repetidos);

    // Elementos que no se repiten (Asumimos de L1 respecto a L2 para este ejemplo)
    Lista l_no_repetidos = verElementosQueNoSeRepiten(l1, l2);
    printf("Elementos en L1 que no se repiten en L2: ");
    l_mostrar(l_no_repetidos);

    // Uso del struct Resultados
    Resultados promedios = promedioAmbasListas(l1, l2);
    printf("\nPromedio de la Lista 1: %.2f\n", promedios.resultado1);
    printf("Promedio de la Lista 2: %.2f\n", promedios.resultado2);

    // Uso del struct ResultadoValorMaximo
    ResultadoValorMaximo maximo = valorMaximo(l1, l2);
    printf("\n--- Datos del Valor Maximo ---\n");
    printf("El valor maximo es: %d\n", maximo.valor);
    printf("Se encuentra en la Lista: %d\n", maximo.lista);
    printf("En la posicion: %d\n", maximo.pos);

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

Lista verElementosQueNoSeRepiten(Lista l1, Lista l2)
{
    Lista l_no_repetidos = l_crear(); // Creamos la lista a retornar
    Iterador iter = iterador(l1);     // Iterador para recorrer L1

    while (hay_siguiente(iter))
    {
        TipoElemento te = siguiente(iter);

        // Si la clave de L1 NO está en L2 (la búsqueda devuelve NULL)
        if (l_buscar(l2, te->clave) == NULL)
        {
            // Creamos un nuevo TipoElemento para no compartir direcciones de memoria
            TipoElemento nuevo_te = te_crear(te->clave);

            // Lo agregamos a nuestra lista de resultados
            l_agregar(l_no_repetidos, nuevo_te);
        }
    }

    return l_no_repetidos;
}

Lista verElementosRepetidos(Lista l1, Lista l2)
{
    Lista l_repetidos = l_crear(); // Creamos la lista para almacenar las coincidencias
    Iterador iter = iterador(l1);  // Iterador para recorrer la primera lista (L1)

    while (hay_siguiente(iter))
    {
        TipoElemento te = siguiente(iter);

        // Buscamos si la clave del elemento actual de L1 existe en L2
        if (l_buscar(l2, te->clave) != NULL)
        {
            // Si existe (no es NULL), creamos un nuevo elemento y lo agregamos a la lista resultado
            TipoElemento nuevo_te = te_crear(te->clave);
            l_agregar(l_repetidos, nuevo_te);
        }
    }

    return l_repetidos;
}

float promedio(Lista l1)
{
    float promedio = 0;
    int cantidad = 0;
    Iterador iter = iterador(l1); // Iterador para recorrer la lista
    while (hay_siguiente(iter))   // Verifica si hay siguiente
    {
        TipoElemento te = siguiente(iter);
        promedio += te->clave;
        cantidad++;
    }
    // Validación de seguridad: evitamos división por cero si la lista está vacía
    if (cantidad == 0)
    {
        return 0; // Retornamos 0 si no hubo elementos para promediar
    }
    promedio = promedio / cantidad;
    return promedio;
}

Resultados promedioAmbasListas(Lista l1, Lista l2)
{
    Resultados res; // Declaramos una variable del tipo de nuestro struct

    // Llamamos a la funcion promedio() que hicimos antes para cada lista
    // y guardamos el resultado en los campos correspondientes del struct
    res.resultado1 = promedio(l1);
    res.resultado2 = promedio(l2);

    // Retornamos el struct ya cargado
    return res;
}

ResultadoValorMaximo valorMaximo(Lista l1, Lista l2)
{
    ResultadoValorMaximo res;
    // Inicializamos la bandera para saber si ya cargamos al menos un primer valor
    int max_encontrado = 0;
    // Por defecto, inicializamos en 0 por si ambas listas llegan a estar vacías
    res.valor = 0;
    res.lista = 0;
    res.pos = 0;
    // --- Búsqueda en la Lista 1 ---
    Iterador iter1 = iterador(l1);
    int pos_actual1 = 0;

    while (hay_siguiente(iter1))
    {
        pos_actual1++; // Llevamos la cuenta de la posición (arranca en 1)
        TipoElemento te = siguiente(iter1);

        // Si es el primer elemento de todos, o si es mayor al máximo actual
        if (!max_encontrado || te->clave > res.valor)
        {
            res.valor = te->clave;
            res.lista = 1; // Indicamos que lo encontramos en la Lista 1
            res.pos = pos_actual1;
            max_encontrado = 1; // Marcamos que ya tenemos un valor de referencia
        }
    }
    // --- Búsqueda en la Lista 2 ---
    Iterador iter2 = iterador(l2);
    int pos_actual2 = 0;

    while (hay_siguiente(iter2))
    {
        pos_actual2++; // Llevamos la cuenta de la posición en L2
        TipoElemento te = siguiente(iter2);

        // Comparamos estrictamente (>) contra el máximo que traemos de L1
        // Si es mayor, actualizamos todos los datos en nuestro struct
        if (!max_encontrado || te->clave > res.valor)
        {
            res.valor = te->clave;
            res.lista = 2; // Ahora el máximo está en la Lista 2
            res.pos = pos_actual2;
            max_encontrado = 1;
        }
    }
    return res;
}