#include <stdio.h>
#include "../src/func.h"

int assert_equal(int expected, int actual, const char *description) {
    int result = 0;
    if (expected != actual) {
        printf("✗ %s (esperado=%d, obtenido=%d)\n", description, expected, actual);   
        result = 1;
    } else {
        printf("✓ %s\n", description);
    }

    return result;
}

int test_bisiesto_divisible_por_400(void) {
    return assert_equal(1, Calcular_ano_bisiesto(2000), "2000 es un año bisiesto");
}

int test_bisiesto_divisible_por_4_no_100(void) {
    return assert_equal(1, Calcular_ano_bisiesto(2004), "2004 es un año bisiesto");
}

int test_no_bisiesto_divisible_por_100_no_400(void) {
    return assert_equal(0, Calcular_ano_bisiesto(1900), "1900 no es un año bisiesto");
}

int test_no_bisiesto_2023(void) {
    return assert_equal(0, Calcular_ano_bisiesto(2023), "2023 no es un año bisiesto");
}

int test_bisiesto_2024(void) {
    return assert_equal(1, Calcular_ano_bisiesto(2024), "2024 es un año bisiesto");
}

int test_no_bisiesto_1800(void) {
    return assert_equal(0, Calcular_ano_bisiesto(1800), "1800 no es un año bisiesto");
}

int main(void) {
    int failures = 0;

    failures += test_bisiesto_divisible_por_400();
    failures += test_bisiesto_divisible_por_4_no_100();
    failures += test_no_bisiesto_divisible_por_100_no_400();
    failures += test_no_bisiesto_2023();
    failures += test_bisiesto_2024();
    failures += test_no_bisiesto_1800();

    if (failures != 0) {
        printf("\n%d test(s) fallaron.\n", failures);
    } else {
        printf("\nTodos los tests pasaron correctamente.\n");
    }

    return failures;
}