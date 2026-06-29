
#include <stdlib.h>
#include <stdio.h>
#include "../libs/validaciones/headers/validaciones.h"
#include "tp_conjunto.h"

Conjunto CargarConjuntoEntero(int CantidadElementos);
void EnteroPositivo(int *buffer, char Msg[]);
void Menu();
void ImprimirAsciiMenu(void);
Lista CargarLista();

int main(){
    Menu();
    return 0;
}


Conjunto CargarConjuntoEntero(int CantidadElementos){

    Conjunto C = cto_crear();

    if (CantidadElementos == 0){
        return C;
    }
    TipoElemento x;
    int clave = 0;

    int contador = 0;

    while (contador < CantidadElementos)
    {
        ValidacionEntero(&clave,"Ingrese una clave Numerica para el Elemento");
        
        x=te_crear(clave);

        cto_agregar(C,x);
        contador++;
    }
    
    return C;
}

void EnteroPositivo(int *buffer, char Msg[]){

    int Auxiliar = 0;
    
    //Cartelito("Ingrese Un Numero Positivo para la Cantidad de elementos del conjunto","");

    ValidacionEntero(&Auxiliar,Msg);

    while (Auxiliar < 0)
    {
       // printf("Ingrese Un numero positivo  \n"); 
        ValidacionEntero(&Auxiliar,"ingrese un numero Positivo ");
    }
    
    *buffer = Auxiliar;
}

