/*Construir un algoritmo que, utilizando el TAD Pila, permita convertir un número
decimal pasado como parámetro, a su correspondiente valor expresado en una base
de 2 a 16 (hexadecimal). Determinar la complejidad algorítmica de la solución.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "pilas.h"
#include "tipo_elemento.h"
#define MAX 100

char *p_ej4_cambiarbase(int nrobasedecimal, int nrootrabase);
char conversion(int n);
int validacion_ingreso();
void llenar_lista(char lista[], Pila pila, int contador);

int main()
{
    int nrobasedecimal, nrootrabase;
    char *res;
    // Crear validacion de rango entre 2 y 16
    // Pedir datos numericos de base y nueva base
    printf("Ingresa un numero mayor 0 entero para convertir: ");
    nrobasedecimal = validacion_ingreso();

    printf("Ingresa un numero entre 2 y 16: ");
    nrootrabase = validacion_ingreso();

    while (nrootrabase < 2 || nrootrabase > 16)
    {
        printf("ERROR: El numero debe estar entre 2 y 16\n");
        printf("Ingresa otro numero entre 2 y 16: ");
        nrootrabase = validacion_ingreso();
    }

    res = p_ej4_cambiarbase(nrobasedecimal, nrootrabase);
    free(res);
    return 0;
}

int validacion_ingreso()
{
    int numero;
    char car;

    while (scanf("%d%c", &numero, &car) != 2 || car != '\n')
    {
        // Mensaje genérico para cualquier número entero
        printf("Opcion invalida. Ingrese un numero entero: ");

        // Limpieza del buffer de entrada
        if (car != '\n')
        {
            while (getchar() != '\n')
                ;
        }
    }

    // Retornamos el valor ya validado
    return numero;
}

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
    char resultado;
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