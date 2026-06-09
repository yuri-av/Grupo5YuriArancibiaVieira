#include "tp_4_colas.h"
#include "../libs/colas/headers/colas.h"
#include "../libs/pilas/headers/pilas.h"
#include "../libs/listas/headers/listas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/validaciones/headers/validaciones.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

int contador(Cola c);
int cant_divisiones(Cola c, TipoElemento sig);


int c_ej5_divisortotal(Cola c, bool *fuetotal){

    TipoElemento sig;
    Cola caux = c_crear();
    int cantidadElementos = contador(c);
    int divisorEncontrado = 0;

    while(!c_es_vacia(c)){

        sig = c_desencolar(c);

        int divisiones = cant_divisiones(c, sig);

        // Si es divisor total
        if(divisiones == cantidadElementos - 1){
            *fuetotal = true;
            divisorEncontrado = sig->clave;
            c_encolar(caux, sig);
            
            // Devolver el resto a la cola original
            while(!c_es_vacia(c)){
                sig = c_desencolar(c);
                c_encolar(caux, sig);
            }
            break;
        }
        // Si es divisor parcial (al menos 50%)
        else if(divisiones >= cantidadElementos / 2){
            *fuetotal = false;
            divisorEncontrado = sig->clave;
            c_encolar(caux, sig);
            
            // Devolver el resto a la cola original
            while(!c_es_vacia(c)){
                sig = c_desencolar(c);
                c_encolar(caux, sig);
            }
            break;
        }

        c_encolar(caux, sig);
    }

    // Restaurar la cola original
    while(!c_es_vacia(caux)){
        sig = c_desencolar(caux);
        c_encolar(c, sig);
    }

    return divisorEncontrado;
}


int contador(Cola c){

    Cola aux = c_crear();

    TipoElemento x;

    int cont = 0;

    while(!c_es_vacia(c)){

        x = c_desencolar(c);

        cont++;

        c_encolar(aux, x);
    }

    while(!c_es_vacia(aux)){

        x = c_desencolar(aux);

        c_encolar(c, x);
    }

    return cont;
}


int cant_divisiones(Cola c, TipoElemento sig){

    Cola aux = c_crear();

    TipoElemento x;

    int cont = 0;

    while(!c_es_vacia(c)){

        x = c_desencolar(c);

        if(x->clave != sig->clave){

            if(x->clave % sig->clave == 0){

                cont++;
            }
        }

        c_encolar(aux, x);
    }

    while(!c_es_vacia(aux)){

        x = c_desencolar(aux);

        c_encolar(c, x);
    }

    return cont;
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

//funcion auxiliar para e7
static char* construir_mensaje(int nro_cliente, int nro_cola) {
    /* "Cliente 999 Cola 9\0" -> a lo sumo ~20 caracteres, uso 32 */
    char *msg = (char*) malloc(32 * sizeof(char));
    sprintf(msg, "Cliente %d Cola %d", nro_cliente, nro_cola);
    return msg;
}

Cola c_ej7_atenderclientes(Cola c1, Cola c2, Cola c3, int tiempoatencion) {

    Cola resultado = c_crear();

    /* Arreglo para iterar las 3 colas mas comodo */
    Cola colas[3];
    colas[0] = c1;
    colas[1] = c2;
    colas[2] = c3;

    /* Seguimos rotando mientras alguna cola tenga clientes */
    int hay_clientes = 1;

    while (hay_clientes) {

        hay_clientes = 0; /* lo volvemos a poner en 1 si encontramos alguien */

        /* Recorremos las 3 colas en orden */
        for (int i = 0; i < 3; i++) {

            if (c_es_vacia(colas[i])) {
                continue; /* esta cola ya no tiene nadie, saltamos */
            }

            hay_clientes = 1; /* hay al menos una cola con gente */

            int minutos_restantes = tiempoatencion; /* Q disponibles para este turno */

            /* Atendemos mientras tengamos tiempo Y haya clientes en la cola */
            while (minutos_restantes > 0 && !c_es_vacia(colas[i])) {

                TipoElemento cliente = c_frente(colas[i]);

                if (cliente->clave <= minutos_restantes) {
                    /*
                     * El cliente termina de ser atendido en este turno.
                     * Le descontamos su tiempo al disponible,
                     * lo sacamos de la cola y lo registramos.
                     */
                    minutos_restantes -= cliente->clave;

                    /* Sacamos al cliente de la cola */
                    TipoElemento atendido = c_desencolar(colas[i]);

                    /* Construimos el mensaje de resultado */
                    int nro_cliente = *((int*) atendido->valor);
                    char *msg = construir_mensaje(nro_cliente, i + 1);

                    /* Lo encolamos en el resultado */
                    TipoElemento registro = te_crear_con_valor(i + 1, msg);
                    c_encolar(resultado, registro);

                } else {
                    /*
                     * El cliente necesita mas tiempo del que queda en este turno.
                     * Le descontamos los minutos que usamos y terminamos el turno.
                     */
                    cliente->clave -= minutos_restantes;
                    minutos_restantes = 0;
                }
            }
        }
    }

    return resultado;
}
