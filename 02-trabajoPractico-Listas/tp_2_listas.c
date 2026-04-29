#include "tp_2_listas.h"
#include "validaciones.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//2.a
Lista verElementosQueNoSeRepiten(Lista l1, Lista l2) {
    Lista resultado = l_crear();

    Iterador it = iterador(l1);
    while (hay_siguiente(it)) {
        TipoElemento e = siguiente(it);

        // Si la clave de e NO está en l2, la agrego al resultado
        if (l_buscar(l2, e->clave) == NULL) {
            TipoElemento nuevo = te_crear(e->clave);
            l_agregar(resultado, nuevo);
        }
    }

    return resultado;
}

//2_b
/*
Lista verElementosQueNoSeRepiten(Lista l1, Lista l2) {
    Lista resultado = l_crear();

    Iterador it = iterador(l2);
    while (hay_siguiente(it)) {
        TipoElemento e = siguiente(it);

        // Si la clave de e NO está en l1, la agrego al resultado
        if (l_buscar(l1, e->clave) == NULL) {
            TipoElemento nuevo = te_crear(e->clave);
            l_agregar(resultado, nuevo);
        }
    }

    return resultado;
}
*/
//2_c  Que retorne una lista con todos los valores comunes a ambas listas (L1 y L2).
Lista verElementosRepetidos(Lista l1, Lista l2) {
    Lista repetidos = l_crear();
    Iterador ite = iterador(l1);

    while (hay_siguiente(ite)) {          // Por cada elemento de l1...
        TipoElemento elem1 = siguiente(ite);
        bool encontrado = false;          // Todavía no hay coincidencia

        Iterador iteL = iterador(l2);     // Reiniciamos l2 desde el principio
        while (hay_siguiente(iteL) && !encontrado) { // Recorremos l2 hasta encontrar o terminar
            TipoElemento elem2 = siguiente(iteL);
            if (elem1->clave == elem2->clave) { 
                l_agregar(repetidos, elem1);    // agregamos el elemento a la lista resultado
                encontrado = true;              // Marcamos que ya lo encontramos para frenar el while interno
            }
        }
    }

    return repetidos; 
}

//2_d
float promedio(Lista l1) {
    if (l_es_vacia(l1)) return 0.0f;

    float suma = 0.0f;
    int cantidad = 0;

    Iterador it = iterador(l1);
    while (hay_siguiente(it)) {
        TipoElemento e = siguiente(it);
        suma += e->clave;   // acumula la suma
        cantidad++;         // cuenta elementos
    }
    free(it);
    return suma / cantidad; // divide al final
}

//2_e retornar valor minimo y su posicion
/*typedef struct resultadoStruct
{
    int pos;
    int valor;
    int pos_2;
    int valor_2;
} ResultadoValorMinimo;*/
ResultadoValorMinimo valorMinimo(Lista l1, Lista l2){
    ResultadoValorMinimo res;
    
    // Mínimo de l1
    int minVal = l_recuperar(l1, 1)->clave;
    int minPos = 1;
    int actual;

    for (int i = 2; i <= l_longitud(l1); i++) {
        actual = l_recuperar(l1, i)->clave;
        if (actual < minVal) {   
            minVal = actual;     
            minPos = i;          
        }
    }
    res.valor = minVal;
    res.pos = minPos;

    // Mínimo de l2
    int minVal2 = l_recuperar(l2, 1)->clave;
    int minPos2 = 1;

    for (int j = 2; j <= l_longitud(l2); j++) {
        actual = l_recuperar(l2, j)->clave;
        if (actual < minVal2) {   
            minVal2 = actual;     
            minPos2 = j;          
        }
    }
    res.valor_2 = minVal2;
    res.pos_2 = minPos2;

    return res;
}


