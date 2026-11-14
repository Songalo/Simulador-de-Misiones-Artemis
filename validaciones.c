#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

int leerEntero(const char *mensaje, int min, int max) {
    char buffer[100];
    int valor;
    int valido = 0;
    char extra;

    do {
        printf("%s", mensaje);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            size_t len = strlen(buffer);
            if (len > 0 && buffer[len - 1] == '\n') {
                buffer[len - 1] = '\0';
            }
            if (sscanf(buffer, " %d %c", &valor, &extra) == 2) {
                printf("\n[Aviso amigable] Ingresaste varios valores. Solo necesitamos uno.\n\n");
            } else
            if (sscanf(buffer, " %d %c", &valor, &extra) == 1) {
                if (valor >= min && valor <= max) {
                    valido = 1;
                } else {
                    printf("\n[Aviso amigable] El valor está fuera del rango (%d a %d). Probá de nuevo.\n\n", min, max);
                }
            } else {
                printf("\n[Aviso amigable] ¡Cuidado! Ingresaste letras o caracteres no válidos. Necesitamos un número entero.\n\n");
            }
        }
    } while (!valido);

    return valor;
}




float leerFlotante(const char *mensaje, float min, float max) {
    char buffer[100];
    float valor;
    int valido = 0;
    char extra;

    do {
        printf("%s", mensaje);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            size_t len = strlen(buffer);
            if (len > 0 && buffer[len - 1] == '\n') {
                buffer[len - 1] = '\0';
            }
            if (sscanf(buffer, " %f %c", &valor, &extra) == 2) {
                printf("\n[Aviso amigable] Ingresaste varios valores. Solo necesitamos uno.\n\n");
            } else
            if (sscanf(buffer, " %f %c", &valor, &extra) == 1) {
                if (valor >= min && valor <= max) {
                    valido = 1;
                } else {
                    printf("\n[Aviso amigable] Valor fuera del rango válido (%.2f a %.2f).\n\n", min, max);
                }
            } else {
                printf("\n[Aviso amigable] Ingresaste letras. Requerimos un número decimal válido.\n\n");
            }
        }
    } while (!valido);

    return valor;
}

void mostrarMensajeAmable(const char *mensaje) {
    printf("\n--------------------------------------------------\n");
    printf(" 🚀 [Centro de Control Artemis] %s\n", mensaje);
    printf("--------------------------------------------------\n");
}

void mostrarAlerta(const char *mensaje) {
    printf("\n⚠️ [Aviso del Sistema Artemis] %s\n", mensaje);
}

void pausarConsola(void) {
    printf("\nPresioná Enter para continuar...");
    char pausa_buffer[10];
    fgets(pausa_buffer, sizeof(pausa_buffer), stdin);
}
