#include "colas.h"
#include <stdlib.h>
#include <stdio.h>
#include "../libs/validaciones/headers/validaciones.h"

/*2. Resolver los siguientes puntos:
a. Informar si un elemento dado se encuentra en la cola.
b. Agregar un nuevo elemento en una posición dada (colarse).
c. Dado un elemento sacarlo de la cola todas las veces que aparezca.
d. Contar los elementos de la cola.
e. Realizar una función que realice una copia de una cola.
f. Invertir el contenido de una cola sin destruir la cola original*/

bool c_ej2_existeclave(Cola c, int clave);
Cola llenar(int cantidad);
char validacionDeLetra(char mensaje[], char opcionStr[], int tamOpcion, char inicio, char fin);
Cola c_ej2_colarelemento(Cola c, int posicionordinal);

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
    bool clave_encontrada;
    Cola cola_original;
    int cantidad, clave;
    // Cantidad permitida por la estructura
    printf("Ingrese la cantidad de elementos de la cola: ");
    cantidad = validacion_ingreso();
    // Completamos los elementos
    cola_original = llenar(cantidad);
    // El usuario decide que clave buscar
    printf("¿Que clave quiere buscar?: ");
    clave = validacion_ingreso();
    // Buscamos la clave y determinamos el resultado
    clave_encontrada = c_ej2_existeclave(cola_original, clave);
    printf("Resultado: %d", clave_encontrada);

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
        c_encolar(cola, n);
        cantidad--;
    }
    return cola;
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
        c_encolar(c_aux, elemento_salida);
    }

    while (!c_es_vacia(c_aux))
    {
        TipoElemento elemento_salida = c_desencolar(c_aux);
        c_encolar(c_aux, elemento_salida);
    }

    return encontrado;
}

Cola c_ej2_colarelemento(Cola c, int posicionordinal)
{
    Cola aux = c_crear();
    int valor_nuevo;

    printf("Ingrese el valor a ingresar: ");
    valor_nuevo = validacion_ingreso();
    TipoElemento nuevo = te_crear(valor_nuevo);

    while (!c_es_vacia(c))
    {
        c_encolar(aux, c_desencolar(c));
    }
    int contador = 1;

    while (!c_es_vacia(aux))
    {
        if (contador == posicionordinal)
        {
            c_encolar(c, nuevo);
            posicionordinal = -1; // Desactiva la condicion para que no vuelva a entrar
        }
        TipoElemento te_aux = c_desencolar(aux);
        c_encolar(c, te_aux);
        contador++;
    }

    if (posicionordinal != -1)
    {
        // Entrara en este bloque si la posicion en la que quiere ingresar el valor nuevo ->
        // -> no es parte de la cola
        c_encolar(c, nuevo);
    }

    return c;
}
