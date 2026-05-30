#include "colas.h"
#include <stdlib.h>
#include <stdio.h>
#include "../libs/validaciones/headers/validaciones.h"
#include "../libs/Pilas/headers/pilas.h"

/*2. Resolver los siguientes puntos:
f. Invertir el contenido de una cola sin destruir la cola original*/

Cola llenar(int cantidad);
int validacion_ingreso();
char validacionDeLetra(char mensaje[], char opcionStr[], int tamOpcion, char inicio, char fin);
bool c_ej2_existeclave(Cola c, int clave);
Cola c_ej2_colarelemento(Cola c, int posicionordinal);
Cola c_ej2_sacarelemento(Cola c, int clave);
int c_ej2_contarelementos(Cola c);
Cola c_ej2_copiar(Cola c);
Cola c_ej2_invertir(Cola c);

int main()
{
    bool clave_encontrada;
    Cola cola_original;
    int cantidad, clave_buscar, posicionordinal, clave_eliminacion;
    // Cantidad permitida por la estructura
    printf("Ingrese la cantidad de elementos de la cola: ");
    cantidad = validacion_ingreso();
    // Completamos los elementos
    cola_original = llenar(cantidad);
    // El usuario decide que clave buscar
    printf("¿Que clave quiere buscar?: ");
    clave_buscar = validacion_ingreso();
    // Buscamos la clave y determinamos el resultado
    clave_encontrada = c_ej2_existeclave(cola_original, clave_buscar);
    printf("Resultado: %d", clave_encontrada);
    // Ingresar elemento en una posicion
    printf("Ingrese una posicion para encontar elemento: ");
    posicionordinal = validacion_ingreso();
    cola_original = c_ej2_colarelemento(cola_original, posicionordinal);

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
// ============== A ==============
bool c_ej2_existeclave(Cola c, int clave)
{
    Cola c_aux = c_crear();
    bool encontrado = false;

    while (!c_es_vacia(c))
    {
        TipoElemento original = c_desencolar(c);

        if (original->clave == clave)
        {
            encontrado = true;
        }
        c_encolar(c_aux, original);
    }

    while (!c_es_vacia(c_aux))
    {
        TipoElemento elemento_salida = c_desencolar(c_aux);
        c_encolar(c, elemento_salida);
    }

    return encontrado;
}
// ============== B ==============
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
// ============== C ==============
Cola c_ej2_sacarelemento(Cola c, int clave)
{
    Cola aux = c_crear();
    // En donde se ponen los elementos que se buscan para eliminar
    Cola basura = c_crear();

    while (!c_es_vacia(c))
    {
        TipoElemento te_original = c_desencolar(c);
        c_encolar(aux, te_original);
    }

    while (!c_es_vacia(aux))
    {
        TipoElemento te_aux = c_desencolar(aux);
        if (clave == te_aux->clave)
        {
            // Si es el elemento que buscamos
            // Se elimina en todas sus apariciones
            c_encolar(basura, te_aux);
        }
        else
        {
            c_encolar(c, te_aux);
        }
    }
    return c;
}
// ============== D ==============
int c_ej2_contarelementos(Cola c)
{
    Cola aux = c_crear();
    int contador = 0;
    while (!c_es_vacia(c))
    {
        TipoElemento original = c_desencolar(c);
        c_encolar(aux, original);
        contador++;
    }
    while (!c_es_vacia(aux))
    {
        TipoElemento auxiliar = c_desencolar(aux);
        c_encolar(c, auxiliar);
    }

    return contador;
}
// ============== E ==============
Cola c_ej2_copiar(Cola c)
{
    Cola aux = c_crear();
    Cola copia = c_crear();

    while (!c_es_vacia(c))
    {
        TipoElemento original = c_desencolar(c);
        c_encolar(aux, original);
        c_encolar(copia, original);
    }

    while (!c_es_vacia(aux))
    {
        TipoElemento auxiliar = c_desencolar(aux);
        c_encolar(c, auxiliar);
    }
    return copia;
}
// ============== F ==============
Cola c_ej2_invertir(Cola c)
{
    Cola c_aux = c_crear();
    Cola c_invertida = c_crear();
    Pila p_inversora = p_crear();

    while (!c_es_vacia(c))
    {
        TipoElemento original = c_desencolar(c);
        c_encolar(c_aux, original);
        p_apilar(p_inversora, original);
    }

    while (!c_es_vacia(c_aux))
    {
        TipoElemento aux = c_desencolar(c_aux);
        TipoElemento te_inversor = p_desapilar(p_inversora);
        c_encolar(c, aux);
        c_encolar(c_invertida, te_inversor);
    }
    return c_invertida;
}
