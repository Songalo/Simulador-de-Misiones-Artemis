
#include <stdio.h>
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