void Menu(){

    int Opcion = -1;
    do{
    printf("\n\n\n");
    ImprimirAsciiMenu();
    printf("\n\n");

    printf("| 1 - Ejercicio 2: |\n");
    printf("| 2 - Ejercicio 3: |\n");
    printf("| 3 - Ejercicio 4: |\n");
    printf("| 4 - Ejercicio 5: |\n");
    printf("| 5 - Ejercicio 6: |\n");
    printf("| 6 - Ejercicio 7: |\n");
    printf("| 7 - Ejercicio 8: |\n");
    printf("| 0 - SALIR        |\n\n\n");

    EnteroPositivo(&Opcion,"Ingrese la opcion del ejercicio que desee ver : ");

    while (Opcion > 7 || Opcion < 0)
    {
        EnteroPositivo(&Opcion,"Ingrese Una opcion valida entre 0 a 7 : ");
    }
    

    if (Opcion == 0)
    {
        printf("hasta luego......");
        return;
    }

    Conjunto c1 = cto_crear();
    Conjunto c2 = cto_crear();

    if(Opcion == 1 || Opcion == 3 || Opcion == 4||Opcion == 5 || Opcion == 6|| Opcion == 7){

        int CantidadElementos = 0;
        EnteroPositivo(&CantidadElementos,"Ingrese la cantidad de elementos para c1 (Conjunto 1)");

        printf("cargue para c1\n");
        c1=CargarConjuntoEntero(CantidadElementos);

        printf("\n=============================================\n");

        EnteroPositivo(&CantidadElementos,"Ingrese la cantidad de elementos para c2 (Conjunto 2)");
        printf("cargue para c2\n");
        c2=CargarConjuntoEntero(CantidadElementos);

        printf("\n=============================================\n");

        Cartelito("Los Elementos de c1","----------");
        cto_mostrar(c1);

        Cartelito("Los Elementos de c2","----------");
        cto_mostrar(c2);
    }
    printf("\n=============================================\n");
    switch (Opcion)
    {
        case 1:{   

            Cartelito("la Union de c1 y c2 es","----------");
            Conjunto Union = cto_crear();
            Union = c_ej2_union(c1,c2);
            cto_mostrar(Union);
            
            Cartelito("la interseccion de c1 y c2 es","----------");

            Conjunto Interseccion = cto_crear();
            Interseccion = c_ej2_interseccion(c1,c2);
            cto_mostrar(Interseccion);
            
            Cartelito("la diferencia de c1 y c2 es","----------");

            Conjunto Diferencia = cto_crear();
            Diferencia = c_ej2_diferencia(c1,c2);
            cto_mostrar(Diferencia);

            int clave = 0;
            ValidacionEntero(&clave,"Por favor ingrese la clave para saber si Pertenece al Conjunto 1 (c1) \n");

            printf("---------- La clave %d Pertenece Al conjunto c1 ? ----------  ",clave);
            if (c_ej2_pertenece(c1,clave))
            {
                printf("Si, la clave pertenece");
            }
            else{
                printf("No, la clave no pertenece");
            }
            
        break;
        }

        case 2:{
            Lista Lconj = CargarLista();
            Conjunto ConListUnion = c_ej3_uniones(Lconj);
            Conjunto ConListInter = c_ej3_intersecciones(Lconj);

            printf("union entre los conjuntos de la lista ");
            cto_mostrar(ConListUnion);

            printf("interseccion entre los conjuntos de  la lista:\n");
            cto_mostrar(ConListInter);
        }
        break;
        case 3:{
            int CantidadElementos;
            Conjunto c3 = cto_crear();

            EnteroPositivo(&CantidadElementos,"Ingrese la cantidad de elementos para c3");
            printf("cargue para c3\n");
            c3=CargarConjuntoEntero(CantidadElementos);

            Cartelito("c1:","------------");
            cto_mostrar(c1);
    
            Cartelito("c2:","------------");
            cto_mostrar(c2);
    
            Cartelito("c3:","------------");
            cto_mostrar(c3);
            
            printf("Se cumple la propiedad de transitividad ?");
            
            bool Sub = c_ej4_transitividad(c1,c2,c3);
            
            if (Sub)
            {
                printf("\nSi, se cumple");
            }else{
                printf("\nNo, no se cumple");
            }
            break;
        }
        case 4:{
            Conjunto DiferenciaSime =c_ej5_dif_simetrica(c1,c2);
            printf("La diferencia simetrica entre c1 y c2 es de :\n");
            cto_mostrar(DiferenciaSime);
            break;
        }
       case 5:{
    bool ConjuntoPropio = c_ej6_subconjuntopropio(c1,c2);
    printf("c1 es conjunto propio de c2?? ");
    if (ConjuntoPropio)
    {
        printf("Si, lo es");
    }else{
        printf("No lo es..");
    }

    printf("\n\nComplejidad algoritmica: O(n^2)\n");
    printf("Justificacion: Se recorre el conjunto A una vez y para cada elemento ");
    printf("se realiza una busqueda lineal en el conjunto B mediante cto_pertenece(). ");
    printf("Por ello la complejidad total es O(n^2).\n");

    break;
}
        case 6:{
    int CantidadElementos;
    Conjunto c3 = cto_crear();

    EnteroPositivo(&CantidadElementos,"Ingrese la cantidad de elementos para c3");
    printf("cargue para c3\n");
    c3=CargarConjuntoEntero(CantidadElementos);

    Cartelito("c1:","------------");
    cto_mostrar(c1);

    Cartelito("c2:","------------");
    cto_mostrar(c2);

    Cartelito("c3:","------------");
    cto_mostrar(c3);

    c_ej7_subconjtotalparcial(c1,c2,c3);

    printf("\n\nComplejidad algoritmica: O(n^2)\n");
    printf("Justificacion: Cada comparacion recorre un conjunto completo y, para cada ");
    printf("elemento, realiza una busqueda lineal en el otro conjunto. ");
    printf("Aunque se comparan varios pares de conjuntos, esa cantidad es constante, ");
    printf("por lo que la complejidad sigue siendo O(n^2).\n\n");

    break;
}
       case 7:{
    printf("Los dos Conjuntos son iguales?? ");
    if (c_ej8_soniguales(c1,c2))
    {
        printf("Si, son iguales");
    }else{
        printf("No, no son iguales");
    }

    printf("\n\nComplejidad algoritmica: O(n^2)\n");
    printf("Justificacion: Primero se compara la cantidad de elementos (O(1)). ");
    printf("Luego se recorren todos los elementos de A y para cada uno se realiza ");
    printf("una busqueda lineal en B mediante cto_pertenece(). ");
    printf("La complejidad resultante es O(n^2).\n");

    break;
}
        
    }
    
   
    }while (Opcion != 0);
}
void ImprimirAsciiMenu(void)
{
    printf(" __    __     ______     __   __     __  __\n");
    printf("/\\ \"-./  \\   /\\  ___\\   /\\ \"-.\\ \\   /\\ \\/\\ \\\n");
    printf("\\ \\ \\-./\\ \\  \\ \\  __\\   \\ \\ \\-.  \\  \\ \\ \\_\\ \\\n");
    printf(" \\ \\_\\ \\ \\_\\  \\ \\_____\\  \\ \\_\\\\\"\\_\\  \\ \\_____\\\n");
    printf("  \\/_/  \\/_/   \\/_____/   \\/_/ \\/_/   \\/_____/\n");
}

Lista CargarLista(){
    
    Lista ListaResultado= l_crear();
    int contador  =1;
    int CantidadDeConjuntos;
    int CantidadElementos;
    printf("\n==========================================\n");
    EnteroPositivo(&CantidadDeConjuntos,"Ingrese la Cantidad De conjuntos para el punto 3");

    for (int i = 1; i <= CantidadDeConjuntos; i++)
    {
        printf("Para el conjunto N° %d",contador);
        EnteroPositivo(&CantidadElementos,"Ingrese la Cantidad De Elementos");
        
        Conjunto NuevoConjunto = cto_crear();
        NuevoConjunto = CargarConjuntoEntero(CantidadElementos);

        TipoElemento x = te_crear_con_valor(0,NuevoConjunto);

        l_agregar(ListaResultado,x);
        printf("\n=========================================\n");
        contador++;
    }
    return ListaResultado;
}

