# Ejercicio integrador de Testing — Clasificación de Envíos

## Cátedra: Testing de Software

### Lenguaje: C ANSI

---

## 1. Objetivo

El objetivo de este ejercicio es aplicar, sobre una función escrita en **C ANSI**, distintas técnicas de testing:

- Análisis de **caja blanca**.
- Construcción de **grafo dirijido**.
- Cálculo de **complejidad ciclomática**.
- Determinación de **caminos independientes**.
- Diseño de **casos de prueba unitarios**.
- Análisis de **clases de equivalencia**.
- Identificación de **valores límite**.
- Implementación de las pruebas sin utilizar frameworks externos.

La actividad busca que el estudiante pueda relacionar el código fuente con el diseño sistemático de pruebas y justificar por qué determinados casos de prueba son necesarios.

---

## 2. Restricciones técnicas

El ejercicio debe resolverse exclusivamente utilizando **C ANSI**.

### Está permitido

- Variables escalares (`int`, `char`, `float`, `double`, etc.).
- Estructuras de control (`if`, `else`, `while`, `for`, `switch`).
- Funciones.
- Operadores aritméticos, relacionales y lógicos.
- `printf` y `scanf` si fueran necesarios para una aplicación de prueba.

### No está permitido

- Librerías externas.
- Frameworks de testing.
- Unity, CUnit, Google Test u otros frameworks.
- `stdbool.h`.
- Tipo `bool`.
- Vectores.
- Matrices.
- Punteros.
- `struct`.
- Memoria dinámica.
- Archivos.
- Variables globales utilizadas para almacenar resultados.
- Código específico de un compilador.

> **Importante:** aunque `printf` pertenece a la biblioteca estándar de C, puede utilizarse únicamente para mostrar los resultados de las pruebas. La función bajo prueba no debe depender de ninguna librería externa.

---

# 3. Problema a resolver

Una organización necesita clasificar un envío según peso, distancia, tipo de cliente, prioridad y destino, aplicando restricciones de servicio.

Se debe implementar la función:

```c
int clasificar_envio(int peso, int distancia, int cliente, int prioridad, int destino);
```

La función debe devolver un código entero que represente el resultado de la operación.

## Códigos de retorno

| Código | Condición |
|---:|---|
| 1 | ENVIO ECONOMICO |
| 2 | ENVIO ESTANDAR |
| 3 | ENVIO PRIORITARIO |
| 4 | ENVIO RECHAZADO |

---

# 4. Reglas del negocio

Los parámetros tienen las siguientes restricciones:

- `peso`: entre 1 y 50 kg.
- `distancia`: entre 1 y 2000 km.
- `cliente`: 1 = particular, 2 = empresa, 3 = premium.
- `prioridad`: 0 = normal, 1 = urgente.
- `destino`: 1 = urbano, 2 = nacional, 3 = internacional.

---

# 5. Reglas para determinar el resultado

La función deberá aplicar las siguientes reglas en el orden indicado.

1. Cualquier dato fuera de rango produce rechazo.
2. Los envíos internacionales de más de 20 kg son rechazados.
3. Un cliente premium obtiene prioridad si el peso <= 20 kg y la distancia <= 1000 km.
4. Un envío urgente puede ser prioritario si el destino es urbano o nacional y el peso <= 10 kg.
5. Empresas pueden acceder a estándar hasta 30 kg y 1500 km.
6. Particulares acceden a económico hasta 10 kg y 500 km, salvo que sea urgente.
7. Todo envío válido que no entre en las categorías anteriores queda estándar.

---

# 6. Código inicial

El código deberá ser desarrollado por el alumno, comprendiendo la problemática a resolver y las reglas de negocio, como también, los resultados esperados.

> **Importante:** no se debe modificar la lógica de la función para facilitar las pruebas. El objetivo del ejercicio es analizar el comportamiento del código.

Una posible firma es:

```c
int clasificar_envio(int peso, int distancia, int cliente, int prioridad, int destino);
```

El estudiante deberá completar el código de producción a partir de las reglas de negocio y luego diseñar las pruebas sobre esa implementación.

---

# 7. Actividad 1 — Análisis de caja blanca

Analice el código desde el punto de vista de **caja blanca**.

El informe debe identificar:

1. Sentencias.
2. Decisiones.
3. Condiciones simples.
4. Condiciones compuestas.
5. Puntos de entrada.
6. Puntos de salida.
7. Caminos posibles de ejecución.

