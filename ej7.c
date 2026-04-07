#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reunionMafia(int nivel)
{
    if (nivel <= 1)
    {
        char *base = (char *)malloc(6 * sizeof(char));
        strcpy(base, "(-.-)");
        return base;
    }
    else
    {
        char *subNivel = reunionMafia(nivel - 1);

        int tamano = strlen(subNivel) + 7;
        char *nuevoNivel = (char *)malloc(tamano * sizeof(char));

        sprintf(nuevoNivel, "(-.%s.-)", subNivel);

        free(subNivel);

        return nuevoNivel;
    }
}

int validacion_entero(int *n, int scan, char c)
{
    while (scan != 2 || c != '\n' || *n < 1)
    {
        if (scan != 2 || c != '\n')
        {
            while (getchar() != '\n')
                ;
        }
        printf("Error de tipo de datos: ingrese un numero entero mayor a 0: ");
        scan = scanf("%d%c", n, &c);
    }
    return *n;
}

void tests()
{
    printf("=== Tests Ejercicio 6: Mafia China ===\n");

    // Test 1
    char *r1 = reunionMafia(1);
    printf("Test 1 - nivel 1 esperado: (-.-) | resultado: %s\n", r1);
    free(r1);

    // Test 2
    char *r2 = reunionMafia(2);
    printf("Test 2 - nivel 2 esperado: (-.(-.-).-) | resultado: %s\n", r2);
    free(r2);

    // Test 3
    char *r3 = reunionMafia(3);
    printf("Test 3 - nivel 3 esperado: (-.(-.(-.-).-).-) | resultado: %s\n", r3);
    free(r3);
    printf("\n");
}

int main()
{
    tests();

    char c;
    int n;
    printf("Ingrese el nivel de la reunion: ");
    int scan = scanf("%d%c", &n, &c);
    validacion_entero(&n, scan, c);

    char *resultado = reunionMafia(n);
    printf("Vista frontal de la delegacion: %s\n", resultado);

    free(resultado);

    return 0;
}