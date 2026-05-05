#include "func.h"

int Calcular_ano_bisiesto(int ano)
{
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}