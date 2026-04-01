

#include <stdlib.h>
#include <stdio.h>

int division_por_resta(int dividendo, int divisor)
{

    // Variables
    //=====================================
    int resultado;

    // Caso base
    //========================================================================
    if (dividendo < divisor)
    {
        resultado = 0;
    }
    

    // Cuenta la cantidad de veces que entra el divisor en el dividendo
    //========================================================================
    else
    {
        resultado = 1 + division_por_resta(dividendo - divisor, divisor);
    }
    //========================================================================
    return resultado;
}

void division_decimal(int resto, int divisor, int precision)
{
    // Verifico que haya resto y se haya definido un nivel de precisión
    if ((resto > 0) && (precision > 0))
    {
        // Calculo el dividendo a utilizar en la funcion
        int nuevo_dividendo = resto * 10;
        // Llamo a la funcion de division para saber el valor del digito decimal
        int digito = division_por_resta(nuevo_dividendo, divisor);
        // Lo imprimo
        printf("%i", digito);
        // Calculo nuevo resto y vuelvo a llamar a la función
        int proximo_resto = nuevo_dividendo - (digito * divisor);
        division_decimal(proximo_resto, divisor, precision - 1);
    }
}

int main()
{

    // Variables
    //=====================================
    int dividendo, divisor, precision, resto;
    
    // Ejecución de código
    //=====================================
    printf("Ingrese el dividendo: ");
    scanf("%i", &dividendo);
    
    printf("Ingrese el divisor: ");
    scanf("%i", &divisor);
    while (divisor ==  0)
    {
        printf("Error: no se puede dividir por 0, por favor ingrese de nuevo  un valor: ");
        scanf("%i", &divisor);
    }
    printf("Digitos de precision: ");
    scanf("%i", &precision);
    
    int resultado = division_por_resta(dividendo, divisor);
    printf("%i", resultado);

    // Si hay resto, calculamos la parte decimal
    resto = dividendo - (resultado * divisor);
    if (resto > 0 && precision > 0)
    {
        printf(","); // Imprimimos la coma una sola vez
        division_decimal(resto, divisor, precision);
    }

    // Fin
    //=====================================
    return 0;
    //=====================================
}