### Preguntas

**a.** ¿Cuántas decisiones existen en el código?

**b.** ¿Qué diferencias existen entre una decisión y una condición?

**c.** ¿Qué expresiones contienen operadores lógicos `&&` y `||`?

**d.** ¿Qué decisiones tienen múltiples condiciones?

**e.** ¿Existen decisiones anidadas?

---

# 8. Actividad 2 — Grafo dirijido

Construya el **grafo dirijido** de la función.

Cada nodo debe representar una sentencia o bloque lógico relevante.

Por ejemplo:

```text
        ┌──────────────┐
        │    Inicio    │
        └──────┬───────┘
               │
               v
        ┌──────────────┐
        │ Validación   │
        └──────┬───────┘
           Sí  │  No
          ┌────┘
          v
       retorno inválido
```

El grafo completo debe contemplar todos los caminos relevantes hasta los diferentes valores de retorno.

### Entregable

Presentar:

- Imagen del grafo.
- Identificación numérica de los nodos.
- Aristas.
- Nodo inicial.
- Nodos finales.

---

# 9. Actividad 3 — Complejidad ciclomática

Calcule la **complejidad ciclomática** del programa.

Utilice el siguientes y único método visto en clase:

### Método 1

```text
CC = A - N + 2
```

donde:

- `A` = cantidad de aristas.
- `N` = cantidad de nodos.

### Preguntas

1. ¿Cuál es la complejidad ciclomática?
2. ¿Qué representa ese valor?
3. ¿Cuántos caminos independientes deberían identificarse como mínimo?
4. ¿Qué relación existe entre la complejidad ciclomática y la cantidad mínima de casos de prueba de caja blanca?

---

# 10. Actividad 4 — Caminos independientes

A partir del grafo construido, determine un conjunto de **caminos independientes**.

Para cada camino indique:

```text
Camino 1:
Inicio → ... → ... → Retorno

Camino 2:
Inicio → ... → ... → Retorno
```
> **Ayuda:** Un camino es independiente cuando incorpora al menos una arista que no estaba presente en los caminos anteriores.


### Importante

No alcanza con enumerar combinaciones arbitrarias de valores.

Los caminos deben justificarse a partir del **grafo dirijido**.

---

# 11. Actividad 5 — Diseño de casos de prueba de caja blanca

Diseñe los casos de prueba necesarios para cubrir los caminos independientes.

Utilice la siguiente tabla:

| # Caso | Camino | Entrada 1 | Entrada 2 | Entrada 3 | Entrada 4 | Entrada 5 | Resultado esperado | Válido/Inválido |
|---|---:|---:|---:|---:|---:|---:|---:|---|
| 1 | | | | | | | | |
| 2 | | | | | | | | |
| 3 | | | | | | | | |
| n | | | | | | | | |

> **Importante:** Reemplace los nombres de las columnas de entrada por el nombre del parámetro de la función para una mejor claridad al momento de interpretar la tabla.

La cantidad de casos debe justificarse en función de la complejidad ciclomática y de los caminos seleccionados.

---

# 12. Actividad 6 — Caja negra: clases de equivalencia

Ahora ignore la implementación interna.

Considere únicamente:

- Entradas.
- Reglas de negocio.
- Resultado esperado.

Determine las **clases de equivalencia válidas e inválidas**.

## Variables principales

```text
peso, distancia, cliente, prioridad, destino
```

Realice una tabla para cada variable:

| Condición de Entrada | Clases Válidas | Clases Inválidas
|---|---|---|
| [nombre]_formato_cant_digitos | | |
| [nombre]_valor | | |

> **Importante:** Recuerde enumerar cada clase de equivalencia. Esto le será de mucha ayuda para poder realizar los casos de prueba de cada condición de entrada.

---

# 13. Actividad 7 — Valores límite (Exhaustiva)

Identifique los límites relevantes del problema.

Como mínimo deben analizarse los valores inmediatamente anteriores, exactos e inmediatamente posteriores a cada frontera significativa.

Valores sugeridos:

```text
`peso`: 0, 1, 9, 10, 11, 19, 20, 21, 29, 30, 31, 49, 50, 51

`distancia`: 0, 1, 499, 500, 501, 999, 1000, 1001, 1499, 1500, 1501, 1999, 2000, 2001

`cliente` / `destino`: 0, 1, 2, 3, 4

`prioridad`: -1, 0, 1, 2
```

