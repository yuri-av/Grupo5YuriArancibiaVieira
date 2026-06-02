/* Dadas dos colas, determinar si sus contenidos son iguales tanto en posición como en
datos (solo comparar por la clave), sin destruirlas. Utilizar para la resolución del
problema una sola cola auxiliar. Determinar la complejidad algorítmica del problema. */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../libs/colas/headers/colas.h"
#include "../libs/validaciones/headers/validaciones.h"

Cola llenar(int cantidad);
bool c_ej3_iguales(Cola c1, Cola c2);

int main()
{
    Cola c1, c2;
    int cantidad;
    bool son_iguales;
    printf("Ingrese la cantidad de elementos para las colas: ");
    // Ingreso de elementos de cola 1
    cantidad = validacion_ingreso();
    c1 = llenar(cantidad);
    // Ingreso de elementos de cola 2
    c2 = llenar(cantidad);
    // Llamada a la funcion del ejercicio
    son_iguales = c_ej3_iguales(c1, c2);
    printf("Son igules: %d", son_iguales);
    /*El algoritmo implementado para realizar el ejericio es de O(n)
    siendo que la cantidad de elementos sera el mismo para las dos colas,
    no hay diferencia de complejidad siendo que el algoritmo solo utiliza estructuras while
    simples.*/
    return 0;
}

Cola llenar(int cantidad)
{
    Cola cola = c_crear();
    int n;
    while (cantidad > 0)
    {
        printf("Ingrese un valor: ");
        n = validacion_ingreso();
        TipoElemento te = te_crear(n);
        c_encolar(cola, te);
        cantidad--;
    }
    return cola;
}

bool c_ej3_iguales(Cola c1, Cola c2)
{
    TipoElemento te_c1, te_c2, te_aux;
    Cola aux = c_crear();
    bool iguales = true;
    // Intercalamos elementos de c1 con c2 en la auxiliar
    while (!c_es_vacia(c1) && !c_es_vacia(c2))
    {
        te_c1 = c_desencolar(c1);
        te_c2 = c_desencolar(c2);
        if (te_c1->clave != te_c2->clave)
        {
            iguales = false;
        }
        c_encolar(aux, te_c1);
        c_encolar(aux, te_c2);
    }

    // Si una cola quedó con elementos y la otra no, tenían tamaños distintos
    if (!c_es_vacia(c1) || !c_es_vacia(c2))
    {
        iguales = false;

        // Vaciamos lo que haya quedado en c1 o c2 hacia aux para no perderlos
        while (!c_es_vacia(c1))
            c_encolar(aux, c_desencolar(c1));
        while (!c_es_vacia(c2))
            c_encolar(aux, c_desencolar(c2));
    }
    // Devolvemos elementos a sus colas originales
    while (!c_es_vacia(aux))
    {
        te_aux = c_desencolar(aux);
        c_encolar(c1, te_aux);
        // Si todavía quedan elementos en aux, el siguiente pertenece a c2
        if (!c_es_vacia(aux))
        {
            te_aux = c_desencolar(aux);
            c_encolar(c2, te_aux);
        }
    }
    return iguales;
}