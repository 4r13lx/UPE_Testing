#include <stdio.h>
#include "../src/func.h"

// Definir colores para el texto de salida
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define RESET   "\x1b[0m"

// Funcion auxiliar para mostrar resultado
void Probar(int a, int b, int esperado, char *nombre_prueba)
{
    int resultado = CalcularMCD(a, b);

    printf("(a=%d, b=%d) = %d -> %s", a, b, resultado, nombre_prueba);

    if(resultado == esperado)
    {
        printf(GREEN "[OK]\n" RESET);
    }
    else
    {
        printf(RED "[ERROR] -> Esperado: %d\n" RESET, esperado);
    }
}

int main()
{
    /*
        CASOS MAS IMPORTANTES
    */

    /* Caso normal */
    Probar(48, 18, 5, "Caso normal");

    /* Numeros coprimos */
    Probar(17, 13, 1, "Numeros coprimos");

    /* Numeros iguales */
    Probar(10, 10, 10, "Numeros iguales");

    /* Uno es multiplo del otro */
    Probar(20, 5, 5, "Uno es multiplo del otro");

    /* b mayor que a */
    Probar(5, 20, 5, "b mayor que a");

    /* Uno de los numeros es 1 */
    Probar(1, 99, 1, "A es uno(1)");

    /* a = 0 */
    Probar(0, 5, 5, "A es cero(0)");

    /* b = 0 */
    Probar(5, 0, 5, "B es cero(0)");

    /* Ambos en 0 */
    Probar(0, 0, 0, "A y B son cero(0)");

    /* Numeros grandes */
    Probar(1000000, 500000, 500000, "Numero grandes");

    return 0;
}