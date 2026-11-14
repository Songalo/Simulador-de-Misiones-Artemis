
#include <stdio.h>
#include <math.h>
#include "simulador.h"

void calcular_fase1(NaveArtemis *nave)
{
    if (nave == NULL) {
        return;
    }

    nave->tiempo_actual = 0.0;
    nave->altitud = 0.0;
    nave->velocidad = 0.0;
    nave->aceleracion = ACEL_FASE1;

    double altitudes[121];
    double velocidades[121];

    for (int i = 0; i <= 120; i++) {
        double tiempo = (double)i;

        altitudes[i] = 0.5 * nave->aceleracion * tiempo * tiempo;
        velocidades[i] = nave->aceleracion * tiempo;
    }

    nave->altitud = altitudes[120];
    nave->velocidad = velocidades[120];

    nave->tiempo_actual = TIEMPO_SRB; 

    printf("\n--- EVOLUCION DEL ASCENSO ---\n");
    printf("Tiempo\tAltitud (m)\tVelocidad (m/s)\n");

    for (int i = 0; i <= 120; i += 10) {
        printf("%d\t%.2f\t\t%.2f\n",
           i, altitudes[i], velocidades[i]);
    }

    double aceleracion_en_g = nave->aceleracion / ACEL_GRAV;

    printf("\n--- RESULTADOS DE LA PRIMERA ETAPA ---\n");
    printf("Tiempo transcurrido: %.2f segundos\n", nave->tiempo_actual);
    printf("Altitud alcanzada: %.2f metros\n", nave->altitud);
    printf("Velocidad alcanzada: %.2f m/s\n", nave->velocidad);
    printf("Aceleracion de la tripulacion: %.2f g\n", aceleracion_en_g);
    printf("\nDESPRENDIMIENTO DE LOS SRB\n");
    printf("Tiempo del evento: %.2f segundos\n", nave->tiempo_actual);
    printf("La primera etapa ha finalizado.\n");
}


void calcular_fase2(NaveArtemis *nave)
{
    if (nave == NULL) {
        return;
    }
    if (nave->tiempo_actual < TIEMPO_SRB || nave->altitud <= 0.0) {
    printf("Error: primero debe ejecutar la Fase 1.\n");
    return;
}

if (nave->altitud >= ALTURA_OBJETIVO) {
    printf("Error: la Fase 2 ya fue ejecutada.\n");
    return;
}

    // Guardamos los valores iniciales de la segunda fase
    double velocidad_inicial = nave->velocidad;
    double altitud_inicial = nave->altitud;

    // Establecemos la aceleracion de la fase 2
    nave->aceleracion = ACEL_FASE2;

    // Calculamos la distancia que falta para llegar a los 160.000 metros
    double distancia = ALTURA_OBJETIVO - altitud_inicial;

    if (distancia < 0) {
        printf("Error: la nave ya supero la altura objetivo.\n");
        return;
    }

    // Calculamos la velocidad final utilizando MRUV
    double velocidad_final = sqrt(
        velocidad_inicial * velocidad_inicial +
        2 * nave->aceleracion * distancia
    );

    // Calculamos el tiempo que dura la segunda fase
    double tiempo_fase2 =
        (velocidad_final - velocidad_inicial) / nave->aceleracion;

    // Actualizamos los datos de la nave
    nave->tiempo_actual += tiempo_fase2;
    nave->altitud = ALTURA_OBJETIVO;
    nave->velocidad = velocidad_final;

    printf("\n--- RESULTADOS DE LA SEGUNDA FASE ---\n");
    printf("Tiempo de la fase 2: %.2f segundos\n", tiempo_fase2);
    printf("Tiempo total: %.2f segundos\n", nave->tiempo_actual);
    printf("Altitud alcanzada: %.2f metros\n", nave->altitud);
    printf("Velocidad alcanzada: %.2f m/s\n", nave->velocidad);
    printf("Los motores principales se apagan.\n");
}


void simular_caida_libre(NaveArtemis *nave)
{
    if (nave == NULL) {
        return;
    }
    if (nave->altitud != ALTURA_OBJETIVO || nave->velocidad <= 0.0) {
    printf("Error: primero debe completar la Fase 2.\n");
    return;
}

    // Guardamos la velocidad y altitud al apagar los motores
    double velocidad_inicial = nave->velocidad;
    double altitud_inicial = nave->altitud;

    // La aceleracion ahora es la gravedad hacia abajo
    nave->aceleracion = -ACEL_GRAV;

    // Calculamos el tiempo hasta alcanzar la altura maxima
    double tiempo_subida = velocidad_inicial / ACEL_GRAV;

    // Calculamos la altura adicional que alcanza la nave
    double altura_adicional =
        (velocidad_inicial * velocidad_inicial) / (2 * ACEL_GRAV);

    // Calculamos la altura maxima total
    double altura_maxima = altitud_inicial + altura_adicional;

    // Actualizamos los datos de la nave
    nave->tiempo_actual += tiempo_subida;
    nave->altitud = altura_maxima;
    nave->velocidad = 0.0;

    printf("\n--- SIMULACION DE CAIDA LIBRE ---\n");
    printf("Tiempo hasta alcanzar la altura maxima: %.2f segundos\n",
           tiempo_subida);
    printf("Altura adicional: %.2f metros\n", altura_adicional);
    printf("Altura maxima alcanzada: %.2f metros\n", altura_maxima);
    printf("Velocidad en el punto mas alto: %.2f m/s\n", nave->velocidad);
}

void mostrar_reporte_final(NaveArtemis nave) {
    printf("\n==================================================\n"); 
    printf("         INFORME DE DESEMPEÑO - MISIÓN SLS        \n");
    printf("==================================================\n");
    printf(" > Tiempo total de vuelo:    %.2f segundos\n", nave.tiempo_actual); 
    printf(" > Altitud actual/alcanzada: %.2f metros\n", nave.altitud);
    printf(" > Velocidad actual:         %.2f m/s\n", nave.velocidad);
    printf(" > Aceleración registrada:   %.2f m/s^2\n", nave.aceleracion);

    printf(" > Aceleracion maxima durante el ascenso: %.2f m/s^2\n", ACEL_FASE1);

    double g_maximo = ACEL_FASE1 / ACEL_GRAV;
    printf(" > G-Force maxima de la tripulacion: %.2f g\n", g_maximo);

    printf("--------------------------------------------------\n");
    if (nave.altitud >= ALTURA_OBJETIVO) {
        printf(" [ESTADO] Misión completada o fase orbital alcanzada.\n");
    } else if (nave.altitud > 0) {
        printf(" [ESTADO] Misión en curso (Fases intermedias).\n");
    } else {
        printf(" [ESTADO] La nave sigue en la plataforma de lanzamiento.\n");
    }
    printf("==================================================\n");
}