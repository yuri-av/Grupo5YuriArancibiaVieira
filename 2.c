
#include <stdlib.h>
#include <stdio.h>

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

// Tests unitarios
void tests()
{
    printf("=== Tests Ejercicio 2: Producto por suma ===\n");

    // Test 1
    int r1 = producto_por_suma(5, 3);
    printf("Test 1 - producto_por_suma(5, 3)    esperado: 15  | resultado: %d | %s\n",
           r1, r1 == 15 ? "OK" : "FALLO");

    // Test 2
    int r2 = producto_por_suma(4, -3);
    printf("Test 2 - producto_por_suma(4, -3)   esperado: -12 | resultado: %d | %s\n",
           r2, r2 == -12 ? "OK" : "FALLO");

    // Test 3
    int r3 = producto_por_suma(10, 0);
    printf("Test 3 - producto_por_suma(10, 0)   esperado: 0   | resultado: %d | %s\n",
           r3, r3 == 0 ? "OK" : "FALLO");

    printf("\n");
}

int main()
{
    tests();

    int a, b;
    char c;
    printf("Ingrese un numero entero 'a' para ser multiplicado: ");
    while (scanf("%d%c", &a, &c) != 2 || c != '\n')
    {
        while (getchar() != '\n')
            ;
        printf("Error de tipo de datos: ingrese un numero entero: ");
    }
    printf("Ingrese un numero entero 'b' para multiplicar: ");
    while (scanf("%d%c", &b, &c) != 2 || c != '\n')
    {
        while (getchar() != '\n')
            ;
        printf("Error de tipo de datos: ingrese un numero entero: ");
    }
    printf("Iniciando recursion...\n");
    int producto = producto_por_suma(a, b);
    printf("resultado = %i\n", producto);
    return 0;
}