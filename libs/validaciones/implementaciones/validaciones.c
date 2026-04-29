#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>   // strlen, strcspn
#include <ctype.h>    // toupper


/* 
pasamos:
-los parametros para leerCadena()
-la cantidad de variables que hay en el menu (ejemplo, A-F)
*/
char validacionDeLetra(char mensaje[], char opcionStr[], int tamOpcion, char inicio, char fin)
{
    char letra;
    bool entradaValida;

    do
    {
        leerCadena(mensaje, opcionStr, tamOpcion);
        letra = toupper(opcionStr[0]); // Tomamos la primera letra y la convertimos a mayúscula

        // Válido si es exactamente 1 carácter y está dentro del rango indicado
        entradaValida = (strlen(opcionStr) == 1 && letra >= inicio && letra <= fin);

        if (!entradaValida)
        {
            printf(" Error: Ingrese solo una letra entre %c y %c.\n", inicio, fin);
        }
    } while (!entradaValida);

    return letra; // Retornamos la letra válida
}

//validacion general para un numero entero
int validacion_ingreso(){
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

// 2. HERRAMIENTA PARA TEXTOS
void leerCadena(const char *mensaje, char *buffer, int limite){
    while (true)
    {
        printf("%s", mensaje);
        if (fgets(buffer, limite, stdin) != NULL)
        {
            buffer[strcspn(buffer, "\n")] = 0; // Buscamos y quitamos el salto de linea oculto

            if (strlen(buffer) > 0)
            {
                return; // Es un texto valido, salimos
            }
            else
            {
                printf(" Error: La entrada no puede estar vacia.\n");
            }
        }
        else
        {
            printf(" Error de lectura.\n");
            // Limpiamos el buffer de entrada en caso de error critico
            clearerr(stdin);
        }
    }
}

// 1. HERRAMIENTA PARA NUMEROS
int leerEntero(const char *mensaje, bool permitirNegativos){
    char buffer[100];
    int valor;
    char extra;

    while (true)
    {
        printf("%s", mensaje);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        {
            printf(" Error de lectura. Intente de nuevo.\n");
            continue;
        }

        if (buffer[0] == '\n')
        {
            printf(" Error: No puede dejar el campo vacio.\n");
            continue;
        }

        int leidos = sscanf(buffer, "%d %c", &valor, &extra);

        if (leidos == 1)
        {
            if (!permitirNegativos && valor < 0)
            {
                printf(" Error: No se permiten numeros negativos aqui.\n");
            }
            else
            {
                return valor;
            }
        }
        else
        {
            printf(" Error: Entrada invalida. Ingrese solo un numero entero.\n");
        }
    }
}