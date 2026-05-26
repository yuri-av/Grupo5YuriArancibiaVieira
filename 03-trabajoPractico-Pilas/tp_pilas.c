#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tp_pilas.h"
#include "pilas.h"
#include "tipo_elemento.h"

// EJERCICIO 2
/*a. Buscar una clave y determinar si existe en la Pila (sin perder la pila).*/
bool p_ej2_existeclave(Pila p, int clave) {
    Pila Paux = p_crear();
    TipoElemento x;
    
    bool encontrado = false;

    while (p_es_vacia(p) != true) {
        x = p_desapilar(p);
        
        if (x->clave == clave) {
            encontrado = true; 
        }

        p_apilar(Paux, x);
    }

    while (p_es_vacia(Paux) != true) {
        x = p_desapilar(Paux);
        p_apilar(p, x);
    }

    return encontrado;
}

/* b. Colocar en una posición ordinal determinada, recibida por parámetro, un nuevo elemento (Insertar un elemento nuevo).*/
Pila p_ej2_colocarelemento(Pila p, int posicionordinal, TipoElemento x) {
    Pila Paux = p_crear();
    TipoElemento elem;
    int pos = 1;

    while (p_es_vacia(p) != true && pos < posicionordinal) {
        elem = p_desapilar(p);
        p_apilar(Paux, elem);      
        pos++;
    }
    p_apilar(p,x);

    while (p_es_vacia(Paux) != true) {
        elem = p_desapilar(Paux);
        p_apilar(p,elem);
    }

    return p;
}

/*c. Eliminar de una pila un elemento dado (primera ocurrencia encontrada por la clave). */
Pila p_ej2_eliminarclave(Pila p, int clave) {
    Pila Paux = p_crear();
    TipoElemento x;
    int eliminado = 0;

    while (!p_es_vacia(p)) {
        x = p_desapilar(p);

        if (x->clave == clave && eliminado == 0) {
            eliminado = 1;
        } else { 
            p_apilar(Paux, x);
        }
    }

    while (!p_es_vacia(Paux)) {
        x = p_desapilar(Paux);
        p_apilar(p,x);
    } 

    return p;
}

/* d. Intercambiar los valores de 2 posiciones ordinales de la pila, por ejemplo la 2da con la 4ta.*/
Pila p_ej2_intercambiarposiciones(Pila p, int pos1, int pos2) {
    Pila Paux = p_crear();
    TipoElemento x, elemA, elemB;
    int pos = 1;

    while (!p_es_vacia(p)) {
        x = p_desapilar(p);

        if (pos == pos1) {
            elemA = x;
        } 
        if (pos == pos2) {
            elemB = x;
        }

        p_apilar(Paux, x);
        pos++;
    }
    
    pos = pos - 1;
    while (!p_es_vacia(Paux)) {
        x = p_desapilar(Paux);

        if (pos == pos1) {
            p_apilar(p, elemB);
        } else if (pos == pos2) {
            p_apilar(p,elemA);
        } else {
            p_apilar(p,x);
        }
        pos--;
    }

    return p;
}

/*e. Duplicar el contenido de una pila. */
Pila p_ej2_duplicar(Pila p) {
    Pila Paux = p_crear();
    Pila nueva = p_crear();
    TipoElemento x;

    while (!p_es_vacia(p)) {
        x = p_desapilar(p);
        p_apilar(Paux, x);
    }

    while (!p_es_vacia(Paux)) {
        x= p_desapilar(Paux);

        p_apilar(p, x);
        p_apilar(nueva, x);
    }

    return nueva;
}

/*f. Contar los elementos de la pila. */
int p_ej2_cantidadelementos(Pila p) {
    Pila Paux = p_crear();
    TipoElemento x;
    int contador = 0;

    if (p_es_vacia(p)) {
        return 0;
    }

    while (!p_es_vacia(p)) {
        x = p_desapilar(p);
        contador++;
        p_apilar(Paux, x);
    }

    while (!p_es_vacia(Paux)) {
        x = p_desapilar(Paux);
        p_apilar(p, x);
    }

    return contador;
}

/* ejercicio 3 
Dadas dos pilas, determinar si sus contenidos son exactamente iguales (solo por la clave), sin destruirlas. Utilizar para la 
resolución del problema una única pila auxiliar.
Determinar la complejidad algorítmica de la solución. */

