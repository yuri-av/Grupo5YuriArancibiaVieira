
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool divisible_por_7(int n)
{
    if (n < 0)
        n = -n;

    if (n < 70)
    {
        return (n % 7 == 0);
    }
    else
    {
        int ultima_cifra = n % 10;
        int resto = n / 10;
        int nuevo = resto - 2 * ultima_cifra;

        if (nuevo < 0)
            nuevo = -nuevo;

        return divisible_por_7(nuevo);
    }
}

int validacion_entero()
{
    int n;
    char buffer[100];
    char extra;

    while (1)
    {
        printf("Ingrese un valor: ");

        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
            continue;

        if (buffer[0] == '\n')
        {
            printf("Error: No ingreso nada. Por favor, ");
            continue;
        }

        int leidos = sscanf(buffer, "%d %c", &n, &extra);

        if (leidos == 1)
        {
            return n;
        }
        else
        {
            printf("Error de tipo de datos: ingrese un numero entero: ");
        }
    }
}

void tests()
{
    printf("=== Tests Ejercicio 9: Divisible por 7 ===\n");

    // Test 1
    int r1 = divisible_por_7(49);
    printf("Test 1 - divisible_por_7(49)   esperado: 1 (true)  | resultado: %d | %s\n",
           r1, r1 == 1 ? "OK" : "FALLO");

    // Test 2
    int r2 = divisible_por_7(50);
    printf("Test 2 - divisible_por_7(50)   esperado: 0 (false) | resultado: %d | %s\n",
           r2, r2 == 0 ? "OK" : "FALLO");

    // Test 3
    int r3 = divisible_por_7(-77);
    printf("Test 3 - divisible_por_7(-77)  esperado: 1 (true)  | resultado: %d | %s\n",
           r3, r3 == 1 ? "OK" : "FALLO");

    printf("\n");
}

int main()
{
    tests();

    int n = validacion_entero();

    bool resultado = divisible_por_7(n);
    if (resultado == true)
    {
        printf("%i es divisible por 7\n", n);
    }
    else
    {
        printf("%i no es divisible por 7\n", n);
    }

    return 0;
}