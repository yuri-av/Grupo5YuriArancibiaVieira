#include "tp_2_listas.h"
#include "validaciones.h"
#include "tipo_elemento.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h> 
#include <time.h>     
#define MAX 150

// linea para ejecutar todo:
/*
gcc -I libgcc -I libs/listas/headers -I libs/tipoElemento/headers -I libs/validaciones/headers -I 02-trabajoPractico-Listas 02-trabajoPractico-Listas/main.c 02-trabajoPractico-Listas/tp_2_listas.c libs/listas/implementaciones/listas_arreglos.c libs/tipoElemento/implementaciones/tipo_elemento.c libs/validaciones/implementaciones/validacigcc -I libs/listas/headers -I libs/tipoElemento/headers -I libs/validaciones/headers -I 02-trabajoPractico-Listas 02-trabajoPractico-Listas/main.c 02-trabajoPractico-Listas/tp_2_listas.c libs/listas/implementaciones/listas_arreglos.c libs/tipoElemento/implementaciones/tipo_elemento.c libs/validaciones/implementaciones/validaciones.c -o tp2 -lmones.c -o tp2 -lms/listas/headers -I libs/tipoElemento/headers -I libs/validaciones/headers -I 02-tp-listas/header 02-tp-listas/implementacion_main/main.c 02-tp-listas/implementacion_main/tp_2_listas.c libs/listas/implementaciones/listas_arreglos.c libs/tipoElemento/implementaciones/tipo_elemento.c libs/validaciones/implementaciones/validaciones.c -o tp2 -lm
./tp2
*/