//ejercicio 3
ResultadosMul multiplo(Lista l1, Lista l2){
    ResultadosMul resultados;

    if((l_es_vacia(l1)||l_es_vacia(l2))==true){
       resultados.esMultiplo=false; 
       resultados.escalar=false;
       return resultados;
    }
    else{
        if(l_longitud(l1)>l_longitud(l2)){
            resultados.esMultiplo=false; 
            resultados.escalar=false;
            return resultados;
        }
        else{
            
            int i=1;
            Iterador it = iterador(l1);
            while(hay_siguiente(it)){
                siguiente(it);
                if(l_recuperar(l1,i)->clave == 0){
                    resultados.esMultiplo=false; 
                    resultados.escalar=false;
                    return resultados;
                }
                if((l_recuperar(l2,i)->clave % l_recuperar(l1,i)->clave)==0){
                    i++;
                }
                else {
                    resultados.esMultiplo=false; 
                    resultados.escalar=false;
                    return resultados;
                }
            }
            int primerCociente= l_recuperar(l2,1)->clave / l_recuperar(l1,1)->clave;
            resultados.esMultiplo=true;
            resultados.escalar=true;
            int k=1;
            while((l_longitud(l1)>=k) && resultados.escalar==true){
                if ((l_recuperar(l2,k)->clave / l_recuperar(l1,k)->clave)!= primerCociente){
                    resultados.escalar=false;
                }
                else{
                    k++;
                }
            }
            resultados.numEscalar=primerCociente;
        }
    }

    return resultados;
}



// P4 Retorna 1 si L1 > L2, 2 si L2 > L1, 0 si son iguales
// Complejidad: O(min(n, m)) donde n = longitud de l1, m = longitud de L2
int CompararListas(Lista l1, Lista L2){
    int contUno=0;
    int contDos=0;
    int resultado;
    Iterador iterU = iterador(l1);
    Iterador iterD = iterador(L2);

    TipoElemento eUno;
    TipoElemento eDos;
    while (hay_siguiente(iterU) && hay_siguiente(iterD)){
      eUno=siguiente(iterU);
      eDos=siguiente(iterD);

      if(eUno->clave >eDos->clave){
            contUno++;
        }else if(eUno->clave < eDos->clave){
            contDos++;
        }
    }

    if(contUno > contDos) resultado=1;
    else if(contUno < contDos) resultado=2;
    else resultado=0;

    return resultado;
}
//Ejercicio 5
/*Generar un algoritmo que guarde en una lista enlazada los coeficientes de un polinomio. 
Realizar una función que dada la lista de coeficientes y un cierto valor de “X” nos devuelva 
el valor del polinomio para ese punto.  
Luego realizar un proceso que dado un rango de valores de “X” y un valor de intervalo 
“I”, retorne una lista con los valores de “Y” o “F(x)”. 
Ejemplo: si el polinomio es F(x) = 2x + 1.  Se pide retornar los valores de F(x) entre los 
“X” -1 y 1 de a “0,5”.  Es decir se deberían retornar los valores de F(-1), F(-0,5), F(0), 
F(0,5) y F(1).*/

