#include "tp_1_recursividad.h"

//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
//Ejercicio 1:

bool palindromoResolucion(char palabra[], int inicio, int fin) {
    if (inicio >= fin) {
        return true;
    }
    if (!isalpha(palabra[inicio])) {
        return palindromoResolucion(palabra, inicio + 1, fin);
    }
    if (!isalpha(palabra[fin])) {
        return palindromoResolucion(palabra, inicio, fin - 1);
    }
    if (tolower(palabra[inicio]) != tolower(palabra[fin])) {
        return false;
    }
    return palindromoResolucion(palabra, inicio + 1, fin - 1);
}
bool palindromo (char * cadena){
    int inicio = 0;
    int fin = strlen(cadena) - 1;
    bool resultado=palindromoResolucion(cadena,inicio,fin);
}

//ejercicio 2:
int producto_por_suma(int a, int b)
{
    int resultado;
    if (b == 0)
    {
        resultado = 0;
    }
    else if (b > 0)
    {
        resultado = a + producto_por_suma(a, b - 1);
    }
    else
    {
        resultado = -a + producto_por_suma(a, b + 1);
    }
    return resultado;
}

//Ejercicio 3
int fibonacci(int k)
{
    int resultado;
    if (k == 1)
    {
        resultado = 1;
    }
    else if (k == 2)
    {
        resultado = 1;
    }
    else
    {
        resultado = fibonacci(k - 1) + fibonacci(k - 2);
    }
    return resultado;
}

//Ejercicio 4
void divisionResolucion(int m, int n, int *decimales, float *resultado, float peso, int limite) {
    if ((m == 0) || *decimales > limite) {
        return;
    }

    if (m < n) {
        *decimales += 1;
        divisionResolucion(m * 10, n, decimales, resultado, peso / 10.0, limite);
    } else {
        *resultado += peso;
        divisionResolucion(m - n, n, decimales, resultado, peso, limite);
    }
}

float division(int m, int n, int d) {
    int contadorDecimales = 0;
    float resultado = 0;
    divisionResolucion(m, n, &contadorDecimales, &resultado, 1.0, d);

    return resultado;
}

//ejercicio 5
void agregarSeparadorResultado(char origen[],char destino[],int posOriginal, int posDestino,int largo){
    if(posOriginal==largo){
        destino[posDestino]='\0';
        return;
    }
    else{
        destino[posDestino]=origen[posOriginal];
        int quedanHaciaDerecha=(largo-1)-posOriginal;

        if(quedanHaciaDerecha>0 && (quedanHaciaDerecha%3==0)){
            destino[posDestino+1]='.';
            agregarSeparadorResultado(origen,destino,posOriginal+1,posDestino+2,largo);
        }
        else{
            agregarSeparadorResultado(origen,destino,posOriginal+1,posDestino+1,largo);
        }

    }
}


char * agregarSeparadorMiles(char numero[]){
   int largo,puntos,espacioTotal;
    //largo de la cadena
   largo=strlen(numero);
   //cantidad de puntos que va a tener el numero
   puntos=(largo-1)/3;
   //total de numeros + puntos + '/0'
   espacioTotal=largo+puntos+1;
   char *cadena = (char *)malloc(espacioTotal * sizeof(char));

   agregarSeparadorResultado(numero,cadena,0,0,largo);

   return cadena;
}

//ejercicio 6
char *reunionMafia(int nivel)
{
    if (nivel <= 1)
    {
        char *base = (char *)malloc(6 * sizeof(char));
        strcpy(base, "(-.-)");
        return base;
    }
    else
    {
        char *subNivel = reunionMafia(nivel - 1);

        int tamano = strlen(subNivel) + 7;
        char *nuevoNivel = (char *)malloc(tamano * sizeof(char));

        sprintf(nuevoNivel, "(-.%s.-)", subNivel);

        free(subNivel);

        return nuevoNivel;
    }
}

//ejercicio 7
void OndaDigital(char *cadena) {
    if (*cadena == '\0') {
        return;
    }

    //caso inicial
    if (*cadena == 'L') {
        printf("_");
    } else {
        printf("¯");
    }

    //si hubo cambio
    if (*(cadena + 1) != '\0') {
        printf(" ");
        if (*cadena != *(cadena + 1)) {
            printf("|");
        }
    }
    OndaDigital(cadena + 1);
}

//Ejercicio 8

void buscarSubconjuntos(int conjunto[], int tamano, int objetivo, int indiceActual, int subconjuntoActual[], int tamanoSubconjunto, char **output)
{
    // Caso base 1: Se encontró un subconjunto válido
    if (objetivo == 0)
    {
        char bufferTemporal[256];
        int desplazados = 0;

        desplazados += sprintf(bufferTemporal + desplazados, "{");

        for (int i = 0; i < tamanoSubconjunto; i++)
        {
            desplazados += sprintf(bufferTemporal + desplazados, "%i, ", subconjuntoActual[i]);
        }
        desplazados += sprintf(bufferTemporal + desplazados, "}\n");
        strcat(*output, bufferTemporal);
        return;
    }
    // Caso base 2: Se terminaron los números o el objetivo es negativo
    if (indiceActual == tamano || objetivo < 0)
    {
        return;
    }

    // Camino A: INCLUIR
    subconjuntoActual[tamanoSubconjunto] = conjunto[indiceActual];
    buscarSubconjuntos(conjunto, tamano, objetivo - conjunto[indiceActual], indiceActual + 1, subconjuntoActual, tamanoSubconjunto + 1, output);
    // Camino B: EXCLUIR
    buscarSubconjuntos(conjunto, tamano, objetivo, indiceActual + 1, subconjuntoActual, tamanoSubconjunto, output);
}

void subconjuntosQueSumanN(int conjunto[], int tamano, int objetivo, char **output)
{
    int subconjuntoActual[MAX];

    *output = malloc(1024 * sizeof(char)); // Reservamos la memoria
    (*output)[0] = '\0';                   // La inicializamos limpia

    buscarSubconjuntos(conjunto, tamano, objetivo, 0, subconjuntoActual, 0, output);
}
int leer_entero(const char *mensaje)
{
    char buffer[50];
    int valor;
    char extra;
    bool valido = false;

    while (valido != true)
    {
        printf("%s", mensaje);

        // 1. Intentar leer la entrada
        if (fgets(buffer, sizeof(buffer), stdin) == NULL || buffer[0] == '\n')
        {
            printf("  Error: no puede ser nulo. Intente de nuevo.\n");
        }
        // 2. Validar si hay caracteres extra después del número
        else if (sscanf(buffer, "%d %c", &valor, &extra) != 1)
        {
            printf("  Error: solo se permiten numeros enteros. Intente de nuevo.\n");
        }
        // 3. Si no entró en los errores anteriores, la entrada es válida
        else
        {
            printf("Valor valido!\n");
            valido = true;
        }
    }
    return valor;
}
//Ejercicio 9

bool divisible_por_7(int n){
    if (n < 0){
        n = -n;
    }
    if (n < 70){
        return (n % 7 == 0);
    }
    else{
        int ultima_cifra = n % 10;
        int resto = n / 10;
        int nuevo = resto - 2 * ultima_cifra;

        if (nuevo < 0)
            nuevo = -nuevo;

        return divisible_por_7(nuevo);
    }
}

//Ejercicio 10
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

//fin :)
