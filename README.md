# 📘 Práctica de Testing en C

![Global CI](https://github.com/4r13lx/UPE_Testing/actions/workflows/c-cpp.yml/badge.svg) [![C CD Pipeline](https://github.com/4r13lx/UPE_Testing/actions/workflows/c-cdp.yml/badge.svg)](https://github.com/4r13lx/UPE_Testing/actions/workflows/c-cdp.yml) [![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=4r13lx_UPE_Testing&metric=alert_status&token=1e29a1c3b13efaffa02e99443247c76164c68802)](https://sonarcloud.io/summary/new_code?id=4r13lx_UPE_Testing) [![Bugs](https://sonarcloud.io/api/project_badges/measure?project=4r13lx_UPE_Testing&metric=bugs&token=1e29a1c3b13efaffa02e99443247c76164c68802)](https://sonarcloud.io/summary/new_code?id=4r13lx_UPE_Testing) [![Code Smells](https://sonarcloud.io/api/project_badges/measure?project=4r13lx_UPE_Testing&metric=code_smells&token=1e29a1c3b13efaffa02e99443247c76164c68802)](https://sonarcloud.io/summary/new_code?id=4r13lx_UPE_Testing) [![Duplicated Lines (%)](https://sonarcloud.io/api/project_badges/measure?project=4r13lx_UPE_Testing&metric=duplicated_lines_density&token=1e29a1c3b13efaffa02e99443247c76164c68802)](https://sonarcloud.io/summary/new_code?id=4r13lx_UPE_Testing)

### 🔹 Descripción
Repositorio práctico en C que incluye funciones básicas, tests unitarios y un pipeline completo de CI/CD con GitHub Actions, análisis con SonarQube y despliegues automatizados.

### 🎯 Objetivos
- Reforzar conceptos clave de testing mediante ejercicios en C  
- Promover código limpio, mantenible y testeable  
- Introducir flujos de trabajo CI/CD reales  
- Fomentar una mentalidad orientada a la calidad  



### 🧪 Contenido
- ✔️ Funciones básicas en C  
- ✔️ Tests unitarios (por ejemplo, usando frameworks como Unity/CMock o similares)  
- ✔️ Enfoque de validación basado en pruebas  



### ⚙️ Pipeline de CI/CD (GitHub Actions)
Cada cambio en el código dispara automáticamente:

- 🔨 **Proceso de Build** – Compilación con herramientas estándar (ej: GCC)  
- ✅ **Tests Unitarios** – Ejecución completa de pruebas  
- 🔍 **Análisis de Calidad** – Auditoría de código con SonarQube  
- 🚀 **Despliegue Automático**  
  - 🧪 Entorno de Testing  
  - 🌐 Entorno Productivo  



### 🏗️ ¿Por qué es importante?
Este repositorio simula un flujo de trabajo real, permitiendo a los alumnos comprender cómo los equipos modernos:
- Garantizan la calidad del software  
- Automatizan validaciones  
- Entregan soluciones confiables  


### 💡 Idea Clave
> Escribir código en C es solo el comienzo — asegurar su calidad, correcto funcionamiento y entrega continua es lo que define el desarrollo profesional de software.


## 🐳 Distribución del Contenedor Docker

Este repositorio cuenta con pipelines automatizados de Integración Continua (CI) y Despliegue Continuo (CD) encargados de compilar, validar y desplegar el proyecto ante cada cambio realizado en el repositorio.

Cuando el flujo de Integración Continua finaliza correctamente — compilando el código fuente y ejecutando satisfactoriamente todos los tests automatizados — se activa automáticamente el flujo de Despliegue Continuo. Este proceso genera y publica una imagen Docker que contiene tanto el código fuente del repositorio como los artefactos compilados.

El contenedor puede descargarse y ejecutarse localmente en tu máquina, permitiéndote:

- Explorar el código fuente
- Revisar y ejecutar los tests unitarios
- Compilar los ejercicios
- Validar el funcionamiento del proyecto
- Realizar pruebas y modificaciones en un entorno aislado

Podés descargar las imágenes desde el repositorio oficial de paquetes Docker en GitHub:

👉 [Repositorio Docker](https://github.com/users/4r13lx/packages/container/package/upe_testing)

Se recomienda utilizar la última versión disponible, ya que contiene los cambios más recientes, correcciones y funcionalidades validadas automáticamente por los pipelines del proyecto.


---


# 📘 Software Testing Practice in C

### 🔹 Description
A hands-on C programming repository featuring fundamental functions, unit testing, and a complete CI/CD pipeline with GitHub Actions, SonarQube analysis, and automated deployments.

### 🎯 Objectives
- Reinforce core testing concepts through C programming exercises  
- Promote clean, maintainable, and testable C code  
- Introduce real-world CI/CD workflows  
- Encourage a quality-first development mindset  

---

### 🧪 What’s Included
- ✔️ Fundamental C functions  
- ✔️ Unit tests (e.g., using frameworks like Unity/CMock or similar)  
- ✔️ Test-driven validation approach  

---

### ⚙️ CI/CD Pipeline (GitHub Actions)
Every code change automatically triggers:

- 🔨 **Build Process** – Compilation using standard C toolchains (e.g., GCC)  
- ✅ **Unit Testing** – Execution of all test suites  
- 🔍 **Code Quality Analysis** – Static analysis with SonarQube  
- 🚀 **Automated Deployment**  
  - 🧪 Testing Environment  
  - 🌐 Production Environment  

---

### 🏗️ Why This Matters
This repository simulates a real-world development workflow, helping students understand how modern teams:
- Ensure software quality  
- Automate validation processes  
- Deliver reliable and maintainable systems  

---

### 💡 Key Takeaway
> Writing C code is just the beginning — ensuring its correctness, quality, and continuous delivery is what defines professional software development.


## 🐳 Docker Container Distribution

This repository includes automated CI/CD pipelines responsible for compiling, validating, and deploying the project on every change pushed to the repository.

Whenever the Continuous Integration (CI) workflow completes successfully — meaning the source code compiles correctly and all automated tests pass — the Continuous Deployment (CD) workflow is triggered automatically. This process generates and publishes a Docker container containing the repository source code and compiled artifacts.

The container can be downloaded and executed locally on your machine, allowing you to:

- Explore the source code
- Review and execute unit tests
- Compile the exercises
- Validate the project behavior
- Experiment freely in an isolated environment

You can download the container images from the official GitHub Container Registry:

👉 [Docker Package Repository](https://github.com/users/4r13lx/packages/container/package/upe_testing)

It is recommended to use the latest available image version, as it contains the most recent changes, fixes, and validated functionality.