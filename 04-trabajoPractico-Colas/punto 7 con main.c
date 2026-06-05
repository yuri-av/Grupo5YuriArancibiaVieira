#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

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

        if(cant < 0 || cant > TAMANIO_MAXIMO){
            printf("ERROR. Cantidad invalida.\n");
        }

    }while(cant < 0 || cant > TAMANIO_MAXIMO);

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

        if(cant < 0 || cant > TAMANIO_MAXIMO){
            printf("ERROR. Cantidad invalida.\n");
        }

    }while(cant < 0 || cant > TAMANIO_MAXIMO);

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

        if(cant < 0 || cant > TAMANIO_MAXIMO){
            printf("ERROR. Cantidad invalida.\n");
        }

    }while(cant < 0 || cant > TAMANIO_MAXIMO);

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
        return 0;
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

    return 0;
}