# Imagen base minima
FROM alpine:latest

# Instalacion de herramientas necesarias
RUN apk add --no-cache \
    gcc \
    musl-dev \
    make \
    bash

# Directorio de trabajo
WORKDIR /testing

# Copiar todos los ejercicios
COPY . .

# Permisos opcionales
RUN chmod -R 755 /testing

# Mensaje inicial
CMD ["/bin/bash"]