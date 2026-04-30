#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <stdbool.h>

//validacion para la seleccion de los swtich 
char validacionDeLetra(char mensaje[], char opcionStr[], int tamOpcion, char inicio, char fin);

//validacion general para un numero entero
int validacion_ingreso();

//Herramienta para textos
void leerCadena(const char *mensaje, char *buffer, int limite);

//Herramientas para enteros
int leerEntero(const char *mensaje, bool permitirNegativos);

//validacion para double int
double validacion_ingreso_double();
#endif 