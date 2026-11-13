# 1. Se define las variables.
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = simulador_artemis
OBJS = main.c simulador.c validaciones.c

# 2. Regla principal (se ejecuta al escribir solo "make")
all: $(TARGET)

# 3. Instrucción para construir el ejecutable uniendo todos los archivos .c
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) -lm

# 4. Es una regla para limpiar archivos basura (al escribir "make clean")
clean:
	rm -f $(TARGET) *.o