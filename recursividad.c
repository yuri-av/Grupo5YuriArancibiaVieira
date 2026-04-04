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
 
//----------------------------MAIN---------------------------------
int main(){

    //--------FIBONACCI---------
    int fib;
    printf("\nIngrese el numero que desea saber en la sucesion de Fibonacci: ");
    while (scanf("%d", &fib) != 1 || fib < 0) {
        printf("ERROR: el numero no puede ser menor que 0, vuelva a intentar: ");
        while (getchar() != '\n');
    }
    printf("\nEl numero de Fibonacci N %d es: %d\n", fib, fibonacci(fib));
    printf("%s", LINE);

    //--------DIVISION---------
    int Precision, Dividendo, Divisor;

    printf("\nIngrese el Dividendo (positivo): ");
    while (scanf("%d", &Dividendo) != 1 || Dividendo < 0) {
        printf("ERROR: ingrese un numero positivo: ");
        while (getchar() != '\n');
    }

    printf("\nIngrese el Divisor (positivo, distinto de 0): ");
    while (scanf("%d", &Divisor) != 1 || Divisor <= 0) {
        printf("ERROR: el divisor debe ser mayor a 0: ");
        while (getchar() != '\n');
    }

    printf("\nIngrese la Precision (1-10): ");
    while (scanf("%d", &Precision) != 1 || Precision < 1 || Precision > 10) {
        printf("ERROR: la precision debe estar entre 1 y 10: ");
        while (getchar() != '\n');
    }

    DivisionSinOperador(Dividendo, Divisor, Precision);
    printf("%s", LINE);

    //--------MAFIA CHINA---------
    int Chinos;
    printf("\nIngrese el nivel de la reunion de la mafia (positivo): ");
    while (scanf("%d", &Chinos) != 1 || Chinos < 1) {
        printf("ERROR: el numero debe ser positivo: ");
        while (getchar() != '\n');
    }
    MafiaChina(Chinos);
    printf("\n%s", LINE);

    return 0;

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
	
	
int MultPorSuma(int Mult, int aMult) {
    if (aMult == 0) {
        return 0;
    }
    if (aMult < 0) {
        return -Mult + MultPorSuma(Mult, aMult + 1);
    }
    return Mult + MultPorSuma(Mult, aMult - 1);
}
	
int fibonacci(int n) {
    
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
	
	if(n<=0){
		printf("(-.-)");
		return ;
		}
		
	printf("(-.");
	
	MafiaChina(n-1);
	
	printf(".-)");
	
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

