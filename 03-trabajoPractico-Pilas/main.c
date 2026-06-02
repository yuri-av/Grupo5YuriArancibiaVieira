#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "tp_pilas.h"
#include "../libs/validaciones/headers/validaciones.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#define MAX 150

//Dada una pila Auxiliar y una pila a armar , se arma la segunda pila siendo la inversa de la auxiliar
Pila ReApilar(Pila PilaAuxuliar,Pila Armar);
//Invierte la lista con su propio contenido
Pila Invertir(Pila p);
//cargar pila 
void cargarPila(Pila p);

int main(){
    char opcionStr[10];
    char letra;
    char mensaje[MAX];
    // BUCLE DO-WHILE DEL MENU PRINCIPAL
    do
    {
        printf("\n---EJERCICIO A EJECUTAR---\n");
        printf("A) EJERCICIO 2 | Todos\n");
        printf("B) EJERCICIO 3 | Iguales\n");
        printf("C) EJERCICIO 4 | Cambiar Base\n");
        printf("D) EJERCICIO 5 | Invertir\n");
        printf("E) EJERCICIO 6 | Eliminar Clave\n");
        printf("F) EJERCICIO 7 | Elementos Comunes\n");
        printf("G) EJECICIO  8 | Sacar Repetidos\n");
        printf("H) SALIR\n");

        strcpy(mensaje, "Ingrese la letra del ejercicio que quiera ejecutar: ");
        letra=validacionDeLetra(mensaje,opcionStr,sizeof(opcionStr),'A','H');
        // Si el usuario eligio la letra de salida, avisamos y evitamos entrar al switch
        if (letra == 'H'){
            printf("\nSaliendo del programa...\n");
        }
        else
        {
            switch (letra)
            {
            case 'A':{
                /*EJERCICIO 2*/
                printf("PRIMERO CARGAR PILA LUEGO ELEGIR PUNTO A EJECUTAR!!\n");
                Pila p = p_crear();
                cargarPila(p);
                printf("Pila armada con valores de usuario : ");
                p_mostrar(p);

                char opcionStr[10];
                char letra;
                char mensaje[MAX]; 
                
                do
                {
                    printf("\n---EJERCICIO A EJECUTAR---\n");
                    printf("A) EJERCICIO a | Existe Clave\n");
                    printf("B) EJERCICIO b | Colocar elemento\n");
                    printf("C) EJERCICIO c | Eliminar Clave\n");
                    printf("D) EJERCICIO d | Intercambiar Posiciones\n");
                    printf("E) EJERCICIO e | Duplicar\n");
                    printf("F) EJERCICIO f | Contar Elementos\n");
                    printf("G) SALIR\n");

                    strcpy(mensaje, "Ingrese la letra del punto que quiera ejecutar: ");
                    letra=validacionDeLetra(mensaje,opcionStr,sizeof(opcionStr),'A','G');
                    if (letra == 'G'){
                        printf("\n Volviendo al Menu Principal...\n");
                    }
                    else{
                        switch (letra)
                        {
                        case 'A':{
                            /* PUNTO A*/
                            int clave;
                            bool ret;

                            printf("===EJERCICIO 2 PUNTO A===\n");
                            printf("Pila armada con valores de usuario : ");
                            p_mostrar(p);
                            clave = leerEntero("Ingrese la clave que desea Buscar:",true);
                            
                            ret=p_ej2_existeclave(p,clave);

                            if(ret){
                                printf("La clave %d se encuentra en la pila",clave);
                            }
                            else printf("No estaba en la pila");

                            break;
                        }
                        case 'B':{
                            /* PUNTO B*/
                            printf("===EJERCICIO 2 PUNTO B===\n");
                            int clave, elemento;
                            printf("ingrese el elemento(entero) que quiere colocar:");
                            elemento=validacion_ingreso();
                            TipoElemento tipe=te_crear(elemento);

                            clave=leerEntero("ingrese la posicion donde desea colocar este elemento:",false);
                            p=p_ej2_colocarelemento(p,clave,tipe);

                            printf("Pila actualizada: \n");
                            p_mostrar(p);
                            break;
                        }
                        case 'C':{
                            /* PUNTO C*/
                            printf("===EJERCICIO 2 PUNTO C===\n");
                            int clave;
                            clave=leerEntero("Ingrese la clave que desea eliminar:",false);
                            p=p_ej2_eliminarclave(p,clave);

                            printf("Pila actualizada: \n");
                            p_mostrar(p);

                            break;
                        }
                        case 'D':{
                            /* PUNTO D*/
                            printf("===EJERCICIO 2 PUNTO D===\n");
                            int claveUno, claveDos;

                            claveUno=leerEntero("ingrese la primer clave:",false);
                            claveDos=leerEntero("\ncoloque por cual quiere cambiarla:",false);

                            p=p_ej2_intercambiarposiciones(p,claveUno,claveDos);

                            printf("Pila actualizada: \n");
                            p_mostrar(p);

                            break;
                        }
                        case 'E':{
                            /* PUNTO E*/
                            printf("===EJERCICIO 2 PUNTO E===\n");

                            printf("\nDuplicando pila...\n");
                            Pila copia = p_ej2_duplicar(p);

                            printf("Pila original:\n");
                            p_mostrar(p);

                            printf("Pila copia:\n");
                            p_mostrar(copia);

                            break;
                        }
                        case 'F':{
                            /* PUNTO F*/
                            printf("===EJERCICIO 2 PUNTO F===\n");

                            int cant =p_ej2_cantidadelementos(p);
                            printf("\nCantidad de elementos de la pila: %d\n", cant);
                            break;
                        }
                        default:
                            break;
                        }
                    }

                } while (letra!='G');
                printf("\nPresione Enter para continuar...");
                while(getchar() != '\n');  // limpia el buffer
                getchar();                  // ahora sí espera al usuario
                break;
            }
            case 'B':{
                /*EJERCICIO 3*/
                Pila p1 = p_crear();
                cargarPila(p1);

                Pila p2 = p_crear();
                cargarPila(p2);

                printf("Pila numero uno: ");
                p_mostrar(p1);
                printf("Pila numero dos: ");
                p_mostrar(p2);

                if (p_ej3_iguales(p1, p2)) {
                    printf("\nLas pilas son iguales\n");
                } else {
                    printf("\nLas pilas NO son iguales\n");
                }
                printf("Este ejercicio tiene una complejidad Algoritmica de O(n) donde n representa la cantidad de elementos de la pila");
                
                printf("\nPresione Enter para continuar...");
                while(getchar() != '\n');  // limpia el buffer
                getchar();                  // ahora sí espera al usuario
                break;
            }
            case 'C':{
                /*EJERCICIO 4*/
                int nrobasedecimal, nrootrabase;
                char *res;

                nrobasedecimal=leerEntero("ingrese un numero mayor a 0 para convertirlo:",false);

                nrootrabase=leerEntero("ingrese una base entre 2 y 16",false);
                while (nrootrabase < 2 || nrootrabase > 16){
                    nrootrabase=leerEntero("por favor, ingrese una base entre 2 y 16:",false);               
                }
                res = p_ej4_cambiarbase(nrobasedecimal, nrootrabase);
                printf("Resultado: %s\n", res);
                printf("La cantidad de divisiones que se hacen es proporcional a la cantidad de dígitos del resultado,\n");
                printf("que es log en la base elegida del numero original. por lo que tenemos una complejidad algoritmica de O(log n)");
                
                free(res);
                printf("\nPresione Enter para continuar...");
                while(getchar() != '\n');  // limpia el buffer
                getchar();
                break;
            }
            case 'D':{
                /*EJERCICIO 5*/
                Pila p = p_crear();
                cargarPila(p);
                printf("Pila armada con valores de usuario: ");
                p_mostrar(p);

                Pila invertida = p_ej5_invertir(p);

                printf("\nPila invertida: ");
                p_mostrar(invertida);

                printf("\nPresione Enter para continuar...");
                while(getchar() != '\n');  // limpia el buffer
                getchar();
                break;
            }
            case 'E':{
                /*EJERCICIO 6*/
                Pila p = p_crear();
                Pila it = p_crear();
                Pila rec = p_crear();
                cargarPila(p);
                printf("Pila armada con valores de usuario : ");
                p_mostrar(p);

                int clave;
                clave=leerEntero("ingrese la clave que desea ELIMINAR\n",false);

                printf("El metodo iterativo tiene complejidad O(n)\n");
                it=p_ej6_eliminarclave(p,clave);
                printf("Pila actualizada:");
                p_mostrar(it);

                printf("El metodo Recursivo tambien tiene Complejidad O(n)\n");
                rec=p_ej6_eliminarclaveRecu(p,clave);
                printf("Pila actualizada:");
                p_mostrar(rec);

                printf("\nPresione Enter para continuar...");
                while(getchar() != '\n');  // limpia el buffer
                getchar();
                break;
            }
            case 'F':{
                /*EJERCICIO 7*/
                Pila p1 = p_crear();
                cargarPila(p1);
                Pila p2 = p_crear();
                cargarPila(p2);
                Pila rec=p_crear();

                printf("Pila uno: ");
                p_mostrar(p1);
                printf("\nPila dos: ");
                p_mostrar(p2);

                rec=p_ej7_elementoscomunes(p1,p2);
                if(p_es_vacia(rec)){
                    printf("no hubo concidencias.");
                }
                else{
                    printf("las coincidencias fueron:");
                    p_mostrar(rec);
                    printf("\nComplejidad: O(n^2), Recorre con un bucle O(n) y dentro de este p_buscar Ejecuta otro: O(n) * O(n) = O(n^2)");
                }

                printf("\nPresione Enter para continuar...");
                while(getchar() != '\n');  // limpia el buffer
                getchar();
                break;
            }
            case 'G':{
                /*EJERCICIO 8*/
                Pila p = p_crear();
                Pila rec=p_crear();
                cargarPila(p);
                printf("Pila armada con valores de usuario : ");
                p_mostrar(p);

                rec=p_ej8_sacarrepetidos(p);
                printf("\nPila sin valores repetidos: ");
                p_mostrar(rec);

                printf("\nPresione Enter para continuar...");
                while(getchar() != '\n');  // limpia el buffer
                getchar();
                break;
            }
            default:
                break;
            }
        }
    } while (letra != 'H'); // CONDICION DE SALIDA: Se repite MIENTRAS la letra NO sea igual a la letra final.

    return 0;
}

void cargarPila(Pila p){
    int tamanio;

    tamanio=leerEntero("Ingrese el tamanio de la Pila (expresado en enteros):",false);
    while (tamanio>10)
    {
        printf("Atencion, esta definido en pilas.h que el maximo de tamanio es 10. respete este rango.\n");
        tamanio=leerEntero("Ingrese el tamanio de la Pila (expresado en enteros):",false);
    }
    
    for(int i = 0;i<tamanio;i++){
        int Clave = 0;
        Clave=leerEntero("ingrese la clave a apilar para la pila: ",false);

        TipoElemento x = te_crear(Clave);
        p_apilar(p,x);
    }
}