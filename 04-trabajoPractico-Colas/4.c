/*Dada una cola de números enteros, no ordenada, construir un algoritmo que permita
pasar a otra cola todos los elementos que no se repiten en la primera, sin destruir el
contenido de la cola original y dejándola en su estado inicial. Determinar la
complejidad algorítmica de la solución.
Ejemplo: si "C" contiene (12,6, 8, 5, 8, 12, 12) la cola resultado del proceso sería (6,5)*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../libs/colas/headers/colas.h"
#include "../libs/validaciones/headers/validaciones.h"

Cola c_ej4_colanorepetidos(Cola c);
int longitud_cola(Cola c);

int main()
{
    return 0;
}

int longitud_cola(Cola c)
{
    Cola aux = c_crear();
    int contador = 0;
    while (!c_es_vacia(c))
    {
        TipoElemento te = c_desencolar(c);
        c_encolar(aux, te);
        contador++;
    }
    while (!c_es_vacia(aux))
    {
        TipoElemento auxiliar = c_desencolar(aux);
        c_encolar(c, auxiliar);
    }
    return contador;
}

Cola c_ej4_colanorepetidos(Cola c)
{

    Cola resultado = c_crear();
    int apariciones, longitud;
    longitud = longitud_cola(c);
    apariciones = 0;
    // Ciclo exterior recorre longitud veces la cola
    for (int i = 0; i < longitud; i++)
    {
        TipoElemento te = c_desencolar(c);
        int apariciones = 0;

        // Ciclo interior recorre el resto de la cola
        for (int j = 0; j < longitud - 1; j++)
        {
            TipoElemento te_aux = c_desencolar(c);

            if (te->valor == te_aux->valor)
            {
                apariciones++;
            }
            c_encolar(c, te_aux);
        }
        // Verificamos que sea 0 para ingresarlo en la cola resultado
        if (apariciones == 0)
        {
            c_encolar(resultado, te);
        }
        /*Vuelvo a encolar el valor tomado al principio, esto cambia el orden de los elementos
        pero permite de forma natural progresar en la posicion de los elementos asi no se compara el mismo siempre*/
        c_encolar(c, te);
    }
    return resultado;

    /*La complejidad algoritmica de la funcion es de O(n^2) debido a los bucles anidados, */
}