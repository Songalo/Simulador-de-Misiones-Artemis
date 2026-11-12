
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

    nave->altitud = nave->altitud
                  + nave->velocidad * TIEMPO_SRB
                  + (nave->aceleracion * TIEMPO_SRB * TIEMPO_SRB) / 2.0;

    nave->velocidad = nave->velocidad
                    + nave->aceleracion * TIEMPO_SRB;

    nave->tiempo_actual = TIEMPO_SRB; 

    double aceleracion_en_g = nave->aceleracion / ACEL_GRAV;

    printf("\n--- RESULTADOS DE LA PRIMERA ETAPA ---\n");
    printf("Tiempo transcurrido: %.2f segundos\n", nave->tiempo_actual);
    printf("Altitud alcanzada: %.2f metros\n", nave->altitud);
    printf("Velocidad alcanzada: %.2f m/s\n", nave->velocidad);
    printf("Aceleracion de la tripulacion: %.2f g\n", aceleracion_en_g);