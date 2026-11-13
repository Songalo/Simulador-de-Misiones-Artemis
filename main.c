#include <stdio.h>
#include "simulador.h"    
#include "validaciones.h" 

int main(void) {
    // 1. Declaración e inicialización estricta (Lo que hicimos en el commit 1)
    NaveArtemis nave;
    nave.tiempo_actual = 0.0;
    nave.altitud = 0.0;
    nave.velocidad = 0.0;
    nave.aceleracion = 0.0;

    int opcion;

    // 2. Control de flujo: Bucle principal interactivo
    do {
        printf("\n========================================\n");
        printf("    SIMULADOR ARTEMIS - MISION SLS      \n");
        printf("========================================\n");
        printf("[1] Ejecutar Fase 1 (Despegue con SRB)\n");
        printf("[2] Ejecutar Fase 2 (Nucleo Principal)\n");
        printf("[3] Simular Caida Libre (Falla de motores a 160km)\n");
        printf("[4] Ver Reporte de Desempeno Final\n");
        printf("[5] Salir del Sistema\n");
        printf("----------------------------------------\n");
        printf("Seleccione una opcion: ");
        
        // Lectura estándar temporal (la blindaremos en el commit 4)
        scanf("%d", &opcion);

        // 3. Enrutador lógico de opciones
        switch (opcion) {
            case 1:
                printf("\n[INFO] Opcion 1 en construccion...\n");
                break;
            case 2:
                printf("\n[INFO] Opcion 2 en construccion...\n");
                break;
            case 3:
                printf("\n[INFO] Opcion 3 en construccion...\n");
                break;
            case 4:
                printf("\n[INFO] Opcion 4 en construccion...\n");
                break;
            case 5:
                printf("\n[SALIENDO] Finalizando el simulador de vuelo...\n");
                break;
            default:
                printf("\n[ERROR] Opcion fuera de rango. Seleccione entre 1 y 5.\n");
        }
    } while (opcion != 5);

    return 0;
}