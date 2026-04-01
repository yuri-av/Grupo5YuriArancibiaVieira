/*Dados dos números enteros m y n, construir una función recursiva que devuelva el
producto de ambos, calculando el mismo como sumas sucesivas. Esto es:
m*n=m+m+...+m, n veces.
Ejemplos:
producto(5, 3) => 15
producto (10, 4) => 40*/
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
        // Caso normal: sumas 'a' y reducis 'b' hacia el cero
        resultado = a + producto_por_suma(a, b - 1);
    }
    else
    {
        // Caso negativo: sumas '-a' y llevas 'b' hacia el cero (sumándole 1)
        resultado = -a + producto_por_suma(a, b + 1);
    }
    return resultado;
}

int main()
{
    int a, b;
    char c;
    printf("Ingrese un numero entero 'a' para ser multiplicado: ");
    while(scanf("%d%c", &a,&c)!= 2 || c != '\n'){
        while (getchar() != '\n');
        printf("Error de tipo de datos: ingrese un numero entero: ");
    }
    printf("Ingrese un numero entero 'b' para multiplicar: ");
    while(scanf("%d%c", &b,&c)!= 2 || c != '\n'){
        while (getchar() != '\n');
        printf("Error de tipo de datos: ingrese un numero entero: ");
    }
    printf("Iniciando recursion...\n");
    int producto = producto_por_suma(a, b);
    printf("resultado = %i\n", producto);
    return 0;
}
