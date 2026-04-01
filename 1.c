/*Construir una función recursiva que retorne verdadero si una cadena de caracteres
pasada como parámetro es un palíndromo. Ej. “neuquen” ya que se lee igual de atrás
hacia adelante.
Ejemplos:
palindromo(“neuquen”) => verdadero
palindromo(“palindromo”) => falso
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 50

int palindromo(char palabra[], int i, int j)
{
    int resultado;
    if (palabra[i] != palabra[j])
    {
        resultado = 0;
    }
    else if (i >= j)
    {
        resultado = 1;
    }
    else
    {
        resultado = palindromo(palabra, (i + 1), (j - 1));
    }
    return resultado;
}

int main()
{
    char palabra[MAX];
    int resultado;
    int i, j;

    printf("Ingrese una palabra: ");
    fgets(palabra, MAX, stdin);
    palabra[strcspn(palabra, "\n")] = '\0';
    i = 0;
    j = strlen(palabra) - 1;

    resultado = palindromo(palabra, i, j);
    if (resultado == 1)
    {
        printf("%s es palindromo\n", palabra);
    }
    else
    {
        printf("%s no es palindromo\n", palabra);
    }

    return 0;
}