#include <stdio.h>
#include <stdlib.h>

//Ejercicio 10
/*
10.  Se dice que N es un número explosivo cuando éste explota en varios fragmentos más 
chicos que él, dada una bomba B. Si se tiene que N es el número y B la bomba, tales 
que N es mayor que B, se puede hacer que N explote en dos números N1 = N / B 
(división entera) y N2 = N - (N / B). 
Pero B es una bomba que produce una reacción en cadena, si N1 o N2 son mayores que 
B, estos también explotan con la regla anterior, hasta que se encuentre que el número 
no es mayor que B; entonces se dice que ya no se puede explotar el número. 
Escribe una función recursiva que retorne una lista con los pedazos del número N, 
dado que se tiene la bomba B.

Ejemplos: 
Número: 10 
Bomba: 3 
explosion(10, 3) => [3 2 1 1 3] 
Número: 20 
Bomba: 5 
explosion(20, 5) => [4 3 2 2 1 1 1 1 5]
*/

int contarEspacio(int n, int b){
    if(n<=b){
        return 1;
    }
    else{
        int n1=n/b;
        int n2=n-n1;
        return contarEspacio(n1,b)+contarEspacio(n2,b);
    }
}

void llenarArray(int n, int b, int array[], int *i){
    if(n<=b){
        array[*i]=n;
        (*i)++;
    }
    else{
        int n1=n/b;
        int n2=n-n1;

        llenarArray(n1,b,array,i);
        llenarArray(n2,b,array,i);
    }
}

int* explosion (int n, int b){
    int tamanio=contarEspacio(n,b);

    int* listaFinal=(int*) malloc((tamanio+1)*sizeof(int));
    int i=0;
    llenarArray(n,b,listaFinal,&i);
    listaFinal[tamanio] = -1;

    return listaFinal;
}


int main(){
    int n,b;

    printf("ingrese un valor a explotar: ");
    scanf("%d",&n);
    printf("\n");
    printf("ingrese un valor bomba: ");
    scanf("%d",&b);
    printf("\n");

    int *arrayExplosivo=explosion(n,b);

    printf("la explosion creo este array: \n");
    printf("[");
    for(int i=0;arrayExplosivo[i]!=-1;i++){
        printf("%d ",arrayExplosivo[i]);
    }
    printf("]\n");


    return 0;
}