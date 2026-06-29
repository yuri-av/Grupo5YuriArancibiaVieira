#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include "tp_conjunto.h"

void comparar(Conjunto A,Conjunto B);
int Contar_Coincidencias(Conjunto A,Conjunto B);

Conjunto c_ej2_union(Conjunto A, Conjunto B){
    return cto_union(A,B);
}

Conjunto c_ej2_interseccion(Conjunto A, Conjunto B){
    return cto_interseccion(A,B);
}

Conjunto c_ej2_diferencia(Conjunto A, Conjunto B){
    return cto_diferencia(A,B);
}
bool c_ej2_pertenece(Conjunto conjunto, int clave){
    return cto_pertenece(conjunto,clave);
}



Conjunto c_ej3_uniones(Lista l_de_conjuntos){
    Conjunto ctoaux = cto_crear();
    Iterador it = iterador(l_de_conjuntos);
        while (hay_siguiente(it)){
            TipoElemento sig = siguiente(it);
            ctoaux = cto_union(ctoaux,sig->valor);
        }
        return ctoaux;
}
Conjunto c_ej3_intersecciones(Lista l_de_conjuntos){
    if (l_es_vacia(l_de_conjuntos)){
        return cto_crear();
    }

    Iterador it = iterador(l_de_conjuntos);
    TipoElemento sig = siguiente(it);
    Conjunto ctoaux = sig->valor;

    while (hay_siguiente(it)){
        sig = siguiente(it);
        ctoaux = cto_interseccion(ctoaux, sig->valor);
    }
    free(it);
    return ctoaux;
}
bool c_ej4_transitividad(Conjunto A, Conjunto B, Conjunto C){

    //como los Conjuntos "mayores son vacios" y A no lo es , no pertenece
    if ((cto_es_vacio(C) ||cto_es_vacio(B)) && !cto_es_vacio(A))
    {
        return false;
    }
    
    if (cto_cantidad_elementos(C) < cto_cantidad_elementos(B) && cto_cantidad_elementos(A) > cto_cantidad_elementos(B))
    {
       return false;
    }

    TipoElemento x;

    bool AsubconjuntoB = true;
    bool BsubConjuntoC = true;
    bool AsubconjuntoC = true;

    for (int i = 1; i <= cto_cantidad_elementos(A); i++)
    {
        x = cto_recuperar(A,i);
        if (!cto_pertenece(B,x->clave))
        {
            AsubconjuntoB = false;
        }       
    }
    for (int i = 1; i <= cto_cantidad_elementos(B); i++)
    {
        x = cto_recuperar(B,i);
        if (!cto_pertenece(C,x->clave))
        {
        BsubConjuntoC = false;
        }  
    }

    for (int i = 1; i <= cto_cantidad_elementos(A); i++)
    {
        x = cto_recuperar(A,i);
        if (!cto_pertenece(C,x->clave)) AsubconjuntoC = false;
    }

    if (AsubconjuntoB == false)
    {
        printf(" \nEl primero no es Subconjunto del segundo \n");
    }else if(BsubConjuntoC == false){
        printf(" \nEl primero no es Subconjunto del segundo \n");
    }
    

    return AsubconjuntoB && BsubConjuntoC && AsubconjuntoC;

}

/*5. Desarrollar un algoritmo capaz de resolver la diferencia simétrica (por la clave) entre
dos conjuntos. La diferencia simétrica es una operación entre dos conjuntos donde el
conjunto resultante está conformado por los elementos no comunes a los dos
conjuntos. */
Conjunto c_ej5_dif_simetrica(Conjunto A, Conjunto B){


    //Primero DIferencia entre A y B
    Conjunto DifA_B = cto_diferencia(A,B);
    
    //Segundo Diferencia entre B y  A
    Conjunto DifB_A = cto_diferencia(B,A);

    //JUNTO LOS ELEMETNOS
    Conjunto DifSimetrica = cto_union(DifA_B,DifB_A);

    return DifSimetrica;

}
/*
Dados dos conjuntos de números naturales se pide determinar si uno es subconjunto
propio del otro. Determinar la complejidad algorítmica
*/
bool c_ej6_subconjuntopropio(Conjunto A, Conjunto B){

    TipoElemento x ;

    bool Subconjunto = true;
    if (cto_cantidad_elementos(B) <= cto_cantidad_elementos(A))
    {
        return false;
    }

    for (int  i = 1; i <= cto_cantidad_elementos(A); i++)
    {
        x = cto_recuperar(A,i);
        if(cto_pertenece(B,x->clave) == false){
            Subconjunto = false;
        }
    }
    
    return Subconjunto;
    
}
void c_ej7_subconjtotalparcial(Conjunto A, Conjunto B, Conjunto C){
    printf("A vs B: "); comparar(A,B);
    printf("B vs A: "); comparar(B,A);

    printf("A vs C: "); comparar(A,C);
    printf("C vs A: "); comparar(C,A);

    printf("B vs C: "); comparar(B,C);
    printf("C vs B: "); comparar(C,B);
}
int Contar_Coincidencias(Conjunto A,Conjunto B){
    int contador = 0;
    for (int i = 1; i <= cto_cantidad_elementos(A);i++){
    TipoElemento sig = cto_recuperar(A,i);
    if (cto_pertenece(B,sig->clave)){
        contador ++;
    }
}
    return contador;
}

void comparar(Conjunto A,Conjunto B){
    int cant = Contar_Coincidencias(A,B);
    if (cant == cto_cantidad_elementos(A)){
        printf("El primero es subconjunto total del segundo.\n");
    }
    else if (cant * 2 >= cto_cantidad_elementos(A)) {
        printf("El primero es subconjunto parcial del segundo.\n");
    }
    else{
        printf("El primero no es subconjunto del segundo.\n");
    }
}

// Complejidad cuadrática.
bool c_ej8_soniguales(Conjunto A, Conjunto B){
    
    bool TodoBestaEnA = true;
    bool TodoAestaEnB = true;
    TipoElemento x;

    for (int i = 1; i <= cto_cantidad_elementos(A); i++)
    {
        x = cto_recuperar(A,i);
        if (!cto_pertenece(B,x->clave))
        {
            TodoAestaEnB = false;
        }
    }
        for (int i = 1; i <= cto_cantidad_elementos(B); i++)
    {
        x = cto_recuperar(B,i);
        if (!cto_pertenece(A,x->clave))
        {
            TodoBestaEnA = false;
        }
    }
    return TodoAestaEnB && TodoBestaEnA;

}
