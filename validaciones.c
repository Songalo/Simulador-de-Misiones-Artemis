#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

int leerEntero(const char *mensaje, int min, int max) {
    char buffer[100];
    int valor;
    int valido = 0;

    do {
        printf("%s", mensaje);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            size_t len = strlen(buffer);
            if (len > 0 && buffer[len - 1] == '\n') {
                buffer[len - 1] = '\0';
            }
            if (sscanf(buffer, "%d", &valor) == 1) {
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
