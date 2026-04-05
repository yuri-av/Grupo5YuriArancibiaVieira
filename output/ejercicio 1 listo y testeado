#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool palindromo(char palabra[], int inicio, int fin) {
    if (inicio >= fin) {
        return true;
    }
    if (!isalpha(palabra[inicio])) {
        return palindromo(palabra, inicio + 1, fin);
    }
    if (!isalpha(palabra[fin])) {
        return palindromo(palabra, inicio, fin - 1);
    }
    if (tolower(palabra[inicio]) != tolower(palabra[fin])) {
        return false;
    }
    return palindromo(palabra, inicio + 1, fin - 1);
}

int main() {
    char palabra[100];
    printf("Ingrese una palabra o frase: ");
    fgets(palabra, 100, stdin);
    
    palabra[strcspn(palabra, "\n")] = 0;

    int inicio = 0;
    int fin = strlen(palabra) - 1;

    if (palindromo(palabra, inicio, fin))
        printf("Es un palindromo\n");
    else
        printf("No es un palindromo\n");

    return 0;
}
