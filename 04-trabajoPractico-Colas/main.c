#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "tp_4_colas.h"
#include "../libs/colas/headers/colas.h"
#include "../libs/pilas/headers/pilas.h"
#include "../libs/listas/headers/listas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/validaciones/headers/validaciones.h"
#define MAX 150

//cargar cola 
void cargarCola(Cola c);

int main(){
    char opcionStr[10];
    char letra;
    char mensaje[MAX];
    // BUCLE DO-WHILE DEL MENU PRINCIPAL
    do
    {
        printf("\n---EJERCICIO A EJECUTAR---\n");
        printf("A) EJERCICIO 2 | Operaciones Basicas\n");
        printf("B) EJERCICIO 3 | Iguales\n");
        printf("C) EJERCICIO 4 | No Repetidos\n");
        printf("D) EJERCICIO 5 | Divisor Total\n");
        printf("E) EJERCICIO 6 | Comunes a Pila y Cola\n");
        printf("F) EJERCICIO 7 | Atender Clientes\n");
        printf("G) EJERCICIO 8 | Sacar Repetidos\n");
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
                printf("PRIMERO CARGAR COLA LUEGO ELEGIR PUNTO A EJECUTAR!!\n");
                Cola c = c_crear();
                cargarCola(c);
                printf("Cola armada con valores de usuario : ");
                c_mostrar(c);

                char opcionStr[10];
                char letra;
                char mensaje[MAX]; 
                
                do
                {
                    printf("\n---EJERCICIO A EJECUTAR---\n");
                    printf("A) EJERCICIO a | Existe Clave\n");
                    printf("B) EJERCICIO b | Colarse en Posicion\n");
                    printf("C) EJERCICIO c | Sacar Elemento\n");
                    printf("D) EJERCICIO d | Contar Elementos\n");
                    printf("E) EJERCICIO e | Copiar Cola\n");
                    printf("F) EJERCICIO f | Invertir Cola\n");
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
                            printf("Cola armada con valores de usuario : ");
                            c_mostrar(c);
                            clave = leerEntero("Ingrese la clave que desea Buscar:",true);
                            
                            ret=c_ej2_existeclave(c,clave);

                            if(ret){
                                printf("La clave %d se encuentra en la cola",clave);
                            }
                            else printf("No estaba en la cola");

                            break;
                        }
                        case 'B':{
                            /* PUNTO B*/
                            printf("===EJERCICIO 2 PUNTO B===\n");
                            int posicion;

                            printf("Ingrese la posicion ordinal donde desea colarse (1 es el frente): ");
                            posicion=leerEntero("",false);
                            c=c_ej2_colarelemento(c,posicion);

                            printf("Cola actualizada: \n");
                            c_mostrar(c);
                            break;
                        }
                        case 'C':{
                            /* PUNTO C*/
                            printf("===EJERCICIO 2 PUNTO C===\n");
                            int clave2;
                            clave2=leerEntero("Ingrese la clave que desea sacar:",false);
                            c=c_ej2_sacarelemento(c,clave2);

                            printf("Cola actualizada: \n");
                            c_mostrar(c);

                            break;
                        }
                        case 'D':{
                            /* PUNTO D*/
                            printf("===EJERCICIO 2 PUNTO D===\n");

                            int cant =c_ej2_contarelementos(c);
                            printf("\nCantidad de elementos de la cola: %d\n", cant);
                            break;
                        }
                        case 'E':{
                            /* PUNTO E*/
                            printf("===EJERCICIO 2 PUNTO E===\n");

                            printf("\nCopiando cola...\n");
                            Cola copia = c_ej2_copiar(c);

                            printf("Cola original:\n");
                            c_mostrar(c);

                            printf("Cola copia:\n");
                            c_mostrar(copia);

                            break;
                        }
                        case 'F':{
                            /*EJERCICIO 7*/
                            Cola c1 = c_crear();
                            Cola c2 = c_crear();
                            Cola c3 = c_crear();

                            int cant;
                            int tiempo;
                            int Q;
                            int *nro;

                            printf("====================================\n");
                            printf("SIMULADOR DE ATENCION DE CLIENTES\n");
                            printf("====================================\n\n");

                            // ---- Q ----
                            do {
                                Q = leerEntero("Ingrese tiempo de atencion Q (>0): ", false);
                                if (Q <= 0) printf("ERROR. Debe ser mayor que cero.\n");
                            } while (Q <= 0);

                            // ---- COLA 1 ----
                            do {
                                cant = leerEntero("\nCantidad de clientes Cola 1 (0-10): ", false);
                                if (cant > 10) printf("ERROR. Cantidad invalida.\n");
                            } while (cant > 10);

                            for (int i = 1; i <= cant; i++) {
                                char msg[50];
                                do {
                                    sprintf(msg, "Tiempo de atencion Cliente %d Cola 1: ", i);
                                    tiempo = leerEntero(msg, false);
                                    if (tiempo <= 0) printf("ERROR. Debe ser mayor que cero.\n");
                                } while (tiempo <= 0);

                                nro = malloc(sizeof(int));
                                *nro = i;
                                c_encolar(c1, te_crear_con_valor(tiempo, nro));
                            }

                            // ---- COLA 2 ----
                            do {
                                cant = leerEntero("\nCantidad de clientes Cola 2 (0-10): ", false);
                                if (cant > 10) printf("ERROR. Cantidad invalida.\n");
                            } while (cant > 10);

                            for (int i = 1; i <= cant; i++) {
                                char msg[50];
                                do {
                                    sprintf(msg, "Tiempo de atencion Cliente %d Cola 2: ", i);
                                    tiempo = leerEntero(msg, false);
                                    if (tiempo <= 0) printf("ERROR. Debe ser mayor que cero.\n");
                                } while (tiempo <= 0);

                                nro = malloc(sizeof(int));
                                *nro = i;
                                c_encolar(c2, te_crear_con_valor(tiempo, nro));
                            }

                            // ---- COLA 3 ----
                            do {
                                cant = leerEntero("\nCantidad de clientes Cola 3 (0-10): ", false);
                                if (cant > 10) printf("ERROR. Cantidad invalida.\n");
                            } while (cant > 10);

                            for (int i = 1; i <= cant; i++) {
                                char msg[50];
                                do {
                                    sprintf(msg, "Tiempo de atencion Cliente %d Cola 3: ", i);
                                    tiempo = leerEntero(msg, false);
                                    if (tiempo <= 0) printf("ERROR. Debe ser mayor que cero.\n");
                                } while (tiempo <= 0);

                                nro = malloc(sizeof(int));
                                *nro = i;
                                c_encolar(c3, te_crear_con_valor(tiempo, nro));
                            }

                            // ---- VALIDACION ----
                            if (c_es_vacia(c1) && c_es_vacia(c2) && c_es_vacia(c3)) {
                                printf("\nNo hay clientes para atender.\n");
                                printf("\nPresione Enter para continuar...");
                                while(getchar() != '\n');
                                getchar();
                                break;
                            }

                            // ---- EJECUCION ----
                            Cola resultado = c_ej7_atenderclientes(c1, c2, c3, Q);

                            printf("\n====================================\n");
                            printf("ORDEN DE ATENCION\n");
                            printf("====================================\n\n");

                            if (c_es_vacia(resultado)) {
                                printf("No hubo resultados.\n");
                            } else {
                                int orden = 1;
                                while (!c_es_vacia(resultado)) {
                                    TipoElemento x = c_desencolar(resultado);
                                    printf("%d) %s\n", orden, (char*) x->valor);
                                    orden++;
                                }
                            }

                            printf("\nPresione Enter para continuar...");
                            while(getchar() != '\n');
                            getchar();
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
                Cola c1 = c_crear();
                cargarCola(c1);

                Cola c2 = c_crear();
                cargarCola(c2);

                printf("Cola numero uno: ");
                c_mostrar(c1);
                printf("Cola numero dos: ");
                c_mostrar(c2);

                if (c_ej3_iguales(c1, c2)) {
                    printf("\nLas colas son iguales\n");
                } else {
                    printf("\nLas colas NO son iguales\n");
                }
                printf("Este ejercicio tiene una complejidad Algoritmica de O(n) donde n representa la cantidad de elementos de la cola");
                
                printf("\nPresione Enter para continuar...");
                while(getchar() != '\n');  // limpia el buffer
                getchar();                  // ahora sí espera al usuario
                break;
            }
            case 'C':{
                /*EJERCICIO 4*/
                Cola c = c_crear();
                cargarCola(c);
                printf("Cola armada con valores de usuario: ");
                c_mostrar(c);

                Cola norepetidos = c_ej4_colanorepetidos(c);

                printf("\nCola con elementos no repetidos: ");
                c_mostrar(norepetidos);
                printf("\nEste ejercicio tiene una complejidad Algoritmica de O(n^2)");

                printf("\nPresione Enter para continuar...");
                while(getchar() != '\n');  // limpia el buffer
                getchar();
                break;
            }
            case 'D':{
                /*EJERCICIO 5*/
                Cola c = c_crear();

                int cantidad;
                int numero;

                printf("====================================\n");
                printf("EJERCICIO 5 - DIVISORES TOTALES\n");
                printf("====================================\n\n");

                printf("Cantidad de elementos: ");
                scanf("%d",&cantidad);

                while(cantidad <= 0 || cantidad > 10){

                    printf("Cantidad invalida. Reingrese: ");
                    scanf("%d",&cantidad);
                }

                for(int i=0;i<cantidad;i++){

                    printf("Ingrese elemento %d (>=2): ",
                           i+1);

                    scanf("%d",&numero);

                    while(numero < 2){

                        printf("Valor invalido. Reingrese: ");
                        scanf("%d",&numero);
                    }

                    c_encolar(
                        c,
                        te_crear(numero)
                    );
                }

                printf("\nCola ingresada:\n");
                c_mostrar(c);

                bool fuetotal;
                int resultado = c_ej5_divisortotal(c, &fuetotal);

                printf("\nResultado:\n");

                if(resultado == 0){

                    printf("No existen divisores.\n");
                }
                else{

                    if(fuetotal){

                        printf(
                            "%d -> Divisor TOTAL\n",
                            resultado
                        );
                    }
                    else{

                        printf(
                            "%d -> Divisor PARCIAL\n",
                            resultado
                        );
                    }
                }

                printf("\nPresione Enter para continuar...");
                while(getchar() != '\n');  // limpia el buffer
                getchar();
                break;
            }
            case 'E':{
                /*EJERCICIO 6*/
                Pila p = p_crear();
                printf("Cargando pila:\n");
                int tamanioPila=leerEntero("Ingrese el tamanio de la Pila (expresado en enteros):",false);
                while (tamanioPila>10)
                {
                    printf("Atencion, esta definido en pilas.h que el maximo de tamanio es 10. respete este rango.\n");
                    tamanioPila=leerEntero("Ingrese el tamanio de la Pila (expresado en enteros):",false);
                }
                
                for(int i = 0;i<tamanioPila;i++){
                    int Clave = 0;
                    Clave=leerEntero("ingrese la clave a apilar para la pila: ",false);

                    TipoElemento x = te_crear(Clave);
                    p_apilar(p,x);
                }

                Cola c = c_crear();
                printf("Cargando cola:\n");
                cargarCola(c);

                printf("Pila armada: ");
                p_mostrar(p);
                printf("Cola armada: ");
                c_mostrar(c);

                Lista comunes = c_ej6_comunesapilaycola(p, c);

                if (l_es_vacia(comunes)) {
                    printf("\nNo existen valores comunes entre la pila y la cola\n");
                } else {
                    printf("\nValores comunes encontrados: \n");
                    l_mostrar(comunes);
                }

                printf("\nPresione Enter para continuar...");
                while(getchar() != '\n');  // limpia el buffer
                getchar();
                break;
            }
            case 'F':{
                /*EJERCICIO 7*/
                Cola c1 = c_crear();
                Cola c2 = c_crear();
                Cola c3 = c_crear();

                int cant;
                int tiempo;
                int Q;

                int *nro;

                printf("====================================\n");
                printf("SIMULADOR DE ATENCION DE CLIENTES\n");
                printf("====================================\n\n");

                // =====================
                // INGRESO DE Q
                // =====================

                do{
                    printf("Ingrese tiempo de atencion Q (>0): ");
                    scanf("%d",&Q);

                    if(Q <= 0){
                        printf("ERROR. Debe ser mayor que cero.\n");
                    }

                }while(Q <= 0);

                // =====================
                // COLA 1
                // =====================

                do{
                    printf("\nCantidad de clientes Cola 1 (0-10): ");
                    scanf("%d",&cant);

                    if(cant < 0 || cant > 10){
                        printf("ERROR. Cantidad invalida.\n");
                    }

                }while(cant < 0 || cant > 10);

                for(int i=1;i<=cant;i++){

                    do{
                        printf(
                            "Tiempo de atencion Cliente %d Cola 1: ",
                            i
                        );

                        scanf("%d",&tiempo);

                        if(tiempo <= 0){
                            printf("ERROR. Debe ser mayor que cero.\n");
                        }

                    }while(tiempo <= 0);

                    nro = malloc(sizeof(int));
                    *nro = i;

                    c_encolar(
                        c1,
                        te_crear_con_valor(
                            tiempo,
                            nro
                        )
                    );
                }

                // =====================
                // COLA 2
                // =====================

                do{
                    printf("\nCantidad de clientes Cola 2 (0-10): ");
                    scanf("%d",&cant);

                    if(cant < 0 || cant > 10){
                        printf("ERROR. Cantidad invalida.\n");
                    }

                }while(cant < 0 || cant > 10);

                for(int i=1;i<=cant;i++){

                    do{
                        printf(
                            "Tiempo de atencion Cliente %d Cola 2: ",
                            i
                        );

                        scanf("%d",&tiempo);

                        if(tiempo <= 0){
                            printf("ERROR. Debe ser mayor que cero.\n");
                        }

                    }while(tiempo <= 0);

                    nro = malloc(sizeof(int));
                    *nro = i;

                    c_encolar(
                        c2,
                        te_crear_con_valor(
                            tiempo,
                            nro
                        )
                    );
                }

                // =====================
                // COLA 3
                // =====================

                do{
                    printf("\nCantidad de clientes Cola 3 (0-10): ");
                    scanf("%d",&cant);

                    if(cant < 0 || cant > 10){
                        printf("ERROR. Cantidad invalida.\n");
                    }

                }while(cant < 0 || cant > 10);

                for(int i=1;i<=cant;i++){

                    do{
                        printf(
                            "Tiempo de atencion Cliente %d Cola 3: ",
                            i
                        );

                        scanf("%d",&tiempo);

                        if(tiempo <= 0){
                            printf("ERROR. Debe ser mayor que cero.\n");
                        }

                    }while(tiempo <= 0);

                    nro = malloc(sizeof(int));
                    *nro = i;

                    c_encolar(
                        c3,
                        te_crear_con_valor(
                            tiempo,
                            nro
                        )
                    );
                }

                // =====================
                // VALIDACION
                // =====================

                if(
                    c_es_vacia(c1) &&
                    c_es_vacia(c2) &&
                    c_es_vacia(c3)
                ){
                    printf(
                        "\nNo hay clientes para atender.\n"
                    );
                    printf("\nPresione Enter para continuar...");
                    while(getchar() != '\n');
                    getchar();
                    break;
                }

                Cola resultado =
                    c_ej7_atenderclientes(
                        c1,
                        c2,
                        c3,
                        Q
                    );

                printf("\n====================================\n");
                printf("ORDEN DE ATENCION\n");
                printf("====================================\n\n");

                if(c_es_vacia(resultado)){
                    printf("No hubo resultados.\n");
                }
                else{

                    while(!c_es_vacia(resultado)){

                        TipoElemento x =
                            c_desencolar(resultado);

                        printf(
                            "%s\n",
                            (char*)x->valor
                        );
                    }
                }

                printf("\nPresione Enter para continuar...");
                while(getchar() != '\n');  // limpia el buffer
                getchar();
                break;
            }
            case 'G':{
                /*EJERCICIO 8*/
                Cola c = c_crear();
                cargarCola(c);
                printf("Cola armada con valores de usuario : ");
                c_mostrar(c);

                Cola sinrepetidos = c_ej8_sacarrepetidos(c);
                printf("\nCola sin valores repetidos: ");
                c_mostrar(sinrepetidos);

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

void cargarCola(Cola c){
    int tamanio;

    tamanio=leerEntero("Ingrese el tamanio de la Cola (expresado en enteros):",false);
    while (tamanio>10)
    {
        printf("Atencion, esta definido en colas.h que el maximo de tamanio es 10. respete este rango.\n");
        tamanio=leerEntero("Ingrese el tamanio de la Cola (expresado en enteros):",false);
    }
    
    for(int i = 0;i<tamanio;i++){
        int Clave = 0;
        Clave=leerEntero("ingrese la clave a encolar para la cola: ",false);

        TipoElemento x = te_crear(Clave);
        c_encolar(c,x);
    }
}