Lista rellenarLista(int cantidad);
int main(){
    char opcionStr[10];
    char letra;
    char mensaje[MAX];
    // BUCLE DO-WHILE DEL MENU PRINCIPAL
    do
    {
        printf("\n---EJERCICIO A EJECUTAR---\n");
        printf("A) EJERCICIO 2 |\n");
        printf("B) EJERCICIO 3 | Multiplo\n");
        printf("C) EJERCICIO 4 | Comparar Listas\n");
        printf("D) EJERCICIO 5 | Polinomio\n");
        printf("E) EJERCICIO 6 | Es SubLista\n");
        printf("F) SALIR\n");

        strcpy(mensaje, "Ingrese la letra del ejercicio que quiera ejecutar: ");
        letra=validacionDeLetra(mensaje,opcionStr,sizeof(opcionStr),'A','F');
        // Si el usuario eligio 'F', avisamos y evitamos entrar al switch
        if (letra == 'F')
        {
            printf("\nSaliendo del programa...\n");
        }
        else
        {
            // Ejecutamos el ejercicio correspondiente
            switch (letra)
            {
            case 'A':
                {printf("======EJERCICIO DOS======\n");
                srand(time(NULL));
                int cant, dad;
                // Creamos las dos listas
                Lista l1, l2;
                int R;
                // Tamaño de las listas
                printf("Ingrese la cantidad de elementos a agregar a la lista 1: ");
                cant = validacion_ingreso();
                
                printf("Ingrese la cantidad de elementos a agregar a la lista 2: ");
                dad = validacion_ingreso();

                // Llenamos las listas
                printf("\n--- Carga de la Lista 1 ---\n");
                l1 = rellenarLista(cant);
                printf("\n--- Carga de la Lista 2 ---\n");
                l2 = rellenarLista(dad);

                // Elementos que no se repiten (Asumimos de L1 respecto a L2 para este ejemplo)
                Lista l_no_repetidos_l1 = verElementosQueNoSeRepiten(l1, l2);
                printf("\nElementos en L1 que no se repiten en L2: ");
                l_mostrar(l_no_repetidos_l1);
                
                // Elementos que no se repiten (Asumimos de L1 respecto a L2 para este ejemplo)
                Lista l_no_repetidos_l2 = verElementosQueNoSeRepiten(l2, l1);
                printf("\nElementos en L2 que no se repiten en L1: ");
                l_mostrar(l_no_repetidos_l2);

                // Elementos repetidos
                Lista l_repetidos = verElementosRepetidos(l1, l2);
                printf("\nElementos que se repiten en ambas listas: ");
                l_mostrar(l_repetidos);

                //Promedios
                float resultado = promedio(l1);
                printf("El promedio de l1 es: %.2f\n", resultado);
                float result = promedio(l2);
                printf("El promedio de l2 es: %.2f\n",result);

                // Uso del struct ResultadoValorMaximo
                ResultadoValorMinimo min = valorMinimo(l1, l2);
                printf("\n--- Datos del minimo de L1 ---\n");
                printf("El valor min es: %d\n", min.valor);
                printf("Se encuentra en la posicion: %d\n", min.pos);
                // ,,,,
                printf("\n--- Datos del minimo de L2 ---\n");
                printf("El valor min es: %d\n", min.valor_2);
                printf("Se encuentra en la posicion: %d\n", min.pos_2);

                break;}
            case 'B':
               { printf("======EJERCICIO TRES======\n"); 
                srand(time(NULL));
                int cant, dad;
                // Creamos las dos listas
                Lista l1, l2;
                int R;
                // Tamaño de las listas
                printf("Ingrese la cantidad de elementos a agregar a la lista 1: ");
                cant = validacion_ingreso();
                
                printf("Ingrese la cantidad de elementos a agregar a la lista 2: ");
                dad = validacion_ingreso();

                // Llenamos las listas
                printf("\n--- Carga de la Lista 1 ---\n");
                l1 = rellenarLista(cant);
                printf("\n--- Carga de la Lista 2 ---\n");
                l2 = rellenarLista(dad); 
                ResultadosMul resM=multiplo(l1,l2);

                if(resM.esMultiplo!=true){
                    printf("la lista L2 no es multiplo de L1");
                }
                else{
                    if(resM.escalar!=true){
                        printf("Las listas si son multiplos pero L2 no es escalar de L1");
                    }
                    else{
                        printf("Las listas son escalar y su número escalar es %d",resM.numEscalar);
                    }
                }
                break;}
            case 'C':
               { printf("======EJERCICIO CUATRO======\n");
                srand(time(NULL));
                int cant, dad;
                // Creamos las dos listas
                Lista l1, l2;
                int R;
                // Tamaño de las listas
                printf("Ingrese la cantidad de elementos a agregar a la lista 1: ");
                cant = validacion_ingreso();
                
                printf("Ingrese la cantidad de elementos a agregar a la lista 2: ");
                dad = validacion_ingreso();

                // Llenamos las listas
                printf("\n--- Carga de la Lista 1 ---\n");
                l1 = rellenarLista(cant);
                printf("\n--- Carga de la Lista 2 ---\n");
                l2 = rellenarLista(dad);

                R=CompararListas(l1,l2);

                if(R==1){
                    printf("La lista 1 es mayor a Lista 2");
                }else if(R==2){
                    printf("La lista 2 es mayor a la Lista 1");
                }else if(R==0){
                    printf("Las Listas son de igual valor");
                }
                break;}
            case 'D':
            {
                printf("======EJERCICIO CINCO======\n");

                Lista polinomio = l_crear();

                printf("=== CARGA DEL POLINOMIO ===\n");
                printf("Ejemplo: 3x^2 + 2x + 1\n");
                printf("Los coeficientes se cargaran en orden ascendente (x^0, x^1, x^2...)\n\n");

                /* VALIDAR CANTIDAD DE TERMINOS */
                printf("Ingrese cantidad de terminos del polinomio (mayor a 0): ");
                int cantidad;
                do
                {
                    cantidad = validacion_ingreso();
                    if (cantidad <= 0)
                    {
                        printf("Error: debe ingresar un numero entero mayor a 0: ");
                    }
                } while (cantidad <= 0);

                /* CARGA DEL POLINOMIO */
                for (int i = 0; i < cantidad; i++)
                {
                    printf("\n--- Termino %d ---", i + 1);
                    hacerPolinomio(polinomio);
                }

                printf("\nPolinomio cargado:\n");
                l_mostrar(polinomio);

                /* EVALUAR POLINOMIO */
                printf("\n=== EVALUAR POLINOMIO ===\n");
                printf("Ingrese valor de x: ");
                float x = (float)validacion_ingreso_double();

                float resultado = evaluarPoliomio(polinomio, x);
                printf("Resultado de F(%.2f) = %.2f\n", x, resultado);

                /* CALCULAR RANGO */
                printf("\n=== CALCULAR RANGO ===\n");

                printf("Ingrese valor inicial de x: ");
                double desde = validacion_ingreso_double();

                printf("Ingrese valor final de x (mayor o igual al inicial): ");
                double hasta;
                do
                {
                    hasta = validacion_ingreso_double();
                    if (hasta < desde)
                    {
                        printf("Error: debe ingresar un numero valido y mayor o igual a %.2lf: ", desde);
                    }
                } while (hasta < desde);

                printf("Ingrese intervalo de salto (mayor a 0): ");
                double intervalo;
                do
                {
                    intervalo = validacion_ingreso_double();
                    if (intervalo <= 0)
                    {
                        printf("Error: debe ingresar un numero mayor a 0: ");
                    }
                } while (intervalo <= 0);

                Lista rango = calcularRango(polinomio, desde, hasta, intervalo);

                printf("\nValores del polinomio en el rango:\n");
                l_mostrar(rango);
                break;
            }
            
            case 'E':
                {printf("======EJERCICIO SEIS======\n");
                srand(time(NULL));
                int cant, dad;
                // Creamos las dos listas
                Lista l1, l2;
                int R;
                // Tamaño de las listas
                printf("Ingrese la cantidad de elementos a agregar a la lista 1: ");
                cant = validacion_ingreso();
                
                printf("Ingrese la cantidad de elementos a agregar a la lista 2: ");
                dad = validacion_ingreso();

                // Llenamos las listas
                printf("\n--- Carga de la Lista 1 ---\n");
                l1 = rellenarLista(cant);
                printf("\n--- Carga de la Lista 2 ---\n");
                l2 = rellenarLista(dad);


                if(esSublista(l2, l1)){
                    printf("L2 es sublista de L1");
                }
                else{
                    printf("L2 no es sublista de L1");
                }
                break;}
            default:
                break;
            }
        
        }
    } while (letra != 'F'); // CONDICION DE SALIDA: Se repite MIENTRAS la letra NO sea F.

    return 0;
}