No es obligatorio utilizar todos estos valores en los casos finales. El estudiante debe justificar cuáles son necesarios y cuáles pueden descartarse por redundancia.

---

# 14. Actividad 8 — Casos de prueba de caja negra

Diseñe un conjunto de casos de prueba utilizando:

- Clases de equivalencia.
- Análisis de valores límite.
- Reglas de negocio.

Utilice:

| # Caso | Datos de Entrada | Cobertura CE
|---|---:|---|
| 1 | entrada 1: valor | 1, 2, 3, 4, ... |
|   | entrada 2: valor | |
|   | entrada n: valor | |
| 2 | | |
| 3 | | |
| n | | |

---

# 15. Actividad 9 — Casos especiales

Diseñe casos que permitan comprobar específicamente:

### A. Datos inválidos

Probar cada parámetro fuera de rango.

### B. Valores Límites (Exhaustiva)

Probar las condiciones inmediatamente antes, exactamente en el límite e inmediatamente después.

### C. Caminos de resultado

Debe existir al menos un caso que alcance cada código de retorno posible.

### D. Condiciones compuestas

Diseñar casos donde cambie una sola condición de una expresión compuesta mientras las demás permanecen constantes.

### E. Combinaciones

Identificar combinaciones que puedan producir comportamientos diferentes aun cuando individualmente pertenezcan a la misma clase de equivalencia.

---

# 16. Actividad 10 — Implementación de pruebas unitarias

Crear un programa de pruebas en C ANSI.

No se permite utilizar ningún framework.

Se debe implementar manualmente una estructura similar a:

```c
void ejecutar_prueba(
    int id,
    int entrada1,
    int entrada2,
    int entrada3,
    int entrada4,
    int entrada5,
    int esperado
)
{
    int resultado;

    resultado = /* llamada a la función bajo prueba */;

    if (resultado == esperado)
    {
        printf("PASS - Caso %d\n", id);
    }
    else
    {
        printf("FAIL - Caso %d - Esperado: %d - Obtenido: %d\n",
               id, esperado, resultado);
    }
}
```

> Esta función es solamente un ejemplo de infraestructura mínima de pruebas. El estudiante debe completar y adaptar la solución.

---

# 17. Restricciones adicionales para las pruebas

El código de testing tampoco podrá utilizar:

- `bool`
- vectores
- matrices
- punteros
- `struct`
- frameworks
- librerías externas

Por lo tanto, no se podrá implementar algo como:

```c
int casos[100];
```

ni:

```c
struct CasoPrueba
{
    int entrada1;
    int entrada2;
};
```

El objetivo es que cada prueba sea explícita y comprensible.

---

# 18. Actividad 11 — Ejecución y reporte

El programa de pruebas deberá mostrar como mínimo:

```text
========================================
          TEST DE LA FUNCION
========================================

PASS - Caso 1
PASS - Caso 2
FAIL - Caso 3 - Esperado: 2 - Obtenido: 4

----------------------------------------
Total de pruebas : 10
Pruebas exitosas : 9
Pruebas fallidas : 1
----------------------------------------
```

El estudiante deberá incluir evidencia de ejecución.

---

# 19. Actividad 12 — Análisis de cobertura

A partir de los casos diseñados, determinar:

- ¿Se cubrieron todas las sentencias?
- ¿Se cubrieron todas las decisiones?
- ¿Se cubrieron los caminos independientes?
- ¿Se probaron las clases de equivalencia relevantes?
- ¿Se probaron los valores límite?
- ¿Existen condiciones que no fueron cubiertas?
- ¿Existen casos redundantes?

El análisis debe diferenciar claramente:

```text
Cobertura de caja blanca
```

de:

```text
Cobertura de caja negra
```

---

# 20. Actividad 13 — Detección de errores

Suponga que durante la ejecución aparece un resultado que contradice la regla de negocio.

Analice:

1. ¿Qué regla debería cumplirse?
2. ¿Qué camino del grafo debería ejecutarse?
3. ¿Qué condición podría estar provocando el resultado incorrecto?
4. ¿El problema pertenece al código de producción o al caso de prueba?
5. ¿Cómo demostraría el problema mediante una prueba reproducible?

---

# 21. Actividad 14 — Prueba de regresión