bool p_ej3_iguales(Pila p1, Pila p2) {
    Pila Paux = p_crear();
    bool iguales = true;
    TipoElemento x, y;

    // 1. Comparamos elemento por elemento mientras ambas tengan datos
    while (!p_es_vacia(p1) && !p_es_vacia(p2)) {
        x = p_desapilar(p1);
        y = p_desapilar(p2);

        if (x->clave != y->clave) {
            iguales = false;
        }
        // Al desapilar de Paux, saldrá primero y, luego x.
        p_apilar(Paux, x);
        p_apilar(Paux, y);
    }

    // 2. Si una quedó con elementos y la otra no, NO son iguales
    if (!p_es_vacia(p1) || !p_es_vacia(p2)) {
        iguales = false;
    }

    // 3. Reconstrucción unitaria y segura
    while (!p_es_vacia(Paux)) {
        y = p_desapilar(Paux); // El de arriba de todo es un elemento de p2
        p_apilar(p2, y);

        if (!p_es_vacia(Paux)) { 
            x = p_desapilar(Paux); // El siguiente es un elemento de p1
            p_apilar(p1, x);
        }
    }

    return iguales; 
}

/*Ejercicio 4
Construir un algoritmo que, utilizando el TAD Pila, permita convertir un número
decimal pasado como parámetro, a su correspondiente valor expresado en una base
de 2 a 16 (hexadecimal). Determinar la complejidad algorítmica de la solución.
*/
void llenar_lista(char lista[], Pila pila, int contador)
{
    int i;
    printf("Iniciando carga...\n");
    for (i = 0; i < contador; i++)
    {
        TipoElemento te = p_desapilar(pila);
        lista[i] = te->clave;
    }
    lista[contador] = '\0';
}

char conversion(int n)
{
    char resultado='\0';
    if (n >= 10 && n < 16)
    {
        resultado = 'A' + (n - 10);
    }
    return resultado;
}

char *p_ej4_cambiarbase(int nrobasedecimal, int nrootrabase)
{

    Pila p_resultado = p_crear();
    char resto_char;
    int resto;
    int contador = 0; // Cuenta la cantidad de veces que se apilan datos para reservar la memoria necesaria
    bool puede_apilar = true;

    printf("Apilado de datos inciando...\n");
    // Necesitamos que haya algo mas para calcular y que se pueda apilar más elementos en caso de necesitarlo
    while (nrobasedecimal > 0 && puede_apilar)
    {
        // Calculamos el resto que será lo que se ingrese a la pila
        resto = nrobasedecimal % nrootrabase;
        if (resto >= 10 && resto <= 15)
        {
            // Llamamos a la funcion de converison a letras A-F
            resto_char = conversion(resto);
        }
        else if (resto < 10 && resto >= 0)
        {
            resto_char = '0' + resto;
        }
        // Creamos el elemento a ingresar a la pila
        TipoElemento te_char = te_crear(resto_char);

        // Calculamos lo que queda despues de la division
        nrobasedecimal = nrobasedecimal / nrootrabase;
        // Al asignar la funcion a una variable tenemos la condicion de corte del while
        puede_apilar = p_apilar(p_resultado, te_char);
        contador++;
    }
    printf("Apilado de datos finalizado!\n");
    char *resultado = (char *)malloc(sizeof(char) * (contador + 1));
    // Acá llenamos la lista donde se guardará el resultado en forma de string
    llenar_lista(resultado, p_resultado, contador);
    return resultado;
}

/*Ejercicio 5
Invertir el contenido de una pila sin destruir la pila original. Se debe retornar la nueva pila invertida y la original no se 
debe perder. Determinar la complejidad algorítmica de la solución. */

Pila  p_ej5_invertir(Pila p) {
    Pila Paux = p_crear();
    Pila nueva = p_crear();
    TipoElemento x;

    while (!p_es_vacia(p)) {
        x = p_desapilar(p);
        p_apilar(nueva, x);
        p_apilar(Paux, x);
    }

    while (!p_es_vacia(Paux)) { 
        x = p_desapilar(Paux);
        p_apilar(p,x);
    }

    return nueva; 
}

/*ejercicio 6
Dada una pila con valores al azar eliminar todas las ocurrencias de un determinado 
ítem sin perder la pila original.  Deberá retornar una nueva pila sin el ítem en 
consideración.  Resolver iterativamente y recursivamente.  Determinar la complejidad 
algorítmica de ambas soluciones.
*/
Pila p_ej6_eliminarclave(Pila p, int clave){
    if (p_es_vacia(p))
    {
        return p;
    }
    

    TipoElemento x;
    Pila Auxiliar = p_crear(); //Guardamos los TipoElemento de la Pila original
    Pila ResultadoAux = p_crear();
    Pila Resultado = p_crear();

    while (!p_es_vacia(p))//Recorro la Pila original
    {
        x = p_desapilar(p);
        if (x->clave != clave)//Si tiene la clave la añado a la Pila Que vamos a retornar
        {
            p_apilar(ResultadoAux,x);
        }
        p_apilar(Auxiliar,x);
    }
    
    p = ReApilar(Auxiliar,p);
    p_mostrar(p);
    //INVIERTO la lista Resultado porque como guardaba de forma secuencial los primeros elemtnos estan en la base de la pila
    Resultado = ReApilar(ResultadoAux,Resultado);

    return Resultado;
}

