#include <stdio.h>
#include <stdlib.h>

/*Generar un algoritmo recursivo que calcule el k-ésimo número de la serie de Fibonacci.
Ejemplos:
terminoSeriedeFibonacci (1) => 1
terminoSeriedeFibonacci (5) => 8
*/

int fibonacci(int fibo)
{
    int resultado;
    // Defino casos base 1 y 2 ya que sino no funciona la suma de Fn = F(n-1) + F(n-2)
    if (fibo == 1)
    {
        resultado = 1;
    }
    else if (fibo == 2)
    {
        resultado = 2;
    }
    // Si no es ni 1 ni 2, entonces hace la suma normal llamando a la posicion anterior y dos anteriores
    else
    {
        resultado = fibonacci(fibo - 1) + fibonacci(fibo - 2);
    }
    return resultado;
}

int main()
{
    int fibo = 6;
    int resultado = fibonacci(fibo);
    printf("%i\n", resultado);
    return 0;
}