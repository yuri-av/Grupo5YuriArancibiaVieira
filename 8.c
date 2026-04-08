#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 100

void buscarSubconjuntos(int conjunto[], int tamano, int objetivo, int indiceActual, int subconjuntoActual[], int tamanoSubconjunto, char **output)
{
    // Caso base 1: Se encontró un subconjunto válido
    if (objetivo == 0)
    {
        char bufferTemporal[256];
        int desplazados = 0;

        desplazados += sprintf(bufferTemporal + desplazados, "{");

        for (int i = 0; i < tamanoSubconjunto; i++)
        {
            desplazados += sprintf(bufferTemporal + desplazados, "%i, ", subconjuntoActual[i]);
        }

        // --- TRUCO ESTÉTICO ---
        // Si hay números en el subconjunto, retrocedemos el lápiz 2 espacios
        // para sobreescribir la última coma y el espacio.
        if (tamanoSubconjunto > 0)
        {
            desplazados -= 2;
        }

        desplazados += sprintf(bufferTemporal + desplazados, "}\n");
        strcat(*output, bufferTemporal);
        return;
    }

    // Caso base 2: Se terminaron los números o el objetivo es negativo
    if (indiceActual == tamano || objetivo < 0)
    {
        return;
    }

    // Camino A: INCLUIR
    subconjuntoActual[tamanoSubconjunto] = conjunto[indiceActual];
    buscarSubconjuntos(conjunto, tamano, objetivo - conjunto[indiceActual], indiceActual + 1, subconjuntoActual, tamanoSubconjunto + 1, output);

    // Camino B: EXCLUIR
    buscarSubconjuntos(conjunto, tamano, objetivo, indiceActual + 1, subconjuntoActual, tamanoSubconjunto, output);
}
void subconjuntosQueSumanN(int conjunto[], int tamano, int objetivo, char **output)
{
    int subconjuntoActual[MAX];

    *output = malloc(1024 * sizeof(char)); // Reservamos la memoria
    (*output)[0] = '\0';                   // La inicializamos limpia

    buscarSubconjuntos(conjunto, tamano, objetivo, 0, subconjuntoActual, 0, output);
}
int leer_entero(const char *mensaje)
{
    char buffer[50];
    int valor;
    char extra;
    bool valido = false;

    while (valido != true)
    {
        printf("%s", mensaje);

        // 1. Intentar leer la entrada
        if (fgets(buffer, sizeof(buffer), stdin) == NULL || buffer[0] == '\n')
        {
            printf("  Error: no puede ser nulo. Intente de nuevo.\n");
        }
        // 2. Validar si hay caracteres extra después del número
        else if (sscanf(buffer, "%d %c", &valor, &extra) != 1)
        {
            printf("  Error: solo se permiten numeros enteros. Intente de nuevo.\n");
        }
        // 3. Si no entró en los errores anteriores, la entrada es válida
        else
        {
            printf("Valor valido!\n");
            valido = true;
        }
    }
    return valor;
}

int main()
{
    printf("=== Subconjuntos que suman N ===\n\n");
    char *output;
    int conjunto[MAX] = {};
    int tamano = 0;
    int objetivo = 0;

    while (tamano <= 0)
    {
        tamano = leer_entero("Definir los elementos del conjunto: ");
        if (tamano <= 0)
            printf("  Error: debe ser mayor a 0.\n");
    }

    while (objetivo <= 0)
    {
        objetivo = leer_entero("Definir el objetivo: ");
        if (objetivo <= 0)
            printf("  Error: debe ser mayor a 0.\n");
    }

    printf("==== VALORES DE LA LISTA ====\n");
    for (int i = 0; i < tamano; i++)
    {
        bool valido = false;
        printf("Numero %i\n", i + 1);
        while (valido != true)
        {
            conjunto[i] = leer_entero("Ingresar: ");
            valido = true;
        }
    }

    subconjuntosQueSumanN(conjunto, tamano, objetivo, &output);
    printf("Resultado: %s", output);
    free(output);

    return 0;
}