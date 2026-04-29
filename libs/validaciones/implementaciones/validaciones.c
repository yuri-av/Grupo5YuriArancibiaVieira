#include "libs/validaciones/headers/validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

char validacionDeLetra(int cant){


}

int validacion_ingreso(){
    int numero;
    char car;

    while (scanf("%d%c", &numero, &car) != 2 || car != '\n')
    {
        // Mensaje genérico para cualquier número entero
        printf("Opcion invalida. Ingrese un numero entero: ");

        // Limpieza del buffer de entrada
        if (car != '\n')
        {
            while (getchar() != '\n')
                ;
        }
    }

    // Retornamos el valor ya validado
    return numero;
}