#include "colas.h"
#include <stdlib.h>
#include <stdio.h>

/*2. Resolver los siguientes puntos:
a. Informar si un elemento dado se encuentra en la cola.
b. Agregar un nuevo elemento en una posición dada (colarse).
c. Dado un elemento sacarlo de la cola todas las veces que aparezca.
d. Contar los elementos de la cola.
e. Realizar una función que realice una copia de una cola.
f. Invertir el contenido de una cola sin destruir la cola original*/

bool c_ej2_existeclave(Cola c, int clave);
Cola llenar(int cantidad);

/*static const int TAMANIO_MAXIMO = 10;

struct ColaRep;
typedef struct ColaRep *Cola;

Cola c_crear();

bool c_encolar(Cola cola, TipoElemento elemento);

TipoElemento c_desencolar(Cola cola);

bool c_es_vacia(Cola cola);

bool c_es_llena(Cola cola);

void c_mostrar(Cola cola);

TipoElemento c_recuperar(Cola cola);

#endif // COLAS_H*/

int main()
{
    bool encontrado;
    Cola cola_original = c_crear();

    return 0;
}

Cola llenar(int cantidad)
{
    Cola cola = c_crear();
    int opcion;

    printf("A continuacion debera elegir que tipo de dato se ingresara...\n");
    printf("Seleccione: \n");
    do
    {
        // Opciones
        printf("1: INT\n");
        printf("2: CHAR\n");
        printf("3: BOOL\n");
        printf("4: FLOAT\n");
        printf("0: PARA SALIR\n");
        // En caso de no elegir una opcion valida
        while (opcion < 0 || opcion > 4)
        {
            /* code */
        }

        // Instrucciones pertinentes a la opcion
        switch (opcion)
        {
        case 1:
            /* code */
            break;

        default:
            break;
        }
    } while (opcion != 0);
}

bool c_ej2_existeclave(Cola c, int clave)
{
    Cola c_aux = c_crear();
    bool encontrado = false;

    while (!c_es_vacia(c))
    {
        TipoElemento elemento_salida = c_desencolar(c);
        if (elemento_salida->clave == clave)
        {
            encontrado = true;
        }
        TipoElemento elemento_aux = te_crear(elemento_salida);
        c_encolar(c_aux, elemento_aux);
    }
    while (!c_es_vacia(c_aux))
    {
        TipoElemento elemento_salida = c_desencolar(c_aux);
        TipoElemento elemento_aux = te_crear(elemento_salida);
        c_encolar(c_aux, elemento_aux);
    }
    return encontrado;
}