Suponga que se corrige un defecto detectado durante las pruebas.

Defina:

1. El caso que detectó el defecto.
2. El comportamiento esperado.
3. El comportamiento incorrecto.
4. La modificación realizada.
5. Los casos que deben volver a ejecutarse.
6. Por qué esos casos forman parte de una prueba de regresión razonable.

---

# 22. Entrega esperada

La entrega debe contener:

```text
/
├── README.md
├── {función}.c
└── test_{función}.c
```

Opcionalmente:

```text
├── grafo.png
└── informe.pdf
```

---

# 23. Informe

El informe debe incluir:

1. Descripción del problema.
2. Reglas de negocio.
3. Análisis de caja blanca.
4. Grafo dirijido.
5. Complejidad ciclomática.
6. Caminos independientes.
7. Casos de prueba de caja blanca.
8. Clases de equivalencia.
9. Valores límite.
10. Casos de prueba de caja negra.
11. Implementación de pruebas unitarias.
12. Evidencia de ejecución.
13. Análisis de cobertura.
14. Prueba de regresión.
15. Preguntas conceptuales

---

# 24. Preguntas conceptuales

Responder con fundamento:

### 1.

¿Por qué la complejidad ciclomática permite estimar la cantidad mínima de caminos independientes?

### 2.

¿Tener una cobertura de sentencias del 100% significa que el programa está completamente probado?

### 3.

¿Qué diferencia existe entre probar caminos y probar valores límite?

### 4.

¿Por qué una condición compuesta puede requerir más casos de prueba que una condición simple?

### 5.

¿Puede existir un caso de prueba que sea útil para caja blanca pero poco útil para caja negra? Justifique.

### 6.

¿Puede existir un caso de prueba de caja negra que no sea necesario para cubrir un camino independiente? Justifique.

### 7.

¿Qué ventaja aporta el análisis de clases de equivalencia cuando existe una gran cantidad de valores posibles?

### 8.

¿Por qué los valores inmediatamente anteriores y posteriores a un límite son importantes?

### 9.

¿Por qué una prueba de regresión no debería limitarse únicamente al caso que originalmente encontró el defecto?

---

# 26. Criterios de evaluación

| Criterio | Ponderación |
|---|---:|
| Análisis de caja blanca | 15% |
| Grafo dirijido | 15% |
| Complejidad ciclomática | 15% |
| Caminos independientes | 10% |
| Casos de prueba de caja blanca | 10% |
| Clases de equivalencia | 10% |
| Valores límite | 10% |
| Implementación de pruebas en C | 10% |
| Análisis de cobertura y conclusiones | 5% |
| **Total** | **100%** |

---

# 27. Condiciones de aprobación del ejercicio

Para considerar completo el ejercicio, no alcanza con presentar código que compile.

El estudiante debe poder **justificar**:

```text
Código
   ↓
Grafo
   ↓
Complejidad ciclomática
   ↓
Caminos independientes
   ↓
Casos de prueba
```

y, desde el enfoque de caja negra:

```text
Requisitos
   ↓
Clases de equivalencia
   ↓
Valores límite
   ↓
Casos de prueba
   ↓
Resultado esperado
```

La evaluación priorizará la **justificación técnica del diseño de pruebas** por encima de la cantidad de casos realizados.

---

## Conceptos que deben aparecer en la resolución

La resolución deberá demostrar comprensión de:

- Caja blanca.
- Caja negra.
- Grafo dirijido.
- Nodo.
- Arista.
- Predicado.
- Camino.
- Camino independiente.
- Complejidad ciclomática.
- Cobertura de sentencias.
- Cobertura de decisiones.
- Prueba unitaria.
- Caso de prueba.
- Resultado esperado.
- Clases de equivalencia.
- Valores límite.
- Datos válidos.
- Datos inválidos.
- Redundancia de pruebas.
- Cobertura.
- Prueba de regresión.

---

## Observación docente

Este ejercicio está diseñado deliberadamente para que **no sea suficiente con ejecutar algunos ejemplos manualmente**.

Una solución correcta debe demostrar el proceso de razonamiento utilizado para pasar desde el código y los requisitos hacia un conjunto de pruebas justificable.

El objetivo final no es solamente encontrar errores, sino aprender a responder:

> **¿Por qué estos casos de prueba son necesarios y qué parte del sistema demuestran?**