/*Función que recibe una lista vacía y la carga con los términos del polinomio; los 
mismos tendrán el exponente o grado del término (entero mayor o igual a 0) en "clave" y el coeficiente real 
apuntado por "valor". */
void hacerPolinomio(Lista list){
    int n, exponente, control;
    float coeficiente;

    /* VALIDAR CANTIDAD DE TERMINOS */
    printf("Ingrese cantidad de terminos del polinomio (mayor a 0): ");
    control = scanf("%d", &n);

    while (control != 1 || n <= 0)
    {
        printf("Error: debe ingresar un numero entero mayor a 0.\n");
        while (getchar() != '\n');
        printf("Ingrese cantidad de terminos del polinomio (mayor a 0): ");
        control = scanf("%d", &n);
    }

    for (int i = 0; i < n; i++)
    {
        printf("\n-- Termino %d --\n", i + 1);

        /* VALIDAR EXPONENTE */
        printf("Ingrese el exponente (entero >= 0): ");
        control = scanf("%d", &exponente);

        while (control != 1 || exponente < 0)
        {
            printf("Error: el exponente debe ser un entero mayor o igual a 0.\n");
            while (getchar() != '\n');
            printf("Ingrese el exponente (entero >= 0): ");
            control = scanf("%d", &exponente);
        }

        /* VALIDAR COEFICIENTE */
        printf("Ingrese el coeficiente (real): ");
        control = scanf("%f", &coeficiente);

        while (control != 1)
        {
            printf("Error: debe ingresar un numero valido.\n");
            while (getchar() != '\n');
            printf("Ingrese el coeficiente (real): ");
            control = scanf("%f", &coeficiente);
        }

        // Reservamos memoria para el coeficiente porque valor es void*
        float* punteroCoef = (float*) malloc(sizeof(float));
        *punteroCoef = coeficiente;

        // clave = exponente, valor = dirección del coeficiente
        TipoElemento termino = te_crear_con_valor(exponente, punteroCoef);
        l_agregar(list, termino);
    }

    printf("\nPolinomio cargado con %d terminos.\n", n);
}
/*Función que recibe el polinomio y un número real y devuelve el valor del polinomio 
evaluado en ese valor de x.*/
float evaluarPoliomio(Lista list, float x){
    float resultado = 0;

    // Iteramos por cada término de la lista
    Iterador iter = iterador(list);

    while (hay_siguiente(iter))
    {
        TipoElemento termino = siguiente(iter);

        int exponente        = termino->clave;
        float coeficiente    = *((float*) termino->valor); // casteamos void* a float*

        // Acumulamos: coef * x^exp
        resultado += coeficiente * (float) pow(x, exponente);
    }

    free(iter);
    return resultado;
}

/*Función que calcula el polinomio en un rango de valores de x.
Recibe: el polinomio, los valores mínimo y máximo del intervalo y la diferencia entre cada valor 
tomado del intervalo.
Devuelve: una lista de valores reales apuntados por "valor", y que representan los 
valores del polinomio en los sucesivos puntos del intervalo.*/
Lista calcularRango(Lista list, double x, double y, double sumando){
    Lista resultados = l_crear();

    double actual = x;

    // Recorremos el rango de x hasta y de a sumando
    while (actual <= y)
    {
        float valorEnX = evaluarPoliomio(list, (float) actual);

        // Guardamos el resultado como float* en valor, y la posición como clave
        float* punteroVal = (float*) malloc(sizeof(float));
        *punteroVal = valorEnX;

        // Usamos la posición actual dentro de la lista como clave
        int clave = l_longitud(resultados) + 1;

        TipoElemento elem = te_crear_con_valor(clave, punteroVal);
        l_agregar(resultados, elem);

        printf("F(%.4f) = %.4f\n", actual, valorEnX);

        actual += sumando;
    }

    return resultados;
}


// ejercicio 6
// Complejidad algoritmica: O(n*m), donde n=longitud(l1) y m=longitud(l2)
// En el peor caso, si ambas listas tienen igual tamaño, se simplifica a O(n²)
bool esSublista(Lista l1, Lista l2){
    Iterador iterU = iterador(l1);
    bool esta = true;

    while (hay_siguiente(iterU) && esta){
        TipoElemento eUno = siguiente(iterU);
        
        Iterador iterD = iterador(l2);
        bool encontrado = false;
        
        while(hay_siguiente(iterD) && !encontrado){
            TipoElemento eDos = siguiente(iterD);
            if(eDos->clave == eUno->clave){
                encontrado = true;
            }
        }
        
        if(!encontrado){
            esta = false;
        }
    }

    return esta;
}

//rellenar listas
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

            // Reemplazamos todo el bucle de limpieza y scanf por la funcion generica
            int clave = validacion_ingreso();

            TipoElemento te = te_crear(clave);
            l_agregar(lista, te); // Usamos 'l1'
        }
    }

    return lista; // Devolvemos la lista ya rellenada
}