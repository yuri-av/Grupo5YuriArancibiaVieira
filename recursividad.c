#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LINE "\n\n================================================================================\n\n"

//----------------------------PROTOTIPOS---------------------------------


int Palindromo(char Palabra[],int Inicio, int Final); // PUNTO 1
int MultPorSuma(int Mult, int aMult);// PUNTO 2
int fibonacci(int n);// PUNTO 3
int DivEntera(int Dividendo,int Divisor);
int Resto(int Dividendo,int Divisor);
void DivDecimal(int Resto,int Div,int Precision);
float DivisionSinOperador(int Dividendo,int Divisor,int Precision);// PUNTO 4
void insertar(int pos,char st[],char Ins);
int Miles(int i,char pal[]);// PUNTO 5
void MafiaChina(int n);// PUNTO 7

//TESTS
void TestMult();
void TestFibbo();
void Test();

//MENU
void Menu();
void MenuOpciones();
 
//----------------------------MAIN---------------------------------
int main(){
		Test();
		//DivisionSinOperador(-10,0,3);
		MenuOpciones();
    }
//------------------FUNCIONES RECURSIVAS------------------

int Palindromo(char Palabra[],int Inicio, int Final){
	if(Inicio > Final){
		return 1;
		}
	else if(Palabra[Inicio] != Palabra[Final]){
			return 0;
		}
	return Palindromo(Palabra,Inicio+1,Final-1);
	}
	
	
int MultPorSuma(int Mult, int aMult){

	if(aMult ==0 ){
		return 0;
		}
	return Mult + MultPorSuma(Mult,aMult-1);
	}
	
int fibonacci(int n) {
    
    while(n<0){
		printf("ERROR : el numero que desea averiguar no puede ser menor que 0, vuelva a intentar :");
		scanf("%d",&n);
		printf("%s",LINE);
		}
    if (n==0) {
        return 0;
    }
    if(n==1){
        return 1;
    }else{
        return (fibonacci(n-1) + fibonacci(n-2));
	}
        
}


int DivEntera(int Dividendo,int Divisor){
	
	if(Dividendo<Divisor){
		return 0;
		}
	else{
		return 1+(DivEntera(Dividendo-Divisor,Divisor));
		}
	}
int Resto(int Dividendo,int Divisor){
	if(Dividendo<Divisor){
		return Dividendo;
		}
	return Resto(Dividendo-Divisor,Divisor);
	}

void DivDecimal(int Resto,int Div,int Precision){
	if(Resto == 0|| Precision ==0){
		return ;
	}
	else{
		int Digito =(Resto *10)/Div ;
		
		int aux = Resto *10;
		
		int NuevoResto = aux - Digito * Div;
		printf("%i",Digito);
		
		return DivDecimal(NuevoResto,Div,Precision-1);
		}
	}
	
float DivisionSinOperador(int Dividendo,int Divisor,int Precision){
	
	
	//VALIDO RANGOS
	while(Precision >10 || Precision<1){
			printf("ERROR: La precision de los decimales que ingreso es invalida, esta debe estar entre 1 y 10 : ");
			scanf("%d",&Precision);
			printf("%s",LINE);
		}
	while(Dividendo < 0 || Divisor <0){
		printf("ERROR: esta funcion por temas de practicidad no toma valores negativos en sus entradas \n");
		printf("por favor ingrese un numero positivo para el dividendo : ");
		scanf("%d",&Dividendo);
		printf("\npor favor ingrese un numero positivo para el divisor : ");
		scanf("%d",&Divisor);
		printf("%s",LINE);
		}
	while(Divisor == 0){
		printf("ERROR: No se puede dividir por 0, ingrese un valor distinto de este : ");
		scanf("%d",&Divisor);
		printf("%s",LINE);
		}
		
		// FUNCION DE DIVIDIR
	int Resultado = DivEntera(Dividendo,Divisor);
	int Rest = Resto(Dividendo,Divisor);
	printf("El Resultado de Dividir %d con %d es de %d",Dividendo,Divisor,Resultado);
	
	if(Rest != 0){
		printf(".");
		DivDecimal(Rest,Divisor,Precision);
		}
		
	return Resultado;
	
	}

void insertar(int pos,char st[],char Ins){
    
    int len =strlen(st);
    
    for(int i = len;i>=pos;i--){
        
        st[i+1] = st[i];
    }
    
    st[pos] = Ins;
}

int Miles(int i,char pal[]){
    
    if(pal[i] == '\0'){
         return 0;
    }
    
     int contador =   Miles(i+1,pal)+1;
     if(contador == 3 && i > 1){
        
        insertar(i,pal,'.');
        contador = 0;
    }
         
    return contador;
}

void MafiaChina(int n){
	while(n<0){
		printf("ERROR: El numero ingresado por parametro es negativo, por favor vuelva a intentarlo con numero Positivo : ");
		scanf("%d",&n);
		printf("%s",LINE);
		}
	
	if(n<=0){
		return ;
		}
		
	printf("('-");
	
	MafiaChina(n-1);
	
	printf("')");
	
	}

void Menu(){
    printf("\n============== BIENVENIDO ===============\n");
    printf("-------------- OPCIONES ---------------- \n\n 1. Palindromo \n-1. SALIR \n %s",LINE);
    
}
void MenuOpciones(){
	    Menu();
    
    printf("Ingrese la opcion que desee.... ");
    
    int dec= 0;
    scanf("%d",&dec);
    
    while (dec != -1)
    {
        switch (dec)
        {
        case 1 :
			printf("ingrese la palabra  : ");
			char Palabra[20];
			scanf("%s",Palabra);
            printf("\n %d el resultado de Palindromo es ; 0 = False , 1 = True\n",Palindromo(Palabra,0,strlen(Palabra)-1));
            break;
		
         default:
            break;
        }
        Menu();
        

        printf("Ingrese la opcion que desee.... ");
        scanf("%d",&dec);

    }
     
    printf("Adioss <3");
  

}
// ---------------------------- TESTS-----------------------------
void TestMult(){
	printf("Para La funcion MultPorSuma (Multiplicar usando sumas), Realizamos el test unitario : \n");
	if(MultPorSuma(4,5) == 20 && MultPorSuma(6,7) == 42 && MultPorSuma(10,10) == 100){
		printf("\t\t\t===================== TEST APROBADO =====================\n");
		}
	else{
		printf("\t\t\t===================== TEST DESAPROBADO =====================\n");
		}
	printf("%s",LINE);
}
void TestFibbo(){
	printf("Para La funcion Fibonacci (Buscar el k - esimo en la sucesion), Realizamos el test unitario : \n");
	if(fibonacci(5) == 5 && fibonacci(7) == 13 && fibonacci(10) == 55){
		printf("\t\t\t===================== TEST APROBADO =====================\n");
		}
	else{
		printf("\t\t\t===================== TEST DESAPROBADO =====================\n");
		}
	printf("%s",LINE);	
}	

void Test(){
	TestFibbo();
    TestMult();	
	
	}

