#include <stdio.h>
#include "simulador.h"    
#include "validaciones.h" 

int main(void) {
    // 1. Declaración de la variable que mantendrá el estado del vuelo
    NaveArtemis nave;

    // 2. Inicialización estricta para limpiar la memoria residual
    nave.tiempo_actual = 0.0;
    nave.altitud = 0.0;
    nave.velocidad = 0.0;
    nave.aceleracion = 0.0;

    // 3. Mensaje inicial de prueba
    printf("=== SIMULADOR DE MISIONES ARTEMIS ===\n");
    printf("[Sistema inicializado correctamente]\n");

    return 0;
}