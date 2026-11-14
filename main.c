#include <stdio.h>
#include "simulador.h"    
#include "validaciones.h" 

int main(void) {
    NaveArtemis nave;
    ConfiguracionMision config;

    int tipo_mision;

    printf("\n=== SELECCION DE MISION ===\n");
    printf("[1] Mision oficial\n");
    printf("[2] Mision personalizada\n");

    tipo_mision = leerEntero("Seleccione una opcion: ", 1, 2);

    if (tipo_mision == 1) {
        config.acel_fase1 = ACEL_FASE1;
        config.acel_fase2 = ACEL_FASE2;
        config.altura_objetivo = ALTURA_OBJETIVO;

        printf("\nMision oficial seleccionada.\n");
    }
    else {
        printf("\nMision personalizada seleccionada.\n");

        config.acel_fase1 = leerFlotante(
            "Ingrese aceleracion de Fase 1: ", 0.01, 100.0);

        config.acel_fase2 = leerFlotante(
            "Ingrese aceleracion de Fase 2: ", 0.01, 100.0);

        config.altura_objetivo = leerFlotante(
            "Ingrese altura objetivo en metros: ", 1.0, 1000000.0);
    }
    double altura_fase1 = 0.5 * config.acel_fase1 *
                      TIEMPO_SRB * TIEMPO_SRB;

    while (config.altura_objetivo <= altura_fase1) {
        printf("\nLa altura objetivo debe superar %.2f metros.\n",
           altura_fase1);

        config.altura_objetivo = leerFlotante(
            "Ingrese una nueva altura objetivo: ", 1.0, 1000000.0);
}
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
        printf("[3] Simular Falla de Motores y Caida Libre\n");
        printf("[4] Ver Reporte de Desempeno Final\n");
        printf("[5] Salir del Sistema\n");
        printf("----------------------------------------\n");
        
        // 4. BLINDAJE DE SEGURIDAD 
        opcion = leerEntero("Seleccione una opcion (1-5): ", 1, 5);

        switch (opcion) {
            case 1:
                printf("\n--- INICIANDO FASE 1 ---\n");
                calcular_fase1(&nave, &config); 
                break;
            case 2:
                printf("\n--- INICIANDO FASE 2 ---\n");
                calcular_fase2(&nave, &config);
                break;
            case 3:
                printf("\n--- EJECUTANDO FALLA DE MOTORES ---\n");
                simular_caida_libre(&nave, &config);
                break;
            case 4:
                printf("\n--- REPORTE FINAL DE MISION ---\n");
                mostrar_reporte_final(nave, &config); 
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