/*Dados los números enteros m y n, construir una función recursiva que devuelva el
cociente de ambos, calculando el mismo mediante restas sucesivas. Se deberá tener
en cuenta que en el caso de que la división no sea exacta, se devolverán hasta "n"
cifras decimales (si es necesario).
Ejemplos:
division(10, 2) => 5
division(22, 3) => 7,33333  (precision 5)
division(23, 4) => 5,75     (precision 3)
*/
#include <stdlib.h>
#include <stdio.h>

int division_por_resta(int dividendo, int divisor)
{
    if (dividendo < divisor)
    {
        return 0;
    }
    else
    {
        return 1 + division_por_resta(dividendo - divisor, divisor);
    }
}

int resto(int dividendo, int divisor)
{
    if (dividendo < divisor)
    {
        return dividendo;
    }
    return resto(dividendo - divisor, divisor);
}

void division_decimal(int resto_actual, int divisor, int precision)
{
    if (resto_actual == 0 || precision == 0)
    {
        return;
    }

    int nuevo_dividendo = resto_actual * 10;
    int digito = division_por_resta(nuevo_dividendo, divisor);
    printf("%i", digito);

    int proximo_resto = resto(nuevo_dividendo, divisor);
    division_decimal(proximo_resto, divisor, precision - 1);
}

void tests()
{
    printf("=== Tests Ejercicio 4: Division por resta ===\n");

    // Test 1
    int r1 = division_por_resta(10, 2);
    printf("Test 1 - division_por_resta(10, 2)  esperado: 5 | resultado: %d | %s\n",
           r1, r1 == 5 ? "OK" : "FALLO");

    // Test 2
    int r2 = division_por_resta(22, 3);
    printf("Test 2 - division_por_resta(22, 3)  esperado: 7 | resultado: %d | %s\n",
           r2, r2 == 7 ? "OK" : "FALLO");

    // Test 3
    int r3 = resto(22, 3);
    printf("Test 3 - resto(22, 3)               esperado: 1 | resultado: %d | %s\n",
           r3, r3 == 1 ? "OK" : "FALLO");

    printf("\n");
}

int main()
{
    tests();

    int dividendo, divisor, precision;

    printf("Ingrese el dividendo: ");
    scanf("%i", &dividendo);

    printf("Ingrese el divisor: ");
    scanf("%i", &divisor);
    while (divisor == 0)
    {
        printf("Error: no se puede dividir por 0, ingrese de nuevo: ");
        scanf("%i", &divisor);
    }

    printf("Digitos de precision: ");
    scanf("%i", &precision);

    int resultado = division_por_resta(dividendo, divisor);
    printf("%i", resultado);

    int resto_inicial = resto(dividendo, divisor);
    if (resto_inicial > 0 && precision > 0)
    {
        printf(",");
        division_decimal(resto_inicial, divisor, precision);
    }
    printf("\n");

    return 0;
}