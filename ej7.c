#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*Ejercicio 7:Se conoce que la mafia china es muy organizada y protege mucho a sus miembros, cuando deciden asistir a una reunión se dispone de una cantidad de chinos que 
asisten, y ellos se ubican de forma que al mirarlos frontalmente generan cierto respeto y temor. A continuación, se tiene una serie de posibles reuniones y su nivel y la
apariencia que se tiene del grupo que va a la reunión vistos frontalmente:
 Nivel reunión  Vista frontal de la delegación
 1                      (-.-)
 2                   (-.(-.-).-)
 3                (-.(-.(-.-).-).-)
 4             (-.(-.(-.(-.-).-).-).-)
Considerando esta descripción, diseñar los procesos recursivos que permitan mostrar la apariencia del grupo de chinos que asisten a una reunión de nivel “n”.  */

char* reunionMafia(int nivel) {

    if (nivel == 1) {
        char* base = malloc(6);
        strcpy(base, "(-.-)");
        return base;
    }

    char* anterior = reunionMafia(nivel - 1);

    int nuevoTam = strlen(anterior) + 6; //+6 son los caracteres q agregamos en la izquierda y derecha en cada llamada

    char *resultado = malloc(nuevoTam);

    strcpy(resultado, "(-.");
    strcat(resultado, anterior); // agregamos lo del nivel anterior
    strcat(resultado, ".-)");

    free(anterior);

    return resultado;
}

int main() {
    char *resultado;
    int nivel;

    printf("Ingrese el nivel de la reunion: ");
    while (scanf("%d", &nivel) != 1 || nivel < 1) {
        printf("Error, ingrese un numero entero mayor a 0: ");
        while (getchar() != '\n');
    }

    resultado = reunionMafia(nivel);

    if (resultado != NULL) { 
    printf("Vista frontal de la delegacion: %s", resultado);
    free(resultado);
    }

    return 0;
}