//funcion auxiliar para ej6 recursivo
//le paso los punteros de las auxiliares para 1° no perder la Pila original y 2° luego volver a apilar la pila de resultados para tener el orden original
void Filtrar(Pila p,int Clave,Pila Resultado){
    if (p_es_vacia(p))//caso base no tiene mas elemetos la pila
    {
        return;
    }
    else{
        TipoElemento x = p_desapilar(p);
    
        Filtrar(p,Clave,Resultado);

        if (x->clave != Clave )// no tiene la clave?
        {
            p_apilar(Resultado,x);//subo a la Pila Filtrada
        }
        p_apilar(p,x);
    }
    
}

Pila p_ej6_eliminarclaveRecu(Pila p, int clave){
    // Primero creo una copia
    Pila Resultado = p_crear();

    Filtrar(p,clave,Resultado);

    return Resultado;

}

/*Ejercicio 7
Dada dos pilas realizar una función que permita determinar los elementos que tienen 
en común. Debe retornar una nueva pila con esos elementos (que están en ambas 
pilas) sin perder las pilas originales.  Determinar la complejidad algorítmica de la 
solución. 
*/

TipoElemento p_buscar(Pila P,int Clave){

    Pila Paux = p_crear();
    TipoElemento x, Resultado;
    Resultado = NULL;
    bool Encontrado = false;

    if (p_es_vacia(P))
    {
        return Resultado;
    }

    while (!p_es_vacia(P)&& !Encontrado)
    {
        x = p_desapilar(P);

        if (x->clave == Clave)
        {
            Resultado = x;
            Encontrado = true;
        }
        

        p_apilar(Paux,x);
    }
    
    ReApilar(Paux,P);
    return Resultado;
}

Pila p_ej7_elementoscomunes(Pila p1,Pila p2){

    Pila Paux = p_crear();
    Pila ResultadoAux = p_crear();


    if(p_es_vacia(p1)||p_es_vacia(p2)){ //Retorno PIla vacia si estaban asi cuando fueron ingresadas: Si NO tienen elementos en comun el  output es PILA VACIA!
        return ResultadoAux;
    }

    TipoElemento x;

    while (!p_es_vacia(p1))
    {
        x = p_desapilar(p1);

        if (p_buscar(p2,x->clave) != NULL) //Si esta en p2 lo apilo en la nueva Pila, si no esta p_buscar da NULL
        {
            p_apilar(ResultadoAux,x);
        }
        
        p_apilar(Paux,x);

    }
    
    p1=ReApilar(Paux,p1);//Re apilo para dejarla como la original

    Pila Resultado = p_crear();
    Resultado = ReApilar(ResultadoAux,Resultado);

    return Resultado;

}

/*Ejercicio 8
Dada una pila con valores repetidos, se desea obtener una nueva pila con todos los 
valores (sin repetición) y la cantidad de veces que aparecen.  No debe perderse la pila 
original.  El proceso recibe la pila con las repeticiones  y retorna una nueva pila.  
Determinar la complejidad algorítmica de la solución.
*/

Pila p_ej8_sacarrepetidos(Pila p){

    Pila Presultado = p_crear();
    Pila PresultadoAux = p_crear();
    Pila Pduplicada = p_ej2_duplicar(p);
    Pila Paux = p_crear();

    int Apariciones = 0;
    bool TodosLeidos= false;

    TipoElemento Leido,Acomparar;

    if (p_es_vacia(p))
    {
        return Presultado;
    }
    

    while (!TodosLeidos)
    {
        Leido = p_desapilar(Pduplicada);
        Apariciones++;


        while (!p_es_vacia(Pduplicada))
        {
            Acomparar = p_desapilar(Pduplicada);
            if (Leido->clave == Acomparar->clave)
            {
                Apariciones++;

            }else{
                p_apilar(Paux,Acomparar);
            }
        }
        int* CantAparariciones = (int*) malloc(sizeof(int));
        *CantAparariciones = Apariciones;
        Leido->valor = CantAparariciones;
        p_apilar(Presultado,Leido);
        Apariciones = 0;

        ReApilar(Paux,Pduplicada);

        if (p_es_vacia(Pduplicada))
        {
            TodosLeidos = true;
        }
        
    }
    Presultado = ReApilar(Presultado,PresultadoAux); 

    return Presultado;
}