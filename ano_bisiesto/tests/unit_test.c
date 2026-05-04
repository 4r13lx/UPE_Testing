#include <stdio.h>
#include "../src/func.h"

/// @brief Test para verificar que un año divisible por 400 es bisiesto
void test_bisiesto_divisible_por_400() {
    if (Calcular_ano_bisiesto(2000) == 1) {
        printf("✓ Test correcto: 2000 es un año bisiesto\n");
    } else {
        printf("✗ Test incorrecto: 2000 debería ser un año bisiesto\n");
    }
}

/// @brief Test para verificar que un año divisible por 4 pero no por 100 es bisiesto
void test_bisiesto_divisible_por_4_no_100() {
    if (Calcular_ano_bisiesto(2004) == 1) {
        printf("✓ Test correcto: 2004 es un año bisiesto\n");
    } else {
        printf("✗ Test incorrecto: 2004 debería ser un año bisiesto\n");
    }
}

/// @brief Test para verificar que un año divisible por 100 pero no por 400 no es bisiesto
void test_no_bisiesto_divisible_por_100_no_400() {
    if (Calcular_ano_bisiesto(1900) == 0) {
        printf("✓ Test correcto: 1900 no es un año bisiesto\n");
    } else {
        printf("✗ Test incorrecto: 1900 debería no ser un año bisiesto\n");
    }
}

/// @brief Test para verificar que un año no bisiesto común no es bisiesto
void test_no_bisiesto_2023() {
    if (Calcular_ano_bisiesto(2023) == 0) {
        printf("✓ Test correcto: 2023 no es un año bisiesto\n");
    } else {
        printf("✗ Test incorrecto: 2023 debería no ser un año bisiesto\n");
    }
}

/// @brief Test para verificar que un año bisiesto común es bisiesto
void test_bisiesto_2024() {
    if (Calcular_ano_bisiesto(2024) == 1) {
        printf("✓ Test correcto: 2024 es un año bisiesto\n");
    } else {
        printf("✗ Test incorrecto: 2024 debería ser un año bisiesto\n");
    }
}

/// @brief Test para verificar que un año no bisiesto divisible por 100 pero no por 400 no es bisiesto
void test_no_bisiesto_1800() {
    if (Calcular_ano_bisiesto(1800) == 0) {
        printf("✓ Test correcto: 1800 no es un año bisiesto\n");
    } else {
        printf("✗ Test incorrecto: 1800 debería no ser un año bisiesto\n");
    }
}

int main() {
    test_bisiesto_divisible_por_400();
    test_bisiesto_divisible_por_4_no_100();
    test_no_bisiesto_divisible_por_100_no_400();
    test_no_bisiesto_2023();
    test_bisiesto_2024();
    test_no_bisiesto_1800();
    
    printf("\nLos 6 tests fueron ejecutados correctamente!\n");
    return 0;
}