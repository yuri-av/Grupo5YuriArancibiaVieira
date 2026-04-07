
#include <stdio.h>
#include <stdlib.h>

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

int validacion_entero(int *fibo, int scan, char c)
{
    while (scan != 2 || c != '\n' || *fibo < 1)
    {
        if (scan != 2 || c != '\n')
        {
            while (getchar() != '\n')
                ;
        }
        printf("Error de tipo de datos: ingrese un numero entero mayor a 0: ");
        scan = scanf("%d%c", fibo, &c);
    }
    return *fibo;
}

// Tests unitarios
void tests()
{
    printf("=== Tests Ejercicio 3: Fibonacci ===\n");

    // Test 1
    int r1 = fibonacci(1);
    printf("Test 1 - fibonacci(1)  esperado: 1  | resultado: %d | %s\n",
           r1, r1 == 1 ? "OK" : "FALLO");

    // Test 2
    int r2 = fibonacci(5);
    printf("Test 2 - fibonacci(5)  esperado: 5  | resultado: %d | %s\n",
           r2, r2 == 5 ? "OK" : "FALLO");

    // Test 3
    int r3 = fibonacci(10);
    printf("Test 3 - fibonacci(10) esperado: 55 | resultado: %d | %s\n",
           r3, r3 == 55 ? "OK" : "FALLO");

    printf("\n");
}

int main()
{
    tests();

    int fibo;
    char c;
    printf("Ingrese un numero entero: ");
    int scan = scanf("%d%c", &fibo, &c);

    validacion_entero(&fibo, scan, c);

    int resultado = fibonacci(fibo);
    printf("fibonacci(%d) = %i\n", fibo, resultado);
    return 0;
}