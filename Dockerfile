# Imagen base minima
FROM alpine:3.22

# Instalacion de herramientas necesarias
RUN apk add --no-cache \
    gcc \
    musl-dev \
    make \
    bash \
    nano 

# Crear el usuario del sistema "docker" y su grupo
RUN addgroup -S docker && adduser -S docker -G docker

# Directorio de trabajo
WORKDIR /testing

# Copiar los archivos asignando la propiedad al usuario docker inmediatamente
COPY --chown=docker:docker . .

# Permisos opcionales
RUN chmod -R 755 /testing

# Cambiar al usuario no-root para la ejecución
USER docker

# Mensaje inicial
CMD ["/bin/bash"]