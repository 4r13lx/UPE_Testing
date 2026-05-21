#include "func.h"

/// @brief Implementa la logica para calcular el maximo comun divisor
/// @param a Valores enteros que representan a=valor divisible
/// @param b Valores enteros que representan b=divisor
/// @return Se retorna 0 (cero) si el argumento b es 0 (cero), X en caso de que los valores sean validos para realizar la operacion aritmetica
int CalcularMCD(int a, int b)
{
    int temp = 0; // variable para almacenar valores de forma temporal

    while(b!=0) // iterar hasta que b sea igual a 0
    {
        temp = b; // se almacena en temp el valor de b
        b = a % b; // se realiza el calculo aritmetico del modulo de a
        a = temp; // se sobreescribe en a el valor calculado en la sentencia anterior
    }

    return a; // se retorna el valor final de a
}