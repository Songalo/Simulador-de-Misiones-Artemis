#include <stdio.h>
#include "simulador.h"    
#include "validaciones.h" 

int main(void) {
    NaveArtemis nave;
    nave.tiempo_actual = 0.0;
    nave.altitud = 0.0;
    nave.velocidad = 0.0;
    nave.aceleracion = 0.0;

    int opcion;

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
        
        // 4. BLINDAJE DE SEGURIDAD 
        opcion = leerEntero("Seleccione una opcion (1-5): ", 1, 5);

        switch (opcion) {
            case 1:
                printf("\n--- INICIANDO FASE 1 ---\n");
                calcular_fase1(&nave); 
                break;
            case 2:
                printf("\n--- INICIANDO FASE 2 ---\n");
                calcular_fase2(&nave);
                break;
            case 3:
                printf("\n--- SIMULACION DE CAIDA LIBRE ---\n");
                simular_caida_libre(&nave);
                break;
            case 4:
                printf("\n--- REPORTE FINAL DE MISION ---\n");
                mostrar_reporte_final(nave); 
                break;
            case 5:
                printf("\n[SALIENDO] Finalizando el simulador de vuelo...\n");
                break;
        }

        // Evita que el menú vuelva a aparecer instantáneamente y tape los resultados
        if (opcion != 5) {
            pausarConsola(); 
        }

    } while (opcion != 5);

    return 0;
}