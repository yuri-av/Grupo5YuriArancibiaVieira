/*Generar un algoritmo recursivo que le ponga los “.” de los miles a un String de
números.
Ejemplos:
agregarSeparadorMiles (“123456”) => “123.456”
agregarSeparadorMiles (“12345678”) => “12.345.678”*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

void agregarSeparadorMiles(char string[])
{
    if (*string == '\0')
    {
        return;
    }

    printf("%c", string[0]);
    int restante = strlen(string + 1);
    if (restante > 0 && (restante % 3 == 0))
    {
        printf(".");
    }
    agregarSeparadorMiles(string + 1);
}

int main()
{
    char string[MAX];
    printf("Ingrese un numero: ");
    fgets(string, MAX, stdin);
    string[strcspn(string, "\n")] = '\0';

    if (string[0] == '-')
    {
        printf("-");
    }
    agregarSeparadorMiles(string + 1);

    return 0;
}