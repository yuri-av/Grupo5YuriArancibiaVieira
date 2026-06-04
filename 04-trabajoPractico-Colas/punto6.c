#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "tp_4_colas.h"

Lista c_ej6_comunesapilaycola(Pila p, Cola c);
/**
6.	Dada una pila y una cola generada con valores al azar retornar en una lista todos los valores comunes a ambas
	y en qué posición ordinal se encontró cada uno en su estructura.  Si existe mas de una vez la primer posicion encontrada.
	No se deben destruir las estructuras originales.
 */
// retornar una lista con los valores comunes segun las especificaciones del ejercicio.
// Si no existen valores comunes retornar la lista vacia.
int main() {
    srand(time(NULL));

    Pila p = p_crear();
    Cola c = c_crear();

    printf("Generando valores al azar...\n\n");

    for (int i = 0; i < 7; i++) p_apilar(p, te_crear((rand() % 10) + 1));
    for (int i = 0; i < 7; i++) c_encolar(c, te_crear((rand() % 10) + 1));

    Lista Resultado = c_ej6_comunesapilaycola(p, c);

   printf("Resultados detallados (Valor:PosPila:PosCola):\n");

    if (l_es_vacia(Resultado)) {
        printf("No se encontraron valores comunes.\n");
    } else {
        // Recorremos la lista posición por posición
        for (int i = 1; i <= l_longitud(Resultado); i++) {
            TipoElemento elem = l_recuperar(Resultado, i);
            
            printf("Valor: %d | Posiciones (Pila:Cola): %s\n", elem->clave, (char*)elem->valor);
        }
    }

    return 0;
}

Lista c_ej6_comunesapilaycola(Pila p, Cola c){
    Lista Resultado = l_crear();
    Pila Paux = p_crear();
    Cola Caux = c_crear();

    int PosicionPila = 1;


    TipoElemento x;
    TipoElemento y;

    while (!p_es_vacia(p))// Si p no es vacia recorro
    {

        x = p_desapilar(p);//desapilo para tener el siguiente valor
        p_apilar(Paux,x);//guardo en la pAux para no perder la pila original
            
        int PosicionCola = 1;
        bool Encontrado = false;
            while (!c_es_vacia(c))//comparo con toda la cola
            {
                y = c_desencolar(c);
                c_encolar(Caux,y);

                if (x->clave == y->clave&&!Encontrado){//si son iguales
                    
                    bool yaEstaEnLista = false;
                    if (l_buscar(Resultado,x->clave) == NULL) //SI NO ESTA EN LA LISTA RESULTADO lA CLAVE DE X
                    {
                        Encontrado = true; //Para este valor de la pila ya lo encontramos al menos una ves

                        char* stringPos = (char*) malloc(30*sizeof(char));
            
                        sprintf(stringPos, "%d:%d", PosicionPila, PosicionCola);
                
                        TipoElemento nuevoElemento = te_crear_con_valor(x->clave,stringPos);
                        l_agregar(Resultado,nuevoElemento); // agrego a la lista
                    }
                    
                }
                PosicionCola++;
            }

            while (!c_es_vacia(Caux))// transfiero de nuevo a la cola para comparar
            {
                y = c_desencolar(Caux);
                c_encolar(c,y);
            }
            PosicionPila++;
        }
        

    

    while (!p_es_vacia(Paux)) //re apilo
    {
        x = p_desapilar(Paux);
        p_apilar(p,x);
    }


    return Resultado;

}