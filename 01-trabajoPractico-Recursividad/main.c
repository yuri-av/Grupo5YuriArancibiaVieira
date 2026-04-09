#include "tp_1_recursividad.h"

// Librerias
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define MAX_ELEMENTOS 100

// PROTOTIPOS DE LAS HERRAMIENTAS DE VALIDACION
int leerEntero(const char *mensaje, bool permitirNegativos);
void leerCadena(const char *mensaje, char *buffer, int limite);
int main()
{
    char opcionStr[10];
    char letra;
    bool entradaValida; // Variable limpia para controlar la validacion

    // BUCLE DO-WHILE DEL MENU PRINCIPAL
    do
    {
        printf("\n---ELIJA QUE EJERCICIO EJECUTAR---\n");
        printf("A) EJERCICIO 1 |Palindromo\n");
        printf("B) EJERCICIO 2 |Producto\n");
        printf("C) EJERCICIO 3 |Fibonacci\n");
        printf("D) EJERCICIO 4 |Division\n");
        printf("E) EJERCICIO 5 |SeparadorMiles\n");
        printf("F) EJERCICIO 6 |MafiaChina\n");
        printf("G) EJERCICIO 7 |ondaDigital\n");
        printf("H) EJERCICIO 8 |subconjuntosQueSuman\n");
        printf("I) EJERCICIO 9 |divisiblePor7\n");
        printf("J) EJERCICIO 10|Explosion\n");
        printf("K) SALIR\n");

        // BUCLE DO-WHILE PARA VALIDAR LA LETRA INGRESADA
        do
        {
            leerCadena("Ingrese la letra del ejercicio (A-K): ", opcionStr, sizeof(opcionStr));
            letra = toupper(opcionStr[0]); // Tomamos la primera letra y la hacemos mayuscula

            // Evaluamos si cumple las reglas: longitud 1 y estar entre la A y la K
            entradaValida = (strlen(opcionStr) == 1 && letra >= 'A' && letra <= 'K');

            if (!entradaValida)
            {
                printf(" Error: Por favor, ingrese solo una letra entre A y K.\n");
            }
        } while (!entradaValida); // Se repite MIENTRAS la entrada NO sea valida

        // Si el usuario eligio 'K', avisamos y evitamos entrar al switch
        if (letra == 'K')
        {
            printf("\nSaliendo del programa...\n");
        }
        else
        {
            // Ejecutamos el ejercicio correspondiente
            switch (letra)
            {
            ////////////////////////////////////_UNO_/////////////////////////////////////////////////
            case 'A':
            {
                char palabra[100];
                leerCadena("Ingrese una palabra o frase: ", palabra, sizeof(palabra));

                if (palindromo(palabra))
                    printf("Es un palindromo.\n");
                else
                    printf("No es un palindromo.\n");
                break;
            }
            ////////////////////////////////////_DOS_/////////////////////////////////////////////////
            case 'B':
            {
                int m = leerEntero("Ingrese el numero entero 'm' (multiplicando): ", true);
                int n = leerEntero("Ingrese el numero entero 'n' (multiplicador): ", true);

                printf("Iniciando recursion...\n");
                int prod = producto(m, n);
                printf("resultado = %i\n", prod);
                break;
            }
            ////////////////////////////////////_TRES_/////////////////////////////////////////////////
            case 'C':
            {
                int k;
                do
                {
                    k = leerEntero("Ingrese que termino de Fibonacci desea ver (mayor a 0): ", false);
                    if (k <= 0)
                        printf(" Error: El numero debe ser mayor a 0.\n");
                } while (k <= 0);

                int resultado = terminoSeridFibonacci(k);
                printf("fibonacci(%d) = %i\n", k, resultado);
                break;
            }
            ////////////////////////////////////_CUATRO_/////////////////////////////////////////////////
            case 'D':
            {
                int dividendo = leerEntero("Ingrese el dividendo: ", true);
                int divisor;
                do
                {
                    divisor = leerEntero("Ingrese el divisor (no puede ser 0): ", true);
                    if (divisor == 0)
                        printf(" Error: No se puede dividir por 0.\n");
                } while (divisor == 0);

                int precision;
                do
                {
                    precision = leerEntero("Ingrese digitos de precision (0 o mas): ", false);
                    if (precision < 0)
                        printf(" Error: La precision no puede ser negativa.\n");
                } while (precision < 0);

                float resultado = division(dividendo, divisor, precision);
                printf("el resultado es: %.*f\n", precision, resultado);
                break;
            }
            ////////////////////////////////////_CINCO_//////////////////////////////////////////////////
            case 'E':
            {
                char numero[100];
                bool esValido;
                bool esNegativo = false;

                do
                {
                    esValido = true;
                    esNegativo = false;
                    leerCadena("Ingrese un numero para separar por miles (puede ser largo): ", numero, sizeof(numero));

                    int inicio = 0;
                    if (numero[0] == '-')
                    {
                        esNegativo = true;
                        inicio = 1;
                        if (strlen(numero) == 1)
                            esValido = false;
                    }

                    for (int i = inicio; numero[i] != '\0'; i++)
                    {
                        if (!isdigit(numero[i]))
                        {
                            esValido = false;
                            printf(" Error: Contiene caracteres invalidos. Solo ingrese numeros enteros.\n");
                            break;
                        }
                    }
                } while (!esValido);

                char *resultadoFinal = NULL;
                if (esNegativo)
                {
                    resultadoFinal = agregarSeparadorMiles(&numero[1]);
                }
                else
                {
                    resultadoFinal = agregarSeparadorMiles(numero);
                }

                if (resultadoFinal != NULL)
                {
                    printf("Original: %s\n", numero);
                    printf("Formateado: %s%s\n", (esNegativo ? "-" : ""), resultadoFinal);
                    free(resultadoFinal);
                }
                break;
            }
            ////////////////////////////////////_SEIS_/////////////////////////////////////////////////
            case 'F':
            {
                int nivel;
                do
                {
                    nivel = leerEntero("Ingrese el nivel de la reunion (mayor o igual a 1): ", false);
                    if (nivel < 1)
                        printf(" Error: El nivel minimo es 1.\n");
                } while (nivel < 1);

                char *resultadoM = reunionMafia(nivel);
                printf("Vista frontal de la delegacion:\n%s\n", resultadoM);
                free(resultadoM);
                break;
            }
            ////////////////////////////////////_SIETE_/////////////////////////////////////////////////
            case 'G':
            {
                char cadena[100];
                bool valido;

                do
                {
                    valido = true;
                    leerCadena("Ingrese la onda digital (solo L y H): ", cadena, sizeof(cadena));

                    for (int i = 0; cadena[i] != '\0'; i++)
                    {
                        cadena[i] = toupper(cadena[i]);
                        if (cadena[i] != 'L' && cadena[i] != 'H')
                        {
                            printf(" Error: La onda solo puede contener las letras 'L' o 'H'.\n");
                            valido = false;
                            break;
                        }
                    }
                } while (!valido);

                printf("Resultado:\n");
                ondaDigital(cadena);
                printf("\n");
                break;
            }
            ////////////////////////////////////_OCHO_/////////////////////////////////////////////////
            case 'H':
            {
                printf("=== Subconjuntos que suman N ===\n\n");
                char *output;
                int conjunto[MAX_ELEMENTOS] = {0};

                int tamano;
                do
                {
                    tamano = leerEntero("Definir la cantidad de elementos del conjunto (mayor a 0): ", false);
                } while (tamano <= 0);

                int objetivo;
                do
                {
                    objetivo = leerEntero("Definir el objetivo a sumar (mayor a 0): ", false);
                } while (objetivo <= 0);

                printf("==== VALORES DE LA LISTA ====\n");
                for (int i = 0; i < tamano; i++)
                {
                    char msj[50];
                    sprintf(msj, "Ingresar numero %i: ", i + 1);
                    conjunto[i] = leerEntero(msj, true);
                }

                subconjuntosQueSumanN(conjunto, tamano, objetivo, &output);
                printf("\nResultado:\n%s", output);
                free(output);
                break;
            }
            ////////////////////////////////////_NUEVE_/////////////////////////////////////////////////
            case 'I':
            {
                int n = leerEntero("Ingrese un valor para ver si es divisible por 7: ", true);
                bool resultado = divisiblePor7(n);

                if (resultado)
                    printf("%i es divisible por 7\n", n);
                else
                    printf("%i no es divisible por 7\n", n);
                break;
            }
            ////////////////////////////////////_DIEZ_/////////////////////////////////////////////////
            case 'J':
            {
                int n = leerEntero("Ingrese el valor que desea explotar: ", true);
                int b;
                do
                {
                    b = leerEntero("Ingrese el valor de la bomba (mayor a 1): ", false);
                    if (b <= 1)
                        printf(" Error: La bomba debe ser mayor a 1 para causar explosion.\n");
                } while (b <= 1);

                int *arrayExplosivo = explosion(n, b);

                printf("La explosion creo este array: \n[");
                for (int i = 0; arrayExplosivo[i] != -1; i++)
                {
                    printf("%d ", arrayExplosivo[i]);
                }
                printf("]\n");

                free(arrayExplosivo);
                break;
            }
            default:
                // Ahora no necesitamos el default, ya que la validacion asegura que sea de A a J
                break;
            }

            printf("\n------------------------------------------------\n");
        }

    } while (letra != 'K'); // CONDICION DE SALIDA: Se repite MIENTRAS la letra NO sea K.

    return 0;
}
//==============================================================================
// FUNCIONES DE VALIDACION
//==============================================================================

// 1. HERRAMIENTA PARA NUMEROS
int leerEntero(const char *mensaje, bool permitirNegativos)
{
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

// 2. HERRAMIENTA PARA TEXTOS
void leerCadena(const char *mensaje, char *buffer, int limite)
{
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