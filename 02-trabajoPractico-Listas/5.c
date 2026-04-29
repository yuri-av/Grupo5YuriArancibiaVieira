#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "tp_2_listas.h"
#include "listas.h"
#include "tipo_elemento.h"

// Firmas de las funciones
void hacerPolinomio(Lista list);
float evaluarPoliomio(Lista list, float x);
Lista calcularRango(Lista list, double x, double y, double sumando);
int validacion_ingreso_int();
double validacion_ingreso_double();

int main()
{
    Lista polinomio = l_crear();

    printf("=== CARGA DEL POLINOMIO ===\n");
    printf("Ejemplo: 3x^2 + 2x + 1\n");
    printf("Los coeficientes se cargaran en orden ascendente (x^0, x^1, x^2...)\n\n");

    /* VALIDAR CANTIDAD DE TERMINOS */
    printf("Ingrese cantidad de terminos del polinomio (mayor a 0): ");
    int cantidad;
    do
    {
        cantidad = validacion_ingreso_int();
        if (cantidad <= 0)
        {
            printf("Error: debe ingresar un numero entero mayor a 0: ");
        }
    } while (cantidad <= 0);

    /* CARGA DEL POLINOMIO */
    for (int i = 0; i < cantidad; i++)
    {
        printf("\n--- Termino %d ---", i + 1);
        hacerPolinomio(polinomio);
    }

    printf("\nPolinomio cargado:\n");
    l_mostrar(polinomio);

    /* EVALUAR POLINOMIO */
    printf("\n=== EVALUAR POLINOMIO ===\n");
    printf("Ingrese valor de x: ");
    float x = (float)validacion_ingreso_double();

    float resultado = evaluarPoliomio(polinomio, x);
    printf("Resultado de F(%.2f) = %.2f\n", x, resultado);

    /* CALCULAR RANGO */
    printf("\n=== CALCULAR RANGO ===\n");

    printf("Ingrese valor inicial de x: ");
    double desde = validacion_ingreso_double();

    printf("Ingrese valor final de x (mayor o igual al inicial): ");
    double hasta;
    do
    {
        hasta = validacion_ingreso_double();
        if (hasta < desde)
        {
            printf("Error: debe ingresar un numero valido y mayor o igual a %.2lf: ", desde);
        }
    } while (hasta < desde);

    printf("Ingrese intervalo de salto (mayor a 0): ");
    double intervalo;
    do
    {
        intervalo = validacion_ingreso_double();
        if (intervalo <= 0)
        {
            printf("Error: debe ingresar un numero mayor a 0: ");
        }
    } while (intervalo <= 0);

    Lista rango = calcularRango(polinomio, desde, hasta, intervalo);

    printf("\nValores del polinomio en el rango:\n");
    l_mostrar(rango);

    return 0;
}

int validacion_ingreso_int()
{
    int numero;
    char car = '\0';

    while (scanf("%d%c", &numero, &car) != 2 || car != '\n')
    {
        printf("Entrada invalida. Ingrese un numero entero: ");
        if (car != '\n')
        {
            while (getchar() != '\n')
                ;
        }
        car = '\0';
    }
    return numero;
}

double validacion_ingreso_double()
{
    double numero;
    char car = '\0';

    while (scanf("%lf%c", &numero, &car) != 2 || car != '\n')
    {
        printf("Entrada invalida. Ingrese un numero (puede usar decimales): ");
        if (car != '\n')
        {
            while (getchar() != '\n')
                ;
        }
        car = '\0';
    }
    return numero;
}

void hacerPolinomio(Lista list)
{
    int potencia_actual = l_longitud(list);
    printf("\nIngrese el coeficiente para x^%d: ", potencia_actual);
    int coeficiente = validacion_ingreso_int();

    l_agregar(list, te_crear(coeficiente));
}

float evaluarPoliomio(Lista list, float x)
{
    float resultado = 0;
    int exponente = 0;
    Iterador iter = iterador(list);

    while (hay_siguiente(iter))
    {
        TipoElemento te = siguiente(iter);
        resultado += (float)(te->clave * pow(x, exponente));
        exponente++;
    }

    return resultado;
}

Lista calcularRango(Lista list, double x, double y, double sumando)
{
    Lista resultados = l_crear();

    for (double x_actual = x; x_actual <= (y + 0.00001); x_actual += sumando)
    {
        float valor_y = evaluarPoliomio(list, (float)x_actual);
        l_agregar(resultados, te_crear((int)valor_y));
    }

    return resultados;
}