/*Escribir una función recursiva que implemente el método que se describe para saber si
un número es divisible por 7. Se separa la primera cifra de la derecha, se la multiplica
por 2, y se resta este producto de lo que queda a la izquierda y así sucesivamente,
hasta que el resultado obtenido sea un número menor a 70. El número original será
múltiplo de 7 si el resultado da cero o múltiplo de 7. */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool divisiblePor7(int n)
{
    if (n < 70)
    {
        return (n % 7 == 0);
    }
    else
    {
        int ult = n % 10;

        int resto = n / 10;

        int nuevo = resto - 2 * ult;

        return divisiblePor7(nuevo);
    }
}

int validacion_entero()
{
    int n;
    char c;

    printf("Ingrese un valor: ");
    int scan = scanf("%d%c", &n, &c);

    while (scan != 2 || c != '\n')
    {
        // limpiar buffer
        while (getchar() != '\n');

        printf("Error de tipo de datos: ingrese un numero entero: ");
        scan = scanf("%d%c", &n, &c);
    }

    return n;
}

int main()
{

    int n = validacion_entero();

    bool resultado = divisiblePor7(abs(n));
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
