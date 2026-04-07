
#include <stdio.h>

#define MAX_ELEMENTOS 100

void subconjuntos_que_suman_N(int lista_num[], int objetivo)
{
    static int actual[MAX_ELEMENTOS];
    static int tam_actual = 0;

    if (objetivo == 0)
    {
        printf("{");
        for (int i = 0; i < tam_actual; i++)
        {
            printf("%d", actual[i]);
            if (i < tam_actual - 1)
                printf(", ");
        }
        printf("}\n");
        return;
    }

    if (lista_num[0] == -999)
        return;

    subconjuntos_que_suman_N(lista_num + 1, objetivo);

    actual[tam_actual] = lista_num[0];
    tam_actual++;
    subconjuntos_que_suman_N(lista_num + 1, objetivo - lista_num[0]);
    tam_actual--;
}

int leer_entero(const char *mensaje)
{
    char buffer[50];
    int valor;
    char extra;

    while (1)
    {
        printf("%s", mensaje);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL || buffer[0] == '\n')
        {
            printf("  Error: no puede ser nulo. Intente de nuevo.\n");
            continue;
        }
        if (sscanf(buffer, "%d%c", &valor, &extra) == 2 && extra != '\n')
        {
            printf("  Error: solo se permiten numeros enteros. Intente de nuevo.\n");
            continue;
        }
        if (sscanf(buffer, "%d", &valor) != 1)
        {
            printf("  Error: solo se permiten numeros enteros. Intente de nuevo.\n");
            continue;
        }

        return valor;
    }
}

void tests()
{
    printf("=== Tests Ejercicio 8: Subconjuntos que suman N ===\n");

    // Test 1
    int c1[] = {10, 3, 1, 7, 4, 2, -999};
    printf("Test 1 - {10,3,1,7,4,2} que suman 7\n");
    printf("  esperado: {7} {1,4,2} {3,4}\n");
    printf("  resultado:\n  ");
    subconjuntos_que_suman_N(c1, 7);

    // Test 2
    int c2[] = {10, 3, 1, 7, 4, 2, -999};
    printf("Test 2 - {10,3,1,7,4,2} que suman 10\n");
    printf("  esperado: {10} {1,7,2} {3,7} {3,1,4,2}\n");
    printf("  resultado:\n  ");
    subconjuntos_que_suman_N(c2, 10);

    // Test 3
    int c3[] = {1, 2, 3, -999};
    printf("Test 3 - {1,2,3} que suman 99 (sin solucion)\n");
    printf("  esperado: (ninguno)\n");
    printf("  resultado: ");
    subconjuntos_que_suman_N(c3, 99);
    printf("(ninguno)\n");

    printf("\n");
}

int main()
{
    tests();

    int lista_num[MAX_ELEMENTOS + 1];
    int tamanio, objetivo;

    printf("=== Subconjuntos que suman N ===\n\n");

    while (1)
    {
        tamanio = leer_entero("Cuantos elementos tiene el conjunto? ");
        if (tamanio <= 0)
            printf("  Error: debe ser mayor a 0.\n");
        else
            break;
    }

    printf("Ingrese los %d elementos (pueden ser negativos):\n", tamanio);
    for (int i = 0; i < tamanio; i++)
    {
        char mensaje[30];
        sprintf(mensaje, "  Elemento [%d]: ", i + 1);
        lista_num[i] = leer_entero(mensaje);
    }
    lista_num[tamanio] = -999;

    objetivo = leer_entero("Ingrese el numero objetivo (N): ");

    printf("\nSubconjuntos que suman %d:\n", objetivo);
    subconjuntos_que_suman_N(lista_num, objetivo);

    return 0;
}